#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   Checks if the distance between the last atom constructed by this
*   degree of freedom to the closing atom is less than or equal to the
*   closing distance.
*/
 
logical chkclsdst(
struct backbone_d *desc
)
{
   int starting_atom;
   float dx,dy,dz,r2max,r2;
   logical ok;
 
   if (desc->closing_atom == 0)
      return true;
   else
   {
      starting_atom = desc->forward ?
                      desc->at_n->atomno :
                      desc->at_ca->atomno;
      r2max = desc->closing_distance * desc->closing_distance;
      dx = coords.xcart[starting_atom-1] - coords.xcart[desc->closing_atom-1];
      dy = coords.ycart[starting_atom-1] - coords.ycart[desc->closing_atom-1];
      dz = coords.zcart[starting_atom-1] - coords.zcart[desc->closing_atom-1];
      r2 = dx*dx + dy*dy + dz*dz;
      ok = r2 <= r2max;
      if (dbg.cgen > 0 && !ok)
         fprintf(out,"Closing distance too large. R2 = %g and R2MAX = %g.\n",
                    r2,r2max);
      return ok;
   }
}
 
