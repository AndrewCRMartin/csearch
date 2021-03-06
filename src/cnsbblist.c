#include "ProtoTypes.h"
#include "CongenProto.h"
#include "values.h"
 
/*
*   Constructs a list of atoms in catom which connect the last atom
*   built by the backbone degree of freedom pointed to by desc to the
*   closing atom in that degree of freedom. The construction goes in the
*   backward direction.
*/
 
void cnsbblist(
struct backbone_d *desc,
int *catom,
int *natomp
)
{
   int nat,clsres,segfirst,iseg,ires;
   logical ok;
 
   ok = true;
   iseg = getseg(&desc->resno,pstruct.segndx,&values.nsegs);
   segfirst = pstruct.segndx[iseg-1][0]+1;
   nat = 0;
   catom[nat++] = desc->at_ca->atomno;
   clsres = getres((short)desc->closing_atom,pstruct.lstatm,values.nres);
   if (clsres >= desc->resno)
   {
      fprintf(out,"Error in cnsbblist -- Closing atom comes after\n");
      fprintf(out,"residue in the backbone degree of freedom for \
residue %.4s %.4s\n", pstruct.resnme[desc->resno-1],pstruct.resid[desc->resno-1]);
      fprintf(out,"The closing atom will be ignored.\n");
      ok = false;
   }
   else
   {
      for (ires=desc->resno-1; ires >= clsres; )
      {
         if (!(catom[nat++] = typeinres(ires,ires+1==segfirst ? "NT  " : "N   "))) break;
         if (catom[nat-1] == desc->closing_atom) break;
         if (!(catom[nat++] = typeinres(--ires,"C   "))) break;
         if (catom[nat-1] == desc->closing_atom) break;
         if (!(catom[nat++] = typeinres(ires,"CA  "))) break;
         if (catom[nat-1] == desc->closing_atom) break;
      }
      if (catom[nat-1] != desc->closing_atom)
      {
         ok = false;
         fprintf(out,"Error in cnsbblist -- \
Closing atom for residue %.4s %.4s was not found.\n",
                pstruct.resnme[desc->resno-1],pstruct.resid[desc->resno-1]);
      }
   }
   if (!ok)
   {
      nat = 0;
      desc->closing_atom = 0;
   }
   *natomp = nat;
}
 
