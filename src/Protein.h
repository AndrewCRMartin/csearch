/****************************************************************************** 
 *      Name: Protein.h                                                       *
 *  Function: Header file - contains definitions of constants for use in the  *
 *            Protein Build application.                                      *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: D.R. Marsh, Tessella Support Services plc                       *
 *      Date: 30/11/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * 17/04/91 GCC     Modified basic protein window size as it can now be       *
 *                  resized.                                                  *
 ******************************************************************************/

#ifndef __PROTEIN__
#define __PROTEIN__
	
/* Protein menu button identifiers */
#define PROTEIN_BUILD			0
#define PROTEIN_CONFORM			1
#define PROTEIN_READ			2
#define PROTEIN_WRITE			3
#define PROTEIN_FINISH			4
#define PROTEIN_MAX_OPTIONS PROTEIN_FINISH+1

#define PROTEIN_RESIDUES		20

/* Protein application identifiers */
#define PROT_BUILD_DELETE	0
#define PROT_BUILD_INSERT	1
#define PROT_BUILD_MUTATE	2
#define PROT_BUILD_BUILD	3
#define PROT_BUILD_ADD_H	4
#define PROT_BUILD_SET_CHARGES	5
#define PROT_BUILD_FINISH	6

#define CHIRAL_D		0
#define CHIRAL_R		0
#define CHIRAL_L		1

#define DEFAULT_AUTO_BUILD_MODE		1

/* Delete Residue dialog constants */
#define PB_DR_DELETE		0
#define PB_DR_CLEAR		1
#define PB_DR_FINISH		2
#define MAX_PB_DR_ATOMS		1
#define MAX_PB_DR_RESIDUES	1

#define NO_RESIDUE		-1

/* Insert Residue dialog constants */
#define PB_IR_INS_AFTER		0
#define PB_IR_INS_BEFORE	1
#define PB_IR_CLEAR		2
#define PB_IR_FINISH		3
#define MAX_PB_IR_ATOMS		1
#define MAX_PB_IR_RESIDUES	1

#define PB_SR_FINISH		0

/* Mutate Residue dialog constants */
#define PB_MR_MUTATE		0
#define PB_MR_CLEAR		1
#define PB_MR_FINISH		2
#define MAX_PB_MR_ATOMS		1
#define MAX_PB_MR_RESIDUES	1

#define PROTEIN_ORIGIN_X		100
#define PROTEIN_ORIGIN_Y		50
#define PROTEIN_LENGTH			500
#define PROTEIN_HEIGHT			200

/* OMUPD drm 11/11/91 modify colour SSF 608 */
#define PROTEIN_WINDOW_RED	50
#define PROTEIN_WINDOW_GREEN	50
#define PROTEIN_WINDOW_BLUE	50

#define PB_BUTTON_LEFT		20	/* left corner of first button */
#define PB_BUTTON_BOTTOM	540	/* bottom corner of first button */
#define PB_BUTTON_LENGTH	50	/* length of first button */
#define PB_BUTTON_HEIGHT	25	/* height of first button */
#define PB_SHIFT		70	/* inter-button distance */

#define PB_BUTTON_BOTTOM_INS	300	/* bottom corner of first button in insert dialog */

/* Protein Build dialog item identifiers */
#define iPBAla			   0	/* Ala button item */
#define iPBArg			   1	/* Arg button item */
#define iPBAsn			   2	/* Asn button item */
#define iPBAsp			   3	/* Asp button item */
#define iPBCys			   4	/* Cys button item */
#define iPBGln			   5	/* Gln button item */
#define iPBGlu			   6	/* Glu button item */
#define iPBGly			   7	/* Gly button item */
#define iPBHis			   8	/* His button item */
#define iPBIle			   9	/* Ile button item */
#define iPBLeu			   10	/* Leu button item */
#define iPBLys			   11	/* Lys button item */
#define iPBMet			   12	/* Met button item */
#define iPBPhe			   13	/* Phe button item */
#define iPBPro			   14	/* Pro button item */
#define iPBSer			   15	/* Ser button item */
#define iPBThr			   16	/* Thr button item */
#define iPBTrp			   17	/* Trp button item */
#define iPBTyr			   18	/* Tyr button item */
#define iPBVal			   19	/* Val button item */

#define PC_BOX_LEFT		40	/* left corner of box */
#define PC_BOX_RIGHT		280	/* right corner of box */
#define PC_BOX_BOTTOM		100	/* bottom of box */
#define PC_BOX_TOP		350	/* top of box */

#define PC_BOX_SHIFTV		50	/* distance between lines */
#define PC_BOX_SHIFTH		80	/* distance between lines */

/* Protein conformation dialog constants */
#define PROT_CONF_UPDATE	0
#define PROT_CONF_CANCEL	1
#define PROT_CONF_CLEAR		2
#define PROT_CONF_ALPHA		3
#define PROT_CONF_BETA		4
#define PROT_CONF_USER		5

#define MAX_PC_UC_ATOMS		2
#define MAX_PC_UC_RESIDUES	2

#define PROT_TRANSFER_CANCEL	0
#define PROT_TRANSFER_ENTER	1

#endif
