#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Specifies a group.
   Syntax: GROUP name first-atom-iupac last-atom-iupac

   04.08.92 Some rewriting.   By:   ACRM.
*/
 
void RTFGroup(
int  *p_SawTable,
int  TableSize,
char TableKey[MXTABL][4],
int  *TableReplace
)
{
   int NumGroups,
       AtomIdx, 
       ok;

   if(restop.nreses == 0)
   {
      fprintf(out,"Error==> A residue must be specified before a \
group in the residue topology.\n");
      ResTop_errcnt++;
   }
   else
   {
      abmpad(ResTop_strparam[0],4);
      NumGroups = restop.nparam[restop.nreses-1][9] + 1;
      strncpy(restop.grpnam[restop.nreses-1][NumGroups-1],ResTop_strparam[0],4);

      if(!strncpy(restop.grpnam[restop.nreses-1][NumGroups-1],BLANK,4))
      {
         fprintf(out,"Error==> Group name not specified in residue topology.\n");
         ResTop_errcnt++;
      }
      else
      {
         AtomIdx = LookupName(ResTop_strparam[0],&ok,TableSize,TableKey,
                              TableReplace,p_SawTable);
         if(ok)
         {
            restop.lstgrp[restop.nreses-1][NumGroups-1] = AtomIdx;

            if(restop.fstgrp[restop.nreses-1][NumGroups-1] > 
               restop.lstgrp[restop.nreses-1][NumGroups-1])
            {
               fprintf(out,"Error==> First atom in group follows \
last in residue topology. Group ignored.\n");
               ResTop_errcnt++;
            }
            else
            {
               restop.nparam[restop.nreses-1][9] = NumGroups;
            }
         }
      }
   }
}
 
