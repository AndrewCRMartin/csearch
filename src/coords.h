#ifndef __COORDS_H__
#define __COORDS_H__

/***********************************************************************
 *      NAME: COORDS                                                   *
 *  FUNCTION: To declare the coordinate arrays                         *
 * COPYRIGHT: (C) OXFORD MOLECULAR LIMITED, 1992                       *
 *---------------------------------------------------------------------*
 *    AUTHOR: Robert Williams                                          *
 *      DATE: 05/10/92                                                 *
 *---------------------------------------------------------------------*
 *    INPUTS:                                                          *
 *   OUTPUTS:                                                          *
 *    LOCALS:                                                          *
 *   GLOBALS:                                                          *
 *     CALLS:                                                          *
 *---------------------------------------------------------------------*
 * MODIFICATION RECORD                                                 *
 * DD/MM/YY   INITS   COMMENTS                                         *
 ***********************************************************************
   Variable name   array bounds           description
   -------------   ------------           -----------
     XCART           (MAXAT)     X cartesian coordinate for each atom
     YCART           (MAXAT)     Y cartesian coordinate for each atom
     ZCART           (MAXAT)     Z cartesian coordinate for each atom
 
     XWORK           (MAXAT)     X work space coordinate for each atom
     YWORK           (MAXAT)     Y work space coordinate for each atom
     ZWORK           (MAXAT)     Z work space coordinate for each atom

  Declarations */

extern struct {
      float xcart[maxat], ycart[maxat], zcart[maxat], 
            xwork[maxat], ywork[maxat], zwork[maxat];
      } coords;

#endif
