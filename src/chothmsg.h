/******************************************************************************/
/* File        :                                                              */
/*              chothmsg.h                                                    */
/* Description :                                                              */
/*              error message defines and strings for use with wrterror       */
/* Copyright   :                                                              */
/*              Copyright (C) 1992 S.M.J.Searle. All rights reserved          */
/*              This file may not be copied or redistributed in any           */
/*              form or by any method except with written permission          */
/*              from the author.                                              */
/* Address     :                                                              */
/*              Biochemistry Department,                                      */
/*              University of Bath,                                           */
/*              4 West,                                                       */
/*              Claverton Down,                                               */
/*              Bath,                                                         */
/*              Avon,                                                         */
/*              BA2 7AY,                                                      */
/*              England.                                                      */
/* Telephone   :                                                              */
/*              0225 826826 Ext. 5411                                         */
/******************************************************************************/
/* IO errors */
#define FOPEN 		0
#define FGETSNULL	1
#define FGETSZERO	2
#define GETTOKZERO      3
#define MAXLENTOK       4

/* Pointer Errors */
#define NULLPOINTER	10
#define MALLERR		11
#define CALLERR		12
#define VECERR          13
#define NOENV           14

/* AA errors */
#define UNKAA           15

/* String Errors */
#define ZEROSTRING	20
#define SSCANFNUM	21
#define STRTOLONG	22
#define ZEROLEN         23
#define STRNCPYNULL     24

#define SINGMAT         29
/* Array errors */
#define ZEROARRAY       30

/* Fitting errors */
#define ZEROMAT         31
#define ROTSPECIAL      32
#define INVALNAT        33
#define MAXITER         34

/* Application errors */
#define USAGE           35
#define NOPDB           36
#define NUMSEQ          37
#define ORDERERR        38
#define INVALCUT        39
#define PDBINCONSIST    40
#define NOORDERRES      41
#define EXTRAAT         42
#define MISSAT          43
#define NOATOM          44
#define ZEROSEQ         45
#define MISMATCH        46
#define NODEL           47
#define EXTRARES        48
#define NOSEQ           49
#define NUMTOOLONG      50
#define INCLEN          51
#define INCZERO         52
#define NORES           53
#define NOCOFGAT        54
#define DIFFNUMDIFF     55
#define ZEROLENSEQ      56
#define NORANGE         57
#define PDBRESMISSING   58
#define RANGELIMITS     59
#define INCERROR        60
#define MATFILEERR      61
#define CHNNOTFOUND     62
#define SEQPOSRANGE     63
#define SEQWINGAP       64
#define DIFFLENSEQ      65
#define ZERORES         66
#define INSUFRES        67


/* General defines */
#define NUMERROR	68


static char *message[NUMERROR] = {
	"Error: Unable to open file ",
	"Error: fgets() returned a NULL pointer ",
	"Error: Attempt to get a zero length string using fgets() ",
	"Error: Gettok failed to find a token",
	"Error: Maximum length of token exceeded",
	"",
	"",
	"",
	"",
	"",
/* 10 */
	"Error: Null pointer ",
	"Error: Failed in malloc. Variable name ",
	"Error: Failed in calloc. Variable name ",
	"Error: Failed allocating vector called from",
	"Error: Unable to find environment variable",
	"Error: Unknown amino acid ",
	"",
	"",
	"",
	"",
/* 20 */
	"Error: Zero length string ",
	"Error: sscanf() returned an incorrect number of arguments ",
	"Error: String to long. ",
	"Error: zero length ",
	"Error: strncpy returned a NULL",
	"",
	"",
	"",
	"",
	"Error: Singular matrix",
/* 30 */
	"Error: Zero element array",
	"Error: Singular matrix",
	"Error: Special case in fitting routine. No fitting done",
	"Error: Invalid number of atoms",
	"Error: Maximum number of iterations exceeded",
/* 35 */
	"Usage ",
	"Error: PDB file not read correctly",
	"Warning : Number of sequences read greater than 2",
	"Error: Error reading order file",
	"Error: Invalid cutoff ",
	"Error: Inconsistancy ",     
	"Error: Residue not found in order structure",
	"Warning: extra atoms found in residue while ordering",
	"Error: Missing atoms in residue while ordering",
	"Error: Atom not found for residue",
	"Error: No sequences",
	"Error: Sequence mismatch",
	"Error: Failed to create DEL residue ",
	"Error: Extra residues after aligned region",
	"Error: No sequence in file ",
	"Error: String representing residue number is too long",
	"Error: String representing residue number is too long",
	"Error: String is zero long",
	"Error: No residues ",
	"Error: No atoms to calculate CofG for ",
	"Error: Different number of differences",
	"Error: Zero length sequence",
	"Error: No ranges",
	"Error: Failed to find PDB residue number",
	"Error: Range limits are wrong",
	"Error: Error with PDB numbers",
	"Error: Reading MDM matrix file",
	"Error: Chain not found for a residue number",
	"Error: Sequence position out of range",
	"Warning: Sequence window contained a gap",
	"Error: Sequences are different lengths",
	"Error: Zero residues",
	"Error: Insufficient residues in sequence"
	};
