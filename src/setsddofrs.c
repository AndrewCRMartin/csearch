#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/* Add the residue numbers between startres and lastres to the listed
   pointed to by res and currently pointed to presp. */
 
void setsddofrs(
int startres,
int lastres,
int *res,
float def_sgrid,
float def_maxevdw,
logical def_vavoid,
logical def_clump_symmetry,
int **presp,
float **psgridp,
float **pmaxevdwp,
logical **pvavoidp,
logical **pclump_symmetryp
)
{
   int *pres;
   int dir,i;
   float *psgrid;
   float *pmaxevdw;
   logical *pvavoid;
   logical *pclump_symmetry;
 
   pres = *presp;
   psgrid = *psgridp;
   pmaxevdw = *pmaxevdwp;
   pvavoid = *pvavoidp;
   pclump_symmetry = *pclump_symmetryp;
   dir = sign(lastres-startres);
   if (dir == 0) dir = 1;
   for (i=startres; dir > 0 ? i<=lastres : i>=lastres; i += dir)
   {
      if (i < 1 || i > values.nres)
      {
         fprintf(out,"Warning from SET_SIDEDOF_RES -- \n");
         fprintf(out,"Residues improperly specified for sidechain degree of \
freedom.\n");
         break;
      }
      *pres++ = i;
      *pres = 0;
      *psgrid++ = def_sgrid;
      *pmaxevdw++ = def_maxevdw;
      *pvavoid++ = def_vavoid;
      *pclump_symmetry++ = def_clump_symmetry;
      if (pres - res > values.nres)
      {
         prdie("Error in SET_SIDEDOF_RES -- Sidechain residue array \
exceeded.\n");
      }
   }
   *presp = pres;
   *psgridp = psgrid;
   *pmaxevdwp = pmaxevdw;
   *pvavoidp = pvavoid;
   *pclump_symmetryp = pclump_symmetry;
}
 
