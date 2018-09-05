#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/**************************************************************************/
/*
*    Finds all sidechain conformations. srpp is the current index into
*    the sideres pointer array, and clpp is the current index into the
*    clumps pointer array for the particular residue. This function
*    returns success (return value == 1) or failure (return value <= 0)
*    for its generation, and will dispatch to the next degree of freedom.
*
*    Some special hackery is done for efficiency if a sidechain fails to
*    be placed. SEARCH_NEAR_ATOM maintains a list of residues that make
*    bad contacts (sidehits). If a sidechain fails to be placed,
*     sidchnfst will abort the search until one of the residues
*    responsible for the failure is encountered. The negative of residue
*    which failed completely is passed back as the value of this
*    routine.
*/
/**************************************************************************/
 
int  sidchnall(
struct dof *dofp,
struct sidechain_d *desc,
struct sideres **srpp,
struct clump **clpp
)
{
   float *phip,*philist;
   struct sideres *srp,**s2pp,*s2p;
   struct clump *clp;
   int status,i,nphi;
   char buf[21];
   struct atom *freeatp;
 
   if ((srp = *srpp) == null)
   {
      if (dbg.cgen) fprintf(out,"Sidechain_all: Dispatching.\n");
      dispatch(dofp->next);
      return 1;
   }
   else if ((clp = *clpp) == null)
   {
      if (dbg.cgen)
         fprintf(out,"Sidechain_all: Residue: %.4s %.4s *clpp == null\n",
                pstruct.resnme[srp->resno-1],pstruct.resid[srp->resno-1]);
      srp->count++;
      srpp++;
      if (*srpp != null) clpp = (*srpp)->clumps;
      return  sidchnall(dofp,desc,srpp,clpp);
   }
   else
   {
      if (dbg.cgen)
      {
         freeatp = clp->free_atom;
         buf[0] = '\0';
         print_atom1(buf,freeatp->atomno);
      }
      if (clpp == srp->clumps)
      {
         for (s2pp=desc->residues; (s2p = *s2pp); s2pp++)
            srp->sidehits[s2p->resno-1] = 0;
         srp->count = 0;
      }
      setsidphis(srp,clp,&philist,&nphi,srp->sidehits);
      for (i=1, phip=philist; i <= nphi; i++,phip++)
      {
         if (dbg.cgen)
            fprintf(out,"Sidechain_all: Atom: %s phi = %g  i = %d\n",
                   buf,*phip/dtorad,i);
            constclmp(clp,*phip);
            if (srp->vavoid ||
                chkcntcts(clp->atoms,&srp->maxevdw,srp->sidehits))
            {
                if (srp->vavoid) adatmstgrd(clp->atoms);
                /* ACRM added cast */
                status =  sidchnall(dofp,(struct sidechain_d *)desc,
                                       srpp,clpp+1);
                delatmsfgrd(clp->atoms);
                if (status < 0 && cg.sidehits_opt)
                {
                   if (dbg.cgen)
                   {
                      fprintf(out,"Sidechain_all: Backtracking now on atom %s\n",
                             buf);
                   }
                   s2p = desc->residues[-status-1];
                   if (srp->resno != -status)
                   {
                      free(philist);
                      return status;
                   }
                }
             }
         }
         if (dbg.cgen)
         {
            fprintf(out,"Sidechain_all: Loop on atom %s complete\n",buf);
         }
         if (clpp == srp->clumps && srp->count == 0)
         {
            if (dbg.cgen)
            {
               fprintf(out,"Sidechain_all: Residue: %.4s %.4s Search failed\n",
                      pstruct.resnme[srp->resno-1],pstruct.resid[srp->resno-1]);
            }
            if (cg.sidehits_opt)
            {
               status = -(values.nres+1);   /* In case no residue contacts */
               for (s2pp=srpp-1;  s2pp >= desc->residues;  s2pp--)
               {
                  s2p = *s2pp;
                  if (srp->sidehits[s2p->resno-1] != 0)
                  {
                     status = -s2p->resno;
                     if (dbg.cgen)
                     {
                        fprintf(out,"Sidechain_all: Backtracking to \
residue %.4s %.4s\n",pstruct.resnme[s2p->resno-1],pstruct.resid[s2p->resno-1]);
                     }
                     break;
                  }
               }
            }
            else
               status = srp->count > 0;
         }
         else
            status = srp->count > 0;
      free(philist);
      return status;
   }
}
 
