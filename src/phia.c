#ifdef __FORT_UNDERSCORE__
#define phia phia_
#endif

#include "ProtoTypes.h"
#include "CongenProto.h"

#ifndef PI
#define PI ((double)4.0*atan((double)1.0))
#endif

/* OMUPD rkw 02/10/92 added RADTODEG to convert radians to degrees */

#define RADTODEG ((double)180.0 / PI)


/* Calculates dihedral angles from the atom numbers in iarray,
   jarry, karray and larray, returning the values in parray.

   02.08.92 Rewritten   Author:  ACRM
*/
 
void phia(short   *iarray,
          short   *jarray,
          short   *karray,
          short   *larray,
          single  *parray,
          int     *ndih,
          single  *x,
          single  *y,
          single  *z
)
{
   single dummy = 9999.0; /* Null coordinate */
   int    i, j, k, l,    /* Abbreviate index into coordinate arrays */
          iphi;          /* Torsion angle counter */
 
   if(*ndih==0) return;
 
   for(iphi = 0; iphi < *ndih; iphi++)
   {
      i = iarray[iphi] - 1;
      j = jarray[iphi] - 1;
      k = karray[iphi] - 1;
      l = larray[iphi] - 1;
 
      if(i<0 || l<0 || k<0 || l<0)
      {
         parray[iphi] = 0.0;
      }
      else
      {
         if(x[i]==dummy || x[j]==dummy || x[k]==dummy || x[l]==dummy)
         {
            parray[iphi] = 0.0;
         }
         else
         {
            if((fabs((double)atomangle(x[i],y[i],z[i],x[j],y[j],z[j],
                                       x[k],y[k],z[k])) <= 0.1) ||
               (fabs((double)atomangle(x[j],y[j],z[j],x[k],y[k],z[k],
                                       x[l],y[l],z[l])) <= 0.1))
            {
               fprintf(out," ** WARNING ** IC Dihedral %5d almost linear.\n\
Atoms: %d %d %d %d\n",iphi+1,i+1,j+1,k+1,l+1);

            }

            /* Calculate the torsion angle */

/* OMUPD rkw 01/10/92 torsion angle must be in degrees */

            parray[iphi] = (float)RADTODEG * phi(x[i],y[i],z[i],x[j],y[j],z[j],
                            x[k],y[k],z[k],x[l],y[l],z[l]);

         }
      }
   }
}
 
