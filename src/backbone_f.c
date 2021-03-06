#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   Constructs a backbone degree of freedom
*/
void backbone_f (
struct dof *dofp,
struct backbone_d *desc
)
{
   int nres;
   logical ok,prohere;
   struct pepmap *map,*p;
 
   if(dbg.cgen)
      fprintf(out,"Entering backbone_f  Residue is %.4s\n",
                 pstruct.resnme[desc->resno-1]);
   prohere = strncmp(pstruct.resnme[desc->resno-1],"PRO ",4) == 0;
   if(desc->nter || desc->cter)
   {
      nres = desc->ntermap;
      map = desc->termap;
   }
   else if (strncmp(pstruct.resnme[desc->resno-1],"GLY ",4) == 0)
   {
      nres = cg.nglymap;
      map = cg.glymap;
      }
   else if (strncmp(pstruct.resnme[desc->resno-1],"PRO ",4) == 0)
   {
      prohere = true;
      nres = cg.npromap;
      map = cg.promap;
   }
   else
   {
      nres = cg.naamap;
      map = cg.aamap;
   }
 
   if (dofp->restart_iter > 1)
   {
      dofp->iter = dofp->restart_iter;
      map += dofp->restart_iter - 1;
      dofp->restart_iter = 0;
   }
   else
      dofp->iter = 1;
 
   for (p=map; dofp->iter<=nres; dofp->iter++,p++)
   {
      if(dbg.cgen) fprintf(out,"Backbone_f: Iteration %d\n",dofp->iter);
      ok = true;
      if(!desc->cistrans && p->cisonly) ok = false;
      if(prohere &&
         (p->phi < cg.proconsphi[0] || p->phi > cg.proconsphi[cg.nprocons-1]))
      ok = false;
      if (!ok) if (dbg.cgen) fprintf(out,"Backbone_f: Bad torsions\n");
      if (ok)
      {
         desc->omega = p->omega;
         desc->phi = p->phi;
         desc->psi = p->psi;
         if (desc->forward)
         {
            if (desc->nter)
            {
               constatm(desc->at_h,-rad120);
               constatm(desc->at_ca,rad120);
            }
            else
            {
               constatm(desc->at_ca,p->omega);
               constatm(desc->at_h, p->omega-pi);
            }
            constatm(desc->at_c,p->phi);
            if (strncmp(pstruct.resnme[desc->resno-1],"PRO ",4) == 0)
               mkprolrng(coords.xcart,coords.ycart,coords.zcart,
                                 &desc->at_cb->ante[0],&desc->at_cb->ante[1],
                                 &desc->at_cb->ante[2],&desc->at_cb->atomno,
                                 &desc->at_cg->atomno,&desc->at_cd->atomno,
                                 &p->phi,cg.procons,cg.proconsphi,&cg.nprocons);
            else
              constatm(desc->at_cb,p->phi-rad120);
 
            constatm(desc->at_n,p->psi);
            constatm(desc->at_o,p->psi-pi);
         }
         else /* Backwards */
         {
            constatm(desc->at_n,p->psi);
            constatm(desc->at_c,p->phi);
            if (strncmp(pstruct.resnme[desc->resno-1],"PRO ",4) == 0)
               mkprolrng(coords.xcart,coords.ycart,coords.zcart,
                                 &desc->at_cb->ante[0],&desc->at_cb->ante[1],
                                 &desc->at_cb->ante[2],&desc->at_cb->atomno,
                                 &desc->at_cg->atomno,&desc->at_cd->atomno,
                                 &p->phi,cg.procons,cg.proconsphi,&cg.nprocons);
            else
               constatm(desc->at_cb,p->phi-rad120);
 
            if (desc->nter)
            {
               constatm(desc->at_ht1,p->phi-rad120);
               constatm(desc->at_h,p->phi+rad120);
            }
            else
            {
               constatm(desc->at_h,p->phi-pi);
               constatm(desc->at_ca,p->omega);
               constatm(desc->at_o,p->omega-pi);
            }
         }  /* End of if(forward) else (backward) */
 
         /* ACRM added cast */
         if (chkclsdst((struct backbone_d *)desc))
            if (chkcntcts(dofp->atoms,&desc->maxevdw,dummy_sidehits))
            {
               dispatch(dofp->next);
               delatmsfgrd(dofp->atoms);
            }
      }
   }
}
 
