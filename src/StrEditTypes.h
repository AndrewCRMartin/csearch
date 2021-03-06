/****************************************************************************** 
 *   Name: StrEditTypes                                                    *
 *  Function: Structure Edit types header file - contains definition of the   *
 *            data types used by the Nemesis structure editing functions.     *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: D.R. Marsh, Tessella Support Services plc                       *
 *      Date: 18/08/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * dd/mm/yy                                                                   *
 ******************************************************************************/

#ifndef __STREDITTYPES__
#define __STREDITTYPES__

#ifndef __STREDIT__
#include "StrEdit.h"
#endif

/* The Structure editor reset record is used to */
/* control how changes to molecules are undone  */
typedef struct 
   {     
   short   SEcount;   /* number of invocations of structure editor */
   Logical   dirty;   /* flag that structure is 'dirty': i.e. has been edited */
   } SEResetRecord;
   
/* The Delete Atom record contains the current state of any selections made
   during the Delete Atom dialog */
typedef struct 
   {
   short   nselectedAtoms;      /* number of atoms selected */
   short   selectedAtoms[MAX_SE_DA_ATOMS];   /* selected atom to be deleted*/
   short   DAoption;   /* Delete Atom option selected */
   } SEDeleteAtom;

/* The Delete Bond record contains the current state of any selections made
   during the Delete Bond dialog */
typedef struct 
   {
   short      natoms;      /* number of bonds selected */
   short      newAtom;   /* first atom for a new bond */
   short      BondAtom[MAX_SE_DB_ATOMS];/* atoms defining the bond */
   short      DBoption;   /* Delete Bond option selected */
   } SEDeleteBond;

/* The Delete Fragment record contains the layout of the controls and the */
/* current state of any selections made during the Delete Fragment dialog */
typedef struct 
   {
   short      selectedAtom;   /* selected atom in fragment to be deleted */
   short      DFoption;   /* Delete Fragment option selected */
   } SEDeleteFrag;

/* The Make Bond record contains the layout of the controls and the */
/* current state of any selections made during the Make Bond dialog */
typedef struct 
   {
   short      nselectedAtoms;   /* number of atoms selected */
   short      newAtom;   /* first atom for a new bond */
   short      BondAtom[2];   /* atoms defining the bond */
   short      MBoption;   /* Make Bond option selected */
   } SEMakeBond;

/* The Retype Atom record contains the layout of the controls and the */
/* current state of any selections made during the Retype Atom dialog */
typedef struct 
   {
   short      nselectedAtoms;   /* number of atoms selected */
   short      selectedAtoms[MAX_SE_RA_ATOMS]; /* selected atoms to be retyped */
   short      RAoption;         /* Retype Atom option selected */
   short      newAtomType;      /* the new atom type to be used */
   } SERetypeAtom;

/* The Add Hydrogens record contains the layout of the controls and the */
/* current state of any selections made during the Add Hydrogens dialog */
typedef struct 
   {
   short      nselectedAtoms;   /* number of atoms selected */
   short      selectedAtoms[MAX_SE_AH_ATOMS]; /* selected atoms to add H to */
   short      AHoption;         /* Add Hydrogen option selected */
   } SEAddHydrogens;

/* current state of any selections made during the Add Fragment dialog */
typedef struct 
   {
   short      JoinAtom[2];   /* atoms defining the join */
   short      AFoption;      /* Add Fragment option selected */
   Logical    canAppend;     /* can append to existing molecule */
   Logical    canAddNew;     /* can create new molecule */
   WDMap      displayMap;    /* world-device mapping for fragment */
   } SEAddFragment;

/* current state of any selections made during the Change Group dialog */
typedef struct 
   {
   short      JoinAtom[2];   /* atoms defining the join */
   short      CGoption;      /* Change Group option selected */
   Logical    canChange;     /* can change group */
   short      newGroupType;  /* the new group type selected */
   } SEChangeGroup;

/* The Edit Labels record contains the selected atom made during the 
       Edit Labels dialog */
typedef struct 
   {
   short   SelectedAtom;    /* selected atoms re-label  */
   } SELabelAtom;
/* The Edit Types  record contains the selected atom made during the 
       Edit Types  dialog */
typedef struct 
   {
   short   SelectedAtom;    /* selected atoms re-label  */
   } SETypeAtom;
#endif
