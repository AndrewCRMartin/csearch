/*************************************************************************

   Program:    
   File:       SysDefs.h
   
   Version:    V1.0R
   Date:       01.03.94
   Function:   System-type variable type definitions
   
   Copyright:  (c) SciTech Software 1993
   Author:     Dr. Andrew C. R. Martin
   Address:    SciTech Software
               23, Stag Leys,
               Ashtead,
               Surrey,
               KT21 2TD.
   Phone:      +44 (0372) 275775
   EMail:      INTERNET: amartin@scitec.adsp.sub.org
                         martin@bsm.bioc.ucl.ac.uk
               UUCP:     ...{uunet|rutgers}!cbmehq!cbmuk!scitec!amartin
               JANET:    martin@uk.ac.ucl.bioc.bsm
               
**************************************************************************

   This program is not in the public domain, but it may be copied
   according to the conditions laid out in the accompanying file
   COPYING.DOC

   The code may be modified as required, but any modifications must be
   documented so that the person responsible can be identified. If someone
   else breaks this code, I don't want to be blamed for code that does not
   work! 

   The code may not be sold commercially or included as part of a 
   commercial product except as described in the file COPYING.DOC.

**************************************************************************

   Description:
   ============

**************************************************************************

   Usage:
   ======

**************************************************************************

   Revision History:
   =================

*************************************************************************/
#ifndef _SYSDEFS_H
#define _SYSDEFS_H

#ifndef EXEC_TYPES_H    /* Commodore Amiga; defines in <exec/types.h>   */
typedef void            *APTR;

#ifndef SYS_TYPES_H     /* Unix: <sys/types.h>, MS-DOS: <sys\types.h>   */
#ifndef _TYPES_         /* Ditto                                        */
typedef short           BOOL;
typedef long            LONG;
typedef unsigned long   ULONG;
typedef short           SHORT;
typedef unsigned short  USHORT;
#endif
#endif
#endif

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifdef _ESV_
typedef long            time_t;   /* Required on E&S System V           */
typedef long            clock_t;  /* Ditto                              */
#define CLOCKS_PER_SEC  1000000   /* Ditto                              */
#endif

#endif
