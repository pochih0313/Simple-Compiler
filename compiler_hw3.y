/*	Definition section */
%{
#include "compiler.h" 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Entry Entry;
struct Entry {
    int index;
    int var_index;
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
char *return_type;
Entry *postfix_entry;
int label_num = 0;

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
void doPostfix(struct Entry *entry, char *op_type);
struct Value doMultiplication(char *left_type, char *right_type, char *op_type);
struct Value doAddition(char *left_type, char *right_type, char *op_type);
void doComparison(char *left_type, char *right_type, char *op_type);
%}

%union {
    struct Value value;
    char *type;
    char *op_type;
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
%type <op_type> cmp_op add_op mul_op post_op assign_op

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
            
            // If not redeclare variable
            if(!error_flag[1]) { 
                do_declaration($1,$2.id_name,$4);
            }
        }
    | type ID SEMICOLON {
            insert_symbol(cur_header, $2.id_name, $1, "variable", "");
            if(!error_flag[1]) {
                if(strcmp($1,"int") == 0) {      
                    if(depth == 1) {
                        // Global variable
                        sprintf(code, ".field public static %s I\n", $2.id_name);
                    }
                    else {
                        // Local variable
                        sprintf(code, "\tldc 0\n\tistore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp($1,"float") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s F\n", $2.id_name);
                    }
                    else {
                        sprintf(code, "\tldc 0.0\n\tfstore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp($1,"bool") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s Z\n", $2.id_name);
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

                // // Find the variable
                // Entry *tmp = cur->root->next;
                // while (tmp != NULL) {
                //     if (tmp->var_index == lookup_symbol(cur, $1.id_name)) {
                //         if(cur->depth == 0) {
                //             // Load global variable
                //             sprintf(code, "\tgetstatic compiler_hw3/%s %s\n", $1.id_name, tmp->type);
                //             code_gen(code);
                //         }
                //         else {
                //             // Load local variable
                //             if(strcmp(tmp->type,"int") == 0) {      
                //                 sprintf(code, "\tiload %d\n", tmp->var_index);
                //                 code_gen(code);
                //             }
                //             else if(strcmp(tmp->type,"float") == 0) {      
                //                 sprintf(code, "\tfload %d\n", tmp->var_index);
                //                 code_gen(code);
                //             }
                //             else if(strcmp(tmp->type,"string") == 0) {      
                //                 sprintf(code, "\taload %d\n", tmp->var_index);
                //                 code_gen(code);
                //             }
                //             else if(strcmp(tmp->type,"bool") == 0) {      
                //                 sprintf(code, "\tiload %d\n", tmp->var_index);
                //                 code_gen(code);
                //             }
                //             else yyerror("Unable to load");
                //         }                    
                //         break;
                //     }
                //     else {
                //         tmp = tmp->next;
                //     }
                // }
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
    | comparison_expr cmp_op addition_expr {
        $$.compute_type = "bool";
        doComparison($1.compute_type, $3.compute_type, $2);
    }
;
addition_expr
    : multiplication_expr { $$ = $1; }
    | addition_expr add_op multiplication_expr {
        $$ = doAddition($1.compute_type, $3.compute_type, $2);
    }
;
multiplication_expr
    : postfix_expr { $$ = $1; }
    | multiplication_expr mul_op postfix_expr {
        if(strcmp($2, "DIV_T") == 0 && ($3.i_val == 0 || $3.f_val == 0)) {
            yyerror("Can't be divided by zero");
        }
        else {
            $$ = doMultiplication($1.compute_type, $3.compute_type, $2);
        }
    }
;
postfix_expr
    : parenthesis { $$ = $1; }
    | parenthesis post_op { 
            $$ = $1;
            if(strcmp($1.val_type, "ID_T") == 0) {
                doPostfix(postfix_entry, $2);
            }
            else yyerror("Wrong value type for postfix expression");
        }         
;
parenthesis
    : constant { $$ = $1; }
    | ID {
            Header *cur = cur_header;
            int f = 0;
            while (cur != NULL) {
                if(lookup_symbol(cur, $1.id_name) != -1) {
                    f = 1;

                    // Find the variable
                    Entry *tmp = cur->root->next;
                    while (tmp != NULL) {
                        if (tmp->var_index == lookup_symbol(cur, $1.id_name)) {
                            postfix_entry = tmp; // For postfix expression
                            $1.compute_type = tmp->type;

                            if(cur->depth == 0) {
                                // Load global variable
                                sprintf(code, "\tgetstatic compiler_hw3/%s %s\n", $1.id_name, tmp->type);
                                code_gen(code);
                            }
                            else {
                                // Load local variable
                                if(strcmp(tmp->type,"int") == 0) {      
                                    sprintf(code, "\tiload %d\n", tmp->var_index);
                                    code_gen(code);
                                    
                                }
                                else if(strcmp(tmp->type,"float") == 0) {      
                                    sprintf(code, "\tfload %d\n", tmp->var_index);
                                    code_gen(code);
                                }
                                else if(strcmp(tmp->type,"string") == 0) {      
                                    sprintf(code, "\taload %d\n", tmp->var_index);
                                    code_gen(code);
                                }
                                else if(strcmp(tmp->type,"bool") == 0) {      
                                    sprintf(code, "\tiload %d\n", tmp->var_index);
                                    code_gen(code);
                                }
                                else yyerror("Unable to load");
                            }                    
                            break;
                        }
                        else {
                            tmp = tmp->next;
                        }
                    }
                    break;
                }
                cur = cur->previous;
            }
            if (f != 1) {
                sprintf(msg[error_num++], "Undeclared variable <%s>", $1.id_name);
                error_flag[1] = 1;
            }
            $$ = $1;
        }
    | LB expression RB { $$ = $2; }
    | func { $$ = $1; }
;
cmp_op
    : MT { $$ = "MT_T"; }
    | LT { $$ = "LT_T"; }
    | MTE { $$ = "MTE_T"; }
    | LTE { $$ = "LTE_T"; }
    | EQ { $$ = "EQ_T"; }
    | NE { $$ = "NE_T"; }
;
add_op
    : ADD { $$ = "ADD_T"; }
    | SUB { $$ = "SUB_T"; }
;
mul_op
    : MUL { $$ = "MUL_T"; }
    | DIV { $$ = "DIV_T"; }
    | MOD { $$ = "MOD_T"; }
;
post_op
    : INC { $$ = "INC_T"; }
    | DEC { $$ = "DEC_T"; }
;
assign_op
    : ASGN { $$ = "ASGN_T"; }
    | ADDASGN { $$ = "ADDASGN_T"; }
    | SUBASGN { $$ = "SUBASGN_T"; }
    | MULASGN { $$ = "MULASGN_T"; }
    | DIVASGN { $$ = "DIVASGN_T"; }
    | MODASGN { $$ = "MODASGN_T"; }
;
constant
    : I_CONST {
            $1.compute_type = "int";
            $$ = $1;
            sprintf(code, "\tldc %d\n", $1.i_val);
            code_gen(code);
        }
    | F_CONST {
            $1.compute_type = "float";
            $$ = $1;
            sprintf(code, "\tldc %f\n", $1.f_val);
            code_gen(code);
        }
    | QUOTA STR_CONST QUOTA {
            $2.compute_type = "string";
            $$ = $2;
            sprintf(code, "\tldc %s\n", $2.string);
            code_gen(code);
        }
    | TRUE {
            $1.compute_type = "bool";
            $$ = $1;
            code_gen("\tldc 1\n");
        }
    | FALSE {
            $1.compute_type = "bool";
            $$ = $1;
            code_gen("\tldc 0\n");
        }
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
        } LB{ create_symbol(); } type_arguments RB {
            
            // Get all attributes in function from table
            char *list[20];
            int n = 0;
            if(strcmp(cur_header->previous->tail->attribute,"") != 0) {
                char* temp;
                temp = malloc(sizeof(char *));
                sprintf(temp,"%s", cur_header->previous->tail->attribute);

                //Get attribute list
                char *pch;  
                pch = strtok(temp,", ");
                while(pch != NULL) {
                    list[n] = pch;
                    n++;
                    pch = strtok(NULL,", ");
                }
            }

            sprintf(code, ".method public static %s(", $2.id_name);
            code_gen(code);
            if(strcmp($2.id_name, "main") == 0)
                if(strcmp($1,"void") != 0)
                    yyerror("main should return void");
                else {
                    code_gen("[Ljava/lang/String;)V\n");
                    return_type = "void";
                }
            else {
                for(int i = 0; i < n; i++) {
                    if(strcmp(list[i], "int") == 0)
                        code_gen("I");
                    else if (strcmp(list[i], "float") == 0)
                        code_gen("F");
                    else if (strcmp(list[i], "bool") == 0)
                        code_gen("Z");
                    else if (strcmp(list[i], "void") == 0)
                        code_gen("V");
                    else if (strcmp(list[i], "string") == 0)
                        code_gen("[Ljava/lang/String;");
                }
                code_gen(")");

                // Return type
                if(strcmp($1, "int") == 0) {
                    code_gen("I\n");
                    return_type = "int";
                }
                else if (strcmp($1, "float") == 0) {
                    code_gen("F\n");
                    return_type = "float";
                }       
                else if (strcmp($1, "bool") == 0) {
                    code_gen("Z\n");
                    return_type = "bool";
                }
                else if (strcmp($1, "void") == 0) {
                    code_gen("V\n");
                    return_type = "void";
                }
                else if (strcmp($1, "string") == 0) {
                    code_gen("[Ljava/lang/String;\n");
                    return_type = "string";
                }
            }

            code_gen(".limit stack 50\n");
            code_gen(".limit locals 50\n");
        } func_block { code_gen(".end method\n"); }
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
    | LCB program RET SEMICOLON RCB { 
            if(strcmp(return_type, "void") == 0)
                code_gen("\treturn\n");
            else
                yyerror("Wrong return type");
            dump_flag = 1;
        }
    | LCB program RET expression SEMICOLON RCB {
            if(strcmp(return_type, "int") == 0 && strcmp($4.compute_type, "int") == 0) {
                code_gen("\tireturn\n");
            }  
            else if(strcmp(return_type, "int") == 0 && strcmp($4.compute_type, "float") == 0) {
                code_gen("\tf2i\n");
                code_gen("\tireturn\n");
            }
            else if(strcmp(return_type, "float") == 0 && strcmp($4.compute_type, "float") == 0) {
                code_gen("\tfreturn\n");
            }  
            else if(strcmp(return_type, "float") == 0 && strcmp($4.compute_type, "int") == 0) {
                code_gen("\ti2f\n");
                code_gen("\tfreturn\n");
            }
            else if(strcmp(return_type, "bool") == 0 && strcmp($4.compute_type, "bool") == 0) {
                code_gen("\tireturn\n");
            }
            else if(strcmp(return_type, "string") == 0 && strcmp($4.compute_type, "string") == 0) {
                code_gen("\tareturn\n");
            }
            else yyerror("Wrong return type");
                
            dump_flag = 1;
        }
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
                    ".super java/lang/Object\n");

    yyparse();
    if(error_flag[0] != 1) {
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);
    }

    // fprintf(file, "\treturn\n"
    //               ".end method\n");

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
            if(strcmp(kind, "variable") == 0) {
                temp->var_index = variable_num++;
            }
            else if(strcmp(kind, "parameter") == 0) {
                if(header->previous->tail->attribute == "")
                header->previous->tail->attribute = attribute;
                else {
                    char* temp;
                    temp = malloc(sizeof(char *));
                    sprintf(temp,"%s, %s", header->previous->tail->attribute, attribute);
                    header->previous->tail->attribute = temp;
                }
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
                return cur->var_index;
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
    if(strcmp(type,"int") == 0) {      
        if(depth == 1) {
            if(strcmp(val.val_type, "FLOAT_T") == 0) {
                val.i_val = (int)val.f_val;
                sprintf(code, ".field public static %s I = %d\n", id_name, val.i_val);
                code_gen(code);
            }
            else if(strcmp(val.val_type, "INT_T") == 0) {
                sprintf(code, ".field public static %s I = %d\n", id_name, val.i_val);
                code_gen(code);
            } 
            else yyerror("Can't declare global variable");
        }
        else {
            if(strcmp(val.compute_type, "float") == 0) {
                code_gen("\tf2i\n");
            }
            sprintf(code, "\tistore %d\n",variable_num-1);
            code_gen(code);
        }
    }
    else if(strcmp(type,"float") == 0) {
        if(depth == 1) {
            if(strcmp(val.val_type, "INT_T") == 0) {
                val.f_val = (float)val.i_val;    
                sprintf(code, ".field public static %s F = %f\n", id_name, val.f_val);
                code_gen(code);         
            }
            else if(strcmp(val.val_type, "FLOAT_T") == 0) {
                sprintf(code, ".field public static %s F = %f\n", id_name, val.f_val);
                code_gen(code);
            }
            else yyerror("Can't declare global variable");
        }
        else {
            if(strcmp(val.compute_type, "int") == 0) {
                code_gen("\ti2f\n");
            }
            sprintf(code, "\tfstore %d\n",variable_num-1);
            code_gen(code);
        }
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

void doPostfix(struct Entry *entry, char *op_type)
{
    if(strcmp(op_type, "INC_T") == 0) {
        if(strcmp(entry->type, "int") == 0) {
            code_gen("\tldc 1\n");
            code_gen("\tiadd\n");
            sprintf(code, "\tistore %d\n", entry->var_index);
            code_gen(code);
        }
        else if(strcmp(entry->type, "float") == 0) {
            code_gen("\tldc 1.0\n");
            code_gen("\tfadd\n");
            sprintf(code, "\tfstore %d\n", entry->var_index);
            code_gen(code);
        }
        else yyerror("wrong variable type");
    }
    else if(strcmp(op_type, "DEC_T") == 0) {
        if(strcmp(entry->type, "int") == 0) {
            code_gen("\tldc 1\n");
            code_gen("\tisub\n");
            sprintf(code, "\tistore %d\n", entry->var_index);
            code_gen(code);
        }
        else if(strcmp(entry->type, "float") == 0) {
            code_gen("\tldc 1.0\n");
            code_gen("\tfsub\n");
            sprintf(code, "\tfstore %d\n", entry->var_index);
            code_gen(code);
        }
        else yyerror("wrong variable type");
    }
}

struct Value doMultiplication(char *left_type, char *right_type, char *op_type)
{
    struct Value val;
    if(strcmp(op_type, "MUL_T") == 0) {
        if(strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\timul\n");
            val.compute_type = "int";
        }
        else if(strcmp(left_type, "int") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tswap\n");
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
            code_gen("\tfmul\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tfmul\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\ti2f\n");
            code_gen("\tfmul\n");
            val.compute_type = "float";
        }
        else yyerror("Wrong type for multiplication");
    }
    else if(strcmp(op_type, "DIV_T") == 0) {
        if(strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\tidiv\n");
            val.compute_type = "int";
        }
        else if(strcmp(left_type, "int") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tswap\n");
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
            code_gen("\tfdiv\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tfdiv\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\ti2f\n");
            code_gen("\tfdiv\n");
            val.compute_type = "float";
        }
        else yyerror("Wrong type for division");
    }
    else if(strcmp(op_type, "MOD_T") == 0) {
        if(strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\tirem\n");
            val.compute_type = "int";
        }
        else yyerror("Only int can be used in mod operation");
    }

    return val;
}

struct Value doAddition(char *left_type, char *right_type, char *op_type)
{
    struct Value val;
    if(strcmp(op_type, "ADD_T") == 0) {
        if(strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\tiadd\n");
            val.compute_type = "int";
        }
        else if(strcmp(left_type, "int") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tswap\n");
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
            code_gen("\tfadd\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tfadd\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\ti2f\n");
            code_gen("\tfadd\n");
            val.compute_type = "float";
        }
        else yyerror("Wrong type for addtion");
    }
    else if(strcmp(op_type, "SUB_T") == 0) {
        if(strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\tisub\n");
            val.compute_type = "int";
        }
        else if(strcmp(left_type, "int") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tswap\n");
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
            code_gen("\tfsub\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tfsub\n");
            val.compute_type = "float";
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\ti2f\n");
            code_gen("\tfsub\n");
            val.compute_type = "float";
        }
        else yyerror("Wrong type for addition");
    }

    return val;
}

void doComparison(char *left_type, char *right_type, char *op_type)
{
    if(strcmp(left_type, "int") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
        }
        else if(strcmp(left_type, "int") == 0 && strcmp(right_type, "float") == 0) {
            code_gen("\tswap\n");
            code_gen("\ti2f\n");
            code_gen("\tswap\n");
        }
        else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "int") == 0) {
            code_gen("\ti2f\n");
        }
        else yyerror("Wrong type for comparison");

        code_gen("\tfsub\n");

        if(strcmp(op_type, "LT_T") == 0) {
            sprintf(code, "\tiflt LABEL_%d_TRUE\n", label_num);
            code_gen(code);
        }
        else if(strcmp(op_type, "MT_T") == 0) {
            sprintf(code, "\tifgt LABEL_%d_TRUE\n", label_num);
            code_gen(code);
        }
        else if(strcmp(op_type, "LTE_T") == 0) {
            sprintf(code, "\tifle LABEL_%d_TRUE\n", label_num);
            code_gen(code);
        }
        else if(strcmp(op_type, "MTE_T") == 0) {
            sprintf(code, "\tifge LABEL_%d_TRUE\n", label_num);
            code_gen(code);
        }
        else if(strcmp(op_type, "EQ_T") == 0) {
            sprintf(code, "\tifeq LABEL_%d_TRUE\n", label_num);
            code_gen(code);
        }
        else if(strcmp(op_type, "NE_T") == 0) {
            sprintf(code, "\tifne LABEL_%d_TRUE\n", label_num);
            code_gen(code);
        }

        code_gen("\ticonst_0\n"); // Load int value 0 to the stack
        sprintf(code, "\tgoto LABEL_%d_FALSE\n", label_num);
        code_gen(code);
        sprintf(code, "LABEL_%d_TRUE:\n", label_num); // If true
        code_gen(code);
        code_gen("\ticonst_1\n"); // Load int value 1 to the stack
        sprintf(code, "LABEL_%d_FALSE:\n", label_num); //If false
        code_gen(code);
        

        label_num++;
}