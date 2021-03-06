/******************************************************************************
 *                                                                            *
 *      Name: Cosmic.h                                                        *
 *  Function: Cosmic header file - contains definition of constants used by   *
 *            the Nemesis Energy setup and calculation dialogs and windows.   *
 *            Nemesis uses the COSMIC force field to perform all its energy   *
 *            calculations.                                                   *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: K.J. Woods, Tessella Support Services Ltd.                      *
 *      Date: 12/04/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * 22/10/90  KJW    New constants to flag unparametrized atom situations      *
 * 26/05/92  KJW    Updated for C version of COSMIC                           *
 * 03/07/92  GAC    Reduced atom limits for Nemesis Sampler                   *
 * 09/08/92  KJW    Increased atom limits for special large version           *
 * 01/05/93  KJW    Unified parameters for Mac, Windows & Unix                *
 ******************************************************************************/

#if !defined(__COSMIC__)
#define __COSMIC__

#if !defined(__NEM_TYPES__)
#include "NemTypes.h"
#endif

/* Energy calculation target classes */
#define ALL_ACTIVE             1
#define ALL_VISIBLE            2
#define ALL_MOLECULES          3
#define ONE_MOLECULE           4

/* maximum number of energy terms in the COSMIC force field */
#define MAX_ENERGY_TERMS             5

/* maximum number iterations performed by the COSMIC force field optimization */
#define MAX_ITER                   200

/* action flags when unparameterized atoms are found */
#define COSMIC_UP_DEFAULTS           1
#define COSMIC_UP_ABORT              2

/* error return codes */
#define COSMIC_NO_ERROR             0   /* no error */
#define COSMIC_IO_ERROR             1   /* I/O error */
#define COSMIC_UP_ERROR             2   /* unparameterized atom error */
#define COSMIC_COMPUTE_ERROR        3   /* other error */
#define ATOM_OVERFLOW_ERROR         5   /* max number of atoms reached */
#define BOND_OVERFLOW_ERROR         6   /* max number of bonds reached */
#define LIMIT_OVERFLOW_ERROR        7   /* internal limit exceeded */

/* define the COSMIC parameter file names */
#if defined(__UNIX__)
   #define   ANGLE_FILE        "/DAT/angff.fff"
   #define   BOND_FILE         "/DAT/bondff.fff"
   #define   HUCK_FILE         "/DAT/huck2params.dat"
   #define   MOD_BOND_FILE     "/DAT/huck2bond.fff"
   #define   MOD_TORS_FILE     "/DAT/huck2tor.fff"
   #define   TORSION_FILE      "/DAT/torff.fff"
   #define   VDW_FILE          "/DAT/vdwff.fff"
#else
   #define   ANGLE_FILE        "angff.fff"
   #define   BOND_FILE         "bondff.fff"
   #define   HUCK_FILE         "huck2params.dat"
   #define   MOD_BOND_FILE     "huck2bond.fff"
   #define   MOD_TORS_FILE     "huck2tor.fff"
   #define   TORSION_FILE      "torff.fff"
   #define   VDW_FILE          "vdwff.fff"
#endif

/* define COSMIC array dimensions */
#if defined (DEMO)
   #define MAXATT              50   /* maximum number of atoms */
   #define MAXBON              10   /* maximum number of rotateable bonds */
   #define MAXANG             100   /* maximum number of angles */
   #define MAXTOR             200   /* maximum number of torsions */
   #define MAXVDW            1225   /* maximum number of vdw interactions */
   #define MAXATP              25   /* maximum number of pi atoms */
   #define MAXOBP              25   /* maximum number of pi bonds */
   #define MAXOB              100   /* maximum number of bonds */
   #define MXASYS              25   /* maximum number of atoms in a single pi system */
   #define MXBSYS              25   /* maximum number of bonds in a single pi system */
   #define MAXETS               5   /* maximum number of energy term switches */
#elif defined (LARGE_VERSION)
   #define MAXATT             250   /* maximum number of atoms */
   #define MAXBON             200   /* maximum number of rotateable bonds */
   #define MAXANG             500   /* maximum number of angles */
   #define MAXTOR            1000   /* maximum number of torsions */
   #define MAXVDW           31150   /* maximum number of vdw interactions */
   #define MAXATP             200   /* maximum number of pi atoms */
   #define MAXOBP             200   /* maximum number of pi bonds */
   #define MAXOB              400   /* maximum number of bonds */
   #define MXASYS             100   /* maximum number of atoms in a single pi system */
   #define MXBSYS             100   /* maximum number of bonds in a single pi system */
   #define MAXETS               5   /* maximum number of energy term switches */
#elif defined (__UNIX__)
   #define MAXATT             250   /* maximum number of atoms */
   #define MAXBON             200   /* maximum number of rotateable bonds */
   #define MAXANG             500   /* maximum number of angles */
   #define MAXTOR            1000   /* maximum number of torsions */
   #define MAXVDW           31150   /* maximum number of vdw interactions */
   #define MAXATP             200   /* maximum number of pi atoms */
   #define MAXOBP             200   /* maximum number of pi bonds */
   #define MAXOB              400   /* maximum number of bonds */
   #define MXASYS             100   /* maximum number of atoms in a single pi system */
   #define MXBSYS             100   /* maximum number of bonds in a single pi system */
   #define MAXETS               5   /* maximum number of energy term switches */
#else
   #define MAXATT             125   /* maximum number of atoms */
   #define MAXBON              50   /* maximum number of rotateable bonds */
   #define MAXANG             200   /* maximum number of angles */
   #define MAXTOR             400   /* maximum number of torsions */
   #define MAXVDW            7850   /* maximum number of vdw interactions */
   #define MAXATP              50   /* maximum number of pi atoms */
   #define MAXOBP              50   /* maximum number of pi bonds */
   #define MAXOB              200   /* maximum number of bonds */
   #define MXASYS              50   /* maximum number of atoms in a single pi system */
   #define MXBSYS              50   /* maximum number of bonds in a single pi system */
   #define MAXETS               5   /* maximum number of energy term switches */
#endif

/* define COSMIC parameter array dimensions */
#define MAX_ANGLE_TYPES    300
#define MAX_BOND_TYPES     150
#define MAX_HUCK_COULOMB    25
#define MAX_HUCK_RESONANCE  75
#define MAX_MOD_BOND_TYPES  50
#define MAX_MOD_TORS        50
#define MAX_TORS_TYPES     150
#define MAX_VDW_TYPES       50
#define MAX_VDW_PARM        10

/* define max range for vdW interactions */
#define MAX_VDW_RANGE       15.0      /* Angstroms */

/* define COSMIC iteration tolerances */
#define RHO                 1.0e-6
#define DFLT_ENERGY_TOL     1.0e-7
#define DFLT_GRADIENT_TOL   1.0e-10

/* define physical constants */
#define MORSE_B          5.643    /* b parameter in Morse potential */
#define KCAL           332.17     /* convert Joules -> kcal/mol */

/* define axis mnemonics */
#define AXIS_X           3        /* the x-axis */
#define AXIS_Y           2        /* the y-axis */
#define AXIS_Z           1        /* the z-axis */

#if defined(__MACINTOSH__)
   #if !defined(__COSMIC_RESOURCE__)
   #include "CosmicResource.h"
   #endif
#endif

#endif
