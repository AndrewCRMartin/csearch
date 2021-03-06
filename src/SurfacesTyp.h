/****************************************************************************** 
 *      Name: SurfacesTyp                                                     *
 *  Function: Surfaces types header file - contains definition of the data    *
 *            types used by the Nemesis Surfaces functions.                   *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: K.J. Woods, Tessella Support Services plc                       *
 *      Date: 21/05/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * 03/10/90 drm     Modified for PIMMS                                        *
 ******************************************************************************/

#ifndef __SURFACESTYP__
#define __SURFACESTYP__

#ifndef __SURFACES__
#include "Surfaces.h"
#endif

/* The Surface Settings record contains the current state of */
/* any settings set by the user from the Surfaces menu  */
typedef struct 
	{
	Logical		display;	/* flags if surface is to be displayed*/
	Logical		validSurface;	/* flags if a valid surface has been loaded */
	float		dotDensity;	/* surface dot density (dots/square Angstrom) */
	float		probeRadius;	/* radius of surface probe (Angstroms)*/
	float		vdWExpand;	/* vdW expansion factor */
	short		colourMode;	/* surface colour mode */
	char		surfaceName[MAX_SURF_NAME];	/* root name for surface files */
	} SurfaceSettings;

/* The Surface record contains the definition of a */
/* surface - read from a Connolly generated file   */
typedef struct 
	{
	float		x[MAXDOT];		/* surface x-coordinate */
	float		y[MAXDOT];		/* surface y-coordinate */
	float		z[MAXDOT];		/* surface z-coordinate */
	float		area[MAXDOT];		/* surface dot density (dots/square Angstrom) */
	} Surface, *SurfacePtr;

/* The Surface Property record contains the values of a given  */
/* property at each surface dot (the property must be a real quantity) */
typedef struct 
	{
	float		contact[MAXDOT];	/* contact surface property */
	float		reentrant[MAXDOT];	/* reentrant surface property */
	float       minimumValue;		/* minmum value on the surface */
	float       maximumValue;		/* maximum value on the surface */
	} SurfaceProperty, *SurfacePropertyPtr;

/* The SurfaceLookup record contains a list of */
/* the parent atoms of each dot on the surface */
typedef struct 
	{
	short	NContactDots;	/* number of dots in contact surface */
	short	NReentrantDots;	/* number of dots in reentrant surface */
	short	iXContact[MAXDOT];	/* logical position of parent atom */
	short	iXReentrant[MAXDOT];	/* logical position of parent atom */
	short	imolContact[MAXDOT];	/* parent molecule of dot */
	short	imolReentrant[MAXDOT];	/* parent molecule of dot */
	} SurfaceLookup, *SurfaceLookupPtr;

/* The SurfaceColour record contains a list of the */
/* colours used to colour each dot on the surface  */
typedef struct 
	{
	float	colourLevels[MAX_COLOUR_LEVELS + 2];	/* levels used to determine colour ranges */
	RGBColour	colours[MAX_COLOUR_LEVELS];     /* colour of each range */
	} SurfaceColour, *SurfaceColourPtr;

/* The Exclude Atom record contains the layout of the controls and the */
/* current state of any selections made during the Exclude Atom dialog */
/* Excluded atoms are flagged so that no Connolly surface is generated */
/* for these atoms.                                                    */
typedef struct 
	{
	short	nselectedAtoms;	/* number of atoms selected */
	short	selectedAtoms[MAX_SURF_EA_ATOMS];	/* selected atom to be excluded */
	short	EAoption;	/* Exclude Atom option selected*/
	} SurfExcludeAtom;
#endif
