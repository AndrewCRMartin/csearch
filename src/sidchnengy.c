#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Evaluates the energy of the sidechain pointed to by srp. */
 
double sidchnengy(
struct sideres *srp
)
{
   double ep,ei,ehb,evdw,eel,e;
   struct resphi *rp;
   struct clump *clp,**clpp;
   int mode,*ip,i;
   /* ACRM added floats so schnatm is called properly */
   float eel_f,
         evdw_f,
         ehb_f;
 
   if (srp->natom == 0) return 0.0;
   rp = srp->torsions;
 
   ep = ephi(1,rp->ip,rp->jp,rp->kp,rp->lp,rp->icp,rp->nphi,
             engpar.torcon,engpar.tormlt,engpar.torphs,
             coords.xcart,coords.ycart,coords.zcart,pstruct.qmove,0,0);
   if (dbg.cgen > 2) fprintf(out,"  EP = %g\n",ep);
 
   rp = srp->impropers;
   ei = ephi(2,rp->ip,rp->jp,rp->kp,rp->lp,rp->icp,rp->nphi,
             engpar.impcon,engpar.tormlt,engpar.eqitan,
             coords.xcart,coords.ycart,coords.zcart,pstruct.qmove,0,0);
   if (dbg.cgen > 2) fprintf(out,"  EI = %g\n",ei);
 
   for (clpp = srp->clumps; (clp = *clpp); clpp++)
      delatmsfgrd(clp->atoms);
   ehb = 0.0;
   mode = donor_hbond_energy;
   for (ip = srp->donors; (i = *ip); ip++)
   {  /* ACRM Changed to use floats */
      eel_f  = (float)eel,
      evdw_f = (float)evdw,
      ehb_f  = (float)ehb;
      schnatm(i,mode,null,f77_false,null,null,&eel_f,&evdw_f,&ehb_f);
      eel  = (double)eel_f;
      evdw = (double)evdw_f;
      ehb  = (double)ehb_f;
   }
   mode = acceptor_hbond_energy;
   for (ip = srp->acceptors; (i = *ip); ip++)
   {  /* ACRM changed to use floats */
      eel_f  = (float)eel,
      evdw_f = (float)evdw,
      ehb_f  = (float)ehb;
      schnatm(i,mode,null,f77_false,null,null,&eel_f,&evdw_f,&ehb_f);
      eel  = (double)eel_f;
      evdw = (double)evdw_f;
      ehb  = (double)ehb_f;
   }
   if (dbg.cgen > 2) fprintf(out,"  EHB = %g\n",ehb);
   mode = nbond_energy;
   eel = 0.0;
   evdw = 0.0;
   /* ACRM Changed to using floats */
   eel_f  = (float)eel,
   evdw_f = (float)evdw,
   ehb_f  = (float)ehb;
   walk_over_sideres(srp,
                     schnatm(atp->atomno,mode,(float *)&zero,
                                      cg.ignore_evdw,
                                      null,null,&eel_f,&evdw_f,&ehb_f);
                     adatmtgrd(atp->atomno);
   );
   /* ACRM recover our doubles */
   eel  = (double)eel_f;
   evdw = (double)evdw_f;
   ehb  = (double)ehb_f;
 
   if (dbg.cgen > 2) fprintf(out,"  EEL = %g\n  EVDW = %g\n",eel,evdw);
   e = ep + ei + ehb + eel + evdw;
   if (dbg.cgen > 1) fprintf(out,"  E = %g\n",e);
   return e;
}
 
