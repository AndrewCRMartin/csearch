/*****************************************************************************
 *      Name: explcntcts.c                                                   *
 *  Function:                                                                *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1992                                 *
 *---------------------------------------------------------------------------*
 *    Author: B.N. Jamieson, Oxford Molecular Ltd                            *
 *      Date: 26/02/92                                                       *
 *---------------------------------------------------------------------------*
 *    Inputs:                                                                *
 *   Outputs:                                                                *
 *   Returns:                                                                *
 * Externals:                                                                *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 * 26/02/92   DW         Added header; removed grid.H                        *
 *****************************************************************************/

#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   For clump pointed to by srp, this procedure finds the range of
*   allowable torsion angles for the free torsion angle which avoid
*   van der Waals interactions with neighboring atoms.
*/
 
void explcntcts(
struct sideres *srp,
struct clump *clp,
struct range_list **rangepp,
int *sidehits
)
{
   struct range_list *rangep,*nrp,*trp;
   struct atom *free_atp,*atp,**atpp;
   float oc[3],ecx[3],ecy[3],ecz[3];
   int startx,starty,startz,lastx,lasty,lastz;
   int ix,iy,iz;
   float rmax;
   int ispace,sgp,igrid,iatm;
   float startphi,lastphi;
   logical impact;
   struct range_list crange;
   float clow[2],chigh[2];
 
   rangep = struct_alloc(range_list);
   rangep->maxele = range_list_inc;
   rangep->nrange = 1;
   rangep->low = (float *) alloc(range_list_inc * sizeof(float));
   rangep->high = (float *) alloc(range_list_inc * sizeof(float));
   nrp = struct_alloc(range_list);
   nrp->maxele = range_list_inc;
   nrp->nrange = 0;
   nrp->low = (float *) alloc(range_list_inc * sizeof(float));
   nrp->high = (float *) alloc(range_list_inc * sizeof(float));
   *(rangep->low) = -pi;
   *(rangep->high) = pi;
   crange.low = clow;
   crange.high = chigh;
   free_atp = clp->free_atom;
   ecsetxyzsys(free_atp->ante,oc,ecx,ecy,ecz);
   ecsetlims(oc,ecx,&clp->avoidxcenter,&clp->avoidextent,&clp->avoidrmax,
                 &clp->avoidvdwrmax,&startx,&starty,&startz,
                 &lastx,&lasty,&lastz,&rmax);
   for (ix=startx; ix<=lastx; ix++)
   {
      for (iy=starty; iy<=lasty; iy++)
      {
         for (iz=startz; iz<=lastz; iz++)
         {
            igrid = ((iz-1)*grid.ngridy+iy-1)*grid.ngridx+ix-1;
            ispace = grid.space_grid[igrid];
            if (ispace != 0)
            {
               for (sgp=grid.clshd[ispace-1]; sgp; sgp=grid.nextcls[sgp-1])
               {
                  iatm = grid.clsatm[sgp-1];
                  for (atpp = clp->atoms; (atp = *atpp); atpp++)
                  {
                     ecchkcont(&iatm,&atp->atomno,oc,ecx,ecy,ecz,
                                      &atp->avoidx,&atp->avoidr,
                                      &atp->avoidphi,atp->rcontact,
                                      &startphi,&lastphi,&impact,sidehits,
                                      grid.resbya,
                                      grid.cntnbx,grid.nbxa,grid.qside);
                     if (startphi == -10.0)
                     {
                        rangep->nrange = 0;
                        goto outer_break;
                     }
                     if (!impact)
                     {
                        continue;
                     }
                     else
                     {
                        if (lastphi <= pi)
                        {
                           clow[0] = startphi - range_eps;
                           chigh[0] = lastphi + range_eps;
                           crange.nrange = 1;
                        }
                        else
                        {
                           clow[0] = -pi;
                           chigh[0] = lastphi - 2*pi + range_eps;
                           clow[1] = startphi - range_eps;
                           chigh[1] = pi;
                           crange.nrange = 2;
                        }
                        isctrnglst(rangep,&crange,nrp);
                        swap(rangep,nrp,trp);
                     }
                  }
               }
            }
         }
      }
   }
outer_break:
   *rangepp = rangep;
   free_range(nrp);
}
 
