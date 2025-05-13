%{
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

#define ET_INT      1
#define ET_BOOL     2
#define ET_FLOAT    3
#define ET_DOUBLE   4
#define ET_STRING   5
#define ET_VOID     6

int check_binary_type(int left, int right, char *op) {
    if (left != right) {
        ERR("type mismatch in operation '%s'", op);
        return -1;
    }
    return left;
}

int yacctype_to_ettype(int yacctype);
%}

/* All in one */
%union {
    int              ival;       // for integer literals
    float            fval;       // for floating point literals
    char            *sval;       // for string literals
    char            *idname;     // for identifier name

    struct ParseInfo {
        int             type;
        int             is_object;
        int             is_array;
        int             is_func;
        int             is_const;
        int             func_param_type[16];
        int             ary_dim[16];
    } parse_info;

}

%type <parse_info> expression ident literal ary_invoke func_invoke jmp_expr_or_none

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
                ERR("identifier conflict: %s", $2);
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
                ERR("identifier conflict: %s", $4);
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
                ERR("identifier conflict: %s", $2);
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
    : VOID                                  { global_stat_ctx.type = ET_VOID;      }
    | BOOL                                  { global_stat_ctx.type = ET_BOOL;      }
    | INT                                   { global_stat_ctx.type = ET_INT;       }
    | STRING                                { global_stat_ctx.type = ET_STRING;    }
    | FLOAT                                 { global_stat_ctx.type = ET_FLOAT;     }
    | DOUBLE                                { global_stat_ctx.type = ET_DOUBLE;    }

var_decl
    : type ident_decl_list SEMICOLON {
        TRACE("var_decl", "end");
    }

ident_decl_list
    : ident_decl COMMA ident_decl_list
    | ident_decl

ident_decl
    : IDENT decl_init_or_none {

            if (global_stat_ctx.type == ET_VOID ) {
                ERR("variable type cant be void: %s", $1);
            }

            Symbol sym = {};
            sym.base_type = global_stat_ctx.type;
            sym.is_const = global_stat_ctx.is_const;
            strcpy(sym.name, $1);
            if (insert(&sym) == SYMTAB_ERR_DUP) {
                ERR("identifier conflict: %s", $1);
            }

            TRACE("var_decl", "ident: %s", $1);
        }

decl_init_or_none                          
    : ASSIGN constexpr                      { TRACE("var_decl", "have initilizer");         }
    | /* epsilon */                         { TRACE("var_decl", "not have initializer");    }    

ary_decl
    : type IDENT {

            if (global_stat_ctx.type == ET_VOID) {
                ERR("array base type cant be void.");
            }

            memset(&global_stat_ctx.sym,0 ,sizeof(Symbol));
            global_stat_ctx.sym.base_type = global_stat_ctx.type;
            global_stat_ctx.sym.is_array = true;
            strcpy(global_stat_ctx.sym.name, $2);
            global_stat_ctx.sym.ary_dim_num = 0;

        } bracket_list SEMICOLON {
            if (insert(&global_stat_ctx.sym) == SYMTAB_ERR_DUP) {
                ERR("identifier conflict: %s", $2);
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
        } jmp_expr_or_none SEMICOLON {
            /* check: same as function return type */
            global_stat_ctx.indent--;
            /* record: has expr or not */
            TRACE("jstmt", "end");
        }

jmp_expr_or_none
    : expression            { $$ = $1;              }
    | /* epsilon */         { $$.type = ET_VOID;    }

bool_expr
    : expression

num
    : IDENT
    | INT_LITERAL

constexpr
    : expression

/* One Confliction Below */
expression
    : expression ADD    expression                          { TRACE0("ADD");         $$ = $1; $$.type = check_binary_type($1.type, $3.type, "+");      }
    | expression SUB    expression                          { TRACE0("SUB");         $$ = $1; $$.type = check_binary_type($1.type, $3.type, "-");      }
    | expression MUL    expression                          { TRACE0("MUL");         $$ = $1; $$.type = check_binary_type($1.type, $3.type, "*");      }
    | expression DIV    expression                          { TRACE0("DIV");         $$ = $1; $$.type = check_binary_type($1.type, $3.type, "/");      }
    | expression MOD    expression                          { TRACE0("MOD");         $$ = $1; $$.type = check_binary_type($1.type, $3.type, "%");      }
    /* Comparisons → Always return ET_BOOL */
    | expression GT     expression                          { TRACE0("GT ");         $$ = $1; check_binary_type($1.type, $3.type, ">");  $$.type = ET_BOOL; }
    | expression GE     expression                          { TRACE0("GE ");         $$ = $1; check_binary_type($1.type, $3.type, ">="); $$.type = ET_BOOL; }
    | expression LT     expression                          { TRACE0("LT ");         $$ = $1; check_binary_type($1.type, $3.type, "<");  $$.type = ET_BOOL; }
    | expression LE     expression                          { TRACE0("LE ");         $$ = $1; check_binary_type($1.type, $3.type, "<="); $$.type = ET_BOOL; }
    | expression EQ     expression                          { TRACE0("EQ ");         $$ = $1; check_binary_type($1.type, $3.type, "=="); $$.type = ET_BOOL; }
    | expression NE     expression                          { TRACE0("NE");          $$ = $1; check_binary_type($1.type, $3.type, "!="); $$.type = ET_BOOL; }

    | expression AND    expression                          { TRACE0("AND");         $$ = $1; check_binary_type($1.type, $3.type, "&&");     $$.type = ET_BOOL;   }
    | expression OR     expression                          { TRACE0("OR");          $$ = $1; check_binary_type($1.type, $3.type, "||");     $$.type = ET_BOOL;   }

    | expression ASSIGN expression                          { TRACE0("ASSIGN");      $$ = $1; $$.type = check_binary_type($1.type, $3.type, "=");
                                                              if (!$1.is_object)    { ERR("lhs of assign operator should be and object"); }
                                                              if ($1.is_const)      { ERR("assign to const object"); }
                                                            }

    | expression DADD                                       { TRACE0("DADD");        $$ = $1; $$.type = $1.type;          }
    | expression DSUB                                       { TRACE0("DSUB");        $$ = $1; $$.type = $1.type;          }    
    | NOT expression                                        { TRACE0("NOT");         $$ = $2; $$.type = ET_BOOL;          }
    | SUB expression %prec USUB                             { TRACE0("SUB(Unary)");  $$ = $2; $$.type = $2.type;          }
    | L_PARENTHESES expression R_PARENTHESES                { TRACE0("PARENTHESE");  $$ = $2; $$.type = $2.type;          }
    | ident                                                 { $$ = $1;  }
    | literal                                               { $$ = $1;  }
    | ary_invoke                                            { $$ = $1;  }
    | func_invoke                                           { $$ = $1;  }

ident
    : IDENT {
        Symbol *sym = search($1);
        if (!sym) {
            ERR("identifier not exists.");
        }

        $$.type         = sym->base_type;
        $$.is_object    = true;
        $$.is_array     = sym->is_array;
        $$.is_func      = sym->is_func;
        $$.is_const     = sym->is_const;
        TRACE("IDNET", "ident:%s", $1);
    }

literal
    : INT_LITERAL               { TRACE("literal", "int literal: %d", $1);      memset(&$$, 0, sizeof(struct ParseInfo)); $$.type = ET_INT;        }
    | FLOAT_LITERAL             { TRACE("literal", "float literal: %f", $1);    memset(&$$, 0, sizeof(struct ParseInfo)); $$.type = ET_FLOAT;      }
    | STRING_LITERAL            { TRACE("literal", "string literal: %s", $1);   memset(&$$, 0, sizeof(struct ParseInfo)); $$.type = ET_STRING;     }
    | TRUE                      { TRACE("literal", "bool literal: true");       memset(&$$, 0, sizeof(struct ParseInfo)); $$.type = ET_BOOL;       }
    | FALSE                     { TRACE("literal", "bool literal: false");      memset(&$$, 0, sizeof(struct ParseInfo)); $$.type = ET_BOOL;       }

ary_invoke
    : IDENT dim_expr_list {
        if (!search($1)) {
            ERR("identifier not exists.");
        }
        TRACE("ary_invoke", "ident: %s", $1);
    }

dim_expr_list
    : L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS dim_expr_list
    | L_SQUARE_BRACKETS expression R_SQUARE_BRACKETS

func_invoke
    : IDENT L_PARENTHESES arg_expr_list R_PARENTHESES {
            Symbol *sym = search($1);
            if (!sym) {
                ERR("identifier not exists.");
            }

            $$.type         = sym->base_type;
            $$.is_object    = true;
            $$.is_array     = sym->is_array;
            $$.is_func      = sym->is_func;
            $$.is_const     = sym->is_const;
            TRACE("func_invoke", "ident: %s", $1);
        }

arg_expr_list
    : expression
    | arg_expr_list COMMA expression
%%

int yacctype_to_ettype(int yacctype) {
    if (yacctype == INT)        return ET_INT;
    if (yacctype == BOOL)       return ET_BOOL;
    if (yacctype == FLOAT)      return ET_FLOAT;
    if (yacctype == DOUBLE)     return ET_DOUBLE;
    if (yacctype == VOID)       return ET_VOID;
    if (yacctype == STRING)     return ET_STRING;
    return -1;
}

void yyerror(char *msg) {
    printf("ERROR: %s\n", msg);
}

void check_main_function() {
    Symbol *sym = search("main");
    if (sym) {
        if (sym->base_type != ET_VOID) {
            ERR("main func's return type should be void.\n");
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

    print_symtab_ctx();
    check_main_function();

    return 0;
}
