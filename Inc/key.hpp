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

    class Key_factory

    Key_factory -> Key : creates

    I_Key <|-up- Key : implements
 @enduml


*/

#pragma once

#include "main.hpp"
#include <cstring>

/// @brief integer class identificator for object production factory class
const int KEY_CLASS_ID = 1;


/*!
 @brief Public interface of one device key 
*/
class I_Key
{
    public:

    virtual bool get_state() const = 0;
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

    typedef enum 
    {
        INACTIVE,
        PRESSED,
        RELEASED
    }
    key_state_t;

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

    virtual bool get_state() const
    {
        return pressed;
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