C
C     Data structure for space grid. Pointer variables are prefixed
C     by GRID_ in order to avoid naming conflicts.
C
      INTEGER CONTACT
      INTEGER NBOND_ENERGY
      INTEGER DONOR_HBOND_ENERGY
      INTEGER ACCEPTOR_HBOND_ENERGY
      PARAMETER ( CONTACT = 1 )
      PARAMETER ( NBOND_ENERGY = 2 )
      PARAMETER ( DONOR_HBOND_ENERGY = 3 )
      PARAMETER ( ACCEPTOR_HBOND_ENERGY = 4 )
C
      INTEGER GRID_SPACE_GRID
      INTEGER NGRIDX,NGRIDY,NGRIDZ
      REAL XMN,YMN,ZMN,XMX,YMX,ZMX
      REAL SPGRIDSZ,RECIPGRID
      INTEGER EXCLUDED
      INTEGER CNTNBX
      INTEGER INGRID
      INTEGER MAXNBX
      INTEGER NBXA
      INTEGER FREEHD,FREECLS
      INTEGER NEXTHD,CLSHD,CLSTL,NEXTCLS,CLSATM
      INTEGER DONP,ACCP
      INTEGER RESBYA
      INTEGER QSIDE
      INTEGER RADIUS
      REAL MAXRADIUS
      COMMON /GRID/ GRID_SPACE_GRID,NGRIDX,NGRIDY,NGRIDZ,
     2              XMN,YMN,ZMN,XMX,YMX,ZMX,SPGRIDSZ,RECIPGRID,
     3              EXCLUDED,CNTNBX,INGRID,MAXNBX,
     4              NBXA,FREEHD,FREECLS,NEXTHD,CLSHD,
     5              CLSTL,NEXTCLS,CLSATM,DONP,
     6              ACCP,RESBYA,QSIDE,RADIUS,
     7              MAXRADIUS
