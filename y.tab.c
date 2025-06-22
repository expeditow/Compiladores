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
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

#define YYSTYPE atributos

using namespace std;

int qntdVariaveisTemp = 0;
int contador_rotulos = 0;

stack<string> pilhaRotulosFimLoop;      // Para 'break': salta para o fim do laço
stack<string> pilhaRotulosProxIteracao; // Para 'continue': salta para o teste/incremento do laço

struct atributos 
{
    string label;       // A variável temporária atribuída
    string traducao;    // A tradução em código intermediário
    string tipo;        // O tipo, p casos de operações que precisamos criar uma nova label
};

typedef struct
{
    string nomeVariavel; // nome no código fonte
    string tipoVariavel;  // int, float, double
    string label; // tipo registrador

} TIPO_SIMBOLO;

int yylex(void);
void yyerror(string);

set<pair<string,string>> temporarias;
vector<map<string, TIPO_SIMBOLO>> pilhaTabelasSimbolos;
stack<pair<string, string>> pilhaExprSwitch;

bool verificaTabelaSimbolos(string nome);
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
void entraEscopo();
void saiEscopo();

void insereFixasTabelaSimbolos(string nome, string tipo);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

string novo_rotulo();

string geraNomeTemporarias(string tipo);
string pegaTipo(string tipo);
string infereTipo(string tipo1, string tipo2);
string pegaBooleano(string valor);
int tamanho_string(string texto);

bool debug = false;
#define true 1
#define false 0

extern int yylinha;


#line 134 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TK_TIPO = 258,                 /* TK_TIPO  */
    TK_ID = 259,                   /* TK_ID  */
    TK_INT = 260,                  /* TK_INT  */
    TK_FLOAT = 261,                /* TK_FLOAT  */
    TK_BOOLEAN = 262,              /* TK_BOOLEAN  */
    TK_CHAR = 263,                 /* TK_CHAR  */
    TK_STRING = 264,               /* TK_STRING  */
    TK_MAIOR_IGUAL = 265,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 266,          /* TK_MENOR_IGUAL  */
    TK_DIFERENTE = 267,            /* TK_DIFERENTE  */
    TK_IGUAL = 268,                /* TK_IGUAL  */
    TK_E_LOGICO = 269,             /* TK_E_LOGICO  */
    TK_OU_LOGICO = 270,            /* TK_OU_LOGICO  */
    TK_NEGACAO = 271,              /* TK_NEGACAO  */
    TK_IF = 272,                   /* TK_IF  */
    TK_ELSE = 273,                 /* TK_ELSE  */
    TK_WHILE = 274,                /* TK_WHILE  */
    TK_DO = 275,                   /* TK_DO  */
    TK_FOR = 276,                  /* TK_FOR  */
    TK_IN = 277,                   /* TK_IN  */
    TK_SWITCH = 278,               /* TK_SWITCH  */
    TK_CASE = 279,                 /* TK_CASE  */
    TK_BREAK = 280,                /* TK_BREAK  */
    TK_DEFAULT = 281,              /* TK_DEFAULT  */
    TK_CONTINUE = 282,             /* TK_CONTINUE  */
    TK_PRINT = 283,                /* TK_PRINT  */
    TK_SCAN = 284,                 /* TK_SCAN  */
    FIM_LINHA = 285                /* FIM_LINHA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_TIPO 258
#define TK_ID 259
#define TK_INT 260
#define TK_FLOAT 261
#define TK_BOOLEAN 262
#define TK_CHAR 263
#define TK_STRING 264
#define TK_MAIOR_IGUAL 265
#define TK_MENOR_IGUAL 266
#define TK_DIFERENTE 267
#define TK_IGUAL 268
#define TK_E_LOGICO 269
#define TK_OU_LOGICO 270
#define TK_NEGACAO 271
#define TK_IF 272
#define TK_ELSE 273
#define TK_WHILE 274
#define TK_DO 275
#define TK_FOR 276
#define TK_IN 277
#define TK_SWITCH 278
#define TK_CASE 279
#define TK_BREAK 280
#define TK_DEFAULT 281
#define TK_CONTINUE 282
#define TK_PRINT 283
#define TK_SCAN 284
#define FIM_LINHA 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_TIPO = 3,                    /* TK_TIPO  */
  YYSYMBOL_TK_ID = 4,                      /* TK_ID  */
  YYSYMBOL_TK_INT = 5,                     /* TK_INT  */
  YYSYMBOL_TK_FLOAT = 6,                   /* TK_FLOAT  */
  YYSYMBOL_TK_BOOLEAN = 7,                 /* TK_BOOLEAN  */
  YYSYMBOL_TK_CHAR = 8,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 9,                  /* TK_STRING  */
  YYSYMBOL_TK_MAIOR_IGUAL = 10,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 11,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_DIFERENTE = 12,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_IGUAL = 13,                  /* TK_IGUAL  */
  YYSYMBOL_TK_E_LOGICO = 14,               /* TK_E_LOGICO  */
  YYSYMBOL_TK_OU_LOGICO = 15,              /* TK_OU_LOGICO  */
  YYSYMBOL_TK_NEGACAO = 16,                /* TK_NEGACAO  */
  YYSYMBOL_TK_IF = 17,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 18,                   /* TK_ELSE  */
  YYSYMBOL_TK_WHILE = 19,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 20,                     /* TK_DO  */
  YYSYMBOL_TK_FOR = 21,                    /* TK_FOR  */
  YYSYMBOL_TK_IN = 22,                     /* TK_IN  */
  YYSYMBOL_TK_SWITCH = 23,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 24,                   /* TK_CASE  */
  YYSYMBOL_TK_BREAK = 25,                  /* TK_BREAK  */
  YYSYMBOL_TK_DEFAULT = 26,                /* TK_DEFAULT  */
  YYSYMBOL_TK_CONTINUE = 27,               /* TK_CONTINUE  */
  YYSYMBOL_TK_PRINT = 28,                  /* TK_PRINT  */
  YYSYMBOL_TK_SCAN = 29,                   /* TK_SCAN  */
  YYSYMBOL_FIM_LINHA = 30,                 /* FIM_LINHA  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_START = 44,                     /* START  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_CODIGO = 46,                    /* CODIGO  */
  YYSYMBOL_ITEM = 47,                      /* ITEM  */
  YYSYMBOL_BLOCO_DECL = 48,                /* BLOCO_DECL  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_BLOCO = 51,                     /* BLOCO  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_CMDS = 53,                      /* CMDS  */
  YYSYMBOL_CMD = 54,                       /* CMD  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_FOR_INICIA = 58,                /* FOR_INICIA  */
  YYSYMBOL_FOR_INCREM = 59,                /* FOR_INCREM  */
  YYSYMBOL_DECL = 60,                      /* DECL  */
  YYSYMBOL_ATR = 61,                       /* ATR  */
  YYSYMBOL_EXP = 62,                       /* EXP  */
  YYSYMBOL_TERMO = 63,                     /* TERMO  */
  YYSYMBOL_FATOR = 64                      /* FATOR  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      33,    34,    41,    37,     2,    38,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      40,    36,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    76,    91,    94,    99,   104,   108,   114,
     114,   122,   122,   131,   137,   137,   145,   151,   156,   157,
     158,   159,   160,   161,   162,   163,   189,   210,   208,   236,
     235,   263,   281,   280,   311,   318,   325,   342,   375,   376,
     377,   379,   381,   384,   388,   397,   416,   442,   477,   510,
     526,   542,   557,   573,   588,   603,   614,   625,   633,   664,
     695,   703,   709,   717,   733,   753,   759,   765,   775,   781
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_TIPO", "TK_ID",
  "TK_INT", "TK_FLOAT", "TK_BOOLEAN", "TK_CHAR", "TK_STRING",
  "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_DIFERENTE", "TK_IGUAL",
  "TK_E_LOGICO", "TK_OU_LOGICO", "TK_NEGACAO", "TK_IF", "TK_ELSE",
  "TK_WHILE", "TK_DO", "TK_FOR", "TK_IN", "TK_SWITCH", "TK_CASE",
  "TK_BREAK", "TK_DEFAULT", "TK_CONTINUE", "TK_PRINT", "TK_SCAN",
  "FIM_LINHA", "'{'", "'}'", "'('", "')'", "';'", "'='", "'+'", "'-'",
  "'>'", "'<'", "'*'", "'/'", "$accept", "START", "$@1", "CODIGO", "ITEM",
  "BLOCO_DECL", "$@2", "$@3", "BLOCO", "$@4", "CMDS", "CMD", "$@5", "$@6",
  "$@7", "FOR_INICIA", "FOR_INCREM", "DECL", "ATR", "EXP", "TERMO",
  "FATOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -55,     4,     2,   -55,     9,   -11,   -55,   -55,   -55,   -55,
     -55,    24,    18,    22,   -55,    27,    37,    38,    44,    45,
     -55,   -55,   226,   -55,     2,   -55,    51,   -55,    41,    49,
      26,    12,   -55,    21,   232,   -55,   232,   232,    52,    55,
     -55,   -55,   232,    76,   100,    48,   -55,    35,   -55,    53,
     -55,   -55,   232,   232,   232,   232,   232,   232,   -55,   232,
     232,   232,   232,   232,   232,   -55,   232,   213,   124,   131,
      66,    83,   -11,    54,   -55,   -55,   138,    56,   -55,    59,
     100,   232,   -55,   232,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,   -55,   -55,   100,   100,   213,    52,
     -55,    60,    58,   232,    65,    68,   -55,   -55,   -55,   169,
      64,    67,    82,    52,   232,   175,   -55,   -55,    71,    80,
     -55,    52,   -55,   182,   262,   -55,   -55,   -55,    81,    78,
     -55,   213,   -55,   -55,    52,   -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     6,     1,     0,    63,    65,    66,    67,    68,
      69,     0,     0,     0,    29,     0,     0,     0,     0,     0,
      13,    14,     0,     3,     6,     7,     0,     8,    19,    21,
      23,    57,    60,    44,     0,    64,     0,     0,     0,    40,
      34,    35,     0,     0,    17,     0,    63,     0,     5,     0,
      20,    22,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     9,     0,    46,     0,     0,
       0,     0,     0,     0,    38,    39,     0,     0,    24,     0,
      17,     0,    61,     0,    51,    52,    53,    54,    55,    56,
      47,    48,    49,    50,    58,    59,    17,    17,    45,     0,
      27,     0,    44,     0,     0,     0,    15,    16,    62,     0,
       0,     0,    25,     0,     0,     0,    36,    37,     0,     0,
      12,     0,    28,     0,    43,    31,    10,    26,     0,     0,
      41,    42,    30,    32,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,    89,   -55,   -55,   -55,   -55,   -37,   -55,
     -54,     0,   -55,   -55,   -55,   -55,   -55,    75,   -36,   -22,
     220,   -47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    23,    24,    25,    96,    97,    26,    44,
      79,    80,   113,    38,   134,    73,   129,    28,    29,    30,
      31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    70,    27,    75,     3,     4,     5,     6,     7,     8,
       9,    10,    67,    33,    68,    69,    94,    95,    11,    12,
      76,    13,    14,    15,    27,    34,   107,    16,    35,    17,
      18,    19,    20,    21,   108,    22,    52,    53,    54,    55,
      56,    57,   110,   111,    98,    52,    53,    54,    55,    56,
      57,    36,    65,    63,    64,    37,    58,    66,    71,    72,
      39,   109,   112,    59,    60,    61,    62,    40,    41,    82,
      49,    50,    59,    60,    61,    62,   122,    42,    43,    51,
      77,   115,    81,    21,   127,   101,    83,   102,   130,   103,
     105,   106,   123,   114,    66,   116,   119,   135,   117,   120,
     121,   125,   131,    71,     5,     6,     7,     8,     9,    10,
     126,   132,   133,    48,    74,     0,    11,    12,     0,    13,
      14,    15,     0,     0,     0,    16,     0,    17,    18,    19,
      78,    21,     0,    22,    52,    53,    54,    55,    56,    57,
       0,    52,    53,    54,    55,    56,    57,     0,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,    99,     0,
       0,    59,    60,    61,    62,   100,     0,     0,    59,    60,
      61,    62,   104,     0,     0,    59,    60,    61,    62,    52,
      53,    54,    55,    56,    57,    52,    53,    54,    55,    56,
      57,     0,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,   118,     0,     0,    59,    60,    61,    62,
     124,     0,    59,    60,    61,    62,   128,     0,     0,    59,
      60,    61,    62,    52,    53,    54,    55,    56,    57,    45,
      46,     6,     7,     8,     9,    10,    46,     6,     7,     8,
       9,    10,    11,     0,     0,     0,     0,     0,    11,     0,
      59,    60,    61,    62,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,    22,     5,     6,     7,     8,
       9,    10,    84,    85,    86,    87,    88,    89,    11,    90,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22
};

static const yytype_int16 yycheck[] =
{
      22,    38,     2,    39,     0,     3,     4,     5,     6,     7,
       8,     9,    34,     4,    36,    37,    63,    64,    16,    17,
      42,    19,    20,    21,    24,    36,    80,    25,     4,    27,
      28,    29,    30,    31,    81,    33,    10,    11,    12,    13,
      14,    15,    96,    97,    66,    10,    11,    12,    13,    14,
      15,    33,    31,    41,    42,    33,    30,    36,     3,     4,
      33,    83,    99,    37,    38,    39,    40,    30,    30,    34,
      19,    30,    37,    38,    39,    40,   113,    33,    33,    30,
       4,   103,    34,    31,   121,    19,    33,     4,   124,    35,
      34,    32,   114,    33,    36,    30,    32,   134,    30,    32,
      18,    30,   124,     3,     4,     5,     6,     7,     8,     9,
      30,    30,    34,    24,    39,    -1,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    33,    10,    11,    12,    13,    14,    15,
      -1,    10,    11,    12,    13,    14,    15,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    37,    38,    39,    40,    34,    -1,    -1,    37,    38,
      39,    40,    34,    -1,    -1,    37,    38,    39,    40,    10,
      11,    12,    13,    14,    15,    10,    11,    12,    13,    14,
      15,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      35,    -1,    37,    38,    39,    40,    34,    -1,    -1,    37,
      38,    39,    40,    10,    11,    12,    13,    14,    15,     3,
       4,     5,     6,     7,     8,     9,     4,     5,     6,     7,
       8,     9,    16,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    33,     4,     5,     6,     7,
       8,     9,    52,    53,    54,    55,    56,    57,    16,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,     3,     4,     5,     6,     7,     8,
       9,    16,    17,    19,    20,    21,    25,    27,    28,    29,
      30,    31,    33,    46,    47,    48,    51,    54,    60,    61,
      62,    63,    64,     4,    36,     4,    33,    33,    56,    33,
      30,    30,    33,    33,    52,     3,     4,    62,    46,    19,
      30,    30,    10,    11,    12,    13,    14,    15,    30,    37,
      38,    39,    40,    41,    42,    31,    36,    62,    62,    62,
      51,     3,     4,    58,    60,    61,    62,     4,    30,    53,
      54,    34,    34,    33,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    49,    50,    62,    34,
      34,    19,     4,    35,    34,    34,    32,    53,    64,    62,
      53,    53,    51,    55,    33,    62,    30,    30,    34,    32,
      32,    18,    51,    62,    35,    30,    30,    51,    34,    59,
      61,    62,    30,    34,    57,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    44,    46,    46,    47,    47,    49,
      48,    50,    48,    48,    52,    51,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    54,    56,
      54,    54,    57,    54,    54,    54,    54,    54,    58,    58,
      58,    59,    59,    59,    60,    60,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     0,     1,     1,     0,
       7,     0,     6,     1,     0,     4,     2,     0,     2,     1,
       2,     1,     2,     1,     1,     5,     7,     0,     6,     0,
       8,     6,     0,    10,     2,     2,     5,     5,     1,     1,
       0,     1,     1,     0,     2,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     4,     1,     2,     1,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 76 "sintatica.y"
                   { entraEscopo(); }
#line 1402 "y.tab.c"
    break;

  case 3: /* START: $@1 CODIGO  */
#line 77 "sintatica.y"
                {
                    if(debug) cout << "[DEBUG] Árvore completa gerada. Tradução:\n";

                    string defines = "\n\t#define true 1\n\t#define false 0\n\n\n";
                    string declaracoes = "";
                    for(auto i: temporarias){
                         if(i.second == "string" || i.second == "char_array")
                          declaracoes += "\tchar " + i.first + "[100];\n"; // tamanho fixo 100, pode melhorar
                        else
                          declaracoes += "\t" + i.second + " " + i.first + ";\n";
                    }
                    cout << defines << declaracoes << endl << yyvsp[0].traducao << endl;
                    saiEscopo();
                }
#line 1421 "y.tab.c"
    break;

  case 5: /* CODIGO: ITEM CODIGO  */
#line 95 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1429 "y.tab.c"
    break;

  case 6: /* CODIGO: %empty  */
#line 99 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1437 "y.tab.c"
    break;

  case 7: /* ITEM: BLOCO_DECL  */
#line 105 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1445 "y.tab.c"
    break;

  case 8: /* ITEM: CMD  */
#line 109 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1453 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 114 "sintatica.y"
                                { entraEscopo(); }
#line 1459 "y.tab.c"
    break;

  case 10: /* BLOCO_DECL: TK_TIPO TK_ID '{' $@2 CMDS '}' FIM_LINHA  */
#line 115 "sintatica.y"
            {
                yyval.tipo = pegaTipo(yyvsp[-6].label); 
                yyval.traducao =  yyval.tipo + " " + yyvsp[-5].label + "(){\n" + yyvsp[-2].traducao + "}\n"; 
                printTabelaSimbolos();
                saiEscopo();
                if(debug) cout << "[DEBUG] Bloco de declaração identificado.\n";
            }
#line 1471 "y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 122 "sintatica.y"
                                { entraEscopo(); }
#line 1477 "y.tab.c"
    break;

  case 12: /* BLOCO_DECL: TK_TIPO TK_ID '{' $@3 CMDS '}'  */
#line 123 "sintatica.y"
            {

                yyval.tipo = pegaTipo(yyvsp[-5].label);
                yyval.traducao =  yyval.tipo + " " + yyvsp[-4].label + "(){\n" + yyvsp[-1].traducao + "}\n";
                printTabelaSimbolos();
                saiEscopo();
                if(debug) cout << "[DEBUG] Bloco de declaração identificado.\n";
            }
#line 1490 "y.tab.c"
    break;

  case 13: /* BLOCO_DECL: FIM_LINHA  */
#line 132 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1498 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 137 "sintatica.y"
                  { entraEscopo(); }
#line 1504 "y.tab.c"
    break;

  case 15: /* BLOCO: '{' $@4 CMDS '}'  */
#line 138 "sintatica.y"
            {   
                printTabelaSimbolos();
                yyval.traducao = yyvsp[-1].traducao;
                saiEscopo();
            }
#line 1514 "y.tab.c"
    break;

  case 16: /* CMDS: CMD CMDS  */
#line 146 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
                if(debug) cout << "[DEBUG] Comando processado. Acumulado:\n" << yyvsp[-1].traducao;
            }
#line 1523 "y.tab.c"
    break;

  case 17: /* CMDS: %empty  */
#line 151 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1531 "y.tab.c"
    break;

  case 18: /* CMD: EXP FIM_LINHA  */
#line 156 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1537 "y.tab.c"
    break;

  case 19: /* CMD: DECL  */
#line 157 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1543 "y.tab.c"
    break;

  case 20: /* CMD: DECL FIM_LINHA  */
#line 158 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1549 "y.tab.c"
    break;

  case 21: /* CMD: ATR  */
#line 159 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1555 "y.tab.c"
    break;

  case 22: /* CMD: ATR FIM_LINHA  */
#line 160 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1561 "y.tab.c"
    break;

  case 23: /* CMD: EXP  */
#line 161 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1567 "y.tab.c"
    break;

  case 24: /* CMD: FIM_LINHA  */
#line 162 "sintatica.y"
                             { yyval.traducao = "";          }
#line 1573 "y.tab.c"
    break;

  case 25: /* CMD: TK_IF '(' EXP ')' BLOCO  */
#line 164 "sintatica.y"
            {
                // Rótulo para o final do 'if'
                string rotuloFimIf = novo_rotulo();

                // 1. Variável para receber a CÓPIA do resultado da condição (o seu T6)
                string temp_copia = insereTemporariasTabelaSimbolos("", "bool");

                // 2. Variável para receber a NEGAÇÃO da cópia (o seu T7)
                string temp_negada = insereTemporariasTabelaSimbolos("", "bool");

                // 3. Monta a tradução para gerar o código EXATO que você quer:
                yyval.traducao = yyvsp[-2].traducao +      // Gera: T4 = T2 >= T3;  ($3.label é T4)
                            
                            // Gera a cópia: T6 = T4
                            "\t" + temp_copia + " = " + yyvsp[-2].label + ";\n" +
                            
                            // Gera a negação explícita: T7 = !T6
                            "\t" + temp_negada + " = !" + temp_copia + ";\n" +
                            
                            // Gera o desvio condicional: if (T7) goto L0;
                            "\tif (" + temp_negada + ") goto " + rotuloFimIf + ";\n" +
                            
                            yyvsp[0].traducao +          // Corpo do 'if'
                            rotuloFimIf + ":\n";     // Rótulo de saída
            }
#line 1603 "y.tab.c"
    break;

  case 26: /* CMD: TK_IF '(' EXP ')' BLOCO TK_ELSE BLOCO  */
#line 190 "sintatica.y"
            {
                string rotuloElse = novo_rotulo();
                string rotuloFimIfElse = novo_rotulo();

                string temp_copia = insereTemporariasTabelaSimbolos("", "bool");
                string temp_negada = insereTemporariasTabelaSimbolos("", "bool");

                yyval.traducao = yyvsp[-4].traducao + 
                            
                            "\t" + temp_copia + " = " + yyvsp[-4].label + ";\n" +
                            "\t" + temp_negada + " = !" + temp_copia + ";\n" +
                            "\tif (" + temp_negada + ") goto " + rotuloElse + ";\n" +
                            yyvsp[-2].traducao +
                            "\tgoto " + rotuloFimIfElse + ";\n" +
                            rotuloElse + ":\n" + 
                            yyvsp[0].traducao +
                            rotuloFimIfElse + ":\n";
            }
#line 1626 "y.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 210 "sintatica.y"
            {
                string rotuloTeste = novo_rotulo();
                string rotuloFimWhile = novo_rotulo();

                pilhaRotulosProxIteracao.push(rotuloTeste);
                pilhaRotulosFimLoop.push(rotuloFimWhile); 

            }
#line 1639 "y.tab.c"
    break;

  case 28: /* CMD: TK_WHILE '(' EXP ')' $@5 BLOCO  */
#line 219 "sintatica.y"
            {

                string rotuloTeste = pilhaRotulosProxIteracao.top(); // Rotulo para o continue
                string rotuloFimWhile = pilhaRotulosFimLoop.top();   // Rotulo para o break

                yyval.traducao = rotuloTeste + ":\n" +
                            yyvsp[-3].traducao + // Exp do While
                            "\tif (!" + yyvsp[-3].label + ") goto " + rotuloFimWhile + ";\n" +
                            yyvsp[0].traducao +
                            "\tgoto " + rotuloTeste + ";\n" +
                            rotuloFimWhile + ":\n";

                // Agora, desempilha.
                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
#line 1660 "y.tab.c"
    break;

  case 29: /* $@6: %empty  */
#line 236 "sintatica.y"
              {
                  // Rótulos que serão o destino do break e continue
                  string rotuloTeste = novo_rotulo();         // Destino do continue
                  string rotuloFimDoWhile = novo_rotulo();    // Destino do break

                  pilhaRotulosProxIteracao.push(rotuloTeste);
                  pilhaRotulosFimLoop.push(rotuloFimDoWhile);
              }
#line 1673 "y.tab.c"
    break;

  case 30: /* CMD: TK_DO $@6 BLOCO TK_WHILE '(' EXP ')' FIM_LINHA  */
#line 245 "sintatica.y"
            {

                string rotuloTeste = pilhaRotulosProxIteracao.top();
                string rotuloFimDoWhile = pilhaRotulosFimLoop.top();

                string rotuloCorpo = novo_rotulo();

                yyval.traducao = rotuloCorpo + ":\n" +      
                              yyvsp[-5].traducao +             
                              rotuloTeste + ":\n" +     
                              yyvsp[-2].traducao +             
                              "\tif (" + yyvsp[-2].label + ") goto " + rotuloCorpo + ";\n" + 
                              rotuloFimDoWhile + ":\n";

                // Desempilha os rótulos.
                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
#line 1696 "y.tab.c"
    break;

  case 31: /* CMD: BLOCO TK_WHILE '(' EXP ')' FIM_LINHA  */
#line 264 "sintatica.y"
            {
                string rotuloTeste = pilhaRotulosProxIteracao.top();
                string rotuloFimDoWhile = pilhaRotulosFimLoop.top();

                string rotuloCorpo = novo_rotulo(); 

                yyval.traducao = rotuloCorpo + ":\n" +    
                              yyvsp[-3].traducao +          
                              rotuloTeste + ":\n" +    
                              yyvsp[0].traducao +           
                              "\tif (" + yyvsp[0].label + ") goto " + rotuloCorpo + ";\n" + 
                              rotuloFimDoWhile + ":\n"; 

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
#line 1717 "y.tab.c"
    break;

  case 32: /* $@7: %empty  */
#line 281 "sintatica.y"
            {
                  string rotuloIncremento = novo_rotulo();
                  string rotuloFimFor = novo_rotulo();

                  pilhaRotulosProxIteracao.push(rotuloIncremento);
                  pilhaRotulosFimLoop.push(rotuloFimFor);

            }
#line 1730 "y.tab.c"
    break;

  case 33: /* CMD: TK_FOR '(' FOR_INICIA ';' EXP ';' FOR_INCREM ')' $@7 BLOCO  */
#line 290 "sintatica.y"
            {

                string rotuloIncrementoReal = pilhaRotulosProxIteracao.top();
                string rotuloFimForReal = pilhaRotulosFimLoop.top();

                string rotuloTesteReal = novo_rotulo();

                yyval.traducao = yyvsp[-7].traducao;               
                yyval.traducao += rotuloTesteReal + ":\n";  
                yyval.traducao += yyvsp[-5].traducao;              
                yyval.traducao += "\tif (!" + yyvsp[-5].label + ") goto " + rotuloFimForReal + ";\n"; 
                yyval.traducao += yyvsp[0].traducao;             
                yyval.traducao += rotuloIncrementoReal + ":\n"; 
                yyval.traducao += yyvsp[-3].traducao;             
                yyval.traducao += "\tgoto " + rotuloTesteReal + ";\n"; 
                yyval.traducao += rotuloFimForReal + ":\n";      

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();

            }
#line 1756 "y.tab.c"
    break;

  case 34: /* CMD: TK_BREAK FIM_LINHA  */
#line 312 "sintatica.y"
            {
                if (pilhaRotulosFimLoop.empty()) {
                    yyerror("Erro semântico: 'pare' (break) fora de um laço.");
                }
                yyval.traducao = "\tgoto " + pilhaRotulosFimLoop.top() + ";\n";
            }
#line 1767 "y.tab.c"
    break;

  case 35: /* CMD: TK_CONTINUE FIM_LINHA  */
#line 319 "sintatica.y"
            {
                if (pilhaRotulosProxIteracao.empty()) {
                    yyerror("Erro semântico: 'passa' (continue) fora de um laço.");
                }
                yyval.traducao = "\tgoto " + pilhaRotulosProxIteracao.top() + ";\n";
            }
#line 1778 "y.tab.c"
    break;

  case 36: /* CMD: TK_PRINT '(' EXP ')' FIM_LINHA  */
#line 326 "sintatica.y"
            {
                string formato = "";
                if (yyvsp[-2].tipo == "int") {
                    formato = "%d";
                } else if (yyvsp[-2].tipo == "float") {
                    formato = "%f";
                } else if (yyvsp[-2].tipo == "char") {
                    formato = "%c";
                } else if (yyvsp[-2].tipo == "bool") { 
                    formato = "%d";
                } else { // adicionar o 
                    yyerror("Tipo inválido para 'fala' (print): " + yyvsp[-2].tipo);
                }

                yyval.traducao = yyvsp[-2].traducao + "\tprintf(\"" + formato + "\\n\", " + yyvsp[-2].label + ");\n";
            }
#line 1799 "y.tab.c"
    break;

  case 37: /* CMD: TK_SCAN '(' TK_ID ')' FIM_LINHA  */
#line 343 "sintatica.y"
            {

                   TIPO_SIMBOLO varSimbolo;
                if (!verificaTabelaSimbolos(yyvsp[-2].label)) {
                    yyerror("Variável '" + yyvsp[-2].label + "' não declarada para 'ouve' (scan).");
                } else {
                    varSimbolo = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
                }

                string tempLer = insereTemporariasTabelaSimbolos("", varSimbolo.tipoVariavel);

                string formato = "";
                if (varSimbolo.tipoVariavel == "int") {
                    formato = "%d";
                } else if (varSimbolo.tipoVariavel == "float") {
                    formato = "%f";
                } else if (varSimbolo.tipoVariavel == "char") {
                    formato = " %c";
                } else if (varSimbolo.tipoVariavel == "bool") {
                    formato = "%d"; 
                } else {
                    yyerror("Tipo inválido para 'ouve' (scan): " + varSimbolo.tipoVariavel);
                }

                string traducaoLeitura = "\tscanf(\"" + formato + "\", &" + tempLer + ");\n";
                string traducaoAtr = "\t" + varSimbolo.label + " = " + tempLer + ";\n";

                yyval.traducao = traducaoLeitura + traducaoAtr;
            }
#line 1833 "y.tab.c"
    break;

  case 38: /* FOR_INICIA: DECL  */
#line 375 "sintatica.y"
                   { yyval.traducao = yyvsp[0].traducao; }
#line 1839 "y.tab.c"
    break;

  case 39: /* FOR_INICIA: ATR  */
#line 376 "sintatica.y"
                  { yyval.traducao = yyvsp[0].traducao; }
#line 1845 "y.tab.c"
    break;

  case 40: /* FOR_INICIA: %empty  */
#line 377 "sintatica.y"
              { yyval.traducao = ""; }
#line 1851 "y.tab.c"
    break;

  case 41: /* FOR_INCREM: ATR  */
#line 380 "sintatica.y"
            { yyval.traducao = yyvsp[0].traducao; }
#line 1857 "y.tab.c"
    break;

  case 42: /* FOR_INCREM: EXP  */
#line 382 "sintatica.y"
            { yyval.traducao = yyvsp[0].traducao; }
#line 1863 "y.tab.c"
    break;

  case 43: /* FOR_INCREM: %empty  */
#line 384 "sintatica.y"
            { yyval.traducao = ""; }
#line 1869 "y.tab.c"
    break;

  case 44: /* DECL: TK_TIPO TK_ID  */
#line 389 "sintatica.y"
            {
               if(yyvsp[-1].label == "falada") {
            insereFixasTabelaSimbolos(yyvsp[0].label, "string");  // registra tipo string na tabela
        } else {
            insereFixasTabelaSimbolos(yyvsp[0].label, yyvsp[-1].label);
        }
        yyval.traducao = ""; // declaração será feita no final no start
            }
#line 1882 "y.tab.c"
    break;

  case 45: /* DECL: TK_TIPO TK_ID '=' EXP  */
#line 398 "sintatica.y"
            {
                insereFixasTabelaSimbolos(yyvsp[-2].label, yyvsp[-3].label);

                TIPO_SIMBOLO varSimbolo = pegaVariavelTabelaSimbolos(yyvsp[-2].label);

                if (varSimbolo.tipoVariavel != pegaTipo(yyvsp[0].tipo)) {
                    yyerror("Variável '" + yyvsp[-2].label + "' não suporta valor atribuído.");
                }

                if (varSimbolo.tipoVariavel == "string") {
                    // inicialização de string com strcpy
                    yyval.traducao = yyvsp[0].traducao + "\tstrcpy(" + varSimbolo.label + ", " + yyvsp[0].label + ");\n";
                } else {
                    yyval.traducao = yyvsp[0].traducao + "\t" + varSimbolo.label + " = " + yyvsp[0].label + ";\n";
                }
            }
#line 1903 "y.tab.c"
    break;

  case 46: /* ATR: TK_ID '=' EXP  */
#line 417 "sintatica.y"
            {

                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos(yyvsp[-2].label))
                    yyerror("Não foi declarado essa variável");
                else
                    temp = pegaVariavelTabelaSimbolos((yyvsp[-2].label));

                if(debug) cout << "[DEBUG] Atribuição: " << yyvsp[-2].label << " = " << yyvsp[0].label 
                << "\n  Tipos: " << temp.tipoVariavel << " <- " << yyvsp[0].tipo << endl;

                if(temp.tipoVariavel != pegaTipo(yyvsp[0].tipo))
                    yyerror("Variavel nao suporta valor atribuido");

                yyval.label = temp.label;
                if (temp.tipoVariavel == "string") {
                    yyval.traducao = yyvsp[0].traducao + "\tstrcpy(" + temp.label + ", " + yyvsp[0].label + ");\n";
                } else {
                    yyval.traducao = yyvsp[0].traducao + "\t" + temp.label + " = " + yyvsp[0].label + ";\n";
                }

            }
#line 1931 "y.tab.c"
    break;

  case 47: /* EXP: EXP '+' TERMO  */
#line 443 "sintatica.y"
            {   
                
                if(debug) cout << "[DEBUG] Operação + entre: " << yyvsp[-2].tipo << " e " << yyvsp[0].tipo 
                << "\n  Label1: " << yyvsp[-2].label << " | Label2: " << yyvsp[0].label << endl;

                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;

                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                    "\t" + yyval.label + " = " + temporario + " + " + yyvsp[0].label + ";\n"; 

                }
                else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                    "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + temporario + ";\n"; 
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                {
                    string erro = "[ERRO] Operação '+' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
                }
            }
#line 1970 "y.tab.c"
    break;

  case 48: /* EXP: EXP '-' TERMO  */
#line 478 "sintatica.y"
            {   
                if(debug) cout << "\n[DEBUG] Operação - entre: " << yyvsp[-2].tipo << " e " << yyvsp[0].tipo 
                << "\n\t  Label1: " << yyvsp[-2].label << " | Label2: " << yyvsp[0].label << endl;
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
                
                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                    "\t" + yyval.label + " = " + temporario + " - " + yyvsp[0].label + ";\n"; 

                }
                else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                    "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + temporario + ";\n"; 
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool"|| yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                {
                    string erro = "[ERRO] Operação '-' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
                }
            }
#line 2007 "y.tab.c"
    break;

  case 49: /* EXP: EXP '>' TERMO  */
#line 511 "sintatica.y"
            {   
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                { 
                    string erro = "[ERRO] Operação '>' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string" )
                    yyerror("Operandos inválidos\n");
                    
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
            }
#line 2027 "y.tab.c"
    break;

  case 50: /* EXP: EXP '<' TERMO  */
#line 527 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '<' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
            }
#line 2047 "y.tab.c"
    break;

  case 51: /* EXP: EXP TK_MAIOR_IGUAL TERMO  */
#line 543 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '>=' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
            }
#line 2066 "y.tab.c"
    break;

  case 52: /* EXP: EXP TK_MENOR_IGUAL TERMO  */
#line 558 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '<=' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
            }
#line 2086 "y.tab.c"
    break;

  case 53: /* EXP: EXP TK_DIFERENTE TERMO  */
#line 574 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '!=' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";          
            }
#line 2105 "y.tab.c"
    break;

  case 54: /* EXP: EXP TK_IGUAL TERMO  */
#line 589 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                    {
                        string erro = "[ERRO] Operação '==' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                        yyerror(erro);
                    }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";          
            }
#line 2124 "y.tab.c"
    break;

  case 55: /* EXP: EXP TK_E_LOGICO TERMO  */
#line 604 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
                    yyerror("Operandos inválidos\n");

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";  
            }
#line 2139 "y.tab.c"
    break;

  case 56: /* EXP: EXP TK_OU_LOGICO TERMO  */
#line 615 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
                    yyerror("Operandos inválidos\n");

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";  
            }
#line 2154 "y.tab.c"
    break;

  case 57: /* EXP: TERMO  */
#line 626 "sintatica.y"
            { 
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao;
                yyval.tipo = yyvsp[0].tipo;        
            }
#line 2164 "y.tab.c"
    break;

  case 58: /* TERMO: TERMO '*' FATOR  */
#line 634 "sintatica.y"
            {   
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("",   yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;

                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                    "\t" + yyval.label + " = " + temporario + " * " + yyvsp[0].label + ";\n"; 

                }
                else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                    "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + temporario + ";\n"; 
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                {
                    string erro = "[ERRO] Operação '*' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao = "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
                }
            }
#line 2199 "y.tab.c"
    break;

  case 59: /* TERMO: TERMO '/' FATOR  */
#line 665 "sintatica.y"
            { 
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("",   yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;

                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                    "\t" + yyval.label + " = " + temporario + " / " + yyvsp[0].label + ";\n"; 

                }
                else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") 
                {
                    if(debug) cout << "[DEBUG] Convertendo int para float: " << yyvsp[-2].label << endl;
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                    "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + temporario + ";\n"; 
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string")
                {
                    string erro = "[ERRO] Operação '/' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao = "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
                }
            }
#line 2234 "y.tab.c"
    break;

  case 60: /* TERMO: FATOR  */
#line 696 "sintatica.y"
            { 
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao; 
                yyval.tipo = yyvsp[0].tipo;
            }
#line 2244 "y.tab.c"
    break;

  case 61: /* FATOR: '(' EXP ')'  */
#line 704 "sintatica.y"
            { 
                yyval.label = yyvsp[-1].label;
                yyval.traducao = yyvsp[-1].traducao;
                yyval.tipo = yyvsp[-1].tipo;
            }
#line 2254 "y.tab.c"
    break;

  case 62: /* FATOR: '(' TK_TIPO ')' FATOR  */
#line 710 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", yyvsp[-2].label);
                yyval.tipo = yyvsp[-2].label;

                yyval.traducao = yyvsp[0].traducao +
                "\t" + yyval.label + " = (" + yyvsp[-2].label + ") " + yyvsp[0].label + ";\n";
            }
#line 2266 "y.tab.c"
    break;

  case 63: /* FATOR: TK_ID  */
#line 718 "sintatica.y"
            {
                TIPO_SIMBOLO temp;

                if(!verificaTabelaSimbolos(yyvsp[0].label))
                    yyerror("Não foi inicializado uma das variáveis");
                else 
                    temp = pegaVariavelTabelaSimbolos(yyvsp[0].label);
                
                if(debug) cout << "[DEBUG] Acessando variável: " << yyvsp[0].label 
                << " (Tipo: " << temp.tipoVariavel << ")\n";

                yyval.label = temp.label;
                yyval.tipo = temp.tipoVariavel;
                yyval.traducao = "";
            }
#line 2286 "y.tab.c"
    break;

  case 64: /* FATOR: TK_NEGACAO TK_ID  */
#line 734 "sintatica.y"
            {
                 yyval.tipo = "bool";

                TIPO_SIMBOLO temp;

                // verificao se é a variável correta

                if(!verificaTabelaSimbolos(yyvsp[0].label))
                    yyerror("Não foi inicializado uma das variáveis");
                else 
                    temp = pegaVariavelTabelaSimbolos(yyvsp[0].label);

                if("bool" != temp.tipoVariavel)
                    yyerror("Operação inválida para o tipo da variável");


                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = "\t" + yyval.label + " = !" + temp.label + ";\n";
            }
#line 2310 "y.tab.c"
    break;

  case 65: /* FATOR: TK_INT  */
#line 754 "sintatica.y"
            { 
                yyval.label = insereTemporariasTabelaSimbolos("", "nmr");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
                yyval.tipo = "int"; 
            }
#line 2320 "y.tab.c"
    break;

  case 66: /* FATOR: TK_FLOAT  */
#line 760 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", "ncv");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n"; 
                yyval.tipo = "float"; 
            }
#line 2330 "y.tab.c"
    break;

  case 67: /* FATOR: TK_BOOLEAN  */
#line 766 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "pp");
                string valor = pegaBooleano(yyvsp[0].label);

                if(valor == "error") yyerror("Valor atribuído de forma errada!");

                yyval.traducao = "\t" + yyval.label + " = " + valor + ";\n";
                yyval.tipo = "bool"; 
            }
#line 2344 "y.tab.c"
    break;

  case 68: /* FATOR: TK_CHAR  */
#line 776 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "letra");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
                yyval.tipo = "char"; 
            }
#line 2354 "y.tab.c"
    break;

  case 69: /* FATOR: TK_STRING  */
#line 781 "sintatica.y"
                       {
               cout << "label = " << yyval.traducao << endl;
               int tamanho = tamanho_string(yyval.traducao);
               yyval.label = insereTemporariasTabelaSimbolos("", "falada");
               yyval.traducao = "\tstrcpy(" + yyval.label + ", " + yyvsp[0].traducao + ");\n";
               yyval.tipo = "string"; 
            }
#line 2366 "y.tab.c"
    break;


#line 2370 "y.tab.c"

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

#line 790 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int tamanho_string(string texto){ 
    // pega as aspas da string
    // vou deixar -2 na saída p tirar as aspas
    // tem que colocar +1 por causa do \0 -> -2 + 1 = -1

    int tamanhoString = 0;
    int i = 0;
    while(texto[i] != '\0'){
        cout << texto[i] << " ";
        tamanhoString++;
        i++;
    }
    cout << endl;

    cout << tamanhoString-1<< endl;
    return tamanhoString-1;
}
string novo_rotulo() {
    return "L" + to_string(contador_rotulos++);
}

// Função para geração de variáveis temporárias
string geraNomeTemp(string tipo)    // Dá para melhorar essa função
{
    
    qntdVariaveisTemp++;

    if(tipo == "nmr" || tipo == "int")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "int"});
    else if(tipo == "ncv" || tipo == "float")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "float"});
    else if(tipo == "pp" || tipo == "bool")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "int"});
    else if(tipo == "letra" || tipo == "char")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "char"});
    else if(tipo == "falada" || tipo == "string")
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "char_array"});
    else // caso em que n tenha nenhum tipo atribuído - vamos inicializar "vazio" - ou em dinâmico
        temporarias.insert({"T" + to_string(qntdVariaveisTemp), "null"});
      
    return "T" + to_string(qntdVariaveisTemp); 
}

// Vai retonar ao registrador assoaciado a variável
string insereTemporariasTabelaSimbolos(string nome, string tipo)
{   
    if (pilhaTabelasSimbolos.empty()) {
        yyerror("Erro de lógica: Tentou gerar temporária sem um escopo ativo.");
        return ""; // Ou lance uma exceção
    }

    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();
    
    TIPO_SIMBOLO temp;
    temp.nomeVariavel = geraNomeTemp(tipo);
    temp.tipoVariavel = pegaTipo(tipo);
    temp.label = temp.nomeVariavel;

    escopoAtual[temp.nomeVariavel] = temp;

    if(debug) cout << "[DEBUG] Inserindo TEMPORARIA na tabela (escopo atual): " << temp.nomeVariavel << " (Tipo: " << temp.tipoVariavel << ")\n";

    return temp.label;
}

void insereFixasTabelaSimbolos(string nome, string tipo)
{   
    if (pilhaTabelasSimbolos.empty())
    {
        yyerror("Erro de lógica: Tentou declarar variável sem um escopo ativo.");
        return;
    }

    // Pega o escopo atual (topo da pilha)
    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();

    // Verifica se a variável já existe no escopo atual
    if (escopoAtual.count(nome))
    {
        yyerror("Erro: Variável '" + nome + "' já declarada neste escopo.");
        return;
    }

    if (debug) cout << "[DEBUG] Inserindo FIXA na tabela (escopo atual): " << nome << " (Tipo: " << tipo << ")\n";

    TIPO_SIMBOLO temp;
    temp.nomeVariavel = nome;
    temp.tipoVariavel = pegaTipo(tipo);
    if(debug) cout << "[DEBUG] Tipo processado em pegaTipo: '" << temp.tipoVariavel << "' para o tipo recebido: '" << tipo << "'\n";
    temp.label = geraNomeTemp(tipo);

    escopoAtual[nome] = temp;
}

// Função para verificar se existe na tabela de símbolos
bool verificaTabelaSimbolos(string nome)
{

    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i)
    {
        if (pilhaTabelasSimbolos[i].count(nome)) 
        { 
            return true; 
        }
    }
    return false;
}

// Só para pegar a variável na tabela de símbolos, tenho que setar em um caso onde não tenha
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome)
{
    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i) {
        if (pilhaTabelasSimbolos[i].count(nome)) {
            return pilhaTabelasSimbolos[i][nome];
        }
    }
    // Adicionado para evitar warning de "no return statement"
    yyerror("Variável '" + nome + "' não encontrada.");
    return {};
}

// Função para printar 
void printTabelaSimbolos()
{
    cout << "\n--- Tabela de Simbolos (Escopos) ---\n";
    for (size_t i = 0; i < pilhaTabelasSimbolos.size(); ++i) {
        cout << "Escopo " << i << ":\n";
        for (const auto& pair : pilhaTabelasSimbolos[i]) {
            const TIPO_SIMBOLO& simbolo = pair.second;
            cout << "  Nome: " << simbolo.nomeVariavel
                      << ", Tipo: " << simbolo.tipoVariavel
                      << ", Label: " << simbolo.label << endl;
        }
    }
    cout << "-----------------------------------\n";
}

// Função para converter tipo
string pegaTipo(string tipo) 
{
    if(tipo == "nmr" || tipo == "int")
        return "int";
    else if(tipo == "ncv" || tipo == "float")
        return "float";
    else if(tipo == "letra" || tipo == "char")
        return "char";
    else if(tipo == "pp" || tipo == "bool")
        return "bool";
     else if(tipo == "falada" || tipo == "string")
        return "string";    
    else 
        return "null";      
}

string infereTipo(string tipo1, string tipo2)
{   
    if(debug) cout << "[DEBUG] Inferindo tipo entre: " << tipo1 << " e " << tipo2 << endl;
    if(tipo1 == "int" && tipo1 == tipo2) return "int";
    else if(tipo1 == "char" || tipo2 == "char") yyerror("Operando inválido!");

    return "float";
}

string pegaBooleano(string valor)
{
    if(valor == "reto") return "true";
    else if(valor == "torto") return "false";
    else return "error"; // erro
}

void entraEscopo()
{
    pilhaTabelasSimbolos.push_back({});
    if (debug) cout << "[DEBUG] Entrou em um novo escopo. Tamanho da pilha: " << pilhaTabelasSimbolos.size() << endl;
}

void saiEscopo()
{
    if (!pilhaTabelasSimbolos.empty()) {
        pilhaTabelasSimbolos.pop_back(); 
        if (debug) cout << "[DEBUG] Saiu do escopo atual. Tamanho da pilha: " << pilhaTabelasSimbolos.size() << endl;
    } else {
        yyerror("Erro de lógica: Tentou sair de um escopo vazio.");
    }
}

int main( int argc, char* argv[] )
{   
    yyparse();
    return 0;
}


void yyerror( string MSG )
{
    cout << "Na linha " << yylinha << ": "<< MSG << endl;
    exit (0);
}
