#include "lookup.h"

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


void put_table(bool ctype, double hlim[4], double slim[2], uchar table[NS][NH]){
    if(ctype == OUTER){
        for(int s = 0; s < NS; s++){
            for(int h = 0; h < NH; h++){
                /*if(h <= hlim[0] || h >= hlim[3]){
                    table[s][h] = (uchar)(smf(s, slim[0], slim[1])*255);
                }else if(s >= slim[1]){
                    table[s][h] = (uchar)((zmf(h, hlim[0], hlim[1]) + smf(h, hlim[2], hlim[3])) * zmf(s, slim[1], slim[1] * 4.) * 0.75 * 255);//
                }else{
                    table[s][h] = (uchar)((zmf(h, hlim[0], hlim[1]) + smf(h, hlim[2], hlim[3])) * smf(s, slim[0], slim[1]) * 0.35 * 255);
                }*/
                table[s][h] = (uchar)((zmf(h, hlim[0], hlim[1]) + smf(h, hlim[2], hlim[3])) * smf(s, slim[0], slim[1]) * 255);
            }
        }
    }else {
        for (int s = 0; s < NS; s++) {
            for (int h = 0; h < NH; h++) {
                /*if (h >= hlim[1] && h <= hlim[2]) {
                    table[s][h] = (uchar)(smf(s, slim[0], slim[1]) * 255);
                } else if (s >= slim[1]) {
                    table[s][h] = (uchar)(pimf(h, hlim[0], hlim[1], hlim[2], hlim[3]) * zmf(s, slim[1], slim[1] * 4.) * 0.75 * 255);//
                } else {
                    table[s][h] = (uchar)(
                            pimf(h, hlim[0], hlim[1], hlim[2], hlim[3]) * smf(s, slim[0], slim[1]) * 0.35 * 255);
                }*/
                table[s][h] = (uchar)(pimf(h, hlim[0], hlim[1], hlim[2], hlim[3]) * smf(s, slim[0], slim[1]) * 255);
            }
        }
    }
}



