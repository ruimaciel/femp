/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         MSH_YYSTYPE
#define YYLTYPE         MSH_YYLTYPE
/* Substitute the variable and function names.  */
#define yyparse         msh_yyparse
#define yylex           msh_yylex
#define yyerror         msh_yyerror
#define yydebug         msh_yydebug
#define yynerrs         msh_yynerrs

#define yylval          msh_yylval
#define yychar          msh_yychar
#define yylloc          msh_yylloc

/* Copy the first part of user declarations.  */
#line 6 "src/msh.y" /* yacc.c:339  */

#define YY_HEADER_EXPORT_START_CONDITIONS

#include <stdio.h>
#include "lex.msh_yy.h" /* for the lexer's start states */

#include <vector>
#include <QString>


#include <libfemp/parsers/fem_msh.h++>



std::vector<size_t> temp;	/*temporary node vector*/
size_t ti;

void yyerror(fem::Model &model, char const *s)
{
	fflush(stderr);
	fprintf(stderr,"error at line %d: %s\n", msh_yylineno, s);
}


#line 102 "src/msh.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "msh.tab.h".  */
#ifndef YY_MSH_YY_SRC_MSH_TAB_H_INCLUDED
# define YY_MSH_YY_SRC_MSH_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef MSH_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define MSH_YYDEBUG 1
#  else
#   define MSH_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define MSH_YYDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined MSH_YYDEBUG */
#if MSH_YYDEBUG
extern int msh_yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/msh.y" /* yacc.c:355  */

//HERE
#include <libfemp/Model.h++>

#line 145 "src/msh.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef MSH_YYTOKENTYPE
# define MSH_YYTOKENTYPE
  enum msh_yytokentype
  {
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
#if ! defined MSH_YYSTYPE && ! defined MSH_YYSTYPE_IS_DECLARED

union MSH_YYSTYPE
{
#line 31 "src/msh.y" /* yacc.c:355  */

	double 	real;
	int	integer;
	char *	text;

#line 214 "src/msh.tab.c" /* yacc.c:355  */
};

typedef union MSH_YYSTYPE MSH_YYSTYPE;
# define MSH_YYSTYPE_IS_TRIVIAL 1
# define MSH_YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined MSH_YYLTYPE && ! defined MSH_YYLTYPE_IS_DECLARED
typedef struct MSH_YYLTYPE MSH_YYLTYPE;
struct MSH_YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define MSH_YYLTYPE_IS_DECLARED 1
# define MSH_YYLTYPE_IS_TRIVIAL 1
#endif


extern MSH_YYSTYPE msh_yylval;
extern MSH_YYLTYPE msh_yylloc;
int msh_yyparse (fem::Model &model);

#endif /* !YY_MSH_YY_SRC_MSH_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "src/msh.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined MSH_YYLTYPE_IS_TRIVIAL && MSH_YYLTYPE_IS_TRIVIAL \
             && defined MSH_YYSTYPE_IS_TRIVIAL && MSH_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  580

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if MSH_YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    93,    94,    95,    98,   101,   104,
     108,   111,   114,   117,   122,   123,   126,   130,   131,   133,
     136,   139,   142,   146,   147,   150,   154,   157,   160,   163,
     166,   169,   172,   175,   178,   183,   184,   187,   194,   201,
     208,   213,   219,   225,   230,   237,   245,   253,   259,   269,
     277,   284,   291,   299,   307,   314,   321,   329,   337,   346,
     355,   364,   375,   382,   389,   397,   405,   416,   434,   435,
     436,   437,   440
};
#endif

#if MSH_YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT", "INTEGER", "TEXT", "LABEL_OPEN",
  "LABEL_CLOSE", "LABEL_OPEN_ELEMENTS", "LABEL_CLOSE_ELEMENTS",
  "MESH_FORMAT", "NODES", "PARAMETRIC_NODES", "PHYSICAL_NAMES", "ELEMENTS",
  "EL_LINE2", "EL_TRIANGLE3", "EL_QUADRANGLE4", "EL_TETRAHEDRON4",
  "EL_HEXAHEDRON8", "EL_PRISM6", "EL_PYRAMID5", "EL_LINE3", "EL_TRIANGLE6",
  "EL_QUADRANGLE9", "EL_TETRAHEDRON10", "EL_HEXAHEDRON27", "EL_PRISM18",
  "EL_PYRAMID14", "EL_POINT", "EL_QUADRANGLE8", "EL_HEXAHEDRON20",
  "EL_PRISM15", "EL_PYRAMID13", "EL_ITRIANGLE9", "EL_TRIANGLE10",
  "EL_ITRIANGLE12", "EL_TRIANGLE15", "EL_ITRIANGLE15", "EL_TRIANGLE21",
  "EL_EDGE4", "EL_EDGE5", "EL_EDGE6", "EL_TETRAHEDRON20",
  "EL_TETRAHEDRON35", "EL_TETRAHEDRON56", "TAG0", "TAG1", "TAG2", "TAG3",
  "OTHER", "'\\n'", "$accept", "document", "HeaderField", "StartHeader",
  "HeaderValues", "EndHeader", "NodesField", "StartNodes",
  "NodesLinesCount", "NodesLines", "NodesLine", "NUMBER", "EndNodes",
  "ParametricNodesField", "StartParametricNodes",
  "ParametricNodesLinesCount", "ParametricNodesLines",
  "ParametricNodesLine", "EndParametricNodes", "PhysicalNamesField",
  "StartPhysicalNames", "PhysicalNamesLinesCount", "PhysicalNamesLines",
  "EndPhysicalNames", "ElementsField", "StartElements",
  "ElementsLinesCount", "ElementsLines", "ElementLine", "Tags",
  "EndElements", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    10
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,     0,    24,    19,    13,   -25,   -44,     2,    20,    23,
      20,    25,    26,    27,   -44,   -44,    28,    13,   -44,   -21,
     -18,   -15,   -14,   -44,    30,   -13,   -44,   -44,   -12,   -44,
       7,    20,    20,   -10,    38,    33,   -44,    13,   -44,   -44,
     -44,   -44,    -6,   -44,   -44,     4,   -44,     5,   -44,   -44,
     -44,    42,    40,    -3,    -1,   -44,    -2,    13,    41,   -44,
     -44,    13,    37,   -44,   -44,    46,    43,   -44,   -44,   -44,
      45,     3,   -44,   -44,    13,    77,    13,    78,    79,    80,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -44,    13,   -44,    13,   -44,   -44,   -44,   -44,    49,
      51,    54,    87,    88,    89,    90,    92,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   107,   155,   -44,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   125,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   -44,
     189,   -44,   190,   154,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   202,   203,   204,   -44,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   201,   -44,   -44,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   249,   250,   -44,   -44,   248,   251,
     252,   253,   254,   -44,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   269,   270,   271,
     268,   272,   273,   275,   276,   277,   -44,   -44,   278,   279,
     274,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   296,   -44,   295,   297,
     299,   300,   301,   302,   298,   -44,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   316,   317,
     318,   319,   -44,   315,   320,   322,   323,   324,   -44,   -44,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   -44,   340,   341,   343,   321,
     344,   346,   347,   348,   349,   342,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   363,   -44,   345,
     364,   365,   366,   367,   -44,   369,   370,   371,   350,   372,
     373,   374,   375,   376,   377,   378,   379,   -44,   362,   380,
     381,   382,   383,   384,   385,   -44,   368,   386,   387,   388,
     390,   391,   393,   394,   -44,   395,   396,   398,   399,   400,
     401,   -44,   402,   403,   404,   405,   406,   407,   408,   410,
     411,   412,   413,   414,   416,   389,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   392,   -44,   428,
     429,   430,   431,   432,   433,   434,   435,   397,   437,   438,
     -44,   440,   441,   442,   443,   445,   446,   447,   448,   -44,
     449,   409,   415,   436,   450,   451,   452,   453,   454,   455,
     457,   -44,   -44,   -44,   458,   459,   460,   461,   463,   464,
     465,   466,   467,   468,   469,   470,   439,   471,   472,   473,
     474,   475,   476,   -44,   477,   478,   479,   480,   481,   482,
     444,   484,   456,   485,   487,   488,   -44,   462,   -44,   489,
     490,   492,   -44,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   504,   505,   506,   507,   483,   508,   510,
     -44,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   486,   525,   -44,   526,   527,
     528,   529,   531,   532,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   503,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,    17,    18,     0,     0,     8,     0,
       0,     0,     0,     3,     0,     0,    14,     4,     0,    23,
       0,     0,     0,     0,     0,     0,     7,     0,    12,    21,
      28,    33,     0,    35,    13,     0,    22,     0,     5,     6,
      29,     0,     0,     0,     0,    34,     0,     0,     0,    15,
      11,     0,     0,    24,    20,     0,     0,    27,    10,     9,
       0,     0,    36,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,    19,     0,    26,    30,    31,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    38,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,    42,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,    65,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   -44,   -44,   -44,   -44,   548,   -44,   -44,   -44,
     -44,   -17,   -44,   549,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    -9,   -44,   -44,   -44,   -44,    17,
     -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    16,    36,     8,     9,    26,    45,
      59,    17,    60,    10,    11,    29,    47,    63,    64,    12,
      13,    34,    52,    67,    23,    24,    43,    56,    72,   122,
      73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      37,    27,    70,   118,   119,   120,   121,    71,    57,    61,
       5,    58,    62,    19,    20,    21,    14,    15,    19,    20,
      54,     1,    48,    49,     6,     7,    18,    25,    22,    28,
      38,    33,    30,    39,    42,    35,    40,    41,    44,    46,
      74,    50,    51,    53,    76,    55,    65,    66,    68,    77,
      69,    78,    75,   155,   111,   156,    79,   112,   157,   114,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   158,   159,   160,   161,   153,   162,   154,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   113,   115,
     116,   117,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   226,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,     0,   258,   259,   260,   261,
     262,     0,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   256,   284,   285,     0,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   257,   304,   305,   306,   308,   309,   263,   310,
     311,   312,   313,   314,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   286,
     331,   333,   287,   334,   335,   336,   337,     0,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   307,
     351,   352,   353,   354,   356,   315,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   332,   377,   379,   338,
     380,   381,   382,   383,   339,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   355,   396,   398,   399,
     400,   401,   378,   402,   403,   404,   406,   407,   408,   409,
     410,   411,   412,   413,   415,   416,   417,   418,   419,   420,
     422,   423,   424,   384,   425,   426,   397,   427,   428,   429,
     430,   405,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   414,   442,   443,   444,   445,   446,   421,
     447,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   461,   462,   463,   464,   465,   466,   467,   468,
     448,   470,   471,   460,   472,   473,   474,   475,   469,   476,
     477,   478,   479,   480,   484,   485,   486,   487,   488,   489,
     481,   490,   491,   492,   493,   494,   482,   495,   496,   497,
     498,   499,   500,   501,   502,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   483,   517,   519,
     503,   520,   521,   523,   524,   516,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   518,   536,   537,
     538,   539,   541,   522,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   558,
     559,   560,   561,   562,   540,   563,   564,   557,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,     0,     0,   579,     0,     0,     0,     0,     0,
      31,    32
};

static const yytype_int8 yycheck[] =
{
      17,    10,     4,    46,    47,    48,    49,     9,     4,     4,
      10,     7,     7,    11,    12,    13,     3,     4,    11,    12,
      37,     6,    31,    32,     0,     6,    51,     4,     8,     4,
      51,     4,     6,    51,     4,     7,    51,    51,    51,    51,
      57,    51,     4,    10,    61,    51,     4,     7,    51,    12,
      51,     5,    11,     4,    51,     4,    13,    74,     4,    76,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     4,     4,     4,     4,   112,     4,   114,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    51,    51,
      51,    51,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,    51,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    51,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    -1,     4,     4,     4,     4,
       4,    -1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    51,     4,     4,    -1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    51,     4,     4,     4,     4,     4,    51,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    51,
       4,     4,    51,     4,     4,     4,     4,    -1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    51,
       4,     4,     4,     4,     4,    51,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,     4,     4,    51,
       4,     4,     4,     4,    51,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,     4,     4,     4,
       4,     4,    51,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    51,     4,     4,    51,     4,     4,     4,
       4,    51,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    51,     4,     4,     4,     4,     4,    51,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      51,     4,     4,    51,     4,     4,     4,     4,    51,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      51,     4,     4,     4,     4,     4,    51,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    51,     4,     4,
      51,     4,     4,     4,     4,    51,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    51,     4,     4,
       4,     4,     4,    51,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,    51,     4,     4,    51,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      12,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    53,    54,    55,    10,     0,     6,    58,    59,
      65,    66,    71,    72,     3,     4,    56,    63,    51,    11,
      12,    13,     8,    76,    77,     4,    60,    76,     4,    67,
       6,    58,    65,     4,    73,     7,    57,    63,    51,    51,
      51,    51,     4,    78,    51,    61,    51,    68,    76,    76,
      51,     4,    74,    10,    63,    51,    79,     4,     7,    62,
      64,     4,     7,    69,    70,     4,     7,    75,    51,    51,
       4,     9,    80,    82,    63,    11,    63,    12,     5,    13,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    51,    63,    51,    63,    51,    51,    51,    46,    47,
      48,    49,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    63,    63,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    51,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    51,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,    51,     4,     4,
       4,     4,     4,    51,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,    51,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    51,     4,     4,
       4,     4,     4,     4,     4,    51,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,    51,     4,     4,     4,     4,     4,    51,    51,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,    51,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,    51,     4,
       4,     4,     4,     4,    51,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    51,     4,     4,
       4,     4,     4,     4,     4,    51,     4,     4,     4,     4,
       4,     4,     4,     4,    51,     4,     4,     4,     4,     4,
       4,    51,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,    51,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      51,     4,     4,     4,     4,     4,     4,     4,     4,    51,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,    51,    51,    51,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    51,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    51,     4,    51,     4,
       4,     4,    51,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      51,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    51,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    61,    62,    63,    63,    64,
      65,    66,    67,    68,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     3,     4,     4,     3,     3,     4,
       3,     4,     3,     2,     0,     2,     5,     1,     1,     3,
       4,     3,     2,     0,     2,     7,     3,     4,     3,     2,
       4,     3,     4,     2,     2,     0,     2,     6,     7,     8,
       8,    12,    10,     9,     7,    10,    13,    14,    31,    22,
      18,     5,    12,    24,    19,    17,    13,    14,    16,    19,
      19,    25,     8,     9,    10,    24,    39,    60,     1,     2,
       3,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (model, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if MSH_YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined MSH_YYLTYPE_IS_TRIVIAL && MSH_YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, model); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, fem::Model &model)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (model);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, fem::Model &model)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, model);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, fem::Model &model)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , model);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, model); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !MSH_YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !MSH_YYDEBUG */


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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, fem::Model &model)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (model);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined MSH_YYLTYPE_IS_TRIVIAL && MSH_YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (fem::Model &model)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 105 "src/msh.y" /* yacc.c:1646  */
    { /*TODO check version */ }
#line 1746 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "src/msh.y" /* yacc.c:1646  */
    { // fem_model_increase_node_reserve(model,$1);
	}
#line 1753 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "src/msh.y" /* yacc.c:1646  */
    { model.setNode((yyvsp[-4].integer), (yyvsp[-3].real), (yyvsp[-2].real), (yyvsp[-1].real)); }
#line 1759 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 130 "src/msh.y" /* yacc.c:1646  */
    {(yyval.real) = (yyvsp[0].real);}
#line 1765 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "src/msh.y" /* yacc.c:1646  */
    {(yyval.real) = (yyvsp[0].integer);}
#line 1771 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "src/msh.y" /* yacc.c:1646  */
    { /*TODO implement this */ }
#line 1777 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "src/msh.y" /* yacc.c:1646  */
    { /*TODO finish this: ./Geo/MVertex.cpp:74 */ }
#line 1783 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 160 "src/msh.y" /* yacc.c:1646  */
    { /*TODO finish this */ }
#line 1789 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "src/msh.y" /* yacc.c:1646  */
    {/*TODO finish this */}
#line 1795 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 166 "src/msh.y" /* yacc.c:1646  */
    {/*TODO finish this*/}
#line 1801 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 169 "src/msh.y" /* yacc.c:1646  */
    {/*TODO finish this*/}
#line 1807 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 179 "src/msh.y" /* yacc.c:1646  */
    { //fem_model_increase_element_reserve(model, $1);
	}
#line 1814 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 187 "src/msh.y" /* yacc.c:1646  */
    { 
	/*
	temp.clear(); temp.reserve(2);
	temp.push_back($4), temp.push_back($5); 
	model.pushElement(fem::Element::FE_LINE2,temp);
	*/
	}
#line 1826 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(3);
	temp.push_back($4), temp.push_back($5), temp.push_back($6); 
	model.pushElement(fem::Element::FE_TRIANGLE3,temp);
	*/
	}
#line 1838 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 201 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(4);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7);
	model.pushElement(fem::Element::FE_QUADRANGLE4,temp);
	*/
	}
#line 1850 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 208 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(4);
	temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_TETRAHEDRON4, temp); 
	}
#line 1860 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 213 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(8);
	temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer));
	temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_HEXAHEDRON8, temp); 
	}
#line 1871 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 219 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(6);
	temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer));
	temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_PRISM6, temp); 
	}
#line 1882 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 225 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(5);
	temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_PYRAMID5, temp); 
	}
#line 1892 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 230 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(3);
	temp.push_back($4), temp.push_back($5), temp.push_back($6);
	model.pushElement(fem::Element::FE_LINE3, temp); 
	*/
	}
#line 1904 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 237 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(6);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9);
	model.pushElement(fem::Element::FE_TRIANGLE6, temp); 
	*/
	}
#line 1917 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(9);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12);
	model.pushElement(fem::Element::FE_QUADRANGLE9, temp); 
	*/
	}
#line 1930 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 253 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(10);
	temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer));
	temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_TETRAHEDRON10, temp); 
	}
#line 1941 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 259 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(27);
	temp.push_back((yyvsp[-27].integer)), temp.push_back((yyvsp[-26].integer)), temp.push_back((yyvsp[-25].integer)), temp.push_back((yyvsp[-24].integer)), temp.push_back((yyvsp[-23].integer));
	temp.push_back((yyvsp[-22].integer)), temp.push_back((yyvsp[-21].integer)), temp.push_back((yyvsp[-20].integer)), temp.push_back((yyvsp[-19].integer)), temp.push_back((yyvsp[-18].integer));
	temp.push_back((yyvsp[-17].integer)), temp.push_back((yyvsp[-16].integer)), temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer));
	temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer)), temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer));
	temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer));
	temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_HEXAHEDRON27, temp); 
	}
#line 1956 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 269 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(8);
	temp.push_back((yyvsp[-18].integer)), temp.push_back((yyvsp[-17].integer)), temp.push_back((yyvsp[-16].integer)), temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer));
	temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer)), temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer));
	temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer));
	temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_PRISM18, temp); 
	}
#line 1969 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 277 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(14);
	temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer)), temp.push_back((yyvsp[-10].integer));
	temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer));
	temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_PYRAMID14, temp); 
	}
#line 1981 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 284 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(1);
	temp.push_back($4);
	model.pushElement(fem::Element::FE_POINT,temp);
	*/
	}
#line 1993 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 291 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(8);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11);
	model.pushElement(fem::Element::FE_QUADRANGLE8, temp); 
	*/
	}
#line 2006 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 299 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(20);
	temp.push_back((yyvsp[-20].integer)), temp.push_back((yyvsp[-19].integer)), temp.push_back((yyvsp[-18].integer)), temp.push_back((yyvsp[-17].integer)), temp.push_back((yyvsp[-16].integer));
	temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer));
	temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer));
	temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_HEXAHEDRON20, temp); 
	}
#line 2019 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 307 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(15);
	temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer));
	temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer));
	temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_PRISM15, temp); 
	}
#line 2031 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 314 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(13);
	temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer)), temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer));
	temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer));
	temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_PYRAMID13, temp); 
	}
#line 2043 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 321 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve( 9);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12);
	model.pushElement(fem::Element::FE_ITRIANGLE9, temp); 
	*/
	}
#line 2056 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 329 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(10);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	model.pushElement(fem::Element::FE_TRIANGLE10, temp); 
	*/
	}
#line 2069 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 337 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(12);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15);
	model.pushElement(fem::Element::FE_ITRIANGLE12, temp); 
	*/
	}
#line 2083 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 346 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(15);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	model.pushElement(fem::Element::FE_TRIANGLE15, temp); 
	*/
	}
#line 2097 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 355 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(15);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	model.pushElement(fem::Element::FE_ITRIANGLE15, temp); 
	*/
	}
#line 2111 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 364 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve(21);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	temp.push_back($24);
	model.pushElement(fem::Element::FE_TRIANGLE21, temp); 
	*/
	}
#line 2127 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 375 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve( 4);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7);
	model.pushElement(fem::Element::FE_EDGE4, temp); 
	*/
	}
#line 2139 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 382 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve( 5);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	model.pushElement(fem::Element::FE_EDGE5, temp); 
	*/
	}
#line 2151 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 389 "src/msh.y" /* yacc.c:1646  */
    {
	/*
	temp.clear(); temp.reserve( 6);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9);
	model.pushElement(fem::Element::FE_EDGE6, temp); 
	*/
	}
#line 2164 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 397 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(20);
	temp.push_back((yyvsp[-20].integer)), temp.push_back((yyvsp[-19].integer)), temp.push_back((yyvsp[-18].integer)), temp.push_back((yyvsp[-17].integer)), temp.push_back((yyvsp[-16].integer)); 
	temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer));
	temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer)); 
	temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_TETRAHEDRON20, temp); 
	}
#line 2177 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 405 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(35);
	temp.push_back((yyvsp[-35].integer)), temp.push_back((yyvsp[-34].integer)), temp.push_back((yyvsp[-33].integer)), temp.push_back((yyvsp[-32].integer)), temp.push_back((yyvsp[-31].integer)); 
	temp.push_back((yyvsp[-30].integer)), temp.push_back((yyvsp[-29].integer)), temp.push_back((yyvsp[-28].integer)), temp.push_back((yyvsp[-27].integer)), temp.push_back((yyvsp[-26].integer));
	temp.push_back((yyvsp[-25].integer)), temp.push_back((yyvsp[-24].integer)), temp.push_back((yyvsp[-23].integer)), temp.push_back((yyvsp[-22].integer)), temp.push_back((yyvsp[-21].integer)); 
	temp.push_back((yyvsp[-20].integer)), temp.push_back((yyvsp[-19].integer)), temp.push_back((yyvsp[-18].integer)), temp.push_back((yyvsp[-17].integer)), temp.push_back((yyvsp[-16].integer));
	temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)), temp.push_back((yyvsp[-11].integer)); 
	temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer)), temp.push_back((yyvsp[-6].integer));
	temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)), temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_TETRAHEDRON35, temp); 
	}
#line 2193 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 416 "src/msh.y" /* yacc.c:1646  */
    {
	temp.clear(); temp.reserve(56);
	temp.push_back((yyvsp[-56].integer)), temp.push_back((yyvsp[-55].integer)), temp.push_back((yyvsp[-54].integer)), temp.push_back((yyvsp[-53].integer)), temp.push_back((yyvsp[-52].integer)); 
	temp.push_back((yyvsp[-51].integer)); temp.push_back((yyvsp[-50].integer)); temp.push_back((yyvsp[-49].integer)), temp.push_back((yyvsp[-48].integer)), temp.push_back((yyvsp[-47].integer));
	temp.push_back((yyvsp[-46].integer)), temp.push_back((yyvsp[-45].integer)), temp.push_back((yyvsp[-44].integer)), temp.push_back((yyvsp[-43].integer)), temp.push_back((yyvsp[-42].integer)); 
	temp.push_back((yyvsp[-41].integer)), temp.push_back((yyvsp[-40].integer)), temp.push_back((yyvsp[-39].integer)), temp.push_back((yyvsp[-38].integer)), temp.push_back((yyvsp[-37].integer));
	temp.push_back((yyvsp[-36].integer)), temp.push_back((yyvsp[-35].integer)), temp.push_back((yyvsp[-34].integer)), temp.push_back((yyvsp[-33].integer)), temp.push_back((yyvsp[-32].integer)); 
	temp.push_back((yyvsp[-31].integer)), temp.push_back((yyvsp[-30].integer)), temp.push_back((yyvsp[-29].integer)), temp.push_back((yyvsp[-28].integer)), temp.push_back((yyvsp[-27].integer));
	temp.push_back((yyvsp[-26].integer)), temp.push_back((yyvsp[-25].integer)), temp.push_back((yyvsp[-24].integer)), temp.push_back((yyvsp[-23].integer)), temp.push_back((yyvsp[-22].integer)); 
	temp.push_back((yyvsp[-21].integer)), temp.push_back((yyvsp[-20].integer)), temp.push_back((yyvsp[-19].integer)), temp.push_back((yyvsp[-18].integer)), temp.push_back((yyvsp[-17].integer));
	temp.push_back((yyvsp[-16].integer)), temp.push_back((yyvsp[-15].integer)), temp.push_back((yyvsp[-14].integer)), temp.push_back((yyvsp[-13].integer)), temp.push_back((yyvsp[-12].integer)); 
	temp.push_back((yyvsp[-11].integer)), temp.push_back((yyvsp[-10].integer)), temp.push_back((yyvsp[-9].integer)), temp.push_back((yyvsp[-8].integer)), temp.push_back((yyvsp[-7].integer));
	temp.push_back((yyvsp[-6].integer)), temp.push_back((yyvsp[-5].integer)), temp.push_back((yyvsp[-4].integer)), temp.push_back((yyvsp[-3].integer)), temp.push_back((yyvsp[-2].integer)); 
	temp.push_back((yyvsp[-1].integer));
	model.pushElement(fem::Element::FE_TETRAHEDRON56, temp); 
	}
#line 2214 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 434 "src/msh.y" /* yacc.c:1646  */
    { /*TODO finish this */}
#line 2220 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 435 "src/msh.y" /* yacc.c:1646  */
    { /*TODO finish this */}
#line 2226 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 436 "src/msh.y" /* yacc.c:1646  */
    { /*TODO finish this */}
#line 2232 "src/msh.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 437 "src/msh.y" /* yacc.c:1646  */
    { /*TODO finish this */}
#line 2238 "src/msh.tab.c" /* yacc.c:1646  */
    break;


#line 2242 "src/msh.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (model, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (model, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, model);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, model);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (model, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, model);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, model);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 443 "src/msh.y" /* yacc.c:1906  */


