%{
#include <stdio.h>
#include <stdlib.h>
extern void yyerror(char *s);
char yylex();
%}

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

%token ADD
%token DOUBLE_ADD
%token SUB
%token DOUBLE_SUB
%token MUL
%token DIV
%token MOD
%token ASSIGN
%token LT
%token LE
%token GT
%token GE
%token EQ
%token NE
%token AND
%token OR
%token NOT

%token BOOL
%token BREAK
%token CASE
%token CHAR
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token EXTERN
%token FALSE
%token FLOAT
%token FOR
%token FOREACH
%token IF
%token INT
%token PRINT
%token PRINTLN
%token READ
%token RETURN
%token SWITCH
%token TRUE
%token VOID
%token WHILE
%token STRING

%token IDENT
%token INT_LITERAL
%token FLOAT_LITERAL
%token STRING_LITERAL

%start translation_unit

%left OR
%left AND
%left NOT
%left LT LE GT GE EQ NE
%left ADD SUB
%left MUL DIV MOD
%right DOUBLE_ADD DOUBLE_SUB USUB

%%
translation_unit 
    : expression
    ;


decl_type_list
    : decl_type decl_type_list
    | /* epsilon */
    ;

decl_type
    : constant_decl
    | variable_decl
    | array_decl

constant_decl
    : CONST type IDENT EQ const_expr SEMICOLON

type
    : BOOL
    | FLOAT
    | INT { printf("int");}
    | STRING
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

global_func_list
    : global_func global_func_list
    | /* epsilon */

global_func
    : return_type IDENT L_PARENTHESES param_list R_PARENTHESES block
    ;

return_type
    : type
    | VOID
    ;

param_list
    : type IDENT COMMA param_list
    | type IDENT
    ;

statement
    : block
    | simple
    | conditional
    | loop
    | return
    | procedure_invoke
    ;

block
    : L_BRACKETS block_compnent_list R_BRACKETS

block_compnent_list
    : decl_type block_compnent_list
    | statement block_compnent_list
    | /* epsilon */
    ;

simple
    : simple_body SEMICOLON
    ;

simple_body
    : IDENT ASSIGN expression
    | PRINT expression
    | PRINTLN expression
    | READ IDENT
    | IDENT DOUBLE_ADD
    | IDENT DOUBLE_SUB
    | /* epsilon */
    ;

conditional
    : IF L_PARENTHESES bool_expr R_PARENTHESES simple_or_blk ELSE simple_or_blk
    | IF L_PARENTHESES bool_expr R_PARENTHESES

simple_or_blk
    : simple
    | block
    ;

loop
    : WHILE L_PARENTHESES bool_expr R_PARENTHESES simple_or_blk
    | FOR L_PARENTHESES simple_body SEMICOLON bool_expr SEMICOLON simple_body R_PARENTHESES simple_body
    | FOREACH L_PARENTHESES IDENT SEMICOLON num RANGE num R_PARENTHESES simple_or_blk

return
    : RETURN expression SEMICOLON
    | RETURN SEMICOLON
    ;

procedure_invoke
    : IDENT L_PARENTHESES expr_list R_PARENTHESES SEMICOLON

expr_list
    : expression COMMA expr_list
    | expression
    | /* epsilon */
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


expression
    : expression ADD expression { $$ = $1 + $3; }
    | expression SUB expression
    | expression MUL expression %prec USUB
    | expression DIV expression
    | expression MOD expression
    | expression GT expression
    | expression GE expression
    | expression LT expression
    | expression LE expression
    | expression EQ expression
    | expression NE expression
    | expression AND expression
    | expression OR expression
    | NOT expression
    | L_PARENTHESES expression L_PARENTHESES
    | IDENT { printf("ident");}
    | literal { }
    | array_invoke
    | func_invoke
    ;

literal
    : INT_LITERAL {printf("get int_literal"); $$ = $1;}
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
    : IDENT L_PARENTHESES argument_list R_PARENTHESES
    ;

argument_list
    : expression COMMA argument_list
    | expression
    | /* epsilon */
    ;
%%

#include <stdio.h>

void yyerror(char *s) {
    printf("ERROR:%s\n", s);
}

int main() {
    yyparse();
    return 0;
}