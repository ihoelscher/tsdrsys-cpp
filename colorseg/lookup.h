/*
 * Create a lookup table using fuzzy logic to segment images in HSV space.
 * The table should be 2D, rows representing Saturation value and columns Saturation.
 *
 * The achromatic area: characterised by s ≤ 0.25 or v ≤ 0.2 or v ≥ 0.9
 * The unstable chromatic area: characterised by 0.25 ≤ s ≤ 0.5 and 0.2 ≤ v ≤ 0.9
 * The chromatic area: characterised by s ≥ 0.5 and 0.2 ≤ v ≤ 0.9
 *
 * ctype - color type (red is outer, yellow is inner)
 * hlim  - color limits at hue channel
 * slim  - color limits at sat channel
 * table - lookup table
*/

#ifndef TSDRS_LOOKUP_H
#define TSDRS_LOOKUP_H

#include <opencv2/core/hal/interface.h>
#include <math.h>

#define OUTER false
#define INNER true

#define NS 256
#define NH 180
#define NV 256


double zmf(double x, double a, double b);
double smf(double x, double a, double b);
double pimf(double x, double a, double b, double c, double d);

void put_table(bool ctype, double hlim[4], double slim[2], double vlim[2], uchar table[NS][NH][NV]);



#endif //TSDRS_LOOKUP_H
