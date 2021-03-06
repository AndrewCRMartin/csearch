#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/* ACRM: replaces GET_RES_IN_STRING etc */
 
int get_resnum(
char chain[],
char res[]
)
{
   int iseg,
       firstres,
       numres,
       i;
 
   iseg = 1;
   if(values.nsegs == 0)
   {
      fprintf(out,"get_resnum couldn't find the segment seg=%s, res=%s\n",
             chain,res);
      return(-1);
   }
   while(strncmp(pstruct.segid[iseg-1],chain,4) && iseg <= values.nsegs) iseg++;
   if(iseg > values.nsegs)
   {
      fprintf(out,"get_resnum couldn't find the segment seg=%s, res=%s\n",
             chain,res);
      return(-1);
   }
   /* Find the first residue in this segment */
   firstres = pstruct.segndx[iseg-1][0] + 1;
   /* And the number of residues in the segment */
   numres   = pstruct.segndx[iseg][0]   - firstres + 1;
   /* For each resdiue in the segment, see if the identifier matches */
   for(i=0; i < numres; i++)
   {
      if(!strncmp(res,pstruct.resid[firstres+i-1],4)) break;
   }
   if(i>=numres)
   {
      fprintf(out,"Warning from get_resnum(), unable to find identifier %s\n",
             res);
      return(0);
   }
   else
   {
      return(i + firstres);
   }
   return(0);
}
 
