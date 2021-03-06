/****************************************************************************** 
 *	Name: StrEdit.h                                                       *
 *  Function: Header file - contains definitions of constants for use in the  *
 *            structure editor windows, dialogs and functions.                *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: D.R. Marsh, Tessella Support Services plc                       *
 *      Date: 18/08/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * dd/mm/yy                                                                   *
 * 15/01/91 GCC     Removed list and invert chiral                            *
 ******************************************************************************/

#ifndef __STREDIT__
#define __STREDIT__
	
/* Structure Edit item identifiers */
#define SE_DELETE_ATOM			0
#define SE_DELETE_BOND			1
#define SE_DELETE_FRAGMENT		2

#define SE_MAKE_BOND			3
#define SE_ADD_HYDROGENS		4
#define SE_ADD_FRAGMENT			5

#define SE_CALC_BONDS			6
#define SE_RETYPE_ATOM			7
#define SE_CHANGE_GROUP			8
#define SE_DUPLICATE                    9
#define SE_EDIT_LABELS                  10
#define SE_EDIT_TYPES                   11

#define SE_RESET			12
#define SE_FINISH			13
#define SE_MAX_OPTIONS SE_FINISH+1

/* add hydrogens return values */
enum {ADD_HYDROGENS_CANCEL, ADD_HYDROGENS_ENTER};

/* Delete Atom dialog constants */
#define SE_DA_DELETE		   0	/* delete button ID */
#define SE_DA_CLEAR		   1	/* clear button ID */
#define SE_DA_FINISH		   2	/* finish button ID */
#define MAX_SE_DA_ATOMS		  20	/* maximum number of atoms that can be selected */

/* Delete Bond dialog constants */
#define SE_DB_DELETE		   0	/* delete button ID */
#define SE_DB_CLEAR		   1	/* clear button ID */
#define SE_DB_FINISH		   2	/* finish button ID */
#define MAX_SE_DB_ATOMS		   2	/* maximum number of atoms that can be selected */

/* Delete Fragment dialog constants */
#define SE_DF_DELETE		   0	/* delete button ID */
#define SE_DF_CLEAR		   1	/* clear button ID */
#define SE_DF_FINISH		   2	/* finish button ID */
#define MAX_SE_DF_ATOMS		  10	/* maximum number of fragments that can be selected */

/* Make Bond dialog constants */
#define SE_MB_MAKE		   0	/* make bond button ID */
#define SE_MB_CLEAR		   1	/* clear button ID */
#define SE_MB_FINISH		   2	/* finish button ID */
#define MAX_SE_MB_ATOMS		   2	/* maximum number of atoms that can be selected */

/* Make Bond Error codes and constants */
#define MBNoError		   0
#define MBAlreadyBonded		   1
#define MBDifferentMolecules	   2
#define MBFirstAtomFull		   3
#define MBSecondAtomFull	   4
#define MBTooFarApart		   5

/* Force Long Bond dialog and constants */
#define NO_FORCE_LONG_BOND	   0
#define FORCE_LONG_BOND		   1

/* Retype Atom dialog constants */
#define MAX_SE_RA_BUTTONS	  13	/* number of delete atom options */
#define MAX_SE_RA_ATOMS		  20	/* maximum number of atoms that can be selected */
#define iSERARetype		   0	/* clear selection button */
#define iSERAClear		   1	/* clear selection button */
#define iSERAFinish		   2	/* finish dialog button */
#define iSERAHydrogen		   0	/* hydrogen type button */
#define iSERACarbon		   1	/* carbon type button */
#define iSERANitrogen		   2	/* nitrogen type button */
#define iSERAOxygen		   3	/* oxygen type button */
#define iSERAPhosphorus		   4	/* phosphorus type button */
#define iSERASulphur		   5	/* sulphur type button */
#define iSERAFluorine		   6	/* fluorine type button */
#define iSERAChlorine		   7	/* chlorine type button */
#define iSERABromine		   8	/* bromine type button */
#define iSERAIodine		   9	/* iodine type button */
#define iSERAOther		  10	/* other atom type button */

/* Atom type dialog item identifiers */
#define iATAtomName		   5	/* atom type name item */
#define iATHighlight		   6	/* atom type dialog highlighted atom */

/* Add Hydrogens dialog constants */
#define SE_AH_H1		   0	/* add one hydrogen button ID */
#define SE_AH_H2		   1	/* add two hydrogens button ID */
#define SE_AH_H3		   2	/* add three hydrogens button ID */
#define SE_AH_CLEAR		   3	/* clear button ID */
#define SE_AH_FINISH		   4	/* finish button ID */
#define MAX_SE_AH_ATOMS		  20	/* maximum number of atoms that can be selected */

/* Add Fragment dialog constants */
#define SE_AF_APPEND		   0	/* append fragment button ID */
#define SE_AF_NEW		   1	/* new fragment button ID */
#define SE_AF_CLEAR		   2	/* clear button ID */
#define SE_AF_FINISH		   3	/* finish button ID */
#define SE_AF_DISPLAY_LEFT	   1	/* left corner of display area */
#define SE_AF_DISPLAY_TOP	  85	/* top corner of display area */
#define SE_AF_DISPLAY_RIGHT	 299	/* right corner of display area */
#define SE_AF_DISPLAY_BOTTOM	 379	/* bottom corner of display area */
#define MAX_SE_AF_ATOMS		   2	/* maximum number of atoms that can be selected */

/* Remove Molecule dialog item identifiers */
#define iSECBAllActive		    4	/* All active molecules radio button */
#define iSECBAllVisible		    5	/* All visible molecules radio button */
#define iSECBAllMolecules	    6	/* All molecules radio button */
#define iSECBOneMolecule	    7	/* Single molecule radio button */
#define iSECBOneNumber		    9	/* Single molecule number */
#define iSECBHighlight		   10	/* highlighted item */
 
/* Change Group dialog constants */
#define SE_CG_CHANGE		   0	/* Change Group button ID */
#define SE_CG_CLEAR		   1	/* clear button ID */
#define SE_CG_FINISH		   2	/* finish button ID */

#define iSECGMethyl  		   0	/* methyl radio button */
#define iSECGEthyl  		   1	/* ethyl radio button */
#define iSECGT_Butyl		   2	/* t_butyl radio button */
#define iSECGPhenyl 	 	   3	/* phenyl radio button */
#define iSECGCarboxyl		   4	/* carboxyl radio button */
#define iSECGHydroxyl 		   5	/* hydroxyl radio button */
#define iSECGAmino      	   6	/* amino radio button */
#define iSECGAmido      	   7	/* amido radio button */
#define MAX_SE_CG_ATOMS		   2	/* maximum number of atoms that can be selected */

/* Duplicate Molecule dialog Constants */
#define DUPLICATE_MOL              0    /* molecule number */
#define DUPLICATE_COP              1    /* Number of copies */
#define DUPLICATE_RUN              2    /* Duplicate */
#define DUPLICATE_CANCEL           3    /* Close dialog */

/* Edit Types dialog Constants */
#define SE_TYPE_ED                 0    /* edit type */
#define SE_TYPE_AUTO               1    /* auto type */
#define SE_TYPE_CLEAR              2    /* clear list*/
#define SE_TYPE_CANCEL             3    /* Close dialog */

/* Edit Labels dialog Constants */
#define SE_LABEL_ED                 0    /* edit label*/
#define SE_LABEL_AUTO               1    /* auto label*/
#define SE_LABEL_CLEAR              2    /* clear list*/
#define SE_LABEL_CANCEL             3    /* Close dialog */

/* Edit Label dialog Constants */
#define SE_EL_LABEL                 0    /* edit label*/
#define SE_EL_OK                    1    /* enter change */
#define SE_EL_CANCEL                2    /* cancel change */

/* Edit Types dialog Constants */
#define SE_ET_TYPE                  0    /* edit type*/
#define SE_ET_OK                    1    /* enter change */
#define SE_ET_CANCEL                2    /* cancel change */

#endif
