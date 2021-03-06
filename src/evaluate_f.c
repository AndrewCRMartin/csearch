/*****************************************************************************
 *      Name:                                                                *
 *  Function:                                                                *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1993                                 *
 *---------------------------------------------------------------------------*
 *    Author:                                                                *
 *      Date:                                                                *
 *---------------------------------------------------------------------------*
 *    Inputs:                                                                *
 *   Outputs:                                                                *
 *   Returns:                                                                *
 * Externals:                                                                *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 * 16/08/93   rkw        moved "#ifdef EVALUATE" to inside the function      *
 *****************************************************************************/
#include "ProtoTypes.h"
#include "CongenProto.h"
 
void evaluate_f(dofp,desc)
struct dof *dofp;
struct evaluate_d *desc;
{
/* OMUPD rkw 16/08/93 moved "#ifdef EVALUATE" to here from the top */
#ifdef EVALUATE
   float evaluation;
   int i,i1;
 
   if (dbg.cgen) fprintf(out,"evaluate_f:\n");
   desc->evalcount++;
   for (i=0;  i<desc->nconsp;  i++)
   {
      delatmfgrd(desc->consp[i]);
      i1 = desc->consp[i] - 1;
/*
*   The following code is commented out until HBOND stops generating
*   hydrogen positions.
      desc->savedx[i] = coords.xcart[i1];
      desc->savedy[i] = coords.ycart[i1];
      desc->savedz[i] = coords.zcart[i1];
*/
   }
   for (i=0;  i < values.natoms;  i++)
   {
      desc->savedx[i] = coords.xcart[i];
      desc->savedy[i] = coords.ycart[i];
      desc->savedz[i] = coords.zcart[i];
   }
   switch (desc->eval_code)
   {
   case eval_code_rms:
      evaluate_gap_rms(desc->consp,&desc->nconsp,desc->initx,
                       desc->inity,desc->initz,&desc->evaluation);
      fprintf(out,"RMS deviation for evaluation %10d is %g\n",
             desc->evalcount,desc->evaluation);
      break;
   case eval_code_energy:
      evaluate_gap_energy(desc->minist,&desc->ministl,desc->workst,
                          &cg.ignore_evdw,desc->imove,&desc->evaluation);
      fprintf(out,"Energy for evaluation %10d is %g\n",
             desc->evalcount,desc->evaluation);
      break;
   case eval_code_user:
      user_cgeval(dofp,desc,&desc->evaluation);
      fprintf(out,"User evaluation %10d is %g\n",
             desc->evalcount,desc->evaluation);
      break;
   default:
      fprintf(out,"Error in evaluate_f -- unknown eval_code = %d.\n",
                     desc->eval_code);
      die();
      break;
   }
   if (desc->evalcount == 1)
       desc->mineval = desc->maxeval = desc->evaluation;
   else
   {
      desc->mineval = minf2(desc->mineval,desc->evaluation);
      desc->maxeval = maxf2(desc->maxeval,desc->evaluation);
   }
   for (i=0;  i<desc->nconsp;  i++)
      adatmtgrd(desc->consp[i]);
 
   dispatch(dofp->next);
   for (i=0;  i<desc->nconsp;  i++)
   {
       delatmfgrd(desc->consp[i]);
       i1 = desc->consp[i] - 1;
/*
*   The following code is commented out until HBOND stops generating
*   hydrogen positions.
       coords.xcart[i1] = desc->savedx[i];
       coords.ycart[i1] = desc->savedy[i];
       coords.zcart[i1] = desc->savedz[i];
*/
   }
   for (i=0;  i < values.natoms;  i++)
   {
      coords.xcart[i] = desc->savedx[i];
      coords.ycart[i] = desc->savedy[i];
      coords.zcart[i] = desc->savedz[i];
   }
   for(i=0; i<desc->nconsp; i++)
   {
       adatmtgrd(desc->consp[i]);
   }
/* OMUPD rkw 16/08/93 moved "#endif" to here from the bottom */
#endif /* EVALUATE */
}
