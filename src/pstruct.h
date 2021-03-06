/***********************************************************************
 *      NAME: PSTRUCT                                                  *
 *  FUNCTION: To declare the variables used for storing information    *
 *            related to the whole protein structure. This includes    *
 *            atomic data and topology data                            *
 * COPYRIGHT: (C) OXFORD MOLECULAR LIMITED, 1992                       *
 *---------------------------------------------------------------------*
 *    AUTHOR: Robert Williams                                          *
 *      DATE: 06/10/92                                                 *
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
  Variable  Array Bounds                Description
  --------  ------------                -----------
   ATMNME     MAXAT      List of IUPAC atom names 
   ATCODE     MAXAT      List of atom type codes
   ATMASS     MAXAT      List of atomic masses
   ATCHRG     MAXAT      List of atomic charges
   QMOVE      MAXAT      Indicates if atoms can move (0=Y, 1=N)
   ATBND1     MAXBND     List of principal atoms in bonds
   ATBND2     MAXBND     List of second atoms in bonds
   ATANG1     MAXANG     List of first atoms in bond angles
   ATANG2     MAXANG     List of second atoms in bond angles
   ATANG3     MAXANG     List of third atoms in bond angles
   ATTOR1     MAXTOR     List of first atoms in proper torsions
   ATTOR2     MAXTOR     List of second atoms in proper torsions
   ATTOR3     MAXTOR     List of third atoms in proper torsions
   ATTOR4     MAXTOR     List of fourth atoms in proper torsions
   ATIMP1     MAXIMP     List of first atoms in improper torsions 
   ATIMP2     MAXIMP     List of second atoms in improper torsions
   ATIMP3     MAXIMP     List of third atoms in improper torsions
   ATIMP4     MAXIMP     List of fourth atoms in improper torsions
   NBEXCL     MAXNB      List of non-bond exclusions, indexed by LSTEXC 
   LSTEXC     MAXAT      Gives the last non-bond exclusion in NBEXCL
                         for an atom
   HBACPT     MXDORA     List of hydrogen bond acceptors
   HBAAN1     MXDORA     First antecedent atom to HBACPT
   HBAAN2     MXDORA     Second antecedent atom to HBACPT
   HBDONR     MXDORA     List of heavy atom donors
   HBDHYD     MXDORA     Hydrogen bond donor atom attached hydrogen
   HBDAN1     MXDORA     First antecedant atom to HBDONR
   HBDAN2     MXDORA     Second antecedant atom to HBDONR
   LSTATM   (MAXRES+1)   LSTATM(I+1) gives the last atom in residue I
   RESNDX     MAXRES     Index of where residues are in the topology arrays
   RESNME     MAXRES     List of residue names
   RESID      MAXRES     List of residue indentifications
   SEGID      MAXSEG     List of segment indentifications
   SEGNDX  (MAXSEQ+1,10) This array gives information regarding the
                         separation of the structure into segments.
                         The first array argument indicates:
                               1 Total number of residues
                               2 Total number of atoms
                               3 Total number of bonds
                               4 Total number of bond angles
                               5 Total number of proper torsions
                               6 Total number of improper torsions
                               7 Total non-bond exclusions
                               8 Total H-bond donor atoms
                               9 Total H-bond acceptor atoms
                              10 The segment type flag 
                         The second argument indicates the last value
                         for the quantity defined by the first argument
                         ie SEGNDX(3,I+1) gives the last bond number 
                         for segment I.
*/

#ifndef __PSTRUCT_H__
#define __PSTRUCT_H__

extern struct {
      char      segid[maxseg][4],  resid[maxres][4],
                resnme[maxres][4], atmnme[maxat][4];

      float     atchrg[maxat], atmass[maxat];

      int       lstexc[maxat], segndx[maxseg+1][10];

      short int atbnd1[maxbnd], atbnd2[maxbnd], atang1[maxang], 
                atang2[maxang], atang3[maxang], attor1[maxtor],
                attor2[maxtor], attor3[maxtor], attor4[maxtor], 
                atimp1[maximp], atimp2[maximp], atimp3[maximp],
                atimp4[maximp], hbacpt[mxdora], hbaan1[mxdora],
                hbaan2[mxdora], hbdonr[mxdora], hbdhyd[mxdora], 
                hbdan1[mxdora], hbdan2[mxdora], lstatm[maxres+1],
                resndx[maxres], nbexcl[maxnb], qmove[maxat],
                atcode[maxat];


      } pstruct;

#endif
