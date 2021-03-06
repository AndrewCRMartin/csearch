#include "ProtoTypes.h"
#include "CongenProto.h"
#include "cgparse.h"

#define WDMAX 80
 
/* Set up the sidechain degree of freedom. */
 
void setsidchn(
int prev_start,
int prev_last,
struct sidechain_d *dp,
int *res,
float *sgrid,
float *maxevdw,
logical *vavoid,
logical *clump_symmetry,
logical *okp
)
{
   logical ok;
   int startres,lastres,newsres,newlres,*pres,i;
   float   old_sgrid,new_sgrid,cur_sgrid,*psgrid;
   float   old_maxevdw,new_maxevdw,cur_maxevdw,*pmaxevdw;
   logical old_vavoid,new_vavoid,cur_vavoid,*pvavoid;
   logical old_clump_symmetry,new_clump_symmetry,cur_clump_symmetry,
           *pclump_symmetry;
 
   ok = true;
   startres = 0;
   lastres = 0;
   pres = res;
   *res = 0;
   psgrid = sgrid;
   pmaxevdw = maxevdw;
   pvavoid = vavoid;
   pclump_symmetry = clump_symmetry;
   dp->ncomb = 3;
   dp->maxsideiter = 10;
 
/* grid size */
   for(i=0; i<3; i++) g_strparam[1][i] = toupper(g_strparam[1][i]);
   if(!strncmp(g_strparam[1],"MIN",3))
      cur_sgrid = -1.0;
   else
   {
      sscanf(g_strparam[1],"%f",&cur_sgrid);
      if(cur_sgrid <= 0.0) cur_sgrid = 30.0;
   }
   old_sgrid = new_sgrid = cur_sgrid;
 
 
/* Max VDW energy */
   sscanf(g_strparam[0],"%f",&cur_maxevdw);
   old_maxevdw = new_maxevdw = cur_maxevdw;
 
 
/* VAVOID always on */
   cur_vavoid = true;
   old_vavoid = new_vavoid = cur_vavoid;
 
/* SYMMETRY always on */
   cur_clump_symmetry = true;
   old_clump_symmetry = new_clump_symmetry = cur_clump_symmetry;
 
/* Default sidechain construction option */
   dp->sideopt = first;
 
/* Evaluation option; we don't allow the user to alter this */
   dp->evalopt = eo_energy;
 
/* Start res */
   padspace(g_strparam[2],4);
   padspace(g_strparam[3],4);
   newsres = get_resnum(g_strparam[2],g_strparam[3]);
   new_sgrid = cur_sgrid;
   new_maxevdw = cur_maxevdw;
   new_vavoid = cur_vavoid;
   new_clump_symmetry = cur_clump_symmetry;
   if (newsres != 0)
   {
      if (startres != 0)
      {
         if (lastres == 0) lastres = startres;
         setsddofrs(startres,lastres,res,
                         old_sgrid,old_maxevdw,old_vavoid,
                         old_clump_symmetry,
                         &pres,&psgrid,&pmaxevdw,&pvavoid,
                         &pclump_symmetry);
      }
      startres = newsres;
      old_sgrid = new_sgrid;
      old_maxevdw = new_maxevdw;
      old_vavoid = new_vavoid;
      old_clump_symmetry = new_clump_symmetry;
      lastres = 0;
   }
 
/* Last res */
   padspace(g_strparam[2],4);
   padspace(g_strparam[4],4);
   newlres = get_resnum(g_strparam[2],g_strparam[4]);
   if (newlres != 0)
   {
      if (lastres != 0)
      {
         fprintf(out,"\nWarning from PARSE_SIDECHAIN -- LASTRES specified \
twice for one range.\n");
         fprintf(out,"The last value specified will be used.\n");
      }
      lastres = newlres;
   }
 
/* We don't allow the user to set dp->ncomb at present */
/* We don't allow the user to set dp->maxsideiter at present */
 
/* Sidechain construction protocol option */
   for(i=0; i<3; i++) g_strparam[5][i] = toupper(g_strparam[5][i]);
   for(i=0; i<nsideopt; i++)
   {
      if(!strncmp(st_sideopt[i],g_strparam[5],3))
      {
         dp->sideopt = i+1;
         break;
      }
   }
 
/* Check we have sensible valuies for startres and lastres */
   if (startres == 0)
   {
      if (lastres !=0)
      {
         fprintf(out,"Lastres specified without corresponding startres\n");
         fprintf(out,"The value of startres from the last backbone degree \
of freedom will be used.\n");
      }
      else lastres = prev_last;
      startres = prev_start;
      old_sgrid = cur_sgrid;
      old_maxevdw = cur_maxevdw;
      old_vavoid = cur_vavoid;
      old_clump_symmetry = cur_clump_symmetry;
   }
   else
   {
      if (lastres == 0) lastres = startres;
   }
 
   /* Actually fill in the details into the dof */
   setsddofrs(startres,lastres,res,
                   old_sgrid,old_maxevdw,old_vavoid,old_clump_symmetry,
                   &pres,&psgrid,&pmaxevdw,&pvavoid,&pclump_symmetry);
 
   /* Finally fill in stuff which depends on the construction option */
   switch (dp->sideopt)
   {
   case first:
      dp->ncomb = 1;
      break;
   case independent:
      dp->ncomb = 1;
      break;
   case all:
      dp->ncomb = 1;
      break;
   case iterative:
      dp->ncomb = 2;
      break;
   case combination:
      if (dp->ncomb < 1)
      {
         fprintf(out,"Warning from PARSE_SIDECHAIN -- NCOMB raised to 1.\n");
         dp->ncomb = 1;
      }
      break;
   }
}
 
