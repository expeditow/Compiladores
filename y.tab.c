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
#include <set> // Adicionado para o set de variáveis alocadas

#define YYSTYPE atributos

using namespace std;

// Contadores globais
int qntdVariaveisTemp = 0;
int contador_rotulos = 0;

// Constante para o buffer do scan
#define SCAN_BUFFER_SIZE 1024

// Pilhas para controle de laços (break/continue)
stack<string> pilhaRotulosFimLoop;
stack<string> pilhaRotulosProxIteracao;

// --- LÓGICA DE STRINGS (DO SEGUNDO CÓDIGO) ---
// Conjunto para rastrear labels de strings que foram alocadas com malloc e precisam de free()
set<string> variaveisAlocadas;

// Estrutura para guardar informações da função (do primeiro código)
struct TIPO_FUNCAO {
    string tipoRetorno;
    vector<string> tiposParametros;
};

// A tabela de símbolos para funções (do primeiro código)
map<string, TIPO_FUNCAO> tabelaFuncoes;

// Atributos para os nós da árvore sintática
// O campo 'tamanho' foi adicionado, conforme o segundo código.
struct atributos 
{
    string label;
    string traducao;
    string tipo;
    int tamanho; // Campo adicionado do segundo código
     vector<string> lista_tipos; // <-- ADICIONE/CONFIRME ESTA LINHA
};

// Estrutura para os símbolos na tabela
typedef struct
{
    string nomeVariavel; // nome no código fonte
    string tipoVariavel; // int, float, double
    string label; // nome no código intermediário (ex: T1, T2)

    bool isArray = false;
    int arraySize = 0;
    int arraySize2 = 0;
    bool isParam = false; // Campo do primeiro código para diferenciar parâmetros

   int getTamanhoTotal() const {
        return arraySize * (arraySize2 > 0 ? arraySize2 : 1);
    }

} TIPO_SIMBOLO;

// Protótipos de funções
int yylex(void);
void yyerror(string);

// Variáveis e estruturas de dados do compilador
set<pair<string,string>> temporarias;
vector<map<string, TIPO_SIMBOLO>> pilhaTabelasSimbolos;
stack<pair<string, string>> pilhaExprSwitch;
vector<TIPO_SIMBOLO> todosOsSimbolos; // <-- ADICIONE ESTA LINHA

// Funções de manipulação da Tabela de Símbolos
bool verificaTabelaSimbolos(string nome);
TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome);
void printTabelaSimbolos();
void entraEscopo();
void saiEscopo();

// Funções para inserir na Tabela de Símbolos
void insereFixasTabelaSimbolos(string nome, string tipo, bool ehArray = false, int tamanhoArray = 0, int tamanhoArray2 = 0, bool ehParam = false);
string insereTemporariasTabelaSimbolos(string nome, string tipo);

// Funções auxiliares de geração de código
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


#line 172 "y.tab.c"

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
    TK_POTENCIA = 290,             /* TK_POTENCIA  */
    TK_PRINT = 291,                /* TK_PRINT  */
    TK_SCAN = 292,                 /* TK_SCAN  */
    FIM_LINHA = 293                /* FIM_LINHA  */
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
#define TK_POTENCIA 290
#define TK_PRINT 291
#define TK_SCAN 292
#define FIM_LINHA 293

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
  YYSYMBOL_TK_POTENCIA = 35,               /* TK_POTENCIA  */
  YYSYMBOL_TK_PRINT = 36,                  /* TK_PRINT  */
  YYSYMBOL_TK_SCAN = 37,                   /* TK_SCAN  */
  YYSYMBOL_FIM_LINHA = 38,                 /* FIM_LINHA  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '>'  */
  YYSYMBOL_51_ = 51,                       /* '<'  */
  YYSYMBOL_52_ = 52,                       /* '*'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_START = 55,                     /* START  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_LISTA_FUNCOES = 57,             /* LISTA_FUNCOES  */
  YYSYMBOL_FUNCAO = 58,                    /* FUNCAO  */
  YYSYMBOL_59_2 = 59,                      /* $@2  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_PARAMS = 61,                    /* PARAMS  */
  YYSYMBOL_PARAM = 62,                     /* PARAM  */
  YYSYMBOL_BLOCO = 63,                     /* BLOCO  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_CMDS = 65,                      /* CMDS  */
  YYSYMBOL_CMD = 66,                       /* CMD  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_68_8 = 68,                      /* $@8  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_FOR_INICIA = 70,                /* FOR_INICIA  */
  YYSYMBOL_FOR_INCREM = 71,                /* FOR_INCREM  */
  YYSYMBOL_DECL = 72,                      /* DECL  */
  YYSYMBOL_ATR = 73,                       /* ATR  */
  YYSYMBOL_EXP = 74,                       /* EXP  */
  YYSYMBOL_TERMO = 75,                     /* TERMO  */
  YYSYMBOL_FATOR = 76,                     /* FATOR  */
  YYSYMBOL_LISTA_ARGS = 77,                /* LISTA_ARGS  */
  YYSYMBOL_POTENCIA = 78                   /* POTENCIA  */
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
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      39,    40,    52,    48,    41,    49,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      51,    45,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   116,   191,   195,   197,   200,   204,   204,
     204,   245,   254,   261,   268,   325,   325,   333,   339,   344,
     345,   346,   347,   348,   349,   350,   351,   364,   381,   381,
     402,   402,   424,   424,   449,   456,   464,   496,   521,   525,
     532,   533,   534,   536,   537,   538,   542,   548,   581,   589,
     598,   634,   653,   670,   687,   704,   714,   729,   746,   760,
     810,   830,   837,   844,   851,   858,   865,   872,   879,   886,
     890,   910,   930,   934,   980,   989,  1007,  1025,  1043,  1061,
    1063,  1069,  1089,  1097,  1103,  1110,  1118,  1125,  1134,  1144,
    1162,  1173,  1182,  1190,  1217
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
  "TK_DIV_IGUAL", "TK_POTENCIA", "TK_PRINT", "TK_SCAN", "FIM_LINHA", "'('",
  "')'", "','", "'{'", "'}'", "';'", "'='", "'['", "']'", "'+'", "'-'",
  "'>'", "'<'", "'*'", "'/'", "$accept", "START", "$@1", "LISTA_FUNCOES",
  "FUNCAO", "$@2", "$@3", "PARAMS", "PARAM", "BLOCO", "$@6", "CMDS", "CMD",
  "$@7", "$@8", "$@9", "FOR_INICIA", "FOR_INCREM", "DECL", "ATR", "EXP",
  "TERMO", "FATOR", "LISTA_ARGS", "POTENCIA", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -75,     5,   -75,   -75,     1,    23,   -75,   -75,    -1,    37,
      40,    12,    30,   -75,   -75,    37,    31,   -75,   -75,   -75,
      58,   -75,    77,   -17,   154,   -75,   -75,   -75,   -75,   -75,
      81,    62,    63,   -75,    64,    66,    68,   105,   106,    73,
      75,   -75,   127,   154,    74,    58,    78,    80,   217,   -29,
      86,   -75,   -20,   -75,   -75,   154,   154,   154,   154,   154,
     171,   154,    69,   245,   -75,   154,   154,    31,    47,   -75,
     -75,   -75,   -75,   154,   118,    83,    42,   -75,   -75,   -75,
     -75,   -75,   154,   154,   154,   154,   154,   154,   -75,   154,
     154,   154,   154,   154,   154,   154,   154,   120,   427,   427,
     427,   427,   228,    84,   143,   427,   259,   154,   -75,   273,
     286,   109,   414,    94,   -75,   -75,   303,    99,   154,   -75,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -75,   -75,   -75,   427,    93,   154,   -75,   154,    14,   316,
      31,   -75,   103,   154,   154,   107,   111,   -75,    97,   -75,
     333,   154,   154,   101,   131,    31,   154,   344,   357,   -75,
     -75,   145,   200,   427,   363,   154,    31,   -75,   404,    24,
     188,   108,   154,   122,   374,   -75,   114,   154,   125,   -75,
     427,   -75,   415,   154,   -75,   -75,   421,   -75,    -5,   427,
     122,    31,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     7,     1,     3,     0,     6,     5,     0,    13,
       0,     0,    12,    14,     8,    13,     0,    11,    15,     9,
      18,    10,     0,    81,     0,    83,    84,    85,    86,    87,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,    18,    20,    22,    24,    69,
      94,    72,    46,    76,    78,     0,     0,     0,     0,    92,
       0,     0,    81,    39,    82,     0,     0,     0,    42,    34,
      35,    75,    77,     0,     0,     0,     0,    74,    16,    17,
      21,    23,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    91,     0,    81,    50,     0,     0,    38,     0,
       0,     0,     0,     0,    40,    41,     0,     0,     0,    79,
      63,    64,    65,    66,    67,    68,    59,    60,    61,    62,
      70,    71,    93,    47,     0,    92,    73,     0,    88,     0,
       0,    28,     0,     0,     0,     0,     0,    80,    49,    90,
       0,     0,     0,    88,    26,     0,     0,     0,     0,    36,
      37,     0,    58,    55,     0,     0,     0,    29,     0,     0,
      45,     0,     0,    89,     0,    27,     0,     0,     0,    43,
      44,    48,     0,     0,    89,    31,     0,    32,    57,    56,
       0,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   139,   -75,   -66,
     -75,   123,   -75,   -75,   -75,   -75,   -75,   -75,   102,   -65,
     -24,   397,   -41,    34,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     7,    16,    21,    11,    12,    19,
      20,    44,    45,   155,    67,   191,   113,   178,    46,    47,
      48,    49,    50,   103,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,   111,    77,   115,     5,     3,   -89,   -89,   -89,   -89,
     -89,   -89,    53,    54,    55,    56,    57,    58,    76,   130,
     131,   132,    59,    93,    94,    96,    97,     8,    60,    61,
     -89,    98,    99,   100,   101,   102,   105,   106,     9,     6,
      10,   109,   110,   -89,    13,   -89,   -89,   -89,   -89,   116,
      22,   112,    14,    82,    83,    84,    85,    86,    87,   151,
     152,    22,    23,    24,    25,    26,    27,    28,    29,   151,
     177,    15,   133,    18,   154,    30,    31,   147,    32,    33,
      34,    52,   119,   139,    35,    64,    36,    37,    38,   167,
      89,    90,    91,    92,    39,    40,    41,    42,    53,    54,
     175,    65,    66,    68,    69,   179,    70,    43,    59,    71,
      72,   102,    73,   150,    74,   107,    80,    78,    81,   157,
     158,    95,   117,   118,   136,   192,   134,   163,   164,   142,
      75,    62,   168,    25,    26,    27,    28,    29,   144,   146,
     148,   174,   156,   161,    30,   159,   180,   165,   182,   160,
     166,   171,   185,   186,    17,   181,    37,    38,    62,   189,
      25,    26,    27,    28,    29,   187,    42,   183,    79,   149,
     114,    30,    53,    54,     0,   104,    43,    25,    26,    27,
      28,    29,    59,    37,    38,     0,     0,     0,    30,   137,
       0,     0,    23,    42,    25,    26,    27,    28,    29,     0,
      37,    38,     0,    43,     0,    30,     0,     0,     0,     0,
      42,   -88,   -88,   -88,   -88,   -88,   -88,    37,    38,     0,
      43,     0,     0,     0,     0,     0,     0,    42,    82,    83,
      84,    85,    86,    87,     0,   -88,     0,    43,     0,    82,
      83,    84,    85,    86,    87,     0,   172,     0,   -88,     0,
     -88,   -88,   -88,   -88,     0,    88,    82,    83,    84,    85,
      86,    87,     0,     0,     0,    89,    90,    91,    92,   135,
      82,    83,    84,    85,    86,    87,    89,    90,    91,    92,
       0,     0,     0,   108,    82,    83,    84,    85,    86,    87,
       0,     0,     0,    89,    90,    91,    92,    82,    83,    84,
      85,    86,    87,     0,     0,     0,   138,    89,    90,    91,
      92,     0,     0,   140,    82,    83,    84,    85,    86,    87,
       0,    89,    90,    91,    92,     0,   141,    82,    83,    84,
      85,    86,    87,     0,    89,    90,    91,    92,     0,     0,
       0,     0,     0,   145,    82,    83,    84,    85,    86,    87,
       0,    89,    90,    91,    92,    82,    83,    84,    85,    86,
      87,     0,     0,   153,    89,    90,    91,    92,    82,    83,
      84,    85,    86,    87,    82,    83,    84,    85,    86,    87,
     162,    89,    90,    91,    92,    82,    83,    84,    85,    86,
      87,   169,    89,    90,    91,    92,     0,     0,     0,     0,
       0,   170,     0,     0,     0,    89,    90,    91,    92,     0,
     173,    89,    90,    91,    92,    82,    83,    84,    85,    86,
      87,   184,    89,    90,    91,    92,    82,    83,    84,    85,
      86,    87,    82,    83,    84,    85,    86,    87,    82,    83,
      84,    85,    86,    87,   176,    55,    56,    57,    58,     0,
       0,     0,    89,    90,    91,    92,     0,     0,     0,    60,
     143,     0,   188,    89,    90,    91,    92,     0,   190,    89,
      90,    91,    92,     0,     0,    89,    90,    91,    92,   120,
     121,   122,   123,   124,   125,     0,   126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
      24,    67,    43,    68,     3,     0,    11,    12,    13,    14,
      15,    16,    29,    30,    31,    32,    33,    34,    42,    93,
      94,    95,    39,    52,    53,    45,    46,     4,    45,    46,
      35,    55,    56,    57,    58,    59,    60,    61,    39,    38,
       3,    65,    66,    48,     4,    50,    51,    52,    53,    73,
       3,     4,    40,    11,    12,    13,    14,    15,    16,    45,
      46,     3,     4,     5,     6,     7,     8,     9,    10,    45,
      46,    41,    96,    42,   140,    17,    18,   118,    20,    21,
      22,     4,    40,   107,    26,     4,    28,    29,    30,   155,
      48,    49,    50,    51,    36,    37,    38,    39,    29,    30,
     166,    39,    39,    39,    38,   170,    38,    49,    39,     4,
       4,   135,    39,   137,    39,    46,    38,    43,    38,   143,
     144,    35,     4,    40,    40,   191,     6,   151,   152,    20,
       3,     4,   156,     6,     7,     8,     9,    10,    44,    40,
      47,   165,    39,    46,    17,    38,   170,    46,   172,    38,
      19,     6,    38,   177,    15,    47,    29,    30,     4,   183,
       6,     7,     8,     9,    10,    40,    39,    45,    45,   135,
      68,    17,    29,    30,    -1,     4,    49,     6,     7,     8,
       9,    10,    39,    29,    30,    -1,    -1,    -1,    17,    46,
      -1,    -1,     4,    39,     6,     7,     8,     9,    10,    -1,
      29,    30,    -1,    49,    -1,    17,    -1,    -1,    -1,    -1,
      39,    11,    12,    13,    14,    15,    16,    29,    30,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    39,    11,    12,
      13,    14,    15,    16,    -1,    35,    -1,    49,    -1,    11,
      12,    13,    14,    15,    16,    -1,    46,    -1,    48,    -1,
      50,    51,    52,    53,    -1,    38,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    48,    49,    50,    51,    41,
      11,    12,    13,    14,    15,    16,    48,    49,    50,    51,
      -1,    -1,    -1,    38,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    48,    49,    50,    51,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    -1,    -1,    40,    11,    12,    13,    14,    15,    16,
      -1,    48,    49,    50,    51,    -1,    40,    11,    12,    13,
      14,    15,    16,    -1,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    40,    11,    12,    13,    14,    15,    16,
      -1,    48,    49,    50,    51,    11,    12,    13,    14,    15,
      16,    -1,    -1,    47,    48,    49,    50,    51,    11,    12,
      13,    14,    15,    16,    11,    12,    13,    14,    15,    16,
      47,    48,    49,    50,    51,    11,    12,    13,    14,    15,
      16,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,    -1,
      47,    48,    49,    50,    51,    11,    12,    13,    14,    15,
      16,    47,    48,    49,    50,    51,    11,    12,    13,    14,
      15,    16,    11,    12,    13,    14,    15,    16,    11,    12,
      13,    14,    15,    16,    40,    31,    32,    33,    34,    -1,
      -1,    -1,    48,    49,    50,    51,    -1,    -1,    -1,    45,
      46,    -1,    47,    48,    49,    50,    51,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    48,    49,    50,    51,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,    57,     3,    38,    58,     4,    39,
       3,    61,    62,     4,    40,    41,    59,    61,    42,    63,
      64,    60,     3,     4,     5,     6,     7,     8,     9,    10,
      17,    18,    20,    21,    22,    26,    28,    29,    30,    36,
      37,    38,    39,    49,    65,    66,    72,    73,    74,    75,
      76,    78,     4,    29,    30,    31,    32,    33,    34,    39,
      45,    46,     4,    74,     4,    39,    39,    68,    39,    38,
      38,     4,     4,    39,    39,     3,    74,    76,    43,    65,
      38,    38,    11,    12,    13,    14,    15,    16,    38,    48,
      49,    50,    51,    52,    53,    35,    45,    46,    74,    74,
      74,    74,    74,    77,     4,    74,    74,    46,    38,    74,
      74,    63,     4,    70,    72,    73,    74,     4,    40,    40,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      78,    78,    78,    74,     6,    41,    40,    46,    47,    74,
      40,    40,    20,    46,    44,    40,    40,    76,    47,    77,
      74,    45,    46,    47,    63,    67,    39,    74,    74,    38,
      38,    46,    47,    74,    74,    46,    19,    63,    74,    47,
      44,     6,    46,    47,    74,    63,    40,    46,    71,    73,
      74,    47,    74,    45,    47,    38,    74,    40,    47,    74,
      47,    69,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    56,    55,    55,    57,    57,    57,    59,    60,
      58,    61,    61,    61,    62,    64,    63,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    66,
      68,    66,    69,    66,    66,    66,    66,    66,    66,    66,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     0,     0,
       8,     3,     1,     0,     2,     0,     4,     2,     0,     2,
       1,     2,     1,     2,     1,     1,     5,     7,     0,     6,
       0,     8,     0,    10,     2,     2,     5,     5,     3,     2,
       1,     1,     0,     1,     1,     0,     2,     4,     8,     5,
       3,     3,     3,     3,     3,     6,     9,     9,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     4,     2,     2,     2,     2,     2,     3,
       4,     1,     2,     1,     1,     1,     1,     1,     4,     7,
       3,     1,     0,     3,     1
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
#line 116 "sintatica.y"
      { entraEscopo(); }
#line 1538 "y.tab.c"
    break;

  case 3: /* START: $@1 LISTA_FUNCOES  */
#line 117 "sintatica.y"
    {
        if(debug) cout << "[DEBUG] Árvore completa gerada. Tradução:\n";

        // Cabeçalhos C padrão
        string cabecalho = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\n\n";
        string defines = "#define true 1\n#define false 0\n\n";

        // Função auxiliar para strlen (CORPO COMPLETO RESTAURADO)
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
        
        // Função auxiliar para potenciação (CORPO COMPLETO)
        string funcao_potencia =
            "float potencia_helper(float base, int expoente) {\n"
            "\tfloat resultado = 1.0;\n"
            "\tint contador = expoente;\n"
            "L_POW_START:\n"
            "\tif (contador <= 0) goto L_POW_END;\n"
            "\tresultado = resultado * base;\n"
            "\tcontador = contador - 1;\n"
            "\tgoto L_POW_START;\n"
            "L_POW_END:\n"
            "\treturn resultado;\n"
            "}\n\n";

        // Geração das declarações de variáveis (LÓGICA CORRIGIDA para vetores)
        string declaracoes = "";
        for (const auto& simbolo : todosOsSimbolos) {
            if (simbolo.isArray) {
                int tamanho = simbolo.getTamanhoTotal();
                declaracoes += "\t" + simbolo.tipoVariavel + " " + simbolo.label + "[" + to_string(tamanho) + "];\n";
            } else {
                if (simbolo.tipoVariavel == "string")
                    declaracoes += "\tchar* " + simbolo.label + " = NULL;\n";
                else if(simbolo.tipoVariavel == "bool")
                    declaracoes += "\tint " + simbolo.label + ";\n";
                else
                    declaracoes += "\t" + simbolo.tipoVariavel + " " + simbolo.label + ";\n";
            }
        }

        // Montagem do código final
        cout << cabecalho 
             << defines 
             << declaracoes << "\n" 
             << funcao_meu_strlen 
             << funcao_potencia 
             << yyvsp[0].traducao << endl;

        saiEscopo();
    }
#line 1618 "y.tab.c"
    break;

  case 5: /* LISTA_FUNCOES: LISTA_FUNCOES FUNCAO  */
#line 196 "sintatica.y"
        { yyval.traducao = yyvsp[-1].traducao + "\n" + yyvsp[0].traducao; }
#line 1624 "y.tab.c"
    break;

  case 6: /* LISTA_FUNCOES: LISTA_FUNCOES FIM_LINHA  */
#line 198 "sintatica.y"
        { yyval = yyvsp[-1]; }
#line 1630 "y.tab.c"
    break;

  case 7: /* LISTA_FUNCOES: %empty  */
#line 200 "sintatica.y"
        { yyval.traducao = ""; }
#line 1636 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 204 "sintatica.y"
                                   { entraEscopo(); }
#line 1642 "y.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 204 "sintatica.y"
                                                            { saiEscopo(); }
#line 1648 "y.tab.c"
    break;

  case 10: /* FUNCAO: TK_TIPO TK_ID '(' PARAMS ')' $@2 BLOCO $@3  */
#line 205 "sintatica.y"
    {
        string tipoRetorno = pegaTipo(yyvsp[-7].label);
        string nome = yyvsp[-6].label;
        string corpoFuncao = yyvsp[-1].traducao;

        if (nome == "principal")
            nome = "main";

        if (tabelaFuncoes.count(nome)) {
            yyerror("Função '" + nome + "' já foi declarada.");
        } else {
            TIPO_FUNCAO infoFunc;
            infoFunc.tipoRetorno = tipoRetorno;
            infoFunc.tiposParametros = yyvsp[-4].lista_tipos; // <-- ESTA LINHA CONSERTA O BUG DE SALVAMENTO
            
            tabelaFuncoes[nome] = infoFunc;
            // --- DEBUG ---
            cout << "[DEBUG FUNCAO] Salvando definicao da funcao '" << nome << "'. "
                 << "Tipos de parametros esperados (" << infoFunc.tiposParametros.size() << "): ";
            for(const auto& tipo : infoFunc.tiposParametros) { cout << tipo << " "; }
            cout << endl;
            if(debug) cout << "[DEBUG] Função '" << nome << "' inserida na tabela de funções.\n";
        }
        
        if (nome == "main") {
            string frees = "";
            if (!variaveisAlocadas.empty()) {
                frees += "\n";
                for (const auto& varLabel : variaveisAlocadas) {
                    frees += "\tfree(" + varLabel + ");\n";
                }
            }
            corpoFuncao += frees;
        }

        yyval.traducao = tipoRetorno + " " + nome + "(" + yyvsp[-4].traducao + ") {\n" + corpoFuncao + "}\n";
    }
#line 1690 "y.tab.c"
    break;

  case 11: /* PARAMS: PARAM ',' PARAMS  */
#line 246 "sintatica.y"
        { 
            yyval.traducao = yyvsp[-2].traducao + ", " + yyvsp[0].traducao;
            
            // Constrói a lista de tipos completa
            yyval.lista_tipos = yyvsp[-2].lista_tipos; // Começa com a lista do primeiro param
            // Insere a lista dos params restantes no final
            yyval.lista_tipos.insert(yyval.lista_tipos.end(), yyvsp[0].lista_tipos.begin(), yyvsp[0].lista_tipos.end());
        }
#line 1703 "y.tab.c"
    break;

  case 12: /* PARAMS: PARAM  */
#line 255 "sintatica.y"
        { 
            // Caso base: se for só um parâmetro, apenas repassa seus atributos
            yyval.traducao = yyvsp[0].traducao;
            yyval.lista_tipos = yyvsp[0].lista_tipos;
        }
#line 1713 "y.tab.c"
    break;

  case 13: /* PARAMS: %empty  */
#line 261 "sintatica.y"
        { 
            yyval.traducao = ""; 
            // A lista de tipos aqui fica intencionalmente vazia
        }
#line 1722 "y.tab.c"
    break;

  case 14: /* PARAM: TK_TIPO TK_ID  */
#line 269 "sintatica.y"
    {
        string tipoParametro = pegaTipo(yyvsp[-1].label);
        insereFixasTabelaSimbolos(yyvsp[0].label, yyvsp[-1].label, false, 0, 0, true);

        // A tradução da assinatura em C++ (ex: "int x")
        yyval.traducao = tipoParametro + " " + yyvsp[0].label;
        
        // Ação essencial: Cria uma lista contendo o tipo deste parâmetro
        yyval.lista_tipos.push_back(tipoParametro);
          // --- DEBUG ---
     
    }
#line 1739 "y.tab.c"
    break;

  case 15: /* $@6: %empty  */
#line 325 "sintatica.y"
                  { entraEscopo(); }
#line 1745 "y.tab.c"
    break;

  case 16: /* BLOCO: '{' $@6 CMDS '}'  */
#line 326 "sintatica.y"
            {   
                printTabelaSimbolos();
                yyval.traducao = yyvsp[-1].traducao;
                saiEscopo();
            }
#line 1755 "y.tab.c"
    break;

  case 17: /* CMDS: CMD CMDS  */
#line 334 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
                if(debug) cout << "[DEBUG] Comando processado. Acumulado:\n" << yyvsp[-1].traducao;
            }
#line 1764 "y.tab.c"
    break;

  case 18: /* CMDS: %empty  */
#line 339 "sintatica.y"
            {
                yyval.traducao = "";
            }
#line 1772 "y.tab.c"
    break;

  case 19: /* CMD: EXP FIM_LINHA  */
#line 344 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1778 "y.tab.c"
    break;

  case 20: /* CMD: DECL  */
#line 345 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1784 "y.tab.c"
    break;

  case 21: /* CMD: DECL FIM_LINHA  */
#line 346 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1790 "y.tab.c"
    break;

  case 22: /* CMD: ATR  */
#line 347 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1796 "y.tab.c"
    break;

  case 23: /* CMD: ATR FIM_LINHA  */
#line 348 "sintatica.y"
                             { yyval.traducao = yyvsp[-1].traducao; }
#line 1802 "y.tab.c"
    break;

  case 24: /* CMD: EXP  */
#line 349 "sintatica.y"
                             { yyval.traducao = yyvsp[0].traducao; }
#line 1808 "y.tab.c"
    break;

  case 25: /* CMD: FIM_LINHA  */
#line 350 "sintatica.y"
                             { yyval.traducao = "";           }
#line 1814 "y.tab.c"
    break;

  case 26: /* CMD: TK_IF '(' EXP ')' BLOCO  */
#line 352 "sintatica.y"
            {
                string rotuloFimIf = novo_rotulo();
                string temp_copia = insereTemporariasTabelaSimbolos("", "bool");
                string temp_negada = insereTemporariasTabelaSimbolos("", "bool");

                yyval.traducao = yyvsp[-2].traducao +
                                 "\t" + temp_copia + " = " + yyvsp[-2].label + ";\n" +
                                 "\t" + temp_negada + " = !" + temp_copia + ";\n" +
                                 "\tif (" + temp_negada + ") goto " + rotuloFimIf + ";\n" +
                                 yyvsp[0].traducao +
                                 rotuloFimIf + ":\n";
            }
#line 1831 "y.tab.c"
    break;

  case 27: /* CMD: TK_IF '(' EXP ')' BLOCO TK_ELSE BLOCO  */
#line 365 "sintatica.y"
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
#line 1852 "y.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 381 "sintatica.y"
                                   { /* Ação em tempo de redução */
                string rotuloTeste = novo_rotulo();
                string rotuloFimWhile = novo_rotulo();
                pilhaRotulosProxIteracao.push(rotuloTeste);
                pilhaRotulosFimLoop.push(rotuloFimWhile); 
            }
#line 1863 "y.tab.c"
    break;

  case 29: /* CMD: TK_WHILE '(' EXP ')' $@7 BLOCO  */
#line 388 "sintatica.y"
            {
                string rotuloTeste = pilhaRotulosProxIteracao.top();
                string rotuloFimWhile = pilhaRotulosFimLoop.top();

                yyval.traducao = rotuloTeste + ":\n" +
                                 yyvsp[-3].traducao +
                                 "\tif (!" + yyvsp[-3].label + ") goto " + rotuloFimWhile + ";\n" +
                                 yyvsp[0].traducao +
                                 "\tgoto " + rotuloTeste + ";\n" +
                                 rotuloFimWhile + ":\n";

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
#line 1882 "y.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 402 "sintatica.y"
                    {
                string rotuloTeste = novo_rotulo();
                string rotuloFimDoWhile = novo_rotulo();
                pilhaRotulosProxIteracao.push(rotuloTeste);
                pilhaRotulosFimLoop.push(rotuloFimDoWhile);
            }
#line 1893 "y.tab.c"
    break;

  case 31: /* CMD: TK_DO $@8 BLOCO TK_WHILE '(' EXP ')' FIM_LINHA  */
#line 409 "sintatica.y"
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

                pilhaRotulosProxIteracao.pop();
                pilhaRotulosFimLoop.pop();
            }
#line 1913 "y.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 424 "sintatica.y"
                                                               {
                string rotuloIncremento = novo_rotulo();
                string rotuloFimFor = novo_rotulo();
                pilhaRotulosProxIteracao.push(rotuloIncremento);
                pilhaRotulosFimLoop.push(rotuloFimFor);
            }
#line 1924 "y.tab.c"
    break;

  case 33: /* CMD: TK_FOR '(' FOR_INICIA ';' EXP ';' FOR_INCREM ')' $@9 BLOCO  */
#line 431 "sintatica.y"
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
#line 1947 "y.tab.c"
    break;

  case 34: /* CMD: TK_BREAK FIM_LINHA  */
#line 450 "sintatica.y"
            {
                if (pilhaRotulosFimLoop.empty()) {
                    yyerror("Erro semântico: 'break' fora de um laço.");
                }
                yyval.traducao = "\tgoto " + pilhaRotulosFimLoop.top() + ";\n";
            }
#line 1958 "y.tab.c"
    break;

  case 35: /* CMD: TK_CONTINUE FIM_LINHA  */
#line 457 "sintatica.y"
            {
                if (pilhaRotulosProxIteracao.empty()) {
                    yyerror("Erro semântico: 'continue' fora de um laço.");
                }
                yyval.traducao = "\tgoto " + pilhaRotulosProxIteracao.top() + ";\n";
            }
#line 1969 "y.tab.c"
    break;

  case 36: /* CMD: TK_PRINT '(' EXP ')' FIM_LINHA  */
#line 465 "sintatica.y"
            {
                if (yyvsp[-2].tipo == "string_literal") {
                    // Lógica do segundo código: aloca, imprime e libera imediatamente.
                    string temp_print_str = insereTemporariasTabelaSimbolos("", "string");
                    int tamanho = tamanho_string(yyvsp[-2].traducao); // Usa a função substituída

                    stringstream ss;
                    ss << "\t" << temp_print_str << " = (char*) malloc(" << tamanho << ");\n";
                    ss << "\tstrcpy(" << temp_print_str << ", " << yyvsp[-2].traducao << ");\n";
                    ss << "\tprintf(\"%s\\n\", " << temp_print_str << ");\n";
                    ss << "\tfree(" << temp_print_str << ");\n"; // Liberação imediata
                    yyval.traducao = ss.str();

                } else {
                    // Lógica original para outras variáveis (números, char, variáveis string)
                    string formato = "";
                    string tipoVar = pegaTipo(yyvsp[-2].tipo);
                    
                    if (tipoVar == "int") formato = "%d";
                    else if (tipoVar == "float") formato = "%f";
                    else if (tipoVar == "char") formato = "%c";
                    else if (tipoVar == "bool") formato = "%d";
                    else if (tipoVar == "string") formato = "%s";
                    else {
                        yyerror("Tipo inválido para 'print': " + yyvsp[-2].tipo);
                    }
                    
                    yyval.traducao = yyvsp[-2].traducao + "\tprintf(\"" + formato + "\\n\", " + yyvsp[-2].label + ");\n";
                }
            }
#line 2004 "y.tab.c"
    break;

  case 37: /* CMD: TK_SCAN '(' TK_ID ')' FIM_LINHA  */
#line 497 "sintatica.y"
            {
                TIPO_SIMBOLO varSimbolo;
                if (!verificaTabelaSimbolos(yyvsp[-2].label)) {
                    yyerror("Variável '" + yyvsp[-2].label + "' não declarada para 'scan'.");
                } else {
                    varSimbolo = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
                }

                if (varSimbolo.tipoVariavel == "string") {
                    stringstream ss;
                    ss << "\tfree(" << varSimbolo.label << ");\n";
                    ss << "\t" << varSimbolo.label << " = (char*) malloc(" << SCAN_BUFFER_SIZE << ");\n";
                    ss << "\tscanf(\"%s\", " << varSimbolo.label << ");\n";
                    
                    variaveisAlocadas.insert(varSimbolo.label);
                    yyval.traducao = ss.str();
                } else {
                    string formato = (varSimbolo.tipoVariavel == "int" || varSimbolo.tipoVariavel == "bool") ? "%d" :
                                     (varSimbolo.tipoVariavel == "float") ? "%f" : " %c";
                    string argumentoScan = "&" + varSimbolo.label;
                    
                    yyval.traducao = "\tscanf(\"" + formato + "\", " + argumentoScan + ");\n";
                }
            }
#line 2033 "y.tab.c"
    break;

  case 38: /* CMD: TK_RETURN EXP FIM_LINHA  */
#line 522 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + "\treturn " + yyvsp[-1].label + ";\n";
            }
#line 2041 "y.tab.c"
    break;

  case 39: /* CMD: TK_RETURN EXP  */
#line 526 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao + "\treturn " + yyvsp[0].label + ";\n";
            }
#line 2049 "y.tab.c"
    break;

  case 40: /* FOR_INICIA: DECL  */
#line 532 "sintatica.y"
                   { yyval.traducao = yyvsp[0].traducao; }
#line 2055 "y.tab.c"
    break;

  case 41: /* FOR_INICIA: ATR  */
#line 533 "sintatica.y"
                  { yyval.traducao = yyvsp[0].traducao; }
#line 2061 "y.tab.c"
    break;

  case 42: /* FOR_INICIA: %empty  */
#line 534 "sintatica.y"
              { yyval.traducao = ""; }
#line 2067 "y.tab.c"
    break;

  case 43: /* FOR_INCREM: ATR  */
#line 536 "sintatica.y"
                  { yyval.traducao = yyvsp[0].traducao; }
#line 2073 "y.tab.c"
    break;

  case 44: /* FOR_INCREM: EXP  */
#line 537 "sintatica.y"
                  { yyval.traducao = yyvsp[0].traducao; }
#line 2079 "y.tab.c"
    break;

  case 45: /* FOR_INCREM: %empty  */
#line 538 "sintatica.y"
              { yyval.traducao = ""; }
#line 2085 "y.tab.c"
    break;

  case 46: /* DECL: TK_TIPO TK_ID  */
#line 543 "sintatica.y"
            {
                insereFixasTabelaSimbolos(yyvsp[0].label, yyvsp[-1].label);
                yyval.traducao = ""; // A declaração real ocorre no início do código C
            }
#line 2094 "y.tab.c"
    break;

  case 47: /* DECL: TK_TIPO TK_ID '=' EXP  */
#line 549 "sintatica.y"
            {
                insereFixasTabelaSimbolos(yyvsp[-2].label, yyvsp[-3].label);
                TIPO_SIMBOLO varSimbolo = pegaVariavelTabelaSimbolos(yyvsp[-2].label);

                string tipoExp = pegaTipo(yyvsp[0].tipo);
                // Tipo de checagem do segundo código (sem char_array)
                if (varSimbolo.tipoVariavel != tipoExp && varSimbolo.tipoVariavel != "string" && yyvsp[0].tipo != "string_literal") {
                    yyerror("Tipo incompatível na declaração de '" + yyvsp[-2].label + "'.");
                }
                
                if (varSimbolo.tipoVariavel == "string") {
                    string temp_tamanho = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    if (yyvsp[0].tipo == "string_literal") {

                        int tamanho = tamanho_string(yyvsp[0].traducao);
                        ss << "\t" << temp_tamanho << " = " << tamanho << ";\n";
                        ss << "\t" << varSimbolo.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varSimbolo.label << ", " << yyvsp[0].traducao << ");\n";
                    } else { // O lado direito é uma variável string
                        ss << yyvsp[0].traducao;
                        ss << "\t" << temp_tamanho << " = meu_strlen(" << yyvsp[0].label << ") + 1;\n";
                        ss << "\t" << varSimbolo.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varSimbolo.label << ", " << yyvsp[0].label << ");\n";
                    }
                    yyval.traducao = ss.str();
                    variaveisAlocadas.insert(varSimbolo.label);
                } else {
                    yyval.traducao = yyvsp[0].traducao + "\t" + varSimbolo.label + " = " + yyvsp[0].label + ";\n";
                }
            }
#line 2131 "y.tab.c"
    break;

  case 48: /* DECL: TK_TIPO TK_ID '[' TK_INT ']' '[' TK_INT ']'  */
#line 582 "sintatica.y"
            {
                string tipo = pegaTipo(yyvsp[-7].label);
                int tamanho1 = stoi(yyvsp[-4].label);
                int tamanho2 = stoi(yyvsp[-1].label);
                insereFixasTabelaSimbolos(yyvsp[-6].label, yyvsp[-7].label, true, tamanho1, tamanho2);
                yyval.traducao = "";
            }
#line 2143 "y.tab.c"
    break;

  case 49: /* DECL: TK_TIPO TK_ID '[' TK_INT ']'  */
#line 590 "sintatica.y"
            {
                string tipo = pegaTipo(yyvsp[-4].label);
                int tamanho = stoi(yyvsp[-1].label);
                insereFixasTabelaSimbolos(yyvsp[-3].label, yyvsp[-4].label, true, tamanho);
                yyval.traducao = "";
            }
#line 2154 "y.tab.c"
    break;

  case 50: /* ATR: TK_ID '=' EXP  */
#line 599 "sintatica.y"
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
                string tipoExp = pegaTipo(yyvsp[0].tipo);

                // Tipo de checagem do segundo código (sem char_array)
                if (varEsquerda.tipoVariavel != tipoExp && varEsquerda.tipoVariavel != "string" && yyvsp[0].tipo != "string_literal") {
                    yyerror("Tipo incompatível na atribuição para '" + yyvsp[-2].label + "'.");
                }

                yyval.label = varEsquerda.label;

                // --- LÓGICA DE ATRIBUIÇÃO DE STRING (IDÊNTICA EM AMBOS) ---
                if (varEsquerda.tipoVariavel == "string") {
                    string temp_tamanho = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    ss << "\tfree(" << varEsquerda.label << ");\n";

                    if (yyvsp[0].tipo == "string_literal") {
                        int tamanho = tamanho_string(yyvsp[0].traducao);
                        ss << "\t" << temp_tamanho << " = " << tamanho << ";\n";
                        ss << "\t" << varEsquerda.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varEsquerda.label << ", " << yyvsp[0].traducao << ");\n";
                    } else { // O lado direito é outra variável string
                        ss << yyvsp[0].traducao;
                        ss << "\t" << temp_tamanho << " = meu_strlen(" << yyvsp[0].label << ") + 1;\n";
                        ss << "\t" << varEsquerda.label << " = (char*) malloc(" << temp_tamanho << ");\n";
                        ss << "\tstrcpy(" << varEsquerda.label << ", " << yyvsp[0].label << ");\n";
                    }
                    yyval.traducao = ss.str();
                    variaveisAlocadas.insert(varEsquerda.label); 
                } else {
                    yyval.traducao = yyvsp[0].traducao + "\t" + varEsquerda.label + " = " + yyvsp[0].label + ";\n";
                }
            }
#line 2194 "y.tab.c"
    break;

  case 51: /* ATR: TK_ID TK_MAIS_IGUAL EXP  */
#line 635 "sintatica.y"
            {
                TIPO_SIMBOLO varEsquerda = pegaVariavelTabelaSimbolos(yyvsp[-2].label);
                string tipoResultado = infereTipo(varEsquerda.tipoVariavel, yyvsp[0].tipo);
                if (tipoResultado != varEsquerda.tipoVariavel && varEsquerda.tipoVariavel != "float") {
                    yyerror("Erro de tipo em '+=': Nao e possivel atribuir um " + tipoResultado + " a um " + varEsquerda.tipoVariavel);
                }

                string temp_valor_esq = insereTemporariasTabelaSimbolos("", varEsquerda.tipoVariavel);
                string temp_resultado = insereTemporariasTabelaSimbolos("", tipoResultado);
                stringstream ss;
                ss << yyvsp[0].traducao;
                ss << "\t" << temp_valor_esq << " = " << varEsquerda.label << ";\n";
                ss << "\t" << temp_resultado << " = " << temp_valor_esq << " + " << yyvsp[0].label << ";\n";
                ss << "\t" << varEsquerda.label << " = " << temp_resultado << ";\n";
                yyval.traducao = ss.str();
                yyval.label = varEsquerda.label;
                yyval.tipo = varEsquerda.tipoVariavel;
            }
#line 2217 "y.tab.c"
    break;

  case 52: /* ATR: TK_ID TK_MENOS_IGUAL EXP  */
#line 654 "sintatica.y"
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
#line 2238 "y.tab.c"
    break;

  case 53: /* ATR: TK_ID TK_MULT_IGUAL EXP  */
#line 671 "sintatica.y"
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
#line 2259 "y.tab.c"
    break;

  case 54: /* ATR: TK_ID TK_DIV_IGUAL EXP  */
#line 688 "sintatica.y"
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
#line 2280 "y.tab.c"
    break;

  case 55: /* ATR: TK_ID '[' EXP ']' '=' EXP  */
#line 705 "sintatica.y"
            {
                TIPO_SIMBOLO temp = pegaVariavelTabelaSimbolos(yyvsp[-5].label);
                if (!temp.isArray) yyerror("Variável '" + yyvsp[-5].label + "' não é um vetor.");
                if (yyvsp[-3].tipo != "int") yyerror("Índice de vetor deve ser inteiro.");
                if (temp.tipoVariavel != pegaTipo(yyvsp[0].tipo)) yyerror("Tipo incompatível ao atribuir em vetor.");

                yyval.label = temp.label;
                yyval.traducao = yyvsp[-3].traducao + yyvsp[0].traducao + "\t" + temp.label + "[" + yyvsp[-3].label + "] = " + yyvsp[0].label + ";\n";
            }
#line 2294 "y.tab.c"
    break;

  case 56: /* ATR: TK_ID '[' EXP ']' '[' EXP ']' '=' EXP  */
#line 715 "sintatica.y"
            {
                TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos(yyvsp[-8].label);
                if (!mat.isArray || mat.arraySize2 == 0) yyerror("'" + yyvsp[-8].label + "' não é matriz 2D.");
                if (yyvsp[-6].tipo != "int" || yyvsp[-3].tipo != "int") yyerror("Índices de matriz devem ser inteiros.");
                if (mat.tipoVariavel != pegaTipo(yyvsp[0].tipo)) yyerror("Tipo incompatível ao atribuir em matriz.");
                
                string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
                string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");
                yyval.traducao  = yyvsp[-6].traducao + yyvsp[-3].traducao +
                                 "\t" + tempMult + " = " + yyvsp[-6].label + " * " + to_string(mat.arraySize2) + ";\n" +
                                 "\t" + tempIdx  + " = " + tempMult + " + " + yyvsp[-3].label + ";\n" +
                                 yyvsp[0].traducao +
                                 "\t" + mat.label + "[" + tempIdx + "] = " + yyvsp[0].label + ";\n";
            }
#line 2313 "y.tab.c"
    break;

  case 57: /* ATR: TK_ID '=' TK_ID '[' EXP ']' '[' EXP ']'  */
#line 730 "sintatica.y"
            {
                TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos(yyvsp[-6].label);
                if (!mat.isArray || mat.arraySize2 == 0) yyerror("'" + yyvsp[-6].label + "' não é matriz 2D.");
                TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos(yyvsp[-8].label);
                if (destino.tipoVariavel != mat.tipoVariavel) yyerror("Tipos incompatíveis.");
                if (yyvsp[-4].tipo != "int" || yyvsp[-1].tipo != "int") yyerror("Índices da matriz devem ser inteiros.");
                
                string tempMult = insereTemporariasTabelaSimbolos("temp", "int");
                string tempIdx  = insereTemporariasTabelaSimbolos("temp", "int");
                yyval.traducao  = yyvsp[-4].traducao + yyvsp[-1].traducao +
                                 "\t" + tempMult + " = " + yyvsp[-4].label + " * " + to_string(mat.arraySize2) + ";\n" +
                                 "\t" + tempIdx  + " = " + tempMult + " + " + yyvsp[-1].label + ";\n" +
                                 "\t" + destino.label + " = " + mat.label + "[" + tempIdx + "];\n";
                yyval.label = yyvsp[-8].label;
                yyval.tipo  = destino.tipoVariavel;
            }
#line 2334 "y.tab.c"
    break;

  case 58: /* ATR: TK_ID '=' TK_ID '[' EXP ']'  */
#line 747 "sintatica.y"
            {
                TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos(yyvsp[-3].label);
                if (!vet.isArray || vet.arraySize2 != 0) yyerror("'" + yyvsp[-3].label + "' não é vetor 1D.");
                TIPO_SIMBOLO destino = pegaVariavelTabelaSimbolos(yyvsp[-5].label);
                if (destino.tipoVariavel != vet.tipoVariavel) yyerror("Tipos incompatíveis.");
                if (yyvsp[-1].tipo != "int") yyerror("Índice do vetor deve ser inteiro.");

                yyval.traducao  = yyvsp[-1].traducao + "\t" + yyvsp[-5].label + " = " + vet.label + "[" + yyvsp[-1].label + "];\n";
                yyval.label = destino.label;
                yyval.tipo  = destino.tipoVariavel;
            }
#line 2350 "y.tab.c"
    break;

  case 59: /* EXP: EXP '+' TERMO  */
#line 761 "sintatica.y"
            {   
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;

                // --- LÓGICA DE CONCATENAÇÃO DE STRING (IDÊNTICA EM AMBOS OS CÓDIGOS) ---
                if (yyval.tipo == "string") {
                    yyval.label = insereTemporariasTabelaSimbolos("", "string");
                    string temp_len1 = insereTemporariasTabelaSimbolos("", "int");
                    string temp_len2 = insereTemporariasTabelaSimbolos("", "int");
                    string temp_total_len = insereTemporariasTabelaSimbolos("", "int");
                    stringstream ss;

                    if (yyvsp[-2].tipo == "string_literal") {
                        ss << "\t" << temp_len1 << " = " << tamanho_string(yyvsp[-2].label) - 1 << ";\n";
                    } else {
                        ss << "\t" << temp_len1 << " = meu_strlen(" << yyvsp[-2].label << ");\n";
                    }

                    if (yyvsp[0].tipo == "string_literal") {
                        ss << "\t" << temp_len2 << " = " << tamanho_string(yyvsp[0].label) - 1 << ";\n";
                    } else {
                        ss << "\t" << temp_len2 << " = meu_strlen(" << yyvsp[0].label << ");\n";
                    }

                    ss << "\t" << temp_total_len << " = " << temp_len1 << " + " << temp_len2 << " + 1;\n";
                    ss << "\t" << yyval.label << " = (char*) malloc(" << temp_total_len << ");\n";
                    ss << "\tstrcpy(" << yyval.label << ", " << yyvsp[-2].label << ");\n";
                    ss << "\tstrcat(" << yyval.label << ", " << yyvsp[0].label << ");\n";
                    yyval.traducao += ss.str();
                    variaveisAlocadas.insert(yyval.label);
                } 
                // Lógica original para números
                else {
                    yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                    if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") {
                        string temporario = insereTemporariasTabelaSimbolos("","float");
                        yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                                        "\t" + yyval.label + " = " + temporario + " + " + yyvsp[0].label + ";\n";
                    } else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") {
                        string temporario = insereTemporariasTabelaSimbolos("","float");
                        yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" +
                                        "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + temporario + ";\n";
                    } else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool") {
                        yyerror("[ERRO] Operação '+' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo);
                    } else {
                        yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
                    }
                }
            }
#line 2404 "y.tab.c"
    break;

  case 60: /* EXP: EXP '-' TERMO  */
#line 811 "sintatica.y"
            {   
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
                
                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                                    "\t" + yyval.label + " = " + temporario + " - " + yyvsp[0].label + ";\n"; 
                } else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                                    "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + temporario + ";\n"; 
                } else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool"|| yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") {
                    yyerror("[ERRO] Operação '-' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo);
                } else {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
                }
            }
#line 2428 "y.tab.c"
    break;

  case 61: /* EXP: EXP '>' TERMO  */
#line 831 "sintatica.y"
            {   
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
            }
#line 2439 "y.tab.c"
    break;

  case 62: /* EXP: EXP '<' TERMO  */
#line 838 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
            }
#line 2450 "y.tab.c"
    break;

  case 63: /* EXP: EXP TK_MAIOR_IGUAL TERMO  */
#line 845 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
            }
#line 2461 "y.tab.c"
    break;

  case 64: /* EXP: EXP TK_MENOR_IGUAL TERMO  */
#line 852 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
            }
#line 2472 "y.tab.c"
    break;

  case 65: /* EXP: EXP TK_DIFERENTE TERMO  */
#line 859 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
            }
#line 2483 "y.tab.c"
    break;

  case 66: /* EXP: EXP TK_IGUAL TERMO  */
#line 866 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
            }
#line 2494 "y.tab.c"
    break;

  case 67: /* EXP: EXP TK_E_LOGICO TERMO  */
#line 873 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";   
            }
#line 2505 "y.tab.c"
    break;

  case 68: /* EXP: EXP TK_OU_LOGICO TERMO  */
#line 880 "sintatica.y"
            {
                yyval.tipo = "bool";
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool") yyerror("Operandos inválidos\n");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";   
            }
#line 2516 "y.tab.c"
    break;

  case 69: /* EXP: TERMO  */
#line 887 "sintatica.y"
            { yyval = yyvsp[0]; }
#line 2522 "y.tab.c"
    break;

  case 70: /* TERMO: TERMO '*' POTENCIA  */
#line 891 "sintatica.y"
            {   
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;

                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                                    "\t" + yyval.label + " = " + temporario + " * " + yyvsp[0].label + ";\n"; 
                } else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                                    "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + temporario + ";\n"; 
                } else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") {
                    yyerror("[ERRO] Operação '*' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo);
                } else {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
                }
            }
#line 2546 "y.tab.c"
    break;

  case 71: /* TERMO: TERMO '/' POTENCIA  */
#line 911 "sintatica.y"
            { 
                yyval.tipo = infereTipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;

                if(yyvsp[-2].tipo == "int" && yyvsp[0].tipo == "float") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[-2].label + ";\n" +
                                    "\t" + yyval.label + " = " + temporario + " / " + yyvsp[0].label + ";\n"; 
                } else if(yyvsp[-2].tipo == "float" && yyvsp[0].tipo == "int") {
                    string temporario = insereTemporariasTabelaSimbolos("","float");
                    yyval.traducao += "\t" + temporario + " = (float) " + yyvsp[0].label + ";\n" + 
                                    "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + temporario + ";\n"; 
                } else if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool" || yyvsp[-2].tipo == "string" || yyvsp[0].tipo == "string") {
                    yyerror("[ERRO] Operação '/' inválida entre tipos " + yyvsp[-2].tipo + " e " + yyvsp[0].tipo);
                } else {
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
                }
            }
#line 2570 "y.tab.c"
    break;

  case 72: /* TERMO: POTENCIA  */
#line 931 "sintatica.y"
            { yyval = yyvsp[0]; }
#line 2576 "y.tab.c"
    break;

  case 73: /* FATOR: TK_ID '(' LISTA_ARGS ')'  */
#line 935 "sintatica.y"
            {
                 string nomeFunc = yyvsp[-3].label;
                
                // 1. Verifica se a função existe na tabela de funções (seu código, está correto)
                if (!tabelaFuncoes.count(nomeFunc)) {
                    yyerror("Função '" + nomeFunc + "' não foi declarada.");
                }

                TIPO_FUNCAO infoFunc = tabelaFuncoes[nomeFunc];
                
                // --- BLOCO DE VERIFICAÇÃO RIGOROSA DE TIPOS (CÓDIGO FALTANTE) ---

                // Pega os tipos esperados (da definição da função)
                vector<string> tiposEsperados = infoFunc.tiposParametros;
                // Pega os tipos fornecidos (dos argumentos na chamada)
                vector<string> tiposFornecidos = yyvsp[-1].lista_tipos;

                // 2. Verifica se a QUANTIDADE de argumentos está correta
                if (tiposEsperados.size() != tiposFornecidos.size()) {
                    string erro = "Número incorreto de argumentos para a função '" + nomeFunc + "'. ";
                    erro += "Esperado: " + to_string(tiposEsperados.size()) + ", ";
                    erro += "Fornecido: " + to_string(tiposFornecidos.size()) + ".";
                    yyerror(erro);
                }

                // 3. Verifica se o TIPO de cada argumento está correto
                for (size_t i = 0; i < tiposEsperados.size(); ++i) {
                    string esperado = tiposEsperados[i];
                    string fornecido = tiposFornecidos[i];

                    // Se os tipos não forem EXATAMENTE idênticos, a compilação falha.
                    if (esperado != fornecido) {
                        string erro = "Tipo incompatível para o argumento " + to_string(i+1) + " da função '" + nomeFunc + "'. ";
                        erro += "Esperado: '" + esperado + "', mas foi fornecido: '" + fornecido + "'.";
                        yyerror(erro);
                    }
                }
                // --- FIM DO BLOCO DE VERIFICAÇÃO ---
                
                // Se todas as verificações passaram, a geração de código ocorre normalmente
                string tipoRetorno = infoFunc.tipoRetorno;
                yyval.label = insereTemporariasTabelaSimbolos("", tipoRetorno);
                yyval.tipo = tipoRetorno;
                yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + nomeFunc + "(" + yyvsp[-1].label + ");\n";
            }
#line 2626 "y.tab.c"
    break;

  case 74: /* FATOR: '-' FATOR  */
#line 981 "sintatica.y"
            {
                if (yyvsp[0].tipo != "int" && yyvsp[0].tipo != "float") {
                    yyerror("Operador '-' unario so pode ser aplicado a tipos numericos (int, float).");
                }
                yyval.tipo = yyvsp[0].tipo; 
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = -" + yyvsp[0].label + ";\n";
            }
#line 2639 "y.tab.c"
    break;

  case 75: /* FATOR: TK_INCREMENTO TK_ID  */
#line 990 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[0].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '++' so pode ser aplicado a variaveis numericas.");

                yyval.tipo = var.tipoVariavel;
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_valor_var = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_soma = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_valor_var << " = " << var.label << ";\n";
                ss << "\t" << temp_soma << " = " << temp_valor_var << " + " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_soma << ";\n";
                yyval.traducao = ss.str();
                yyval.label = var.label;
            }
#line 2661 "y.tab.c"
    break;

  case 76: /* FATOR: TK_ID TK_INCREMENTO  */
#line 1008 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[-1].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '++' so pode ser aplicado a variaveis numericas.");

                yyval.tipo = var.tipoVariavel;
                string temp_retorno = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_soma = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_retorno << " = " << var.label << ";\n";
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_soma << " = " << temp_retorno << " + " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_soma << ";\n";
                yyval.traducao = ss.str();
                yyval.label = temp_retorno;
            }
#line 2683 "y.tab.c"
    break;

  case 77: /* FATOR: TK_DECREMENTO TK_ID  */
#line 1026 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[0].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '--' so pode ser aplicado a variaveis numericas.");
                
                yyval.tipo = var.tipoVariavel;
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_valor_var = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_sub = insereTemporariasTabelaSimbolos("", var.tipoVariavel);

                stringstream ss;
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_valor_var << " = " << var.label << ";\n";
                ss << "\t" << temp_sub << " = " << temp_valor_var << " - " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_sub << ";\n";
                yyval.traducao = ss.str();
                yyval.label = var.label;
            }
#line 2705 "y.tab.c"
    break;

  case 78: /* FATOR: TK_ID TK_DECREMENTO  */
#line 1044 "sintatica.y"
            {
                TIPO_SIMBOLO var = pegaVariavelTabelaSimbolos(yyvsp[-1].label);
                if (var.tipoVariavel != "int" && var.tipoVariavel != "float") yyerror("Operador '--' so pode ser aplicado a variaveis numericas.");

                yyval.tipo = var.tipoVariavel;
                string temp_retorno = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_um = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                string temp_sub = insereTemporariasTabelaSimbolos("", var.tipoVariavel);
                
                stringstream ss;
                ss << "\t" << temp_retorno << " = " << var.label << ";\n";
                ss << "\t" << temp_um << " = 1;\n";
                ss << "\t" << temp_sub << " = " << temp_retorno << " - " << temp_um << ";\n";
                ss << "\t" << var.label << " = " << temp_sub << ";\n";
                yyval.traducao = ss.str();
                yyval.label = temp_retorno;
            }
#line 2727 "y.tab.c"
    break;

  case 79: /* FATOR: '(' EXP ')'  */
#line 1062 "sintatica.y"
            { yyval = yyvsp[-1]; }
#line 2733 "y.tab.c"
    break;

  case 80: /* FATOR: '(' TK_TIPO ')' FATOR  */
#line 1064 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", yyvsp[-2].label);
                yyval.tipo = yyvsp[-2].label;
                yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (" + pegaTipo(yyvsp[-2].label) + ") " + yyvsp[0].label + ";\n";
            }
#line 2743 "y.tab.c"
    break;

  case 81: /* FATOR: TK_ID  */
#line 1070 "sintatica.y"
            {
                if (!verificaTabelaSimbolos(yyvsp[0].label)) {
                    yyerror("Variável não declarada: '" + yyvsp[0].label + "'");
                }
                TIPO_SIMBOLO simbolo = pegaVariavelTabelaSimbolos(yyvsp[0].label);

                if (simbolo.isParam) {
                    yyval.label = simbolo.nomeVariavel;
                } else {
                    yyval.label = simbolo.label;
                }

                yyval.tipo = simbolo.tipoVariavel;
                yyval.traducao = "";

                if (simbolo.isArray) {
                    yyerror("Acesso inválido: vetor/matriz '" + simbolo.nomeVariavel + "' usado sem índice.");
                }
            }
#line 2767 "y.tab.c"
    break;

  case 82: /* FATOR: TK_NEGACAO TK_ID  */
#line 1090 "sintatica.y"
            {
                yyval.tipo = "bool";
                TIPO_SIMBOLO temp = pegaVariavelTabelaSimbolos(yyvsp[0].label);
                if("bool" != temp.tipoVariavel) yyerror("Operação de negação inválida para o tipo da variável.");
                yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);
                yyval.traducao = "\t" + yyval.label + " = !" + temp.label + ";\n";
            }
#line 2779 "y.tab.c"
    break;

  case 83: /* FATOR: TK_INT  */
#line 1098 "sintatica.y"
            {   
                yyval.label = insereTemporariasTabelaSimbolos("", "int");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
                yyval.tipo = "int"; 
            }
#line 2789 "y.tab.c"
    break;

  case 84: /* FATOR: TK_FLOAT  */
#line 1104 "sintatica.y"
            {   
                //cout << "testnado";
                yyval.label = insereTemporariasTabelaSimbolos("", "float");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n"; 
                yyval.tipo = "float"; 
            }
#line 2800 "y.tab.c"
    break;

  case 85: /* FATOR: TK_BOOLEAN  */
#line 1111 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "bool");
                string valor = pegaBooleano(yyvsp[0].label);
                if(valor == "error") yyerror("Valor booleano inválido!");
                yyval.traducao = "\t" + yyval.label + " = " + valor + ";\n";
                yyval.tipo = "bool"; 
            }
#line 2812 "y.tab.c"
    break;

  case 86: /* FATOR: TK_CHAR  */
#line 1119 "sintatica.y"
            {
                yyval.label = insereTemporariasTabelaSimbolos("", "char");
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
                yyval.tipo = "char"; 
            }
#line 2822 "y.tab.c"
    break;

  case 87: /* FATOR: TK_STRING  */
#line 1126 "sintatica.y"
            {
                // Apenas passa o literal (ex: "meu texto") para cima na árvore
                // e marca o tipo como 'string_literal' para que outras regras saibam
                // que não se trata de uma variável, mas de um valor constante.
                yyval.label = yyvsp[0].label;
                yyval.traducao = yyvsp[0].traducao;
                yyval.tipo = "string_literal"; 
            }
#line 2835 "y.tab.c"
    break;

  case 88: /* FATOR: TK_ID '[' EXP ']'  */
#line 1134 "sintatica.y"
                                {
                TIPO_SIMBOLO vet = pegaVariavelTabelaSimbolos(yyvsp[-3].label);
                if (!vet.isArray || vet.arraySize2 != 0) yyerror("'" + yyvsp[-3].label + "' não é vetor 1D.");
                if (yyvsp[-1].tipo != "int") yyerror("Índice do vetor deve ser inteiro.");

                string temp = insereTemporariasTabelaSimbolos("", vet.tipoVariavel);
                yyval.traducao = yyvsp[-1].traducao + "\t" + temp + " = " + vet.label + "[" + yyvsp[-1].label + "];\n";
                yyval.label = temp;
                yyval.tipo = vet.tipoVariavel;
            }
#line 2850 "y.tab.c"
    break;

  case 89: /* FATOR: TK_ID '[' EXP ']' '[' EXP ']'  */
#line 1144 "sintatica.y"
                                            {
                TIPO_SIMBOLO mat = pegaVariavelTabelaSimbolos(yyvsp[-6].label);
                if (!mat.isArray || mat.arraySize2 == 0) yyerror("'" + yyvsp[-6].label + "' não é matriz 2D.");
                if (yyvsp[-4].tipo != "int" || yyvsp[-1].tipo != "int") yyerror("Índices da matriz devem ser inteiros.");

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
#line 2870 "y.tab.c"
    break;

  case 90: /* LISTA_ARGS: EXP ',' LISTA_ARGS  */
#line 1163 "sintatica.y"
        { 
            yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao; 
            yyval.label = yyvsp[-2].label + ", " + yyvsp[0].label;

            // Constrói a lista de tipos dos argumentos fornecidos
            yyval.lista_tipos.push_back(pegaTipo(yyvsp[-2].tipo));
            yyval.lista_tipos.insert(yyval.lista_tipos.end(), yyvsp[0].lista_tipos.begin(), yyvsp[0].lista_tipos.end());
             // --- DEBUG ---
           
        }
#line 2885 "y.tab.c"
    break;

  case 91: /* LISTA_ARGS: EXP  */
#line 1174 "sintatica.y"
        { 
            yyval = yyvsp[0]; 
            // Garante que a lista de tipos seja criada para o único argFumento
            yyval.lista_tipos.push_back(pegaTipo(yyvsp[0].tipo));
            // --- DEBUG ---
           
        }
#line 2897 "y.tab.c"
    break;

  case 92: /* LISTA_ARGS: %empty  */
#line 1182 "sintatica.y"
        {
            yyval.traducao = "";
            yyval.label = "";
            // A lista de tipos fica intencionalmente vazia
        }
#line 2907 "y.tab.c"
    break;

  case 93: /* POTENCIA: FATOR TK_POTENCIA POTENCIA  */
#line 1191 "sintatica.y"
        {
            // Verificação: Nossa função helper espera um expoente inteiro.
            if (yyvsp[0].tipo != "int") {
                yyerror("Potenciação com expoente não-inteiro não é suportada.");
            }

            string base = yyvsp[-2].label;
            string expoente = yyvsp[0].label;

            // Junta o código de preparação da base e do expoente.
            string traducao_preparacao = yyvsp[-2].traducao + yyvsp[0].traducao;

            // A função helper espera uma base float, então convertemos se for int.
            if (yyvsp[-2].tipo == "int") {
                string temp_base = insereTemporariasTabelaSimbolos("", "float");
                traducao_preparacao += "\t" + temp_base + " = (float) " + base + ";\n";
                base = temp_base;
            }

            yyval.tipo = "float"; // Nossa função helper sempre retorna float.
            yyval.label = insereTemporariasTabelaSimbolos("", yyval.tipo);

            // A tradução agora é apenas uma chamada para a função helper
            yyval.traducao = traducao_preparacao +
                         "\t" + yyval.label + " = potencia_helper(" + base + ", " + expoente + ");\n";
        }
#line 2938 "y.tab.c"
    break;

  case 94: /* POTENCIA: FATOR  */
#line 1218 "sintatica.y"
        { yyval = yyvsp[0]; }
#line 2944 "y.tab.c"
    break;


#line 2948 "y.tab.c"

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

#line 1220 "sintatica.y"


#include "lex.yy.c"

int yyparse();

// --- FUNÇÃO `tamanho_string` SUBSTITUÍDA PELA DO SEGUNDO CÓDIGO ---
int tamanho_string(string texto){ 
    // O texto vem com aspas, ex: "abc". O tamanho é 5 ('"', 'a', 'b', 'c', '"').
    // O tamanho real da string é 3 ('a', 'b', 'c').
    // Precisamos alocar 4 bytes (para 'a', 'b', 'c', '\0').
    // Então, o tamanho do texto do token - 2 (aspas) + 1 (null terminator) = tamanho - 1.
    return texto.length() - 1;
}

string novo_rotulo() {
    return "L" + to_string(contador_rotulos++);
}

string geraNomeTemp(string tipo)
{
    qntdVariaveisTemp++;
    string label = "T" + to_string(qntdVariaveisTemp);
    string tipo_real = "null";

    if(tipo == "nmr" || tipo == "int") tipo_real = "int";
    else if(tipo == "ncv" || tipo == "float") tipo_real = "float";
    else if(tipo == "pp" || tipo == "bool") tipo_real = "int"; // Booleanos são traduzidos para int
    else if(tipo == "letra" || tipo == "char") tipo_real = "char";
    else if(tipo == "falada" || tipo == "string" || tipo == "string_literal" || tipo == "char_array") tipo_real = "string";
    
    temporarias.insert({label, tipo_real});
    return label; 
}

string insereTemporariasTabelaSimbolos(string nome, string tipo)
{   
    if (pilhaTabelasSimbolos.empty()) {
        yyerror("Erro de lógica: Tentou gerar temporária sem um escopo ativo.");
        return "";
    }
    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();
    
    TIPO_SIMBOLO temp;
    temp.nomeVariavel = geraNomeTemp(tipo);
    temp.tipoVariavel = pegaTipo(tipo);
    temp.label = temp.nomeVariavel;

    escopoAtual[temp.nomeVariavel] = temp;
    todosOsSimbolos.push_back(temp);
    if(debug) cout << "[DEBUG] Inserindo TEMPORARIA na tabela: " << temp.nomeVariavel << " (Tipo: " << temp.tipoVariavel << ")\n";
    return temp.label;
}

void insereFixasTabelaSimbolos(string nome, string tipo, bool ehArray, int tamanhoArray, int tamanhoArray2, bool ehParam)
{   
    if (pilhaTabelasSimbolos.empty()) {
        yyerror("Erro de lógica: Tentou declarar variável sem um escopo ativo.");
        return;
    }

    map<string, TIPO_SIMBOLO>& escopoAtual = pilhaTabelasSimbolos.back();

    if (escopoAtual.count(nome)) {
        yyerror("Erro: Variável '" + nome + "' já declarada neste escopo.");
        return;
    }

    if (debug) cout << "[DEBUG] Inserindo FIXA na tabela: " << nome << " (Tipo: " << tipo << ")\n";

    TIPO_SIMBOLO temp;
    temp.nomeVariavel = nome;
    temp.tipoVariavel = pegaTipo(tipo);
    temp.label = geraNomeTemp(tipo);
    temp.isArray = ehArray;
    temp.arraySize = tamanhoArray;
    temp.arraySize2 = tamanhoArray2;
    temp.isParam = ehParam; // Campo preservado do primeiro código

    escopoAtual[nome] = temp;
    todosOsSimbolos.push_back(temp); // <-- ADICIONE ESTA LINHA
}

bool verificaTabelaSimbolos(string nome)
{
    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i) {
        if (pilhaTabelasSimbolos[i].count(nome)) { 
            return true; 
        }
    }
    return false;
}

TIPO_SIMBOLO pegaVariavelTabelaSimbolos(string nome)
{
    for (int i = pilhaTabelasSimbolos.size() - 1; i >= 0; --i) {
        if (pilhaTabelasSimbolos[i].count(nome)) {
            return pilhaTabelasSimbolos[i][nome];
        }
    }
    yyerror("Variável '" + nome + "' não encontrada.");
    return {}; // Retorno para evitar warnings
}

void printTabelaSimbolos()
{
    if (!debug) return;
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

string pegaTipo(string tipo) 
{
    if(tipo == "nmr" || tipo == "int") return "int";
    if(tipo == "ncv" || tipo == "float") return "float";
    if(tipo == "letra" || tipo == "char") return "char";
    if(tipo == "pp" || tipo == "bool") return "bool";
    if(tipo == "falada" || tipo == "string" || tipo == "string_literal" || tipo == "char_array") return "string";
    return "null";
}

// --- FUNÇÃO `infereTipo` SUBSTITUÍDA PELA DO SEGUNDO CÓDIGO ---
string infereTipo(string tipo1, string tipo2)
{
    if(debug) cout << "[DEBUG] Inferindo tipo entre: " << tipo1 << " e " << tipo2 << endl;

    string t1 = pegaTipo(tipo1);
    string t2 = pegaTipo(tipo2);

    // Se ambos são strings, o resultado é uma string
    if (t1 == "string" && t2 == "string") {
        return "string";
    }

    // Lógica para números (pode ser ajustada para ser mais robusta)
    if(t1 == "float" || t2 == "float") return "float";
    if(t1 == "int" && t2 == "int") return "int";
    
    yyerror("Operação com tipos incompatíveis: " + tipo1 + " e " + tipo2);
    return "null"; // Retorno de erro
}

string pegaBooleano(string valor)
{
    if(valor == "reto") return "true";
    if(valor == "torto") return "false";
    return "error";
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
    cout << "Erro na linha " << yylinha << ": "<< MSG << endl;
    exit (0);
}
