#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Looks up the index for an atom name */
 
int LookupName(
char name[],
int  *ok,
int  ntabl,
char tblkey[MXTABL][4],
int  tblrep[MXTABL],
int  *sawtbl
)
{
   int ind, i;
   char temp[8];
   ind = 0;
 
   /* If it's a null string, make it a string of blanks instead */
   if(!name[0]) strncpy(name,BLANK,4);
 
   for(i=0;i<restop.nparam[restop.nreses-1][0];i++)
   {
      if(!strncmp(restop.namatm[restop.nreses-1][i],name,4))
      {
         ind = i+1;
         break;
      }
   }
   if(ind)
   {
      *ok = TRUE;
   }
   else
   {
      for(i=0;i<ntabl;i++)
      {
         if(!strncmp(tblkey[i],name,4))
         {
            ind = i+1;
            break;
         }
      }
      if(!ind)
      {
         strncpy(temp,name,4);
         temp[4] = '\0';
         fprintf(out,"ReadRTF(): Error==> Atom %4s not found in ATOM or \
DECLARE table. Ignored.\n",temp);
         ResTop_errcnt++;
         *ok = FALSE;
      }
      else
      {
         *ok = TRUE;
         ind = tblrep[ind-1];
         if(ind > 0)
         {
            ind += restop.nparam[restop.nreses-1][0];
            *sawtbl = TRUE;
         }
      }
   }
   return(ind);
}
 
