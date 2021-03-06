      SUBROUTINE SRCHNATM1(IND,SPACE_GRID,SEARCH_MODE,MAXEVDW,
     +                             IGNORE_EVDW,CNTNBX,NBXA,EXCLUDED,
     +                             PARM_NO,CLSHD,NEXTCLS,CLSATM,DONP,
     +                             ACCP,QSIDE,SIDEHITS,RESBYA,IMPACT,
     +                             EEL,EVDW,EHB,OUTOFBOUND)
C
C     Performs a search of the space near atom, IND. The actual
C     operation is determined by the variable, SEARCH_MODE, which is
C     decoded as follows:
C
C     SEARCH_MODE value       Function
C
C     CONTACT                 Search for contacts which exceed MAXEVDW
C                             in energy
C     NBOND_ENERGY            Evaluate non-bonded energy terms.
C     DONOR_HBOND_ENERGY      Calculate hydrogen bond energy for
C                             hydrogen atom, IND.
C     ACCEPTOR_HBOND_ENERGY   Calculate hydrogen bond energy for the
C                             hydrogen bond acceptor, IND.
C
C     If the atom, IND, does not fit in the grid, OUTOFBOUND will
C     be returned as true so that the grid can be enlarged.
C
      IMPLICIT NONE
      include "grid.inc"
      include "params.inc"
      include "cg.inc"
      include "coords.inc"
      include "dbg.inc"
      include "hbonds.inc"
      include "values.inc"
      include "engpar.inc"
      include "pstruct.inc"
      include "restop.inc"
 
C Argument declarations

      INTEGER*2 SPACE_GRID(NGRIDX,NGRIDY,NGRIDZ), NBXA(MAXNBX,*),
     +          PARM_NO(100,100)

      INTEGER CNTNBX(*), CLSHD(*), NEXTCLS(*), CLSATM(*), DONP(*), 
     +        ACCP(*), SIDEHITS(*), RESBYA(*), IND, SEARCH_MODE

      REAL MAXEVDW

      DOUBLE PRECISION EEL, EVDW, EHB
 
      LOGICAL EXCLUDED(*), QSIDE(*), IMPACT, IGNORE_EVDW, OUTOFBOUND

C Local declarations

      INTEGER IX, IY, IZ, IRAD, STARTX, STARTY, STARTZ, LASTX, LASTY,
     +        LASTZ, I, CHMCEIL

      REAL XIND, YIND, ZIND, CUT2
C
      IF (SEARCH_MODE.EQ.CONTACT) IMPACT = .FALSE.
      CALL COMPSPCGRD(IND,IX,IY,IZ,OUTOFBOUND)
      IF (OUTOFBOUND) RETURN
 
      IF (SEARCH_MODE.EQ.CONTACT) THEN
         IRAD = 1
         CUT2 = 1.0
      ELSEIF (SEARCH_MODE.EQ.NBOND_ENERGY) THEN
 
C ACRM
C    NBCUT taken of the heap and simply placed in
C    the NBND common block
CCC            IRAD = CHMCEIL(RHEAP(BNBND(NBCUT))*RECIPGRID)
CCC            CUT2 = (RHEAP(BNBND(NBCUT))*RECIPGRID)**2
         IRAD = CHMCEIL(NBCUT*RECIPGRID)
         CUT2 = (NBCUT*RECIPGRID)**2
      ELSEIF (SEARCH_MODE.EQ.ACCEPTOR_HBOND_ENERGY) THEN
         IRAD = CHMCEIL(HBCUT*RECIPGRID)
         CUT2 = (HBCUT*RECIPGRID)**2
      ELSEIF (SEARCH_MODE.EQ.DONOR_HBOND_ENERGY) THEN
         IRAD = CHMCEIL(HBCUT*RECIPGRID)
         CUT2 = (HBCUT*RECIPGRID)**2
      ENDIF
 
      STARTX = IX - IRAD
      STARTY = IY - IRAD
      STARTZ = IZ - IRAD
      IF (STARTX.LT.1) STARTX = 1
      IF (STARTY.LT.1) STARTY = 1
      IF (STARTZ.LT.1) STARTZ = 1
      LASTX = IX + IRAD
      LASTY = IY + IRAD
      LASTZ = IZ + IRAD
      IF (LASTX.GT.NGRIDX) LASTX = NGRIDX
      IF (LASTY.GT.NGRIDY) LASTY = NGRIDY
      IF (LASTZ.GT.NGRIDZ) LASTZ = NGRIDZ
      DO 100 I = 1, CNTNBX(IND)
         EXCLUDED(NBXA(I,IND)) = .TRUE.
  100 CONTINUE
      XIND = XCART(IND)
      YIND = YCART(IND)
      ZIND = ZCART(IND)
      IF (SEARCH_MODE.EQ.NBOND_ENERGY.OR.SEARCH_MODE.EQ.CONTACT) THEN
         CALL RNNBSRCH(SEARCH_MODE,STARTX,LASTX,STARTY,LASTY,
     +                         STARTZ,LASTZ,SPACE_GRID,CLSHD,CLSATM,
     +                         EXCLUDED,PARM_NO,MAXEVDW,IMPACT,IND,
     +                         RESBYA,QSIDE,SIDEHITS,EEL,IGNORE_EVDW,
     +                         EVDW,NEXTCLS,XIND,YIND,ZIND)
      ELSE
         CALL RNHBNDSRCH(STARTX,STARTY,STARTZ,LASTX,LASTY,LASTZ,
     +                         SPACE_GRID,CLSHD,CLSATM,EXCLUDED,
     +                         SEARCH_MODE,DONP,NEXTCLS,PARM_NO,EHB,
     +                         ACCP,IND)
      ENDIF
      DO 200 I = 1, CNTNBX(IND)
         EXCLUDED(NBXA(I,IND)) = .FALSE.
  200 CONTINUE
      RETURN
      END
