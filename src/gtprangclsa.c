#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   Determines the angle between atoms it, jt, and kt by looking them up
*   in the parameter list. If stretch_all is true, then cmaxdt[0] is
*   added to the angle. Otherwise, the angle array cangle is searched,
*   and if found, the corresponding entry from cmaxdt is added.
*/
 
float gtprangclsa(
int it,
int jt,
int kt,
logical stretch_all,
int **cangle,
float cmaxdt[],
int nangle
)
{
   float ret;
   int t,i;
   logical found;
 
   if (stretch_all)
   {
      ret = gtprangl2(it,jt,kt) + cmaxdt[0];
   }
   else
   {
      if (it > kt)
      {
         swap(it,kt,t);
      }
      found = false;
      for (i = 0;  i < nangle;  i++)
      {
         if (it == cangle[i][0] && jt == cangle[i][1] && kt == cangle[i][2])
         {
            found = true;
            break;
         }
      }
      if (!found)
      {
         ret = gtprangl2(it,jt,kt);
      }
      else
      {
         ret = gtprangl2(it,jt,kt) + cmaxdt[i];
      }
   }
   return ret;
}
 
