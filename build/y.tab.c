/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

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

#line 96 "build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DOT = 3,                        /* DOT  */
  YYSYMBOL_RANGE = 4,                      /* RANGE  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_COLON = 6,                      /* COLON  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_L_PARENTHESES = 8,              /* L_PARENTHESES  */
  YYSYMBOL_R_PARENTHESES = 9,              /* R_PARENTHESES  */
  YYSYMBOL_L_SQUARE_BRACKETS = 10,         /* L_SQUARE_BRACKETS  */
  YYSYMBOL_R_SQUARE_BRACKETS = 11,         /* R_SQUARE_BRACKETS  */
  YYSYMBOL_L_BRACKETS = 12,                /* L_BRACKETS  */
  YYSYMBOL_R_BRACKETS = 13,                /* R_BRACKETS  */
  YYSYMBOL_DOUBLE_ADD = 14,                /* DOUBLE_ADD  */
  YYSYMBOL_DOUBLE_SUB = 15,                /* DOUBLE_SUB  */
  YYSYMBOL_MUL = 16,                       /* MUL  */
  YYSYMBOL_DIV = 17,                       /* DIV  */
  YYSYMBOL_MOD = 18,                       /* MOD  */
  YYSYMBOL_ADD = 19,                       /* ADD  */
  YYSYMBOL_SUB = 20,                       /* SUB  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NE = 26,                        /* NE  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_TERNARY = 29,                   /* TERNARY  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_BOOL = 31,                      /* BOOL  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_CASE = 33,                      /* CASE  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_CONST = 35,                     /* CONST  */
  YYSYMBOL_CONTINUE = 36,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 37,                   /* DEFAULT  */
  YYSYMBOL_DO = 38,                        /* DO  */
  YYSYMBOL_DOUBLE = 39,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_EXTERN = 41,                    /* EXTERN  */
  YYSYMBOL_FALSE = 42,                     /* FALSE  */
  YYSYMBOL_FLOAT = 43,                     /* FLOAT  */
  YYSYMBOL_FOR = 44,                       /* FOR  */
  YYSYMBOL_FOREACH = 45,                   /* FOREACH  */
  YYSYMBOL_IF = 46,                        /* IF  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_PRINT = 48,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 49,                   /* PRINTLN  */
  YYSYMBOL_READ = 50,                      /* READ  */
  YYSYMBOL_RETURN = 51,                    /* RETURN  */
  YYSYMBOL_SWITCH = 52,                    /* SWITCH  */
  YYSYMBOL_TRUE = 53,                      /* TRUE  */
  YYSYMBOL_VOID = 54,                      /* VOID  */
  YYSYMBOL_WHILE = 55,                     /* WHILE  */
  YYSYMBOL_STRING = 56,                    /* STRING  */
  YYSYMBOL_INT_LITERAL = 57,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 58,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 59,            /* STRING_LITERAL  */
  YYSYMBOL_IDENT = 60,                     /* IDENT  */
  YYSYMBOL_NOT = 61,                       /* NOT  */
  YYSYMBOL_USUB = 62,                      /* USUB  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_translation_unit = 64,          /* translation_unit  */
  YYSYMBOL_external_decl = 65,             /* external_decl  */
  YYSYMBOL_func_def = 66,                  /* func_def  */
  YYSYMBOL_67_1 = 67,                      /* $@1  */
  YYSYMBOL_68_2 = 68,                      /* $@2  */
  YYSYMBOL_param_list = 69,                /* param_list  */
  YYSYMBOL_stmts = 70,                     /* stmts  */
  YYSYMBOL_stmt = 71,                      /* stmt  */
  YYSYMBOL_obj_def = 72,                   /* obj_def  */
  YYSYMBOL_constant_decl = 73,             /* constant_decl  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_variable_decl = 75,             /* variable_decl  */
  YYSYMBOL_ident_decl_list = 76,           /* ident_decl_list  */
  YYSYMBOL_ident_decl = 77,                /* ident_decl  */
  YYSYMBOL_array_decl = 78,                /* array_decl  */
  YYSYMBOL_bracket_list = 79,              /* bracket_list  */
  YYSYMBOL_cstmt = 80,                     /* cstmt  */
  YYSYMBOL_estmt = 81,                     /* estmt  */
  YYSYMBOL_sstmt = 82,                     /* sstmt  */
  YYSYMBOL_estmt_or_cstmt = 83,            /* estmt_or_cstmt  */
  YYSYMBOL_istmt = 84,                     /* istmt  */
  YYSYMBOL_jstmt = 85,                     /* jstmt  */
  YYSYMBOL_bool_expr = 86,                 /* bool_expr  */
  YYSYMBOL_num = 87,                       /* num  */
  YYSYMBOL_const_expr = 88,                /* const_expr  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_literal = 90,                   /* literal  */
  YYSYMBOL_array_invoke = 91,              /* array_invoke  */
  YYSYMBOL_dim_expr_list = 92,             /* dim_expr_list  */
  YYSYMBOL_func_invoke = 93,               /* func_invoke  */
  YYSYMBOL_arg_expr_list = 94              /* arg_expr_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    95,    99,   100,   104,   104,   108,   108,
     115,   116,   120,   121,   125,   126,   127,   128,   129,   130,
     134,   135,   136,   140,   144,   145,   146,   147,   148,   149,
     153,   157,   158,   162,   163,   167,   170,   171,   175,   180,
     181,   182,   183,   184,   188,   189,   193,   194,   198,   199,
     200,   204,   205,   209,   213,   214,   218,   219,   220,   221,
     222,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   253,   254,   255,   256,   257,   261,
     265,   266,   270,   274,   275
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DOT", "RANGE",
  "COMMA", "COLON", "SEMICOLON", "L_PARENTHESES", "R_PARENTHESES",
  "L_SQUARE_BRACKETS", "R_SQUARE_BRACKETS", "L_BRACKETS", "R_BRACKETS",
  "DOUBLE_ADD", "DOUBLE_SUB", "MUL", "DIV", "MOD", "ADD", "SUB", "LT",
  "LE", "GT", "GE", "EQ", "NE", "AND", "OR", "TERNARY", "ASSIGN", "BOOL",
  "BREAK", "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE",
  "ELSE", "EXTERN", "FALSE", "FLOAT", "FOR", "FOREACH", "IF", "INT",
  "PRINT", "PRINTLN", "READ", "RETURN", "SWITCH", "TRUE", "VOID", "WHILE",
  "STRING", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "IDENT",
  "NOT", "USUB", "$accept", "translation_unit", "external_decl",
  "func_def", "$@1", "$@2", "param_list", "stmts", "stmt", "obj_def",
  "constant_decl", "type", "variable_decl", "ident_decl_list",
  "ident_decl", "array_decl", "bracket_list", "cstmt", "estmt", "sstmt",
  "estmt_or_cstmt", "istmt", "jstmt", "bool_expr", "num", "const_expr",
  "expression", "literal", "array_invoke", "dim_expr_list", "func_invoke",
  "arg_expr_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -74,    36,   -74,   -74,   -28,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -54,   -74,   -74,   -42,     4,    20,
      35,    16,   156,   -10,    27,    41,   -74,    -9,    27,    38,
      57,     8,    59,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
      42,   -74,    66,   -74,   -74,   -74,    82,    64,   -74,    69,
      38,    38,   -28,   -74,   -74,   101,   -74,   101,   -74,    80,
      83,    87,   101,   101,    43,   133,   -74,    88,   -74,   -74,
     -74,    31,   101,   -74,   -74,    45,   -74,   -74,   -74,   -74,
     -74,   199,   -74,   -74,   -74,   -74,   -74,   -74,   329,    18,
     101,    46,   101,   221,   243,    94,   -74,   265,   101,   101,
     101,   -74,   418,    -5,   -74,   -74,   -74,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   -74,   287,    96,    98,   384,   -74,   -74,   -74,   -74,
     125,   384,    33,   367,    18,    18,    18,     6,     6,   131,
     131,   131,   131,   435,   435,   418,   401,   418,   101,   -44,
     124,   124,   101,   -74,   123,   309,   -74,   -74,   134,   -74,
     -74,    95,   -74,   384,   -74,   101,   -44,   124,   349,   128,
     -74,   124,   124,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    25,     0,    29,    28,    26,    24,    27,
       2,     4,     5,    20,     0,    21,    22,     0,    34,     0,
      32,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,    60,    59,    56,    57,    58,    33,    35,
      34,    31,     0,    13,     8,     6,    11,    37,    23,     0,
       0,     0,     0,    36,    43,     0,    38,     0,    88,     0,
       0,     0,     0,     0,     0,     0,    87,     0,    84,    85,
      86,    80,     0,    12,    14,     0,    15,    16,    17,    18,
      19,     0,    81,    82,    83,     9,     7,    10,     0,    78,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,    89,    77,    34,    42,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,    53,    39,    40,    41,    51,
       0,    93,     0,     0,    63,    64,    65,    61,    62,    68,
      69,    66,    67,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,    92,    91,     0,    55,    54,     0,    47,
      46,    44,    48,    94,    90,     0,     0,     0,     0,     0,
      45,     0,     0,    49,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,   -74,    90,   -74,   -74,   103,
     -74,     0,   -74,   112,   -74,   -74,   108,   -20,   114,   -74,
     -73,   -74,   -74,    70,    -2,   139,   -55,   -74,   -74,    15,
     -74,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    10,    11,    51,    50,    30,    49,    73,    12,
      13,    31,    15,    19,    20,    16,    25,   159,   160,    78,
     161,    79,    80,   124,   158,    38,    81,    82,    83,   101,
      84,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,    14,    89,     3,    17,    23,    18,    93,    94,    44,
      97,     5,    22,   156,    23,     6,   157,   102,    21,     7,
     105,   106,   107,   108,   109,    24,     8,    26,     9,    76,
      85,    86,   105,   106,    24,   122,     2,   125,   152,    99,
      27,   100,   153,   125,   131,   133,    28,    32,    39,    75,
      43,    40,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    45,     3,    46,    33,
      47,     4,    24,    48,    23,     5,    54,    55,   162,     6,
      34,    43,    56,     7,    35,    36,    37,    52,    90,    57,
       8,    91,     9,   155,   170,    92,    98,   163,   173,   174,
       3,   128,   149,    95,     4,   103,   123,   150,     5,    55,
     168,    58,     6,    59,    60,    61,     7,    62,    63,    64,
      65,    57,    66,     8,    67,     9,    68,    69,    70,    71,
      72,    54,    55,   100,   151,   167,    43,   172,   166,    41,
      96,    55,    87,    58,    57,   105,   106,   107,   108,   109,
     110,   111,    74,    57,    66,    53,   116,   117,    68,    69,
      70,    71,    72,    77,   169,    29,    58,    42,   130,   164,
       0,     0,    62,    63,    64,    58,     0,    66,     0,     0,
       0,    68,    69,    70,    71,    72,    66,     3,     0,     0,
      68,    69,    70,    71,    72,     5,     0,     0,     0,     6,
       0,     0,     0,     7,     0,     0,   104,     0,     0,     0,
       8,     0,     9,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   126,   120,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     127,   120,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   129,   120,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   148,   120,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   165,   120,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   121,   120,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   171,   120,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   154,   120,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,   120,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,   120,   105,
     106,   107,   108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
      55,     1,    57,    31,     4,    10,    60,    62,    63,    29,
      65,    39,     8,    57,    10,    43,    60,    72,    60,    47,
      14,    15,    16,    17,    18,    30,    54,     7,    56,    49,
      50,    51,    14,    15,    30,    90,     0,    92,     5,     8,
       5,    10,     9,    98,    99,   100,    30,    57,     7,    49,
      12,    60,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     9,    31,    60,    42,
      11,    35,    30,     7,    10,    39,     7,     8,   151,    43,
      53,    12,    13,    47,    57,    58,    59,     5,     8,    20,
      54,     8,    56,   148,   167,     8,     8,   152,   171,   172,
      31,     7,     6,    60,    35,    60,    60,     9,    39,     8,
     165,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    20,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     7,     8,    10,     9,    40,    12,     9,     4,    27,
       7,     8,    52,    42,    20,    14,    15,    16,    17,    18,
      19,    20,    49,    20,    53,    47,    25,    26,    57,    58,
      59,    60,    61,    49,   166,     9,    42,    28,    98,   154,
      -1,    -1,    48,    49,    50,    42,    -1,    53,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    53,    31,    -1,    -1,
      57,    58,    59,    60,    61,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,    -1,    -1,     7,    -1,    -1,    -1,
      54,    -1,    56,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     7,    30,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       7,    30,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     7,    30,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     7,    30,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     7,    30,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     9,    30,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     9,    30,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    11,    30,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    14,
      15,    16,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,     0,    31,    35,    39,    43,    47,    54,    56,
      65,    66,    72,    73,    74,    75,    78,    74,    60,    76,
      77,    60,     8,    10,    30,    79,     7,     5,    30,     9,
      69,    74,    57,    42,    53,    57,    58,    59,    88,     7,
      60,    76,    88,    12,    80,     9,    60,    11,     7,    70,
      68,    67,     5,    79,     7,     8,    13,    20,    42,    44,
      45,    46,    48,    49,    50,    51,    53,    55,    57,    58,
      59,    60,    61,    71,    72,    74,    80,    81,    82,    84,
      85,    89,    90,    91,    93,    80,    80,    69,    89,    89,
       8,     8,     8,    89,    89,    60,     7,    89,     8,     8,
      10,    92,    89,    60,     7,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      30,     9,    89,    60,    86,    89,     7,     7,     7,     7,
      86,    89,    94,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,     7,     6,
       9,     9,     5,     9,    11,    89,    57,    60,    87,    80,
      81,    83,    83,    89,    92,     7,     4,    40,    89,    87,
      83,     9,     9,    83,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    67,    66,    68,    66,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    73,    74,    74,    74,    74,    74,    74,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    81,
      81,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    90,    91,
      92,    92,    93,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     0,     7,     0,     7,
       4,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     1,     4,     4,     3,     3,     3,
       3,     3,     2,     1,     5,     7,     1,     1,     5,     9,
       9,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* translation_unit: translation_unit external_decl  */
#line 94 "src/parser.y"
                                                                    { }
#line 1357 "build/y.tab.c"
    break;

  case 3: /* translation_unit: %empty  */
#line 95 "src/parser.y"
                                                                    { TRACE("Reducing to translation_unit");    stat_ctx.indent++;}
#line 1363 "build/y.tab.c"
    break;

  case 4: /* external_decl: func_def  */
#line 99 "src/parser.y"
                                                                    { }
#line 1369 "build/y.tab.c"
    break;

  case 5: /* external_decl: obj_def  */
#line 100 "src/parser.y"
                                                                    { TRACE("Reducing to obj_def");    }
#line 1375 "build/y.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 104 "src/parser.y"
                                                                    {
            TRACE("Reducing to func, nums of param:%d", stat_ctx.num_param);
            stat_ctx.num_param = 0; stat_ctx.indent++;
        }
#line 1384 "build/y.tab.c"
    break;

  case 7: /* func_def: type IDENT L_PARENTHESES param_list R_PARENTHESES $@1 cstmt  */
#line 107 "src/parser.y"
                { stat_ctx.indent--; }
#line 1390 "build/y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 108 "src/parser.y"
                                                                    {
            TRACE("Reducing to func, nums of param:0");
            stat_ctx.indent++;               
        }
#line 1399 "build/y.tab.c"
    break;

  case 9: /* func_def: type IDENT L_PARENTHESES R_PARENTHESES cstmt $@2 cstmt  */
#line 111 "src/parser.y"
                { stat_ctx.indent--; }
#line 1405 "build/y.tab.c"
    break;

  case 10: /* param_list: type IDENT COMMA param_list  */
#line 115 "src/parser.y"
                                                                    { stat_ctx.num_param++; }
#line 1411 "build/y.tab.c"
    break;

  case 11: /* param_list: type IDENT  */
#line 116 "src/parser.y"
                                                                    { stat_ctx.num_param++;   }
#line 1417 "build/y.tab.c"
    break;

  case 12: /* stmts: stmts stmt  */
#line 120 "src/parser.y"
                                            {   }
#line 1423 "build/y.tab.c"
    break;

  case 14: /* stmt: obj_def  */
#line 125 "src/parser.y"
                                            { TRACE("Reducing to obj_def");       }
#line 1429 "build/y.tab.c"
    break;

  case 15: /* stmt: cstmt  */
#line 126 "src/parser.y"
                                            { TRACE("Reducing to cstmt ");         }
#line 1435 "build/y.tab.c"
    break;

  case 16: /* stmt: estmt  */
#line 127 "src/parser.y"
                                            { TRACE("Reducing to estmt ");         }
#line 1441 "build/y.tab.c"
    break;

  case 17: /* stmt: sstmt  */
#line 128 "src/parser.y"
                                            { TRACE("Reducing to sstmt ");         }
#line 1447 "build/y.tab.c"
    break;

  case 18: /* stmt: istmt  */
#line 129 "src/parser.y"
                                            { TRACE("Reducing to istmt");         }
#line 1453 "build/y.tab.c"
    break;

  case 19: /* stmt: jstmt  */
#line 130 "src/parser.y"
                                            { TRACE("Reducing to jstmt");         }
#line 1459 "build/y.tab.c"
    break;

  case 39: /* estmt: PRINT expression SEMICOLON  */
#line 180 "src/parser.y"
                                                { }
#line 1465 "build/y.tab.c"
    break;

  case 40: /* estmt: PRINTLN expression SEMICOLON  */
#line 181 "src/parser.y"
                                                { }
#line 1471 "build/y.tab.c"
    break;

  case 41: /* estmt: READ IDENT SEMICOLON  */
#line 182 "src/parser.y"
                                                { }
#line 1477 "build/y.tab.c"
    break;

  case 42: /* estmt: expression SEMICOLON  */
#line 183 "src/parser.y"
                                                { }
#line 1483 "build/y.tab.c"
    break;

  case 43: /* estmt: SEMICOLON  */
#line 184 "src/parser.y"
                                                { }
#line 1489 "build/y.tab.c"
    break;

  case 44: /* sstmt: IF L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt  */
#line 188 "src/parser.y"
                                                                                                    { }
#line 1495 "build/y.tab.c"
    break;

  case 45: /* sstmt: IF L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt ELSE estmt_or_cstmt  */
#line 189 "src/parser.y"
                                                                                                    { }
#line 1501 "build/y.tab.c"
    break;

  case 48: /* istmt: WHILE L_PARENTHESES bool_expr R_PARENTHESES estmt_or_cstmt  */
#line 198 "src/parser.y"
                                                                                                                 { }
#line 1507 "build/y.tab.c"
    break;

  case 49: /* istmt: FOR L_PARENTHESES expression SEMICOLON expression SEMICOLON expression R_PARENTHESES estmt_or_cstmt  */
#line 199 "src/parser.y"
                                                                                                                 { }
#line 1513 "build/y.tab.c"
    break;

  case 50: /* istmt: FOREACH L_PARENTHESES IDENT COLON num RANGE num R_PARENTHESES estmt_or_cstmt  */
#line 200 "src/parser.y"
                                                                                                                 { }
#line 1519 "build/y.tab.c"
    break;

  case 61: /* expression: expression ADD expression  */
#line 227 "src/parser.y"
                                                                    { TRACE("Reducing to ADD"); }
#line 1525 "build/y.tab.c"
    break;

  case 62: /* expression: expression SUB expression  */
#line 228 "src/parser.y"
                                                                    { TRACE("Reducing to SUB"); }
#line 1531 "build/y.tab.c"
    break;

  case 63: /* expression: expression MUL expression  */
#line 229 "src/parser.y"
                                                                    { TRACE("Reducing to MUL"); }
#line 1537 "build/y.tab.c"
    break;

  case 64: /* expression: expression DIV expression  */
#line 230 "src/parser.y"
                                                                    { TRACE("Reducing to DIV"); }
#line 1543 "build/y.tab.c"
    break;

  case 65: /* expression: expression MOD expression  */
#line 231 "src/parser.y"
                                                                    { TRACE("Reducing to MOD"); }
#line 1549 "build/y.tab.c"
    break;

  case 66: /* expression: expression GT expression  */
#line 232 "src/parser.y"
                                                                    { TRACE("Reducing to GT"); }
#line 1555 "build/y.tab.c"
    break;

  case 67: /* expression: expression GE expression  */
#line 233 "src/parser.y"
                                                                    { TRACE("Reducing to GE"); }
#line 1561 "build/y.tab.c"
    break;

  case 68: /* expression: expression LT expression  */
#line 234 "src/parser.y"
                                                                    { TRACE("Reducing to LT"); }
#line 1567 "build/y.tab.c"
    break;

  case 69: /* expression: expression LE expression  */
#line 235 "src/parser.y"
                                                                    { TRACE("Reducing to LE"); }
#line 1573 "build/y.tab.c"
    break;

  case 70: /* expression: expression EQ expression  */
#line 236 "src/parser.y"
                                                                    { TRACE("Reducing to EQ"); }
#line 1579 "build/y.tab.c"
    break;

  case 71: /* expression: expression NE expression  */
#line 237 "src/parser.y"
                                                                    { TRACE("Reducing to NE"); }
#line 1585 "build/y.tab.c"
    break;

  case 72: /* expression: expression AND expression  */
#line 238 "src/parser.y"
                                                                    { TRACE("Reducing to AND"); }
#line 1591 "build/y.tab.c"
    break;

  case 73: /* expression: expression OR expression  */
#line 239 "src/parser.y"
                                                                    { TRACE("Reducing to OR"); }
#line 1597 "build/y.tab.c"
    break;

  case 74: /* expression: expression ASSIGN expression  */
#line 240 "src/parser.y"
                                                                    { TRACE("Reducing to ASSIGN"); }
#line 1603 "build/y.tab.c"
    break;

  case 75: /* expression: expression DOUBLE_ADD  */
#line 241 "src/parser.y"
                                                                    { TRACE("Reducing to DOUBLE_ADD"); }
#line 1609 "build/y.tab.c"
    break;

  case 76: /* expression: expression DOUBLE_SUB  */
#line 242 "src/parser.y"
                                                                    { TRACE("Reducing to DOUBLE_SUB"); }
#line 1615 "build/y.tab.c"
    break;

  case 77: /* expression: NOT expression  */
#line 243 "src/parser.y"
                                                                    { TRACE("Reducing to NOT"); }
#line 1621 "build/y.tab.c"
    break;

  case 78: /* expression: SUB expression  */
#line 244 "src/parser.y"
                                                                    { TRACE("Reducing to SUB(Unary)"); }
#line 1627 "build/y.tab.c"
    break;

  case 79: /* expression: L_PARENTHESES expression R_PARENTHESES  */
#line 245 "src/parser.y"
                                                                    { TRACE("Reducing to PARENTHESE"); }
#line 1633 "build/y.tab.c"
    break;

  case 80: /* expression: IDENT  */
#line 246 "src/parser.y"
                                                                    { TRACE("Reducing to IDNET"); }
#line 1639 "build/y.tab.c"
    break;

  case 81: /* expression: literal  */
#line 247 "src/parser.y"
                                                                    { TRACE("Reducing to LITERAL"); }
#line 1645 "build/y.tab.c"
    break;

  case 82: /* expression: array_invoke  */
#line 248 "src/parser.y"
                                                                    { TRACE("Reducing to ARRAY"); }
#line 1651 "build/y.tab.c"
    break;

  case 83: /* expression: func_invoke  */
#line 249 "src/parser.y"
                                                                    { TRACE("Reducing to FUNC_INVOKE"); }
#line 1657 "build/y.tab.c"
    break;

  case 92: /* func_invoke: IDENT L_PARENTHESES arg_expr_list R_PARENTHESES  */
#line 270 "src/parser.y"
                                                                        {}
#line 1663 "build/y.tab.c"
    break;


#line 1667 "build/y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 277 "src/parser.y"


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
