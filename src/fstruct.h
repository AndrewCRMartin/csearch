
/*-------------------------------------------------------------*/
/*                                                             */
/*                                                             */
/*    (C) Jan Pedersen                           20.02.90      */
/*                                                             */
/*    Lab of Moleclar Biophysics                 v1.0          */
/*    Rex Richards Building                                    */
/*    South Parks Road                                         */
/*    Oxford OX1 3QU                                           */
/*                                                             */
/*                                                             */
/*    This code is in the public domain. It may be copied      */
/*    and/or modified by anyone providing this notice is       */
/*    retained and that the code is not sold for profit.       */
/*    Programs resulting from the use of this code may be      */
/*    sold commercially, providing suitable acknowledge-       */
/*    ments are included and that notice is given that         */
/*    this portion of the code is used with permission of      */
/*    the author.                                              */
/*                                                             */
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/*    Structures and definitions for framework builder         */
/*    J.T.P. 10.90    Bath University MG                       */
/*                                                             */
/*-------------------------------------------------------------*/

#include <math.h>

#define TRUE 1
#define FALSE 0
#define START_OF_HEAVY_CHAIN 118

#ifndef PI
#define PI M_PI 
#endif

typedef struct pdb_format
	{
	char info[7];
	int atomno;
	char atomtyp[5];
	char restyp[4];
	char chainid[3];
	int resno;
        float X,Y,Z,occup,bval;
	struct pdb_format *next;
        struct pdb_format *prev;
        } PDB;

typedef struct atom_format
	{
	int atomno;
	float X,Y,Z;
	float vdw_and_probe;
	struct atom_format *next;
	} FB_ATOM;

typedef struct nayb_list
	{
	FB_ATOM *atom;
	FB_ATOM *nayb[50];
	struct nayb_list *next;
	} NAYB;

