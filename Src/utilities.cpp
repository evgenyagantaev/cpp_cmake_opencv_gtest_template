#include "utilities.hpp"


bool draw_cross(cv::Mat img, int j, int i, uint8_t brightness)
{
    bool success = false;

    if((i>2) && (j>2) && (i<(img.rows - 3)) && (j<(img.cols - 3)))
    {
        //img->at<uchar>(i,j) = brightness;
        img.at<uchar>(i-1,j) = brightness;
        img.at<uchar>(i-2,j) = brightness;
        img.at<uchar>(i-3,j) = brightness;
        img.at<uchar>(i+1,j) = brightness;
        img.at<uchar>(i+2,j) = brightness;
        img.at<uchar>(i+3,j) = brightness;
        img.at<uchar>(i,j-1) = brightness;
        img.at<uchar>(i,j-2) = brightness;
        img.at<uchar>(i,j-3) = brightness;
        img.at<uchar>(i,j+1) = brightness;
        img.at<uchar>(i,j+2) = brightness;
        img.at<uchar>(i,j+3) = brightness;
    }

    return success;
    
}