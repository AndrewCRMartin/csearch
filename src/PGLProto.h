/***********************************************************************
 *      Name: PGLProto.h                                               *
 *  Function: PIMMS Graphics Library header file                       *
 * Copyright: (C) Oxford Molecular Limited                             *
 *---------------------------------------------------------------------*
 *    Author: D. Walker, Tessella Support Services plc                 *
 *      Date: 12/06/89                                                 *
 *---------------------------------------------------------------------*
 * Modification Record                                                 *
 * Date     Inits   Comments                                           *
 * 14/03/91  KJW    Add the WindowBox structure                        *
 * 20/03/91  GCC    Added arrow key definitions.                       *
 * 19/07/91  JPH    Added PIMMS_CURSOR definitions ( from HPGraph.h ). *
 * 08/10/91  drm    Added definition for VGX                           *
 * 09/10/91  drm    Added definition for VGX for HP section            *
 ***********************************************************************/

#ifndef __PGLPROTO__
#define __PGLPROTO__
#if defined (__SILICONGRAPHICS__)
#include <gl/sphere.h>
#endif

/* WARNING: If extra definitions are added to this file, they should also */
/*          be added to the FORTRAN equivalent 'pgl.inc'. */
/*          Also, please DO NOT add definitions for the HP without adding */
/*          a similar one for the SG, IBM, vax ( dummy ) etc */

#if defined (__HEWLETTPACKARD__)
/* Device declarations */
#define PIMMS_LEFTMOUSE    Button1Mask            /* Left Mouse */
#define PIMMS_MIDDLEMOUSE  Button2Mask            /* Middle Mouse */
#define PIMMS_RIGHTMOUSE   Button3Mask            /* Right Mouse */
#define PIMMS_KEYBOARD     KeyPressMask           /* Keyboard key press */
#define PIMMS_WINSHUT      StructureNotifyMask    /* Close */ 
#define PIMMS_WINQUIT      StructureNotifyMask    /* Quit */
#define PIMMS_WINFREEZE    NoEventMask            /* Stow */
#define PIMMS_WINTHAW      NoEventMask            /* Unstow */
#define PIMMS_REDRAW       ExposureMask           /* Redraw events */
#define PIMMS_REDRAWICONIC NoEventMask            /* Iconize */
#define PIMMS_TIMER0       NoEventMask            /* timer */
#define PIMMS_INPUTCHANGE  EnterWindowMask        /* Input focus */
#define PIMMS_LEFTARROW    XK_Left                /* Left arrow */
#define PIMMS_RIGHTARROW   XK_Right               /* Right arrow */
#define PIMMS_DOWNARROW    XK_Down                /* Down arrow */
#define PIMMS_UPARROW      XK_Up                  /* Up arrow */
#define PIMMS_DOUBLECLICK  100                    /* Dble Click Event */
#define PIMMS_STILLDOWN    222                    /* PGLgetbutton still down */

/* buffer declarations */
#define PIMMS_BCKBUFFER   1
#define PIMMS_FRNTBUFFER  2
#define PIMMS_BOTHBUFFERS 3

/* Cursor types */
#define PIMMS_CURSOR_NORMAL XC_arrow
#define PIMMS_CURSOR_WATCH XC_watch
#define PIMMS_CURSOR_BUG XC_spider

/* define number of double buffer redraws */
#define PIMMS_DOUBLE_BUFFER_REDRAWS 2

/* drm 09/10/91 define these as the SG_VGX value is used in InitMainScr */
#define SG_B_OR_G         0
#define SG_GT             1
#define SG_GTX            2
#define SG_PERSONAL_IRIS  3
#define SG_VGX           4

/* define number of polygons for HP sphere drawing */
#define LONGITUDES 20
#define LATITUDES  10

#else

#if defined (__SILICONGRAPHICS__) || defined (__IBM__)
/* Device declarations */
#define PIMMS_LEFTMOUSE    LEFTMOUSE              /* Left Mouse */
#define PIMMS_MIDDLEMOUSE  MIDDLEMOUSE            /* Middle Mouse */
#define PIMMS_RIGHTMOUSE   RIGHTMOUSE             /* Right Mouse */
#define PIMMS_KEYBOARD     KEYBD                  /* Keyboard key press */
#if defined (__IBM__)
#define PIMMS_WINSHUT      WINQUIT                /* IBM does not support shut */
#else
#define PIMMS_WINSHUT      WINSHUT                /* Close */ 
#endif
#define PIMMS_WINQUIT      WINQUIT                /* Quit */
#define PIMMS_WINFREEZE    WINFREEZE              /* Stow */
#define PIMMS_WINTHAW      WINTHAW                /* Unstow */
#define PIMMS_REDRAW       REDRAW                 /* Redraw events */
#define PIMMS_REDRAWICONIC REDRAWICONIC           /* Iconize */
#define PIMMS_TIMER0       TIMER0                 /* timer */
#define PIMMS_INPUTCHANGE  INPUTCHANGE            /* Input focus */
#define PIMMS_LEFTARROW    LEFTARROWKEY           /* Left arrow */
#define PIMMS_RIGHTARROW   RIGHTARROWKEY          /* Right arrow */
#define PIMMS_DOWNARROW    DOWNARROWKEY           /* Down arrow */
#define PIMMS_UPARROW      UPARROWKEY             /* Up arrow */
#define PIMMS_DOUBLECLICK      100                /* Dble Click Event */
#define PIMMS_STILLDOWN    222                    /* PGLgetbutton still down */

/* buffer declarations */
#define PIMMS_BCKBUFFER   BCKBUFFER
#define PIMMS_FRNTBUFFER  FRNTBUFFER
#define PIMMS_BOTHBUFFERS BOTHBUFFERS

/* Cursor types */
#define PIMMS_CURSOR_NORMAL 0
#define PIMMS_CURSOR_WATCH 1
#define PIMMS_CURSOR_BUG   2

/* define number of double buffer redraws */
#if defined (__IBM__)
#define PIMMS_DOUBLE_BUFFER_REDRAWS 2
#else
#define PIMMS_DOUBLE_BUFFER_REDRAWS 1
#endif

#define SG_B_OR_G        0
#define SG_GT            1
#define SG_GTX           2
#define SG_PERSONAL_IRIS 3
#define SG_VGX           4

#else

/* Dummy declarations */
/* None of these numbers mean anything !!! */
/* But a definition is needed to allow code to compile on other machines */

/* Device declarations */
#define PIMMS_LEFTMOUSE    0                      /* Left Mouse */
#define PIMMS_MIDDLEMOUSE  1                      /* Middle Mouse */
#define PIMMS_RIGHTMOUSE   2                      /* Right Mouse */
#define PIMMS_KEYBOARD     3                      /* Keyboard key press */
#define PIMMS_WINSHUT      4                      /* Close */ 
#define PIMMS_WINQUIT      5                      /* Quit */
#define PIMMS_WINFREEZE    6                      /* Stow */
#define PIMMS_WINTHAW      7                      /* Unstow */
#define PIMMS_REDRAW       8                      /* Redraw events */
#define PIMMS_REDRAWICONIC 8                      /* Iconize */
#define PIMMS_TIMER0      10                      /* timer */
#define PIMMS_INPUTCHANGE 11                      /* Input focus */
#define PIMMS_DOUBLECLICK      100                /* Dble Click Event */
#define PIMMS_STILLDOWN    222                    /* PGLgetbutton still down */

/* buffer declarations */
#define PIMMS_BCKBUFFER   0
#define PIMMS_FRNTBUFFER  1
#define PIMMS_BOTHBUFFERS 2

/* Cursor types */
#define PIMMS_CURSOR_NORMAL 0
#define PIMMS_CURSOR_WATCH 1
#define PIMMS_CURSOR_BUG   2

/* define number of double buffer redraws */
#define PIMMS_DOUBLE_BUFFER_REDRAWS 1

#define SG_B_OR_G         0
#define SG_GT             1
#define SG_GTX            2
#define SG_PERSONAL_IRIS  3
#define SG_VGX           4

#endif    /* END SG or IBM */
#endif    /* END HP */

#define PIMMS_DEPTHCUE_MIN   0         /* Minimum RGB value for d.cue */
#define PIMMS_DEPTHCUE_MIN_FRACTION 0.5	/* fractional reduction in intensity */

/* Bell volume parameter */
#define PIMMS_BELL_VOLUME 100


/* define the WindowBox structure to contain information  */
/* about window size and position (in screen coordinates) */
typedef struct _WindowBox *WindowBoxPtr;
typedef struct _WindowBox
   {
   long originX;             /* x coordinate of window origin */
   long originY;             /* y coordinate of window origin */
   long width;               /* window width (horizontal size) */
   long height;              /* window height (vertical size) */
   } WindowBox;

/* OMUPD RAS 27/04/92 Add a second field to what was an array
   of window identifiers kept by the PGL.  This means we can
   run some windows in CM mode and some in RGB               */

typedef struct {
   long ID;
   short cmode;              /* Colour mode TRUE CMap, FALSE RGB */
   short bmode;              /* Buffer TRUE Dbuf, false SBuf */
   } WIDlist, *WIDlistPtr ;

#endif /* END __PGLPROTO__ */
