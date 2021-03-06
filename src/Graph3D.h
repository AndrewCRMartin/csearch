/****************************************************************************** 
 *	Name: Graph3D                                                         *
 *  Function: Three-dimensional graphics header file                          *
 * Copyright: (C) Oxford Molecular Limited.                                   *
 *----------------------------------------------------------------------------*
 *    Author: K.J. Woods, Tessella Support Services Ltd.                      *
 *      Date: 10/02/90                                                        *
 *----------------------------------------------------------------------------*
 * Modification Record                                                        *
 * Date     Inits   Comments                                                  *
 * dd/mm/yy                                                                   *
 ******************************************************************************/


#ifndef __GRAPH3D__
#define __GRAPH3D__

#define NOAXIS	-1
#define XAXIS	 0
#define YAXIS	 1
#define ZAXIS	 2

#define NULLTRANSFORM	0
#define ROTATION		1
#define TRANSLATION		2
#define SCALE			3

/* #define PI 	3.141592654 */ /* ACRM 16.01.05 */

#define XAXISEXTENT  	 15.0			/* Positive extent of the  X-axis */
#define YAXISEXTENT  	 15.0			/* Positive extent of the  Y-axis */

/* The MINSCALE and MAXSCALE values have been set to the values below in */
/* order to prevent the underflow or overflow of QuickDraw coordinates   */
#define MINSCALE	  	 0.00001		/* Minimum scale value */
#define MAXSCALE	 10000.0			/* Maximum scale value */


struct Point3D 	{
		float x;
		float y;
		float z;
		} ;

#ifndef __cplusplus
typedef struct Point3D Point3D;
#endif

struct Point2D	{
		float x;
		float y;
		} ;

#ifndef __cplusplus
typedef struct Point2D Point2D;
#endif

struct Point2Ds	{
		short x;
		short y;
		} ;

#ifndef __cplusplus
typedef struct Point2Ds Point2Ds;
typedef struct Point2Ds *Point2DsPtr;
#endif

struct Vector3D {
 		float x;
		float y;
		float z;
		} ;

#ifndef __cplusplus
typedef struct Vector3D Vector3D;
#endif

/* WDMap is a structure which contains the parameters describing the  */
/* mapping from world coordinates (x, y) to device coordinates (i, j) */
struct WDMap {
		float xLeft;
		float yBottom;
		float xRight;
		float yTop;
		short iLeft;
		short jBottom;
		short iRight;
		short jTop;
		float hRatio;
		float vRatio;
	     } ;

#ifndef __cplusplus
typedef struct WDMap WDMap;
#endif

typedef WDMap *WDMapPtr;

#endif
