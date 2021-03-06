#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
#define MAXBUFF 200
 
extern int info_level;

/* This does processing of the non-bonded list, setting A and B parameters
   for each atom pair.
   
   02.08.92 Some rewriting.   By:   ACRM.
*/
 
void procnbnds(FILE  *fp,
               short IndxTab[100][100],
               int   *NumNBonds)
{
   char  buff1[MAXBUFF+1],
         buff2[MAXBUFF+1],
         *buffp,
         AtomName[8],
         tempstr1[8],
         tempstr2[8];
   float a, b, r6,
         vdw, numerator,
         Alpha[500],
         EffNElec[500],
         VDWRadius[500],
         denominator,
         emin;
   int   i, j, nat,
         nbc[100],
         idx[500];
 
   if(info_level) fprintf(out,"\n                   NON-BONDED PARAMETERS\n\
                   =====================\n\n\
       #   ATOM  CODE  POLARIZABILITY   N (EFF)   RADIUS\n\n");
 
   i = 0;
 
   while(fgets(buff1,MAXBUFF,fp) && i<=values.natyps)
   {
      terminate(buff1);
      struppr(buff1,buff2);
      buffp = killspcs(buff2);
      if(!strncmp(buffp,"END",3)) break;
 
      sscanf(buffp,"%s %f %f %f",AtomName,&engpar.atmpol[i],&engpar.atneff[i],
             &engpar.vdwrad[i]);
      ljustpad(AtomName);
      nbc[i] = 0;
      for(j=0;j<values.natyps;j++) if(!strncmp(restop.acodes[j],AtomName,4)) nbc[i] = j+1;
 
      if(nbc[i] == 0)
         fprintf(out,"Warning: Atom for nbond %4s doesn't exist\n",AtomName);
 
      strncpy(tempstr1,restop.acodes[nbc[i]-1],4); tempstr1[4] = '\0';
      if(info_level) fprintf(out,"       %4d   %4s  %4d %10.3f%10.3f%10.3f\n",
                  i+1,tempstr1,nbc[i],engpar.atmpol[i],engpar.atneff[i],
                  engpar.vdwrad[i]);
 
      i++;
   }

   nat = i;
   sorti_perm(nbc,nat,idx);

   for(i=0;i<nat;i++)
   {
      Alpha[i]     = engpar.atmpol[idx[i]];
      EffNElec[i]  = engpar.atneff[idx[i]];
      VDWRadius[i] = engpar.vdwrad[idx[i]];
   }
   
   for(i=0;i<nat;i++)
   {
      engpar.atflag[nbc[i]-1] = i+1;
      engpar.atmpol[i]        = Alpha[i];
      engpar.atneff[i]        = EffNElec[i];
      engpar.vdwrad[i]        = VDWRadius[i];
   }
 
   /* Convert to A and B parameters for each combination */
   *NumNBonds = 0;
   for(i=1; i<=nat; i++)
   {
      for(j=1; j<=i; j++)
      {
         if(*NumNBonds%50 == 0 && info_level)
         {
            fprintf(out,"\n       #    PAIR     CODE         A\
         B     SUM OF RADII   DEPTH OF WELL\n");
         }

         engpar.nbkey[*NumNBonds] = (int)IndxTab[nbc[i-1]-1][nbc[j-1]-1];
         vdw                   = engpar.vdwrad[i-1] + engpar.vdwrad[j-1];
         r6                    = (float)pow((double)vdw,(double)6);
         if(r6 < 0.000001)  r6 = 0.000001;
         numerator             = CONST * engpar.atmpol[i-1] * engpar.atmpol[j-1];

         if(engpar.atneff[i-1] >= 0.5 && engpar.atneff[j-1] >= 0.5 && numerator != 0.0)
         {
            denominator = sqrt((double)(engpar.atmpol[i-1]/engpar.atneff[i-1])) +
                          sqrt((double)(engpar.atmpol[j-1]/engpar.atneff[j-1]));
            b           = numerator/denominator;
            emin        = -0.5*b/r6;
         }
         else if(engpar.atneff[i-1] <= 0.0 && engpar.atneff[j-1] <= 0.0)
         {
            emin        = -sqrt((double)(engpar.atneff[i-1]*engpar.atneff[j-1]));
            b           = -2.0*emin*r6;
         }
         else if(engpar.atneff[i-1] <= 0.0 && engpar.atneff[j-1] >= 0.5)
         {
            numerator   = 0.25 * CONST * engpar.atmpol[j-1] *
                          sqrt((double)(engpar.atmpol[j-1] * engpar.atneff[j-1]))/r6;
            emin        = -sqrt((double)(-engpar.atneff[i-1]*numerator));
            b           = -2.0*emin*r6;
         }
         else if(engpar.atneff[j-1] <= 0.0 && engpar.atneff[i-1] >= 0.5)
         {
            numerator   = 0.25 * CONST * engpar.atmpol[i-1] *
                          sqrt((double)(engpar.atmpol[i-1] * engpar.atneff[i-1]))/r6;
            emin        = -sqrt((double)(-engpar.atneff[j-1]*numerator));
            b           = -2.0*emin*r6;
         }
         else
         {
            b           = 0.0;
            emin        = 0.0;
         }

         a = 0.5*b*r6;
         engpar.vdwr6[*NumNBonds] = b;
         engpar.vdwr12[*NumNBonds] = a;
 
         strncpy(tempstr1,restop.acodes[nbc[i-1]-1],4); tempstr1[4] = '\0';
         strncpy(tempstr2,restop.acodes[nbc[j-1]-1],4); tempstr2[4] = '\0';
 
 
         if(info_level) fprintf(out,"     %4d %4s ---%4s %4d %10.2f%10.2f%10.3f \
%10.4f\n", *NumNBonds+1,tempstr1,tempstr2,engpar.nbkey[*NumNBonds],a,b,vdw,emin);

         (*NumNBonds)++;
      }
   }
}
 
