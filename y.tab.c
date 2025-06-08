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

struct atributos // Atributos aqui é cada nó da árvore, cada nó possui:
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

bool verificaTabelaSimbolos(string nome);
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
void entraEscopo();
void saiEscopo();

void insereFixasTabelaSimbolos(string nome, string tipo);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

string geraNomeTemporarias(string tipo);
string pegaTipo(string tipo);
string infereTipo(string tipo1, string tipo2);
string pegaBooleano(string valor);

bool debug = false;
#define true 1
#define false 0

extern int yylinha;


#line 127 "y.tab.c"

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
    TK_MAIOR_IGUAL = 264,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 265,          /* TK_MENOR_IGUAL  */
    TK_DIFERENTE = 266,            /* TK_DIFERENTE  */
    TK_IGUAL = 267,                /* TK_IGUAL  */
    TK_E_LOGICO = 268,             /* TK_E_LOGICO  */
    TK_OU_LOGICO = 269,            /* TK_OU_LOGICO  */
    TK_NEGACAO = 270,              /* TK_NEGACAO  */
    FIM_LINHA = 271                /* FIM_LINHA  */
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
#define TK_MAIOR_IGUAL 264
#define TK_MENOR_IGUAL 265
#define TK_DIFERENTE 266
#define TK_IGUAL 267
#define TK_E_LOGICO 268
#define TK_OU_LOGICO 269
#define TK_NEGACAO 270
#define FIM_LINHA 271

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
  YYSYMBOL_TK_MAIOR_IGUAL = 9,             /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 10,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_DIFERENTE = 11,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_IGUAL = 12,                  /* TK_IGUAL  */
  YYSYMBOL_TK_E_LOGICO = 13,               /* TK_E_LOGICO  */
  YYSYMBOL_TK_OU_LOGICO = 14,              /* TK_OU_LOGICO  */
  YYSYMBOL_TK_NEGACAO = 15,                /* TK_NEGACAO  */
  YYSYMBOL_FIM_LINHA = 16,                 /* FIM_LINHA  */
  YYSYMBOL_17_ = 17,                       /* '{'  */
  YYSYMBOL_18_ = 18,                       /* '}'  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '>'  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_26_ = 26,                       /* '('  */
  YYSYMBOL_27_ = 27,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_START = 29,                     /* START  */
  YYSYMBOL_30_1 = 30,                      /* $@1  */
  YYSYMBOL_BLOCOS = 31,                    /* BLOCOS  */
  YYSYMBOL_BLOCO = 32,                     /* BLOCO  */
  YYSYMBOL_33_2 = 33,                      /* $@2  */
  YYSYMBOL_34_3 = 34,                      /* $@3  */
  YYSYMBOL_CMDS = 35,                      /* CMDS  */
  YYSYMBOL_CMD = 36,                       /* CMD  */
  YYSYMBOL_DECL = 37,                      /* DECL  */
  YYSYMBOL_ATR = 38,                       /* ATR  */
  YYSYMBOL_EXP = 39,                       /* EXP  */
  YYSYMBOL_TERMO = 40,                     /* TERMO  */
  YYSYMBOL_FATOR = 41                      /* FATOR  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   95

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  71

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


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
      26,    27,    24,    20,     2,    21,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    19,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    67,    80,    83,    88,    93,    93,   101,
     101,   108,   114,   120,   125,   126,   127,   128,   129,   130,
     131,   135,   142,   164,   199,   232,   248,   264,   279,   296,
     311,   326,   337,   348,   356,   387,   418,   426,   432,   440,
     456,   476,   482,   488,   498
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
  "TK_INT", "TK_FLOAT", "TK_BOOLEAN", "TK_CHAR", "TK_MAIOR_IGUAL",
  "TK_MENOR_IGUAL", "TK_DIFERENTE", "TK_IGUAL", "TK_E_LOGICO",
  "TK_OU_LOGICO", "TK_NEGACAO", "FIM_LINHA", "'{'", "'}'", "'='", "'+'",
  "'-'", "'>'", "'<'", "'*'", "'/'", "'('", "')'", "$accept", "START",
  "$@1", "BLOCOS", "BLOCO", "$@2", "$@3", "CMDS", "CMD", "DECL", "ATR",
  "EXP", "TERMO", "FATOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -37,    21,    14,   -37,    10,   -37,   -37,    14,    25,   -37,
     -37,    -3,    -3,    39,    26,   -37,   -37,   -37,   -37,    40,
     -37,     3,    33,    -3,    36,    37,    46,     9,   -37,    43,
     -37,    20,   -37,    38,   -37,    27,    47,   -37,   -37,   -37,
      20,    20,    20,    20,    20,    20,   -37,    20,    20,    20,
      20,    20,    20,   -37,    61,    20,   -37,   -37,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,   -37,   -37,
     -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     6,     1,     0,    11,     3,     6,     0,     5,
       7,    13,    13,     0,    39,    41,    42,    43,    44,     0,
      20,     0,     0,    13,    15,    17,    19,    33,    36,     0,
      21,     0,    40,     0,    39,     0,     0,    12,    16,    18,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,    10,    22,     0,    37,     8,    27,    28,
      29,    30,    31,    32,    23,    24,    25,    26,    34,    35,
      38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,    57,   -37,   -37,   -37,     8,   -37,   -37,
     -37,     1,    45,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,     7,    11,    12,    22,    23,    24,
      25,    26,    27,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      13,    14,    15,    16,    17,    18,    33,    34,    15,    16,
      17,    18,    19,    20,     8,    68,    69,     4,    19,    70,
      29,     3,    35,    21,    34,    15,    16,    17,    18,    21,
       5,    37,    54,    51,    52,    19,    40,    41,    42,    43,
      44,    45,    10,    30,    32,    31,    21,    47,    48,    49,
      50,    36,    38,    39,    56,    40,    41,    42,    43,    44,
      45,    53,    46,    57,     9,    55,    47,    48,    49,    50,
      40,    41,    42,    43,    44,    45,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    15,    16,     4,    51,    52,     3,    15,    55,
      12,     0,    21,    26,     4,     5,     6,     7,     8,    26,
      16,    23,    31,    24,    25,    15,     9,    10,    11,    12,
      13,    14,    17,     4,     4,    19,    26,    20,    21,    22,
      23,    18,    16,    16,    27,     9,    10,    11,    12,    13,
      14,    18,    16,    16,     7,    27,    20,    21,    22,    23,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,     0,     3,    16,    31,    32,     4,    31,
      17,    33,    34,     3,     4,     5,     6,     7,     8,    15,
      16,    26,    35,    36,    37,    38,    39,    40,    41,    35,
       4,    19,     4,     3,     4,    39,    18,    35,    16,    16,
       9,    10,    11,    12,    13,    14,    16,    20,    21,    22,
      23,    24,    25,    18,    39,    27,    27,    16,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    41,    41,
      41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    30,    29,    29,    31,    31,    33,    32,    34,
      32,    32,    35,    35,    36,    36,    36,    36,    36,    36,
      36,    37,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    40,    40,    40,    41,    41,    41,
      41,    41,    41,    41,    41
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     0,     0,     7,     0,
       6,     1,     2,     0,     2,     1,     2,     1,     2,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     4,     1,
       2,     1,     1,     1,     1
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
#line 67 "sintatica.y"
               { entraEscopo(); }
#line 1273 "y.tab.c"
    break;

  case 3: /* START: $@1 BLOCOS  */
#line 68 "sintatica.y"
            {   
                if(debug) cout << "[DEBUG] Árvore completa gerada. Tradução:\n";

                string defines = "\n\t#define true 1\n\t#define false 0\n\n\n";
                string declaracoes = "";
                for(auto i: temporarias){
                    declaracoes += "\t" + i.second + " " + i.first + ";\n";
                }
                cout << defines << declaracoes << endl << yyvsp[0].traducao << endl;
                //printTabelaSimbolos(); // - fins depurativos
                saiEscopo();
            }
#line 1290 "y.tab.c"
    break;

  case 5: /* BLOCOS: BLOCO BLOCOS  */
#line 84 "sintatica.y"
            {
                yyval.traducao =  yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1298 "y.tab.c"
    break;

  case 6: /* BLOCOS: %empty  */
#line 88 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1306 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 93 "sintatica.y"
                                { entraEscopo(); }
#line 1312 "y.tab.c"
    break;

  case 8: /* BLOCO: TK_TIPO TK_ID '{' $@2 CMDS '}' FIM_LINHA  */
#line 94 "sintatica.y"
            {
                yyval.traducao =  yyvsp[-6].label + " " + yyvsp[-5].label + "{\n" + yyvsp[-2].traducao + "}\n";
                printTabelaSimbolos();
                saiEscopo();
                if(debug) cout << "[DEBUG] Bloco identificado.\n";
            }
#line 1323 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 101 "sintatica.y"
                              { entraEscopo(); }
#line 1329 "y.tab.c"
    break;

  case 10: /* BLOCO: TK_TIPO TK_ID '{' $@3 CMDS '}'  */
#line 102 "sintatica.y"
            {
                yyval.traducao =  yyvsp[-5].label + " " + yyvsp[-4].label + "{\n" + yyvsp[-1].traducao + "}\n";
                printTabelaSimbolos(); 
                saiEscopo();
                if(debug) cout << "[DEBUG] Bloco identificado.\n";
            }
#line 1340 "y.tab.c"
    break;

  case 11: /* BLOCO: FIM_LINHA  */
#line 109 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1348 "y.tab.c"
    break;

  case 12: /* CMDS: CMD CMDS  */
#line 115 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
                if(debug) cout << "[DEBUG] Comando processado. Acumulado:\n" << yyvsp[-1].traducao;
            }
#line 1357 "y.tab.c"
    break;

  case 13: /* CMDS: %empty  */
#line 120 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1365 "y.tab.c"
    break;

  case 14: /* CMD: EXP FIM_LINHA  */
#line 125 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1371 "y.tab.c"
    break;

  case 15: /* CMD: DECL  */
#line 126 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1377 "y.tab.c"
    break;

  case 16: /* CMD: DECL FIM_LINHA  */
#line 127 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1383 "y.tab.c"
    break;

  case 17: /* CMD: ATR  */
#line 128 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1389 "y.tab.c"
    break;

  case 18: /* CMD: ATR FIM_LINHA  */
#line 129 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1395 "y.tab.c"
    break;

  case 19: /* CMD: EXP  */
#line 130 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1401 "y.tab.c"
    break;

  case 20: /* CMD: FIM_LINHA  */
#line 131 "sintatica.y"
                             { yyval.traducao = "";          }
#line 1407 "y.tab.c"
    break;

  case 21: /* DECL: TK_TIPO TK_ID  */
#line 136 "sintatica.y"
            { 
                insereFixasTabelaSimbolos(yyvsp[0].label, yyvsp[-1].label); 
                yyval.traducao = "";
            }
#line 1416 "y.tab.c"
    break;

  case 22: /* ATR: TK_ID '=' EXP  */
#line 143 "sintatica.y"
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
                yyval.traducao = yyvsp[0].traducao + "\t" + temp.label + " = " + yyvsp[0].label + ";\n";

            }
#line 1440 "y.tab.c"
    break;

  case 23: /* EXP: EXP '+' TERMO  */
#line 165 "sintatica.y"
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
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                {
                    string erro = "[ERRO] Operação '+' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
                }
            }
#line 1479 "y.tab.c"
    break;

  case 24: /* EXP: EXP '-' TERMO  */
#line 200 "sintatica.y"
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
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                {
                    string erro = "[ERRO] Operação '-' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
                }
            }
#line 1516 "y.tab.c"
    break;

  case 25: /* EXP: EXP '>' TERMO  */
#line 233 "sintatica.y"
            {   
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                { 
                    string erro = "[ERRO] Operação '>' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                    yyerror("Operandos inválidos\n");
                   
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
            }
#line 1536 "y.tab.c"
    break;

  case 26: /* EXP: EXP '<' TERMO  */
#line 249 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '<' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
            }
#line 1556 "y.tab.c"
    break;

  case 27: /* EXP: EXP TK_MAIOR_IGUAL TERMO  */
#line 265 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '>=' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
            }
#line 1575 "y.tab.c"
    break;

  case 28: /* EXP: EXP TK_MENOR_IGUAL TERMO  */
#line 280 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '<=' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                    yyerror("Operandos inválidos\n");
                

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
            }
#line 1596 "y.tab.c"
    break;

  case 29: /* EXP: EXP TK_DIFERENTE TERMO  */
#line 297 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                {
                    string erro = "[ERRO] Operação '!=' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";           
            }
#line 1615 "y.tab.c"
    break;

  case 30: /* EXP: EXP TK_IGUAL TERMO  */
#line 312 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if((yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") || (yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int")) 
                    {
                        string erro = "[ERRO] Operação '==' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                        yyerror(erro);
                    }
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                    yyerror("Operandos inválidos\n");
                
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";           
            }
#line 1634 "y.tab.c"
    break;

  case 31: /* EXP: EXP TK_E_LOGICO TERMO  */
#line 327 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
                    yyerror("Operandos inválidos\n");

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";  
            }
#line 1649 "y.tab.c"
    break;

  case 32: /* EXP: EXP TK_OU_LOGICO TERMO  */
#line 338 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
                    yyerror("Operandos inválidos\n");

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";  
            }
#line 1664 "y.tab.c"
    break;

  case 33: /* EXP: TERMO  */
#line 349 "sintatica.y"
            { 
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao;
                yyval.tipo = yyvsp[0].tipo;      
            }
#line 1674 "y.tab.c"
    break;

  case 34: /* TERMO: TERMO '*' FATOR  */
#line 357 "sintatica.y"
            {   
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("",  yyval.tipo);
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
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                {
                    string erro = "[ERRO] Operação '*' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao = "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
                }
            }
#line 1709 "y.tab.c"
    break;

  case 35: /* TERMO: TERMO '/' FATOR  */
#line 388 "sintatica.y"
            { 
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("",  yyval.tipo);
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
                else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
                {
                    string erro = "[ERRO] Operação '/' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo;
                    yyerror(erro);
                }
                else 
                {
                    yyval.traducao = "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
                }
            }
#line 1744 "y.tab.c"
    break;

  case 36: /* TERMO: FATOR  */
#line 419 "sintatica.y"
            { 
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao; 
                yyval.tipo = yyvsp[0].tipo;
            }
#line 1754 "y.tab.c"
    break;

  case 37: /* FATOR: '(' EXP ')'  */
#line 427 "sintatica.y"
            { 
                yyval.label = yyvsp[-1].label;
                yyval.traducao = yyvsp[-1].traducao;
                yyval.tipo = yyvsp[-1].tipo;
            }
#line 1764 "y.tab.c"
    break;

  case 38: /* FATOR: '(' TK_TIPO ')' FATOR  */
#line 433 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", yyvsp[-2].label);
                yyval.tipo = yyvsp[-2].label;

                yyval.traducao = yyvsp[0].traducao +
                "\t" + yyval.label + " = (" + yyvsp[-2].label + ") " + yyvsp[0].label + ";\n";
            }
#line 1776 "y.tab.c"
    break;

  case 39: /* FATOR: TK_ID  */
#line 441 "sintatica.y"
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
#line 1796 "y.tab.c"
    break;

  case 40: /* FATOR: TK_NEGACAO TK_ID  */
#line 457 "sintatica.y"
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
#line 1820 "y.tab.c"
    break;

  case 41: /* FATOR: TK_INT  */
#line 477 "sintatica.y"
            { 
                yyval.label = insereTemporariasTabelaSimbolos("", "nmr");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
                yyval.tipo = "int"; 
            }
#line 1830 "y.tab.c"
    break;

  case 42: /* FATOR: TK_FLOAT  */
#line 483 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", "ncv");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n"; 
                yyval.tipo = "float"; 
            }
#line 1840 "y.tab.c"
    break;

  case 43: /* FATOR: TK_BOOLEAN  */
#line 489 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "pp");
                string valor = pegaBooleano(yyvsp[0].label);

                if(valor == "error") yyerror("Valor atribuído de forma errada!");

                yyval.traducao = "\t" + yyval.label + " = " + valor + ";\n";
                yyval.tipo = "bool"; 
            }
#line 1854 "y.tab.c"
    break;

  case 44: /* FATOR: TK_CHAR  */
#line 499 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "letra");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
                yyval.tipo = "char"; 
            }
#line 1864 "y.tab.c"
    break;


#line 1868 "y.tab.c"

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

#line 506 "sintatica.y"


#include "lex.yy.c"

int yyparse();

// Função para geração de variáveis temporárias
string geraNomeTemp(string tipo)  // Dá para melhorar essa função
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
}

// Função para printar 
void printTabelaSimbolos()
{
    cout << "\n--- Tabela de Simbolos (Escopos) ---\n";
    for (size_t i = 0; i < pilhaTabelasSimbolos.size(); ++i) {
        cout << "Escopo " << i << ":\n";
        for (const auto& pair : pilhaTabelasSimbolos[i]) {
            const TIPO_SIMBOLO& simbolo = pair.second;
            std::cout << "  Nome: " << simbolo.nomeVariavel
                      << ", Tipo: " << simbolo.tipoVariavel
                      << ", Label: " << simbolo.label << std::endl;
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
