#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* The main routine to do the work! */
 
void ReadRTF(
FILE *unit,
int qprint,
int *natc
)
{
   int   ResTopTyp,
         j,
         eof,
         prnflg,
         ntabl,
         sawtbl,
         wrncto=0,
         nrx;
   float totchg;
 
   char  tblkey[MXTABL][4],
         nbxnam[mxnber][4];
   int   tblrep[MXTABL],
         nbxn[mxatmr];
 
   /* Command parser stuff */
   KeyWd RESTOPkeywords[RESTOPNCOMM];  /* Array to store keywords      */
   char  comline[MXCBUF+1];            /* The command line for parsing */ 
   int   key;                          /* Return value from parse()    */
   int   i;                            /* Counter                      */
 
   /* Initialise returned string array */
   for(i=0; i<RESTOPMAXSTRPARAM; i++)
      ResTop_strparam[i] = (char *)malloc(RESTOPMAXSTRLEN * sizeof(char));
 
   /* Construct the keywords */
   MAKEKEY(RESTOPkeywords[0],"TOPOLOGY",STRING,1);    /* Was TYPE  */
   MAKEKEY(RESTOPkeywords[1],"TYPE",STRING,3);        /* Was MASS  */
   MAKEKEY(RESTOPkeywords[2],"DECLARE",STRING,2);
   MAKEKEY(RESTOPkeywords[3],"RESIDUE",STRING,2);
   MAKEKEY(RESTOPkeywords[4],"ATOM",STRING,4);
   MAKEKEY(RESTOPkeywords[5],"BOND",STRING,2);
   MAKEKEY(RESTOPkeywords[6],"ANGLE",STRING,3);
   MAKEKEY(RESTOPkeywords[7],"TORSION",STRING,4);
   MAKEKEY(RESTOPkeywords[8],"IMPROPER",STRING,4);
   MAKEKEY(RESTOPkeywords[9],"DONOR",STRING,4);
   MAKEKEY(RESTOPkeywords[10],"ACCEPTOR",STRING,1);
   MAKEKEY(RESTOPkeywords[11],"BUILD",STRING,9);
   MAKEKEY(RESTOPkeywords[12],"GROUP",STRING,3);
   MAKEKEY(RESTOPkeywords[13],"END",NUMBER,0);
   MAKEKEY(RESTOPkeywords[14],"PRINT",STRING,1);
 
 
   /* Zero the error and warning counts                                 */
   ResTop_errcnt  = 0;
   ResTop_wrncnt = 0;
 
   /* Blank or zero various arrays. Set flags.                          */
   for(i=0;i<maximr;i++)
   {
      strncpy(restop.namres[i],BLANK,4);
      for(j=0;j<ninfo;j++) restop.nparam[i][j] = 0;
   }
   for(i=0;i<ninfo;i++) restop.nparus[i] = 0;
   for(i=0;i<maxatt;i++)
   {
      strncpy(restop.acodes[i],BLANK,4);
      restop.atmmas[i] = 0.0;
   }
   eof = FALSE;
   prnflg = qprint;
   ResTopTyp = 0;
   restop.nreses = 0;
   ntabl = 1;
   *natc = 0;
   totchg = 0.0;
 
   /* Initialise DECLARE table
      sawtbl records where DECLARE'd atom names were used during the
      processing of this residue. Once they're used, new atoms can't be
      defined because the value of NATOM would then be different.
   */
   strncpy(tblkey[0],BLANK,4);
   tblrep[0] = -99;
   sawtbl = FALSE;
 
 
   /* Sit in a loop until we reach the end of the file                  */
 
   while(!eof && fgets(comline,MXCBUF,unit))
   {
      terminate(comline);
 
      key = parse(comline,RESTOPNCOMM,RESTOPkeywords,ResTop_numparam,
                  ResTop_strparam);
      switch(key)
      {
      case PARSE_ERRC:
      case PARSE_ERRP:
         fprintf(out,"ReadRTF(): Error in command:\n");
         ResTop_errcnt++;
      case PARSE_COMMENT:
         break;
      case 0: /* TOPOLOGY                                               */
         ResTopTyp = RTFTopology();
         break;
      case 1: /* TYPE                                                   */
         RTFType(natc);
         break;
      case 2: /* DECLARE                                                */
         RTFDeclare(tblkey,tblrep,&ntabl);
         break;
      case 3: /* RESIDUE                                                */
         RTFResidue(&totchg,&nrx,&sawtbl,nbxn,nbxnam,ntabl,tblkey,tblrep);
         break;
      case 4: /* ATOM                                                   */
         RTFAtom(nbxn,sawtbl,&nrx,nbxnam,natc);
         break;
      case 5: /* BOND                                                   */
         RTFBond(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 6: /* ANGLE                                                  */
         RTFAngle(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 7: /* TORSION                                                */
         RTFTorsion(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 8: /* IMPROPER                                               */
         RTFImproper(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 9: /* DONOR                                                  */
         RTFDonor(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 10: /* ACCEPTOR                                              */
         RTFAcceptor(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 11: /* BUILD                                                 */
         RTFBuild();
         break;
      case 12: /* GROUP                                                 */
         RTFGroup(&sawtbl,ntabl,tblkey,tblrep);
         break;
      case 13: /* END                                                   */
         eof = TRUE;
         break;
      case 14: /* PRINT                                                 */
         RTFPrint(&prnflg);
         break;
      default:
         break;
      }
 
      /* Check for errors/warnings and print the offending line         */
      if(ResTop_errcnt + ResTop_wrncnt != wrncto)
      {
         wrncto = ResTop_errcnt+ResTop_wrncnt;
         fprintf(out,"          %s\n",comline);
      }
   }  /* End of while() in file                                         */
 
   /* Finish off the last residue                                       */
   finres(totchg,nbxn,nbxnam,ntabl,tblkey,&sawtbl,tblrep);
 
   /* Check everything was OK                                           */
   CheckNATC(natc);
   CheckRTF();
 
   /* Print warning messages                                            */
   if(ResTop_wrncnt)
      fprintf(out,"ReadRTF(): There were %d warning(s)\n",ResTop_wrncnt);
   if(ResTop_errcnt)
   {
      fprintf(out,"ReadRTF(): There were %d error(s)\n",ResTop_errcnt);
      fprintf(out,"           Execution will be terminated\n");
      die();
   }
 
   /* Free the returned string array                                    */
   for(i=0; i<RESTOPMAXSTRPARAM; i++) free(ResTop_strparam[i]);
 
   /* We won't need the file again, so close it                         */
   fclose(unit);
   unit = NULL;
 
   /* Here we ought to free the KeyWd strings                           */
}
 
