/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison/analizador_sintactico.y"


#include <stdio.h>
#include <math.h>
#include "analizador_sintactico.h"
#include "tabla_simbolos.h"
#include "analizador_lexico.h"
#include "componente_lexico.h"
#include "funciones_propias.h"
#include "definiciones.h"
#include "boolean.h"
#include "errores.h"

/* Tratamiento de errores */
void yyerror(const char *s); /* Funcion de impresión de error */

/* Estructura de datos de la ejecución actual */
void reset_current_exec();
struct CurrentExec {
	bool error;			 /* Booleano para no imprimir resultado en caso de error */
	int err_flag;		 /* Flag del error actual */
	bool print_out;		 /* Booleano para no imprimir resultado cuando proceda */
	bool file;			 /* Booleano para indicar la lectura de fichero */
	bool file_ready;	 /* Booleano para indicar la correcta carga de un fichero que está en espera */
	char *last_fnc_name; /* Nombre de la última función utilizada (para la impresión de errores) */
} ce;

/* Checkeo de inicialización de variables y constantes */
bool is_inicializada(CompLexico *cl);

/* Función de limpiado de strings de yylval */
void clear_string(char *ptr);


#line 106 "bison/analizador_sintactico.tab.c"

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

#include "definiciones.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERICO = 3,                   /* NUMERICO  */
  YYSYMBOL_FUNCION = 4,                    /* FUNCION  */
  YYSYMBOL_IDENTIFICADOR = 5,              /* IDENTIFICADOR  */
  YYSYMBOL_CONSTANTE = 6,                  /* CONSTANTE  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_FP_NARGS = 8,                   /* FP_NARGS  */
  YYSYMBOL_FP_ONEARG = 9,                  /* FP_ONEARG  */
  YYSYMBOL_FP_EXPARG = 10,                 /* FP_EXPARG  */
  YYSYMBOL_END_COMMAND_FILE = 11,          /* END_COMMAND_FILE  */
  YYSYMBOL_12_ = 12,                       /* ';'  */
  YYSYMBOL_13_ = 13,                       /* '='  */
  YYSYMBOL_PLUS_EQ = 14,                   /* PLUS_EQ  */
  YYSYMBOL_MINUS_EQ = 15,                  /* MINUS_EQ  */
  YYSYMBOL_MULT_EQ = 16,                   /* MULT_EQ  */
  YYSYMBOL_DIV_EQ = 17,                    /* DIV_EQ  */
  YYSYMBOL_EXP_EQ = 18,                    /* EXP_EQ  */
  YYSYMBOL_MOD_EQ = 19,                    /* MOD_EQ  */
  YYSYMBOL_20_ = 20,                       /* '-'  */
  YYSYMBOL_21_ = 21,                       /* '+'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '%'  */
  YYSYMBOL_NEG = 25,                       /* NEG  */
  YYSYMBOL_26_ = 26,                       /* '^'  */
  YYSYMBOL_27_n_ = 27,                     /* '\n'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_input = 31,                     /* input  */
  YYSYMBOL_line = 32,                      /* line  */
  YYSYMBOL_end = 33,                       /* end  */
  YYSYMBOL_instr = 34,                     /* instr  */
  YYSYMBOL_pyc = 35,                       /* pyc  */
  YYSYMBOL_comm = 36,                      /* comm  */
  YYSYMBOL_exp_asg = 37,                   /* exp_asg  */
  YYSYMBOL_fp = 38,                        /* fp  */
  YYSYMBOL_exp = 39,                       /* exp  */
  YYSYMBOL_var = 40,                       /* var  */
  YYSYMBOL_asign = 41,                     /* asign  */
  YYSYMBOL_asign_op = 42,                  /* asign_op  */
  YYSYMBOL_storage = 43,                   /* storage  */
  YYSYMBOL_fnc = 44                        /* fnc  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  83

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
      27,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    24,     2,     2,
      28,    29,    22,    21,     2,    20,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    12,
       2,    13,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    79,   108,   110,   111,   113,   125,   126,
     133,   134,   135,   136,   139,   140,   144,   146,   150,   151,
     155,   166,   212,   235,   254,   276,   278,   280,   282,   283,
     284,   285,   298,   299,   300,   301,   306,   320,   335,   339,
     353,   354,   355,   356,   357,   358,   363,   365,   381
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMERICO", "FUNCION",
  "IDENTIFICADOR", "CONSTANTE", "STRING", "FP_NARGS", "FP_ONEARG",
  "FP_EXPARG", "END_COMMAND_FILE", "';'", "'='", "PLUS_EQ", "MINUS_EQ",
  "MULT_EQ", "DIV_EQ", "EXP_EQ", "MOD_EQ", "'-'", "'+'", "'*'", "'/'",
  "'%'", "NEG", "'^'", "'\\n'", "'('", "')'", "$accept", "input", "line",
  "end", "instr", "pyc", "comm", "exp_asg", "fp", "exp", "var", "asign",
  "asign_op", "storage", "fnc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    59,    61,   267,   268,   269,   270,   271,   272,
      45,    43,    42,    47,    37,   273,    94,    10,    40,    41
};
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -27,     4,   -27,    19,   -27,   -26,   113,   -10,   -22,   -17,
      -3,   -27,    16,    72,   -27,    77,   -27,   -27,    19,    46,
      16,   -27,   -27,   114,   -27,   -27,    20,   -27,   -27,    72,
      72,    72,    72,    72,    72,    72,   -27,     0,    88,    72,
     -27,   -27,   -27,     8,     6,   -27,   -27,   -27,    59,    59,
      72,    72,    72,    72,    72,    72,    72,    86,   114,   114,
     114,   114,   114,   114,   -27,     7,    18,    24,    96,   -27,
     -27,   119,   119,     8,     8,     8,     8,   114,   -27,   -27,
     -27,   -27,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    25,     0,    36,    37,     0,     0,
       0,     9,    14,     0,     8,     0,     3,     6,     0,     0,
      11,    17,    16,    18,    26,    19,     0,    27,     7,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      15,    36,    37,    33,     0,     4,     5,    13,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
      42,    43,    45,    44,    20,     0,     0,     0,     0,    35,
      12,    29,    28,    30,    31,    32,    34,    38,    48,    23,
      21,    22,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,    67,    -1,    25,   -27,    44,   -27,   -12,
      22,   -27,   -27,   -27,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    16,    17,    47,    48,    20,    21,    22,    23,
      24,    25,    36,    26,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    43,    29,   -47,     2,     3,    37,     4,     5,     6,
       7,    38,     8,     9,    10,    11,    12,    57,    58,    59,
      60,    61,    62,    63,    13,    39,    19,    68,    12,    64,
      11,    14,    15,    56,    55,    69,    79,    40,    71,    72,
      73,    74,    75,    76,    77,    49,    14,    80,    70,     4,
       5,     6,     7,    81,     8,     9,    10,    11,    12,    44,
      67,     0,     4,     5,     6,     7,    13,     8,     9,    10,
      28,    12,     0,    14,    15,     4,     5,    41,    42,    13,
       4,     5,     6,     7,     0,    45,    46,    15,     0,     0,
       0,    65,    13,    41,    42,    66,     0,    13,     0,     0,
      15,     0,     0,     0,     0,    15,    50,    51,    52,    53,
      54,     0,    55,     0,     0,    78,    50,    51,    52,    53,
      54,     0,    55,     0,     0,    82,   -46,    30,    31,    32,
      33,    34,    35,     0,    50,    51,    52,    53,    54,     0,
      55,    52,    53,    54,     0,    55
};

static const yytype_int8 yycheck[] =
{
       1,    13,    28,    13,     0,     1,    28,     3,     4,     5,
       6,    28,     8,     9,    10,    11,    12,    29,    30,    31,
      32,    33,    34,    35,    20,    28,     1,    39,    12,    29,
      11,    27,    28,    13,    26,    29,    29,    12,    50,    51,
      52,    53,    54,    55,    56,    20,    27,    29,    49,     3,
       4,     5,     6,    29,     8,     9,    10,    11,    12,    15,
      38,    -1,     3,     4,     5,     6,    20,     8,     9,    10,
       3,    12,    -1,    27,    28,     3,     4,     5,     6,    20,
       3,     4,     5,     6,    -1,    18,    19,    28,    -1,    -1,
      -1,     3,    20,     5,     6,     7,    -1,    20,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    28,    20,    21,    22,    23,
      24,    -1,    26,    -1,    -1,    29,    20,    21,    22,    23,
      24,    -1,    26,    -1,    -1,    29,    13,    14,    15,    16,
      17,    18,    19,    -1,    20,    21,    22,    23,    24,    -1,
      26,    22,    23,    24,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,     0,     1,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    20,    27,    28,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    43,    44,    33,    28,
      14,    15,    16,    17,    18,    19,    42,    28,    28,    28,
      35,     5,     6,    39,    37,    33,    33,    34,    35,    35,
      20,    21,    22,    23,    24,    26,    13,    39,    39,    39,
      39,    39,    39,    39,    29,     3,     7,    40,    39,    29,
      34,    39,    39,    39,    39,    39,    39,    39,    29,    29,
      29,    29,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    32,    32,    33,    33,
      34,    34,    34,    34,    35,    35,    36,    36,    37,    37,
      38,    38,    38,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    40,    40,    41,    41,
      42,    42,    42,    42,    42,    42,    43,    43,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     2,     1,     1,
       2,     1,     3,     2,     1,     2,     1,     1,     1,     1,
       3,     4,     4,     4,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     1,     1,     3,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 3: /* input: input line  */
#line 79 "bison/analizador_sintactico.y"
                             {
			 /* Cargamos fichero si está en espera */
			if (ce.file_ready) {
				ce.file_ready = FALSE;
				ce.file = TRUE;
				read_file();
			}
			/* Procesamos si terminamos de leer un fichero o terminamos de leer una línea */
			else if (!ce.file) {
				/* Finalización del comando */
				if (!ce.error) {
					/* Impresión de la salida*/
					if(ce.print_out) {
						print_output((yyvsp[0].num));
					}
					commit_variables(); // Guardamos variables de la línea
				}
				else {
					rollback_variables(); // Eliminamos variables de la línea
				}

				/* Imprimimos prompt */
				print_prompt();
				/* Reseteamos valores de la ejecución actual */
				reset_current_exec();
			} }
#line 1500 "bison/analizador_sintactico.tab.c"
    break;

  case 4: /* line: instr end  */
#line 108 "bison/analizador_sintactico.y"
                  { (yyval.num) = (yyvsp[-1].num); }
#line 1506 "bison/analizador_sintactico.tab.c"
    break;

  case 5: /* line: pyc end  */
#line 110 "bison/analizador_sintactico.y"
                          { ce.print_out = FALSE; }
#line 1512 "bison/analizador_sintactico.tab.c"
    break;

  case 6: /* line: end  */
#line 111 "bison/analizador_sintactico.y"
                      { ce.print_out = FALSE; }
#line 1518 "bison/analizador_sintactico.tab.c"
    break;

  case 7: /* line: error end  */
#line 113 "bison/analizador_sintactico.y"
                            {
			/* Cancelamos la impresión actual */
			ce.error = TRUE;
			/* Cancelamos lectura de archivo */
			if (ce.file || ce.file_ready) {
				ce.file = !close_file();
				ce.file_ready = FALSE;
			}
			yyerrok; }
#line 1532 "bison/analizador_sintactico.tab.c"
    break;

  case 9: /* end: END_COMMAND_FILE  */
#line 126 "bison/analizador_sintactico.y"
                                   {
			/* Cerramos archivo */
			ce.file = !close_file();
			ce.file_ready = FALSE;
			}
#line 1542 "bison/analizador_sintactico.tab.c"
    break;

  case 10: /* instr: comm pyc  */
#line 133 "bison/analizador_sintactico.y"
                 { (yyval.num) = (yyvsp[-1].num); }
#line 1548 "bison/analizador_sintactico.tab.c"
    break;

  case 11: /* instr: comm  */
#line 134 "bison/analizador_sintactico.y"
                       { (yyval.num) = (yyvsp[0].num); }
#line 1554 "bison/analizador_sintactico.tab.c"
    break;

  case 12: /* instr: comm pyc instr  */
#line 135 "bison/analizador_sintactico.y"
                                 { (yyval.num) = (yyvsp[0].num); }
#line 1560 "bison/analizador_sintactico.tab.c"
    break;

  case 13: /* instr: pyc instr  */
#line 136 "bison/analizador_sintactico.y"
                            { (yyval.num) = (yyvsp[0].num); }
#line 1566 "bison/analizador_sintactico.tab.c"
    break;

  case 16: /* comm: fp  */
#line 144 "bison/analizador_sintactico.y"
           { /* Cancelamos impresión pues es una función*/
			 ce.print_out = FALSE; }
#line 1573 "bison/analizador_sintactico.tab.c"
    break;

  case 17: /* comm: exp_asg  */
#line 146 "bison/analizador_sintactico.y"
                          { (yyval.num) = (yyvsp[0].num); }
#line 1579 "bison/analizador_sintactico.tab.c"
    break;

  case 18: /* exp_asg: exp  */
#line 150 "bison/analizador_sintactico.y"
                    { (yyval.num) = (yyvsp[0].num); }
#line 1585 "bison/analizador_sintactico.tab.c"
    break;

  case 19: /* exp_asg: asign  */
#line 151 "bison/analizador_sintactico.y"
                                { (yyval.num) = (yyvsp[0].num); }
#line 1591 "bison/analizador_sintactico.tab.c"
    break;

  case 20: /* fp: FP_NARGS '(' ')'  */
#line 155 "bison/analizador_sintactico.y"
                                 {
			/* Guardamos referencia a la función */
			ce.last_fnc_name = (yyvsp[-2].cmplx)->lexema;
			/* Llamada a la función */  	
			(*((yyvsp[-2].cmplx)->datos.dfp.fncptr))();
			/* Realizamos salida del programa si corresponde */
			if ((yyvsp[-2].cmplx)->datos.dfp.tipo == FP_EXIT) {
				YYACCEPT;
			} }
#line 1605 "bison/analizador_sintactico.tab.c"
    break;

  case 21: /* fp: FP_ONEARG '(' STRING ')'  */
#line 166 "bison/analizador_sintactico.y"
                                           {
			CompLexico *f = (yyvsp[-3].cmplx);
			/* Guardamos referencia a la función */
			ce.last_fnc_name = (yyvsp[-3].cmplx)->lexema;
			/* Llamada a la función load() */
			if (f->datos.dfp.tipo == FP_LOAD) {
				/* Imprimimos error si la ruta no es válida */
				if (!((bool(*)())f->datos.dfp.fncptr)((yyvsp[-1].str))) {
					/* Registramos el error */
					ce.err_flag = ERR_FILE_NOT_FOUND; 
					yyerror((yyvsp[-1].str));
					clear_string((yyvsp[-1].str)); // Liberación de memoria del string
					/* Abortamos lectura debido al error */
					YYERROR;
				}
				/* Establecemos booleano de carga correcta de archivo */
				else {
					clear_string((yyvsp[-1].str)); // Liberación de memoria del string
					ce.file_ready = TRUE;
				}
			}
			/* Llamada a la función import() */
			else if (f->datos.dfp.tipo == FP_IMPORT) {
				/* Imprimimos error si la ruta no es válida */
				if (!((bool(*)())f->datos.dfp.fncptr)((yyvsp[-1].str))) {
					/* Registramos el error */
					ce.err_flag = ERR_LIB_NOT_FOUND; 
					yyerror((yyvsp[-1].str));
					clear_string((yyvsp[-1].str)); // Liberación de memoria del string
					/* Abortamos lectura debido al error */
					YYERROR;
				}
				clear_string((yyvsp[-1].str)); // Liberación de memoria del string
			}
			/* Error de tipo de dato */
			else {
				clear_string((yyvsp[-1].str)); // Liberación de memoria del string
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
#line 1655 "bison/analizador_sintactico.tab.c"
    break;

  case 22: /* fp: FP_ONEARG '(' var ')'  */
#line 212 "bison/analizador_sintactico.y"
                                        {
			CompLexico *f = (yyvsp[-3].cmplx);
			/* Guardamos referencia a la función */
			ce.last_fnc_name = (yyvsp[-3].cmplx)->lexema;
			/* Función clean(var) */
			if (f->datos.dfp.tipo == FP_CLEAN_VAR) {
				f->datos.dfp.fncptr((yyvsp[-1].cmplx)->lexema);
			}
			/* Función echo(bool) */
			else if (f->datos.dfp.tipo == FP_ECHO) {
				f->datos.dfp.fncptr((bool)(yyvsp[-1].cmplx)->datos.di.valor);
			}
			/* Error de tipo de dato */
			else {
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
#line 1682 "bison/analizador_sintactico.tab.c"
    break;

  case 23: /* fp: FP_ONEARG '(' NUMERICO ')'  */
#line 235 "bison/analizador_sintactico.y"
                                             {
			CompLexico *f = (yyvsp[-3].cmplx);
			/* Guardamos referencia a la función */
			ce.last_fnc_name = (yyvsp[-3].cmplx)->lexema;
			/* Función echo(bool) */
			if (f->datos.dfp.tipo == FP_ECHO) {
				f->datos.dfp.fncptr((bool)(yyvsp[-1].num));
			}
			/* Error de tipo de dato */
			else {
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
#line 1705 "bison/analizador_sintactico.tab.c"
    break;

  case 24: /* fp: FP_EXPARG '(' exp ')'  */
#line 254 "bison/analizador_sintactico.y"
                                        {
			CompLexico *f = (yyvsp[-3].cmplx);
			/* Guardamos referencia a la función */
			ce.last_fnc_name = (yyvsp[-3].cmplx)->lexema;
			/* Llamada a la función load() */
			if (f->datos.dfp.tipo == FP_PRINT) {
				f->datos.dfp.fncptr((yyvsp[-1].num));
			}
			/* Error de tipo de dato */
			else {
				/* Registramos el error */
				ce.err_flag = ERR_INVALID_ARGUMENT_TYPE; 
				yyerror(f->lexema);
				/* Necesario para parar el analisis y no imprimir mas errores */
				ce.err_flag = STOP_CURRENT_ANALISIS;
				/* Abortamos lectura debido al error */
				YYERROR; 
			} }
#line 1728 "bison/analizador_sintactico.tab.c"
    break;

  case 25: /* exp: NUMERICO  */
#line 276 "bison/analizador_sintactico.y"
                         { (yyval.num) = (yyvsp[0].num); }
#line 1734 "bison/analizador_sintactico.tab.c"
    break;

  case 26: /* exp: var  */
#line 278 "bison/analizador_sintactico.y"
                      { (yyval.num) = (yyvsp[0].cmplx)->datos.di.valor; }
#line 1740 "bison/analizador_sintactico.tab.c"
    break;

  case 27: /* exp: fnc  */
#line 280 "bison/analizador_sintactico.y"
                      { (yyval.num) = (yyvsp[0].num); }
#line 1746 "bison/analizador_sintactico.tab.c"
    break;

  case 28: /* exp: exp '+' exp  */
#line 282 "bison/analizador_sintactico.y"
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 1752 "bison/analizador_sintactico.tab.c"
    break;

  case 29: /* exp: exp '-' exp  */
#line 283 "bison/analizador_sintactico.y"
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 1758 "bison/analizador_sintactico.tab.c"
    break;

  case 30: /* exp: exp '*' exp  */
#line 284 "bison/analizador_sintactico.y"
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 1764 "bison/analizador_sintactico.tab.c"
    break;

  case 31: /* exp: exp '/' exp  */
#line 285 "bison/analizador_sintactico.y"
                              {
			// Comprobamos que no se produzca una división por 0
			if ((yyvsp[0].num) > 0) {
				(yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num);
			}
			// División por 0
			else {
				/* Registramos el error */
				ce.err_flag = ERR_DIVISION_BY_0;
				yyerror(NULL);
				/* Abortamos lectura debido al error */
				YYERROR;
			} }
#line 1782 "bison/analizador_sintactico.tab.c"
    break;

  case 32: /* exp: exp '%' exp  */
#line 298 "bison/analizador_sintactico.y"
                              { (yyval.num) = fmod((yyvsp[-2].num), (yyvsp[0].num)); }
#line 1788 "bison/analizador_sintactico.tab.c"
    break;

  case 33: /* exp: '-' exp  */
#line 299 "bison/analizador_sintactico.y"
                                    { (yyval.num) = -(yyvsp[0].num); }
#line 1794 "bison/analizador_sintactico.tab.c"
    break;

  case 34: /* exp: exp '^' exp  */
#line 300 "bison/analizador_sintactico.y"
                              { (yyval.num) = pow((yyvsp[-2].num), (yyvsp[0].num)); }
#line 1800 "bison/analizador_sintactico.tab.c"
    break;

  case 35: /* exp: '(' exp_asg ')'  */
#line 301 "bison/analizador_sintactico.y"
                                  { (yyval.num) = (yyvsp[-1].num); }
#line 1806 "bison/analizador_sintactico.tab.c"
    break;

  case 36: /* var: IDENTIFICADOR  */
#line 306 "bison/analizador_sintactico.y"
                              {
			/* Comprobación de inicialización */
			if (!is_inicializada((yyvsp[0].cmplx))) {
				/* Registramos el error */
				ce.err_flag = ERR_SYMBOL_NOT_DEFINED;
				yyerror((yyvsp[0].cmplx)->lexema);
				/* Abortamos lectura debido al error */
				YYERROR;
			}
			/* Asignamos */
			else {
			(yyval.cmplx) = (yyvsp[0].cmplx); 
			} }
#line 1824 "bison/analizador_sintactico.tab.c"
    break;

  case 37: /* var: CONSTANTE  */
#line 320 "bison/analizador_sintactico.y"
                            { 
			/* Comprobación de inicialización */
			if(!is_inicializada((yyvsp[0].cmplx))) {
				/* Registramos el error */
				ce.err_flag = ERR_CONSTANT_NOT_DEFINED;
				yyerror((yyvsp[0].cmplx)->lexema);
				/* Abortamos lectura debido al error */
				YYERROR;
			}
			/* Asignamos */
			else {
				(yyval.cmplx) = (yyvsp[0].cmplx);
		 	} }
#line 1842 "bison/analizador_sintactico.tab.c"
    break;

  case 38: /* asign: storage '=' exp  */
#line 335 "bison/analizador_sintactico.y"
                        { 	
			(yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor = (yyvsp[0].num));
			(yyvsp[-2].cmplx)->datos.di.inicializado = TRUE; }
#line 1850 "bison/analizador_sintactico.tab.c"
    break;

  case 39: /* asign: IDENTIFICADOR asign_op  */
#line 339 "bison/analizador_sintactico.y"
                                         {
			/* Comprobacion de inicialización */
			if (!is_inicializada((yyvsp[-1].cmplx))) {
				/* Registramos el error */
				ce.err_flag = ERR_SYMBOL_NOT_DEFINED;
				yyerror((yyvsp[-1].cmplx)->lexema);
				/* Abortamos lectura debido al error */
				YYERROR;
			}
			/* Asignamos */
			else {
				(yyval.num) = ((yyvsp[-1].cmplx)->datos.di.valor = (yyvsp[0].num));
		 	} }
#line 1868 "bison/analizador_sintactico.tab.c"
    break;

  case 40: /* asign_op: PLUS_EQ exp  */
#line 353 "bison/analizador_sintactico.y"
                            { (yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor += (yyvsp[0].num)); }
#line 1874 "bison/analizador_sintactico.tab.c"
    break;

  case 41: /* asign_op: MINUS_EQ exp  */
#line 354 "bison/analizador_sintactico.y"
                                       { (yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor -= (yyvsp[0].num)); }
#line 1880 "bison/analizador_sintactico.tab.c"
    break;

  case 42: /* asign_op: MULT_EQ exp  */
#line 355 "bison/analizador_sintactico.y"
                                      { (yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor *= (yyvsp[0].num)); }
#line 1886 "bison/analizador_sintactico.tab.c"
    break;

  case 43: /* asign_op: DIV_EQ exp  */
#line 356 "bison/analizador_sintactico.y"
                                     { (yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor /= (yyvsp[0].num)); }
#line 1892 "bison/analizador_sintactico.tab.c"
    break;

  case 44: /* asign_op: MOD_EQ exp  */
#line 357 "bison/analizador_sintactico.y"
                                     { (yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor = fmod((yyvsp[-2].cmplx)->datos.di.valor, (yyvsp[0].num))); }
#line 1898 "bison/analizador_sintactico.tab.c"
    break;

  case 45: /* asign_op: EXP_EQ exp  */
#line 358 "bison/analizador_sintactico.y"
                                     { (yyval.num) = ((yyvsp[-2].cmplx)->datos.di.valor = pow((yyvsp[-2].cmplx)->datos.di.valor, (yyvsp[0].num))); }
#line 1904 "bison/analizador_sintactico.tab.c"
    break;

  case 46: /* storage: IDENTIFICADOR  */
#line 363 "bison/analizador_sintactico.y"
                                      { (yyval.cmplx) = (yyvsp[0].cmplx); }
#line 1910 "bison/analizador_sintactico.tab.c"
    break;

  case 47: /* storage: CONSTANTE  */
#line 365 "bison/analizador_sintactico.y"
                                    {	
				/* Constante ya inicializada */
				if(is_inicializada((yyvsp[0].cmplx))) {
					/* Registramos el error */
					ce.err_flag = ERR_CONSTANT_REDEFINITION;
					yyerror((yyvsp[0].cmplx)->lexema);
					/* Abortamos lectura debido al error */
					YYERROR;
				} 
				/* Devolvemos referencia */
				else {
					(yyval.cmplx) = (yyvsp[0].cmplx);
				} }
#line 1928 "bison/analizador_sintactico.tab.c"
    break;

  case 48: /* fnc: FUNCION '(' exp ')'  */
#line 381 "bison/analizador_sintactico.y"
                            { (yyval.num) = (*((yyvsp[-3].cmplx)->datos.dfm.fncptr))((yyvsp[-1].num)); }
#line 1934 "bison/analizador_sintactico.tab.c"
    break;


#line 1938 "bison/analizador_sintactico.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 383 "bison/analizador_sintactico.y"


/* Funcion de error */
void yyerror(const char *s) {
	/* Error ya tratado */
	if (yychar == STOP_CURRENT_ANALISIS) {
		return;
	}
	/* Flag no definida */
	else if (ce.err_flag == ERR_UNKNOWN_ERROR) {	
		switch(yychar) {
			/* Valor en la izquierda de una asignación no válido */
			case '=':
			case PLUS_EQ:
			case MINUS_EQ:
			case MULT_EQ:
			case DIV_EQ:
			case MOD_EQ:
			case EXP_EQ:
				raise_error(ERR_INVALID_ASSIGN_TYPE, NULL);
				break;
			/* Llamada incorrecta a una función */
			case '(':
			case ')':
				raise_error(ERR_INVALID_FUNCTION_CALL, ce.last_fnc_name);
				break;
			/* String en un lugar no válido */
			case STRING:
				clear_string(yylval.str); // Liberación de memoria del string
				raise_error(ERR_UNKNOWN_ERROR, s); // Lanzamos error igualmente
				break;
			/* Error de sintaxis de bison */
			default:
				raise_error(ERR_UNKNOWN_ERROR, s);
		}
	}
	/* Flag definida */
	else {
		raise_error(ce.err_flag, s);
	}
	/* Paramos la impresión de errores hasta final de lectura del comando */
	ce.err_flag = STOP_CURRENT_ANALISIS;
}

// Comprueba si una variable o constante está inicializada
bool is_inicializada(CompLexico *cl) { 
	if((cl->id == IDENTIFICADOR || cl->id == CONSTANTE) && cl->datos.di.inicializado == TRUE)
		return TRUE;
	return FALSE;
}

/* Función de limpiado de strings de yylval */
void clear_string(char *ptr) {
	if (ptr != NULL) {
		free(ptr);
		ptr = NULL;
	}
}

/* Reseteo de los datos de la ejecución actual */
void reset_current_exec() {
	ce.error = FALSE;
	ce.err_flag = ERR_UNKNOWN_ERROR;
	ce.print_out = TRUE;
	ce.file_ready = FALSE;
	ce.file = FALSE;
	ce.last_fnc_name = NULL;
}

/* Inicializaciones y cerrados del analizador sintáctico */
// Inicializacion del analizador sintactico
void inicializacion_analizador_sintactico() {
	// Impresion del prompt
	print_prompt();
	// Inicialización de la primera ejecución
	reset_current_exec();
}

// Liberacion de memoria del analizador sintactico
void cerrado_analizador_sintactico() {
	// Liberación de memoria de las funciones propias
	finalizacion_funciones();
}
