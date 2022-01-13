#include <limits.h>
#include "gtest/gtest.h"

#include "utilities.hpp"

namespace util_tst
{
    cv::Mat img(3, 3, CV_8U);
    int i = 0, j = 0;
    uint8_t brightness = 0;

    TEST(UtilitiesTest, Initial) 
    {
        EXPECT_TRUE(draw_cross(img, i, j, brightness));
    }




}// namespace util_tst