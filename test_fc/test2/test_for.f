      SUBROUTINE TEST_FOR(I)
      INTEGER N
      INTEGER*2 ARRAY
      COMMON /GRID/ N, ARRAY

      DO 100 J=1,N
         ARRAY(J) = I
 100  CONTINUE 

C      CALL FILL2(I)
      END
