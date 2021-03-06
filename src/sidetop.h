#ifndef __SIDETOP_H__
#define __SIDETOP_H__

/***********************************************************************
 *      NAME: SIDETOP                                                  *
 *  FUNCTION: To declare variables relating to sidechain topology      *
 * COPYRIGHT: (C) OXFORD MOLECULAR LIMITED, 1992                       *
 *---------------------------------------------------------------------*
 *    AUTHOR: Robert Williams                                          *
 *      DATE: 05/10/9                                                 *
 *---------------------------------------------------------------------*
 *    INPUTS:                                                          *
 *   OUTPUTS:                                                          *
 *    LOCALS:                                                          *
 *   GLOBALS:                                                          *
 *     CALLS:                                                          *
 *---------------------------------------------------------------------*
 * MODIFICATION RECORD                                                 *
 * DD/MM/YY   INITS   COMMENTS                                         *
 ***********************************************************************
 
    Variable     Array bounds            Description
    --------     ------------            -----------

    ST_ADD            -       Flag for additions to free torsion
    ST_FIXED          -       Flag indicating fixed torsion
    ST_FREE           -       Torsion flag indicating independent atom
    NSCATM            -       The number of sidechain atoms
    NSCLMP            -       The number of sidechain clumps
    NSCRES            -       The number of sidechain residues

    SC_ATOM_BLD    MXSCAT     IUPAC name of atom to be constructed
    SC_ANTE1_BLD   MXSCAT     Neighbour IUPAC named atom for building
    SC_ANTE2_BLD   MXSCAT     Next adjacent IUPAC atom for building
    SC_ANTE3_BLD   MXSCAT     Third adjacent IUPAC atom for building
    SC_BOND_BLD    MXSCAT     Bond for building an atom
    SC_ANGLE_BLD   MXSCAT     Construction angle for each atom
    SC_CODE_BLD    MXSCAT     Flag describing the use of the torsion angle
    SC_TORS_BLD    MXSCAT     Torsion angle for building (FREE=> dont use)
    SC_ATOM_PART   MXCLMP     Partition of atoms into clumps
    SC_CLUMP_PART  MXSRES     Partition of clumps into residues 
    SC_FREE_ATOM   MXCLMP     The free atom in the clump
    SC_OFFSET      MXSCAT     Offset angle for torsion ADD procedure
    SC_RESNAME     MXSRES     The residue names
    SC_SPECIAL     MXSRES     TRUE if consistency checks are ignored
    SC_SYMMETRY    MXCLMP     The Rotational symmetry of each clump

  Where:
 
    MXSRES                 Maximum number of sidechain residues
    MXCLMP                 Maximum number of sidechain clumps
    MXSCAT                 Maximum number of sidechain atoms    */

#define mxsres 30
#define mxclmp 75
#define mxscat 200
#define st_add 1
#define st_fixed 2
#define st_free 3

extern struct {
      float sc_bond_bld[mxscat],
            sc_angle_bld[mxscat],
            sc_tors_bld[mxscat],
            sc_offset[mxscat];

      int   nscatm,
            nsclmp,
            nscres, 
            sc_code_bld[mxscat],
            sc_atom_part[mxclmp+1],
            sc_clump_part[mxsres+1],
            sc_special[mxsres],
            sc_symmetry[mxclmp];

      char  sc_ante1_bld[mxscat][4],
            sc_ante2_bld[mxscat][4],
            sc_ante3_bld[mxscat][4],
            sc_resname[mxsres][4],
            sc_free_atom[mxclmp][4],
            sc_atom_bld[mxscat][4];
      } sidetop;

#endif
