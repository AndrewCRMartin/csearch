#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
#define MAXBUFF 200
 
extern int info_level;

/* This routine processes HBond commands.
   04.08.92 Some rewriting.   By:   ACRM.
*/

void prochbnd(
FILE *fp,
short IndxTab[100][100]
)
{
   char  buff1[MAXBUFF+1],
         buff2[MAXBUFF+1],
         *buffp,
         Atom1[8],
         Atom2[8],
         temp1[8],
         temp2[8];
   int   i, j, k;
   float EnergyMin, DistMin,
         a, b;
 
   if(info_level) fprintf(out,"\n         HYDROGEN BOND PARAMETERS\n\
         ========================\n\n\
      #    PAIR          CODE  EMIN  RMIN      A          B\n\n");
 
   while(fgets(buff1,MAXBUFF,fp))
   {
      terminate(buff1);
      struppr(buff1,buff2);
      buffp = killspcs(buff2);
      if(!strncmp(buffp,"END",3)) break;
 
      sscanf(buffp,"%s %s %f %f",Atom1,Atom2,&EnergyMin,&DistMin);
      ljustpad(Atom1);
      ljustpad(Atom2);
      
      i = j = -1;
      for(k=0; k<values.natyps; k++)
      {
         if(!strncmp(restop.acodes[k],Atom1,4)) i = k;
         if(!strncmp(restop.acodes[k],Atom2,4)) j = k;
      }

      if(i == -1 || j == -1)
      {
         printf("Warning: Atoms in HBond %4s %s %10.5f%10.5f don't exist\n",
                Atom1,Atom2,EnergyMin,DistMin);
      }
      else
      {
         engpar.hbkey[values.nhbpar] = (int)IndxTab[i][j];
         b = (EnergyMin/(-(float)pow((double)5,(double)5) /
                          (float)pow((double)6,(double)6))) *
                          pow((double)(DistMin*DistMin/1.2),(double)5);
         a = b * DistMin * DistMin / 1.2;
         engpar.hbr12[values.nhbpar] = a;
         engpar.hbr10[values.nhbpar] = b;
 
         strncpy(temp1,restop.acodes[i],4); temp1[4] = '\0';
         strncpy(temp2,restop.acodes[j],4); temp2[4] = '\0';
         if(info_level)
            fprintf(out,"     %3d  %4s...%4s%7d %6.1f %6.2f %11.1f %11.1f\n",
                    values.nhbpar+1,temp1,temp2,engpar.hbkey[values.nhbpar],
                    EnergyMin,DistMin,a,b);
         values.nhbpar++;
      }
   }
}
 
