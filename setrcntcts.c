#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/* Sets up the contact distance which gives a van der Waals energy of
   maxevdw for all atom types with the atom in atp. The contact distance
   is stored in the array, atp->rcontact. */
 
void setrcntcts(
struct atom *atp,
float maxevdw,
short parm_no[100][100]
)
{
   double a,b;
   int i,i1,atpitc;
 
   atp->rcontact = (float *) alloc(sizeof(float)*maxatu);
   atpitc = engpar.atflag[pstruct.atcode[atp->atomno-1]-1];
   for (i=1; i<=values.natyps; i++)
   {
      if (strncmp(restop.acodes[i-1],"    ",4) != 0)
      {
         i1 = engpar.atflag[i-1];
         a = engpar.vdwr12[parm_no[i1-1][atpitc-1]-1];
         b = engpar.vdwr6[parm_no[i1-1][atpitc-1]-1];
         if (b == 0) /* Case where vdw energy not defined. */
            atp->rcontact[i1-1] = engpar.vdwrad[i1-1];
         else if (maxevdw <= 0.0)
            atp->rcontact[i1-1] = pow(a/b,1.0/6.0);
         else atp->rcontact[i1-1] = pow((sqrt(b*b+4.0*a*maxevdw)-b)/
                                        (2.0*maxevdw),1.0/6.0);
      }
   }
}
 
