%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
    int     type_id;
    
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
%token LT LE GT GE EQ NE AND OR NOT
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
            TRACE("func_def", "func ident: %s", $2);
            global_stat_ctx.num_param = 0;

            memset(&global_stat_ctx.sym,0 ,sizeof(Symbol));
            global_stat_ctx.sym.base_type = global_stat_ctx.type;
            global_stat_ctx.sym.is_func = true;
            strcpy(global_stat_ctx.sym.name, $2);

            add_symtab_layer();
        } L_PARENTHESES param_list_or_empty R_PARENTHESES {
            global_stat_ctx.sym.param_num = global_stat_ctx.num_param;
            if (insert_parent(&global_stat_ctx.sym) == SYMTAB_ERR_DUP) {
                ERR("symbol tabel name conflict.");
            }

            global_stat_ctx.num_param = 0;
            global_stat_ctx.indent++;
        } fcstmt {
            print_symtab_ctx();
            delete_symtab_layer();
            global_stat_ctx.indent--;
            TRACE("func_def", "end");
        }

/* special case */
fcstmt
    : L_BRACKETS {
            TRACE("fcstmt", "begin");
            global_stat_ctx.indent++;
        } stmts R_BRACKETS {
            global_stat_ctx.indent--;
            TRACE("fcstmt", "end");
        }

param_list_or_empty
    : param_list
    | /* epsilon */

param_list
    : param_list COMMA type IDENT {
            global_stat_ctx.sym.func_param_type[global_stat_ctx.num_param] = global_stat_ctx.type;

            Symbol sym = {};
            sym.base_type = global_stat_ctx.type;
            strcpy(sym.name, $4);
            if (insert(&sym) == SYMTAB_ERR_DUP) {
                ERR("symbol tabel name conflict.");
            }

            global_stat_ctx.num_param++;
            TRACE("func_def", "param ident: %s", $4);
        }
    | type IDENT {
            global_stat_ctx.sym.func_param_type[global_stat_ctx.num_param] = global_stat_ctx.type;

            Symbol sym = {};
            sym.base_type = global_stat_ctx.type;
            strcpy(sym.name, $2);
            if (insert(&sym) == SYMTAB_ERR_DUP) {
                ERR("symbol tabel name conflict.");
            }

            global_stat_ctx.num_param++;
            TRACE("func_def", "param ident: %s", $2);
        }

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
            global_stat_ctx.is_const = true;
        } ident_decl_list SEMICOLON  {
            global_stat_ctx.is_const = false;
            global_stat_ctx.indent--;
            TRACE("const_decl", "end");
        }

type
    : VOID                                  { global_stat_ctx.type = VOID;      }
    | BOOL                                  { global_stat_ctx.type = BOOL;      }
    | INT                                   { global_stat_ctx.type = INT;       }
    | STRING                                { global_stat_ctx.type = STRING;    }
    | FLOAT                                 { global_stat_ctx.type = FLOAT;     }
    | DOUBLE                                { global_stat_ctx.type = DOUBLE;    }

var_decl
    : type ident_decl_list SEMICOLON {
        TRACE("var_decl", "end");
    }

ident_decl_list
    : ident_decl COMMA ident_decl_list
    | ident_decl

ident_decl
    : IDENT decl_init_or_none {

            Symbol sym = {};
            sym.base_type = global_stat_ctx.type;
            sym.is_const = global_stat_ctx.is_const;
            strcpy(sym.name, $1);
            if (insert(&sym) == SYMTAB_ERR_DUP) {
                ERR("symbol tabel name conflict.");
            }

            TRACE("var_decl", "ident: %s", $1);
        }

decl_init_or_none                          
    : ASSIGN constexpr                      { TRACE("var_decl", "have initilizer");         }
    | /* epsilon */                         { TRACE("var_decl", "not have initializer");    }    

ary_decl
    : type IDENT {

            memset(&global_stat_ctx.sym,0 ,sizeof(Symbol));
            global_stat_ctx.sym.base_type = global_stat_ctx.type;
            global_stat_ctx.sym.is_array = true;
            strcpy(global_stat_ctx.sym.name, $2);
            global_stat_ctx.sym.ary_dim_num = 0;

        } bracket_list SEMICOLON {
            if (insert(&global_stat_ctx.sym) == SYMTAB_ERR_DUP) {
                ERR("symbol tabel name conflict.");
            }
            TRACE("ary_decl", "ident: %s", $2);
        }

bracket_list
    : L_SQUARE_BRACKETS INT_LITERAL R_SQUARE_BRACKETS bracket_list {
            global_stat_ctx.sym.ary_dim[global_stat_ctx.sym.ary_dim_num] = $2;
            global_stat_ctx.sym.ary_dim_num++;
        }
    | L_SQUARE_BRACKETS INT_LITERAL R_SQUARE_BRACKETS {
            global_stat_ctx.sym.ary_dim[global_stat_ctx.sym.ary_dim_num] = $2;
            global_stat_ctx.sym.ary_dim_num++;
        }

cstmt
    : L_BRACKETS {
            TRACE("cstmt", "begin");
            global_stat_ctx.indent++;
            add_symtab_layer();
        } stmts {
            print_symtab_ctx();
            delete_symtab_layer();
        } R_BRACKETS {
            global_stat_ctx.indent--;
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
    : IF {
            TRACE0("if");
        } L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt else_part

else_part
    : ELSE {
        } estmt_or_cstmt {
        }
    | /* epsilon */

estmt_or_cstmt
    : estmt
    | cstmt
istmt
    : WHILE {
            TRACE0("while");
        } L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt
    | FOR {
            TRACE0("for");
        } L_PARENTHESES expression SEMICOLON expression SEMICOLON expression R_PARENTHESES estmt_or_cstmt
    | FOREACH {
            TRACE0("foreach");
        } L_PARENTHESES IDENT COLON num RANGE num R_PARENTHESES estmt_or_cstmt

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
    : expression

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
    | expression ASSIGN expression                          { TRACE0("ASSIGN");                     }
    | expression DADD                                       { TRACE0("DADD");                       }
    | expression DSUB                                       { TRACE0("DSUB");                       }    
    | NOT expression                                        { TRACE0("NOT");                        }
    | SUB expression %prec USUB                             { TRACE0("SUB(Unary)");                 }
    | L_PARENTHESES expression R_PARENTHESES                { TRACE0("PARENTHESE");                 }
    | IDENT {
            if (!search($1)) {
                ERR("Identifier not exists.");
            }
            TRACE("IDNET", "ident:%s", $1);
        }
    | literal                                               { }
    | ary_invoke                                            { }
    | func_invoke                                           { }

literal
    : INT_LITERAL                                           { TRACE("literal", "int literal: %d", $1);          }
    | FLOAT_LITERAL                                         { TRACE("literal", "float literal: %f", $1);        }
    | STRING_LITERAL                                        { TRACE("literal", "string literal: %s", $1);       }
    | TRUE                                                  { TRACE("literal", "bool literal: true");           }
    | FALSE                                                 { TRACE("literal", "bool literal: false");          }

ary_invoke
    : IDENT dim_expr_list {
        if (!search($1)) {
            ERR("Identifier not exists.");
        }
        TRACE("ary_invoke", "ident: %s", $1);
    }

dim_expr_list
    : L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS dim_expr_list
    | L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS

func_invoke
    : IDENT L_PARENTHESES arg_expr_list R_PARENTHESES {
            if (!search($1)) {
                ERR("Identifier not exists.");
            }
            TRACE("func_invoke", "ident: %s", $1);
        }

arg_expr_list
    : expression
    | arg_expr_list COMMA expression
%%

void yyerror(char *msg) {
    printf("ERROR: %s\n", msg);
}

void check_main_function() {
    Symbol *sym = search("main");
    if (sym) {
        if (sym->base_type != VOID) {
            ERR("main func's return type should be void\n");
        }
        if (sym->param_num != 0) {
            ERR("main func shouldnt have param.\n");
        }
    } else {
        ERR("main func not exists.\n");
    }

}

int main() {
    init_symtab_ctx();
    printf("Start to parsing program:\n");
    yyparse();

    printf("\n");
    print_symtab_ctx();

    check_main_function();

    return 0;
}
