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
