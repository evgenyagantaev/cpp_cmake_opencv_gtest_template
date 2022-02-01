/*!
 @file
 @startuml
    
    note top of Keyboard 
        keyboard
    end note

    class Keyboard 
    {
        .....
        -Keyboard()
        -Keyboard(const Keyboard&)
        -Keyboard& operator=(const Keyboard&)
        -~Keyboard()
        -----
        +{static} Keyboard& get_instance()
        .....
        .....
    }

    interface I_keyboard
    {

    }

    note left of Keyboard::get_instance()
        singleton
    end note

    class Key
    Interface I_Key
    I_Key <|-up- Key : implements

    I_keyboard <|-up- Keyboard : implements

    Keyboard --> Key : depends


    
 @enduml
*/

#pragma once

#include "main.hpp"
#include "key.hpp"

#include <sstream>
#include <iostream>
#include <string>
#include "cpp_pthread_lib.hpp"

#include <vector>


class I_Keyboard
{
    public:

};


/*!
 @startuml

    object a { 
        not pressed 
    }
    object A {
        short press 
    }
    object AA {
        long press
    }
    object AaA {
        double click
    }

    object keys {
        abcd
    }

    caption keyboard state word

 @enduml
*/


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

/*!
 @startuml

    caption: main loop of keyboard action thread

    start

    : KEY_POLLING_PERIOD = 10 miliseconds;
    :read current system tick counter;

    if ( (current system tick counter - saved tick counter) >= 
            KEY_POLLING_PERIOD) then (yes )

        : update keys state;
        : read current keys state;
        : assemble keyboard current state word;
        : saved tick counter = current system tick counter;
    
    endif

    stop

 @enduml

 */