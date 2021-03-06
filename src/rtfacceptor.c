#include "ProtoTypes.h"
#include "CongenProto.h"
 
 
/* Specifies an HBond acceptor. One or 2 antecedants may be specified.
   If so, the atoms must be placed in double inverted commas.
 
                    { iupac               }
   Syntax: ACCEPTOR { "iupac iupac"       }
                    { "iupac iupac iupac" }

   04.08.92 Some rewriting.   By:   ACRM.
*/
 
void RTFAcceptor(
int  *p_SawTable,
int  TableSize,
char TableKey[MXTABL][4],
int  *TableReplace
)
{
   int  NumAccept,
        Atom1,
        Atom2,
        Atom3,
        ok;
   char *buffer;
   char iupac1[8],
        iupac2[8],
        iupac3[8];
 
   if(restop.nreses == 0)
   {
      fprintf(out,"Error==> A residue must be specified in the residue \
topology before acceptors.\n");
      ResTop_errcnt++;
   }
   else
   {
      NumAccept   = restop.nparam[restop.nreses-1][7];
      buffer      = ResTop_strparam[0];
      buffer     += GetString(buffer,iupac1);
      buffer      = killspcs(buffer);
      buffer     += GetString(buffer,iupac2);
      buffer      = killspcs(buffer);
      buffer     += GetString(buffer,iupac3);
 
      abmpad(iupac1,4);
      abmpad(iupac2,4);
      abmpad(iupac3,4);
 
      Atom1 = LookupName(iupac1,&ok,TableSize,TableKey,
                         TableReplace,p_SawTable);
      if(ok)
      {
         Atom2 = LookupName(iupac2,&ok,TableSize,TableKey,
                            TableReplace,p_SawTable);
         if(ok)
         {
            Atom3 = LookupName(iupac3,&ok,TableSize,TableKey,
                               TableReplace,p_SawTable);
            if(ok)
            {
               NumAccept++;
               restop.acpthb[restop.nreses-1][NumAccept-1] = Atom1;
               restop.aan1hb[restop.nreses-1][NumAccept-1] = Atom2;
               restop.aan2hb[restop.nreses-1][NumAccept-1] = Atom3;
               restop.nparam[restop.nreses-1][7]           = NumAccept;
            }
         }
      }
   }
}
 
