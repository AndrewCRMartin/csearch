#include "ProtoTypes.h"
#include "CongenProto.h"
 
extern int info_level;

/* Reads a PGP file */
 
int ReadPGP(
FILE *fp
)
{
   int c,n=0;
   FLIST *list,*list_start;
 
 
   c = 0;
   while(c != EOF && !feof(fp))
   {
      list_start = (FLIST *)malloc(sizeof(FLIST));
      if(!list_start)
         prdie("ReadPGP(): Unable to allocate memory for parameter list");
      list = list_start;
      c = forscanf(fp,"%4s%4s%1x%4s%1x%4s%1x%4s%1x%4s%1x%4s%1x%1d%10f%10f%10f",
      list);
      if(c==EOF) break;
      strncpy(gres[++n],list->rets,4);    NEXT(list);
      gres[n][4]='\0';
      if(!gres[n][0])
      {
         n--;
         continue;
      }
      strncpy(gatom[n][1],list->rets,4);  NEXT(list);
      gatom[n][1][4] = '\0';
      strncpy(gatom[n][2],list->rets,4);  NEXT(list);
      gatom[n][2][4] = '\0';
      strncpy(gatom[n][3],list->rets,4);  NEXT(list);
      gatom[n][3][4] = '\0';
      strncpy(gatom[n][4],list->rets,4);  NEXT(list);
      gatom[n][4][4] = '\0';
      strncpy(gatom[n][5],list->rets,4);  NEXT(list);
      gatom[n][5][4] = '\0';
      strncpy(gatom[n][6],list->rets,4);  NEXT(list);
      gatom[n][6][4] = '\0';
      igtype[n] = list->retd;             NEXT(list);
      gr[n]     = list->retf;             NEXT(list);
      alpha[n]  = list->retf;             NEXT(list);
      beta[n]   = list->retf;
 
#ifdef DEBUG
      printf("%4s %4s %4s %4s %4s %4s %4s %1d %8.3f %8.3f %8.3f\n",gres[n],
      gatom[n][1],gatom[n][2],gatom[n][3],gatom[n][4],gatom[n][5],gatom[n][6],
      igtype[n],gr[n],alpha[n],beta[n]);
#endif
 
      if(igtype[n] != 0)
      {
         alpha[n] *= (PI/180.0);
         beta[n]  *= (PI/180.0);
      }
 
      /* Free the forscanf list */
      FREEFORSCANFLIST(list_start);
   }  /* End of file */
 
   npgp = n;
   if(info_level>0)
      printf("Number of proton generation parameters = %d\n",npgp);
 
   return(npgp);
}
 
