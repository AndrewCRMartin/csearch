#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* ACRM 18.06.91 C translation
 
   Searches TYPE in RES for ALPHA_VAR and returns the index in
   INDEX_VAR. ALPHA_VAR can have + or - at the beginning in order
   to refer to adjacent residues.
   WARNING: A kludge is present in order to handle NT in the
   N-terminal residues of segments. It should be deleted someday.
*/
 
void assign_name (
char  type[maxat][4],
short *ibase,
int   *ires,
int   *index_var,
char  alpha_var[]
)
{
   char wd[5];
   int  ir,
        l,
        fstatm,
        lstatm;
 
   ir = *ires;
   if(alpha_var[0] == '+')
   {
      ir = *ires + 1;
      copyst(wd,&four,&l,alpha_var+1,&three);
      padspace(wd,5);
   }
   else if (alpha_var[0] == '-')
   {
      ir = *ires - 1;
      copyst(wd,&four,&l,alpha_var+1,&three);
      padspace(wd,5);
   }
   else
   {
      ir = *ires;
      copyst(wd,&four,&l,alpha_var,&four);
   }
 
   fstatm = ibase[ir-1] + 1;
   lstatm = ibase[ir];
 
   *index_var = srwdbd(type,&fstatm,&lstatm,wd);
   if(*index_var == 0 && !strncmp(wd,"N   ",4))
   {
      *index_var = srwdbd(type,&fstatm,&lstatm,"NT  ");
      if(*index_var > 0)
         fprintf(out,"Warning from ASSIGN_NAME -- NT replaced N \
for an atom name in residue %d\n",ir);
   }
 
   if(*index_var == 0)
   {  int i;
 
      fprintf(out,"Error in ASSIGN_NAME -- Unable to find %s \
in the TYPE array as follows:\n",wd);
      for(i=fstatm; i<=lstatm; i++) fprintf(out,"%4s ",type[i-1]);
      fprintf(out,"\n");
      die();
   }
}
 
