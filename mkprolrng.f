CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      SUBROUTINE MKPROLRNG(X,Y,Z,IND_C,IND_N,IND_CA,IND_CB,
     +                             IND_CG,IND_CD,PHI,PROCONS,PROCONSPHI,
     +                             NPROCONS)
C
C     Given a value for the PHI torsion, and pointers to various atoms
C     of the proline residue (in IND_C, IND_N, etc.), and the proline
C     constructor arrays, the positions of CB, CG and CD are
C     constructed. IND_C points to the carbonyl carbon of the previous
C     residue. PROCONS contains the internal coordinates for the three
C     ring atoms in the order, CA-CB, N-CA-CB, C-N-CA-CB, CB-CG,
C     CA-CB-CG, N-CA-CB-CG, CG-CD, CB-CG-CD, CA-CB-CG-CD. PROCONSPHI
C     contains the values for PHI to which the constructor information
C     applies, and NPROCONS contains the number of Phi's in the tables.
C
      IMPLICIT NONE
 
      INTEGER IND_C, IND_N, IND_CA, IND_CB, IND_CG, IND_CD
      INTEGER NPROCONS,START,STOP
      REAL X(*), Y(*), Z(*)
      REAL PHI, PROCONS(9,*), PROCONSPHI(*)
      REAL BOND(3), THETA(3), TORSION(3), PHI1, PHI2, INTERPA
 
      CHARACTER*100 BUFFER
 
      include "values.inc"
C
      CALL BINSCHR(PROCONSPHI,NPROCONS,PHI,START,STOP)
 
      IF (START.LT.1.OR.STOP.GT.NPROCONS) THEN
         WRITE (BUFFER,9001) PHI
         CALL CPRINT(BUFFER)
         CALL DIE
      ENDIF
      PHI1 = PROCONSPHI(START)
      PHI2 = PROCONSPHI(STOP)
      BOND(1) = INTERPA(PHI1,PROCONS(1,START),PHI2,PROCONS(1,STOP),
     +          PHI)
      THETA(1) = INTERPA(PHI1,PROCONS(2,START),PHI2,PROCONS(2,STOP),
     +           PHI)
      TORSION(1) = INTERPA(PHI1,PROCONS(3,START),PHI2,
     +             PROCONS(3,STOP),PHI)
      BOND(2) = INTERPA(PHI1,PROCONS(4,START),PHI2,PROCONS(4,STOP),
     +          PHI)
      THETA(2) = INTERPA(PHI1,PROCONS(5,START),PHI2,PROCONS(5,STOP),
     +           PHI)
      TORSION(2) = INTERPA(PHI1,PROCONS(6,START),PHI2,
     +             PROCONS(6,STOP),PHI)
      BOND(3) = INTERPA(PHI1,PROCONS(7,START),PHI2,PROCONS(7,STOP),
     +          PHI)
      THETA(3) = INTERPA(PHI1,PROCONS(8,START),PHI2,PROCONS(8,STOP),
     +           PHI)
      TORSION(3) = INTERPA(PHI1,PROCONS(9,START),PHI2,
     +             PROCONS(9,STOP),PHI)
      CALL CARTX2(X,Y,Z,IND_C,IND_N,IND_CA,IND_CB,BOND(1),THETA(1),
     +            TORSION(1))
      CALL CARTX2(X,Y,Z,IND_N,IND_CA,IND_CB,IND_CG,BOND(2),THETA(2),
     +            TORSION(2))
      CALL CARTX2(X,Y,Z,IND_CA,IND_CB,IND_CG,IND_CD,BOND(3),THETA(3),
     +            TORSION(3))
      RETURN
 9001 FORMAT ('0Error in MKPROLRNG -- Phi value =',1PG14.7,
     +        ' is out of bounds.')
      END
