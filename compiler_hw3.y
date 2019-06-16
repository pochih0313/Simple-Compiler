/*	Definition section */
%{
#include "compiler.h" 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Entry Entry;
struct Entry {
    int index;
    char *name;
    char *kind;
    char *type;
    int scope;
    char *attribute;
    Entry *next;
};
typedef struct Header Header;
struct Header {
    int depth;
    Entry *root;
    Entry *tail;
    Header *previous;
};
Header *header_root = NULL;
Header *cur_header = NULL;

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern int error_flag[2];
extern char msg[10][100];
extern int error_num;

int depth = 0;
int entry_num[100] = {0};
int dump_flag = 0;
char code[256];
int err_flag = 0;
int variable_num = 0;

FILE *file; // To generate .j file for Jasmin

void yyerror(char *s);

/* symbol table functions */
int lookup_symbol(Header *header, char *id_name);
void create_symbol();
void insert_symbol(Header *header, char *id_name, char* type, char* kind, char* attribute);
void dump_symbol();
void free_symbol_table();

/* code generation functions, just an example! */
void code_gen(char const *s);
void do_declaration(char *type, char *id_name, Value val);

%}

%union {
    struct Value value;
    char *type;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token RET
%token QUOTA
/* Token with return, which need to sepcify type */
%token <type> VOID INT FLOAT STRING BOOL
%token <value> ID I_CONST F_CONST STR_CONST
%token <value> TRUE FALSE
/* Nonterminal with return, which need to sepcify type */
%type <type> type
%type <value> expression comparison_expr addition_expr
%type <value> multiplication_expr postfix_expr parenthesis
%type <value> constant func

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%
program
    : program stat
    | error
    | 
;
stat
    : declaration
    | compound_stat
    | expression_stat
    | print_func
    | func_definition
;
declaration
    : type ID ASGN expression SEMICOLON {
            insert_symbol(cur_header, $2.id_name, $1, "variable", "");
            if(!error_flag[1]) {
                do_declaration($1,$2.id_name,$4);
            }
        }
    | type ID SEMICOLON {
            insert_symbol(cur_header, $2.id_name, $1, "variable", "");
            if(!error_flag[1]) {
                if(strcmp($1,"int") == 0) {      
                    if(depth == 1) {
                        sprintf(code, ".field public static %s I = 0\n", $2.id_name);
                    }
                    else {
                        sprintf(code, "\tldc 0\n\tistore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp($1,"float") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s F = 0.0\n", $2.id_name);
                    }
                    else {
                        sprintf(code, "\tldc 0.0\n\tfstore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp($1,"bool") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s Z = 0\n", $2.id_name);
                    }
                    else {
                        sprintf(code, "\tldc 0\n\tistore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp($1,"string") == 0) {
                    if(depth != 1) {
                        sprintf(code, "\tldc \"\"\n\tastore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else yyerror("Unsupported type");
            }
        }
;
type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;
compound_stat
    : if_stat
    | while_stat
;
if_stat
    : IF expression block
    | IF expression block ELSE block
    | IF expression block ELSE if_stat
;
block
    : LCB{ create_symbol(); } program RCB { dump_flag = 1; }
;
while_stat
    : WHILE expression block
;
expression_stat
    : expression SEMICOLON
    | ID{ 
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, $1.id_name) != -1) {
                f = 1;
                break;
            }
            cur = cur->previous;
        }
        if (f != 1) {
            sprintf(msg[error_num++], "Undeclared variable %s", $1.id_name);
            error_flag[1] = 1;
        }
    } assign_op expression SEMICOLON
;
expression
    : comparison_expr { $$ = $1; }
;
comparison_expr
    : addition_expr { $$ = $1; }
    | comparison_expr cmp_op addition_expr
;
addition_expr
    : multiplication_expr { $$ = $1; }
    | addition_expr add_op multiplication_expr
;
multiplication_expr
    : postfix_expr { $$ = $1; }
    | multiplication_expr mul_op postfix_expr
;
postfix_expr
    : parenthesis { $$ = $1; }
    | parenthesis post_op
;
parenthesis
    : constant { $$ = $1; }
    | ID { $$ = $1; 
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, $1.id_name) != -1) {
                f = 1;
                break;
            }
            cur = cur->previous;
        }
        if (f != 1) {
            sprintf(msg[error_num++], "Undeclared variable <%s>", $1.id_name);
            error_flag[1] = 1;
        }
    }
    | TRUE { $$ = $1; }
    | FALSE { $$ = $1; }
    | LB expression RB { $$ = $2; }
    | func { $$ = $1; }
;
cmp_op
    : MT
    | LT
    | MTE
    | LTE
    | EQ
    | NE
;
add_op
    : ADD
    | SUB
;
mul_op
    : MUL
    | DIV
    | MOD
;
post_op
    : INC
    | DEC
;
assign_op
    : ASGN
    | ADDASGN
    | SUBASGN
    | MULASGN
    | DIVASGN
    | MODASGN
;
constant
    : I_CONST { $$ = $1; }
    | F_CONST { $$ = $1; }
    | QUOTA STR_CONST QUOTA { $$ = $2; }
;
print_func
    : PRINT LB ID{
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, $3.id_name) != -1) {
                f = 1;
                break;
            }
            cur = cur->previous;
        }
        if (f != 1) {
            sprintf(msg[error_num++], "Undeclared variable %s", $3.id_name);
            error_flag[1] = 1;
        }
    } RB SEMICOLON
    | PRINT LB QUOTA STR_CONST QUOTA RB SEMICOLON
;
func_definition
    : type ID{
            insert_symbol(cur_header, $2.id_name, $1, "function", "");
        } LB{ create_symbol(); } type_arguments RB func_block
;
type_arguments
    : type_arguments COMMA arg
    | arg
    |
;
arg
    : type ID { insert_symbol(cur_header, $2.id_name, $1, "parameter", $1); }
;
func_block
    : LCB program RCB { dump_flag = 1; }
    | LCB program RET SEMICOLON RCB { dump_flag = 1; }
    | LCB program RET expression SEMICOLON RCB { dump_flag = 1; }
;
func
    : ID{
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, $1.id_name) != -1) {
                f = 1;
                break;
            }
            cur = cur->previous;
        }
        if (f != 1) {
            sprintf(msg[error_num++], "Undeclared function %s", $1.id_name);
            error_flag[1] = 1;
        }
    } LB arguments RB { $$ = $1; }
;
arguments
    : arguments COMMA expression {
        if($3.id_name) {
            Header *cur = cur_header;
            int f = 0;
            while (cur != NULL) {
                if(lookup_symbol(cur, $3.id_name) != -1) {
                    f = 1;
                    break;
                }
                cur = cur->previous;
            }
            if (f != 1) {
                sprintf(msg[error_num++], "Undeclared variable %s", $3.id_name);
                error_flag[1] = 1;
            }
        }
    }
    | expression {
        if($1.id_name) {
            Header *cur = cur_header;
            int f = 0;
            while (cur != NULL) {
                if(lookup_symbol(cur, $1.id_name) != -1) {
                    f = 1;
                    break;
                }
                cur = cur->previous;
            }
            if (f != 1) {
                sprintf(msg[error_num++], "Undeclared variable %s", $1.id_name);
                error_flag[1] = 1;
            }
        }
    }
    | 
;
%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n"
                    ".method public static main([Ljava/lang/String;)V\n");

    yyparse();
    if(error_flag[0] != 1) {
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);
    }

    fprintf(file, "\treturn\n"
                  ".end method\n");

    fclose(file);

    if(err_flag){
		remove("compiler_hw3.j");
	}
    return 0;
}

void yyerror(char *s)
{
    err_flag = 1;
    if((strcmp(s, "syntax error") == 0) && error_flag[0] == 0) {
        error_flag[0] = 1;
    } 
    else {
        //printf("%s\n", buf);
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
    }
}

/* stmbol table functions */
void create_symbol() {
    Header *p = malloc(sizeof(Header));
    p->depth = depth++;
    p->root = malloc(sizeof(Entry));
    p->root->next = NULL;
    p->tail = p->root;
    //printf("create a table: %d\n", p->depth);
    if (cur_header == NULL) {
        p->previous = NULL;
        cur_header = p;
        header_root = cur_header;
    }
    else {
        p->previous = cur_header;
        cur_header = p;
    }
}
void insert_symbol(Header *header, char* id_name, char* type, char* kind, char* attribute) {
    if (cur_header == NULL) {
        create_symbol();
        header = cur_header;
    }
    if (lookup_symbol(header, id_name) == -1) {
        Entry *temp = malloc(sizeof(Entry));
        temp->index = entry_num[header->depth]++;
        temp->name = id_name;
        temp->kind = kind;
        temp->type = type;
        temp->scope = header->depth;
        temp->attribute = "";
        if(header->previous != NULL){
            if(strcmp(kind, "variable") == 0)
                variable_num++;
            if(header->previous->tail->attribute == "")
                header->previous->tail->attribute = attribute;
            else {
                char* temp;
                temp = malloc(sizeof(char *));
                sprintf(temp,"%s, %s", header->previous->tail->attribute, attribute);
                header->previous->tail->attribute = temp;
            }
        }
        temp->next = NULL;
        header->tail->next = temp;
        header->tail = header->tail->next;
    }
    else {
        if(kind == "variable"){
            sprintf(msg[error_num++], "Redeclared variable %s", id_name);
            error_flag[1] = 1;
        }
        else if (kind == "function"){
            sprintf(msg[error_num++], "Redeclared function %s", id_name);
            error_flag[1] = 1;
        }    
    }
}
int lookup_symbol(Header *header, char *id_name) {
    if (header->root != NULL) {
        Entry *cur = header->root->next;
        while (cur != NULL) {
            if (strcmp(cur->name, id_name) == 0) {
                return cur->index;
            }
            else {
                cur = cur->next;
            }
        }
        return -1;
    }
    else {
        return -1;
    }
}
void dump_symbol() {
    if (cur_header->root->next != NULL) {
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        Entry *cur = cur_header->root->next;
        while(cur != NULL) {
            if(strcmp(cur->kind, "variable") == 0)
                variable_num--;
            if(cur->attribute != "") {
                printf("%-10d%-10s%-12s%-10s%-10d%s\n", cur->index, cur->name, cur->kind, cur->type, cur->scope, cur->attribute);
            }
            else {
                printf("%-10d%-10s%-12s%-10s%-10d\n", cur->index, cur->name, cur->kind, cur->type, cur->scope);
            }
            Entry *temp = cur;
            cur = cur->next;
            free(temp);
            temp = NULL;
        }
        printf("\n");
        entry_num[cur_header->depth] = 0;
    }
    cur_header = cur_header->previous;
    depth--;
}

/* code generation functions */
void code_gen(char const *s)
{
    if (!err_flag)
        fprintf(file, "%s", s);
}

void do_declaration(char *type, char *id_name, Value val)
{
    int flag = 0;
    if(strcmp(type,"int") == 0) {      
        if(strcmp(val.val_type, "FLOAT_T") == 0) {
            val.i_val = (int)val.f_val;
            flag = 1;                    
        }
        if(depth == 1) {
            sprintf(code, ".field public static %s I = %d\n", id_name, val.i_val);
        }
        else {
            if(flag == 1) code_gen("\tf2i\n");
            sprintf(code, "\tistore %d\n",variable_num-1);
        }
        code_gen(code);
    }
    else if(strcmp(type,"float") == 0) {
        if(strcmp(val.val_type, "INT_T") == 0) {
            val.f_val = (float)val.i_val;
            flag = 1;                      
        }
        if(depth == 1) {
            sprintf(code, ".field public static %s F = %f\n", id_name, val.f_val);
        }
        else {
            if(flag == 1) code_gen("\ti2f\n");
            sprintf(code, "\tfstore %d\n",variable_num-1);
        }
        code_gen(code);
    }
    else if(strcmp(type,"bool") == 0) {
        if(depth == 1) {
            sprintf(code, ".field public static %s Z = %d\n", id_name, val.b_val);
        }
        else {
            sprintf(code, "\tistore %d\n",variable_num-1);
        }
        code_gen(code);
    }
    else if(strcmp(type,"string") == 0) {
        if(depth != 1) {
            sprintf(code, "\tastore %d\n",variable_num-1);
        }
        code_gen(code);
    }
    else yyerror("Unsupported type");
}