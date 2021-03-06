#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/* Complete the rest of chain closure descriptor. */
 
void finchncls(
struct dof *dofp,
struct chain_closure_d *dp
)
{
   int i,segfirst,seglast,iseg,ires,ind,fstatm,lstatm;
   struct atom **atpp;
 
   dp->maxdt *= dtorad;
   iseg = getseg(&dp->startres,pstruct.segndx,&values.nsegs);
   segfirst = pstruct.segndx[iseg-1][0] + 1;
   seglast = pstruct.segndx[iseg][0];
   fillatm_n(&dp->first_n,dp->startres,true);
   for (ires=dp->startres-1, i=0; ires<=dp->startres+3; ires++, i++)
   {
      fstatm = pstruct.lstatm[ires-1]+1;
      lstatm = pstruct.lstatm[ires];
      dp->pos_n[i] = srwdbd(pstruct.atmnme,&fstatm,&lstatm,
                            ires==segfirst+1 ? "NT  " : "N   ");
      dp->pos_ca[i] = srwdbd(pstruct.atmnme,&fstatm,&lstatm,"CA  ");
      dp->pos_c[i] = srwdbd(pstruct.atmnme,&fstatm,&lstatm,"C   ");
   }
   for (ind=0, i=0; i<=6; ind++, i += 2)
   {
      dp->atmind[i][0] = dp->pos_ca[ind];
      dp->atmind[i][1] = dp->pos_c[ind];
      dp->atmind[i][2] = dp->pos_n[ind+1];
   }
   for (ind=1, i=1; i <= 5; ind++, i += 2)
   {
      dp->atmind[i][0] = dp->pos_n[ind];
      dp->atmind[i][1] = dp->pos_ca[ind];
      dp->atmind[i][2] = dp->pos_c[ind];
   }
   for (i=0, ires=dp->startres; i <= 2; ires++, i++)
   {
      dp->clscistrans[i] =
         dp->cistrans && strncmp(pstruct.resnme[ires-1],"PRO ",4) == 0;
   }
   dofp->atoms = (struct atom **) alloc(28*sizeof(struct atom *));
   for (ires=dp->startres,i=0; ires<=dp->startres+2; ires++,i++)
       fillbbatms(dofp->atoms,ires,true,false,
                              &dp->at_n[i],&dp->at_h[i],&dp->at_ca[i],
                              &dp->at_cb[i],&dp->at_cg[i],&dp->at_cd[i],
                              &dp->at_c[i],&dp->at_o[i],&dp->at_ht1[i]);
   if (dp->at_ca[2]) free(dp->at_ca[2]);
   if (dp->at_c[2]) free(dp->at_c[2]);
   if (dp->at_o[2]) free(dp->at_o[2]);
   if (dp->at_n[2]) free(dp->at_n[2]);
   dp->at_ca[2] = null;
   dp->at_c[2] = null;
   dp->at_o[2] = null;
   dp->at_n[2] = null;
 
   /* The following code ensures that all the atoms are pointed to
      by a continuous array. */
   atpp = dofp->atoms;
   for (ires=dp->startres,i=0; ires<=dp->startres+2; ires++,i++)
   {
      if (dp->at_n[i]) *atpp++ = dp->at_n[i];
      if (dp->at_h[i]) *atpp++ = dp->at_h[i];
      if (dp->at_ht1[i]) *atpp++ = dp->at_ht1[i];
      if (dp->at_ca[i]) *atpp++ = dp->at_ca[i];
      if (dp->at_cb[i]) *atpp++ = dp->at_cb[i];
      if (dp->at_cg[i]) *atpp++ = dp->at_cg[i];
      if (dp->at_cd[i]) *atpp++ = dp->at_cd[i];
      if (dp->at_c[i]) *atpp++ = dp->at_c[i];
      if (dp->at_o[i]) *atpp++ = dp->at_o[i];
   }
   *atpp = null;
}
 
