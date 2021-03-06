/******************************************************************************
 *      Name: HPGraph.h                                                       *
 *  Function: Header file primarily for use by the PGL library when           *
 *            used on the HP machine running Xwindows.                        *
 * Copyright: (C) Oxford Molecular Limited                                    *
 *----------------------------------------------------------------------------*
 *    Author: G C Calvert, Tessella Support Services plc                      *
 *      Date: 28/08/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * dd/mm/yy                                                                   *
 * 30/11/90 GCC     Corrected PIMMS_CURSOR_ARROW to PIMMS_CURSOR_NORMAL       *
 * 04/02/91 GCC     Corrected forlink and backlink pointers in                *
 *                  HPwindow structure.                                       *
 * 20/03/91 GCC     Added keysyms include file for X windows.                 *
 * 19/07/91 JPH     Moved PIMMS_CURSOR_ARROW etc to PGLProto.h.               *
 * 26/07/91 JPH     Added definitions of 'Window' on SG, ColorIndex on HP     *
 ******************************************************************************/

#ifndef __HPGRAPH__
#define __HPGRAPH__

#ifdef __HEWLETTPACKARD__

/* include the starbase and Xwindows header files */

#include <starbase.c.h>

#ifndef X_H
#include <X11/X.h>
#endif

#ifndef _XtIntrinsic_h
#ifdef SIGCHLD	/* SIGCHLD is defined in signal.h and Xos.h on HP */
#undef SIGCHLD	/* so undefine before includuing Xos.h (within Intrinsic.h) */
#endif
#include <X11/Intrinsic.h>
#endif

#ifndef _XtAtom_h_
#include <X11/StringDefs.h>
#endif

#ifndef _XLIB_H_
#include <X11/Xlib.h>
#include <X11/Xlib.h>
#endif

#ifndef _XUTIL_H_
#include <X11/Xutil.h>
#endif

#include <X11/cursorfont.h>
#include <X11/keysym.h>

/* define the text height for PGL drawn text */
#define PGL_CHAR_HEIGHT 9

/* The basic PGL library (as designed for the Silicon Graphics machine )
   used a single long integer to reference a window.  The Xwindows/starbase
   system uses two pointers to a window, an Xwindow pointer for Xwindows
   output, and a starbase file pointer for starbase output.  In order to
   maintain compatibility with the basic PGL library, the HP PGL library
   implements its own long integer pointer which is used to reference
   these two other pointers.  This means that the higher level (above the 
   PGL library) source code need not be changed and a window is still
   referenced by a single long integer.

   The PGL library therefore maintains a structure for each open window
   in which it holds details of the Xwindow and starbase pointers.  The
   PGL long integer is used to point into the appropriate structure.

   The structures are maintained in a linked list, with elements of the 
   list being allocated dynamically when a window is opened and deallocated
   when a window is closed.

   Each element consists of five items:

      forlink - is a pointer to the next element in the list, set to NULL
                if this is the last element in the list
      backlink - is a pointer to the previous element in the list, being
                set to NULL is this is the first element in the list
      windowID - is the Xwindow identifier
      fildes - is the starbase file descriptor identifier
      ID - is the PGL window identifier

   The list is maintained in order of ID, with ID running from 0 upwards.
   When a new element is required, storage is allocated and it is inserted
   into the list at the appropriate point, or appended at the end.  Empty
   slots are filled  if possible.  When an element is deleted, its storage
   is freed, and the forlink and backlink pointers of adjacent elements 
   are modified accordingly.  When an element must be referenced, the list
   is scanned until the approriate element is found. 

   PGL routines for processing the list are available.  

   In addition, a number of global variables are maintained in conjunction
   with the list.  

      Display *XserverID - is a pointer to the Xwindows display
      long CurrentWindow - is a PGL pointer to the window regarded as
                           current  
      HPwindowPtr - is a pointer to an element in the linked list of
                    window identifiers.  It does not always point to the 
                    start of the list, but does always point to an element
                    in the list.  It is a fairly trivial matter to scan
                    back down the list to set this variable to point to 
                    the first element in the list if required.  */

typedef struct _HPwindow {
               struct _HPwindow *forlink;  /* pointer to next element in list */
               struct _HPwindow *backlink; /* pointer to previous element in list */
               Window windowID;	/* Xwindows window identifier */
               int fildes;	/* starbase file identifier */
               long ID;		/* PGL window identifier */
               short LWidth;    /* Line drawing width for this window */
               short OriginX;   /* Window X Origin */
               short OriginY;   /* Window Y Origin */
               int Buffer;      /* Current buffer for double buffering */
               short IsBuffered; /* Is this window double buffered ? */
               long event_mask; /* event mask for window */
               } HPwindow, *HPwindowPtr;

/* Since Starbase doesn't define a "get the current line drawing width"
   function, it has been added to the above structure. A default line
   width HP_INITIAL_LWID is also defined */

#define HP_INITIAL_LWID 1

/* Window border width for bordered windows */

#define HP_WINDOW_BORDER_WIDTH 10

/* Define a "Fix" to be used by PGLgetmousxy.c to correct for the top window
   border width */

#define HP_WINDOW_TOPBORDER_FIX 20
#define PIMMS_X_FRAME_BORDER_WIDTH 5

/* Define fractions of whole screen to use with PIMMS */

#define HP_FRAC_SCREEN 0.95

/* define a structure to hold a linked list of colour map entries */
typedef struct _HPcolor
   {
      struct _HPcolor *forlink;   /* pointer to next element in list */
      struct _HPcolor *backlink;  /* pointer to previous element in list */
      short red;       /* red colour value (0-255) */
      short green;     /* green colour value (0-255) */
      short blue;      /* blue colour value (0-255) */
      unsigned long index; /* index into colour map */
      short class;     /* class of entry, single or depth cue */
      short ncolors;   /* number of colours for a depth cue entry */
   } HPcolor, *HPcolorPointer;

/* the stucture to hold details of the color map */
typedef struct
   {
      Colormap cmap;   /* the pointer to the colour map */
      HPcolorPointer linkPtr; /* the pointer to the linked list */
   } ColorRecord;

enum {PIMMS_SINGLE_COLOR, PIMMS_DEPTH_CUE_COLOR};

#else  /* if not HP/Xwindows/starbase */

/* define types for unused Xwindows identifiers */
typedef unsigned long Window;
typedef short  Display;
typedef short *HPwindowPtr;
/* the stucture to hold details of the color map */
typedef struct
   {
      char *linkPtr; /* the pointer to the linked list */
   } ColorRecord;

#endif

#endif
