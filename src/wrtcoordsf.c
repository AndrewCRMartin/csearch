#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   Write out the coordinates for all atoms constructed thus far. A
*   title line is generated for each degree of freedom except status
*   (set process name). We use a separate title string to build each
*   line because the backbone degree of freedom title can overrun the 80
*   character limit.
*/
 
void wrtcoordsf(
struct dof *dofp,
struct write_coordinates_d *desc
)
{
   char *title;
   int ntitle,i,l;
   struct dof *p;
   float tote = 0.0;
   char title1[200];
 
   if (dbg.cgen) 
      fprintf(out,"Write_coordinates_f: conformation %d\n",confnum+1);

   ntitle=1;
   for (p=dof_head; p!=dofp; p = p->next)
      if (p->dof_type != status_t) ntitle++;
   title = alloc(80*ntitle);
   for (p=dof_head, i=80; p != dofp; p=p->next)
   {
      switch (p->dof_type)
      {
      case backbone_t:
         {
            struct backbone_d *dp;
            dp = (struct backbone_d *)p->desc; /* ACRM added cast */
            sprintf(title1,
                    "Backbone %.4s %.4s Iter = %d Omega = %g Phi = %g Psi = %g",
                    pstruct.resnme[dp->resno-1],pstruct.resid[dp->resno-1],
                    p->iter,dp->omega,dp->phi,dp->psi);
         }
         break;
      case chain_closure_t:
         {
            struct chain_closure_d *dp;
            dp = (struct chain_closure_d *)p->desc; /* ACRM added cast */
            sprintf(title1,"Chain Closure iteration %d",p->iter);
         }
         break;
      case sidechain_t:
         {
            struct sidechain_d *dp;
            dp = (struct sidechain_d *)p->desc; /* ACRM added cast */
            tote = dp->energy;
            sprintf(title1,"Sidechain placement");
         }
         break;
      case write_coordinates_t:
         sprintf(title1,"Write coordinates");
         break;
      case status_t:
         break;
      case rbest_t:
         {
            struct rbest_d *dp;
            dp = (struct rbest_d *)p->desc; /* ACRM added cast */
            sprintf(title1,"Read Best Conformation #%d  E = %g",
                    p->iter,dp->energy);
         }
         break;
#ifdef EVALUATE
      case evaluate_t:
         {
            struct evaluate_d *dp;
            dp = p->desc;
            sprintf(title1,"Evaluate Conformation  %s is %g",
                    dp->eval_code == eval_code_energy ?
                    "Energy"
                    : dp->eval_code == eval_code_rms ? "RMS"
                    : dp->eval_code == eval_code_user ? "USER"
                    : "Unknown (ERROR)",dp->evaluation);
            tote = dp->evaluation;
         }
         break;
#endif /* EVALUATE */
      default:
         fprintf(out,"\nError in wrtcoordsf() -- Bad dof_type = %d\n",
                    p->dof_type);
         die();
      }
 
      if (p->dof_type != status_t)
      {
         l = strlen(title1);
         if (l>80) l = 80;
         filspc(title1,&eighty,&l);
         strncpy(title+i,title1,80);
         i += 80;
      }
   }
   sprintf(title,"Energy = %g\n",tote);
   l = strlen(title);
   if (l>80) l = 80;
   filspc(title,&eighty,&l);
/*
//   cgwrtnxt(&desc->cunit,desc->consp,&desc->nconsp,title,&ntitle,&tote);
*/
   /* C version */
   cgwrtnxt(desc->consp,desc->nconsp,tote);
 
   free(title);
   if (++confnum >= desc->maxconf)
   {
      fprintf(out,"\nMaxconf has been exceeded.\n");
      dststop();
   }
   dispatch(dofp->next);
}
 
