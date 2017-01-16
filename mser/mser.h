//
// Created by ihoelscher on 16/08/16.
//

#ifndef TSDRS_MSER_H
#define TSDRS_MSER_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

#define OPENING     0x01
#define CLOSING     0x02
#define ERODE       0x04
#define DILATE      0x08
#define GAUSS       0x10
#define BILATERAL   0x20
#define MEDIAN      0x40
#define THRESH      0x80

typedef struct MSER_param{
    int delta;
    int min_area;
    int max_area;
    double max_variation;
    double min_diversity;
}MSER_param;

void prefilter(uchar flags, Mat src, Mat& dst);
bool isRoi(Rect r, Mat src);
double areaOfItersection(Rect a, Rect b);
bool suppress(Rect r, vector<Rect>& rois);
uchar getRegions(MSER_param params, uchar preflags, Mat& src, vector<Rect>& rois);


#endif //TSDRS_MSER_H
