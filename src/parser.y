%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sym_table.h"
#include "stat_and_trace.h"

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
%token DADD DSUB MUL DIV MOD ADD SUB
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
%right DADD DSUB

%start trans_unit

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
ident       = identifier
*/

trans_unit
    : trans_unit external_decl                                      { }
    | /* epsilon */                                                 { TRACE0("trans_unit");   global_stat_ctx.indent++;   }

external_decl
    : func_def                                                      { }
    | obj_def                                                       { }

func_def
    : type IDENT {
            TRACE("func_def", "begin");
            TRACE("func_def", "ret type: %s", "Hello");
            TRACE("func_def", "func ident: %s", $2);
            global_stat_ctx.num_param = 0;
        } L_PARENTHESES param_list_or_empty R_PARENTHESES {
            TRACE("func_def", "nums of param: %d", global_stat_ctx.num_param);
            global_stat_ctx.num_param = 0;
            global_stat_ctx.indent++;
        } cstmt {
            global_stat_ctx.indent--;
            TRACE("func_def", "end");
        }       

param_list_or_empty
    : param_list
    | /* epsilon */

param_list
    : type IDENT COMMA param_list                                   { global_stat_ctx.num_param++; TRACE("func_def", "param ident: %s ", $2);     }
    | type IDENT                                                    { global_stat_ctx.num_param++; TRACE("func_def", "param ident: %s ", $2);     }

stmts
    : stmts stmt                            { }
    | /* epsilon */

stmt
    : obj_def                               { }
    | cstmt                                 { }
    | estmt                                 { }
    | sstmt                                 { }
    | istmt                                 { }
    | jstmt                                 { }

obj_def
    : const_decl                            { }
    | var_decl                              { }
    | ary_decl                              { }

const_decl
    : CONST type {
            TRACE("const_decl", "begin");
            global_stat_ctx.indent++;
        } ident_decl_list SEMICOLON  {
            global_stat_ctx.indent--;
            TRACE("const_decl", "end");
        }

type
    : VOID
    | BOOL
    | INT
    | STRING
    | FLOAT
    | DOUBLE

var_decl
    : type ident_decl_list SEMICOLON {
            TRACE0("var_decl");
        }

ident_decl_list
    : ident_decl COMMA ident_decl_list
    | ident_decl

ident_decl
    : IDENT ASSIGN constexpr
    | IDENT

ary_decl
    : type IDENT bracket_list SEMICOLON {
            TRACE0("ary_decl");
        }

bracket_list
    : L_SQUARE_BRACKETS INT_LITERAL R_SQUARE_BRACKETS bracket_list
    | L_SQUARE_BRACKETS INT_LITERAL R_SQUARE_BRACKETS

cstmt
    : L_BRACKETS {
        TRACE("cstmt", "begin");
        global_stat_ctx.indent++;
    } stmts R_BRACKETS {
        global_stat_ctx.indent--;
        TRACE("cstmt", "numbers of stmt: %d", local_stat_ctx.num_substat);
        TRACE("cstmt", "end");
    }

/* no just expression statement, also contain some speicial statement, like print, bruh */
estmt
    : PRINT {
            TRACE("estmt", "begin");
            global_stat_ctx.indent++;
        } expression SEMICOLON {
            global_stat_ctx.indent--;
            TRACE("estmt", "end" );
        }
    | PRINTLN {
            TRACE("estmt", "begin");
            global_stat_ctx.indent++;
        } expression SEMICOLON {
            global_stat_ctx.indent--;
            TRACE("estmt", "end");
        }
    | READ IDENT {
            TRACE("estmt", "begin");
            TRACE("estmt", "ident: %s", $2);
        }  SEMICOLON {
            TRACE("estmt", "end");
        }
    | expr_preamble {
            TRACE("estmt", "begin");
            global_stat_ctx.indent++;
        } expression SEMICOLON {
            global_stat_ctx.indent--;
            TRACE("estmt", "end");
        }      
    | SEMICOLON { TRACE("estmt", "empty"); }

expr_preamble
    :   /* */

sstmt
    : IF L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt                                       { }
    | IF L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt ELSE estmt_or_cstmt                   { }

estmt_or_cstmt
    : estmt
    | cstmt

istmt
    : WHILE L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt                                                 { }
    | FOR L_PARENTHESES expression SEMICOLON expression SEMICOLON expression R_PARENTHESES estmt_or_cstmt        { }
    | FOREACH L_PARENTHESES IDENT COLON num RANGE num R_PARENTHESES estmt_or_cstmt                               { }

jstmt
    : RETURN {
            TRACE("jstmt", "begin");
            global_stat_ctx.indent++;
        } expr_or_none SEMICOLON {
            global_stat_ctx.indent--;
            /* record: has expr or not */
            TRACE("jstmt", "end");
        }

expr_or_none
    : expression            {  /* ctx has expr = true ; */ }
    | /* epsilon */         {  /* ctx has expr = false; */ }

bool_expr
    : expression

num
    : IDENT
    | INT_LITERAL

constexpr
    : INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | TRUE
    | FALSE

/* One Confliction Below */
expression
    : expression ADD    expression                          { TRACE0("ADD");                 }
    | expression SUB    expression                          { TRACE0("SUB");                 }
    | expression MUL    expression                          { TRACE0("MUL");                 }
    | expression DIV    expression                          { TRACE0("DIV");                 }
    | expression MOD    expression                          { TRACE0("MOD");                 }
    | expression GT     expression                          { TRACE0("GT ");                 }
    | expression GE     expression                          { TRACE0("GE ");                 }
    | expression LT     expression                          { TRACE0("LT ");                 }
    | expression LE     expression                          { TRACE0("LE ");                 }
    | expression EQ     expression                          { TRACE0("EQ ");                 }
    | expression NE     expression                          { TRACE0("NE");                 }
    | expression AND    expression                          { TRACE0("AND");                 }
    | expression OR     expression                          { TRACE0("OR");                 }
    | expression ASSIGN expression                          { TRACE0("ASSIGN");                 }
    | expression DADD                                       { TRACE0("DADD");         }
    | expression DSUB                                       { TRACE0("DSUB");         }    
    | NOT expression                                        { TRACE0("NOT");          }
    | SUB expression %prec USUB                             { TRACE0("SUB(Unary)");   }
    | L_PARENTHESES expression R_PARENTHESES                { TRACE0("PARENTHESE");   }
    | IDENT                                                 { TRACE0("IDNET");          }
    | literal                                               { TRACE0("literal");;         }
    | ary_invoke                                            { TRACE0("ary_invoke");          }
    | func_invoke                                           { TRACE0("func_invoke");          }

literal
    : INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | TRUE
    | FALSE

ary_invoke
    : IDENT dim_expr_list

dim_expr_list
    : L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS dim_expr_list
    | L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS

func_invoke
    : IDENT L_PARENTHESES arg_expr_list R_PARENTHESES

arg_expr_list
    : expression
    | arg_expr_list COMMA expression
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
