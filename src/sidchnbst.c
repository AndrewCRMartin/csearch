#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   Finds the "best" conformation for sidechain described by srp, where
*   best is defined by the evaluation function pointed to by
*   desc->eval_func. This routine will maintain the list of "maxconf"
*   best conformations.
*
*   The never_fail flag serves an important purpose when sidchnbst
*   is used with the sidchnitr procedure. There, the iterative
*   process, if done with infinite precision, guarantees that there will
*   always be a place to locate a sidechain under construction. However,
*   because of numerical error and the tight fits that the van der Waals
*   avoidance code can find, the program may not find the previous
*   sidechain conformation. Thus, when never_fail is on, it forces
*   sidchnbst to ignore the local environment when constructing the
*   sidechain using the torsion angles that were successful in the
*   previous iteration. N.B., the code to implement never_fail only
*   works when sidchnitr is the calling procedure, and in
*   particular, when the last torsion angles are stored in
*   clp->best_phi[1].
*/
 
void sidchnbst(
struct sidechain_d *desc,
int maxconf,
struct sideres *srp,
struct clump **clpp,
logical never_fail
)
{
   struct clump *clp;
   float e,maxe,closest_phi;
   float *phip,*philist;
   int imaxe,i,nphi;
   char buf[21];
   struct atom *freeatp;
   char resid[4],resname[4];
 
   if ((clp = *clpp) == null)
   {
      if (dbg.cgen)
      {
         strncpy(resid,pstruct.resid[srp->resno-1],4);
         strncpy(resname,pstruct.resnme[srp->resno-1],4);
      }
      e = (*desc->eval_func) (srp);
      if (srp->nconf < maxconf)
      {
         srp->beste[srp->nconf] = e;
         cpintobst(srp,srp->nconf);
         walk_clumps(srp,clp->best_phi[srp->nconf] = clp->cur_phi; );
         if (dbg.cgen)
         {
            fprintf(out,"Sidechain_best: Residue: %.4s %.4s beste[%d] \
being replaced\n",resname,resid,srp->nconf);
         }
         srp->nconf++;
      }
      else
      {
         maxe = -largnum;
         for (i=0; i<maxconf; i++)
         {
            if (srp->beste[i] >= maxe)
            {
               maxe = srp->beste[i];
               imaxe = i;
            }
         }
         if (e >= maxe)
            ;      /* Wasn't good enough --- do nothing */
         else
         {
            if (dbg.cgen)
            {
               fprintf(out,"Sidechain_best: Residue: %.4s %.4s beste[%d] \
being replaced\n",resname,resid,imaxe);
            }
            srp->beste[imaxe] = e;
            cpintobst(srp,imaxe);
            walk_clumps(srp, clp->best_phi[imaxe] = clp->cur_phi; );
         }
      }
   }
   else
   {
      if (dbg.cgen)
      {
         freeatp = clp->free_atom;
         buf[0] = '\0';
         print_atom1(buf,freeatp->atomno);
      }
      setsidphis(srp,clp,&philist,&nphi,srp->sidehits);
      closest_phi = largnum * dtorad;
      if (never_fail)
      {
         for (i=1, phip=philist; i<=nphi; i++,phip++)
         {
            if (fabs(*phip - clp->best_phi[1]) <
                fabs(closest_phi - clp->best_phi[1]))
            {
               closest_phi = *phip;
            }
         }
      }
      if (nphi == 0 && never_fail)
      {
         if (dbg.cgen)
         {
            fprintf(out,"Sidechain_best: No acceptable torsion angles found.\n");
            fprintf(out,"                Using torsion angles from previous \
iteration.\n");
         }
         free(philist);
         philist = (float *) alloc(sizeof(float));
         closest_phi = *philist = clp->best_phi[1];
         nphi = 1;
      }
      if (never_fail && fabs(closest_phi-clp->best_phi[1]) > 1.0E-04)
      {
         if (dbg.cgen)
         {
            fprintf(out,"Warning from sidchnbst:\n");
            fprintf(out,"  closest_phi = %g and best_phi[1] = %g do not \
agree.\n",closest_phi/dtorad,clp->best_phi[1]/dtorad);
         }
         *(philist+nphi++) = closest_phi = clp->best_phi[1];
      }
      for (i=1, phip=philist; i<=nphi; i++,phip++)
      {
         if (dbg.cgen)
            fprintf(out,"Sidechain_best: Atom: %s phi = %g  i = %d\n",
                   buf,*phip/dtorad,i);
         constclmp(clp,*phip);
         if (srp->vavoid || (never_fail && closest_phi == *phip))
         {
            adatmstgrd(clp->atoms);
            /* ACRM added () round logical */
            sidchnbst(desc,maxconf,srp,clpp+1,(closest_phi == *phip));
            delatmsfgrd(clp->atoms);
         }
         else if (chkcntcts(clp->atoms,&srp->maxevdw,srp->sidehits))
         {
            sidchnbst(desc,maxconf,srp,clpp+1,false);
            delatmsfgrd(clp->atoms);
         }
      }
      free(philist);
   }
}
 
