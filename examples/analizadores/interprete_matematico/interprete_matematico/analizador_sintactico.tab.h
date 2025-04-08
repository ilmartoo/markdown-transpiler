/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_ANALIZADOR_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_ANALIZADOR_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 40 "bison/analizador_sintactico.y"

	#include "analizador_sintactico.h"
	#include "analizador_lexico.h"
	#include "boolean.h"
	#include "componente_lexico.h"

#line 56 "analizador_sintactico.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMERICO = 258,                /* NUMERICO  */
    FUNCION = 259,                 /* FUNCION  */
    IDENTIFICADOR = 260,           /* IDENTIFICADOR  */
    CONSTANTE = 261,               /* CONSTANTE  */
    STRING = 262,                  /* STRING  */
    FP_NARGS = 263,                /* FP_NARGS  */
    FP_ONEARG = 264,               /* FP_ONEARG  */
    FP_EXPARG = 265,               /* FP_EXPARG  */
    END_COMMAND_FILE = 266,        /* END_COMMAND_FILE  */
    PLUS_EQ = 267,                 /* PLUS_EQ  */
    MINUS_EQ = 268,                /* MINUS_EQ  */
    MULT_EQ = 269,                 /* MULT_EQ  */
    DIV_EQ = 270,                  /* DIV_EQ  */
    EXP_EQ = 271,                  /* EXP_EQ  */
    MOD_EQ = 272,                  /* MOD_EQ  */
    NEG = 273                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "bison/analizador_sintactico.y"

	CompLexico *cmplx;
	double num;
	char *str;

#line 97 "analizador_sintactico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADOR_SINTACTICO_TAB_H_INCLUDED  */
