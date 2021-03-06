       SUBROUTINE GCF(GAMMCF,A,X,GLN)
C 
COM OMUPD BNJ 2/9/91
C 
       IMPLICIT NONE
C 
       REAL  GAMMCF , A , X,GLN,EPS,GOLD,A0,A1,B0,B1,FAC
       REAL  AN,ANA,G,GAMMLN,ANF, TEST
C
       INTEGER ITMAX,N
C
COM
C
C     Returns the incomplete gamma function Q(a,x) as a continued
C     fraction GAMMCP.
C     Also returns ln gamma(a) as GLN
C 
      PARAMETER (ITMAX=10000,EPS=3.E-20)
C 
      GLN = GAMMLN(A)
      GOLD = 0.0
      A0 = 1.0
      A1 = X
      B0 = 0.0
      B1 = 1.0
      FAC = 1.0
      DO 100 N = 1, ITMAX
         AN = FLOAT(N)
         ANA = AN - A
         A0 = (A1+A0*ANA)*FAC
         B0 = (B1+B0*ANA)*FAC
         ANF = AN*FAC
         A1 = X*A0 + ANF*A1
         B1 = X*B0 + ANF*B1
         IF (A1.NE.0.) THEN
            FAC = 1.0/A1
            G = B1*FAC
            IF (EPS.GT.ABS((G-GOLD)/G)) GOTO 200
            GOLD = G
         ENDIF
  100 CONTINUE
      IF (ABS((G-GOLD)/G).LT.(EPS*1.0E10)) THEN
         PRINT *, 'Warning in GCF: MAY not have converged'
         PRINT *, 'G =', G
         PRINT *, 'GOLD = ', GOLD
         PRINT *, '(G-GOLD)/G =', (G-GOLD)/G
         PRINT *, 'ABS((G-GOLD)/G) =', (ABS(G-GOLD)/G)
         PRINT *, 'EPS*1.0E10 =', EPS*1.0E10
      ELSE
         PRINT *, 'Error in GCF: A too large, ITMAX too small'
         PRINT *, 'G =', G
         PRINT *, 'GOLD = ', GOLD
         PRINT *, '(G-GOLD)/G =', (G-GOLD)/G
         PRINT *, 'ABS((G-GOLD)/G) =', (ABS(G-GOLD)/G)
         PRINT *, 'EPS =', EPS
         CALL DIE
      ENDIF
C
  200 CONTINUE
C
C -- Prevent floating point underflows if bounds checking is enabled.
C    If TEST is less than '-80.' round down to 0.0 .
C
      TEST = -X + A * ALOG(X) - GLN
      IF ( TEST .GT. -80. ) THEN
        GAMMCF = EXP( TEST ) * G
      ELSE
        GAMMCF = 0.0
      ENDIF
C
      RETURN
      END
