%{
#include <stdio.h>
#include <stdlib.h>
#include "sym_table.h"

struct StatContext {
    int indent;
    int num_stmt;
    int num_param;
    int num_arg;
} stat_ctx;

#define TRACE(fmt, ...)    {   for (int i = 0; i < stat_ctx.indent; i++) putchar('\t'); printf(fmt"\n", ##__VA_ARGS__);} while(0)

extern void yyerror(char *s);
extern int yylex();

#define YYDEDUG 1
extern char* yytext;

typedef struct IdentDecl {
    char *name;
} IdentDecl;
%}

/* All in one */
%union {
    int     ival;       // for integer literals
    float   fval;       // for floating point literals
    char   *sval;       // for string literals
    char   *idname;     // for identifier name
}

%token DOT
%token RANGE
%token COMMA
%token COLON
%token SEMICOLON
%token L_PARENTHESES
%token R_PARENTHESES
%token L_SQUARE_BRACKETS
%token R_SQUARE_BRACKETS
%token L_BRACKETS
%token R_BRACKETS

/* Todo: Implement C Operator Precedence */

%token DOUBLE_ADD DOUBLE_SUB MUL DIV MOD ADD SUB
%token LT LE GT GE EQ NE AND OR
%token TERNARY ASSIGN

/* Keywords */
%token BOOL BREAK CASE CHAR CONST CONTINUE DEFAULT
%token DO DOUBLE ELSE EXTERN FALSE FLOAT FOR
%token FOREACH IF INT PRINT PRINTLN READ RETURN
%token SWITCH TRUE VOID WHILE STRING

%token <ival>       INT_LITERAL
%token <fval>       FLOAT_LITERAL
%token <sval>       STRING_LITERAL
%token <idname>     IDENT

%left OR
%left AND
%left NOT
%right ASSIGN
%left LT LE GT GE
%left EQ NE
%left ADD SUB
%left MUL DIV MOD
%right USUB
%right DOUBLE_ADD DOUBLE_SUB

%start translation_unit

%%

/*
stmt        = statement
stmts       = statements

cstmt       = compound statement
estmt       = expression statement
sstmt       = selection statement
istmt       = iteration statement
jstmt       = jump statement

arg         = argument
param       = parameter
decl        = declaration
*/

translation_unit
    : translation_unit external_decl                                { }
    | /* epsilon */                                                 { TRACE("Reducing to translation_unit");    stat_ctx.indent++;}
    ;

external_decl
    : func_def                                                      { }
    | obj_def                                                       { TRACE("Reducing to obj_def");    }
    ;

func_def
    : type IDENT L_PARENTHESES param_list R_PARENTHESES             {
            TRACE("Reducing to func, nums of param:%d", stat_ctx.num_param);
            stat_ctx.num_param = 0; stat_ctx.indent++;
        } cstmt { stat_ctx.indent--; }       
    | type IDENT L_PARENTHESES R_PARENTHESES cstmt                  {
            TRACE("Reducing to func, nums of param:0");
            stat_ctx.indent++;               
        } cstmt { stat_ctx.indent--; }    
    ;

param_list
    : type IDENT COMMA param_list                                   { stat_ctx.num_param++; }
    | type IDENT                                                    { stat_ctx.num_param++;   }
    ;

stmts
    : stmts stmt                            {   }
    | /* epsilon */
    ;

stmt
    : obj_def                               { TRACE("Reducing to obj_def");       }
    | cstmt                                 { TRACE("Reducing to cstmt ");         }
    | estmt                                 { TRACE("Reducing to estmt ");         }
    | sstmt                                 { TRACE("Reducing to sstmt ");         }
    | istmt                                 { TRACE("Reducing to istmt");         }
    | jstmt                                 { TRACE("Reducing to jstmt");         }
    ;

obj_def
    : constant_decl
    | variable_decl
    | array_decl
    ;

constant_decl
    : CONST type IDENT ASSIGN const_expr SEMICOLON
    ;

type
    : VOID
    | BOOL
    | INT
    | STRING
    | FLOAT
    | DOUBLE
    ;

variable_decl
    : type ident_decl_list SEMICOLON
    ;

ident_decl_list
    : ident_decl COMMA ident_decl_list
    | ident_decl
    ;

ident_decl
    : IDENT ASSIGN const_expr
    | IDENT
    ;

array_decl
    : type IDENT bracket_list SEMICOLON

bracket_list
    : L_SQUARE_BRACKETS INT_LITERAL R_SQUARE_BRACKETS bracket_list
    | L_SQUARE_BRACKETS INT_LITERAL R_SQUARE_BRACKETS
    ;

cstmt
    : L_BRACKETS stmts R_BRACKETS
    ;

/* no just expression statement, also contain some speicial statement, like print, bruh */
estmt
    : PRINT expression SEMICOLON                { }
    | PRINTLN expression SEMICOLON              { }
    | READ IDENT SEMICOLON                      { }
    | expression SEMICOLON                      { }      
    | SEMICOLON                                 { }
    ;

sstmt
    : IF L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt                                       { }
    | IF L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt ELSE estmt_or_cstmt                   { }
    ;

estmt_or_cstmt
    : estmt
    | cstmt
    ;

istmt
    : WHILE L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt                                                 { }
    | FOR L_PARENTHESES expression SEMICOLON expression SEMICOLON expression R_PARENTHESES estmt_or_cstmt        { }
    | FOREACH L_PARENTHESES IDENT COLON num RANGE num R_PARENTHESES estmt_or_cstmt                               { }
    ;

jstmt
    : RETURN expression SEMICOLON
    | RETURN SEMICOLON
    ;

bool_expr
    : expression
    ;

num
    : IDENT
    | INT_LITERAL
    ;

const_expr
    : INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | TRUE
    | FALSE
    ;

/* One Confliction Below */
expression
    : expression ADD expression                                     { TRACE("Reducing to ADD"); }
    | expression SUB expression                                     { TRACE("Reducing to SUB"); }
    | expression MUL expression                                     { TRACE("Reducing to MUL"); }
    | expression DIV expression                                     { TRACE("Reducing to DIV"); }
    | expression MOD expression                                     { TRACE("Reducing to MOD"); }
    | expression GT expression                                      { TRACE("Reducing to GT"); }
    | expression GE expression                                      { TRACE("Reducing to GE"); }
    | expression LT expression                                      { TRACE("Reducing to LT"); }
    | expression LE expression                                      { TRACE("Reducing to LE"); }
    | expression EQ expression                                      { TRACE("Reducing to EQ"); }
    | expression NE expression                                      { TRACE("Reducing to NE"); }
    | expression AND expression                                     { TRACE("Reducing to AND"); }
    | expression OR expression                                      { TRACE("Reducing to OR"); }
    | expression ASSIGN expression                                  { TRACE("Reducing to ASSIGN"); }
    | expression DOUBLE_ADD                                         { TRACE("Reducing to DOUBLE_ADD"); }
    | expression DOUBLE_SUB                                         { TRACE("Reducing to DOUBLE_SUB"); }    
    | NOT expression                                                { TRACE("Reducing to NOT"); }
    | SUB expression %prec USUB                                     { TRACE("Reducing to SUB(Unary)"); }
    | L_PARENTHESES expression R_PARENTHESES                        { TRACE("Reducing to PARENTHESE"); }
    | IDENT                                                         { TRACE("Reducing to IDNET"); }
    | literal                                                       { TRACE("Reducing to LITERAL"); }
    | array_invoke                                                  { TRACE("Reducing to ARRAY"); }
    | func_invoke                                                   { TRACE("Reducing to FUNC_INVOKE"); }
    ;

literal
    : INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | TRUE
    | FALSE
    ;

array_invoke
    : IDENT dim_expr_list
    ;

dim_expr_list
    : L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS dim_expr_list
    | L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS
    ;

func_invoke
    : IDENT L_PARENTHESES arg_expr_list R_PARENTHESES                   {}
    ;

arg_expr_list
    : expression
    | arg_expr_list COMMA expression
    ;
%%

void yyerror(char *msg) {
    printf("ERROR: %s\n", msg);
}

void traverse_ast_tree() {

}

void init_sym_table() {

}
void check_main_function() {}

int main() {
    init_sym_table;

    printf("Start to parsing program:\n");
    yyparse();

    check_main_function();
    traverse_ast_tree();
    return 0;
}
