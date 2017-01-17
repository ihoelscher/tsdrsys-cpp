#include <math.h>
#include "stdio.h"

typedef struct fuzzyvar{
    short nMF;
    char *f;
    double *a;
    double *b;
    double *c;
    double *d;
    double *y;
}fuzzyvar;

#define MAX_GRAY 256

double zmf(double x, double a, double b);
double smf(double x, double a, double b);
double pimf(double x, double a, double b, double c, double d);
double interp_membership(char f, double a, double b, double c, double d, double val);
double centroid(double *a, int N);
double inference(fuzzyvar *in, fuzzyvar out, double *x, int N);
