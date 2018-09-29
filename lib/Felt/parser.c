/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

/*
    This file is part of the FElt finite element analysis package.
    Copyright (C) 1993-1997 Jason I. Gobat and Darren C. Atkinson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/************************************************************************
 * File:	parser.y						*
 *									*
 * Description:	This file contains the yacc specification for the	*
 *		parser for the FElt 2.0 system.				*
 ************************************************************************/

# include <stdio.h>
# include "code.h"
# include "error.h"
# include "objects.h"
# include "problem.h"
# include "allocate.h"

# if !defined (__GNUC__) && !defined (__sparc__)
# define alloca malloc		/* prevents alloca from being called */
# endif

# define VariableExpression 2	/* not 0, 1, or, 'h' */

extern void yyerror ( );
extern int  yylex  ( );
# ifdef NEED_STRDUP
extern char *strdup ( );
# endif

/* Last parameters (default for some parameters is to inherit the last). */

static double		  last_x;		/* last x coordinate	   */
static double		  last_y;		/* last y coordinate	   */
static double		  last_z;		/* last z coordinate	   */
static char		 *last_constraint;	/* name of last constraint */
static char		 *last_material;	/* name of last material   */



/* Current objects (inherited attributes). */

static Item		  found;		/* current object	   */
static Node		  node;			/* current node		   */
static Element		  element;		/* current element	   */
static Material		  material;		/* current material	   */
static Distributed	  load;			/* current load		   */
static Force		  force;		/* current force	   */
static Constraint	  constraint;		/* current constraint	   */
static Definition	  definition;		/* current definition	   */
static LoadCase		  loadcase;		/* current loadcase	   */


/* Dummy strucutures.  If an object is defined twice, the second definition
   is illegal and the current object is set to a dummy object. */

static struct node	  dummy_node;		/* dummy node		   */
static struct element	  dummy_element;	/* dummy element	   */
static struct material	  dummy_material;	/* dummy material	   */
static struct distributed dummy_load;		/* dummy distributed load  */
static struct force	  dummy_force;		/* dummy force		   */
static struct constraint  dummy_constraint;	/* dummy constraint	   */
static struct loadcase    dummy_loadcase;	/* dummy loadcase	   */


/* Temporary arrays. */

static int		  int_array [1024];	/* temporary integer array */
static int		 *int_ptr;		/* pointer into array	   */
static Pair		  pair_array [1024];	/* temporary pair array	   */
static Pair		 *pair_ptr;		/* pointer into array	   */
static CasePair		  case_array [1024];	/* temporary case pair array */
static CasePair		 *case_ptr;		/* pointer into case array */


/* Temporary variables for gravity triplet */

static double		  triple_x;		
static double		  triple_y;
static double		  triple_z;


/* Discrete expression variables. */

static int		  table_error = 0;	/* error indicator	   */
static double		  last_time = 0;	/* last time coordinate	   */
static double		 *table = NULL;		/* table of values	   */
static unsigned		  table_count = 0;	/* count of values	   */
static unsigned		  table_size = 0;	/* size of table	   */


/* Figure list variables. */

static float		  figure_x;		/* current x-coordinate	   */
static float		  figure_y;		/* current y-coordinate	   */
static unsigned		  figure_size;		/* size of figure list	   */
static unsigned		  fig_point_size;	/* size of point list	   */
static FigInfo		 *figure;		/* current figure	   */

/* Line 371 of yacc.c  */
#line 184 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR = 258,
     AND = 259,
     NEQUAL = 260,
     EQUALS = 261,
     GT_EQ = 262,
     LT_EQ = 263,
     RSHIFT = 264,
     LSHIFT = 265,
     UNARY = 266,
     NAME = 267,
     INTEGER = 268,
     DOUBLE = 269,
     BOOLEAN = 270,
     TIME = 271,
     SIN = 272,
     COS = 273,
     TAN = 274,
     POW = 275,
     EXP = 276,
     LOG = 277,
     LOG10 = 278,
     SQRT = 279,
     HYPOT = 280,
     FLOOR = 281,
     CEIL = 282,
     FMOD = 283,
     FABS = 284,
     ANALYSIS_TYPE = 285,
     DIRECTION = 286,
     CONSTRAINT = 287,
     HINGED = 288,
     NODE_DOF = 289,
     MASS_MODE = 290,
     PROBLEM = 291,
     ANALYSIS = 292,
     LOAD_CASES = 293,
     END = 294,
     NODES = 295,
     ELEMENTS = 296,
     MATERIALS = 297,
     LOADS = 298,
     FORCES = 299,
     CONSTRAINTS = 300,
     TITLE_EQ = 301,
     NODES_EQ = 302,
     ELEMENTS_EQ = 303,
     ANALYSIS_EQ = 304,
     X_EQ = 305,
     Y_EQ = 306,
     Z_EQ = 307,
     FORCE_EQ = 308,
     CONSTRAINT_EQ = 309,
     MASS_EQ = 310,
     LOAD_EQ = 311,
     MATERIAL_EQ = 312,
     E_EQ = 313,
     IX_EQ = 314,
     IY_EQ = 315,
     IZ_EQ = 316,
     A_EQ = 317,
     J_EQ = 318,
     G_EQ = 319,
     T_EQ = 320,
     RHO_EQ = 321,
     NU_EQ = 322,
     KAPPA_EQ = 323,
     RK_EQ = 324,
     RM_EQ = 325,
     KX_EQ = 326,
     KY_EQ = 327,
     KZ_EQ = 328,
     C_EQ = 329,
     DIRECTION_EQ = 330,
     VALUES_EQ = 331,
     FX_EQ = 332,
     FY_EQ = 333,
     FZ_EQ = 334,
     MX_EQ = 335,
     MY_EQ = 336,
     MZ_EQ = 337,
     SFX_EQ = 338,
     SFY_EQ = 339,
     SFZ_EQ = 340,
     SMX_EQ = 341,
     SMY_EQ = 342,
     SMZ_EQ = 343,
     TX_EQ = 344,
     TY_EQ = 345,
     TZ_EQ = 346,
     RX_EQ = 347,
     RY_EQ = 348,
     RZ_EQ = 349,
     ITX_EQ = 350,
     ITY_EQ = 351,
     ITZ_EQ = 352,
     IRX_EQ = 353,
     IRY_EQ = 354,
     IRZ_EQ = 355,
     VX_EQ = 356,
     VY_EQ = 357,
     VZ_EQ = 358,
     AX_EQ = 359,
     AY_EQ = 360,
     AZ_EQ = 361,
     ALPHA_EQ = 362,
     BETA_EQ = 363,
     GAMMA_EQ = 364,
     DOFS_EQ = 365,
     MASS_MODE_EQ = 366,
     START_EQ = 367,
     STOP_EQ = 368,
     STEP_EQ = 369,
     GRAVITY_EQ = 370,
     ITERATIONS_EQ = 371,
     TOLERANCE_EQ = 372,
     LOAD_STEPS_EQ = 373,
     RELAXATION_EQ = 374,
     INPUT_RANGE_EQ = 375,
     INPUT_DOF_EQ = 376,
     INPUT_NODE_EQ = 377,
     NODE_FORCES_EQ = 378,
     ELEMENT_LOADS_EQ = 379,
     CANVAS = 380,
     FIGURES = 381,
     NODE_NUM_EQ = 382,
     ELT_NUM_EQ = 383,
     SNAP_EQ = 384,
     GRID_EQ = 385,
     SNAP_SIZE_EQ = 386,
     GRID_SIZE_EQ = 387,
     X_MIN_EQ = 388,
     X_MAX_EQ = 389,
     Y_MIN_EQ = 390,
     Y_MAX_EQ = 391,
     SCALE_EQ = 392,
     X_POS_EQ = 393,
     Y_POS_EQ = 394,
     WIDTH_EQ = 395,
     HEIGHT_EQ = 396,
     NODE_COLOR_EQ = 397,
     ELT_COLOR_EQ = 398,
     LABEL_FONT_EQ = 399,
     TOOL_COLOR_EQ = 400,
     TOOL_FONT_EQ = 401,
     FONT_EQ = 402,
     COLOR_EQ = 403,
     LENGTH_EQ = 404,
     TEXT_EQ = 405,
     POINTS_EQ = 406,
     FIGURE_TYPE = 407
   };
#endif
/* Tokens.  */
#define OR 258
#define AND 259
#define NEQUAL 260
#define EQUALS 261
#define GT_EQ 262
#define LT_EQ 263
#define RSHIFT 264
#define LSHIFT 265
#define UNARY 266
#define NAME 267
#define INTEGER 268
#define DOUBLE 269
#define BOOLEAN 270
#define TIME 271
#define SIN 272
#define COS 273
#define TAN 274
#define POW 275
#define EXP 276
#define LOG 277
#define LOG10 278
#define SQRT 279
#define HYPOT 280
#define FLOOR 281
#define CEIL 282
#define FMOD 283
#define FABS 284
#define ANALYSIS_TYPE 285
#define DIRECTION 286
#define CONSTRAINT 287
#define HINGED 288
#define NODE_DOF 289
#define MASS_MODE 290
#define PROBLEM 291
#define ANALYSIS 292
#define LOAD_CASES 293
#define END 294
#define NODES 295
#define ELEMENTS 296
#define MATERIALS 297
#define LOADS 298
#define FORCES 299
#define CONSTRAINTS 300
#define TITLE_EQ 301
#define NODES_EQ 302
#define ELEMENTS_EQ 303
#define ANALYSIS_EQ 304
#define X_EQ 305
#define Y_EQ 306
#define Z_EQ 307
#define FORCE_EQ 308
#define CONSTRAINT_EQ 309
#define MASS_EQ 310
#define LOAD_EQ 311
#define MATERIAL_EQ 312
#define E_EQ 313
#define IX_EQ 314
#define IY_EQ 315
#define IZ_EQ 316
#define A_EQ 317
#define J_EQ 318
#define G_EQ 319
#define T_EQ 320
#define RHO_EQ 321
#define NU_EQ 322
#define KAPPA_EQ 323
#define RK_EQ 324
#define RM_EQ 325
#define KX_EQ 326
#define KY_EQ 327
#define KZ_EQ 328
#define C_EQ 329
#define DIRECTION_EQ 330
#define VALUES_EQ 331
#define FX_EQ 332
#define FY_EQ 333
#define FZ_EQ 334
#define MX_EQ 335
#define MY_EQ 336
#define MZ_EQ 337
#define SFX_EQ 338
#define SFY_EQ 339
#define SFZ_EQ 340
#define SMX_EQ 341
#define SMY_EQ 342
#define SMZ_EQ 343
#define TX_EQ 344
#define TY_EQ 345
#define TZ_EQ 346
#define RX_EQ 347
#define RY_EQ 348
#define RZ_EQ 349
#define ITX_EQ 350
#define ITY_EQ 351
#define ITZ_EQ 352
#define IRX_EQ 353
#define IRY_EQ 354
#define IRZ_EQ 355
#define VX_EQ 356
#define VY_EQ 357
#define VZ_EQ 358
#define AX_EQ 359
#define AY_EQ 360
#define AZ_EQ 361
#define ALPHA_EQ 362
#define BETA_EQ 363
#define GAMMA_EQ 364
#define DOFS_EQ 365
#define MASS_MODE_EQ 366
#define START_EQ 367
#define STOP_EQ 368
#define STEP_EQ 369
#define GRAVITY_EQ 370
#define ITERATIONS_EQ 371
#define TOLERANCE_EQ 372
#define LOAD_STEPS_EQ 373
#define RELAXATION_EQ 374
#define INPUT_RANGE_EQ 375
#define INPUT_DOF_EQ 376
#define INPUT_NODE_EQ 377
#define NODE_FORCES_EQ 378
#define ELEMENT_LOADS_EQ 379
#define CANVAS 380
#define FIGURES 381
#define NODE_NUM_EQ 382
#define ELT_NUM_EQ 383
#define SNAP_EQ 384
#define GRID_EQ 385
#define SNAP_SIZE_EQ 386
#define GRID_SIZE_EQ 387
#define X_MIN_EQ 388
#define X_MAX_EQ 389
#define Y_MIN_EQ 390
#define Y_MAX_EQ 391
#define SCALE_EQ 392
#define X_POS_EQ 393
#define Y_POS_EQ 394
#define WIDTH_EQ 395
#define HEIGHT_EQ 396
#define NODE_COLOR_EQ 397
#define ELT_COLOR_EQ 398
#define LABEL_FONT_EQ 399
#define TOOL_COLOR_EQ 400
#define TOOL_FONT_EQ 401
#define FONT_EQ 402
#define COLOR_EQ 403
#define LENGTH_EQ 404
#define TEXT_EQ 405
#define POINTS_EQ 406
#define FIGURE_TYPE 407



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 117 "parser.y"

    int       i;
    double    d;
    char     *s;
    Pair      p;
    CasePair  cp;
    char      c;


/* Line 387 of yacc.c  */
#line 541 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 569 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  172
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  303
/* YYNRULES -- Number of states.  */
#define YYNSTATES  553

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   407

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,     2,     2,    22,     9,     2,
     167,   168,    20,    18,   171,    19,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     2,
      12,     2,    13,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   169,     2,   170,     8,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     7,     2,    24,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
      10,    11,    14,    15,    16,    17,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    12,    13,    16,    17,    20,    21,
      24,    27,    30,    33,    35,    38,    39,    41,    43,    45,
      47,    49,    51,    53,    55,    57,    59,    61,    64,    67,
      68,    71,    73,    75,    79,    82,    83,    86,    89,    92,
      95,    98,   101,   103,   106,   108,   111,   112,   115,   117,
     119,   123,   126,   127,   132,   135,   138,   140,   144,   147,
     149,   151,   155,   158,   160,   163,   166,   167,   170,   172,
     175,   176,   179,   182,   185,   188,   191,   194,   197,   200,
     203,   206,   209,   212,   215,   218,   221,   224,   227,   230,
     232,   235,   238,   239,   242,   244,   247,   248,   251,   254,
     257,   259,   263,   266,   268,   274,   279,   282,   285,   286,
     289,   291,   294,   295,   298,   302,   306,   310,   314,   318,
     322,   326,   330,   334,   338,   342,   346,   348,   351,   354,
     355,   358,   360,   363,   364,   367,   371,   375,   379,   383,
     387,   391,   394,   397,   400,   403,   406,   409,   412,   415,
     418,   421,   424,   427,   429,   431,   433,   435,   437,   439,
     442,   445,   446,   449,   451,   454,   455,   458,   461,   463,
     467,   470,   472,   478,   483,   486,   489,   490,   493,   496,
     499,   502,   505,   508,   511,   514,   517,   520,   523,   526,
     529,   532,   537,   542,   545,   548,   550,   554,   557,   558,
     562,   565,   566,   573,   576,   577,   580,   583,   584,   587,
     590,   593,   596,   599,   602,   605,   608,   611,   614,   617,
     620,   623,   626,   629,   632,   635,   638,   641,   644,   647,
     649,   652,   653,   656,   658,   661,   662,   665,   668,   671,
     674,   677,   680,   683,   686,   689,   694,   698,   701,   702,
     708,   710,   712,   715,   719,   722,   724,   730,   731,   733,
     741,   746,   751,   755,   759,   763,   767,   771,   775,   779,
     783,   787,   791,   795,   799,   803,   807,   811,   815,   818,
     821,   824,   827,   831,   833,   835,   837,   839,   844,   849,
     854,   861,   866,   871,   876,   881,   888,   893,   898,   905,
     910,   911,   912,   913
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     173,     0,    -1,   174,   175,   178,    53,    -1,    64,   253,
      53,    -1,    -1,    50,   176,    -1,    -1,   176,   177,    -1,
      -1,    60,    26,    -1,    61,    27,    -1,    62,    27,    -1,
      63,    44,    -1,     1,    -1,   178,   179,    -1,    -1,   180,
      -1,   187,    -1,   198,    -1,   204,    -1,   212,    -1,   218,
      -1,   234,    -1,   226,    -1,   241,    -1,   244,    -1,    53,
      -1,    54,   181,    -1,   181,   182,    -1,    -1,   183,   185,
      -1,   184,    -1,    27,    -1,   167,   257,   168,    -1,   185,
     186,    -1,    -1,    64,   257,    -1,    65,   257,    -1,    66,
     257,    -1,    69,   257,    -1,    67,    26,    -1,    68,    26,
      -1,     1,    -1,   188,   189,    -1,    55,    -1,   189,   190,
      -1,    -1,   191,   193,    -1,   192,    -1,    27,    -1,   167,
     257,   168,    -1,   193,   194,    -1,    -1,    61,   169,   195,
     170,    -1,    71,    26,    -1,    70,   197,    -1,     1,    -1,
     195,   171,   196,    -1,   195,   196,    -1,   196,    -1,   184,
      -1,   197,   171,    26,    -1,   197,    26,    -1,    26,    -1,
      56,   199,    -1,   199,   200,    -1,    -1,   201,   202,    -1,
      26,    -1,   202,   203,    -1,    -1,   162,    26,    -1,    72,
     257,    -1,    73,   257,    -1,    74,   257,    -1,    75,   257,
      -1,    76,   257,    -1,    77,   257,    -1,    78,   257,    -1,
      79,   257,    -1,    80,   257,    -1,    81,   257,    -1,    82,
     257,    -1,    83,   257,    -1,    84,   257,    -1,    85,   257,
      -1,    86,   257,    -1,    87,   257,    -1,    88,   257,    -1,
       1,    -1,    57,   205,    -1,   205,   206,    -1,    -1,   207,
     208,    -1,    26,    -1,   208,   209,    -1,    -1,   162,    26,
      -1,    89,    45,    -1,    90,   210,    -1,     1,    -1,   210,
     171,   211,    -1,   210,   211,    -1,   211,    -1,   167,   184,
     171,   257,   168,    -1,   167,   184,   257,   168,    -1,    58,
     213,    -1,   213,   214,    -1,    -1,   215,   216,    -1,    26,
      -1,   216,   217,    -1,    -1,   162,    26,    -1,    91,   256,
     253,    -1,    92,   256,   253,    -1,    93,   256,   253,    -1,
      94,   256,   253,    -1,    95,   256,   253,    -1,    96,   256,
     253,    -1,    97,   256,   253,    -1,    98,   256,   253,    -1,
      99,   256,   253,    -1,   100,   256,   253,    -1,   101,   256,
     253,    -1,   102,   256,   253,    -1,     1,    -1,    59,   219,
      -1,   219,   220,    -1,    -1,   221,   222,    -1,    26,    -1,
     222,   223,    -1,    -1,   162,    26,    -1,   103,   256,   224,
      -1,   104,   256,   224,    -1,   105,   256,   224,    -1,   106,
     256,   225,    -1,   107,   256,   225,    -1,   108,   256,   225,
      -1,   109,   257,    -1,   110,   257,    -1,   111,   257,    -1,
     112,   257,    -1,   113,   257,    -1,   114,   257,    -1,   115,
     257,    -1,   116,   257,    -1,   117,   257,    -1,   118,   257,
      -1,   119,   257,    -1,   120,   257,    -1,     1,    -1,   253,
      -1,    46,    -1,   253,    -1,    46,    -1,    47,    -1,    52,
     227,    -1,   227,   228,    -1,    -1,   229,   230,    -1,    26,
      -1,   230,   231,    -1,    -1,   137,   232,    -1,   138,   232,
      -1,     1,    -1,   232,   171,   233,    -1,   232,   233,    -1,
     233,    -1,   167,   184,   171,    26,   168,    -1,   167,   184,
      26,   168,    -1,    51,   235,    -1,   235,   236,    -1,    -1,
     121,   257,    -1,   122,   257,    -1,   123,   257,    -1,    83,
     257,    -1,    84,   257,    -1,   126,   257,    -1,   128,   257,
      -1,   127,   257,    -1,   130,    27,    -1,   132,    27,    -1,
     133,   257,    -1,   131,   257,    -1,   135,    48,    -1,   136,
     184,    -1,    61,   169,   237,   170,    -1,   124,   169,   238,
     170,    -1,   125,    49,    -1,   129,   239,    -1,     1,    -1,
     237,   171,   184,    -1,   237,   184,    -1,    -1,   238,   171,
      48,    -1,   238,    48,    -1,    -1,   167,   257,   171,   257,
     240,   168,    -1,   171,   257,    -1,    -1,   139,   242,    -1,
     242,   243,    -1,    -1,   141,    29,    -1,   142,    29,    -1,
     143,    29,    -1,   144,    29,    -1,   145,   257,    -1,   146,
     257,    -1,   147,   257,    -1,   148,   257,    -1,   149,   257,
      -1,   150,   257,    -1,   152,   257,    -1,   153,   257,    -1,
     154,   257,    -1,   155,   257,    -1,   151,   257,    -1,   156,
      26,    -1,   157,    26,    -1,   158,    26,    -1,   159,    26,
      -1,   160,    26,    -1,   245,   246,    -1,   140,    -1,   246,
     247,    -1,    -1,   248,   249,    -1,   166,    -1,   249,   250,
      -1,    -1,    64,   257,    -1,    65,   257,    -1,   154,   257,
      -1,   155,   257,    -1,   126,   257,    -1,   163,   257,    -1,
     164,    26,    -1,   162,    26,    -1,   161,    26,    -1,   165,
     169,   251,   170,    -1,   251,   171,   252,    -1,   251,   252,
      -1,    -1,   167,   257,   171,   257,   168,    -1,   258,    -1,
     254,    -1,   254,    18,    -1,   254,   171,   255,    -1,   254,
     255,    -1,   255,    -1,   167,   257,   171,   257,   168,    -1,
      -1,   258,    -1,   258,     3,   260,   258,     4,   261,   258,
      -1,   258,     5,   262,   258,    -1,   258,     6,   263,   258,
      -1,   258,     7,   258,    -1,   258,     8,   258,    -1,   258,
       9,   258,    -1,   258,    11,   258,    -1,   258,    10,   258,
      -1,   258,    12,   258,    -1,   258,    13,   258,    -1,   258,
      15,   258,    -1,   258,    14,   258,    -1,   258,    17,   258,
      -1,   258,    16,   258,    -1,   258,    18,   258,    -1,   258,
      19,   258,    -1,   258,    20,   258,    -1,   258,    21,   258,
      -1,   258,    22,   258,    -1,    18,   258,    -1,    19,   258,
      -1,    23,   258,    -1,    24,   258,    -1,   167,   258,   168,
      -1,    27,    -1,    28,    -1,    30,    -1,   259,    -1,    31,
     167,   258,   168,    -1,    32,   167,   258,   168,    -1,    33,
     167,   258,   168,    -1,    34,   167,   258,   171,   258,   168,
      -1,    35,   167,   258,   168,    -1,    36,   167,   258,   168,
      -1,    37,   167,   258,   168,    -1,    38,   167,   258,   168,
      -1,    39,   167,   258,   171,   258,   168,    -1,    40,   167,
     258,   168,    -1,    41,   167,   258,   168,    -1,    42,   167,
     258,   171,   258,   168,    -1,    43,   167,   258,   168,    -1,
      -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   192,   192,   193,   199,   212,   213,   218,   219,   224,
     230,   235,   240,   245,   252,   253,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   275,   280,   281,
     286,   291,   319,   320,   326,   327,   332,   337,   342,   347,
     352,   358,   363,   370,   375,   386,   387,   392,   397,   422,
     423,   429,   430,   435,   457,   462,   464,   469,   474,   479,
     488,   497,   510,   523,   536,   541,   542,   547,   552,   566,
     567,   572,   578,   583,   588,   593,   598,   603,   608,   613,
     618,   623,   628,   633,   638,   643,   648,   653,   658,   663,
     670,   675,   676,   681,   686,   701,   702,   707,   713,   718,
     739,   744,   749,   754,   763,   772,   786,   791,   792,   797,
     802,   817,   818,   823,   829,   834,   839,   844,   849,   854,
     859,   864,   869,   874,   879,   884,   889,   896,   901,   902,
     907,   912,   927,   928,   933,   939,   949,   959,   969,   979,
     989,   999,  1004,  1009,  1014,  1019,  1024,  1029,  1034,  1039,
    1044,  1049,  1054,  1059,  1064,  1069,  1077,  1082,  1087,  1097,
    1102,  1103,  1107,  1111,  1125,  1126,  1130,  1155,  1180,  1185,
    1190,  1195,  1204,  1213,  1226,  1231,  1232,  1237,  1242,  1247,
    1252,  1257,  1262,  1267,  1272,  1277,  1282,  1287,  1292,  1297,
    1302,  1307,  1322,  1333,  1338,  1345,  1350,  1355,  1361,  1368,
    1373,  1379,  1390,  1400,  1406,  1415,  1420,  1421,  1426,  1431,
    1436,  1441,  1446,  1451,  1456,  1461,  1466,  1471,  1476,  1481,
    1486,  1491,  1496,  1501,  1507,  1513,  1519,  1525,  1536,  1541,
    1549,  1550,  1555,  1560,  1586,  1587,  1592,  1597,  1602,  1607,
    1612,  1617,  1622,  1628,  1634,  1640,  1645,  1658,  1672,  1684,
    1695,  1701,  1715,  1732,  1733,  1734,  1739,  1761,  1768,  1778,
    1789,  1799,  1809,  1815,  1821,  1827,  1833,  1839,  1845,  1851,
    1857,  1863,  1869,  1875,  1881,  1887,  1893,  1899,  1905,  1910,
    1916,  1922,  1928,  1933,  1939,  1945,  1951,  1956,  1962,  1968,
    1974,  1980,  1986,  1992,  1998,  2004,  2010,  2016,  2022,  2028,
    2038,  2047,  2056,  2067
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'?'", "':'", "OR", "AND", "'|'", "'^'",
  "'&'", "NEQUAL", "EQUALS", "'<'", "'>'", "GT_EQ", "LT_EQ", "RSHIFT",
  "LSHIFT", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "UNARY",
  "NAME", "INTEGER", "DOUBLE", "BOOLEAN", "TIME", "SIN", "COS", "TAN",
  "POW", "EXP", "LOG", "LOG10", "SQRT", "HYPOT", "FLOOR", "CEIL", "FMOD",
  "FABS", "ANALYSIS_TYPE", "DIRECTION", "CONSTRAINT", "HINGED", "NODE_DOF",
  "MASS_MODE", "PROBLEM", "ANALYSIS", "LOAD_CASES", "END", "NODES",
  "ELEMENTS", "MATERIALS", "LOADS", "FORCES", "CONSTRAINTS", "TITLE_EQ",
  "NODES_EQ", "ELEMENTS_EQ", "ANALYSIS_EQ", "X_EQ", "Y_EQ", "Z_EQ",
  "FORCE_EQ", "CONSTRAINT_EQ", "MASS_EQ", "LOAD_EQ", "MATERIAL_EQ", "E_EQ",
  "IX_EQ", "IY_EQ", "IZ_EQ", "A_EQ", "J_EQ", "G_EQ", "T_EQ", "RHO_EQ",
  "NU_EQ", "KAPPA_EQ", "RK_EQ", "RM_EQ", "KX_EQ", "KY_EQ", "KZ_EQ", "C_EQ",
  "DIRECTION_EQ", "VALUES_EQ", "FX_EQ", "FY_EQ", "FZ_EQ", "MX_EQ", "MY_EQ",
  "MZ_EQ", "SFX_EQ", "SFY_EQ", "SFZ_EQ", "SMX_EQ", "SMY_EQ", "SMZ_EQ",
  "TX_EQ", "TY_EQ", "TZ_EQ", "RX_EQ", "RY_EQ", "RZ_EQ", "ITX_EQ", "ITY_EQ",
  "ITZ_EQ", "IRX_EQ", "IRY_EQ", "IRZ_EQ", "VX_EQ", "VY_EQ", "VZ_EQ",
  "AX_EQ", "AY_EQ", "AZ_EQ", "ALPHA_EQ", "BETA_EQ", "GAMMA_EQ", "DOFS_EQ",
  "MASS_MODE_EQ", "START_EQ", "STOP_EQ", "STEP_EQ", "GRAVITY_EQ",
  "ITERATIONS_EQ", "TOLERANCE_EQ", "LOAD_STEPS_EQ", "RELAXATION_EQ",
  "INPUT_RANGE_EQ", "INPUT_DOF_EQ", "INPUT_NODE_EQ", "NODE_FORCES_EQ",
  "ELEMENT_LOADS_EQ", "CANVAS", "FIGURES", "NODE_NUM_EQ", "ELT_NUM_EQ",
  "SNAP_EQ", "GRID_EQ", "SNAP_SIZE_EQ", "GRID_SIZE_EQ", "X_MIN_EQ",
  "X_MAX_EQ", "Y_MIN_EQ", "Y_MAX_EQ", "SCALE_EQ", "X_POS_EQ", "Y_POS_EQ",
  "WIDTH_EQ", "HEIGHT_EQ", "NODE_COLOR_EQ", "ELT_COLOR_EQ",
  "LABEL_FONT_EQ", "TOOL_COLOR_EQ", "TOOL_FONT_EQ", "FONT_EQ", "COLOR_EQ",
  "LENGTH_EQ", "TEXT_EQ", "POINTS_EQ", "FIGURE_TYPE", "'('", "')'", "'['",
  "']'", "','", "$accept", "specification", "initialize",
  "problem_description", "problem_parameter_list", "problem_parameter",
  "section_list", "section", "node_section", "node_definition_list",
  "node_definition", "node_number", "node_number_expression",
  "node_parameter_list", "node_parameter", "element_section",
  "element_header", "element_definition_list", "element_definition",
  "element_number", "element_number_expression", "element_parameter_list",
  "element_parameter", "element_node_list", "element_node",
  "element_load_list", "material_section", "material_definition_list",
  "material_definition", "material_name", "material_parameter_list",
  "material_parameter", "load_section", "load_definition_list",
  "load_definition", "load_name", "load_parameter_list", "load_parameter",
  "value_pair_list", "value_pair", "force_section",
  "force_definition_list", "force_definition", "force_name",
  "force_parameter_list", "force_parameter", "constraint_section",
  "constraint_definition_list", "constraint_definition", "constraint_name",
  "constraint_parameter_list", "constraint_parameter", "translation",
  "rotation", "loadcase_section", "loadcase_definition_list",
  "loadcase_definition", "loadcase_name", "loadcase_parameter_list",
  "loadcase_parameter", "loadcase_pair_list", "loadcase_pair",
  "analysis_section", "analysis_parameter_list", "analysis_parameter",
  "analysis_node_list", "analysis_dof_list", "triple", "opt_z_coordinate",
  "canvas_section", "canvas_parameter_list", "canvas_parameter",
  "figure_section", "figure_header", "figure_definition_list",
  "figure_definition", "figure_type", "figure_parameter_list",
  "figure_parameter", "figure_pair_list", "figure_pair",
  "variable_expression", "discrete_pair_list", "discrete_pair",
  "enable_copy", "constant_expression", "expression", "function",
  "if_action", "else_action", "or_action", "and_action", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    63,    58,   258,   259,   124,    94,    38,
     260,   261,    60,    62,   262,   263,   264,   265,    43,    45,
      42,    47,    37,    33,   126,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,    40,    41,    91,
      93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   172,   173,   173,   174,   175,   175,   176,   176,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   180,   181,   181,
     182,   183,   184,   184,   185,   185,   186,   186,   186,   186,
     186,   186,   186,   187,   188,   189,   189,   190,   191,   192,
     192,   193,   193,   194,   194,   194,   194,   195,   195,   195,
     196,   197,   197,   197,   198,   199,   199,   200,   201,   202,
     202,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   205,   205,   206,   207,   208,   208,   209,   209,   209,
     209,   210,   210,   210,   211,   211,   212,   213,   213,   214,
     215,   216,   216,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   218,   219,   219,
     220,   221,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   225,   225,   225,   226,
     227,   227,   228,   229,   230,   230,   231,   231,   231,   232,
     232,   232,   233,   233,   234,   235,   235,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   237,   237,   237,   238,
     238,   238,   239,   240,   240,   241,   242,   242,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   244,   245,
     246,   246,   247,   248,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   251,   252,
     253,   253,   253,   254,   254,   254,   255,   256,   257,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     260,   261,   262,   263
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     0,     2,     0,     2,     0,     2,
       2,     2,     2,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     1,     1,     3,     2,     0,     2,     2,     2,     2,
       2,     2,     1,     2,     1,     2,     0,     2,     1,     1,
       3,     2,     0,     4,     2,     2,     1,     3,     2,     1,
       1,     3,     2,     1,     2,     2,     0,     2,     1,     2,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     0,     2,     1,     2,     0,     2,     2,     2,
       1,     3,     2,     1,     5,     4,     2,     2,     0,     2,
       1,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     2,     0,
       2,     1,     2,     0,     2,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     2,     1,     2,     0,     2,     2,     1,     3,
       2,     1,     5,     4,     2,     2,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     4,     2,     2,     1,     3,     2,     0,     3,
       2,     0,     6,     2,     0,     2,     2,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     0,     2,     1,     2,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     3,     2,     0,     5,
       1,     1,     2,     3,     2,     1,     5,     0,     1,     7,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     4,     4,     4,
       6,     4,     4,     4,     4,     6,     4,     4,     6,     4,
       0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     0,     6,     0,     0,     0,     0,   283,   284,
     285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,   255,   250,   286,
       1,     8,    15,     0,   278,   279,   280,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     3,   252,     0,     0,   254,   300,   302,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   258,   253,     0,     0,     0,
     262,   263,   264,   266,   265,   267,   268,   270,   269,   272,
     271,   273,   274,   275,   276,   277,    13,     0,     0,     0,
       0,     7,   176,   161,    26,    29,    44,    66,    92,   108,
     129,   207,   229,    14,    16,    17,    46,    18,    19,    20,
      21,    23,    22,    24,    25,   231,   287,   288,   289,     0,
     291,   292,   293,   294,     0,   296,   297,     0,   299,     0,
       0,   260,   261,     9,    10,    11,    12,     0,   159,    27,
      64,    90,   106,   127,   205,    43,   228,     0,     0,     0,
     256,   301,   195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   163,   160,   165,    32,     0,    28,    35,    31,
      68,    65,    70,    94,    91,    96,   110,   107,   112,   131,
     128,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,    49,     0,    45,    52,    48,   233,   230,
     235,   290,   295,   298,     0,   198,   180,   181,   177,   178,
     179,   201,   193,   182,   184,   183,     0,   194,   185,   188,
     186,   187,   189,   190,     0,     0,     0,     0,     0,     0,
       0,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   222,   218,   219,   220,   221,   223,   224,   225,   226,
     227,     0,     0,   232,   259,     0,     0,     0,   168,     0,
       0,   164,    33,    42,     0,     0,     0,     0,     0,     0,
      34,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,   100,     0,     0,     0,    95,   126,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,     0,
     111,   153,   257,   257,   257,   257,   257,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,    50,    56,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   191,
       0,   197,   200,   192,     0,     0,     0,   166,   171,   167,
      36,    37,    38,    40,    41,    39,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    71,    98,     0,    99,   103,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     134,     0,    63,    55,    54,   236,   237,   240,   238,   239,
     244,   243,   241,   242,   248,   196,   199,   204,     0,     0,
     170,     0,     0,   102,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   155,   135,   154,   136,
     137,   157,   158,   138,   156,   139,   140,    60,     0,    59,
      62,     0,     0,     0,     0,     0,     0,   169,     0,     0,
     101,    53,     0,    58,    61,     0,   245,     0,   247,   203,
     202,   173,     0,     0,   105,    57,     0,   246,   172,   104,
       0,     0,   249
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    32,    77,   121,    78,   133,   134,   169,
     207,   208,   517,   276,   320,   135,   136,   175,   245,   246,
     247,   302,   387,   518,   519,   473,   137,   170,   211,   212,
     277,   340,   138,   171,   214,   215,   278,   345,   436,   437,
     139,   172,   217,   218,   279,   360,   140,   173,   220,   221,
     280,   381,   507,   513,   141,   168,   203,   204,   274,   311,
     407,   408,   142,   167,   201,   305,   306,   267,   524,   143,
     174,   242,   144,   145,   176,   249,   250,   303,   398,   522,
     538,   508,    26,    27,   439,    51,    95,    29,    97,   254,
      98,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -446
static const yytype_int16 yypact[] =
{
     -55,  1127,    14,   -31,  1153,  1153,  1153,  1153,  -446,  -446,
    -446,  -127,   -71,   -63,   -58,   -56,   -46,   -35,   -13,    16,
      18,    19,    20,    22,  1153,    59,   -15,  -446,  1059,  -446,
    -446,  -446,  -446,  1153,  -446,  -446,  -446,  -446,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,   -51,   405,  -446,  -446,  1153,    23,  -446,  -446,  -446,
    -446,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,   109,    -9,   405,
     476,   501,   537,    17,   577,   597,   617,   640,    48,   665,
     701,   193,   761,  1153,  -446,  1059,  -446,  1153,  1153,  1153,
     680,   737,   454,   252,   252,    64,    64,    64,    64,    56,
      56,   105,   105,  -446,  -446,  -446,  -446,   165,   168,   170,
     148,  -446,  -446,  -446,   216,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  1153,
    -446,  -446,  -446,  -446,  1153,  -446,  -446,  1153,  -446,    49,
    1206,   360,   517,  -446,  -446,  -446,  -446,  1146,   192,   -23,
     194,   198,   199,   201,  1154,   -14,    62,   781,   804,   829,
    -446,  -446,  -446,    77,  1153,  1153,  1153,  1153,  1153,    78,
     202,  1153,  1153,  1153,    83,   226,  1153,   227,  1153,   207,
     -23,  -446,  -446,  -446,  -446,  -446,  1153,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,   228,   230,   231,   232,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,   263,   274,   275,
     277,   278,  -446,  -446,  1153,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  1153,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  1153,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  1205,    88,   338,   901,   967,   991,
     803,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,   137,   123,   -47,  1059,   -22,   -42,   135,  -446,   140,
     140,  -446,  -446,  -446,  1153,  1153,  1153,   282,   283,  1153,
    -446,  -446,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,   284,
    -446,  -446,   268,   147,   289,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   290,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
     291,  -446,  -446,  -446,   149,   293,   295,  -446,  1153,  1153,
    1153,  1153,  1153,   296,   297,  1153,   298,   169,  -446,  -446,
     -23,  -446,  -446,  -446,   292,  1153,   -23,   -70,  -446,   -70,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,   -23,   -65,  -446,  -446,  1127,
    1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,
    1127,  -446,  1081,  1081,  1081,   849,   849,   849,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,   -23,  -446,   -25,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,   171,   -24,   140,
    -446,   972,   147,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   -12,  -446,
    -446,   315,   -48,  1153,   175,   176,   319,  -446,  1153,   178,
    -446,  -446,   -23,  -446,  -446,  1153,  -446,   180,  -446,  -446,
    -446,  -446,   215,   219,  -446,  -446,   217,  -446,  -446,  -446,
    1153,   233,  -446
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -148,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -445,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -420,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -442,  -368,  -446,  -446,  -446,  -446,  -446,  -446,
      89,  -399,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -137,     6,  -446,    15,   212,   -93,   287,  -446,  -446,  -446,
    -446,  -446
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -175
static const yytype_int16 yytable[] =
{
     159,   520,   525,    54,   205,   205,   402,    25,   490,     1,
     490,   509,   510,   243,    30,   205,   493,   388,   389,    31,
      58,   209,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      38,    57,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    58,   273,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    96,   530,   533,    72,    73,    74,    75,    76,   390,
      70,    71,    72,    73,    74,    75,    76,   545,   515,   516,
     527,   256,   257,   258,   259,   260,    39,   406,   263,   264,
     265,   489,   435,   269,    40,   271,   492,   391,   392,    41,
     116,    42,    53,   275,   393,   394,   395,   396,   397,   535,
      93,    43,   536,   537,   383,    74,    75,    76,   403,   404,
     131,   132,    44,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   206,   206,   521,   526,   399,   400,
     -47,   301,    55,   244,    45,   206,    56,   401,   531,   532,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,   117,
     118,   119,   120,   307,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,    46,   384,    47,    48,    49,   149,    50,
      55,   163,   166,   385,   386,   164,    58,   165,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -2,   180,   202,   154,
     210,   410,   411,   412,   213,   216,   415,   219,   248,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   255,   261,    -5,    -5,
     266,   262,   485,   268,   270,   272,   312,   281,   488,   282,
     283,   284,   -47,   -47,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   491,    28,   296,
     -47,    34,    35,    36,    37,   475,   476,   477,   478,   479,
     297,   298,   482,   299,   300,   382,   405,   406,   413,   414,
     433,    52,   487,   434,   435,   438,   451,   470,   471,   472,
      79,   474,   480,   481,   483,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   484,   313,
     486,   534,   523,   540,   541,   542,   544,   535,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   157,   -30,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   548,   160,   161,   162,   549,   550,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   529,   409,
     547,   552,   314,   315,   316,   317,   318,   319,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
     539,     0,     0,     0,     0,   543,   177,     0,     0,     0,
       0,   178,   546,     0,   179,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   551,     0,     0,
       0,   514,   514,   514,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   -30,   -30,    58,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,    58,   -30,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      58,   304,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,     0,     0,    94,   452,   453,   454,   455,   456,   457,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    58,   146,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,     0,     0,     0,    58,   147,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    58,   148,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,     0,    28,
      28,    28,    28,    28,    28,   150,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,     0,    58,   151,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    58,   152,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,   361,     0,     0,    58,   153,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,  -130,
       0,     0,    58,   155,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     0,     0,     0,     0,     4,     5,   156,
       0,     0,     6,     7,     0,     0,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,   511,   512,     0,     0,     0,
       0,     0,   321,     0,     0,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,     0,     0,     0,   -67,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -130,  -130,     0,     0,     0,     0,     0,   251,
       0,     0,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,     0,     0,     0,     0,   380,     0,     0,   341,     0,
       0,     0,   252,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
       4,     5,   346,   -93,     0,     6,     7,   253,     0,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,  -109,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -67,   -67,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,     0,     0,     0,     0,     0,   342,   343,     0,     0,
       0,     0,    58,   339,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     7,   -93,   -93,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,   506,     0,   344,
    -109,  -109,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,   528,     0,     4,     5,   182,     0,     0,
       6,     7,     0,   359,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     4,     5,     0,     0,     0,     6,     7,     0,     0,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,   308,   183,     0,    58,
     181,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   184,
     185,  -162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,     0,     0,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,     0,     0,  -174,  -174,     0,     0,     0,
       0,     0,     0,     0,    24,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,   310,  -162,  -162
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-446)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      93,    26,    26,    18,    27,    27,    48,     1,   407,    64,
     409,   453,   454,    27,     0,    27,   436,    64,    65,    50,
       3,   169,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     167,    26,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     3,   200,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    56,   492,   518,    18,    19,    20,    21,    22,   126,
      16,    17,    18,    19,    20,    21,    22,   532,   456,   457,
     489,   184,   185,   186,   187,   188,   167,   167,   191,   192,
     193,   171,   167,   196,   167,   198,   171,   154,   155,   167,
       1,   167,    53,   206,   161,   162,   163,   164,   165,   167,
     171,   167,   170,   171,     1,    20,    21,    22,   170,   171,
     139,   140,   167,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   167,   167,   171,   171,   170,   171,
      27,   244,   167,   167,   167,   167,   171,   305,   170,   171,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   266,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   167,    61,   167,   167,   167,   171,   167,
     167,    26,    44,    70,    71,    27,     3,    27,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,   168,    26,   171,
      26,   314,   315,   316,    26,    26,   319,    26,   166,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   169,   169,   139,   140,
     167,    49,   400,    27,    27,    48,   168,    29,   406,    29,
      29,    29,   139,   140,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   435,     1,    26,
     167,     4,     5,     6,     7,   388,   389,   390,   391,   392,
      26,    26,   395,    26,    26,   168,   171,   167,    26,    26,
      26,    24,   405,    45,   167,    26,    26,    26,   169,    26,
      33,    26,    26,    26,    26,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   169,     1,
      48,    26,   171,   168,   168,    26,   168,   167,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,   171,    27,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   168,    97,    98,    99,   168,   171,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   491,   310,
     537,   168,    64,    65,    66,    67,    68,    69,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     523,    -1,    -1,    -1,    -1,   528,   149,    -1,    -1,    -1,
      -1,   154,   535,    -1,   157,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   550,    -1,    -1,
      -1,   455,   456,   457,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   139,   140,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,     3,   167,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       3,   254,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,    -1,    -1,   168,   362,   363,   364,   365,   366,   367,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,     3,   168,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,     3,   168,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,     3,   168,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,    -1,   452,
     453,   454,   455,   456,   457,   168,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,     3,   168,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     3,   168,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     1,    -1,    -1,     3,   168,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    26,
      -1,    -1,     3,   168,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    18,    19,   168,
      -1,    -1,    23,    24,    -1,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    26,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,   162,    -1,    -1,     1,    -1,
      -1,    -1,   168,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      18,    19,     1,    26,    -1,    23,    24,   168,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   167,    26,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,     3,   162,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    23,    24,   139,   140,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,   162,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,    -1,   171,    -1,    18,    19,     1,    -1,    -1,
      23,    24,    -1,   162,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    18,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     1,    61,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    83,
      84,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,   135,   136,    -1,    -1,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    64,   173,   174,    18,    19,    23,    24,    27,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   167,   253,   254,   255,   258,   259,
       0,    50,   175,   167,   258,   258,   258,   258,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   257,   258,    53,    18,   167,   171,   255,     3,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   176,   178,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   171,   168,   258,   255,   260,   262,   263,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,     1,    60,    61,    62,
      63,   177,    51,    52,    53,    54,    55,    56,    57,    58,
      59,   139,   140,   179,   180,   187,   188,   198,   204,   212,
     218,   226,   234,   241,   244,   245,   168,   168,   168,   171,
     168,   168,   168,   168,   171,   168,   168,   171,   168,   257,
     258,   258,   258,    26,    27,    27,    44,   235,   227,   181,
     199,   205,   213,   219,   242,   189,   246,   258,   258,   258,
     168,     4,     1,    61,    83,    84,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   135,
     136,   236,    26,   228,   229,    27,   167,   182,   183,   184,
      26,   200,   201,    26,   206,   207,    26,   214,   215,    26,
     220,   221,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   243,    27,   167,   190,   191,   192,   166,   247,
     248,   168,   168,   168,   261,   169,   257,   257,   257,   257,
     257,   169,    49,   257,   257,   257,   167,   239,    27,   257,
      27,   257,    48,   184,   230,   257,   185,   202,   208,   216,
     222,    29,    29,    29,    29,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,    26,    26,    26,    26,
      26,   257,   193,   249,   258,   237,   238,   257,     1,   137,
     138,   231,   168,     1,    64,    65,    66,    67,    68,    69,
     186,     1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   162,
     203,     1,    89,    90,   162,   209,     1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   162,
     217,     1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     162,   223,   168,     1,    61,    70,    71,   194,    64,    65,
     126,   154,   155,   161,   162,   163,   164,   165,   250,   170,
     171,   184,    48,   170,   171,   171,   167,   232,   233,   232,
     257,   257,   257,    26,    26,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,    26,    45,   167,   210,   211,    26,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,    26,   256,   256,   256,   256,   256,   256,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
      26,   169,    26,   197,    26,   257,   257,   257,   257,   257,
      26,    26,   257,    26,   169,   184,    48,   257,   184,   171,
     233,   184,   171,   211,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,    46,   224,   253,   224,
     224,    46,    47,   225,   253,   225,   225,   184,   195,   196,
      26,   171,   251,   171,   240,    26,   171,   233,   171,   257,
     211,   170,   171,   196,    26,   167,   170,   171,   252,   257,
     168,   168,    26,   257,   168,   196,   257,   252,   168,   168,
     171,   257,   168
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1787 of yacc.c  */
#line 199 "parser.y"
    {
		last_x = 0;
		last_y = 0;
		last_z = 0;
		last_material = NULL;
		last_constraint = NULL;
	    }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 225 "parser.y"
    {
		Deallocate (problem.title);
		problem.title = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    {
		problem.num_nodes = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    {
		problem.num_elements = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    {
		problem.mode = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 292 "parser.y"
    {
		if ((yyvsp[(1) - (1)].i) < 1 || (yyvsp[(1) - (1)].i) > problem.num_nodes) {
		    error ("node number %u is illegal", (yyvsp[(1) - (1)].i));
		    node = &dummy_node;
		    break;
		}

		node = CreateNode ((yyvsp[(1) - (1)].i));
		found = TreeInsert (problem.node_tree, node);

		if (found != (Item) node) {
		    error ("node number %u is repeated", (yyvsp[(1) - (1)].i));
		    DestroyNode (node);
		    node = &dummy_node;
		    break;
		}

		node -> x = last_x;
		node -> y = last_y;
		node -> z = last_z;
		node -> constraint = last_constraint ?
			(Constraint) strdup (last_constraint) : NULL;
	    }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 321 "parser.y"
    {(yyval.i) = (yyvsp[(2) - (3)].d);}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 333 "parser.y"
    {
		node -> x = last_x = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 338 "parser.y"
    {
		node -> y = last_y = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 343 "parser.y"
    {
		node -> z = last_z = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 348 "parser.y"
    {
                node -> m = (yyvsp[(2) - (2)].d);
            }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 353 "parser.y"
    {
		Deallocate (node -> force);
		node -> force = (Force) (yyvsp[(2) - (2)].s);
	    }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 359 "parser.y"
    {
		node -> constraint = (Constraint) (last_constraint = (yyvsp[(2) - (2)].s));
	    }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 376 "parser.y"
    {
		definition = defnlookup ((yyvsp[(1) - (1)].s));
		Deallocate ((yyvsp[(1) - (1)].s));
		if (!definition)
		    return 1;
	    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 398 "parser.y"
    {
		if ((yyvsp[(1) - (1)].i) < 1 || (yyvsp[(1) - (1)].i) > problem.num_elements) {
		    error ("element number %u is illegal", (yyvsp[(1) - (1)].i));
		    element = &dummy_element;
		    break;
		}

		element = CreateElement ((yyvsp[(1) - (1)].i), definition);
		found = TreeInsert (problem.element_tree, element);

		if (found != (Item) element) {
		    error ("element number %u is repeated", (yyvsp[(1) - (1)].i));
		    DestroyElement (element);
		    element = &dummy_element;
		    break;
		}

		element -> material = last_material ?
			(Material) strdup (last_material) : NULL;
	    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 424 "parser.y"
    {(yyval.i) = (yyvsp[(2) - (3)].d);}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 436 "parser.y"
    {
		unsigned i;
		unsigned size;
		unsigned number;


		if (element == &dummy_element)
		    break;

		size = int_ptr - int_array;

		if (size != element -> definition -> numnodes) {
		    number = element -> number;
		    error ("incorrect number of nodes for element %u", number);
		    break;
		}

		for (i = 1; i <= size; i ++)
		    element -> node [i] = (Node) int_array [i - 1];
	    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 458 "parser.y"
    {
		element -> material = (Material) (last_material = (yyvsp[(2) - (2)].s));
	    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 470 "parser.y"
    {
		*int_ptr ++ = (yyvsp[(3) - (3)].i);
	    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 475 "parser.y"
    {
		*int_ptr ++ = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 480 "parser.y"
    {
		int_ptr = int_array;
		*int_ptr ++ = (yyvsp[(1) - (1)].i);
	    }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 489 "parser.y"
    {
		if ((yyvsp[(1) - (1)].i) > problem.num_nodes)
		    error ("node number %u is illegal", (yyvsp[(1) - (1)].i));
	    }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 498 "parser.y"
    {
		if (element -> numdistributed == 3) {
		    error ("element %u has too many loads", element -> number);
		    break;
		}

		element -> numdistributed ++;
		Deallocate (element -> distributed [element -> numdistributed]);
		element -> distributed [element -> numdistributed] =
		  (Distributed) (yyvsp[(3) - (3)].s);
	    }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 511 "parser.y"
    {
		if (element -> numdistributed == 3) {
		    error ("element %u has too many loads", element -> number);
		    break;
		}

		element -> numdistributed ++;
		Deallocate (element -> distributed [element -> numdistributed]);
		element -> distributed [element -> numdistributed] =
		  (Distributed) (yyvsp[(2) - (2)].s);
	    }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 524 "parser.y"
    {
		element -> numdistributed = 1;
		Deallocate (element -> distributed [element -> numdistributed]);
		element -> distributed [element -> numdistributed] =
		  (Distributed) (yyvsp[(1) - (1)].s);
	    }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 553 "parser.y"
    {
		material = CreateMaterial ((yyvsp[(1) - (1)].s));
		found = TreeInsert (problem.material_tree, material);

		if (found != (Item) material) {
		    error ("material %s is previously defined", (yyvsp[(1) - (1)].s));
		    DestroyMaterial (material);
		    material = &dummy_material;
		}
	    }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 573 "parser.y"
    {
		Deallocate (material -> color);
                material -> color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 579 "parser.y"
    {
		material -> E = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 584 "parser.y"
    {
		material -> Ix = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 589 "parser.y"
    {
		material -> Iy = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 594 "parser.y"
    {
		material -> Iz = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 599 "parser.y"
    {
		material -> A = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 604 "parser.y"
    {
		material -> J = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 609 "parser.y"
    {
		material -> G = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 614 "parser.y"
    {
		material -> t = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 619 "parser.y"
    {
		material -> rho = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 624 "parser.y"
    {
		material -> nu = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 629 "parser.y"
    {
		material -> kappa = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 634 "parser.y"
    {
		material -> Rk = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 639 "parser.y"
    {
		material -> Rm = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 644 "parser.y"
    {
                material -> Kx = (yyvsp[(2) - (2)].d);
            }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 649 "parser.y"
    {
                material -> Ky = (yyvsp[(2) - (2)].d);
            }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 654 "parser.y"
    {
                material -> Kz = (yyvsp[(2) - (2)].d);
            }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 659 "parser.y"
    {
                material -> c = (yyvsp[(2) - (2)].d);
            }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 687 "parser.y"
    {
		load = CreateDistributed ((yyvsp[(1) - (1)].s), 0);
		found = TreeInsert (problem.distributed_tree, load);

		if (found != (Item) load) {
		    error ("load %s is previously defined", (yyvsp[(1) - (1)].s));
		    DestroyDistributed (load);
		    load = &dummy_load;
		}
	    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 708 "parser.y"
    {
		Deallocate (load -> color);
                load -> color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 714 "parser.y"
    {
		load -> direction = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 719 "parser.y"
    {
		unsigned i;
		unsigned size;


		if (load == &dummy_load)
		    break;

		size = pair_ptr - pair_array;

		if (!(load -> value = Allocate (Pair, size)))
		    Fatal ("unable to allocate memory for pairs");

		UnitOffset (load -> value);
		load -> nvalues = size;

		for (i = 1; i <= size; i ++)
		    load -> value [i] = pair_array [i - 1];
	    }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 745 "parser.y"
    {
		*pair_ptr ++ = (yyvsp[(3) - (3)].p);
	    }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 750 "parser.y"
    {
		*pair_ptr ++ = (yyvsp[(2) - (2)].p);
	    }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 755 "parser.y"
    {
		pair_ptr = pair_array;
		*pair_ptr ++ = (yyvsp[(1) - (1)].p);
	    }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 764 "parser.y"
    {
		if ((yyvsp[(2) - (5)].i) < 1 || (yyvsp[(2) - (5)].i) > problem.num_nodes)
		    error ("node number %u is illegal", (yyvsp[(2) - (5)].i));

		(yyval.p).node = (yyvsp[(2) - (5)].i);
		(yyval.p).magnitude = (yyvsp[(4) - (5)].d);
	    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 773 "parser.y"
    {
		if ((yyvsp[(2) - (4)].i) < 1 || (yyvsp[(2) - (4)].i) > problem.num_nodes)
		    error ("node number %u is illegal", (yyvsp[(2) - (4)].i));

		(yyval.p).node = (yyvsp[(2) - (4)].i);
		(yyval.p).magnitude = (yyvsp[(3) - (4)].d);
	    }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 803 "parser.y"
    {
		force = CreateForce ((yyvsp[(1) - (1)].s));
		found = TreeInsert (problem.force_tree, force);

		if (found != (Item) force) {
		    error ("force %s is previously defined", (yyvsp[(1) - (1)].s));
		    DestroyForce (force);
		    force = &dummy_force;
		}
	    }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 824 "parser.y"
    {
		Deallocate (force -> color);
                force -> color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 830 "parser.y"
    {
		AssignForce (force, Fx, InCore, copy_input (0));
	    }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 835 "parser.y"
    {
		AssignForce (force, Fy, InCore, copy_input (0));
	    }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 840 "parser.y"
    {
		AssignForce (force, Fz, InCore, copy_input (0));
	    }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 845 "parser.y"
    {
		AssignForce (force, Mx, InCore, copy_input (0));
	    }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 850 "parser.y"
    {
		AssignForce (force, My, InCore, copy_input (0));
	    }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 855 "parser.y"
    {
		AssignForce (force, Mz, InCore, copy_input (0));
	    }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 860 "parser.y"
    {
		AssignSpectrum (force, Fx, InCore, copy_input (0));
	    }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 865 "parser.y"
    {
		AssignSpectrum (force, Fy, InCore, copy_input (0));
	    }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 870 "parser.y"
    {
		AssignSpectrum (force, Fz, InCore, copy_input (0));
	    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 875 "parser.y"
    {
		AssignSpectrum (force, Mx, InCore, copy_input (0));
	    }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 880 "parser.y"
    {
		AssignSpectrum (force, My, InCore, copy_input (0));
	    }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 885 "parser.y"
    {
		AssignSpectrum (force, Mz, InCore, copy_input (0));
	    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 913 "parser.y"
    {
		constraint = CreateConstraint ((yyvsp[(1) - (1)].s));
		found = TreeInsert (problem.constraint_tree, constraint);

		if (found != (Item) constraint) {
		    error ("constraint %s is previously defined", (yyvsp[(1) - (1)].s));
		    DestroyConstraint (constraint);
		    constraint = &dummy_constraint;
		}
	    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 934 "parser.y"
    {
		Deallocate (constraint -> color);
                constraint -> color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 940 "parser.y"
    {
                if ((yyvsp[(3) - (3)].c) == VariableExpression)
                   AssignConstraint (constraint, Tx, InCore, copy_input(0), 1);
                else  {
                   AssignConstraint (constraint, Tx, NULL, NULL, (yyvsp[(3) - (3)].c));
		   copy_input (0);
		}
	    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 950 "parser.y"
    {
                if ((yyvsp[(3) - (3)].c) == VariableExpression)
                   AssignConstraint (constraint, Ty, InCore, copy_input(0), 1);
                else {
                   AssignConstraint (constraint, Ty, NULL, NULL, (yyvsp[(3) - (3)].c));
		   copy_input (0);
		}
	    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 960 "parser.y"
    {
                if ((yyvsp[(3) - (3)].c) == VariableExpression)
                   AssignConstraint (constraint, Tz, InCore, copy_input(0), 1);
                else {
                   AssignConstraint (constraint, Tz, NULL, NULL, (yyvsp[(3) - (3)].c));
		   copy_input (0);
		}
	    }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 970 "parser.y"
    {
                if ((yyvsp[(3) - (3)].c) == VariableExpression)
                   AssignConstraint (constraint, Rx, InCore, copy_input(0), 1);
                else {
                   AssignConstraint (constraint, Rx, NULL, NULL, (yyvsp[(3) - (3)].c));
		   copy_input (0);
		}
	    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 980 "parser.y"
    {
                if ((yyvsp[(3) - (3)].c) == VariableExpression)
                   AssignConstraint (constraint, Ry, InCore, copy_input(0), 1);
                else {
                   AssignConstraint (constraint, Ry, NULL, NULL, (yyvsp[(3) - (3)].c));
		   copy_input (0);
		}
	    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 990 "parser.y"
    {
                if ((yyvsp[(3) - (3)].c) == VariableExpression)
                   AssignConstraint (constraint, Rz, InCore, copy_input(0), 1);
                else {
                   AssignConstraint (constraint, Rz, NULL, NULL, (yyvsp[(3) - (3)].c));
		   copy_input (0);
		}
	    }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1000 "parser.y"
    {
                constraint -> ix [Tx] = (yyvsp[(2) - (2)].d);
            }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1005 "parser.y"
    {
                constraint -> ix [Ty] = (yyvsp[(2) - (2)].d);
            }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1010 "parser.y"
    {
                constraint -> ix [Tz] = (yyvsp[(2) - (2)].d);
            }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1015 "parser.y"
    {
                constraint -> ix [Rx] = (yyvsp[(2) - (2)].d);
            }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1020 "parser.y"
    {
                constraint -> ix [Ry] = (yyvsp[(2) - (2)].d);
            }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1025 "parser.y"
    {
                constraint -> ix [Rz] = (yyvsp[(2) - (2)].d);
            }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1030 "parser.y"
    {
		constraint -> vx [Tx] = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1035 "parser.y"
    {
		constraint -> vx [Ty] = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1040 "parser.y"
    {
		constraint -> vx [Tz] = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1045 "parser.y"
    {
		constraint -> ax [Tx] = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1050 "parser.y"
    {
		constraint -> ax [Ty] = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1055 "parser.y"
    {
		constraint -> ax [Tz] = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1065 "parser.y"
    {
		(yyval.c) = VariableExpression;
	    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1070 "parser.y"
    {
		(yyval.c) = (yyvsp[(1) - (1)].i);
	    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1078 "parser.y"
    {
		(yyval.c) = VariableExpression;
	    }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1083 "parser.y"
    {
		(yyval.c) = (yyvsp[(1) - (1)].i);
	    }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1088 "parser.y"
    {
		(yyval.c) = (yyvsp[(1) - (1)].i);
	    }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1112 "parser.y"
    {
		loadcase = CreateLoadCase ((yyvsp[(1) - (1)].s));
		found = TreeInsert (problem.loadcase_tree, loadcase);

		if (found != (Item) loadcase) {
		    error ("loadcase %s is previously defined", (yyvsp[(1) - (1)].s));
		    DestroyLoadCase (loadcase);
		    loadcase = &dummy_loadcase;
		}
	    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1131 "parser.y"
    {
		unsigned i;
		unsigned size;


		if (loadcase == &dummy_loadcase)
		    break;

		size = case_ptr - case_array;

		if (!(loadcase -> nodes = Allocate (Node, size)) ||
                    !(loadcase -> forces = Allocate (Force, size)))
		    Fatal ("unable to allocate memory for node case pairs");

		UnitOffset (loadcase -> nodes);
		UnitOffset (loadcase -> forces);
		loadcase -> numforces = size;

		for (i = 1; i <= size; i ++) {
		    loadcase -> nodes [i] = (Node) case_array [i - 1].noe;
                    loadcase -> forces [i]   = (Force) case_array [i - 1].fol;
                }
	    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1156 "parser.y"
    {
		unsigned i;
		unsigned size;


		if (loadcase == &dummy_loadcase)
		    break;

		size = case_ptr - case_array;

		if (!(loadcase -> elements = Allocate (Element, size)) ||
                    !(loadcase -> loads = Allocate (Distributed, size)))
		    Fatal ("unable to allocate memory for element case pairs");

		UnitOffset (loadcase -> elements);
		UnitOffset (loadcase -> loads);
		loadcase -> numloads = size;

		for (i = 1; i <= size; i ++) {
		    loadcase -> elements [i] = (Element) case_array [i - 1].noe;
                    loadcase -> loads [i]   = (Distributed) case_array [i - 1].fol;
                }
	    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1186 "parser.y"
    {
		*case_ptr ++ = (yyvsp[(3) - (3)].cp);
	    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1191 "parser.y"
    {
		*case_ptr ++ = (yyvsp[(2) - (2)].cp);
	    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1196 "parser.y"
    {
		case_ptr = case_array;
		*case_ptr ++ = (yyvsp[(1) - (1)].cp);
	    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1205 "parser.y"
    {
		if ((yyvsp[(2) - (5)].i) < 1 || (yyvsp[(2) - (5)].i) > problem.num_nodes)
		    error ("node number %u is illegal", (yyvsp[(2) - (5)].i));

		(yyval.cp).noe = (yyvsp[(2) - (5)].i);
		(yyval.cp).fol = (yyvsp[(4) - (5)].s);
	    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1214 "parser.y"
    {
		if ((yyvsp[(2) - (4)].i) < 1 || (yyvsp[(2) - (4)].i) > problem.num_nodes)
		    error ("node number %u is illegal", (yyvsp[(2) - (4)].i));

		(yyval.cp).noe = (yyvsp[(2) - (4)].i);
		(yyval.cp).fol = (yyvsp[(3) - (4)].s);
	    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1238 "parser.y"
    {
		analysis.alpha = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1243 "parser.y"
    {
		analysis.beta = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1248 "parser.y"
    {
		analysis.gamma = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1253 "parser.y"
    {
                analysis.Rk = (yyvsp[(2) - (2)].d);
            }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1258 "parser.y"
    {
                analysis.Rm = (yyvsp[(2) - (2)].d);
            }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1263 "parser.y"
    {
		analysis.start = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1268 "parser.y"
    {
		analysis.step = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1273 "parser.y"
    {
		analysis.stop = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1278 "parser.y"
    {
		analysis.iterations = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1283 "parser.y"
    {
		analysis.load_steps = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1288 "parser.y"
    {
		analysis.relaxation = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1293 "parser.y"
    {
		analysis.tolerance = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1298 "parser.y"
    {
                analysis.input_dof = (yyvsp[(2) - (2)].i);
            }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1303 "parser.y"
    {
                analysis.input_node = (Node) (yyvsp[(2) - (2)].i);
            }
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1308 "parser.y"
    {
		unsigned i;


		analysis.numnodes = int_ptr - int_array;

		if (!(analysis.nodes = Allocate (Node, analysis.numnodes)))
		    Fatal ("unable to allocate memory for analysis nodes");

		UnitOffset (analysis.nodes);
		for (i = 1; i <= analysis.numnodes; i ++)
		    analysis.nodes [i] = (Node) int_array [i - 1];
	    }
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1323 "parser.y"
    {
		int i;


		analysis.numdofs = 0;
		for (i = 1; i <= 6; i ++)
		    if (analysis.dofs [i])
			analysis.dofs [++ analysis.numdofs] = i;
	    }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1334 "parser.y"
    {
		analysis.mass_mode = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1339 "parser.y"
    {
                analysis.gravity [1] = triple_x;
                analysis.gravity [2] = triple_y;
                analysis.gravity [3] = triple_z;
            }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1351 "parser.y"
    {
		*int_ptr ++ = (yyvsp[(3) - (3)].i);
	    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1356 "parser.y"
    {
		*int_ptr ++ = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1361 "parser.y"
    {
		int_ptr = int_array;
	    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1369 "parser.y"
    {
		analysis.dofs [(yyvsp[(3) - (3)].i)] = 1;
	    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1374 "parser.y"
    {
		analysis.dofs [(yyvsp[(2) - (2)].i)] = 1;
	    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1379 "parser.y"
    {
		int i;


		for (i = 1; i <= 6; i ++)
		     analysis.dofs [i] = 0;
	    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1391 "parser.y"
    {
		triple_x = (yyvsp[(2) - (6)].d);
		triple_y = (yyvsp[(4) - (6)].d);
		triple_z = (yyvsp[(5) - (6)].d);
	    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1401 "parser.y"
    {
		(yyval.d) = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1406 "parser.y"
    {
                (yyval.d) = 0.0;
            }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1427 "parser.y"
    {
		appearance.node_numbers = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1432 "parser.y"
    {
		appearance.element_numbers = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1437 "parser.y"
    {
		appearance.snap = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1442 "parser.y"
    {
		appearance.grid = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1447 "parser.y"
    {
		appearance.snap_size = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1452 "parser.y"
    {
		appearance.grid_size = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1457 "parser.y"
    {
		appearance.x_min = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1462 "parser.y"
    {
		appearance.x_max = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1467 "parser.y"
    {
		appearance.y_min = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1472 "parser.y"
    {
		appearance.y_max = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1477 "parser.y"
    {
		appearance.x_pos = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1482 "parser.y"
    {
		appearance.y_pos = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1487 "parser.y"
    {
		appearance.width = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1492 "parser.y"
    {
		appearance.height = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1497 "parser.y"
    {
		appearance.scale = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1502 "parser.y"
    {
		Deallocate (appearance.node_color);
		appearance.node_color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1508 "parser.y"
    {
		Deallocate (appearance.element_color);
		appearance.element_color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1514 "parser.y"
    {
		Deallocate (appearance.label_font);
		appearance.label_font = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1520 "parser.y"
    {
		Deallocate (appearance.tool_color);
		appearance.tool_color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1526 "parser.y"
    {
		Deallocate (appearance.tool_font);
		appearance.tool_font = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1542 "parser.y"
    {
		figure_size = 0;
	    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1561 "parser.y"
    {
		if (appearance.num_figures == figure_size) {
		    figure_size = figure_size ? figure_size <<= 1 : 4;
		    if (!Reallocate (appearance.figures, FigInfo, figure_size))
			Fatal ("unable to allocate figure list");
		}

		figure = &appearance.figures [appearance.num_figures ++];
		figure -> type = (yyvsp[(1) - (1)].i);
		figure -> x = 0;
		figure -> y = 0;
		figure -> width = 0;
		figure -> height = 0;
		figure -> start = 0;
		figure -> length = 0;
		figure -> num_points = 0;
		figure -> points = NULL;
		figure -> font = NULL;
		figure -> text = NULL;
		figure -> color = NULL;
	    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1593 "parser.y"
    {
		figure -> x = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1598 "parser.y"
    {
		figure -> y = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 1603 "parser.y"
    {
		figure -> width = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 1608 "parser.y"
    {
		figure -> height = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 1613 "parser.y"
    {
		figure -> start = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1618 "parser.y"
    {
		figure -> length = (yyvsp[(2) - (2)].d);
	    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1623 "parser.y"
    {
		Deallocate (figure -> text);
		figure -> text = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1629 "parser.y"
    {
		Deallocate (figure -> color);
		figure -> color = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1635 "parser.y"
    {
		Deallocate (figure -> font);
		figure -> font = (yyvsp[(2) - (2)].s);
	    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1646 "parser.y"
    {
		if (fig_point_size == figure -> num_points) {
		    fig_point_size <<= 1;
		    Reallocate (figure -> points, FigInfoPair, fig_point_size);
		    if (figure -> points == NULL)
			Fatal ("unable to allocate figure points");
		}

		figure -> points [figure -> num_points].x = figure_x;
		figure -> points [figure -> num_points ++].y = figure_y;
	    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1659 "parser.y"
    {
		if (fig_point_size == figure -> num_points) {
		    fig_point_size <<= 1;
		    Reallocate (figure -> points, FigInfoPair, fig_point_size);
		    if (figure -> points == NULL)
			Fatal ("unable to allocate figure points");
		}

		figure -> points [figure -> num_points].x = figure_x;
		figure -> points [figure -> num_points ++].y = figure_y;
	    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1672 "parser.y"
    {
		figure -> points = Allocate (FigInfoPair, 2);
		if (figure -> points == NULL)
		    Fatal ("unable to allocate figure points");

		fig_point_size = 2;
		figure -> num_points = 0;
	    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1685 "parser.y"
    {
		figure_x = (yyvsp[(2) - (5)].d);
		figure_y = (yyvsp[(4) - (5)].d);
	    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1696 "parser.y"
    {
		EmitCode (HaltOp);
		SetIP (0);
	    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1702 "parser.y"
    {
		if (table_error)
		    EmitCode (PushOp, 0.0);
		else
		    EmitCode (TableOp, table, table_count);

		EmitCode (HaltOp);
		table_count = 0;
		table_error = 0;
		last_time = 0;
		SetIP (0);
	    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1716 "parser.y"
    {
		if (table_error)
		    EmitCode (PushOp, 0.0);
		else
		    EmitCode (CycleOp, table, table_count);

		EmitCode (HaltOp);
		table_count = 0;
		table_error = 0;
		last_time = 0;
		SetIP (0);
	    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 1740 "parser.y"
    {
		if ((yyvsp[(2) - (5)].d) < last_time) {
		    error ("point not in nondecreasing order");
		    table_error = 1;
		    break;
		}

		if (table_count == table_size) {
		    table_size = table_size ? table_size << 1 : 8;
		    if (!Reallocate (table, double, table_size))
			Fatal ("unable to expand table");
		}

		table [table_count ++] = last_time = (yyvsp[(2) - (5)].d);
		table [table_count ++] = (yyvsp[(4) - (5)].d);
	    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 1761 "parser.y"
    {
		copy_input (1);
	    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 1769 "parser.y"
    {
		EmitCode (HaltOp);
		SetIP (0);
		(yyval.d) = EvalCode (InCore, 0.0);
	    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 1779 "parser.y"
    {
		int ip = GetIP ( );
		SetIP (ip - (yyvsp[(7) - (7)].i) - 2);
		EmitCode (JmpOp, (yyvsp[(7) - (7)].i));
		SetIP (GetIP ( ) - (yyvsp[(4) - (7)].i) - 4);
		EmitCode (JzOp, (yyvsp[(4) - (7)].i) + 2);
		SetIP (ip);
		(yyval.i) = (yyvsp[(1) - (7)].i) + (yyvsp[(3) - (7)].i) + (yyvsp[(4) - (7)].i) + (yyvsp[(6) - (7)].i) + (yyvsp[(7) - (7)].i);
	    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1790 "parser.y"
    {
		int ip = GetIP ( );
		SetIP (ip - (yyvsp[(4) - (4)].i) - 3);
		EmitCode (JnzOp, (yyvsp[(4) - (4)].i) + 1);
		SetIP (ip);
		EmitCode (TestOp);
		(yyval.i) = (yyvsp[(1) - (4)].i) + (yyvsp[(3) - (4)].i) + (yyvsp[(4) - (4)].i) + 1;
	    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 1800 "parser.y"
    {
		int ip = GetIP ( );
		SetIP (ip - (yyvsp[(4) - (4)].i) - 3);
		EmitCode (JzOp, (yyvsp[(4) - (4)].i) + 1);
		SetIP (ip);
		EmitCode (TestOp);
		(yyval.i) = (yyvsp[(1) - (4)].i) + (yyvsp[(3) - (4)].i) + (yyvsp[(4) - (4)].i) + 1;
	    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 1810 "parser.y"
    {
		EmitCode (OrOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 1816 "parser.y"
    {
		EmitCode (XorOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1822 "parser.y"
    {
		EmitCode (AndOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1828 "parser.y"
    {
		EmitCode (EqOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1834 "parser.y"
    {
		EmitCode (NeqOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1840 "parser.y"
    {
		EmitCode (LtOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1846 "parser.y"
    {
		EmitCode (GtOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1852 "parser.y"
    {
		EmitCode (LteqOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 1858 "parser.y"
    {
		EmitCode (GteqOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 1864 "parser.y"
    {
		EmitCode (LsftOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 1870 "parser.y"
    {
		EmitCode (RsftOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1876 "parser.y"
    {
		EmitCode (AddOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1882 "parser.y"
    {
		EmitCode (SubOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1888 "parser.y"
    {
		EmitCode (MulOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1894 "parser.y"
    {
		EmitCode (DivOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1900 "parser.y"
    {
		EmitCode (ModOp);
		(yyval.i) = (yyvsp[(1) - (3)].i) + 1 + (yyvsp[(3) - (3)].i);
	    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1906 "parser.y"
    {
		(yyval.i) = (yyvsp[(2) - (2)].i);
	    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1911 "parser.y"
    {
		EmitCode (NegOp);
		(yyval.i) = 1 + (yyvsp[(2) - (2)].i);
	    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1917 "parser.y"
    {
		EmitCode (NotOp);
		(yyval.i) = 1 + (yyvsp[(2) - (2)].i);
	    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1923 "parser.y"
    {
		EmitCode (InvOp);
		(yyval.i) = 1 + (yyvsp[(2) - (2)].i);
	    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1929 "parser.y"
    {
		(yyval.i) = (yyvsp[(2) - (3)].i);
	    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1934 "parser.y"
    {
		EmitCode (PushOp, (double) (yyvsp[(1) - (1)].i));
		(yyval.i) = 2;
	    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1940 "parser.y"
    {
		EmitCode (PushOp, (yyvsp[(1) - (1)].d));
		(yyval.i) = 2;
	    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1946 "parser.y"
    {
		EmitCode (TimeOp);
		(yyval.i) = 1;
	    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1957 "parser.y"
    {
		EmitCode (SinOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 1963 "parser.y"
    {
		EmitCode (CosOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1969 "parser.y"
    {
		EmitCode (TanOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 1975 "parser.y"
    {
		EmitCode (PowOp);
		(yyval.i) = (yyvsp[(3) - (6)].i) + (yyvsp[(5) - (6)].i) + 1;
	    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1981 "parser.y"
    {
		EmitCode (ExpOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1987 "parser.y"
    {
		EmitCode (LnOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1993 "parser.y"
    {
		EmitCode (LogOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1999 "parser.y"
    {
		EmitCode (SqrtOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 2005 "parser.y"
    {
		EmitCode (HypotOp);
		(yyval.i) = (yyvsp[(3) - (6)].i) + (yyvsp[(5) - (6)].i) + 1;
	    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 2011 "parser.y"
    {
		EmitCode (FloorOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 2017 "parser.y"
    {
		EmitCode (CeilOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 2023 "parser.y"
    {
		EmitCode (FmodOp);
		(yyval.i) = (yyvsp[(3) - (6)].i) + (yyvsp[(5) - (6)].i) + 1;
	    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 2029 "parser.y"
    {
		EmitCode (FabsOp);
		(yyval.i) = (yyvsp[(3) - (4)].i) + 1;
	    }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 2038 "parser.y"
    {
		EmitCode (JzOp, 0);
		(yyval.i) = 2;
	    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 2047 "parser.y"
    {
		EmitCode (JmpOp, 0);
		(yyval.i) = 2;
	    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 2056 "parser.y"
    {
		EmitCode (CopyOp);
		EmitCode (JnzOp, 0);
		EmitCode (PopOp);
		(yyval.i) = 4;
	    }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 2067 "parser.y"
    {
		EmitCode (CopyOp);
		EmitCode (JzOp, 0);
		EmitCode (PopOp);
		(yyval.i) = 4;
	    }
    break;


/* Line 1787 of yacc.c  */
#line 4575 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 2075 "parser.y"


# ifdef YYBYACC
char *felt_suppress_warnings_from_gcc = yysccsid;
# endif
