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
// Estrutura para guardar informações da função
struct TIPO_FUNCAO {
    string tipoRetorno;
    vector<string> tiposParametros;
};

// A nova tabela de símbolos para funções
map<string, TIPO_FUNCAO> tabelaFuncoes;
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

    bool isArray = false; // Indica se é uma matriz
    int arraySize = 0;         // tamanho primeira dimensão
    int arraySize2 = 0;        // tamanho segunda dimensão (nova)
     bool isParam = false; // <-- ADICIONE ESTE CAMPO

 int getTamanhoTotal() const {
        return arraySize * (arraySize2 > 0 ? arraySize2 : 1);
    }

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

void insereFixasTabelaSimbolos(string nome, string tipo,bool ehArray = false, int tamanhoArray = 0,int tamanhoArray2 = 0,bool ehParam = false);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

string novo_rotulo();

string geraNomeTemp(string tipo);
string pegaTipo(string tipo);
string infereTipo(string tipo1, string tipo2);
string pegaBooleano(string valor);
int tamanho_string(string texto);

bool debug = false;
#define true 1
#define false 0

extern int yylinha;


#line 150 "y.tab.c"

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
    TK_RETURN = 260,               /* TK_RETURN  */
    TK_INT = 261,                  /* TK_INT  */
    TK_FLOAT = 262,                /* TK_FLOAT  */
    TK_BOOLEAN = 263,              /* TK_BOOLEAN  */
    TK_CHAR = 264,                 /* TK_CHAR  */
    TK_STRING = 265,               /* TK_STRING  */
    TK_MAIOR_IGUAL = 266,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 267,          /* TK_MENOR_IGUAL  */
    TK_DIFERENTE = 268,            /* TK_DIFERENTE  */
    TK_IGUAL = 269,                /* TK_IGUAL  */
    TK_E_LOGICO = 270,             /* TK_E_LOGICO  */
    TK_OU_LOGICO = 271,            /* TK_OU_LOGICO  */
    TK_NEGACAO = 272,              /* TK_NEGACAO  */
    TK_IF = 273,                   /* TK_IF  */
    TK_ELSE = 274,                 /* TK_ELSE  */
    TK_WHILE = 275,                /* TK_WHILE  */
    TK_DO = 276,                   /* TK_DO  */
    TK_FOR = 277,                  /* TK_FOR  */
    TK_IN = 278,                   /* TK_IN  */
    TK_SWITCH = 279,               /* TK_SWITCH  */
    TK_CASE = 280,                 /* TK_CASE  */
    TK_BREAK = 281,                /* TK_BREAK  */
    TK_DEFAULT = 282,              /* TK_DEFAULT  */
    TK_CONTINUE = 283,             /* TK_CONTINUE  */
    TK_INCREMENTO = 284,           /* TK_INCREMENTO  */
    TK_DECREMENTO = 285,           /* TK_DECREMENTO  */
    TK_MAIS_IGUAL = 286,           /* TK_MAIS_IGUAL  */
    TK_MENOS_IGUAL = 287,          /* TK_MENOS_IGUAL  */
    TK_MULT_IGUAL = 288,           /* TK_MULT_IGUAL  */
    TK_DIV_IGUAL = 289,            /* TK_DIV_IGUAL  */
    TK_PRINT = 290,                /* TK_PRINT  */
    TK_SCAN = 291,                 /* TK_SCAN  */
    FIM_LINHA = 292                /* FIM_LINHA  */
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
#define TK_RETURN 260
#define TK_INT 261
#define TK_FLOAT 262
#define TK_BOOLEAN 263
#define TK_CHAR 264
#define TK_STRING 265
#define TK_MAIOR_IGUAL 266
#define TK_MENOR_IGUAL 267
#define TK_DIFERENTE 268
#define TK_IGUAL 269
#define TK_E_LOGICO 270
#define TK_OU_LOGICO 271
#define TK_NEGACAO 272
#define TK_IF 273
#define TK_ELSE 274
#define TK_WHILE 275
#define TK_DO 276
#define TK_FOR 277
#define TK_IN 278
#define TK_SWITCH 279
#define TK_CASE 280
#define TK_BREAK 281
#define TK_DEFAULT 282
#define TK_CONTINUE 283
#define TK_INCREMENTO 284
#define TK_DECREMENTO 285
#define TK_MAIS_IGUAL 286
#define TK_MENOS_IGUAL 287
#define TK_MULT_IGUAL 288
#define TK_DIV_IGUAL 289
#define TK_PRINT 290
#define TK_SCAN 291
#define FIM_LINHA 292

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
  YYSYMBOL_TK_RETURN = 5,                  /* TK_RETURN  */
  YYSYMBOL_TK_INT = 6,                     /* TK_INT  */
  YYSYMBOL_TK_FLOAT = 7,                   /* TK_FLOAT  */
  YYSYMBOL_TK_BOOLEAN = 8,                 /* TK_BOOLEAN  */
  YYSYMBOL_TK_CHAR = 9,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 10,                 /* TK_STRING  */
  YYSYMBOL_TK_MAIOR_IGUAL = 11,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 12,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_DIFERENTE = 13,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_IGUAL = 14,                  /* TK_IGUAL  */
  YYSYMBOL_TK_E_LOGICO = 15,               /* TK_E_LOGICO  */
  YYSYMBOL_TK_OU_LOGICO = 16,              /* TK_OU_LOGICO  */
  YYSYMBOL_TK_NEGACAO = 17,                /* TK_NEGACAO  */
  YYSYMBOL_TK_IF = 18,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 19,                   /* TK_ELSE  */
  YYSYMBOL_TK_WHILE = 20,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 21,                     /* TK_DO  */
  YYSYMBOL_TK_FOR = 22,                    /* TK_FOR  */
  YYSYMBOL_TK_IN = 23,                     /* TK_IN  */
  YYSYMBOL_TK_SWITCH = 24,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 25,                   /* TK_CASE  */
  YYSYMBOL_TK_BREAK = 26,                  /* TK_BREAK  */
  YYSYMBOL_TK_DEFAULT = 27,                /* TK_DEFAULT  */
  YYSYMBOL_TK_CONTINUE = 28,               /* TK_CONTINUE  */
  YYSYMBOL_TK_INCREMENTO = 29,             /* TK_INCREMENTO  */
  YYSYMBOL_TK_DECREMENTO = 30,             /* TK_DECREMENTO  */
  YYSYMBOL_TK_MAIS_IGUAL = 31,             /* TK_MAIS_IGUAL  */
  YYSYMBOL_TK_MENOS_IGUAL = 32,            /* TK_MENOS_IGUAL  */
  YYSYMBOL_TK_MULT_IGUAL = 33,             /* TK_MULT_IGUAL  */
  YYSYMBOL_TK_DIV_IGUAL = 34,              /* TK_DIV_IGUAL  */
  YYSYMBOL_TK_PRINT = 35,                  /* TK_PRINT  */
  YYSYMBOL_TK_SCAN = 36,                   /* TK_SCAN  */
  YYSYMBOL_FIM_LINHA = 37,                 /* FIM_LINHA  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '+'  */
  YYSYMBOL_48_ = 48,                       /* '-'  */
  YYSYMBOL_49_ = 49,                       /* '>'  */
  YYSYMBOL_50_ = 50,                       /* '<'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_START = 54,                     /* START  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_LISTA_FUNCOES = 56,             /* LISTA_FUNCOES  */
  YYSYMBOL_FUNCAO = 57,                    /* FUNCAO  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_PARAMS = 60,                    /* PARAMS  */
  YYSYMBOL_PARAM = 61,                     /* PARAM  */
  YYSYMBOL_BLOCO = 62,                     /* BLOCO  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_CMDS = 64,                      /* CMDS  */
  YYSYMBOL_CMD = 65,                       /* CMD  */
  YYSYMBOL_66_7 = 66,                      /* $@7  */
  YYSYMBOL_67_8 = 67,                      /* $@8  */
  YYSYMBOL_68_9 = 68,                      /* $@9  */
  YYSYMBOL_FOR_INICIA = 69,                /* FOR_INICIA  */
  YYSYMBOL_FOR_INCREM = 70,                /* FOR_INCREM  */
  YYSYMBOL_DECL = 71,                      /* DECL  */
  YYSYMBOL_ATR = 72,                       /* ATR  */
  YYSYMBOL_EXP = 73,                       /* EXP  */
  YYSYMBOL_TERMO = 74,                     /* TERMO  */
  YYSYMBOL_FATOR = 75,                     /* FATOR  */
  YYSYMBOL_LISTA_ARGS = 76                 /* LISTA_ARGS  */
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
#define YYLAST   513

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      38,    39,    51,    47,    40,    48,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      50,    44,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    94,   171,   174,   176,   179,   182,   182,
     182,   206,   208,   211,   214,   266,   266,   274,   280,   285,
     286,   287,   288,   289,   290,   291,   292,   318,   339,   337,
     365,   364,   392,   410,   409,   440,   447,   454,   471,   501,
     507,   514,   515,   516,   518,   520,   523,   527,   536,   553,
     566,   580,   604,   631,   652,   673,   692,   720,   748,   789,
     825,   860,   893,   909,   925,   940,   956,   971,   986,   997,
    1008,  1016,  1047,  1078,  1086,  1106,  1123,  1148,  1176,  1198,
    1220,  1226,  1234,  1267,  1287,  1293,  1299,  1309,  1315,  1322,
    1342,  1368,  1375,  1381
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
  "TK_RETURN", "TK_INT", "TK_FLOAT", "TK_BOOLEAN", "TK_CHAR", "TK_STRING",
  "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_DIFERENTE", "TK_IGUAL",
  "TK_E_LOGICO", "TK_OU_LOGICO", "TK_NEGACAO", "TK_IF", "TK_ELSE",
  "TK_WHILE", "TK_DO", "TK_FOR", "TK_IN", "TK_SWITCH", "TK_CASE",
  "TK_BREAK", "TK_DEFAULT", "TK_CONTINUE", "TK_INCREMENTO",
  "TK_DECREMENTO", "TK_MAIS_IGUAL", "TK_MENOS_IGUAL", "TK_MULT_IGUAL",
  "TK_DIV_IGUAL", "TK_PRINT", "TK_SCAN", "FIM_LINHA", "'('", "')'", "','",
  "'{'", "'}'", "';'", "'='", "'['", "']'", "'+'", "'-'", "'>'", "'<'",
  "'*'", "'/'", "$accept", "START", "$@1", "LISTA_FUNCOES", "FUNCAO",
  "$@2", "$@3", "PARAMS", "PARAM", "BLOCO", "$@6", "CMDS", "CMD", "$@7",
  "$@8", "$@9", "FOR_INICIA", "FOR_INCREM", "DECL", "ATR", "EXP", "TERMO",
  "FATOR", "LISTA_ARGS", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -68,     6,   -68,   -68,     4,    13,   -68,   -68,   -30,    21,
      22,    -6,    24,   -68,   -68,    21,    30,   -68,   -68,   -68,
      52,   -68,    72,   468,   154,   -68,   -68,   -68,   -68,   -68,
      75,    47,    53,   -68,    54,    57,    58,    92,    93,    60,
      63,   -68,   100,   154,    95,    71,    52,    65,    81,   225,
     -47,   -68,   -25,   -68,   -68,   154,   154,   154,   154,   154,
     181,   154,   -20,   252,   -68,   154,   154,    30,    19,   -68,
     -68,   -68,   -68,   154,   115,    86,   237,   -68,    83,   -68,
     -68,   -68,   -68,   154,   154,   154,   154,   154,   154,   -68,
     154,   154,   154,   154,   154,   154,   154,   120,   446,   446,
     446,   446,   266,    94,    82,   446,     0,   154,   -68,   279,
     296,   108,   111,    91,   -68,   -68,   308,    96,   154,   -68,
     154,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -68,   -68,   446,   101,   154,   -68,   154,    -2,   325,
      30,   -68,    99,   154,   154,   102,   104,   -68,   337,   105,
     -68,   348,   154,   154,   112,   130,    30,   154,   354,   366,
     -68,   -68,   116,   160,   209,   446,   377,   154,    30,   -68,
     406,    39,   197,   -68,   121,   154,   124,   417,   -68,   132,
     154,   131,   -68,   446,   -68,   423,   154,   -68,   -68,   435,
     -68,    16,   446,   124,    30,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     7,     1,     3,     0,     6,     5,     0,    13,
       0,     0,    12,    14,     8,    13,     0,    11,    15,     9,
      18,    10,     0,    82,     0,    84,    85,    86,    87,    88,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,    18,    20,    22,    24,
      70,    73,    47,    77,    79,     0,     0,     0,     0,    93,
       0,     0,    82,    40,    83,     0,     0,     0,    43,    35,
      36,    76,    78,     0,     0,     0,     0,    75,     0,    16,
      17,    21,    23,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,    55,    92,     0,    82,    51,     0,     0,    39,     0,
       0,     0,     0,     0,    41,    42,     0,     0,     0,    80,
       0,    64,    65,    66,    67,    68,    69,    60,    61,    62,
      63,    71,    72,    48,     0,    93,    74,     0,    89,     0,
       0,    28,     0,     0,     0,     0,     0,    81,     0,    50,
      91,     0,     0,     0,    89,    26,     0,     0,     0,     0,
      37,    38,     0,     0,    59,    56,     0,     0,     0,    29,
       0,     0,    46,    32,     0,     0,    90,     0,    27,     0,
       0,     0,    44,    45,    49,     0,     0,    90,    31,     0,
      33,    58,    57,     0,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   171,   -68,   -16,
     -68,   147,   -68,   -68,   -68,   -68,   -68,   -68,   126,   -67,
     -21,    89,   -41,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     7,    16,    21,    11,    12,    44,
      20,    45,    46,   156,    67,   194,   113,   181,    47,    48,
      49,    50,    51,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,   115,    77,    63,    94,    95,     3,     5,     9,    53,
      54,    83,    84,    85,    86,    87,    88,     8,    59,    96,
      97,    76,    22,   112,    10,   107,    13,   -90,   -90,   -90,
     -90,   -90,   -90,    14,    98,    99,   100,   101,   102,   105,
     106,     6,   152,   153,   109,   110,   138,    90,    91,    92,
      93,   111,   116,   131,   132,    22,    23,    24,    25,    26,
      27,    28,    29,   -90,    15,   -90,   -90,   -90,   -90,    30,
      31,    18,    32,    33,    34,   133,    52,   147,    35,    64,
      36,    37,    38,   152,   180,    65,   139,    39,    40,    41,
      42,    66,    68,    18,    69,    70,    71,    72,    73,   148,
      43,    74,    81,    75,    62,   182,    25,    26,    27,    28,
      29,    53,    54,    79,   102,    78,   151,    30,    82,   117,
      59,   120,   158,   159,   155,   118,   134,   137,   142,    37,
      38,   165,   166,   136,   144,   146,   170,   157,    42,   160,
     169,   161,    55,    56,    57,    58,   177,   149,    43,   168,
     163,   183,   178,   173,   185,    60,   143,   167,    62,   189,
      25,    26,    27,    28,    29,   192,   174,   184,   186,   188,
     190,    30,   121,   122,   123,   124,   125,   126,   195,   127,
     128,   129,   130,    37,    38,   104,    17,    25,    26,    27,
      28,    29,    42,    80,   114,     0,   150,     0,    30,     0,
       0,    23,    43,    25,    26,    27,    28,    29,     0,     0,
      37,    38,     0,     0,    30,     0,     0,     0,     0,    42,
     -89,   -89,   -89,   -89,   -89,   -89,    37,    38,     0,    43,
       0,     0,     0,     0,     0,    42,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    43,     0,     0,    83,    84,
      85,    86,    87,    88,   175,     0,   -89,     0,   -89,   -89,
     -89,   -89,    89,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    90,    91,    92,    93,   119,    83,    84,    85,
      86,    87,    88,     0,    90,    91,    92,    93,     0,   108,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    90,
      91,    92,    93,     0,     0,     0,   135,    83,    84,    85,
      86,    87,    88,    90,    91,    92,    93,     0,   140,    83,
      84,    85,    86,    87,    88,     0,    90,    91,    92,    93,
       0,     0,     0,     0,     0,   141,    83,    84,    85,    86,
      87,    88,     0,    90,    91,    92,    93,   145,    83,    84,
      85,    86,    87,    88,     0,    90,    91,    92,    93,    83,
      84,    85,    86,    87,    88,    83,    84,    85,    86,    87,
      88,   154,    90,    91,    92,    93,   162,    83,    84,    85,
      86,    87,    88,     0,    90,    91,    92,    93,    83,    84,
      85,    86,    87,    88,   164,    90,    91,    92,    93,     0,
     171,    90,    91,    92,    93,     0,     0,     0,     0,   172,
       0,     0,     0,    90,    91,    92,    93,    83,    84,    85,
      86,    87,    88,   176,    90,    91,    92,    93,    83,    84,
      85,    86,    87,    88,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,   179,    83,    84,    85,    86,
      87,    88,     0,    90,    91,    92,    93,    83,    84,    85,
      86,    87,    88,   187,    90,    91,    92,    93,     0,   191,
      90,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,   193,    90,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    53,    54,    55,
      56,    57,    58,     0,     0,     0,    59,     0,     0,     0,
       0,     0,    60,    61
};

static const yytype_int16 yycheck[] =
{
      16,    68,    43,    24,    51,    52,     0,     3,    38,    29,
      30,    11,    12,    13,    14,    15,    16,     4,    38,    44,
      45,    42,     3,     4,     3,    45,     4,    11,    12,    13,
      14,    15,    16,    39,    55,    56,    57,    58,    59,    60,
      61,    37,    44,    45,    65,    66,    46,    47,    48,    49,
      50,    67,    73,    94,    95,     3,     4,     5,     6,     7,
       8,     9,    10,    47,    40,    49,    50,    51,    52,    17,
      18,    41,    20,    21,    22,    96,     4,   118,    26,     4,
      28,    29,    30,    44,    45,    38,   107,    35,    36,    37,
      38,    38,    38,    41,    37,    37,     4,     4,    38,   120,
      48,    38,    37,     3,     4,   172,     6,     7,     8,     9,
      10,    29,    30,    42,   135,    20,   137,    17,    37,     4,
      38,    38,   143,   144,   140,    39,     6,    45,    20,    29,
      30,   152,   153,    39,    43,    39,   157,    38,    38,    37,
     156,    37,    31,    32,    33,    34,   167,    46,    48,    19,
      45,   172,   168,    37,   175,    44,    45,    45,     4,   180,
       6,     7,     8,     9,    10,   186,     6,    46,    44,    37,
      39,    17,    83,    84,    85,    86,    87,    88,   194,    90,
      91,    92,    93,    29,    30,     4,    15,     6,     7,     8,
       9,    10,    38,    46,    68,    -1,   135,    -1,    17,    -1,
      -1,     4,    48,     6,     7,     8,     9,    10,    -1,    -1,
      29,    30,    -1,    -1,    17,    -1,    -1,    -1,    -1,    38,
      11,    12,    13,    14,    15,    16,    29,    30,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    38,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    48,    -1,    -1,    11,    12,
      13,    14,    15,    16,    45,    -1,    47,    -1,    49,    50,
      51,    52,    37,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    47,    48,    49,    50,    39,    11,    12,    13,
      14,    15,    16,    -1,    47,    48,    49,    50,    -1,    37,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    47,
      48,    49,    50,    -1,    -1,    -1,    40,    11,    12,    13,
      14,    15,    16,    47,    48,    49,    50,    -1,    39,    11,
      12,    13,    14,    15,    16,    -1,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    39,    11,    12,    13,    14,
      15,    16,    -1,    47,    48,    49,    50,    39,    11,    12,
      13,    14,    15,    16,    -1,    47,    48,    49,    50,    11,
      12,    13,    14,    15,    16,    11,    12,    13,    14,    15,
      16,    46,    47,    48,    49,    50,    39,    11,    12,    13,
      14,    15,    16,    -1,    47,    48,    49,    50,    11,    12,
      13,    14,    15,    16,    46,    47,    48,    49,    50,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,    48,    49,    50,    11,    12,    13,
      14,    15,    16,    46,    47,    48,    49,    50,    11,    12,
      13,    14,    15,    16,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    39,    11,    12,    13,    14,
      15,    16,    -1,    47,    48,    49,    50,    11,    12,    13,
      14,    15,    16,    46,    47,    48,    49,    50,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,    55,     0,    56,     3,    37,    57,     4,    38,
       3,    60,    61,     4,    39,    40,    58,    60,    41,    62,
      63,    59,     3,     4,     5,     6,     7,     8,     9,    10,
      17,    18,    20,    21,    22,    26,    28,    29,    30,    35,
      36,    37,    38,    48,    62,    64,    65,    71,    72,    73,
      74,    75,     4,    29,    30,    31,    32,    33,    34,    38,
      44,    45,     4,    73,     4,    38,    38,    67,    38,    37,
      37,     4,     4,    38,    38,     3,    73,    75,    20,    42,
      64,    37,    37,    11,    12,    13,    14,    15,    16,    37,
      47,    48,    49,    50,    51,    52,    44,    45,    73,    73,
      73,    73,    73,    76,     4,    73,    73,    45,    37,    73,
      73,    62,     4,    69,    71,    72,    73,     4,    39,    39,
      38,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    73,     6,    40,    39,    45,    46,    73,
      39,    39,    20,    45,    43,    39,    39,    75,    73,    46,
      76,    73,    44,    45,    46,    62,    66,    38,    73,    73,
      37,    37,    39,    45,    46,    73,    73,    45,    19,    62,
      73,    46,    43,    37,     6,    45,    46,    73,    62,    39,
      45,    70,    72,    73,    46,    73,    44,    46,    37,    73,
      39,    46,    73,    46,    68,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    55,    54,    54,    56,    56,    56,    58,    59,
      57,    60,    60,    60,    61,    63,    62,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    65,
      67,    65,    65,    68,    65,    65,    65,    65,    65,    65,
      65,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     0,     0,
       8,     3,     1,     0,     2,     0,     4,     2,     0,     2,
       1,     2,     1,     2,     1,     1,     5,     7,     0,     6,
       0,     8,     6,     0,    10,     2,     2,     5,     5,     3,
       2,     1,     1,     0,     1,     1,     0,     2,     4,     8,
       5,     3,     3,     3,     3,     3,     6,     9,     9,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     4,     2,     2,     2,     2,     2,
       3,     4,     1,     2,     1,     1,     1,     1,     1,     4,
       7,     3,     1,     0
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
#line 94 "sintatica.y"
      { entraEscopo(); }
#line 1518 "y.tab.c"
    break;

  case 3: /* START: $@1 LISTA_FUNCOES  */
#line 95 "sintatica.y"
    {
        if(debug) cout << "[DEBUG] Árvore completa gerada. Tradução:\n";

        string defines = "\n\t#define true 1\n\t#define false 0\n\n\n";
        string declaracoes = "";

        string funcao_meu_strlen = "int meu_strlen(char* v0) {\n"
            "\tint v1;\n"
            "\tint t1;\n\tint t2;\n\tint t3;\n\tint t4;\n\tint t5;\n\tint t7;\n\tint t8;\n\tint t9;\n\tint t10;\n\tint t11;\n"
            "\tchar t6;\n\n"
            "\tt1 = (v0 == NULL);\n"
            "\tt2 = !t1;\n"
            "\tif (t2) goto R0;\n\n"
            "\tt3 = 0;\n"
            "\treturn t3;\n\n"
            "R0:\n"
            "\tt4 = 0;\n"
            "\tv1 = t4;\n\n"
            "R1:\n"
            "\tt5 = v1;\n"
            "\tt6 = v0[t5];\n"
            "\tt7 = (t6 != '\\0');\n"
            "\tt8 = !t7;\n"
            "\tif (t8) goto R2;\n\n"
            "\tt9 = v1;\n"
            "\tt10 = t9 + 1;\n"
            "\tv1 = t10;\n"
            "\tgoto R1;\n\n"
            "R2:\n"
            "\tt11 = v1;\n"
            "\treturn t11;\n"
            "}\n\n";

        for (auto i : temporarias) {
            string label = i.first;
            string tipo = i.second;

            bool declarada = false;

            if (!pilhaTabelasSimbolos.empty()) {
                for (const auto& par : pilhaTabelasSimbolos.back()) {
                    const TIPO_SIMBOLO& simbolo = par.second;

                    if (simbolo.label == label) {
                        // Encontrou variável fixa associada
                        if (simbolo.isArray) {
                            int tamanho = simbolo.getTamanhoTotal();

                            if (simbolo.tipoVariavel == "string" || simbolo.tipoVariavel == "char_array") {
                                declaracoes += "\tchar " + simbolo.label + "[" + to_string(tamanho) + "];\n";
                            } else {
                                declaracoes += "\t" + simbolo.tipoVariavel + " " + simbolo.label + "[" + to_string(tamanho) + "];\n";
                            }
                        } else {
                            if (simbolo.tipoVariavel == "string" || simbolo.tipoVariavel == "char_array")
                                declaracoes += "\tchar* " + simbolo.label + ";\n";
                            else
                                declaracoes += "\t" + simbolo.tipoVariavel + " " + simbolo.label + ";\n";
                        }

                        declarada = true;
                        break;
                    }
                }
            }

            if (!declarada) {
                if (tipo == "string" || tipo == "char_array")
                    declaracoes += "\tchar* " + label + ";\n";
                else
                    declaracoes += "\t" + tipo + " " + label + ";\n";
            }
        }

        cout << defines << funcao_meu_strlen << declaracoes << "\n" << yyvsp[0].traducao << endl;
        saiEscopo();
    }
#line 1600 "y.tab.c"
    break;

  case 5: /* LISTA_FUNCOES: LISTA_FUNCOES FUNCAO  */
#line 175 "sintatica.y"
        { yyval.traducao = yyvsp[-1].traducao + "\n" + yyvsp[0].traducao; }
#line 1606 "y.tab.c"
    break;

  case 6: /* LISTA_FUNCOES: LISTA_FUNCOES FIM_LINHA  */
#line 177 "sintatica.y"
        { yyval = yyvsp[-1]; }
#line 1612 "y.tab.c"
    break;

  case 7: /* LISTA_FUNCOES: %empty  */
#line 179 "sintatica.y"
        { yyval.traducao = ""; }
#line 1618 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 182 "sintatica.y"
                                   { entraEscopo(); }
#line 1624 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 182 "sintatica.y"
                                                            { saiEscopo(); }
#line 1630 "y.tab.c"
    break;

  case 10: /* FUNCAO: TK_TIPO TK_ID '(' PARAMS ')' $@2 BLOCO $@3  */
#line 183 "sintatica.y"
    {
        string tipoRetorno = pegaTipo(yyvsp[-7].label);
        string nome = yyvsp[-6].label;

        if (nome == "principal")
            nome = "main"; // traduz principal() → main()
        // -----  👇 CÓDIGO NOVO AQUI 👇 -----
        if (tabelaFuncoes.count(nome)) {
            yyerror("Função '" + nome + "' já foi declarada.");
        } else {
            TIPO_FUNCAO infoFunc;
            infoFunc.tipoRetorno = tipoRetorno;
            // OBS: A regra PARAMS precisaria ser modificada para
            // preencher os tipos dos parâmetros. Por enquanto, deixaremos vazio.
            tabelaFuncoes[nome] = infoFunc;
            if(debug) cout << "[DEBUG] Função '" << nome << "' inserida na tabela de funções.\n";
        }
        // -----  fim do código novo -----

        yyval.traducao = tipoRetorno + " " + nome + "(" + yyvsp[-4].traducao + ") {\n" + yyvsp[-1].traducao + "}\n";
    }
#line 1656 "y.tab.c"
    break;

  case 11: /* PARAMS: PARAM ',' PARAMS  */
#line 207 "sintatica.y"
        { yyval.traducao = yyvsp[-2].traducao + ", " + yyvsp[0].traducao; }
#line 1662 "y.tab.c"
    break;

  case 12: /* PARAMS: PARAM  */
#line 209 "sintatica.y"
        { yyval.traducao = yyvsp[0].traducao; }
#line 1668 "y.tab.c"
    break;

  case 13: /* PARAMS: %empty  */
#line 211 "sintatica.y"
        { yyval.traducao = ""; }
#line 1674 "y.tab.c"
    break;

  case 14: /* PARAM: TK_TIPO TK_ID  */
#line 215 "sintatica.y"
    {
        string tipo = pegaTipo(yyvsp[-1].label);
        // Agora passamos 'true' para o último argumento, marcando como parâmetro
        insereFixasTabelaSimbolos(yyvsp[0].label, yyvsp[-1].label, false, 0, 0, true); 

        yyval.traducao = tipo + " " + yyvsp[0].label;
    }
#line 1686 "y.tab.c"
    break;

  case 15: /* $@6: %empty  */
#line 266 "sintatica.y"
                  { entraEscopo(); }
#line 1692 "y.tab.c"
    break;

  case 16: /* BLOCO: '{' $@6 CMDS '}'  */
#line 267 "sintatica.y"
            {   
                printTabelaSimbolos();
                yyval.traducao = yyvsp[-1].traducao;
                saiEscopo();
            }
#line 1702 "y.tab.c"
    break;

  case 17: /* CMDS: CMD CMDS  */
#line 275 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
                if(debug) cout << "[DEBUG] Comando processado. Acumulado:\n" << yyvsp[-1].traducao;
            }
#line 1711 "y.tab.c"
    break;

  case 18: /* CMDS: %empty  */
#line 280 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1719 "y.tab.c"
    break;

  case 19: /* CMD: EXP FIM_LINHA  */
#line 285 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1725 "y.tab.c"
    break;

  case 20: /* CMD: DECL  */
#line 286 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1731 "y.tab.c"
    break;

  case 21: /* CMD: DECL FIM_LINHA  */
#line 287 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1737 "y.tab.c"
    break;

  case 22: /* CMD: ATR  */
#line 288 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1743 "y.tab.c"
    break;

  case 23: /* CMD: ATR FIM_LINHA  */
#line 289 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1749 "y.tab.c"
    break;

  case 24: /* CMD: EXP  */
#line 290 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1755 "y.tab.c"
    break;

  case 25: /* CMD: FIM_LINHA  */
#line 291 "sintatica.y"
                             { yyval.traducao = "";          }
#line 1761 "y.tab.c"
    break;

  case 26: /* CMD: TK_IF '(' EXP ')' BLOCO  */
#line 293 "sintatica.y"
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
#line 1791 "y.tab.c"
    break;

  case 27: /* CMD: TK_IF '(' EXP ')' BLOCO TK_ELSE BLOCO  */
#line 319 "sintatica.y"
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
#line 1814 "y.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 339 "sintatica.y"
            {
                string rotuloTeste = novo_rotulo();
                string rotuloFimWhile = novo_rotulo();

                pilhaRotulosProxIteracao.push(rotuloTeste);
                pilhaRotulosFimLoop.push(rotuloFimWhile); 

            }
#line 1827 "y.tab.c"
    break;

  case 29: /* CMD: TK_WHILE '(' EXP ')' $@7 BLOCO  */
#line 348 "sintatica.y"
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
#line 1848 "y.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 365 "sintatica.y"
              {
                  // Rótulos que serão o destino do break e continue
                  string rotuloTeste = novo_rotulo();         // Destino do continue
                  string rotuloFimDoWhile = novo_rotulo();    // Destino do break

                  pilhaRotulosProxIteracao.push(rotuloTeste);
                  pilhaRotulosFimLoop.push(rotuloFimDoWhile);
              }
#line 1861 "y.tab.c"
    break;

  case 31: /* CMD: TK_DO $@8 BLOCO TK_WHILE '(' EXP ')' FIM_LINHA  */
#line 374 "sintatica.y"
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
#line 1884 "y.tab.c"
    break;

  case 32: /* CMD: BLOCO TK_WHILE '(' EXP ')' FIM_LINHA  */
#line 393 "sintatica.y"
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
#line 1905 "y.tab.c"
    break;

  case 33: /* $@9: %empty  */
#line 410 "sintatica.y"
            {
                  string rotuloIncremento = novo_rotulo();
                  string rotuloFimFor = novo_rotulo();

                  pilhaRotulosProxIteracao.push(rotuloIncremento);
                  pilhaRotulosFimLoop.push(rotuloFimFor);

            }
#line 1918 "y.tab.c"
    break;

  case 34: /* CMD: TK_FOR '(' FOR_INICIA ';' EXP ';' FOR_INCREM ')' $@9 BLOCO  */
#line 419 "sintatica.y"
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
#line 1944 "y.tab.c"
    break;

  case 35: /* CMD: TK_BREAK FIM_LINHA  */
#line 441 "sintatica.y"
            {
                if (pilhaRotulosFimLoop.empty()) {
                    yyerror("Erro semântico: 'pare' (break) fora de um laço.");
                }
                yyval.traducao = "\tgoto " + pilhaRotulosFimLoop.top() + ";\n";
            }
#line 1955 "y.tab.c"
    break;

  case 36: /* CMD: TK_CONTINUE FIM_LINHA  */
#line 448 "sintatica.y"
            {
                if (pilhaRotulosProxIteracao.empty()) {
                    yyerror("Erro semântico: 'passa' (continue) fora de um laço.");
                }
                yyval.traducao = "\tgoto " + pilhaRotulosProxIteracao.top() + ";\n";
            }
#line 1966 "y.tab.c"
    break;

  case 37: /* CMD: TK_PRINT '(' EXP ')' FIM_LINHA  */
#line 455 "sintatica.y"
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
#line 1987 "y.tab.c"
    break;

  case 38: /* CMD: TK_SCAN '(' TK_ID ')' FIM_LINHA  */
#line 472 "sintatica.y"
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
#line 2021 "y.tab.c"
    break;

  case 39: /* CMD: TK_RETURN EXP FIM_LINHA  */
#line 502 "sintatica.y"
            {
                // A tradução da expressão (ex: a + b) já vem em $2.traducao
                // O resultado final da expressão está em $2.label
                yyval.traducao = yyvsp[-1].traducao + "\treturn " + yyvsp[-1].label + ";\n";
            }
#line 2031 "y.tab.c"
    break;

  case 40: /* CMD: TK_RETURN EXP  */
#line 508 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao + "\treturn " + yyvsp[0].label + ";\n";
            }
#line 2039 "y.tab.c"
    break;

  case 41: /* FOR_INICIA: DECL  */
#line 514 "sintatica.y"
                   { yyval.traducao = yyvsp[0].traducao; }
#line 2045 "y.tab.c"
    break;

  case 42: /* FOR_INICIA: ATR  */
#line 515 "sintatica.y"
                  { yyval.traducao = yyvsp[0].traducao; }
#line 2051 "y.tab.c"
    break;

  case 43: /* FOR_INICIA: %empty  */
#line 516 "sintatica.y"
              { yyval.traducao = ""; }
#line 2057 "y.tab.c"
    break;

  case 44: /* FOR_INCREM: ATR  */
#line 519 "sintatica.y"
            { yyval.traducao = yyvsp[0].traducao; }
#line 2063 "y.tab.c"
    break;

  case 45: /* FOR_INCREM: EXP  */
#line 521 "sintatica.y"
            { yyval.traducao = yyvsp[0].traducao; }
#line 2069 "y.tab.c"
    break;

  case 46: /* FOR_INCREM: %empty  */
#line 523 "sintatica.y"
            { yyval.traducao = ""; }
#line 2075 "y.tab.c"
    break;

  case 47: /* DECL: TK_TIPO TK_ID  */
#line 528 "sintatica.y"
            {
               if(yyvsp[-1].label == "falada") {
            insereFixasTabelaSimbolos(yyvsp[0].label, "string");  // registra tipo string na tabela
        } else {
            insereFixasTabelaSimbolos(yyvsp[0].label, yyvsp[-1].label);
        }
        yyval.traducao = ""; // declaração será feita no final no start
            }
#line 2088 "y.tab.c"
    break;

  case 48: /* DECL: TK_TIPO TK_ID '=' EXP  */
#line 537 "sintatica.y"
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
#line 2109 "y.tab.c"
    break;

  case 49: /* DECL: TK_TIPO TK_ID '[' TK_INT ']' '[' TK_INT ']'  */
#line 554 "sintatica.y"
    {
        string tipo = pegaTipo(yyvsp[-7].label);
        int tamanho1 = stoi(yyvsp[-4].label);
        int tamanho2 = stoi(yyvsp[-1].label);

        if (tipo == "string" || yyvsp[-7].label == "falada") {
            insereFixasTabelaSimbolos(yyvsp[-6].label, "string", true, tamanho1, tamanho2);
        } else {
            insereFixasTabelaSimbolos(yyvsp[-6].label, yyvsp[-7].label, true, tamanho1, tamanho2);
        }
        yyval.traducao = "";
    }
#line 2126 "y.tab.c"
    break;

  case 50: /* DECL: TK_TIPO TK_ID '[' TK_INT ']'  */
#line 567 "sintatica.y"
    {
        string tipo = pegaTipo(yyvsp[-4].label);
        int tamanho = stoi(yyvsp[-1].label);

        if (tipo == "string" || yyvsp[-4].label == "falada") {
            insereFixasTabelaSimbolos(yyvsp[-3].label, "string", true, tamanho);
        } else {
            insereFixasTabelaSimbolos(yyvsp[-3].label, yyvsp[-4].label, true, tamanho);
        }
        yyval.traducao = "";
    }
#line 2142 "y.tab.c"
    break;

  case 51: /* ATR: TK_ID '=' EXP  */
#line 581 "sintatica.y"
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
#line 2170 "y.tab.c"
    break;

  case 52: /* ATR: TK_ID TK_MAIS_IGUAL EXP  */
#line 605 "sintatica.y"
            {
               TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
    
                // Checagem de tipo
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, yyvsp[0].tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") {
                    yyerror("Erro de tipo em '+=': Nao e possivel atribuir um " + tipoResultado + " a um " + varEsquerda.tipoVariavel);
                }

                // Criação das temporárias
                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);

                stringstream ss;
                // Primeiro, inclui o código da expressão da direita, se houver
                ss << yyvsp[0].traducao;
                // Agora, os passos detalhados
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";              // temp_valor_esq = x;
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " + " << yyvsp[0].label << ";\n"; // temp_resultado = temp_valor_esq + y;
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";                // x = temp_resultado;

                yyval.traducao = ss.str();
                yyval.label = varEsquerda.label;
                yyval.tipo = varEsquerda.tipoVariavel;
            }
#line 2200 "y.tab.c"
    break;

  case 53: /* ATR: TK_ID TK_MENOS_IGUAL EXP  */
#line 632 "sintatica.y"
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, yyvsp[0].tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") { yyerror("Erro de tipo em '-='."); }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);

                stringstream ss;
                ss << yyvsp[0].traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " - " << yyvsp[0].label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";

                yyval.traducao = ss.str();
                yyval.label = varEsquerda.label;
                yyval.tipo = varEsquerda.tipoVariavel;
            }
#line 2223 "y.tab.c"
    break;

  case 54: /* ATR: TK_ID TK_MULT_IGUAL EXP  */
#line 653 "sintatica.y"
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, yyvsp[0].tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") { yyerror("Erro de tipo em '*='."); }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);

                stringstream ss;
                ss << yyvsp[0].traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " * " << yyvsp[0].label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";

                yyval.traducao = ss.str();
                yyval.label = varEsquerda.label;
                yyval.tipo = varEsquerda.tipoVariavel;
            }
#line 2246 "y.tab.c"
    break;

  case 55: /* ATR: TK_ID TK_DIV_IGUAL EXP  */
#line 674 "sintatica.y"
        {
            TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
            string tipoResultado = infereTipo(varEsquerda.tipoVariavel, yyvsp[0].tipo);
            if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") { yyerror("Erro de tipo em '/='."); }

            string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
            string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);

            stringstream ss;
            ss << yyvsp[0].traducao;
            ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
            ss << "\t" << temp_resultado << " = " << temp_valor_esq << " / " << yyvsp[0].label << ";\n";
            ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";

            yyval.traducao = ss.str();
            yyval.label = varEsquerda.label;
            yyval.tipo = varEsquerda.tipoVariavel;
        }
#line 2269 "y.tab.c"
    break;

  case 56: /* ATR: TK_ID '[' EXP ']' '=' EXP  */
#line 693 "sintatica.y"
    {
        // 1) Verifica se variável existe
        if (!verificaTabelaSimbolos(yyvsp[-5].label))
            yyerror("Variável '" + yyvsp[-5].label + "' não declarada para atribuição em índice.");

        // 2) Recupera símbolo
        TIPO_SIMBOLO temp = pegaVariavelTabelaSimbolos(yyvsp[-5].label);

        // 3) Verifica se é realmente um vetor
        if (!temp.isArray)
            yyerror("Variável '" + yyvsp[-5].label + "' não é um vetor.");

        // 4) O índice deve ser inteiro
        if (yyvsp[-3].tipo != "int")
            yyerror("Índice de vetor deve ser inteiro: tipo recebido '" + yyvsp[-3].tipo + "'.");

        // 5) Verifica compatibilidade de tipos no RHS
        if (temp.tipoVariavel != pegaTipo(yyvsp[0].tipo))
            yyerror("Tipo incompatível ao atribuir em vetor '" + yyvsp[-5].label + "'.");

        // 6) Monta o acesso e a tradução
        yyval.label = temp.label;                     // o próprio vetor
        yyval.traducao = yyvsp[-3].traducao    // tradução da expressão de índice
                    + yyvsp[0].traducao    // tradução do RHS
                    + "\t" + temp.label 
                    + "[" + yyvsp[-3].label + "] = " + yyvsp[0].label + ";\n";
    }
#line 2301 "y.tab.c"
    break;

  case 57: /* ATR: TK_ID '[' EXP ']' '[' EXP ']' '=' EXP  */
#line 721 "sintatica.y"
    {
    if (!verificaTabelaSimbolos(yyvsp[-8].label))
        yyerror("Matriz não declarada: " + yyvsp[-8].label);

    TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos(yyvsp[-8].label);

    if (!mat.isArray || mat.arraySize2 == 0)
        yyerror("'" + yyvsp[-8].label + "' não é matriz 2D.");

    if (yyvsp[-6].tipo != "int" || yyvsp[-3].tipo != "int")
        yyerror("Índices de matriz devem ser inteiros.");

    if (mat.tipoVariavel != pegaTipo(yyvsp[0].tipo))
        yyerror("Tipo incompatível ao atribuir em matriz '" + yyvsp[-8].label + "'.");

    // Cria temporárias para calcular índice linearizado
    string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
    string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");

    yyval.traducao  = yyvsp[-6].traducao               // código de i
                 + yyvsp[-3].traducao               // código de j
                 + "\t" + tempMult + " = " + yyvsp[-6].label + " * " + to_string(mat.arraySize2) + ";\n"
                 + "\t" + tempIdx  + " = " + tempMult + " + " + yyvsp[-3].label + ";\n"
                 + yyvsp[0].traducao               // código do valor
                 + "\t" + mat.label + "[" + tempIdx + "] = " + yyvsp[0].label + ";\n";

    }
#line 2333 "y.tab.c"
    break;

  case 58: /* ATR: TK_ID '=' TK_ID '[' EXP ']' '[' EXP ']'  */
#line 749 "sintatica.y"
        {
        // 1) Verifica se a matriz existe
        if (!verificaTabelaSimbolos(yyvsp[-6].label))
            yyerror("Matriz não declarada: " + yyvsp[-6].label);

        // 2) Recupera o símbolo
        TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos(yyvsp[-6].label);

        // 3) Verifica se é uma matriz 2D
        if (!mat.isArray || mat.arraySize2 == 0)
            yyerror("'" + yyvsp[-6].label + "' não é matriz 2D.");

        // 4) Verifica se o lado esquerdo existe e é variável atribuível
        if (!verificaTabelaSimbolos(yyvsp[-8].label))
            yyerror("Variável '" + yyvsp[-8].label + "' não declarada.");

        TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos(yyvsp[-8].label);

        // 5) Tipos compatíveis?
        if (destino.tipoVariavel != mat.tipoVariavel)
            yyerror("Tipos incompatíveis entre '" + yyvsp[-8].label + "' e matriz '" + yyvsp[-6].label + "'.");

        // 6) Índices devem ser inteiros
        if (yyvsp[-4].tipo != "int" || yyvsp[-1].tipo != "int")
            yyerror("Índices da matriz devem ser inteiros.");

        // 7) Gerar temporários
        string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
        string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");

        // 8) Tradução
        yyval.traducao  = yyvsp[-4].traducao              // código do primeiro índice
                        + yyvsp[-1].traducao              // código do segundo índice
                        + "\t" + tempMult + " = " + yyvsp[-4].label + " * " + to_string(mat.arraySize2) + ";\n"
                        + "\t" + tempIdx  + " = " + tempMult + " + " + yyvsp[-1].label + ";\n"
                        + "\t" + destino.label + " = " + mat.label + "[" + tempIdx + "];\n";

        yyval.label = yyvsp[-8].label;
        yyval.tipo  = destino.tipoVariavel;
        }
#line 2378 "y.tab.c"
    break;

  case 59: /* ATR: TK_ID '=' TK_ID '[' EXP ']'  */
#line 790 "sintatica.y"
{
    // 1) Verifica se vetor existe
    if (!verificaTabelaSimbolos(yyvsp[-3].label))
        yyerror("Vetor não declarado: " + yyvsp[-3].label);

    // 2) Recupera símbolo do vetor
    TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos(yyvsp[-3].label);

    // 3) Verifica se é vetor 1D (array com arraySize e arraySize2 == 0)
    if (!vet.isArray || vet.arraySize2 != 0)
        yyerror("'" + yyvsp[-3].label + "' não é vetor 1D.");

    // 4) Verifica se variável destino existe
    if (!verificaTabelaSimbolos(yyvsp[-5].label))
        yyerror("Variável '" + yyvsp[-5].label + "' não declarada.");

    TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos(yyvsp[-5].label);

    // 5) Verifica compatibilidade de tipos
    if (destino.tipoVariavel != vet.tipoVariavel)
        yyerror("Tipos incompatíveis entre '" + yyvsp[-5].label + "' e vetor '" + yyvsp[-3].label + "'.");

    // 6) Índice deve ser inteiro
    if (yyvsp[-1].tipo != "int")
        yyerror("Índice do vetor deve ser inteiro.");

    // 7) Cria tradução
    yyval.traducao  = yyvsp[-1].traducao                   // código do índice
                 + "\t" + yyvsp[-5].label + " = " + vet.label + "[" + yyvsp[-1].label + "];\n";

    yyval.label = destino.label;
    yyval.tipo  = destino.tipoVariavel;
}
#line 2416 "y.tab.c"
    break;

  case 60: /* EXP: EXP '+' TERMO  */
#line 826 "sintatica.y"
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
#line 2455 "y.tab.c"
    break;

  case 61: /* EXP: EXP '-' TERMO  */
#line 861 "sintatica.y"
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
#line 2492 "y.tab.c"
    break;

  case 62: /* EXP: EXP '>' TERMO  */
#line 894 "sintatica.y"
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
#line 2512 "y.tab.c"
    break;

  case 63: /* EXP: EXP '<' TERMO  */
#line 910 "sintatica.y"
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
#line 2532 "y.tab.c"
    break;

  case 64: /* EXP: EXP TK_MAIOR_IGUAL TERMO  */
#line 926 "sintatica.y"
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
#line 2551 "y.tab.c"
    break;

  case 65: /* EXP: EXP TK_MENOR_IGUAL TERMO  */
#line 941 "sintatica.y"
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
#line 2571 "y.tab.c"
    break;

  case 66: /* EXP: EXP TK_DIFERENTE TERMO  */
#line 957 "sintatica.y"
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
#line 2590 "y.tab.c"
    break;

  case 67: /* EXP: EXP TK_IGUAL TERMO  */
#line 972 "sintatica.y"
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
#line 2609 "y.tab.c"
    break;

  case 68: /* EXP: EXP TK_E_LOGICO TERMO  */
#line 987 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
                    yyerror("Operandos inválidos\n");

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";  
            }
#line 2624 "y.tab.c"
    break;

  case 69: /* EXP: EXP TK_OU_LOGICO TERMO  */
#line 998 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
                    yyerror("Operandos inválidos\n");

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao +
                "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";  
            }
#line 2639 "y.tab.c"
    break;

  case 70: /* EXP: TERMO  */
#line 1009 "sintatica.y"
            { 
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao;
                yyval.tipo = yyvsp[0].tipo;        
            }
#line 2649 "y.tab.c"
    break;

  case 71: /* TERMO: TERMO '*' FATOR  */
#line 1017 "sintatica.y"
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
#line 2684 "y.tab.c"
    break;

  case 72: /* TERMO: TERMO '/' FATOR  */
#line 1048 "sintatica.y"
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
#line 2719 "y.tab.c"
    break;

  case 73: /* TERMO: FATOR  */
#line 1079 "sintatica.y"
            { 
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao; 
                yyval.tipo = yyvsp[0].tipo;
            }
#line 2729 "y.tab.c"
    break;

  case 74: /* FATOR: TK_ID '(' LISTA_ARGS ')'  */
#line 1087 "sintatica.y"
        {
            string nomeFunc = yyvsp[-3].label;
            
            // -----  👇 LÓGICA MODIFICADA AQUI 👇 -----

            // 1. Verifica se a função existe na tabela de funções
            if (!tabelaFuncoes.count(nomeFunc)) {
                yyerror("Função '" + nomeFunc + "' não foi declarada.");
            }

            // 2. Pega as informações da função (especialmente o tipo de retorno)
            TIPO_FUNCAO infoFunc = tabelaFuncoes[nomeFunc];
            string tipoRetorno = infoFunc.tipoRetorno;
            
            // 3. Gera um temporário para receber o valor retornado
            yyval.label = insereTemporariasTabelaSimbolos("", tipoRetorno);
            yyval.tipo = tipoRetorno;
            yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + nomeFunc + "(" + yyvsp[-1].label + ");\n";
        }
#line 2753 "y.tab.c"
    break;

  case 75: /* FATOR: '-' FATOR  */
#line 1107 "sintatica.y"
            {
                // Checagem de tipo: O operador '-' unário só se aplica a números.
                if (yyvsp[0].tipo != "int" && yyvsp[0].tipo != "float") {
                    yyerror("Operador '-' unario so pode ser aplicado a tipos numericos (int, float).");
                }
                
                // O tipo do resultado é o mesmo do operando.
                yyval.tipo = yyvsp[0].tipo; 
                // Criamos uma nova variável temporária para guardar o resultado.
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                
                // A tradução inclui o código do operando ($2.traducao)
                // seguido pela instrução de negação.
                yyval.traducao = yyvsp[0].traducao + 
                            "\t" + yyval.label + " = -" + yyvsp[0].label + ";\n";
            }
#line 2774 "y.tab.c"
    break;

  case 76: /* FATOR: TK_INCREMENTO TK_ID  */
#line 1124 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[0].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") {
                    yyerror("Operador '++' so pode ser aplicado a variaveis numericas.");
                }

                yyval.tipo = var.tipoVariavel;

                // 1. Temporária para o valor 1.
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                // 2. Temporária para o valor atual da variável.
                string temp_valor_var = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                // 3. Temporária para o resultado da soma.
                string temp_soma = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_um << " = 1;\n";                                    // temp_um = 1;
                ss << "\t" << temp_valor_var << " = " << var.label << ";\n";           // temp_valor_var = x;
                ss << "\t" << temp_soma << " = " << temp_valor_var << " + " << temp_um << ";\n"; // temp_soma = temp_valor_var + temp_um;
                ss << "\t" << var.label << " = " << temp_soma << ";\n";                // x = temp_soma;

                yyval.traducao = ss.str();
                yyval.label = var.label;
            }
#line 2803 "y.tab.c"
    break;

  case 77: /* FATOR: TK_ID TK_INCREMENTO  */
#line 1149 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[-1].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") {
                    yyerror("Operador '++' so pode ser aplicado a variaveis numericas.");
                }

                // O tipo do resultado é o tipo da variável.
                yyval.tipo = var.tipoVariavel;

                // 1. A primeira temporária (temp_retorno) recebe o valor da variável (para ser o resultado da expressão).
                string temp_retorno = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                
                // 2. A segunda temporária (temp_um) recebe o valor 1.
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                
                // 3. A terceira temporária (temp_soma) recebe o resultado da soma.
                string temp_soma = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_retorno << " = " << var.label << ";\n";              // temp_retorno = x; (Guarda o valor original)
                ss << "\t" << temp_um << " = 1;\n";                                    // temp_um = 1;
                ss << "\t" << temp_soma << " = " << temp_retorno << " + " << temp_um << ";\n"; // temp_soma = temp_retorno + temp_um;
                ss << "\t" << var.label << " = " << temp_soma << ";\n";                // x = temp_soma;

                yyval.traducao = ss.str();
                yyval.label = temp_retorno; // O resultado da expressão x++ é o valor ANTES do incremento.
            }
#line 2835 "y.tab.c"
    break;

  case 78: /* FATOR: TK_DECREMENTO TK_ID  */
#line 1177 "sintatica.y"
            {
                    TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[0].label);
                    if (var.tipoVariavel != "int" && var.tipoVariavel != "float") {
                        yyerror("Operador '--' so pode ser aplicado a variaveis numericas.");
                    }

                    yyval.tipo = var.tipoVariavel;
                    
                    string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                    string temp_valor_var = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                    string temp_sub = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                    stringstream ss;
                    ss << "\t" << temp_um << " = 1;\n";                                    // temp_um = 1;
                    ss << "\t" << temp_valor_var << " = " << var.label << ";\n";           // temp_valor_var = x;
                    ss << "\t" << temp_sub << " = " << temp_valor_var << " - " << temp_um << ";\n"; // temp_sub = temp_valor_var - temp_um;
                    ss << "\t" << var.label << " = " << temp_sub << ";\n";                // x = temp_sub;
                    
                    yyval.traducao = ss.str();
                    yyval.label = var.label; // O resultado é o novo valor.
            }
#line 2861 "y.tab.c"
    break;

  case 79: /* FATOR: TK_ID TK_DECREMENTO  */
#line 1199 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[-1].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") {
                    yyerror("Operador '--' so pode ser aplicado a variaveis numericas.");
                }

                yyval.tipo = var.tipoVariavel;

                string temp_retorno = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_sub = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_retorno << " = " << var.label << ";\n";              // temp_retorno = x;
                ss << "\t" << temp_um << " = 1;\n";                                    // temp_um = 1;
                ss << "\t" << temp_sub << " = " << temp_retorno << " - " << temp_um << ";\n"; // temp_sub = temp_retorno - temp_um;
                ss << "\t" << var.label << " = " << temp_sub << ";\n";                // x = temp_sub;

                yyval.traducao = ss.str();
                yyval.label = temp_retorno; // O resultado é o valor antigo.
            }
#line 2887 "y.tab.c"
    break;

  case 80: /* FATOR: '(' EXP ')'  */
#line 1221 "sintatica.y"
            { 
                yyval.label = yyvsp[-1].label;
                yyval.traducao = yyvsp[-1].traducao;
                yyval.tipo = yyvsp[-1].tipo;
            }
#line 2897 "y.tab.c"
    break;

  case 81: /* FATOR: '(' TK_TIPO ')' FATOR  */
#line 1227 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", yyvsp[-2].label);
                yyval.tipo = yyvsp[-2].label;

                yyval.traducao = yyvsp[0].traducao +
                "\t" + yyval.label + " = (" + yyvsp[-2].label + ") " + yyvsp[0].label + ";\n";
            }
#line 2909 "y.tab.c"
    break;

  case 82: /* FATOR: TK_ID  */
#line 1235 "sintatica.y"
            {
               // 1. Verifica se o símbolo existe na tabela antes de usá-lo.
        if (!verificaTabelaSimbolos(yyvsp[0].label)) {
            // Melhorei a mensagem de erro para ser mais específica.
            yyerror("Variável não declarada: '" + yyvsp[0].label + "'");
        }

        // 2. Se existe, pega as informações completas do símbolo.
        TIPO_SIMBOLO simbolo = pegaVariavelTabelaSimbolos(yyvsp[0].label);

        // 3. LÓGICA PRINCIPAL CORRIGIDA:
        //    Verifica o novo campo 'isParam' que adicionamos.
        if (simbolo.isParam) {
            // Se for um PARÂMETRO, o "label" que usaremos na tradução
            // será o próprio NOME LOCAL da variável (ex: 'a', 'b').
            yyval.label = simbolo.nomeVariavel;
        } else {
            // Se for uma VARIÁVEL NORMAL, usamos o LABEL GLOBAL gerado
            // (ex: 'T1', 'T2', etc.).
            yyval.label = simbolo.label;
        }

        // 4. O resto da lógica continua igual:
        //    Propaga o tipo e a tradução (que é vazia para um simples acesso).
        yyval.tipo = simbolo.tipoVariavel;
        yyval.traducao = "";

        // Sua verificação de acesso a array, que é muito boa, continua aqui.
        if (simbolo.isArray) {
            yyerror("Acesso inválido: vetor/matriz '" + simbolo.nomeVariavel + "' usado sem índice.");
        }
            }
#line 2946 "y.tab.c"
    break;

  case 83: /* FATOR: TK_NEGACAO TK_ID  */
#line 1268 "sintatica.y"
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
#line 2970 "y.tab.c"
    break;

  case 84: /* FATOR: TK_INT  */
#line 1288 "sintatica.y"
            { 
                yyval.label = insereTemporariasTabelaSimbolos("", "nmr");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
                yyval.tipo = "int"; 
            }
#line 2980 "y.tab.c"
    break;

  case 85: /* FATOR: TK_FLOAT  */
#line 1294 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", "ncv");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n"; 
                yyval.tipo = "float"; 
            }
#line 2990 "y.tab.c"
    break;

  case 86: /* FATOR: TK_BOOLEAN  */
#line 1300 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "pp");
                string valor = pegaBooleano(yyvsp[0].label);

                if(valor == "error") yyerror("Valor atribuído de forma errada!");

                yyval.traducao = "\t" + yyval.label + " = " + valor + ";\n";
                yyval.tipo = "bool"; 
            }
#line 3004 "y.tab.c"
    break;

  case 87: /* FATOR: TK_CHAR  */
#line 1310 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "letra");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
                yyval.tipo = "char"; 
            }
#line 3014 "y.tab.c"
    break;

  case 88: /* FATOR: TK_STRING  */
#line 1315 "sintatica.y"
                       {
               cout << "label = " << yyval.traducao << endl;
               int tamanho = tamanho_string(yyval.traducao);
               yyval.label = insereTemporariasTabelaSimbolos("", "falada");
               yyval.traducao = "\tstrcpy(" + yyval.label + ", " + yyvsp[0].traducao + ");\n";
               yyval.tipo = "string"; 
            }
#line 3026 "y.tab.c"
    break;

  case 89: /* FATOR: TK_ID '[' EXP ']'  */
#line 1322 "sintatica.y"
                                {
            if (!verificaTabelaSimbolos(yyvsp[-3].label))
                yyerror("Vetor '" + yyvsp[-3].label + "' não declarado.");

            TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos(yyvsp[-3].label);

            if (!vet.isArray || vet.arraySize2 != 0)
                yyerror("'" + yyvsp[-3].label + "' não é vetor 1D.");

            if (yyvsp[-1].tipo != "int")
                yyerror("Índice do vetor deve ser inteiro.");

            string temp = insereTemporariasTabelaSimbolos("", vet.tipoVariavel);

            yyval.traducao = yyvsp[-1].traducao +
                        "\t" + temp + " = " + vet.label + "[" + yyvsp[-1].label + "];\n";

            yyval.label = temp;
            yyval.tipo = vet.tipoVariavel;
            }
#line 3051 "y.tab.c"
    break;

  case 90: /* FATOR: TK_ID '[' EXP ']' '[' EXP ']'  */
#line 1342 "sintatica.y"
                                            {
            if (!verificaTabelaSimbolos(yyvsp[-6].label))
                yyerror("Matriz '" + yyvsp[-6].label + "' não declarada.");

            TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos(yyvsp[-6].label);

            if (!mat.isArray || mat.arraySize2 == 0)
                yyerror("'" + yyvsp[-6].label + "' não é matriz 2D.");

            if (yyvsp[-4].tipo != "int" || yyvsp[-1].tipo != "int")
                yyerror("Índices da matriz devem ser inteiros.");

            string tempMult = insereTemporariasTabelaSimbolos("", "int");
            string tempIdx  = insereTemporariasTabelaSimbolos("", "int");
            string tempRes  = insereTemporariasTabelaSimbolos("", mat.tipoVariavel);

            yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao +
                        "\t" + tempMult + " = " + yyvsp[-4].label + " * " + to_string(mat.arraySize2) + ";\n" +
                        "\t" + tempIdx  + " = " + tempMult + " + " + yyvsp[-1].label + ";\n" +
                        "\t" + tempRes  + " = " + mat.label + "[" + tempIdx + "];\n";

            yyval.label = tempRes;
            yyval.tipo = mat.tipoVariavel;
            }
#line 3080 "y.tab.c"
    break;

  case 91: /* LISTA_ARGS: EXP ',' LISTA_ARGS  */
#line 1369 "sintatica.y"
        { 
            // Concatena o código para computar os argumentos
            yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao; 
            // Concatena os labels dos resultados para passar para a função
            yyval.label = yyvsp[-2].label + ", " + yyvsp[0].label;
        }
#line 3091 "y.tab.c"
    break;

  case 92: /* LISTA_ARGS: EXP  */
#line 1376 "sintatica.y"
        { 
            yyval.traducao = yyvsp[0].traducao; 
            yyval.label = yyvsp[0].label;
        }
#line 3100 "y.tab.c"
    break;

  case 93: /* LISTA_ARGS: %empty  */
#line 1381 "sintatica.y"
        {
            yyval.traducao = "";
            yyval.label = "";
        }
#line 3109 "y.tab.c"
    break;


#line 3113 "y.tab.c"

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

#line 1387 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int tamanho_string(string texto){ 
    // pega as aspas da string
    // vou deixar -2 na saída p tirar as aspas
    // tem que colocar +1 por causa do \0 -> -2 + 1 = -1

    int tamanhoString = 0;
    int i = 0;
    while(texto[i] != '\0'){ // se quiser testar como funciona isso aq só tirar o comentário do cout
        //cout << texto[i] << " ";
        tamanhoString++; 
        i++;
    }
    //cout << endl;

    //cout << tamanhoString-1<< endl;
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

void insereFixasTabelaSimbolos(string nome, string tipo,bool ehArray, int tamanhoArray, int tamanhoArray2, bool ehParam)
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

    temp.isArray = ehArray;
    temp.arraySize = tamanhoArray;
    temp.arraySize2 = tamanhoArray2;  // novo!
    temp.isParam = ehParam; // <-- USE O PARÂMETRO AQUI

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
