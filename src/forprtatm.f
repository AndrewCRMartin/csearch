CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C     FORPRTATM
C     ACRM 18.08.91
C     Fortran call to print_atom1()
      SUBROUTINE FORPRTATM(STRING,ATNUM)
      CHARACTER*(*) STRING
      INTEGER ATNUM
      STRING = ' '
      CALL C_PRINT_ATOM(%REF(STRING),%VAL(ATNUM))
      RETURN
      END
