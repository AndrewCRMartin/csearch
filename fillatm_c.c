#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/* Constructs the atom data structure for a backbone C. */
 
void fillatm_c(
struct atom **atp,
int resno,
logical forward
)
{
   int ires,firstat,lastat,fm1,lm1,fp1,lp1,*antep,iseg,segfirst,seglast;
 
   ires = resno - 1;
   *atp = (struct atom *) alloc(sizeof(struct atom));
   (*atp)->atomno = 0;
   clear_atom(*atp);
   fm1 = pstruct.lstatm[ires-1]+1;
   lm1 = pstruct.lstatm[ires];
   firstat = lm1 + 1;
   lastat = pstruct.lstatm[ires+1];
   fp1 = lastat + 1;
   lp1 = pstruct.lstatm[ires+2];
   iseg = getseg(&resno,pstruct.segndx,&values.nsegs);
   segfirst = pstruct.segndx[iseg-1][0] + 1;
   seglast = pstruct.segndx[iseg][0];
 
   (*atp)->atomno = srwdbd(pstruct.atmnme,&firstat,&lastat,
                           resno == segfirst ? "HT2 " : "C   ");
   if ((*atp)->atomno == 0)
   {
      free(*atp);
      *atp = null;
   }
   else
   {
      antep = &(*atp)->ante[0];
      if (forward)
      {
         if (!(*antep = srwdbd(pstruct.atmnme,&fm1,&lm1,"C   ")) &&
                resno == segfirst+1)
            *antep = srwdbd(pstruct.atmnme,&fm1,&lm1,"HT2 ");
         *++antep = srwdbd(pstruct.atmnme,&firstat,&lastat,
                           resno==segfirst+1 ? "NT  " : "N   ");
         *++antep = srwdbd(pstruct.atmnme,&firstat,&lastat,"CA   ");
      }
      else
      {
         *antep = srwdbd(pstruct.atmnme,&fp1,&lp1,"C   ");
         *++antep = srwdbd(pstruct.atmnme,&fp1,&lp1,"CA  ");
         *++antep = srwdbd(pstruct.atmnme,&fp1,&lp1,
                           resno==segfirst ? "NT  " : "N   ");
      }
      fillbndang(*atp);
   }
}
 
