#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Finish off the previous residue */
 
void finres(
float totchg,
int nbxn[],
char nbxnam[mxnber][4],
int ntabl,
char tblkey[MXTABL][4],
int *p_sawtbl,
int tblrep[MXTABL]
)
{
   char name[8];
   int nat, iat, nx, start, stop, inx, ind, ok;
   float sum;

   if(restop.nreses != 0)
   {
      nat = restop.nparam[restop.nreses-1][0];
      sum = 0.0;
      for(iat=0;iat<nat;iat++) sum+=restop.atmchg[restop.nreses-1][iat];
      if(fabs(sum-totchg) > 1.0e-6)
      {
         fprintf(out,"ReadRTF(): Warning==> Total charge of the %4s \
%11.7f doesn't equal the expected charge, %11.7f\n","XXXX",sum,totchg);
         ResTop_wrncnt++;
      }
 
      /* Convert non-bonded exclusion lists stored temporarily as atom
         names in nbxnam into numbers
      */
      nx = 0;
      for(iat = 0; iat<nat; iat++)
      {
         if(iat == 0)
            start = 0;
         else
            start = nbxn[iat-1];
 
         stop = nbxn[iat];
         for(inx = start; inx<stop; inx++)
         {
            strncpy(name,nbxnam[inx],4);
            if(!strncmp(name,BLANK,4))
            {
               ind = -99;
               ok=TRUE;
            }
            else
            {
               ind = LookupName(name,&ok,ntabl,tblkey,tblrep,p_sawtbl);
            }
            if(ok) restop.exclnb[restop.nreses-1][nx++] = ind;
         }
         restop.nexcld[restop.nreses-1][iat] = nx;
      }
      for(iat = nat;iat>=2;iat--)
         restop.nexcld[restop.nreses-1][iat-1] -=
                       restop.nexcld[restop.nreses-1][iat-2];
      restop.nparam[restop.nreses-1][5] = nx;
      CheckRTF();
   }
}
 
