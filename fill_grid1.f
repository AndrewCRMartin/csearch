C
C     This file contains Fortran subroutines for handling the space grid.
C     The additional C code is found in gridc.c.
C
C     Copyright (c) 1987 Robert E. Bruccoleri
C     Copying of this software, in whole or in part, is permitted
C     provided that the copies are not made for commercial purposes,
C     appropriate credit for the use of the software is given, this
C     copyright notice appears, and notice is given that the copying
C     is by permission of Robert E. Bruccoleri. Any other copying
C     requires specific permission.
C
C                     Management of close contacts:
C
C             Close contact searches are performed using Cartesian space
C     grid. The grid size is set at a value bigger than any repulsive
C     contact whose energy would exceed reasonable values of MAXEVDW.
C     The bounds of the grid are determined by the molecular dimensions,
C     and the location and size of the loop being searched over. The
C     grid consists of pointers to an array of linked lists which store
C     the atoms within the cell. The free elements in the array of
C     linked list heads and tails are managed by a linked list of free
C     elements. A close contact search then requires only searching a
C     maximum of 27 cells. It is also relatively quick to remove and add
C     atoms to the list which is important as conformations are
C     constructed.
C
C             If the space grid overflows, it is expanded to a larger
C     size.
C
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      SUBROUTINE FILL_GRID1(SPACE_GRID,EXCLUDED,CNTNBX,INGRID,NBXA,
     +                      NEXTHD,CLSHD,CLSTL,NEXTCLS,CLSATM,RESBYA,
     +                      RADIUS)
C
C     Initializes the space grid, along with the free lists used to
C     store linked lists of atoms. Also, the excluded array is also
C     cleared.
C
#include "impnone.inc"
#include "grid.inc"
      INTEGER*2 SPACE_GRID(NGRIDX,NGRIDY,NGRIDZ)
      LOGICAL EXCLUDED(*)
      INTEGER CNTNBX(*)
      LOGICAL INGRID(*)
      INTEGER*2 NBXA(MAXNBX,*)
      INTEGER NEXTHD(*), CLSHD(*), CLSTL(*), NEXTCLS(*), CLSATM(*),
     +        RESBYA(*)
      REAL RADIUS(*)
#include "params.inc"
#include "values.inc"
#include "coords.inc"
#include "dbg.inc"
#include "engpar.inc"
#include "pstruct.inc"
C
      INTEGER I
      INTEGER STARTNB, J, IND, DUMMY_TAIL
      INTEGER IX, IRES, IAT
      REAL MAXR
C
      CALL FILL2(SPACE_GRID,NGRIDX*NGRIDY*NGRIDZ,0)
      DO 100 I = 1, NATOMS
         EXCLUDED(I) = .FALSE.
  100 CONTINUE
      CALL FILL4(CNTNBX,NATOMS,0)
      CALL FILLLOG(INGRID,NATOMS,.FALSE.)
      DO 200 I = 1, NATOMS
         IF (I.EQ.1) THEN
            STARTNB = 1
         ELSE
            STARTNB = LSTEXC(I-1) + 1
         ENDIF
         DO 150 IX = STARTNB, LSTEXC(I)
            J = NBEXCL(IX)
            IF (J.GE.0) THEN
               IF (I.LT.J) THEN
                  CNTNBX(I) = CNTNBX(I) + 1
                  IF (CNTNBX(I).GT.MAXNBX) THEN
                     CALL CPRINT(
     +                         'Error in FILL_GRID1 -- MAXNBX exceeded.'
     +                         )
                     CALL DIE
                  ENDIF
                  NBXA(CNTNBX(I),I) = J
                  CNTNBX(J) = CNTNBX(J) + 1
                  IF (CNTNBX(J).GT.MAXNBX) THEN
                     CALL CPRINT(
     +                         'Error in FILL_GRID1 -- MAXNBX exceeded.'
     +                         )
                     CALL DIE
                  ENDIF
                  NBXA(CNTNBX(J),J) = I
               ENDIF
            ENDIF
  150    CONTINUE
  200 CONTINUE
      CALL INFRLS(FREEHD,DUMMY_TAIL,NEXTHD,NATOMS)
      CALL INFRLS(FREECLS,DUMMY_TAIL,NEXTCLS,NATOMS)
      DO 300 IND = 1, NATOMS
         IF (XCART(IND).NE.ANUM) THEN
            CALL ADATMTGRD(%VAL(IND))
         ENDIF
  300 CONTINUE
      CALL FIXINITGRD
      DO 400 IRES = 1, NRES
         DO 350 IAT = LSTATM(IRES) + 1, LSTATM(IRES+1)
            RESBYA(IAT) = IRES
  350    CONTINUE
  400 CONTINUE
      CALL CPYPRM(VDWRAD,ATFLAG,ATCODE,RADIUS,NATOMS)
      MAXRADIUS = MAXR(RADIUS,NATOMS)
      RETURN
      END
