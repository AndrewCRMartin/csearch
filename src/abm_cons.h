#ifndef __ABM_CONS_H__
#define __ABM_CONS_H__
/*****************************************************************************
 *      Name: abm_cons.h                                                     *
 *  Function: To define any parameters to be used in the AbM antibody modell-*
 *            ing program database constraints calculation routines.         *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1993                                 *
 *---------------------------------------------------------------------------*
 *    Author: Robert Williams                                                *
 *      Date: 29/09/93                                                       *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 *****************************************************************************/

#define LEN_CLASSES           3   /* The number of loop length classes */
#define MIN_POPULATION        6   /* Minimum class population level */
#define MAX_CA_DIS     (float)3.9 /* Greatest inter residue distance */
#define SD_MULT        (float)3.5 /* Standard dev. multiplicative factor */

#define CLASS_1_LOW     1        /* Class 1 lower limit */
#define CLASS_1_UP      7        /* Class 1 upper limit */
#define CLASS_2_LOW     8        /* Class 2 lower limit */
#define CLASS_2_UP     12        /* Class 2 upper limit */
#define CLASS_3_LOW    13        /* Class 3 lower limit */
#define CLASS_3_UP     20        /* Class 3 upper limit */

/* Type definitions */

typedef struct ConsData ConsData;  /* Structure for constraints */

/* Structure definitions */

struct ConsData
{
   /* General loop classes */

   int   TheClass;               /* The length class of this loop */
   int   ClsLow[LEN_CLASSES];    /* Initial length class upper limits */
   int   ClsUp[LEN_CLASSES];     /* Initial length class lower limits */

   /* Actual class information used */

   int   Lower;                 /* Lower loop length limit for length class */
   int   Upper;                 /* Upper loop length limit for length class */
   int   Shortest;              /* The shortest loop length in length class */
   int   NinClass;              /* Number of UDB loops in same length class */
   float DPfor[MAX_LOOP_LEN];   /* Av. Dis. from Nter going forward to Cter */
   float DPforSq[MAX_LOOP_LEN]; /* Av. squared Dis. from Nter forward to Cter */
   float DPforSD[MAX_LOOP_LEN]; /* Standard deviation of DPfor values */
   float DPback[MAX_LOOP_LEN];  /* Av. Dis. from Nter going back from Cter */
   float DPbackSq[MAX_LOOP_LEN];/* Av. squared Dis. from Nter back from Cter */
   float DPbackSD[MAX_LOOP_LEN];/* Standard deviation of DPback values */
   float DMfor[MAX_LOOP_LEN];   /* Av. Dis. from Cter going forward to Nter */
   float DMforSq[MAX_LOOP_LEN]; /* Av. squared Dis. from Cter forward to Nter */
   float DMforSD[MAX_LOOP_LEN]; /* Standard deviation of DMfor values */
   float DMback[MAX_LOOP_LEN];  /* Av. Dis. from Cter going back from Nter */
   float DMbackSq[MAX_LOOP_LEN];/* Av. squared Dis. from Cter back from Nter */
   float DMbackSD[MAX_LOOP_LEN];/* Standard deviation of DMback values */
};

#endif
