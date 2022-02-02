#include "keyboard.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <thread>
#include <chrono>
#include <memory>
#include <sstream>


size_t Keyboard::populate_with_keys()
{
    size_t counter = 0;
    a_button.bind_pin(Key_gpio_pins::A_BUTTON_PIN);
    counter++;
    b_button.bind_pin(Key_gpio_pins::B_BUTTON_PIN);
    counter++;
    c_button.bind_pin(Key_gpio_pins::C_BUTTON_PIN);
    counter++;
    d_button.bind_pin(Key_gpio_pins::D_BUTTON_PIN);
    counter++;

    return counter;
}

size_t Keyboard::poll_keys()
{
    
}
