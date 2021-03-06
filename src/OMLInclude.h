/******************************************************************************
 *      Name: OMLInclude.h                                                    *
 *  Function: Declarations of all standard include files.                     *
 * Copyright: (C) Oxford Molecular Limited                                    *
 *----------------------------------------------------------------------------*
 *    Author: J.P.Holland, Oxford Molecular Ltd.                              *
 *      Date: 22-Jul-1991                                                     *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * dd/mm/yy                                                                   *
 * 30/07/91 JPH     Add OMLConstants.h                                        *
 * 01/12/92 DW      Add "__APOLLO__" to the HP cases for new FPP (CR 975)     *
 * 08/03/93 KJW     Include <varargs.h> for non-ANSI C (CR 1492)              *
 ******************************************************************************/

#ifndef __OMLINCLUDE__
#define __OMLINCLUDE__

/* Definitions required BEFORE standard headers used. */
#if defined (__HEWLETTPACKARD__) || defined (__APOLLO__)
#define _HPUX_SOURCE
#include <sys/stdsyms.h>
#else

#if defined (__IBM__)
#define _XOPEN_SOURCE
#define _ALL_SOURCE
#include <standards.h>
#else

#if defined (__SILICONGRAPHICS__)
#if ! defined (__IRIX_3_2__) && ! defined (__EXTENSIONS__)
#define __EXTENSIONS__
#endif /* __IRIX_3_2__ */
#else

#if defined (__SUN__)
#include <sys/stdtypes.h>
#else

#if vax

#else

#if defined (__linux__)

#else

__ NEXT __MACHINE __ SUPPORTED __

#endif /* Linux */
#endif /* vax */
#endif /* __SUN__ */
#endif /* __SILICONGRAPHICS__ */
#endif /* __IBM__ */
#endif /* __HEWLETTPACKARD__ */

/* Include headers included on all machines */
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <ctype.h>

/* Include <stdarg.h> under ANSI C, <varargs.h> under non-ANSI C */
#if (defined(__IRIX_3_2__) || defined(__IRIX_3_3__))
#include <varargs.h>
#else
#include <stdarg.h>
#endif

/* And machine dependent headers */
#ifndef __IRIX_3_2__
/* Standard ANSI only added to SG after IRIX 3.3 */
#include <stdlib.h>
typedef  void * VoidPtr ;
#else
typedef  char * VoidPtr ;
/* fpos_t etc not defined for IRIX 3.2 */
typedef unsigned       fpos_t ;
typedef int            pid_t  ;
typedef int            gid_t  ;
typedef unsigned short mode_t ;
#endif

#if vax							/* IF  VAX */
#define __STDC__
#include <types.h>
#else							/* NOT VAX */

#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/param.h>
#include <malloc.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#if (defined (__HEWLETTPACKARD__) || defined (__APOLLO__)) && defined (SIGCHLD)
#undef SIGCHLD	/* SIGCHLD defined n X11/Xos.h and signal.h on HP */
#endif		/* - undefine before including signal.h */
#include <signal.h>

#if defined (__HEWLETTPACKARD__) || defined (__APOLLO__)/* IF HP */
#else							/* NOT HP */

#if defined (__SILICONGRAPHICS__)			/* IF  SG */
#define __STDC__
#else							/* NOT SG */

#if defined (__IBM__)					/* IF  IBM */
#else							/* NOT IBM */

#if defined (__SUN__)					/* IF  SUN */
#else							/* NOT SUN */

#if defined (__linux__)
#else

/* #ifdef __NEXT_MACHINE_SUPPORTED__ */

/* No valid machine defined - cause an error */
_CAUSE_AN_ERROR_

/* #endif */						/* END NEXT_MACHINE */
#endif                                                  /* END Linux */
#endif							/* END SUN */
#endif							/* END IBM */
#endif							/* END SG */
#endif							/* END HP */
#endif							/* END VAX */

#include "OMLConstants.h"
#include "TrueFalse.h"
#include "Types.h"

#endif
