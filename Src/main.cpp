#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

#include "thermometry.hpp"
#include "utilities.hpp"

#include "space_transformer.hpp"



using namespace cv;
using namespace std;

//***

//Mouse callback
static void onMouse( int event, int x, int y, int, void* userInput );

//***

Mat picture = imread("tuman.jpg", IMREAD_COLOR);

int picture_width;
int picture_height;

cv::Point picture_center;

//***



//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************



int main( int argc, const char** argv )
{
    int threshold_value = 171;
    sscanf(argv[1], "%d", &threshold_value);
    int threshold_type = 0;
    /* 
    0: Binary
    1: Binary Inverted
    2: Threshold Truncated
    3: Threshold to Zero
    4: Threshold to Zero Inverted
    */
    int const max_value = 255;
    int const max_type = 4;
    int const max_binary_value = 255;
    Mat src, src_gray, dst;

    namedWindow("picture", WINDOW_NORMAL);

    src = imread("tuman.jpg", IMREAD_COLOR);

    imshow("picture", src);
    waitKey(2000);

    src_gray = imread("tuman.jpg", IMREAD_GRAYSCALE);
    imshow("picture", src_gray);
    imwrite("tuman_grayscale.jpg", src_gray);
    waitKey(2000);

    threshold( src_gray, dst, threshold_value, max_binary_value, threshold_type );
    imshow("picture", dst);
    imwrite("tuman_bw.jpg", dst);
    waitKey(2000);

     picture_width = picture.cols;
     picture_height = picture.rows;

     for(int i=0; i<picture_width; i++)
     {
         for(int j=0; j<picture_height; j++)
         {
             if(dst.at<uchar>(j,i) == 0)
             {
                 src.at<Vec3b>(j, i) = Vec3b(0, 0, 255);
             }
             else
             {
                 src.at<Vec3b>(j, i) = Vec3b(0, 0, 0);
             }
         }
     }
     imshow("picture", src);
     imwrite("tuman_red.jpg", src);

     cout << "picture " << picture_height << " x " << picture_width << endl;

     picture_center = Point((int)(picture_width/2) - 1, (int)(picture_height/2) - 1);

    setMouseCallback("picture", onMouse, &picture);

    
    waitKey();

    return 0;
}



//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************






//Mouse callback
//*
static void onMouse( int event, int x, int y, int, void* userInput )
{
    //*
    Mat *frame = (Mat *)userInput;

    if( event == EVENT_LBUTTONDOWN )
    {
        draw_cross(*frame, x, y, BLACK);
        cout << "pixel[" << y << "," << x << "] -> " << (int)frame->at<uchar>(y,x) << endl;
        // Show the result
        imshow("picture", picture);

    }
    //*/
 }
 //*/


