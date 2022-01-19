#pragma once

#include "main.h"
#include "Key.hpp"

#include <sstream>
#include <iostream>
#include <string>
#include "cpp_pthread_lib.hpp"

#include <vector>


class I_Keyboard
{
    virtual std::vector<Key> get_keys();

};





class Keyboard: public I_Keyboard
{
    private:

    std::vector<Key> keys;

    public:

    Keyboard(gpio_num_t pin1, gpio_num_t pin2, gpio_num_t pin3, gpio_num_t pin4)
    {
        keys.push_back(Key(pin1));
        keys.push_back(Key(pin2));
        keys.push_back(Key(pin3));
        keys.push_back(Key(pin4));
        pin_setup();
    }

    virtual std::vector<Key> get_keys()
    {
        return keys;
    }

    void pin_setup();

    void keyboard_action();

};