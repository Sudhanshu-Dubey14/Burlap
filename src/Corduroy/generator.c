/*
    This file is part of the FElt finite element analysis package.
    Copyright (C) 1993-2000 Jason I. Gobat and Darren C. Atkinson

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
 * File:	generator.c						*
 *									*
 * Description:	This file contains the public and private function	*
 *		definitions which relate to the generator instance.	*
 ************************************************************************/

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "error.h"
# include "generator.h"
# include "definition.h"

# ifdef NEED_STRDUP
extern char *strdup ( );
# endif


# define streq(a,b)	!strcmp(a,b)
# define strneq(a,b)	strcmp(a,b)

# ifndef LIBDIR
# define LIBDIR "/usr/local/lib/felt"
# endif

# ifndef CPP
# define CPP "/lib/cpp"
# endif


Generator generator;

static char *cpp;
static char  cpp_command [2048];

/************************************************************************
 * Function:	ReadCorduroyFile					*
 *									*
 * Description:	Reads a corduroy file using the preprocessor if		*
 *		desired.  A filename of "-" indicates standard input	*
 *		(can only be used initially) and a NULL filename	*
 *		indicates no file (an empty generation instance is	*
 *		created).						*
 ************************************************************************/

int ReadCorduroyFile (input_name)
    char *input_name;
{
    char  buffer [2048];
    char *plural;
    FILE *input;

	/* open the file and send it through the pre-processor */
    
    if (input_name) {
# ifndef DOS
	if (cpp != NULL) {
	    if (streq (input_name, "-"))
		sprintf (buffer, "%s", cpp_command);
	    else {
		if (access (input_name, R_OK)) {
		    error ("Unable to open %s", input_name);
		    return 1;
		}
		sprintf (buffer, "%s %s", cpp_command, input_name);
	    }

	    if (!(input = popen (buffer, "r"))) {
		error ("Unable to execute %s", cpp);
		return 1;
	    }

	} else
# endif
	{
	    if (streq (input_name, "-"))
		input = stdin;
	    else if (!(input = fopen (input_name, "r"))) {
		error ("Unable to open %s", input_name);
		return 1;
	    }
	}
    } else
	input = NULL;

    /* Initialize the generator instance. */

    generator.start_node    = 1;
    generator.start_element = 1;
    generator.material      = NULL;
    generator.constraint    = NULL;
    generator.num_errors    = 0;
    generator.line	    = 1;
    generator.lines	    = NULL;
    generator.grids	    = NULL;
    generator.quadgrids	    = NULL;
    generator.trimeshes	    = NULL;
    generator.num_lines	    = 0;
    generator.num_grids	    = 0;
    generator.num_quadgrids = 0;
    generator.num_trimeshes = 0;

    if (input_name) 
	generator.filename = strdup (streq(input_name, "-") ? "stdin" : input_name);
    else
	generator.filename = strdup ("");

    /* Parse the input. */
    
    if (input_name) {
	init_lexer (input);
	yyparse ( );
	generator.line = 0;

# ifdef DOS
        fclose (input);
# else
	if (cpp)
	    pclose (input);
	else
	    fclose (input);
# endif

	/* Report any errors. */

	if (generator.num_errors) {
	    plural = generator.num_errors != 1 ? "errors" : "error";
	    error ("%u %s found in input", generator.num_errors, plural);
	    return generator.num_errors;
	}
    }
    
    return 0;
}

/************************************************************************
 * Function:	CorduroyCppOptions						*
 *									*
 * Description:	Parses and removes the preprocesor options from the	*
 *		command line arguments.					*
 ************************************************************************/

int CorduroyCppOptions (argc, argv)
    int  *argc;
    char *argv [ ];
{
    int   i;
    int   j;
    char *arg;
    char  cpp_args [2048];


    j = 1;
    cpp = CPP;

    cpp_args [0] = 0;

    for (i = 1; i < *argc; i ++)
	if ((arg = argv [i]) [0] != '-') {
	    argv [j ++] = arg;
	} else if (streq (arg, "-nocpp")) {
	    cpp = NULL;
	} else if (streq (arg, "-cpp")) {
	    if (++ i == *argc)
		return 1;
	    cpp = argv [i];
	} else if (arg [1] == 'D' || arg [1] == 'U' || arg [1] == 'I') {
	    strcat (cpp_args, " '");
	    strcat (cpp_args, arg);
	    strcat (cpp_args, "'");
	} else
	    argv [j ++] = arg;


    if (cpp)
	sprintf (cpp_command, "%s -I%s %s", cpp, LIBDIR, cpp_args);

    argv [*argc = j] = NULL;
    return 0;
}
