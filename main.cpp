#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <string>
#include <cmath>
#include <queue>
#include <list>
#include <iomanip>
#include "colorseg/lookup.h"
#include "mser/mser.h"

using namespace cv;
using namespace std;

#define NIMAGES 6

#define minV 0.15*255

std::string to_string(int i, int fill)
{
    std::stringstream ss;
    ss << setfill('0') << setw(fill) << i;
    return ss.str();
}

int main( int argc, char** argv )
{

    clock_t segtime=0, msertime=0, total = clock();
    double slim[2] = {255*0.12, 255*0.5}; //12
    double rlim[4] = {4., 14., 160., 176.}; //CHINA 10, 16
    double ylim[4] = {10., 18., 24., 34.};
    double blim[4] = {106., 114., 124., 130.};

    uchar redlt[NS][NH];
    uchar yellt[NS][NH];
    uchar blult[NS][NH];

    put_table(OUTER, rlim, slim, redlt);
    put_table(INNER, ylim, slim, yellt);
    put_table(INNER, blim, slim, blult);

    total = clock() - total;
    int numreg = 0;

    int nimages;

    string imagesfolder("/home/ihoelscher/Databases/st/");
    //string redfolder("/home/ihoelscher/Databases/TSrecog/ALLIMAGES/rois/");
    //string yelfolder("/home/ihoelscher/Databases/CTSD/train/yel/fuzz2/");

    string imageName; // by default

    int a = atoi(argv[1]), b = atoi(argv[2]);

    for(nimages = a; nimages < b; nimages++){


        imageName = to_string(nimages, 5) + ".png";

        cout << imageName << endl;

        Mat img;
        img = imread(imagesfolder+imageName.c_str(), IMREAD_COLOR); // Read the file
        if( img.empty() )                      // Check for invalid input
        {
            cout <<  "Could not open or find the image" << std::endl ;
            return -1;
        }


        clock_t begin = clock();
        Mat hsv;
        cvtColor(img, hsv, COLOR_BGR2HSV);

        Mat rmask(hsv.rows, hsv.cols, CV_8UC1);
        Mat ymask(hsv.rows, hsv.cols, CV_8UC1);
        Mat bmask(hsv.rows, hsv.cols, CV_8UC1);

        int channels = hsv.channels();
        int nRows = hsv.rows;
        int nCols = hsv.cols * channels;
        if (hsv.isContinuous()) {
            nCols *= nRows;
            nRows = 1;
        }

        uchar *p;
        uchar *rm, *ym, *bm;
        for (int x = 0; x < nRows; x++) {
            p = hsv.ptr<uchar>(x);
            rm = rmask.ptr<uchar>(x);
            ym = ymask.ptr<uchar>(x);
            bm = bmask.ptr<uchar>(x);
            for (int y = 0; y < nCols; y += 3) {
                if (*(p + y + 2) > minV) {
                    rm[y / 3] = (uchar) redlt[*(p +y + 1)][*(p + y)];
                    ym[y / 3] = (uchar) yellt[*(p +y + 1)][*(p + y)];
                    bm[y / 3] = (uchar) blult[*(p +y + 1)][*(p + y)];
                }
                else {
                    rm[y / 3] = (uchar) 0;
                    ym[y / 3] = (uchar) 0;
                    bm[y / 3] = (uchar) 0;
                }
            }
        }
        segtime += clock() - begin;

        /*string redfolder("/home/ihoelscher/ClionProjects/TSDRS/images/CTSD/red/");
        string yellowfolder("/home/ihoelscher/ClionProjects/TSDRS/images/CTSD/yel/");
        //string bluefolder("/home/ihoelscher/ClionProjects/TSDRS/images/GTSDB/blu/");

        Mat g, finalr, finaly;
        vector<Mat> channelsv(3);

        g = Mat::zeros(Size(rmask.cols, rmask.rows), CV_8UC1);

        g.copyTo(channelsv[0]);
        g.copyTo(channelsv[1]);
        rmask.copyTo(channelsv[2]);

        cv::merge(channelsv, finalr);
        imwrite(redfolder+imageName, finalr);

        g.copyTo(channelsv[0]);
        ymask.copyTo(channelsv[1]);
        ymask.copyTo(channelsv[2]);
        cv::merge(channelsv, finaly);
        imwrite(yellowfolder+imageName, finaly);

        bmask.copyTo(channelsv[0]);
        g.copyTo(channelsv[1]);
        g.copyTo(channelsv[2]);
        cv::merge(channelsv, finaly);
        imwrite(bluefolder+imageName, finaly);*/


        begin = clock();
        MSER_param yparams = {.delta=1, .min_area=120, .max_area=180000, .max_variation=0.35, .min_diversity=0.9};
        MSER_param rparams = {.delta=1, .min_area=40, .max_area=50000, .max_variation=0.35, .min_diversity=0.9};
        MSER_param bparams = {.delta=1, .min_area=120, .max_area=180000, .max_variation=0.35, .min_diversity=0.9};
        uchar yfilter = ERODE; //GAUSS;// + THRESH;
        uchar rfilter = MEDIAN;//OPENING; // + THRESH;
        uchar bfilter = MEDIAN + OPENING;

        vector<Rect> rois;
        //cout << mask. << endl;
        //uchar err = getRegions(rparams, rfilter, mask, rois);
        uchar rerr = getRegions(rparams, rfilter, rmask, rois);
        uchar yerr = getRegions(yparams, yfilter, ymask, rois);
        //uchar berr = getRegions(bparams, bfilter, bmask, rois);
        msertime += clock() - begin;
        //clock_t end = clock();
        if (!yerr and !rerr) {
            int j = 0;
            //numreg += rois.size();
            //cout << rois.size() << endl;
            for (vector<Rect>::iterator it = rois.begin(); it != rois.end(); ++it) {
                //cout << (*it).x << ' ' << (*it).y << ' ' << (*it).width << ' ' << (*it).height << endl;
                /*int w, h, wh;
                w = (*it).width;
                h = (*it).height;

                if (w > h) {
                    wh = w - h;
                    (*it).y = fmax((*it).y - wh/2, 0);
                    (*it).y + w >= mask.rows ? (*it).height = mask.rows - (*it).y - 1 : (*it).height = w;
                } else {
                    wh = h - w;
                    (*it).x = fmax((*it).x - wh/2, 0);
                    (*it).x + h >= mask.cols ? (*it).width = mask.cols - (*it).x - 1 : (*it).width = h;
                }//*/

                //string roisfolder(redfolder+"rois/");
                string roisfolder(imagesfolder + "rois2/");

                imwrite(roisfolder + to_string(nimages, 0) + "-" + to_string(j, 6) + ".png", img(*it));
                j++;
            }
        }
    }
    total += segtime + msertime;

    double elapsed_secs = (double(total) / CLOCKS_PER_SEC)/(b-a);
    double segsecs = (double(segtime) / CLOCKS_PER_SEC)/(b-a);
    double msersecs = (double(msertime) / CLOCKS_PER_SEC)/(b-a);
    //int mediareg = numreg / NIMAGES;

    cout <<  "Total: " << elapsed_secs << std::endl ;
    cout <<  "Seg: " << segsecs << std::endl ;
    cout <<  "MSER: " << msersecs << std::endl ;

    /*namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", mask);                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    */

    return 0;
}