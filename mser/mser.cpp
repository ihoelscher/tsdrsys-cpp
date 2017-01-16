//
// Created by ihoelscher on 16/08/16.
//

#include "mser.h"

void prefilter(uchar flags, Mat src, Mat& dst){

    if(flags & THRESH){
        threshold(dst, dst, 127, 255, THRESH_TOZERO);
    }

    if(flags & ERODE) {
        Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
        morphologyEx(dst, dst, MORPH_ERODE, element);
    }

    if(flags & OPENING) {
        Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
        morphologyEx(dst, dst, MORPH_OPEN, element, Point(-1, -1), 2);
    }

    if(flags & CLOSING) {
        Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
        morphologyEx(dst, dst, MORPH_CLOSE, element, Point(-1, -1), 2);
    }

    if(flags & DILATE) {
        Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
        morphologyEx(dst, dst, MORPH_DILATE, element);
    }

    if(flags & GAUSS){
        GaussianBlur(dst, dst, Size(3, 3), 0);
    }else if(flags & BILATERAL){
        bilateralFilter(dst, dst, 5, 75, 75);
    }else if(flags & MEDIAN){
        medianBlur(dst, dst, 5);
    }
}

bool isRoi(std::vector<cv::Point> r, Mat src){
    RotatedRect rr = minAreaRect(r);

    int maxSide = fmax((int)rr.size.width, (int)rr.size.height);
    int minSide = fmin((int)rr.size.width, (int)rr.size.height);

    if(maxSide > 300 or minSide < 15) return false;

    if(maxSide/float(minSide) > 1.8) return false;

    /*double min, max;
    Rect rec = boundingRect(r);
    minMaxLoc(src(rec), &min, &max);
    if(max < 150) return false;*/

    return true;
}

double areaOfItersection(Rect a, Rect b){
    int xa[2] = {a.x, a.x + a.width};
    int ya[2] = {a.y, a.y + a.height};

    int xb[2] = {b.x, b.x + b.width};
    int yb[2] = {b.y, b.y + b.height};

    if (xa[0] >= xb[0] and xa[1] <= xb[1] and ya[0] >= yb[0] and ya[1] <= yb[1]) return double(a.width*a.height);
    else return fmax(0, fmin(xa[1], xb[1]) - fmax(xa[0], xb[0])) * fmax(0, fmin(ya[1], yb[1]) - fmax(ya[0], yb[0]));
}

bool suppress(Rect r, vector<Rect>& rois){

    int wc = r.width;
    int hc = r.height;

    double sc = wc*hc;

    for(vector<Rect>::iterator it = rois.begin(); it != rois.end(); ++it){
        double si = areaOfItersection(r, *it);

        int wC = (*it).width;
        int hC = (*it).height;

        double sC = wC*hC;

        double rat = sC/sc;

        //cout << sc << " " << 0.4*sC << " " << si << " " << endl;

        if(si >= 0.25*sc and si < sc and si >= 0.25*sC and si < sC and rat < 2){
            it->x = int(fmin(it->x, r.x));
            it->y = int(fmin(it->y, r.y));
            it->width = int(fmax(it->x+it->width, r.x+r.width)) - it->x;
            it->height = int(fmax(it->y+it->height, r.y+r.height)) - it->y;

            return true;
        }
    }

    return false;
}

bool same(Rect r, vector<Rect> rois){

    int wc = r.width;
    int hc = r.height;

    double sc = wc*hc;

    for(vector<Rect>::iterator it = rois.begin(); it != rois.end(); ++it){
        double si = areaOfItersection(r, *it);

        int wC = (*it).width;
        int hC = (*it).height;

        double sC = wC*hC;

        double min = fmin(sC, sc);
        double max = fmax(sC, sc);
        double rat = max/min;

        //cout << sc << " " << sC << " " << si << " " << endl;

        if(si > 0.75*min and rat < 2) return true;
    }

    return false;
}

struct byArea {
    bool operator () (const Rect & a,const Rect & b) {
        return fmax(a.width,a.height) > fmax(b.width,b.height);
    }
};

uchar getRegions(MSER_param params, uchar preflags, Mat& src, vector<Rect>& rois){
    Mat cpy;

    src.copyTo(cpy);
    prefilter(preflags, src, cpy);

    cv::Ptr<cv::MSER> mser_extractor = cv::MSER::create(params.delta, params.min_area, params.max_area, params.max_variation, params.min_diversity);
    std::vector<std::vector<cv::Point> > msers;
    std::vector<cv::Rect> boxes, aux;
    std::vector<cv::Rect>::iterator itaux;

    mser_extractor->detectRegions(src, msers, boxes);

    //std::sort(boxes.begin(), boxes.end(), byArea());

    //cout << boxes.size() << endl;

    itaux = boxes.begin();
    for(vector<std::vector<cv::Point> >::iterator it = msers.begin(); it != msers.end(); ++it){

        if(isRoi(*it, cpy)){
            int w, h, wh;
            w = itaux->width;
            h = itaux->height;

            if (w > h) {
                wh = w - h;
                itaux->y = fmax(itaux->y - wh/2, 0);
                itaux->y + w >= cpy.rows ? itaux->height = cpy.rows - itaux->y - 1 : itaux->height = w;
            } else {
                wh = h - w;
                itaux->x = fmax(itaux->x - wh/2, 0);
                itaux->x + h >= cpy.cols ? itaux->width = cpy.cols - itaux->x - 1 : itaux->width = h;
            }
            if(!same(*itaux, rois)) rois.push_back(*itaux);

        }
        ++itaux;

    }

    /*std::sort(aux.begin(), aux.end(), byArea());

    for(vector<Rect>::iterator it = aux.begin(); it != aux.end(); ++it){
        int w, h, wh;
        w = it->width;
        h = it->height;

        if (w > h) {
            wh = w - h;
            it->y = fmax(it->y - wh/2, 0);
            it->y + w >= cpy.rows ? it->height = cpy.rows - it->y - 1 : it->height = w;
        } else {
            wh = h - w;
            it->x = fmax(it->x - wh/2, 0);
            it->x + h >= cpy.cols ? it->width = cpy.cols - it->x - 1 : it->width = h;
        }

        if(!same(*it, rois)) rois.push_back(*it);
    }

    /*cout << "AQUI" << endl;

    for(vector<Rect>::iterator it = rois.begin(); it != rois.end(); ++it){
        same(*it, rois);
    }*/

    //rois = boxes;

    return 0;
}

