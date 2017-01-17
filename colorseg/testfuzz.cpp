#include "fuzzy.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
    fuzzyvar *inputs = new fuzzyvar[3];

    // Membership functions for Hue
    inputs[0].nMF = 2;
    inputs[0].f = new char[2];
    inputs[0].a = new double[2];
    inputs[0].b = new double[2];
    inputs[0].c = new double[2];
    inputs[0].d = new double[2];
    inputs[0].y = new double[2];
    // Hue is red
    inputs[0].f[0] = 'n';
    inputs[0].a[0] = 6.;
    inputs[0].b[0] = 16.;
    inputs[0].c[0] = 160.;
    inputs[0].d[0] = 174.;
    // Hue is not red
    inputs[0].f[1] = 'p';
    inputs[0].a[1] = 12.;
    inputs[0].b[1] = 18.;
    inputs[0].c[1] = 156.;
    inputs[0].d[1] = 164.;


    // Membership functions for Sat
    inputs[1].nMF = 3;
    inputs[1].f = new char[3];
    inputs[1].a = new double[3];
    inputs[1].b = new double[3];
    inputs[1].c = new double[3];
    inputs[1].d = new double[3];
    inputs[1].y = new double[3];
    // Sat is achroma
    inputs[1].f[0] = 'z';
    inputs[1].a[0] = 0.05*255;
    inputs[1].b[0] = 0.2*255;
    inputs[1].c[0] = inputs[0].d[0] = 0.;
    // Sat is unstable
    inputs[1].f[1] = 'p';
    inputs[1].a[1] = 0.1*255;
    inputs[1].b[1] = 0.3*255;
    inputs[1].c[1] = 0.4*255;
    inputs[1].d[1] = 0.6*255;
    // Sat is chroma
    inputs[1].f[2] = 's';
    inputs[1].a[2] = 0.4*255;
    inputs[1].b[2] = 0.6*255;
    inputs[1].c[2] = inputs[1].d[2] = 0.;


    // Membership functions for Val
    inputs[2].nMF = 2;
    inputs[2].f = new char[2];
    inputs[2].a = new double[2];
    inputs[2].b = new double[2];
    inputs[2].c = new double[2];
    inputs[2].d = new double[2];
    inputs[2].y = new double[2];
    // Val is achroma
    inputs[2].f[0] = 'z';
    inputs[2].a[0] = 0.*255;
    inputs[2].b[0] = 0.2*255;
    inputs[2].c[0] = inputs[0].d[0] = 0.;
    // Val is chroma
    inputs[2].f[1] = 's';
    inputs[2].a[1] = 0.1*255;
    inputs[2].b[1] = 0.25*255;
    inputs[2].c[1] = inputs[2].d[1] = 0.;


    fuzzyvar output;
    // Membership functions for Grayscale output
    output.nMF = 4;
    output.f = new char[4];
    output.a = new double[4];
    output.b = new double[4];
    output.c = new double[4];
    output.d = new double[4];
    output.y = new double[4];
    // Output is 0
    output.f[0] = '0';
    output.a[0] = output.b[0] =
    output.c[0] = output.d[0] = 0.;
    // Output is low
    output.f[1] = 'z';
    output.a[1] = 0.15*255;
    output.b[1] = 0.4*255;
    output.c[1] = output.d[1] = 0.;
    // Output is md
    output.f[2] = 'p';
    output.a[2] = 0.2*255;
    output.b[2] = 0.35*255;
    output.c[2] = 0.55*255;
    output.d[2] = 0.7*255;
    // Output is high
    output.f[3] = 's';
    output.a[3] = 0.4*255;
    output.b[3] = 0.8*255;
    output.c[3] = output.d[3] = 0;

    double X[3] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};

    double Y = inference(inputs, output, X, 3);

    printf("\n%.2f\n", Y);

    return 0;
}
