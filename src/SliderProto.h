/***********************************************************************
 *      Name: SliderProtoTypes.h                                       *
 *  Function: Slider management prototypes                             *
 * Copyright: (C) Oxford Molecular Limited                             *
 *---------------------------------------------------------------------*
 *    Author: D. Walker, Tessella Support Services plc                 *
 *      Date: 12/06/89                                                 *
*---------------------------------------------------------------------*
 * Modification Record                                                 *
 * Date     Inits   Comments                                           *
 * dd/mm/yy                                                            *
 ***********************************************************************/

/* Flag indicating inclusion of this file */
#ifndef __SLIDERPROTO__
#define __SLIDERPROTO__

/* OMUPD DW 13/3/91 If the button header file hasn't been included, it MUST
   be included now */

#ifndef __BUTTONPROTO__
#include "ButtonProto.h"
#endif

/* Slider structure */

/* OMUPD DW 13/3/91 To allow the use of sliders in dialogs, the slider and
   button structures have been integrated. SliderType is now directly
   equivalent to ButtonType and the following declaration is redundant. */

/* typedef struct SliderType { */
   /* char Title[80];   */      /* Slider Title string */
   /* short OriginX;    */      /* Outer box X origin */
   /* short OriginY;    */      /* Outer box Y origin */
   /* short Length;     */      /* Outer box length */
   /* short Height;     */      /* Outer box height */
   /* float ValueWidth; */      /* Fractional width of value box */
   /* short Format;     */      /* Format specifier */
   /* short NDecimal;   */      /* Number of decimal places */
   /* float Min;        */      /* Minimum value of slider variable */
   /* float Max;        */      /* Maximum value of slider variable */
   /* float Position;   */      /* Current slider position */
   /* short Type;       */      /* slider type - normal or simple */
   /* short Vertical;   */      /* for simple sliders - vetical/horizontal */
/* } SliderType; */

typedef ButtonType SliderType;

/* definitions for slider type */
#define SLIDER_NORMAL   0   /* slider with title and value box */
#define SLIDER_SIMPLE   1   /* simple slider with runner only */

/* Definitions for format specifier */

#define SLIDER_EXPONENTIAL 0
#define SLIDER_FLOAT       1
#define SLIDER_INTEGER     2

/* Slider Colour definitions */

#define SLIDER_OUTER_RED   100
#define SLIDER_OUTER_GREEN 100
#define SLIDER_OUTER_BLUE  100
#define SLIDER_RUN_RED     200
#define SLIDER_RUN_GREEN   200
#define SLIDER_RUN_BLUE    200
#define SLIDER_VALUE_RED   255
#define SLIDER_VALUE_GREEN 255
#define SLIDER_VALUE_BLUE  255
#define SLIDER_FORE_RED    0
#define SLIDER_FORE_GREEN  0
#define SLIDER_FORE_BLUE   0
#define SLIDER_INNER_RED   255
#define SLIDER_INNER_GREEN 255
#define SLIDER_INNER_BLUE  255

/* Slider drawing parameters */

#define SLIDER_YMARGIN  0.05
#define SLIDER_XMARGIN  0.05
#define SLIDER_BARWIDTH 2

#endif
