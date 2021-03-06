#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Start a new residue, finishes the last residue if necessary
   Syntax: RESIDUE name [total-charge]

   04.08.92 Some rewriting.   By:   ACRM.
*/
 
void RTFResidue(
float *p_TotalCharge,
int   *NumExclusions,
int   *p_SawTable,
int   *NBondExclNum,
char  NBondExclNam[mxnber][4],
int   TableSize,
char  TableKey[MXTABL][4],
int   TableReplace[MXTABL]
)
{
   int i;
   
   if(restop.nreses > 0)
      finres(*p_TotalCharge,NBondExclNum,NBondExclNam,TableSize,TableKey,
             p_SawTable,TableReplace);
 
   abmpad(ResTop_strparam[0],4);
 
   if(!strncmp(ResTop_strparam[0],BLANK,4))
   {
      fprintf(out,"Error==> Residues in residue topology must have names.\n");
      ResTop_errcnt++;
   }
   else
   {
      if(++restop.nreses > maximr)
      {
         fprintf(out,"Error==> Too many residues in residue topology. \
MXRTRS (%d) exceeded.\n",maximr);
         die();
      }
      
      strncpy(restop.namres[restop.nreses-1],ResTop_strparam[0],4);
      abmpad(restop.namres[restop.nreses-1],4);

      /* Check if name exists already */
      for(i=0;i<restop.nreses-1;i++)
      {
         if(!strncmp(restop.namres[i],restop.namres[restop.nreses-1],4))
         {
            fprintf(out,"Error==> Duplicate residue name in residue topology.\n");
            ResTop_errcnt++;
            break;
         }
      }
      
      sscanf(ResTop_strparam[1],"%f",p_TotalCharge);

      for(i=0;i<ninfo;i++) restop.nparam[restop.nreses-1][i] = 0;

      *NumExclusions = 0;
      *p_SawTable    = FALSE;
   }
}
 
