CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C     TO EVALUATE-ENERGY-FOR-ONE-HYDROGEN-BOND
      SUBROUTINE HBENERGY(IHBOND,JHBOND,KHBOND,PARM_NO,EHB)
 
      IMPLICIT NONE
      include "params.inc"
      include "values.inc"
      include "grid.inc"
      include "cg.inc"
      include "coords.inc"
      include "engpar.inc"
      include "pstruct.inc"
      include "restop.inc"
      include "dbg.inc"
 
      INTEGER I1, J1, IHBOND, JHBOND, KHBOND, ICHBOND, KEYHB, NINDX
      INTEGER*2 PARM_NO(100,100)
      REAL DELX, DELY, DELZ, SS, DXI, DYI, DZI, RI2, DXJ, DYJ, DZJ, RJ2
      REAL RI, RJ, CST, R2, R4, R6, R10, R12, F1, F2, CST2
      DOUBLE PRECISION EHB1, EHB
 
      CHARACTER*100 BUFFER
 
      I1 = ATCODE(IHBOND)
      J1 = ATCODE(JHBOND)
      KEYHB = PARM_NO(I1,J1)
      ICHBOND = NINDX(KEYHB,HBKEY,NHBPAR)
      IF (ICHBOND.EQ.0) THEN
         CALL CPRINT('Error in HBENERGY -- Parameters not found')
         WRITE (BUFFER,9001) ACODES(I1), ACODES(J1)
         CALL CPRINT(BUFFER)
         CALL CPRINT(' The first parameter available will be used.')
         ICHBOND = 1
      ENDIF
      DELX = XCART(IHBOND) - XCART(JHBOND)
      DELY = YCART(IHBOND) - YCART(JHBOND)
      DELZ = ZCART(IHBOND) - ZCART(JHBOND)
      SS = DELX*DELX + DELY*DELY + DELZ*DELZ
      IF (SS.LT.CUTHB2) THEN
         DXI = XCART(IHBOND) - XCART(KHBOND)
         DYI = YCART(IHBOND) - YCART(KHBOND)
         DZI = ZCART(IHBOND) - ZCART(KHBOND)
         RI2 = DXI*DXI + DYI*DYI + DZI*DZI
         DXJ = XCART(JHBOND) - XCART(KHBOND)
         DYJ = YCART(JHBOND) - YCART(KHBOND)
         DZJ = ZCART(JHBOND) - ZCART(KHBOND)
         RJ2 = DXJ*DXJ + DYJ*DYJ + DZJ*DZJ
         RI = SQRT(RI2)
         RJ = SQRT(RJ2)
         CST = DXI*DXJ + DYI*DYJ + DZI*DZJ
         CST = -CST/RI/RJ
         IF (CST.GE.0.0.AND.CST.GE.COS_CUTHBA) THEN
            R2 = 1.0/SS
            R4 = R2*R2
            R6 = R2*R4
            R10 = R4*R6
            R12 = R6*R6
            F1 = HBR12(ICHBOND)*R10*R2
            F2 = HBR10(ICHBOND)*R10
            CST2 = CST*CST
            EHB1 = (F1-F2)*CST2*CST2
            EHB = EHB + EHB1
            IF (DBG_CGEN.GT.2) THEN
               WRITE (BUFFER,9002) ATMNME(IHBOND), ATMNME(KHBOND),
     +                             ATMNME(JHBOND), IHBOND, KHBOND,
     +                             JHBOND, SQRT(SS), EHB1
               CALL CPRINT(BUFFER)
            ENDIF
         ENDIF
      ENDIF
 9001 FORMAT (' for hydrogen bond between atoms ',A4,1X,A4)
 9002 FORMAT (' EHB for atoms:',3(1X,A4),'(',I5,1X,I5,1X,I5,') R =',
     +        F5.2,' EHB = ',1PG12.5)
      END
