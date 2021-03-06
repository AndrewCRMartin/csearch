C
C     Copyright (c) 1987 Robert E. Bruccoleri
C     Copying of this software, in whole or in part, is permitted
C     provided that the copies are not made for commercial purposes,
C     appropriate credit for the use of the software is given, this
C     copyright notice appears, and notice is given that the copying
C     is by permission of Robert E. Bruccoleri. Any other copying
C     requires specific permission.
C
      SUBROUTINE SCHDLS(HEAD,TAIL,FREE,NEXT,A,ITEM)
C
C     Searches for ITEM in the linked list specified by HEAD, TAIL, and
C     NEXT whose elements are stored in A. The elements is deleted and
C     placed on the free list given by FREE. If the item is not found,
C     an error message is generated with a traceback, but execution will
C     continue.
C
C      IMPLICIT INTEGER(A-Z)
      IMPLICIT NONE
 
      INTEGER HEAD, TAIL, FREE, NEXT(*), A(*), ITEM, ITEMP
 
com omupd bnj 29/08/91
      INTEGER PREVP
com
 
      LOGICAL FOUND
C
C     CRAP-OUT
      IF (HEAD.NE.0) THEN
         IF (A(HEAD).EQ.ITEM) THEN
            ITEMP = HEAD
            IF (HEAD.EQ.TAIL) THEN
               HEAD = 0
               TAIL = 0
            ELSE
               HEAD = NEXT(HEAD)
            ENDIF
         ELSE
            ITEMP = HEAD
   20       CONTINUE
            PREVP = ITEMP
            ITEMP = NEXT(ITEMP)
C           CRAP-OUT
            IF (ITEMP.EQ.0) GOTO 100
            FOUND = A(ITEMP).EQ.ITEM
            IF (.NOT.FOUND) GOTO 20
            IF (ITEMP.EQ.TAIL) THEN
               TAIL = PREVP
               NEXT(TAIL) = 0
            ELSE
               NEXT(PREVP) = NEXT(ITEMP)
            ENDIF
         ENDIF
         NEXT(ITEMP) = FREE
         FREE = ITEMP
         RETURN
      ENDIF
CCC   TO CRAP-OUT
  100 CONTINUE
      CALL CPRINT('***** Error in SCHDLS *****  Unable to find ITEM.')
      CALL TRACE
      RETURN
      END
