#ifndef _OMLIBMP_H__
#define _OMLIBMP_H__

/*****************************************************************************
 *      Name: OMLIBmp.h                                                      *
 *  Function: Header definitions for OMLIB MPS C binding                     *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1993                                 *
 *---------------------------------------------------------------------------*
 *    Author: Dr. D. Walker, Oxford Molecular Ltd                            *
 *      Date: 07/01/93                                                       *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 * 01/11/93   RKW        Added new functions: fwlgnm, fwini2, and their      *
 *                       C binding equivalents.                              *
 *****************************************************************************/

#include <stdio.h>
#include <string.h>

/* Append underscores to the names of FORTRAN routines called from C, if
   appropriate */
#ifdef __FORT_UNDERSCORE__

#define mpexit 	mpexit_
#define mplevl 	mplevl_
#define mpgtlv 	mpgtlv_
#define mpwait	mpwait_

#define fwform 	fwform_
#define fwinit 	fwinit_
#define fwini2 	fwini2_
#define fwtosh 	fwtosh_
#define fwmout 	fwmout_
#define fwadmsg	fwadmsg_
#define fwlgnm  fwlgnm_

#endif

/* OMLIB MP function prototypes */

void mpexit(void);
void mplevl(int *msgLevel);
int  mpgtlv(void);
void mpwait(double *delsec);


/* OMLIB MP C-binding Function prototypes */

void MPAddMsg (char skeleton[],short number);
void MPDelay (double delsec);
int  MPFormat (int format);
int  MPGetLevel (void);
void MPInitialise (char mpsFile[]);
void MPInitial2 (char *mpsFile, char *LogFile);
void MPLevel(int msgLevel);
void MPMsgOut (char mname[], char mid[], char info1[], char info2[],
               char info3[], char info4[], char cretun[]);
void MPShutdown (void);
void MPToScreen(char mpmsg[]);
void MPGetLogName(int MaxLength, char *LogFile);

void fwform(int *format, int *returnCode);
void fwinit(char *fileName, int *lenName);
void fwini2(char *fileName, int *lenName, char *LogFile, int *LenLog);
void fwtosh(char *message, int *lenMessage);
void fwmout(char *,char *,char *,char *,char *,char *,char *,
            int *,int *,int *,int *,int *,int *);
void fwadmsg(char *skeleton, int *lenSkel, short *number);
void fwlgnm(int *MaxLength, char *LogFile);

#endif
