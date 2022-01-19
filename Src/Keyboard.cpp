#include "Keyboard.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <thread>
#include <chrono>
#include <memory>
#include <sstream>
#include <esp_pthread.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

#include "cpp_pthread_lib.hpp"

using namespace std;


void Keyboard::pin_setup()
{
    for(auto element: keys)
    {
        gpio_set_direction(element.get_pin(), GPIO_MODE_INPUT);
    }
}


void Keyboard::keyboard_action()
{
    print_thread_info(" keyboard action thread is started \n");

    const auto sleep_time1 = milliseconds
    {
        1
    };

    size_t counter = 0;
    while(true)
    {
        bool some_key_pressed = false;
        for(auto &key: keys)
        {
            if(gpio_get_level(key.get_pin()) == 0)
            {
                if(key.get_pin() == S4_PIN)
                {
                    key.set_state(false);   // released
                    key.reset_count();
                }
                else
                {
                    key.set_state(true);   // pressed
                    some_key_pressed = true;
                    key.increment_count();
                }
            }
            else
            {
                if(key.get_pin() == S4_PIN)
                {
                    key.set_state(true);   // pressed
                    some_key_pressed = true;
                    key.increment_count();
                }
                else
                {
                    key.set_state(false);   // released
                    key.reset_count();
                }
                 
            }

            if(some_key_pressed)
            {
                gpio_set_level(GREEN_LED, LOW);   // red led on
            }
            else
            {
                gpio_set_level(GREEN_LED, HIGH);  // red led off
            }
        }

        counter++;
        if(counter % 1000 == 0)
        {
            int key_number = 1;
            for(auto &key: keys)
            {
                if(key.get_state())
                {
                    cout << "key number " << key_number << " pressed for " << key.get_count() << " ms" << endl;
                }
                key_number++;
            }
            counter = 0;
        }

        std::this_thread::sleep_for(sleep_time1);
    }
}