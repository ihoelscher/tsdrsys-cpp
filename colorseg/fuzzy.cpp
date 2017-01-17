#include "fuzzy.h"

double zmf(double x, double a, double b){
    double y, m, bb;

    if(x <= a) return 1;

    if(x >= b) return 0;

    m = (a+b)/2.;

    if(x <= m){
        bb = (x - a)/(b - a);
        y = 1 - (2 * pow(bb, 2));
        //printf("%.2f - %d, %.2f, %.2f\n", bb, x, a, b);
    }else{
        bb = (x - b)/(b - a);
        y = 2 * pow(bb, 2);
        //printf("%.2f ", y);
    }

    return(y);
}

double smf(double x, double a, double b){
    double y, m, bb;


    if(x<=a) return 0;

    if(x >= b) return 1;

    m = (a+b)/2.;

    if(x <= m){
        bb = (x - a)/(b - a);
        y = 2 * pow(bb, 2);
    }else{
        bb = (x - b)/(b - a);
        y = 1 - 2 * pow(bb, 2);
    }

    return(y);
}

double pimf(double x, double a, double b, double c, double d){
    double y, mab, mcd, bb;

    if(x <= a || x >= d) return 0;

    if(x >= b || x <= c) return 1;

    mab = (a+b)/2;
    mcd = (c+d)/2;

    if(x >= a && x <= mab){
        bb = (x - a) / (b - a);
        y = 2 * pow(bb, 2);
    }else if(x >= mab && x <= b){
        bb = (x - b) / (b - a);
        y = 1 - (2 * pow(bb, 2));
    }else if(x >= c && x <= mcd){
        bb = (x - c) / (d - c);
        y = 1 - (2 * pow(bb, 2));
    }else{
        bb = (x - d) / (d - c);
        y = 2 * pow(bb, 2);
    }

    return y;
}


double interp_membership(char f, double a, double b, double c, double d, double val){
    switch (f) {
        case 's':
            return smf(val, a, b);
        case 'z':
            return zmf(val, a, b);
        case 'p':
            return pimf(val, a, b, c, d);
        case 'n':
            return (zmf(val, a, b) + smf(val, c, d));
        default :
            return(val == 0 ? 1. : 0.);
    }
}

double centroid(double *a, int N){

    double val_sum = 0.0;
    double i_val_sum = 0.0;

    for (int i = 0; i < N; ++i){
        i_val_sum += double(i)*a[i];
        val_sum += a[i];
    }

    return i_val_sum/val_sum;
}


double inference(fuzzyvar *in, fuzzyvar out, double *x, int N){
    /*  Calcula toda a inferencia dado:
    *       in  : array de variaveis de entrada.
    *       out : variavel de saida.
    *       x   : array de valores de entrada.
    *       N   : tamanho da entrada.
    *
    *       y   : valor da saida para a entrada x.
    */

    double y;

    for(int i = 0; i < N; ++i){
        //printf("%d\n", in[i].nMF);
        for(int j = 0; j < in[i].nMF; ++j){
            in[i].y[j] = interp_membership(in[i].f[j], in[i].a[j], in[i].b[j],
                in[i].c[j], in[i].d[j], x[i]);
            printf("%.1f\n", in[i].y[j]);
        }
    }

    // rule 1: if hue isnt color, then gray_0
    double actvrule1 = in[0].y[1];

    // rule 2: if hue is color and sat is achr, then gray_low
    double actvrule2 = fmin(in[0].y[0], in[1].y[0]);

    // rule 3: if hue is color and sat is unst or val is achr, then gray_md
    double actvrule3 = fmin(in[0].y[0], fmax(in[1].y[1], in[2].y[0]));

    //rule 4: if hue is color and sat is chroma and val is chroma ou achroma, then gray_high
    double actvrule4 = fmin(in[0].y[0], fmin(in[1].y[2], fmax(in[2].y[0], in[2].y[1])));

    double *aggregated = new double[MAX_GRAY];

    for(int i = 0; i < MAX_GRAY; ++i){
        for(int j = 0; j < out.nMF; ++j){
            out.y[j] = interp_membership(out.f[j], out.a[j], out.b[j],
                out.c[j], out.d[j], i);
        }
        double out_0 = fmin(out.y[0], actvrule1);
        double out_low = fmin(out.y[1], actvrule2);
        double out_md = fmin(out.y[2], actvrule3);
        double out_high = fmin(out.y[3], actvrule4);

        aggregated[i] = fmax(out_0, fmax(out_low, fmax(out_md, out_high)));
        printf("%.1f, ", aggregated[i]);
    }

    return centroid(aggregated, MAX_GRAY);
}
