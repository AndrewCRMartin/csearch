/*****************************************************************************
 *      Name: phi                                                            *
 *  Function: Calculate the dihedral angle of four sequentially bonded atoms.*
 *            It returns a value in the range -PI to +PI and returns 0.0 if  *
 *            three or more of the atoms are linear.                         *
 * Copyright: (C) OXFORD MOLECULAR LTD, 1992                                 *
 *---------------------------------------------------------------------------*
 *    Author: Robert Williams                                                *
 *      Date: 02/10/92                                                       *
 *---------------------------------------------------------------------------*
 *    Inputs: ix,iy,iz - XYZ coordinates of the first atom                   *
 *            jx,jy,jz - XYZ coordinates of the second atom                  *
 *            kx,ky,kz - XYZ coordinates of the third atom                   *
 *            lx,ly,lz - XYZ coordinates of the fourth atom                  *
 *   Outputs: NONE                                                           *
 *   Returns: TorAng   - The calculated dihedral angle                       *
 * Externals:                                                                *
 *---------------------------------------------------------------------------*
 * MODIFICATION RECORD:                                                      *
 * DD/MM/YY   Initials   Comments                                            *
 *****************************************************************************/

#include "ProtoTypes.h"
#include "CongenProto.h"

#define  SmallNum  0.001

#ifndef PI
#define PI ((double)4.0*atan((double)1.0))
#endif

float phi(float ix, float iy, float iz,
          float jx, float jy, float jz,
          float kx, float ky, float kz,
          float lx, float ly, float lz)
{

/* Declare the variables used */

   float TorAng = 0.0;

   double Bondij[3], Bondjk[3], Bondkl[3],          /* Bond vectors     */
          Nor1[3],   Nor2[3],                       /* Normal vectors   */
          NNcross[3],                               /* Nor1 x Nor2      */
          NNdotJK,                                  /* NNcross . Bondjk */
          ModN1,     ModN2,                         /* Length of normals*/ 
          CosAng;                                   /* Cosine of TorAng */

   int   i;

/* Get the bond vectors */
 
   Bondij[0] = (double)(ix) - (double)(jx);
   Bondij[1] = (double)(iy) - (double)(jy);
   Bondij[2] = (double)(iz) - (double)(jz);

   Bondjk[0] = (double)(jx) - (double)(kx);
   Bondjk[1] = (double)(jy) - (double)(ky);
   Bondjk[2] = (double)(jz) - (double)(kz);

   Bondkl[0] = (double)(kx) - (double)(lx);
   Bondkl[1] = (double)(ky) - (double)(ly);
   Bondkl[2] = (double)(kz) - (double)(lz);

/* Get the normals to the planes formed by i-j-k (=Nor1) and jkl (=Nor2) */

   Nor1[0] = Bondij[1]*Bondjk[2] - Bondij[2]*Bondjk[1];
   Nor1[1] = Bondij[2]*Bondjk[0] - Bondij[0]*Bondjk[2];
   Nor1[2] = Bondij[0]*Bondjk[1] - Bondij[1]*Bondjk[0];

   Nor2[0] = Bondjk[1]*Bondkl[2] - Bondjk[2]*Bondkl[1];
   Nor2[1] = Bondjk[2]*Bondkl[0] - Bondjk[0]*Bondkl[2];
   Nor2[2] = Bondjk[0]*Bondkl[1] - Bondjk[1]*Bondkl[0];

/* Set the normal vectors to unit length */

   ModN1 = sqrt(Nor1[0]*Nor1[0]+Nor1[1]*Nor1[1]+Nor1[2]*Nor1[2]);
   ModN2 = sqrt(Nor2[0]*Nor2[0]+Nor2[1]*Nor2[1]+Nor2[2]*Nor2[2]);

   if ( ModN1 > SmallNum && ModN2 > SmallNum )
      {
      for (i=0 ; i<3 ; i++) 
         {
         Nor1[i] /= ModN1;
         Nor2[i] /= ModN2;
         }

/* Get the cosine of the angle between them and get the angle*/

      CosAng = Nor1[0]*Nor2[0]+Nor1[1]*Nor2[1]+Nor1[2]*Nor2[2];

      if (CosAng > 1.0) 
          CosAng = 1.0;
      else if (CosAng < -1.0)
          CosAng = -1.0;

/* Determine the sign of the angle */ 

      NNcross[0] = Nor1[1]*Nor2[2] - Nor1[2]*Nor2[1];
      NNcross[1] = Nor1[2]*Nor2[0] - Nor1[0]*Nor2[2];
      NNcross[2] = Nor1[0]*Nor2[1] - Nor1[1]*Nor2[0];

      NNdotJK = NNcross[0]*Bondjk[0]+NNcross[1]*Bondjk[1]+NNcross[2]*Bondjk[2];

      if (NNdotJK > 0.0) 
         TorAng = (float)(acos(CosAng)*-1.0);
      else
         TorAng = (float)(acos(CosAng));

/* Check angle is in the range -PI to PI */

      if (TorAng > (float)(PI))
          TorAng -= (float)(PI * 2);
      else if (TorAng < (float)(-PI))
          TorAng += (float)(PI * 2);

      }
   else 
      {
      TorAng = 0.0;
      }

   return(TorAng);
}
