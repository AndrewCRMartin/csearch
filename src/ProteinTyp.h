/****************************************************************************** 
 *      Name: ProteinTyp                                                      *
 *  Function: Protein types header file - contains definition of the data     *
 *            types used by the PIMMS Protein functions.                      *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: D.R. Marsh, Tessella Support Services plc                       *
 *      Date: 30/11/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 ******************************************************************************/

#ifndef __PROTEINTYP__
#define __PROTEINTYP__

#ifndef __PROTEIN__
#include "Protein.h"
#endif

/* The Sequence Build Settings record contains the current state of */
/* any settings set by the user from the Sequence Build menu  */
typedef struct 
	{
	short	number_to_add;		/* number of a residue to add to seq */
	short	chirality;		/* residue chirality */
	short	autoBuildMode;		/* auto protein build mode */
	char	Res_Window_String[1500]; /* string of 3 letter codes */
	short	numResidues;		/* number of residues in string */
	short	lastBuilt;		/* last residue in the built portion */
	short	molNumber;		/* number of molecule in applic */
	short	extResNumber;		/* external residue code */
	char	extResInsert;		/* external insertion code */
	short	lastextResNumber;	/* last ext res code */
	char	lastextResInsert;	/* last ext insertion code */
	} SeqBuildSettings;

/* current state of any selections made during Add Residue */
typedef struct 
	{
	short		JoinAtom[2];	/* atoms defining the join */
	Logical		canChange;	/* can change group */
	short		CAlphaSeq;	/* the CA in the sequence */
	short		CSeq;		/* the C in the sequence */
	short		NFrag;		/* the N in the fragment */
	short		CAlphaFrag;	/* the CA in the fragment */
	} PBAddResidue;

/* records state of selected atoms during delete residue */
typedef struct
	{
	short	nselectedAtoms;		/* number of selected atoms */
	short	selectedAtoms[MAX_PB_DR_ATOMS];
	short	nselectedResidues;	/* number of selected residues */
	short	selectedResidues[MAX_PB_DR_RESIDUES];
	short	DRoption;		/* Delete residue option selected */
	} PBDeleteResidue;

/* records state of selected atoms during insert residue */
typedef struct
	{
	short	nselectedAtoms;	/* number of selected atoms */
	short	selectedAtoms[MAX_PB_IR_ATOMS];
	short	nselectedResidues;	/* number of selected residues */
	short	selectedResidues[MAX_PB_IR_RESIDUES];
	short	IRoption;	/* Insert residue option selected */
	short	JoinAtom[2];	/* atoms defining the join */
	Logical	canChange;	/* can change atom */
	short	CAlphaFrag;	/* the CA in the fragment */
	short	CFrag;		/* the C in the fragment */
	short	NSeq;		/* the N in the sequence */
	short	CAlphaSeq;	/* the CA in the sequence */
	} PBInsertResidue;

/* records state of selected atoms during mutate residue */
typedef struct
	{
	short	nselectedAtoms;	/* number of selected atoms */
	short	selectedAtoms[MAX_PB_MR_ATOMS];
	short	nselectedResidues;	/* number of selected residues */
	short	selectedResidues[MAX_PB_MR_RESIDUES];
	short	MRoption;	/* Mutate residue option selected */
	} PBMutateResidue;

/* records state of selected atoms residues during conformation updates */
typedef struct
	{
	short	nselectedAtoms;	/* number of selected atoms */
	short	selectedAtoms[MAX_PC_UC_ATOMS];
	short	nselectedResidues;	/* number of selected residues */
	short	selectedResidues[MAX_PC_UC_RESIDUES];
	short	UCoption;	/* Update conformation option selected */
	short	conformType;	/* Type of conformation selected */
	float	phiAngle;	/* phi torsion angle */
	float	psiAngle;	/* psi torsion angle */
	} PCUpdateConformation;

#endif
