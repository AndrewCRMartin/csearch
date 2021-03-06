#include "ProtoTypes.h"
#include "CongenProto.h"
 
void pack2(
unsigned long int *i4,
unsigned short int i2,
unsigned short int j2
)
{
   if(abs(i2)>=(1<<15) || abs(j2)>=(1<<15))
   {
      fprintf(out,"pack2(): Cannot pack abs values > 2^15\n");
      die();
   }
   *i4 = (1<<16)*i2 + j2;
}
 
