#include "ProtoTypes.h"
#include "CongenProto.h"
 
/* Expand one backbone command into as many degrees of freedom as required
   by the range of startres to lastres. */
 
void propbbones(
struct dof **p,
struct backbone_d *dp,
int startres,
int lastres
)
{
   int i;
   struct dof *q;
   struct backbone_d *dq;
 
   dp->resno = startres;
   finbbone(*p,dp);
   for (i = dp->forward ? startres+1 : startres-1;
        dp->forward ? i<=lastres : i>=lastres;
        dp->forward ? i++ : i-- )
   {
      q = (struct dof *) alloc(sizeof(struct dof));
      dq = (struct backbone_d *) alloc(sizeof(struct backbone_d));
      q->dof_type = backbone_t;
      q->ok = (*p)->ok;
      q->desc = (union dof_descriptor *)dq; /* ACRM added cast */
      q->atoms = null;
      q->next = (*p)->next;
      q->prev = *p;
      (*p)->next = q;
      (*p) = q;
      dq->resno = i;
      dq->maxevdw = dp->maxevdw;
      dq->cistrans = dp->cistrans;
      dq->forward = dp->forward;
      dq->closing_atom = dp->closing_atom;
      dq->closing_distance = dp->closing_distance;
      dq->qdelta = dp->qdelta;
      dq->grid = dp->grid;
      dq->tersym = dp->tersym;
      dq->maxdt = dp->maxdt;
      finbbone(*p,dq);
   }
   dof_tail = *p;
}
 
