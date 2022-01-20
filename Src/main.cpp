// doxygen documentation
#include "doxygen_mainpage.cpp"

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

#include "thermometry.hpp"
#include "utilities.hpp"


#include "space_transformer.hpp"



using namespace cv;
using namespace std;


//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************

#include "Key.hpp"

int main( int argc, const char** argv )
{

    Key<GPIO_NUM_0>& key0_ref =  Key<GPIO_NUM_0>::get_instance();
    key0_ref.increment_count();
    cout << endl << key0_ref.get_count() << endl;
    key0_ref.increment_count();
    cout << key0_ref.get_count() << endl;
    key0_ref.increment_count();
    cout << key0_ref.get_count() << endl;

    Key<GPIO_NUM_7>& key7_ref =  Key<GPIO_NUM_7>::get_instance();
    key7_ref.increment_count();
    cout << endl << key7_ref.get_pin() << endl;
    key7_ref.increment_count();
    cout << key7_ref.get_count() << endl;
    key7_ref.increment_count();
    cout << key7_ref.get_count() << endl;

    Key<key_pins_t::pins[0]>& key1_ref = Key<key_pins_t::pins[0]>::get_instance();
    cout << endl << key1_ref.get_pin() << endl;
    cout << typeid(Key<key_pins_t::pins[0]>).name() << endl;

    Key<key_pins_t::pins[1]>& key2_ref = Key<key_pins_t::pins[1]>::get_instance();
    cout << endl << key2_ref.get_pin() << endl;
    cout << typeid(Key<key_pins_t::pins[1]>).name() << endl;

    Key<key_pins_t::pins[2]>& key3_ref = Key<key_pins_t::pins[2]>::get_instance();
    cout << endl << key3_ref.get_pin() << endl;
    cout << typeid(Key<key_pins_t::pins[2]>).name() << endl;

    Key<key_pins_t::pins[3]>& key4_ref = Key<key_pins_t::pins[3]>::get_instance();
    cout << endl << key4_ref.get_pin() << endl;
    cout << typeid(Key<key_pins_t::pins[3]>).name() << endl;
    

    /*
    for(const auto& element: key_pins_t)
    {
        Key<element>& key_ref = Key<element>::get_instance();
        cout << endl << key_ref.get_pin() << endl;
        cout << typeid(Key<element>).name() << endl;
    }
    */

    waitKey();
    
    /*
    int threshold_value = 141;
    if(argc > 1)
    {
        sscanf(argv[1], "%d", &threshold_value);
    }
    int threshold_type = 0;
    //0: Binary
    //1: Binary Inverted
    //2: Threshold Truncated
    //3: Threshold to Zero
    //4: Threshold to Zero Inverted
    
    int const max_value = 255;
    int const max_type = 4;
    int const max_binary_value = 255;
    Mat src, src_gray, dst;

    const String window_name = "picture";
    
    namedWindow(window_name, WINDOW_NORMAL);
    
    src = imread("data/tuman.jpg", IMREAD_COLOR);

    imshow(window_name, src);
    waitKey(2000);

    src_gray = imread("data/tuman.jpg", IMREAD_GRAYSCALE);
    imshow(window_name, src_gray);
    imwrite("data/tuman_grayscale.jpg", src_gray);
    waitKey(2000);

    threshold( src_gray, dst, threshold_value, max_binary_value, threshold_type );
    imshow(window_name, dst);
    imwrite("data/tuman_bw.jpg", dst);
    waitKey(2000);

    uint picture_width = src.cols;
    uint picture_height = src.rows;
    
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
    
    imshow(window_name, src);
    imwrite("data/tuman_red.jpg", src);

    cout << "picture " << picture_height << " x " << picture_width << endl;

    Window_frame window_frame;
    window_frame.window_name = window_name;
    window_frame.frame = src_gray;
    setMouseCallback(window_name, onMouse, (void *)(&window_frame));

    
    waitKey();
    */

   return 0;
}



//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************
//*****************************************************************************************


