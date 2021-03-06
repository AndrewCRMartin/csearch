#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Computes the bounds for the sidechain torsion angle sampling. */
 
void setsdbound(
struct sideres *srp,
struct clump *clp,
float *lbound,
float *hbound,
float *grid
)
{
   struct atom *freeatp;
   float t;
   int combined_symmetry;
   char buf[21];
 
   freeatp = clp->free_atom;
   *lbound = freeatp->torsion;
   if (srp->sgrid == -1.0)
   {
      *grid = freeatp->torsion_period;
      combined_symmetry = gcd((int)(2*pi/(*grid)+0.5),clp->symmetry);
      *hbound = *lbound + 2*pi/combined_symmetry;
   }
   else
   {
      *grid = srp->sgrid;
      *hbound = *lbound + 2*pi/clp->symmetry;
   }
   t = (*hbound - *lbound) / *grid;
   if (dbg.cgen)
   {
      buf[0] = '\0';
      print_atom1(buf,freeatp->atomno);
      fprintf(out,"setsdbound: atom = %s \n  LB = %g  HB = %g \
Grid = %g Count = %g\n", buf, *lbound/dtorad, *hbound/dtorad, *grid/dtorad, t);
   }
   if(fabs(t-(int)(t+0.5)) < eps1)
      *hbound -= *grid/2.0;
   else
   {
      fprintf(out,"\nWarning from setsdbound -- Sidechain grid does \
not divide bounds evenly\n");
      fprintf(out,"LB = %g  HB = %g Grid = %g Count = %g\n",
             *lbound/dtorad,*hbound/dtorad,*grid/dtorad,t);
   }
}
 
