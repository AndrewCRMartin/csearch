#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"

extern int wrnlev;


void generate(
char segname[],
int nbxmod
)
{
   char temp[8];
   int istart, istop;
   int ires,iatom,iphi,imphi,ndons;
 
   if(!segname[0] || segname[0] == ' ') sprintf(segname,"%-d",values.nsegs+1);
   strncpy(pstruct.segid[values.nsegs++],segname,4);
   strncpy(temp,segname,4);
   temp[4] = '\0';
   abmpad(pstruct.segid[values.nsegs-1],4);
 
   istart = pstruct.segndx[values.nsegs-1][0] + 1;
   istop = values.nres;
   genic(istart,istop);
 
   fprintf(out,"\n         Segment %3d has been generated. \
It's identifier is %4s\n",values.nsegs,pstruct.segid[values.nsegs-1]);
 
   /* Remove all internal coordinates which go outside the boundary of the
      segment
   */
   trimic();
 
/*
   if(wrnlev>0)
      fprintf(out,"NATOM:  %d  NBOND: %d  NTHETA: %d  NPHI: %d\n\
NIMPHI: %d  NNB:   %d  NDON:   %d  NACC: %d\n",
values.natoms, values.nbonds, values.nangs, values.nptors, values.nitors,
values.nnbs, values.ndonat, values.naccat);
*/
 
   ires  = pstruct.segndx[values.nsegs-1][0] + 1;
   iatom = pstruct.segndx[values.nsegs-1][1] + 1;
   iphi  = pstruct.segndx[values.nsegs-1][4] + 1;
   imphi = pstruct.segndx[values.nsegs-1][5] + 1;
   ndons = pstruct.segndx[values.nsegs-1][7] + 1;
 
   /* We only handle explicit hydrogen type */
   patexh(ires,iatom,iphi,imphi,ndons);
   updtnictot(nbxmod,1);
 
   /* We have generated a new segment, so update nictot */
   /* Only allow type two (explicit H's) */
   pstruct.segndx[values.nsegs][9] = 2;
 }
 
