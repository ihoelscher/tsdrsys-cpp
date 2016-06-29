#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <ctime>
#include <string>
#include <opencv2/imgproc.hpp>
#include <cmath>
#include <queue>
#include <list>

using namespace cv;
using namespace std;

float zmf(float x, float a, float b);
float smf(float x, float a, float b);
uchar trapmf(uchar x, uchar limits[4]);

typedef struct pixel{
    int x;
    int y;
}Pixel;


int main( int argc, char** argv )
{
    string imageName("POA-01.jpg"); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }
    Mat img;
    img = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
    if( img.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    clock_t total = 0;
    for(int t = 0; t < 1000; t++) {
        clock_t begin = clock();

        Mat hsv;
        cvtColor(img, hsv, COLOR_BGR2HSV);

        uchar reda[2] = {4, 14};
        uchar redb[2] = {168, 176};
        uchar sat[2] = {255 / 4, 255 / 2};

        float rra;
        float rrb;
        float ss;

        Mat mask(hsv.rows, hsv.cols, CV_8UC1, Scalar(0));
        uchar fzval[hsv.rows][hsv.cols];

        Pixel seeds[hsv.rows * hsv.cols];
        int nseeds = 0;

        for (int x = 0; x < img.rows; x++) {
            for (int y = 0; y < img.cols; y++) {
                rra = zmf(hsv.at<Vec3b>(x, y).val[0], reda[0], reda[1]);
                rrb = smf(hsv.at<Vec3b>(x, y).val[0], redb[0], redb[1]);
                ss = smf(hsv.at<Vec3b>(x, y).val[1], sat[0], sat[1]);
                //mask.at<uchar>(x, y) = (uchar)(255*(rra+rrb)*ss);
                fzval[x][y] = (uchar) (255 * (rra + rrb) * ss);
                if (fzval[x][y] == 255) {
                    seeds[nseeds].x = x;
                    seeds[nseeds++].y = y;
                }
            }
        }

        Pixel aux;

        queue<Pixel> q;

        uchar visited[hsv.rows][hsv.cols];
        memset(visited, 0, sizeof(visited));

        int rmin, cmin, rmax, cmax;

        // np;

        uchar flag;

        for (int i = 0; i < nseeds; i++) {
            if (!visited[seeds[i].x][seeds[i].y]) {
                q.push(seeds[i]);
                //            np = 0;

                list<Pixel> topaint;

                while (!q.empty()) {
                    aux = q.front();
                    topaint.push_back(aux);
                    q.pop();

                    visited[aux.x][aux.y] = 1;
                    aux.x - 1 >= 0 ? rmin = aux.x - 1 : rmin = 0;
                    aux.x + 1 < hsv.rows ? rmax = aux.x + 1 : rmin = aux.x;

                    aux.y - 1 >= 0 ? cmin = aux.y - 1 : cmin = 0;
                    aux.y + 1 < hsv.cols ? cmax = aux.y + 1 : cmax = aux.y;

                    for (int x = rmin; x <= rmax; x++) {
                        for (int y = cmin; y <= cmax; y++) {
                            if (!visited[x][y] && fzval[x][y] > 20) {
                                //cout << "OIE";
                                aux.x = x;
                                aux.y = y;
                                q.push(aux);
                                topaint.push_back(aux);
                                /*else if(!flag){
                                    for (list<Pixel>::const_iterator it = topaint.begin(); it != topaint.end(); ++it) {
                                        mask.at<uchar>((*it).x, (*it).y) = 255;
                                    }
                                    flag = 1;
                                    topaint.clear();
                                }else{
                                    mask.at<uchar>(aux.x, aux.y) = 255;
                                }*/
                                visited[x][y] = 1;
                            }
                        }
                    }
                }

                if (topaint.size() >= 80 && topaint.size() <= 9680) {
                    for (list<Pixel>::const_iterator it = topaint.begin(); it != topaint.end(); ++it) {
                        mask.at<uchar>((*it).x, (*it).y) = 255;
                    }
                }
            }
        }

        clock_t end = clock();
        total += end - begin;
    }
    double elapsed_secs = (double(total) / CLOCKS_PER_SEC)/1000.;

    cout <<  "Tempo: " << elapsed_secs << std::endl ;

    /*namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", mask);                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window*/


    return 0;
}

uchar trapmf(uchar x, uchar limits[4]){

    if(x < limits[0] || x > limits[3]) return 0; // 0, x <= a or d <= x
    else if(x >= limits[1] && x <= limits[2]) return 255; // 1, b <= x <= c
    else return x >= limits[3] ? (uchar)255 * (limits[3] - x) / (limits[3] - limits[2]) : (uchar)255 * (x - limits[0]) / (limits[1] - limits[0]);
}

float zmf(float x, float a, float b){
    float y, m, bb;

    m = (a+b)/2.;

    if(x <= a) y = 1;

    else if(x >= b) y = 0;

    else if(x <= m){
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

float smf(float x, float a, float b){
    float y, m, bb;

    m = (a+b)/2.;

    if(x<=a)
        y = 0;
    else if(x >= b)
        y = 1;
    else if(x <= m){
        bb = (x - a)/(b - a);
        y = 2 * pow(bb, 2);
    }else{
        bb = (x - b)/(b - a);
        y = 1 - 2 * pow(bb, 2);
    }

    return(y);
}