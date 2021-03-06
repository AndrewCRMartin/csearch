#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Fills in builder information for a set of 4 atoms.
   Syntax: BUILD name name name name bond angle phi angle bond

   04.08.92 Some rewriting.   By:   ACRM.
*/
 
void RTFBuild(
void
)
{
   int NBuild;

   if(restop.nreses == 0)
   {
      fprintf(out,"Error==> A residue must be specified in the residue topology \
before build.\n");
      ResTop_errcnt++;
   }
   else
   {
      abmpad(ResTop_strparam[0],4);
      abmpad(ResTop_strparam[1],4);
      abmpad(ResTop_strparam[2],4);
      abmpad(ResTop_strparam[3],4);
 
      NBuild = ++(restop.nparam[restop.nreses-1][8]);

      strncpy(restop.bldat1[restop.nreses-1][NBuild-1],ResTop_strparam[0],4);
      strncpy(restop.bldat2[restop.nreses-1][NBuild-1],ResTop_strparam[1],4);
      strncpy(restop.bldat3[restop.nreses-1][NBuild-1],ResTop_strparam[2],4);
      strncpy(restop.bldat4[restop.nreses-1][NBuild-1],ResTop_strparam[3],4);

      sscanf(ResTop_strparam[4],"%f",&restop.b2bld[restop.nreses-1][NBuild-1]);
      sscanf(ResTop_strparam[5],"%f",&restop.a2bld[restop.nreses-1][NBuild-1]);
      sscanf(ResTop_strparam[6],"%f",&restop.torbld[restop.nreses-1][NBuild-1]);
      sscanf(ResTop_strparam[7],"%f",&restop.a1bld[restop.nreses-1][NBuild-1]);
      sscanf(ResTop_strparam[8],"%f",&restop.b1bld[restop.nreses-1][NBuild-1]);
   }
}
 
