#ifndef __OMLIBCP_H__
#define __OMLIBCP_H__

/*****************************************************************************
 *      Name: OMLIBcp.h                                                      *
 *  Function: Definitions for the Command Processor C binding                *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1993                                 *
 *---------------------------------------------------------------------------*
 *    Author: Dr. D. Walker, Oxford Molecular Ltd                            *
 *      Date: 07/01/93                                                       *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 *****************************************************************************/

#include <stdio.h>
#include <string.h>

#define CP_BUFSIZE 512     /* Input buffer length */

/* Add underscores to the names of FORTRAN functions called from C, if
   appropriate */

#ifdef __FORT_UNDERSCORE__

#define cpclvl    cpclvl_
#define cpgetr    cpgetr_
#define cpproc    cpproc_
#define cptidy    cptidy_
#define fwikwd    fwikwd_
#define fwakwd    fwakwd_
#define fwgtok    fwgtok_
#define fwgtva    fwgtva_
#define fwgvt     fwgvt_
#define fwgnwrd   fwgnwrd_
#define fwstrcrd  fwstrcrd_

#endif

/* OMLIB_CP FORTRAN function prototypes */

void cpclvl(void);
void cpgetr(void);
void cpproc(void);
void cptidy(void);


/* OMLIB Command Processor C-binding function prototypes */

void  fwakwd(char *word, int *lenWord);
void  fwgnwrd(short *numWord);
void  fwgtok(short *wordNum,short *token);
void  fwgvt(short *wordNum,short *valueType);
void  fwgtva(short *wordNum,char *valueStr);
void  fwikwd(void);
void  fwstrcrd(char *userRec, int *lenRecord);

void  CPAddKwrd(char *word);
void  CPClearValue (void);
short CPGetNumWords(void);
void  CPGetRecord(void);
short CPGetToken(short wordNum);
short CPGetValueType(short wordNum);
void  CPGetValue(short wordNum,char *valueStr);
void  CPInitNumKwrd(void);
void  CPProcessRecord(void);
void  CPSetRecord(char *userRec);
void  CPTidyRecord(void);

#endif
