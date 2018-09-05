#include "ProtoTypes.h"
#include "CongenProto.h"
 
/*
*   Returns the intersection (AND) of the two range lists pointed to
*   by in1 and in2, and puts the result in out.
*/
 
void isctrnglst(
struct range_list *in1,
struct range_list *in2,
struct range_list *sout
)
{
   int i1,i2,t;
   struct range_list *p;
   float newlow,newhigh;
   float *lowp,*highp;
   logical done;
 
   if (dbg.cgen > 2)
   {
      fprintf(out,"Intersect range list -- Input list 1:\n");
      prtrnglst(in1);
      fprintf(out,"Input list 2:\n");
      prtrnglst(in2);
   }
   done = false;
   sout->nrange = 0;
   i1 = 0;
   i2 = 0;
   while (!done)
   {
      if (i1 >= in1->nrange)
         done = true;
      else if (i2 >= in2->nrange)
         done = true;
      else if (in1->low[i1] > in2->low[i2])
      {
         swap(in1,in2,p);
         swap(i1,i2,t);
      }
      else if (in1->high[i1] < in2->low[i2])
         i1++;
      else
      {
         if (in2->high[i2] <= in1->high[i1])
         {
            newlow = in2->low[i2];
            newhigh = in2->high[i2++];
         }
         else
         {
            newlow = in2->low[i2];
            newhigh = in1->high[i1++];
            swap(in1,in2,p);
            swap(i1,i2,t);
         }
         if (sout->nrange >= sout->maxele)
         {
            lowp = (float *) alloc((sout->maxele += range_list_inc) *
                                   sizeof(float));
            highp = (float *) alloc(sout->maxele * sizeof(float));
            copy(lowp,sout->low,sout->nrange);
            copy(highp,sout->high,sout->nrange);
            if (sout->nrange > 0)
            {
               free(sout->low);
               free(sout->high);
            }
            sout->low = lowp;
            sout->high = highp;
         }
         sout->low[sout->nrange] = newlow;
         sout->high[sout->nrange++] = newhigh;
      }
   }
   if (dbg.cgen > 2)
   {
      fprintf(out,"Output range list\n");
      prtrnglst(sout);
   }
}
 
