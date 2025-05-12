/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_Y_TAB_H_INCLUDED
# define YY_YY_BUILD_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DOT = 258,                     /* DOT  */
    RANGE = 259,                   /* RANGE  */
    COMMA = 260,                   /* COMMA  */
    COLON = 261,                   /* COLON  */
    SEMICOLON = 262,               /* SEMICOLON  */
    L_PARENTHESES = 263,           /* L_PARENTHESES  */
    R_PARENTHESES = 264,           /* R_PARENTHESES  */
    L_SQUARE_BRACKETS = 265,       /* L_SQUARE_BRACKETS  */
    R_SQUARE_BRACKETS = 266,       /* R_SQUARE_BRACKETS  */
    L_BRACKETS = 267,              /* L_BRACKETS  */
    R_BRACKETS = 268,              /* R_BRACKETS  */
    DOUBLE_ADD = 269,              /* DOUBLE_ADD  */
    DOUBLE_SUB = 270,              /* DOUBLE_SUB  */
    MUL = 271,                     /* MUL  */
    DIV = 272,                     /* DIV  */
    MOD = 273,                     /* MOD  */
    ADD = 274,                     /* ADD  */
    SUB = 275,                     /* SUB  */
    LT = 276,                      /* LT  */
    LE = 277,                      /* LE  */
    GT = 278,                      /* GT  */
    GE = 279,                      /* GE  */
    EQ = 280,                      /* EQ  */
    NE = 281,                      /* NE  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    TERNARY = 284,                 /* TERNARY  */
    ASSIGN = 285,                  /* ASSIGN  */
    BOOL = 286,                    /* BOOL  */
    BREAK = 287,                   /* BREAK  */
    CASE = 288,                    /* CASE  */
    CHAR = 289,                    /* CHAR  */
    CONST = 290,                   /* CONST  */
    CONTINUE = 291,                /* CONTINUE  */
    DEFAULT = 292,                 /* DEFAULT  */
    DO = 293,                      /* DO  */
    DOUBLE = 294,                  /* DOUBLE  */
    ELSE = 295,                    /* ELSE  */
    EXTERN = 296,                  /* EXTERN  */
    FALSE = 297,                   /* FALSE  */
    FLOAT = 298,                   /* FLOAT  */
    FOR = 299,                     /* FOR  */
    FOREACH = 300,                 /* FOREACH  */
    IF = 301,                      /* IF  */
    INT = 302,                     /* INT  */
    PRINT = 303,                   /* PRINT  */
    PRINTLN = 304,                 /* PRINTLN  */
    READ = 305,                    /* READ  */
    RETURN = 306,                  /* RETURN  */
    SWITCH = 307,                  /* SWITCH  */
    TRUE = 308,                    /* TRUE  */
    VOID = 309,                    /* VOID  */
    WHILE = 310,                   /* WHILE  */
    STRING = 311,                  /* STRING  */
    INT_LITERAL = 312,             /* INT_LITERAL  */
    FLOAT_LITERAL = 313,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 314,          /* STRING_LITERAL  */
    IDENT = 315,                   /* IDENT  */
    NOT = 316,                     /* NOT  */
    USUB = 317                     /* USUB  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DOT 258
#define RANGE 259
#define COMMA 260
#define COLON 261
#define SEMICOLON 262
#define L_PARENTHESES 263
#define R_PARENTHESES 264
#define L_SQUARE_BRACKETS 265
#define R_SQUARE_BRACKETS 266
#define L_BRACKETS 267
#define R_BRACKETS 268
#define DOUBLE_ADD 269
#define DOUBLE_SUB 270
#define MUL 271
#define DIV 272
#define MOD 273
#define ADD 274
#define SUB 275
#define LT 276
#define LE 277
#define GT 278
#define GE 279
#define EQ 280
#define NE 281
#define AND 282
#define OR 283
#define TERNARY 284
#define ASSIGN 285
#define BOOL 286
#define BREAK 287
#define CASE 288
#define CHAR 289
#define CONST 290
#define CONTINUE 291
#define DEFAULT 292
#define DO 293
#define DOUBLE 294
#define ELSE 295
#define EXTERN 296
#define FALSE 297
#define FLOAT 298
#define FOR 299
#define FOREACH 300
#define IF 301
#define INT 302
#define PRINT 303
#define PRINTLN 304
#define READ 305
#define RETURN 306
#define SWITCH 307
#define TRUE 308
#define VOID 309
#define WHILE 310
#define STRING 311
#define INT_LITERAL 312
#define FLOAT_LITERAL 313
#define STRING_LITERAL 314
#define IDENT 315
#define NOT 316
#define USUB 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "src/parser.y"

    int     ival;       // for integer literals
    float   fval;       // for floating point literals
    char   *sval;       // for string literals
    char   *idname;     // for identifier name

#line 198 "build/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_Y_TAB_H_INCLUDED  */
