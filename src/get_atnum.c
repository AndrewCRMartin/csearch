#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/* ACRM: Replaces GETATN(). Given the chain, residue and atom name,
   returns the atom number. Returns -1, if not found (having issued
   an error message).
   
   02.08.92 Some recoding.    By:   ACRM
*/
 
int get_atnum(char ChainName[],
              char ResName[],
              char AtomName[])
{
   int SegNumber,
       ResNumber,
       StopNum,
       AtomNumber;
 
   /* Get the segment number  */
   SegNumber = 1;
   if(values.nsegs == 0)
   {
      fprintf(out,"get_atnum() couldn't find segment %s (Residue: %s, Atom: %s)\n",
             ChainName,ResName,AtomName);
      return(-1);
   }
   while(strncmp(pstruct.segid[SegNumber-1],ChainName,4) && SegNumber <= values.nsegs)
      SegNumber++;
   if(SegNumber > values.nsegs)
   {
      fprintf(out,"get_atnum() couldn't find segment %s (Residue: %s, Atom: %s)\n",
             ChainName,ResName,AtomName);
      return(-1);
   }
 
   /* Now the res number      */
   ResNumber = pstruct.segndx[SegNumber-1][0]+1;
   StopNum   = pstruct.segndx[SegNumber][0];
   if(ResNumber > StopNum)
   {
      fprintf(out,"get_atnum() couldn't find residue %s (Segment: %s, Atom: %s)\n",
             ResName,ChainName,AtomName);
      return(-1);
   }
   while(strncmp(pstruct.resid[ResNumber-1],ResName,4) && ResNumber <= StopNum)
      ResNumber++;
   if(ResNumber > StopNum)
   {
      fprintf(out,"get_atnum() couldn't find residue %s (Segment: %s, Atom: %s)\n",
             ResName,ChainName,AtomName);
      return(-1);
   }
 
   /* Now the atom number     */
   AtomNumber = pstruct.lstatm[ResNumber-1]+1;
   StopNum    = pstruct.lstatm[ResNumber];
   if(AtomNumber > StopNum)
   {
      fprintf(out,"get_atnum() couldn't find atom %s (Segment: %s, Residue: %s)\n",
             AtomName,ChainName,ResName);
      return(-1);
   }
   while(strncmp(pstruct.atmnme[AtomNumber-1],AtomName,4) &&
                                AtomNumber <= StopNum)
      AtomNumber++;
   if(AtomNumber > StopNum)
   {
      fprintf(out,"get_atnum() couldn't find atom %s (Segment: %s, Residue: %s)\n",
             AtomName,ChainName,ResName);
      return(-1);
   }
 
   return(AtomNumber);
}
 
