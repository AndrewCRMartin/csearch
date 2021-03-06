#ifndef __ABM_KEYWORDS_H__
#define __ABM_KEYWORDS_H__
/*****************************************************************************
 *      Name: abm_keywords.h                                                 *
 *  Function: To define the keyword ID numbers for the AbM interface         *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1993                                 *
 *---------------------------------------------------------------------------*
 *    Author: Robert Williams                                                *
 *      Date: 06/09/93                                                       *
 *---------------------------------------------------------------------------*
 *    Inputs:                                                                *
 *   Outputs:                                                                *
 *   Returns:                                                                *
 * Externals:                                                                *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 *****************************************************************************/

/* Special keywords */

#define KEY_QUIT      1
#define KEY_EXIT      2
 
/* Main menu keywords */

#define KEY_FILEIO    3
#define KEY_ALIGN     4
#define KEY_BUILDER   5
#define KEY_LOGFILE   6
#define KEY_RUNMODE   7
#define KEY_RUN       8
#define KEY_STATUS    9
#define KEY_RESTART  10
#define KEY_RETRY    11
#define KEY_DATABASE 12
#define KEY_SYSTEM   13

/* Input menu keywords */

#define KEY_READSEQ  14
#define KEY_PDBSEQ   15
#define KEY_REMODEL  16
#define KEY_TITLE    17
#define KEY_WRPIR    18

/* Database menu keywords */

#define KEY_DBNAME  19
#define KEY_PDBDIR   20
#define KEY_PDBPREF  21
#define KEY_PDBEXT   22
#define KEY_EXCLUDE  23
#define KEY_MAKEDB   24

/* System menu keywords */

#define KEY_SAVE     25
#define KEY_READ     26
#define KEY_RESET    27
#define KEY_SETDIR   28
#define KEY_SHELL    29
#define KEY_TIDY     30
#define KEY_HILIGHT  31

/* Builder menu keywords */

#define KEY_BLDRESET 32
#define KEY_MODEL    33

/* The framework parameters menu keywords */

#define KEY_SELECT   34
#define KEY_BEST     35

/* The loop parameters menu keywords */

#define KEY_REBUILD  36
#define KEY_CLOSURE  37
#define KEY_INTERACT 38
#define KEY_DBSEARCH 39
#define KEY_CONGEN   40
#define KEY_ENERGY   41
#define KEY_FINAL    42
#define KEY_SDRINT   43
#define KEY_SDRNRES  44

/* The DBSEARCH menu keywords */

#define KEY_INITRES  45
#define KEY_KEEP     46
#define KEY_MAXRES   47
#define KEY_CONSTRT  48

/* The CONGEN menu keywords */

#define KEY_GEMAX    49
#define KEY_AEMAX    50
#define KEY_PEMAX    51
#define KEY_PREMAX   52
#define KEY_BGRID    53
#define KEY_BMVDW    54
#define KEY_CMVDW    55
#define KEY_SCHAIN   56
#define KEY_SGRID    57
#define KEY_SMVDW    58

/* The energy menu keywords */

#define KEY_CROSSTRM 59
#define KEY_OOPLANE  60
#define KEY_1_4DIST  61
#define KEY_CUTOFF   62
#define KEY_DISTCUT  63
#define KEY_SMOOTH   64
#define KEY_BNDMODEL 65
#define KEY_NCYCLE   66
#define KEY_NLOWEST  67

#endif
