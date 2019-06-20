/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

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
char *temp_list[20];
int temp_n = 0;
int param_num = 0;
struct Entry *temp_entry = NULL;
int if_count = 0;
int else_if_count = 0;
int while_count = 0;
int  last_zero = 0;

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
void load_variable(struct Entry *tmp);
void store_variable(struct Entry *tmp);
void do_declaration(char *type, char *id_name, Value val);
void doPostfix(struct Entry *entry, char *op_type);
struct Value doMultiplication(char *left_type, char *right_type, char *op_type);
struct Value doAddition(char *left_type, char *right_type, char *op_type);
void doComparison(char *left_type, char *right_type, char *op_type);
void doAssign(struct Entry *left, char *right_type, char *op_type);
void print_func(char *type);

#line 143 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    SEMICOLON = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    MOD = 268,
    INC = 269,
    DEC = 270,
    MT = 271,
    LT = 272,
    MTE = 273,
    LTE = 274,
    EQ = 275,
    NE = 276,
    ASGN = 277,
    ADDASGN = 278,
    SUBASGN = 279,
    MULASGN = 280,
    DIVASGN = 281,
    MODASGN = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LB = 286,
    RB = 287,
    LCB = 288,
    RCB = 289,
    LSB = 290,
    RSB = 291,
    COMMA = 292,
    RET = 293,
    QUOTA = 294,
    VOID = 295,
    INT = 296,
    FLOAT = 297,
    STRING = 298,
    BOOL = 299,
    ID = 300,
    I_CONST = 301,
    F_CONST = 302,
    STR_CONST = 303,
    TRUE = 304,
    FALSE = 305
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define INC 269
#define DEC 270
#define MT 271
#define LT 272
#define MTE 273
#define LTE 274
#define EQ 275
#define NE 276
#define ASGN 277
#define ADDASGN 278
#define SUBASGN 279
#define MULASGN 280
#define DIVASGN 281
#define MODASGN 282
#define AND 283
#define OR 284
#define NOT 285
#define LB 286
#define RB 287
#define LCB 288
#define RCB 289
#define LSB 290
#define RSB 291
#define COMMA 292
#define RET 293
#define QUOTA 294
#define VOID 295
#define INT 296
#define FLOAT 297
#define STRING 298
#define BOOL 299
#define ID 300
#define I_CONST 301
#define F_CONST 302
#define STR_CONST 303
#define TRUE 304
#define FALSE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 79 "compiler_hw3.y" /* yacc.c:355  */

    struct Value value;
    char *type;
    char *op_type;

#line 289 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 306 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   114,   115,   118,   119,   120,   121,   122,
     123,   126,   134,   180,   181,   182,   183,   184,   187,   188,
     191,   198,   205,   208,   208,   221,   221,   224,   228,   224,
     241,   242,   272,   275,   276,   283,   284,   293,   294,   300,
     301,   313,   314,   346,   347,   350,   351,   352,   353,   354,
     355,   358,   359,   362,   363,   364,   367,   368,   371,   372,
     373,   374,   375,   376,   379,   394,   409,   418,   427,   435,
     442,   451,   451,   481,   488,   490,   490,   488,   562,   563,
     564,   567,   570,   573,   579,   604,   604,   692,   720,   746
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT",
  "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN", "SUBASGN", "MULASGN",
  "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB",
  "LSB", "RSB", "COMMA", "RET", "QUOTA", "VOID", "INT", "FLOAT", "STRING",
  "BOOL", "ID", "I_CONST", "F_CONST", "STR_CONST", "TRUE", "FALSE",
  "$accept", "program", "stat", "declaration", "type", "compound_stat",
  "if_stat", "if_else_stmt", "$@1", "block", "$@2", "while_stat", "$@3",
  "$@4", "expression_stat", "expression", "comparison_expr",
  "addition_expr", "multiplication_expr", "postfix_expr", "parenthesis",
  "cmp_op", "add_op", "mul_op", "post_op", "assign_op", "constant",
  "print_func", "$@5", "func_definition", "$@6", "$@7", "$@8",
  "type_arguments", "arg", "func_block", "return_stmt", "func", "$@9",
  "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,  -104,    68,  -104,    -8,   175,  -104,   -34,   175,    -3,
     -38,  -104,  -104,  -104,  -104,  -104,   124,  -104,  -104,  -104,
    -104,  -104,  -104,   -18,  -104,  -104,    24,  -104,  -104,    27,
     191,    30,    21,  -104,    34,  -104,  -104,  -104,  -104,  -104,
     188,     6,  -104,   175,  -104,  -104,     9,  -104,    42,    23,
    -104,  -104,  -104,  -104,  -104,  -104,   175,    35,     0,    -2,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,   175,  -104,  -104,
     175,  -104,  -104,  -104,   175,  -104,  -104,  -104,  -104,    33,
      36,  -104,  -104,  -104,  -104,    59,   175,  -104,   175,    39,
    -104,  -104,  -104,    30,    21,  -104,    41,    66,  -104,    36,
    -104,  -104,   -21,    69,  -104,    85,    71,  -104,  -104,  -104,
     175,  -104,    60,   133,  -104,  -104,    31,    -7,  -104,  -104,
    -104,  -104,    60,    47,  -104,    85,  -104,   150,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     1,     0,     0,    27,     0,     0,     0,
       0,    17,    13,    14,    16,    15,    42,    64,    65,    69,
      70,     2,     5,     0,     6,    18,    20,    19,     7,     0,
      32,    33,    35,    37,    39,    41,     8,     9,    10,    44,
       0,    42,    23,     0,    66,    67,     0,    83,     0,     0,
      58,    59,    60,    61,    62,    63,     0,     0,    74,     0,
      30,    45,    46,    47,    48,    49,    50,     0,    51,    52,
       0,    53,    54,    55,     0,    56,    57,    40,    71,     0,
       0,    28,    43,    84,    68,     0,    89,    12,     0,     0,
      25,    22,    21,    34,    36,    38,     0,     0,    24,     0,
      31,    88,     0,     0,    75,     0,     0,    73,    29,    86,
       0,    11,    80,     0,    72,    87,     0,     0,    79,    26,
      81,    76,     0,     0,    78,     0,    77,     0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,   -99,  -104,  -104,  -103,  -104,    25,  -104,  -104,   -79,
    -104,  -104,  -104,  -104,  -104,    -5,  -104,    15,    17,    11,
    -104,  -104,  -104,  -104,  -104,  -104,    50,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   -31,  -104,  -104,  -104,  -104,  -104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    21,    22,    23,    24,    25,    26,    80,    92,
     105,    27,    43,    99,    28,    29,    30,    31,    32,    33,
      34,    67,    70,    74,    77,    56,    35,    36,    96,    37,
      89,   112,   123,   117,   118,   126,    38,    39,    57,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    98,     5,    46,    48,    47,   113,     7,    87,   116,
      49,   109,    44,    45,    -4,     1,   110,    -4,    -4,   116,
     108,    -4,    88,    40,    -4,   121,   127,    58,     8,    59,
     122,    90,    71,    72,    73,    60,    10,   -85,    81,    68,
      69,    82,    41,    17,    18,    -4,    19,    20,    75,    76,
      83,    85,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    84,    -4,    -4,    97,    86,   100,     3,    90,
     104,     4,     5,   106,   107,     6,   120,   111,     7,   114,
     125,   101,    93,   103,    91,    95,     1,    94,    -4,    -4,
      79,   124,    -4,     0,     0,    -4,     0,     0,     0,     8,
      11,    12,    13,    14,    15,   115,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -4,    19,    20,    -4,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,     4,     5,     0,     0,
       6,     0,     0,     7,     0,     0,    50,    51,    52,    53,
      54,    55,     0,     4,     5,   -85,     0,     6,     0,     0,
       7,     0,     0,     0,     8,     0,     0,   119,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     8,    19,    20,   128,     7,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     7,    19,
      20,     0,     0,     0,     0,     0,     8,    61,    62,    63,
      64,    65,    66,     0,    10,     0,     0,     0,     0,     0,
      41,    17,    18,     0,    19,    20,     0,    10,     0,     0,
       0,     0,     0,    78,    17,    18,     0,    19,    20
};

static const yytype_int8 yycheck[] =
{
       5,    80,     4,     8,     9,     8,   105,    10,     8,   112,
      48,    32,    46,    47,     0,     1,    37,     3,     4,   122,
      99,     7,    22,    31,    10,    32,   125,    45,    31,     5,
      37,    33,    11,    12,    13,     8,    39,    31,    43,     9,
      10,    32,    45,    46,    47,    31,    49,    50,    14,    15,
       8,    56,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    39,    49,    50,    32,    31,     8,     0,    33,
      31,     3,     4,    32,     8,     7,    45,     8,    10,     8,
      33,    86,    67,    88,    59,    74,     1,    70,     3,     4,
      40,   122,     7,    -1,    -1,    10,    -1,    -1,    -1,    31,
      40,    41,    42,    43,    44,   110,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    31,    49,    50,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,     3,     4,    -1,    -1,
       7,    -1,    -1,    10,    -1,    -1,    22,    23,    24,    25,
      26,    27,    -1,     3,     4,    31,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    31,    49,    50,    34,    10,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    10,    49,
      50,    -1,    -1,    -1,    -1,    -1,    31,    16,    17,    18,
      19,    20,    21,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    50,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    52,     0,     3,     4,     7,    10,    31,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    49,
      50,    53,    54,    55,    56,    57,    58,    62,    65,    66,
      67,    68,    69,    70,    71,    77,    78,    80,    87,    88,
      31,    45,    66,    63,    46,    47,    66,     8,    66,    48,
      22,    23,    24,    25,    26,    27,    76,    89,    45,     5,
       8,    16,    17,    18,    19,    20,    21,    72,     9,    10,
      73,    11,    12,    13,    74,    14,    15,    75,    45,    77,
      59,    66,    32,     8,    39,    66,    31,     8,    22,    81,
      33,    57,    60,    68,    69,    70,    79,    32,    60,    64,
       8,    66,    90,    66,    31,    61,    32,     8,    60,    32,
      37,     8,    82,    52,     8,    66,    55,    84,    85,    34,
      45,    32,    37,    83,    85,    33,    86,    52,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    56,    56,
      57,    57,    57,    59,    58,    61,    60,    63,    64,    62,
      65,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    79,    78,    78,    81,    82,    83,    80,    84,    84,
      84,    85,    86,    87,    87,    89,    88,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     0,     4,     0,     4,     0,     0,     5,
       2,     4,     1,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       1,     0,     6,     5,     0,     0,     0,     9,     3,     1,
       0,     2,     3,     2,     3,     0,     5,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 11:
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    {
            insert_symbol(cur_header, (yyvsp[-3].value).id_name, (yyvsp[-4].type), "variable", "");
            
            // If not redeclare variable
            if(!error_flag[1]) { 
                do_declaration((yyvsp[-4].type),(yyvsp[-3].value).id_name,(yyvsp[-1].value));
            }
        }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    {
            insert_symbol(cur_header, (yyvsp[-1].value).id_name, (yyvsp[-2].type), "variable", "");
            if(!error_flag[1]) {
                if(strcmp((yyvsp[-2].type),"int") == 0) {      
                    if(depth == 1) {
                        // Global variable
                        sprintf(code, ".field public static %s I\n", (yyvsp[-1].value).id_name);
                    }
                    else {
                        // Local variable
                        sprintf(code, "\tldc 0\n\tistore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp((yyvsp[-2].type),"float") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s F\n", (yyvsp[-1].value).id_name);
                    }
                    else {
                        sprintf(code, "\tldc 0.0\n\tfstore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp((yyvsp[-2].type),"bool") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s Z\n", (yyvsp[-1].value).id_name);
                    }
                    else {
                        sprintf(code, "\tldc 0\n\tistore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else if(strcmp((yyvsp[-2].type),"string") == 0) {
                    if(depth == 1) {
                        sprintf(code, ".field public static %s [Ljava/lang/String;\n", (yyvsp[-1].value).id_name);
                    }
                    else {
                        sprintf(code, "\tldc \"\"\n\tastore %d\n",variable_num-1);
                    }
                    code_gen(code);
                }
                else yyerror("Unsupported type");
            }
        }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 180 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 183 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "EXIT_IF_%d", if_count);
        code_gen(code);
        code_gen(":\n");
        if_count++;
        else_if_count = 0;
    }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "EXIT_IF_%d", if_count);
        code_gen(code);
        code_gen(":\n");
        if_count++;
        else_if_count = 0;
    }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "\tifeq LABEL_IF_%d_%d\n", if_count, else_if_count); // Jump if not true
        code_gen(code);
    }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 211 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "\tgoto EXIT_IF_%d\n", if_count);
        code_gen(code);
        sprintf(code, "LABEL_IF_%d_%d", if_count, else_if_count);
        code_gen(code);
        code_gen(":\n");
        else_if_count++;
    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 221 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 221 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_flag = 1; }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "LABEL_WHILE_%d", while_count);
        code_gen(code);
        code_gen(":\n");
    }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 228 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "\tifeq EXIT_WHILE_%d\n", while_count); // If not true, end while
        code_gen(code);
    }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 231 "compiler_hw3.y" /* yacc.c:1646  */
    {
        sprintf(code, "\tgoto LABEL_WHILE_%d\n", while_count);
        code_gen(code);
        sprintf(code, "EXIT_WHILE_%d", while_count);
        code_gen(code);
        code_gen(":\n");
        while_count++;
    }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 242 "compiler_hw3.y" /* yacc.c:1646  */
    {
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, (yyvsp[-3].value).id_name) != -1) {
                f = 1;
                // Find the variable
                Entry *tmp = cur->root->next;
                while (tmp != NULL) {
                    if (tmp->index == lookup_symbol(cur, (yyvsp[-3].value).id_name)) {
                        (yyvsp[-3].value).compute_type = tmp->type;
                        if (depth > 1)
                            doAssign(tmp, (yyvsp[-1].value).compute_type, (yyvsp[-2].op_type));
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
            sprintf(msg[error_num++], "Undeclared variable %s", (yyvsp[-3].value).id_name);
            error_flag[1] = 1;
        }        
    }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 272 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.value).compute_type = "bool";
        if (depth > 1)
            doComparison((yyvsp[-2].value).compute_type, (yyvsp[0].value).compute_type, (yyvsp[-1].op_type));
    }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 283 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 284 "compiler_hw3.y" /* yacc.c:1646  */
    {
        
        if (depth > 1) {
            (yyval.value) = doAddition((yyvsp[-2].value).compute_type, (yyvsp[0].value).compute_type, (yyvsp[-1].op_type));
        }
            
    }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 293 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 294 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if (depth > 1)
            (yyval.value) = doMultiplication((yyvsp[-2].value).compute_type, (yyvsp[0].value).compute_type, (yyvsp[-1].op_type));
    }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 300 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 301 "compiler_hw3.y" /* yacc.c:1646  */
    { 
            (yyval.value) = (yyvsp[-1].value);
            if((yyvsp[-1].value).val_type) {
                if(strcmp((yyvsp[-1].value).val_type, "ID_T") == 0) {
                    if (depth > 1)
                        doPostfix(postfix_entry, (yyvsp[0].op_type));
                }
                else yyerror("Wrong value type for postfix expression");
            }
        }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 313 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 314 "compiler_hw3.y" /* yacc.c:1646  */
    {
            Header *cur = cur_header;
            int f = 0;
            while (cur != NULL) {
                if(lookup_symbol(cur, (yyvsp[0].value).id_name) != -1) {
                    f = 1;

                    // Find the variable
                    Entry *tmp = cur->root->next;
                    while (tmp != NULL) {
                        if (tmp->index == lookup_symbol(cur, (yyvsp[0].value).id_name)) {
                            postfix_entry = tmp; // For postfix expression
                            (yyvsp[0].value).compute_type = tmp->type;
                            if(depth > 1)
                                load_variable(tmp); // Load variable from stack
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
                sprintf(msg[error_num++], "Undeclared variable <%s>", (yyvsp[0].value).id_name);
                error_flag[1] = 1;
            }
            last_zero = 0;
            (yyval.value) = (yyvsp[0].value);
        }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 346 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[-1].value); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    { last_zero = 0; (yyval.value) = (yyvsp[0].value); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 350 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "MT_T"; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 351 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "LT_T"; }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 352 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "MTE_T"; }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 353 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "LTE_T"; }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 354 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "EQ_T"; }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 355 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "NE_T"; }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 358 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "ADD_T"; }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "SUB_T"; }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 362 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "MUL_T"; }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 363 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "DIV_T"; }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 364 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "MOD_T"; }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 367 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "INC_T"; }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 368 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "DEC_T"; }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 371 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "ASGN_T"; }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 372 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "ADDASGN_T"; }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "SUBASGN_T"; }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "MULASGN_T"; }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 375 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "DIVASGN_T"; }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 376 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op_type) = "MODASGN_T"; }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 379 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[0].value).compute_type = "int";
            (yyval.value) = (yyvsp[0].value);
            if(depth > 1) {
                sprintf(code, "\tldc %d\n", (yyvsp[0].value).i_val);
                code_gen(code);
            }

            if((yyvsp[0].value).i_val == 0) {
                last_zero = 1;
            }
            else {
                last_zero = 0;
            }
        }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[0].value).compute_type = "float";
            (yyval.value) = (yyvsp[0].value);
            if(depth > 1) {
                sprintf(code, "\tldc %f\n", (yyvsp[0].value).f_val);
                code_gen(code);
            }

            if((yyvsp[0].value).f_val == 0) {
                last_zero = 1;
            }
            else {
                last_zero = 0;
            }
        }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 409 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[0].value).compute_type = "int";
            (yyvsp[0].value).i_val *= -1;
            (yyval.value) = (yyvsp[0].value);
            if(depth > 1) {
                sprintf(code, "\tldc %d\n", (yyvsp[0].value).i_val);
                code_gen(code);
            }
        }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 418 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[0].value).compute_type = "float";
            (yyvsp[0].value).f_val *= -1;
            (yyval.value) = (yyvsp[0].value);
            if(depth > 1) {
                sprintf(code, "\tldc %f\n", (yyvsp[0].value).f_val);
                code_gen(code);
            }
        }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 427 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].value).compute_type = "string";
            (yyval.value) = (yyvsp[-1].value);
            if(depth > 1) {
                sprintf(code, "\tldc \"%s\"\n", (yyvsp[-1].value).string);
                code_gen(code);
            }
        }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 435 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[0].value).compute_type = "bool";
            (yyval.value) = (yyvsp[0].value);
            if(depth > 1) {
                code_gen("\tldc 1\n");
            }
        }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 442 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyvsp[0].value).compute_type = "bool";
            (yyval.value) = (yyvsp[0].value);
            if(depth > 1) {
                code_gen("\tldc 0\n");
            }
        }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 451 "compiler_hw3.y" /* yacc.c:1646  */
    {
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, (yyvsp[0].value).id_name) != -1) {
                f = 1;

                // Find the variable
                Entry *tmp = cur->root->next;
                while (tmp != NULL) {
                    if (tmp->index == lookup_symbol(cur, (yyvsp[0].value).id_name)) {
                        if(depth > 1) {
                            load_variable(tmp); // Load variable from stack
                            print_func(tmp->type);
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
            sprintf(msg[error_num++], "Undeclared variable %s", (yyvsp[0].value).id_name);
            error_flag[1] = 1;
        }
    }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 481 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(depth > 1) {
            print_func((yyvsp[-2].value).compute_type);
        }
    }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 488 "compiler_hw3.y" /* yacc.c:1646  */
    {
            insert_symbol(cur_header, (yyvsp[0].value).id_name, (yyvsp[-1].type), "function", "");
        }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    {
            
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

            sprintf(code, ".method public static %s(", (yyvsp[-5].value).id_name);
            code_gen(code);
            if(strcmp((yyvsp[-5].value).id_name, "main") == 0)
                if(strcmp((yyvsp[-6].type),"void") != 0)
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
                if(strcmp((yyvsp[-6].type), "int") == 0) {
                    code_gen("I\n");
                    return_type = "int";
                }
                else if (strcmp((yyvsp[-6].type), "float") == 0) {
                    code_gen("F\n");
                    return_type = "float";
                }       
                else if (strcmp((yyvsp[-6].type), "bool") == 0) {
                    code_gen("Z\n");
                    return_type = "bool";
                }
                else if (strcmp((yyvsp[-6].type), "void") == 0) {
                    code_gen("V\n");
                    return_type = "void";
                }
                else if (strcmp((yyvsp[-6].type), "string") == 0) {
                    code_gen("[Ljava/lang/String;\n");
                    return_type = "string";
                }
            }

            code_gen(".limit stack 50\n");
            code_gen(".limit locals 50\n");
        }
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 559 "compiler_hw3.y" /* yacc.c:1646  */
    { code_gen(".end method\n"); }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 567 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol(cur_header, (yyvsp[0].value).id_name, (yyvsp[-1].type), "parameter", (yyvsp[-1].type)); }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 570 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_flag = 1; }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 573 "compiler_hw3.y" /* yacc.c:1646  */
    { 
            if(strcmp(return_type, "void") == 0)
                code_gen("\treturn\n");
            else
                yyerror("Wrong return type");
        }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 579 "compiler_hw3.y" /* yacc.c:1646  */
    {
            if(strcmp(return_type, "int") == 0 && strcmp((yyvsp[-1].value).compute_type, "int") == 0) {
                code_gen("\tireturn\n");
            }  
            else if(strcmp(return_type, "int") == 0 && strcmp((yyvsp[-1].value).compute_type, "float") == 0) {
                code_gen("\tf2i\n");
                code_gen("\tireturn\n");
            }
            else if(strcmp(return_type, "float") == 0 && strcmp((yyvsp[-1].value).compute_type, "float") == 0) {
                code_gen("\tfreturn\n");
            }  
            else if(strcmp(return_type, "float") == 0 && strcmp((yyvsp[-1].value).compute_type, "int") == 0) {
                code_gen("\ti2f\n");
                code_gen("\tfreturn\n");
            }
            else if(strcmp(return_type, "bool") == 0 && strcmp((yyvsp[-1].value).compute_type, "bool") == 0) {
                code_gen("\tireturn\n");
            }
            else if(strcmp(return_type, "string") == 0 && strcmp((yyvsp[-1].value).compute_type, "string") == 0) {
                code_gen("\tareturn\n");
            }
            else yyerror("Wrong return type");
        }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 604 "compiler_hw3.y" /* yacc.c:1646  */
    {
        Header *cur = cur_header;
        int f = 0;
        while (cur != NULL) {
            if(lookup_symbol(cur, (yyvsp[0].value).id_name) != -1) {
                f = 1;

                // Find the variable
                Entry *tmp = cur->root->next;
                while (tmp != NULL) {
                    if (tmp->index == lookup_symbol(cur, (yyvsp[0].value).id_name)) {
                        
                        (yyvsp[0].value).compute_type = tmp->type;
                        
                        // Get all attributes in function from table
                        if(strcmp(tmp->attribute,"") != 0) {
                            char* temp;
                            temp = malloc(sizeof(char *));
                            sprintf(temp,"%s", tmp->attribute);

                            //Get attribute list
                            char *pch;
                            pch = strtok(temp,", ");
                            while(pch != NULL) {
                                temp_list[temp_n] = pch;
                                temp_n++;
                                pch = strtok(NULL,", ");
                            }
                        }
                        if(depth > 1)
                            temp_entry = tmp;
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
            sprintf(msg[error_num++], "Undeclared function %s", (yyvsp[0].value).id_name);
            error_flag[1] = 1;
        }
        
    }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 651 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.value) = (yyvsp[-4].value);
        if(temp_entry) {
            // Invoke function
            sprintf(code, "\tinvokestatic compiler_hw3/%s(", temp_entry->name);
            code_gen(code);
            for (int i = 0; i < temp_n; i++) {
                if(strcmp(temp_list[i], "int") == 0)
                    code_gen("I");
                else if (strcmp(temp_list[i], "float") == 0)
                    code_gen("F");
                else if (strcmp(temp_list[i], "bool") == 0)
                    code_gen("Z");
                else if (strcmp(temp_list[i], "string") == 0)
                    code_gen("[Ljava/lang/String;");
            }
            code_gen(")");

            // Return type
            if(strcmp(temp_entry->type, "int") == 0) {
                code_gen("I\n");
            }
            else if (strcmp(temp_entry->type, "float") == 0) {
                code_gen("F\n");
            }       
            else if (strcmp(temp_entry->type, "bool") == 0) {
                code_gen("Z\n");
            }
            else if (strcmp(temp_entry->type, "void") == 0) {
                code_gen("V\n");
            }
            else if (strcmp(temp_entry->type, "string") == 0) {
                code_gen("[Ljava/lang/String;\n");
            }
            temp_entry = NULL;
            temp_n = 0;
            param_num = 0;
        }
    }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 692 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(error_flag[1] != 1) {
            if((yyvsp[0].value).val_type) {
                if(strcmp((yyvsp[0].value).val_type, "ID_T") == 0) {
                    Header *cur = cur_header;
                    int f = 0;
                    while (cur != NULL) {
                        if(lookup_symbol(cur, (yyvsp[0].value).id_name) != -1) {
                            f = 1;
                            break;
                        }
                        cur = cur->previous;
                    }
                    if (f != 1) {
                        sprintf(msg[error_num++], "Undeclared variable %s", (yyvsp[0].value).id_name);
                        error_flag[1] = 1;
                    }
                }
            }
            

            if(strcmp((yyvsp[0].value).compute_type, temp_list[param_num]) != 0) {
                if(param_num == temp_n) yyerror("Numbers of Parameter is not the same"); 
                else yyerror("Wrong parameter type");
            }
            param_num++;
        }
    }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 720 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(error_flag[1] != 1) {
            if((yyvsp[0].value).val_type) {
                if(strcmp((yyvsp[0].value).val_type, "ID_T") == 0) {
                    Header *cur = cur_header;
                    int f = 0;
                    while (cur != NULL) {
                        if(lookup_symbol(cur, (yyvsp[0].value).id_name) != -1) {
                            f = 1;
                            break;
                        }
                        cur = cur->previous;
                    }
                    if (f != 1) {
                        sprintf(msg[error_num++], "Undeclared variable %s", (yyvsp[0].value).id_name);
                        error_flag[1] = 1;
                    }
                }
            }
            
            if(strcmp((yyvsp[0].value).compute_type, temp_list[param_num]) != 0) {
                yyerror("Wrong parameter type");
            }
            param_num++;
        }
    }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 746 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp(temp_entry->attribute, "") != 0) yyerror("Prameter should be empty"); }
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2426 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 748 "compiler_hw3.y" /* yacc.c:1906  */


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
                temp->var_index = variable_num++;
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

void load_variable(struct Entry *tmp)
{
    if(tmp->scope == 0) {
        // Load global variable
        if(strcmp(tmp->type, "int") == 0)
            sprintf(code, "\tgetstatic compiler_hw3/%s I\n", tmp->name);
        else if (strcmp(tmp->type, "float") == 0)
            sprintf(code, "\tgetstatic compiler_hw3/%s F\n", tmp->name);
        else if (strcmp(tmp->type, "bool") == 0)
            sprintf(code, "\tgetstatic compiler_hw3/%s Z\n", tmp->name);
        else if (strcmp(tmp->type, "void") == 0)
            sprintf(code, "\tgetstatic compiler_hw3/%s V\n", tmp->name);
        else if (strcmp(tmp->type, "string") == 0)
            sprintf(code, "\tgetstatic compiler_hw3/%s [Ljava/lang/String;\n", tmp->name);
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
}

void store_variable(struct Entry *tmp)
{
    if(strcmp(tmp->type,"int") == 0) {
        if(tmp->scope == 0) {
            // Global variable
            sprintf(code, "\tputstatic compiler_hw3/%s I\n", tmp->name);
            code_gen(code);
        }
        else {
            // Local variable
            sprintf(code, "\tistore %d\n", tmp->var_index);
            code_gen(code);
        }
    }
    else if(strcmp(tmp->type,"float") == 0) {
        if(tmp->scope == 0) {
            // Global variable
            sprintf(code, "\tputstatic compiler_hw3/%s F\n", tmp->name);
            code_gen(code);
        }
        else {
            // Local variable
            sprintf(code, "\tfstore %d\n", tmp->var_index);
            code_gen(code);
        }
    }
    else if(strcmp(tmp->type,"bool") == 0) {
        if(tmp->scope == 0) {
            // Global variable
            sprintf(code, "\tputstatic compiler_hw3/%s Z\n", tmp->name);
            code_gen(code);
        }
        else {
            // Local variable
            sprintf(code, "\tistore %d\n", tmp->var_index);
            code_gen(code);
        }
    }
    else if(strcmp(tmp->type,"string") == 0) {
        if(tmp->scope == 0) {
            // Global variable
            sprintf(code, "\tputstatic compiler_hw3/%s [Ljava/lang/String;\n", tmp->name);
            code_gen(code);
        }
        else {
            // Local variable
            sprintf(code, "\tastore %d\n", tmp->var_index);
            code_gen(code);
        }
    }
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
        if(last_zero) {
            yyerror("Divided by zero");
        }
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
        else {
            yyerror("Only int can be used in mod operation");
        }
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
            code_gen("\tisub\n");
    }
    else if(strcmp(left_type, "int") == 0 && strcmp(right_type, "float") == 0) {
        code_gen("\tswap\n");
        code_gen("\ti2f\n");
        code_gen("\tswap\n");
        code_gen("\tfsub\n");
    }
    else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "int") == 0) {
        code_gen("\ti2f\n");
        code_gen("\tfsub\n");
    }
    else if(strcmp(left_type, "float") == 0 && strcmp(right_type, "float") == 0) {
        code_gen("\tfsub\n");
    }
    else yyerror("Wrong type for comparison");

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

void doAssign(struct Entry *left, char *right_type, char *op_type)
{
    if(strcmp(op_type, "ASGN_T") == 0) {
        if(strcmp(left->type,"int") == 0 && strcmp(right_type,"int") == 0) {
            store_variable(left);
        }
        else if(strcmp(left->type,"int") == 0 && strcmp(right_type,"float") == 0) {
            code_gen("\tf2i\n");
            store_variable(left);
        }
        else if(strcmp(left->type,"float") == 0 && strcmp(right_type,"float") == 0) {
            store_variable(left);
        }
        else if(strcmp(left->type,"float") == 0 && strcmp(right_type,"int") == 0) {
            code_gen("\ti2f\n");
            store_variable(left);
        }
        else if(strcmp(left->type,"bool") == 0 && strcmp(right_type,"bool") == 0) {
            store_variable(left);
        }
        else if(strcmp(left->type,"string") == 0 && strcmp(right_type,"string") == 0) {
            store_variable(left);
        }
        else yyerror("Wrong type for assignment");
    }
    else if(strcmp(op_type, "ADDASGN_T") == 0) {
        load_variable(left);
        code_gen("\tswap\n");
        doAddition(left->type,right_type,"ADD_T");
        store_variable(left);
    }
    else if(strcmp(op_type, "SUBASGN_T") == 0) {
        load_variable(left);
        code_gen("\tswap\n");
        doAddition(left->type,right_type,"SUB_T");
        store_variable(left);
    }
    else if(strcmp(op_type, "MULASGN_T") == 0) {
        load_variable(left);
        code_gen("\tswap\n");
        doMultiplication(left->type,right_type,"MUL_T");
        store_variable(left);
    }
    else if(strcmp(op_type, "DIVASGN_T") == 0) {
        load_variable(left);
        code_gen("\tswap\n");
        doMultiplication(left->type,right_type,"DIV_T");
        store_variable(left);
    }
    else if(strcmp(op_type, "MODASGN_T") == 0) {
        load_variable(left);
        code_gen("\tswap\n");
        doMultiplication(left->type,right_type,"MOD_T");
        store_variable(left);
    }
}

void print_func(char *type)
{
    code_gen("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
    code_gen("\tswap\n");
    if(strcmp(type, "int") == 0) {
        code_gen("\tinvokevirtual java/io/PrintStream/println(I)V\n");
    }
    else if(strcmp(type, "float") == 0) {
        code_gen("\tinvokevirtual java/io/PrintStream/println(F)V\n");
    }
    else if(strcmp(type, "string") == 0) {
        code_gen("\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
    }
    else if(strcmp(type, "bool") == 0) {
        code_gen("\tinvokevirtual java/io/PrintStream/println(I)V\n");
    }
    else yyerror("Wrong type for print function");
}
