#pragma once

/*!
 @file
 @startuml
    interface I_Key
    {
        +get_state()
        +check_state()
        +get_count()
        +increment_count()
        +reset_count()
        +bind_pin(gpio_num_t  pin)
        +get_pin()
    }

    class Key 
    {
        -pressed
        -count_ms
        -key_pin
    }

    class Key_gpio_pins
    {
        +a_button_pin {static}
        +b_button_pin {static}
        +c_button_pin {static}
        +d_button_pin {static}
    }

    class Key_factory
    class Keyboard

    Key_factory -> Key : creates

    I_Key <|-up- Key : implements

    Keyboard --> Key_factory : order
    Keyboard --> Key : bind
    Key --> Key_gpio_pins : bind
 @enduml


*/


/// @brief integer class identificator for object production factory class
const int KEY_CLASS_ID = 1;

/*!
 @startuml
 
    

 @enduml
*/


#include "main.hpp"
#include <cstring>


class Key_gpio_pins
{
    public:

    static const gpio_num_t A_BUTTON_PIN = GPIO_NUM_34;
    static const gpio_num_t B_BUTTON_PIN = GPIO_NUM_35;
    static const gpio_num_t C_BUTTON_PIN = GPIO_NUM_36;
    static const gpio_num_t D_BUTTON_PIN = GPIO_NUM_39;
};

typedef enum 
{
    INACTIVE,
    PRESSED,
    RELEASED
}
key_state_t;



/*!
 @brief Public interface of one device key 
*/
class I_Key
{
    public:

    

    virtual key_state_t get_state() const = 0;
    virtual std::size_t check_state() = 0;
    virtual std::size_t get_count() const = 0;
    virtual std::size_t increment_count() = 0;
    virtual std::size_t reset_count() = 0;

    virtual bool bind_pin(gpio_num_t pin) = 0;
    virtual gpio_num_t get_pin() const = 0;
};

/*!
 @brief Class that represents one key of device keyboard
 @details 
    States of one key:
    1. inactive
    2. Pressed X miliseconds
    3. Released after short press
    4. released after long press


 @startuml

    caption: check state of key polling algorithm

    start

    : KEY_POLLING_PERIOD = 10 miliseconds;
    :read current system tick counter;

    if (button pressed) then (yes pressed)
        : state = PRESSED;
        : count += current system tick counter - ticks;
        
    else (not pressed)
        if (state == PRESSED) then (yes)
        : state = RELEASED;
        else
            if (state == RELEASED) then (yes)
            : state = INACTIVE;
            : count = 0;
            endif
        endif
    endif

    : ticks = current system tick counter;

    stop

 @enduml

*/
class Key: public I_Key
{
    public:

    
    private:

    size_t ticks = 0;
    key_state_t key_state = INACTIVE;
    size_t count_ms = 0;

    gpio_num_t key_pin;

    public:

    /*!
    @defgroup interface_implementation This module implements interface I_Key
    @{ 
    */

    virtual key_state_t get_state() const
    {
        return key_state;
    };

    virtual std::size_t check_state();

    virtual std::size_t get_count() const
    {
        return count_ms;
    };

    virtual std::size_t increment_count()
    {
        count_ms++;
        return count_ms;
    };

    virtual std::size_t reset_count()
    {
        count_ms = 0;
        return count_ms;
    };

    virtual bool bind_pin(gpio_num_t pin);

    virtual gpio_num_t get_pin() const
    {
        return key_pin;
    };

    /*! @} */

};