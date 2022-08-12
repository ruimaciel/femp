/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_MSH_YY_SRC_MSH_TAB_H_INCLUDED
#define YY_MSH_YY_SRC_MSH_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef MSH_YYDEBUG
#if defined YYDEBUG
#if YYDEBUG
#define MSH_YYDEBUG 1
#else
#define MSH_YYDEBUG 0
#endif
#else /* ! defined YYDEBUG */
#define MSH_YYDEBUG 1
#endif /* ! defined YYDEBUG */
#endif /* ! defined MSH_YYDEBUG */
#if MSH_YYDEBUG
extern int msh_yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/msh.y" /* yacc.c:1909  */

// HERE
#include <libfemp/Model.h++>

#line 57 "src/msh.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef MSH_YYTOKENTYPE
#define MSH_YYTOKENTYPE
enum msh_yytokentype {
  FLOAT = 258,
  INTEGER = 259,
  TEXT = 260,
  LABEL_OPEN = 261,
  LABEL_CLOSE = 262,
  LABEL_OPEN_ELEMENTS = 263,
  LABEL_CLOSE_ELEMENTS = 264,
  MESH_FORMAT = 265,
  NODES = 266,
  PARAMETRIC_NODES = 267,
  PHYSICAL_NAMES = 268,
  ELEMENTS = 269,
  EL_LINE2 = 270,
  EL_TRIANGLE3 = 271,
  EL_QUADRANGLE4 = 272,
  EL_TETRAHEDRON4 = 273,
  EL_HEXAHEDRON8 = 274,
  EL_PRISM6 = 275,
  EL_PYRAMID5 = 276,
  EL_LINE3 = 277,
  EL_TRIANGLE6 = 278,
  EL_QUADRANGLE9 = 279,
  EL_TETRAHEDRON10 = 280,
  EL_HEXAHEDRON27 = 281,
  EL_PRISM18 = 282,
  EL_PYRAMID14 = 283,
  EL_POINT = 284,
  EL_QUADRANGLE8 = 285,
  EL_HEXAHEDRON20 = 286,
  EL_PRISM15 = 287,
  EL_PYRAMID13 = 288,
  EL_ITRIANGLE9 = 289,
  EL_TRIANGLE10 = 290,
  EL_ITRIANGLE12 = 291,
  EL_TRIANGLE15 = 292,
  EL_ITRIANGLE15 = 293,
  EL_TRIANGLE21 = 294,
  EL_EDGE4 = 295,
  EL_EDGE5 = 296,
  EL_EDGE6 = 297,
  EL_TETRAHEDRON20 = 298,
  EL_TETRAHEDRON35 = 299,
  EL_TETRAHEDRON56 = 300,
  TAG0 = 301,
  TAG1 = 302,
  TAG2 = 303,
  TAG3 = 304,
  OTHER = 305
};
#endif

/* Value type.  */
#if !defined MSH_YYSTYPE && !defined MSH_YYSTYPE_IS_DECLARED

union MSH_YYSTYPE {
#line 31 "src/msh.y" /* yacc.c:1909  */

  double real;
  int integer;
  char *text;

#line 126 "src/msh.tab.h" /* yacc.c:1909  */
};

typedef union MSH_YYSTYPE MSH_YYSTYPE;
#define MSH_YYSTYPE_IS_TRIVIAL 1
#define MSH_YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if !defined MSH_YYLTYPE && !defined MSH_YYLTYPE_IS_DECLARED
typedef struct MSH_YYLTYPE MSH_YYLTYPE;
struct MSH_YYLTYPE {
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
#define MSH_YYLTYPE_IS_DECLARED 1
#define MSH_YYLTYPE_IS_TRIVIAL 1
#endif

extern MSH_YYSTYPE msh_yylval;
extern MSH_YYLTYPE msh_yylloc;
int msh_yyparse(fem::Model &model);

#endif /* !YY_MSH_YY_SRC_MSH_TAB_H_INCLUDED  */
