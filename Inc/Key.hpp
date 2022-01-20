/*!
 @file
 @startuml
    interface I_Key
    {
        +get_state()
        +set_state(bool state)
        +get_count()
        +increment_count()
        +reset_count()
        +get_pin()
    }

    note top of Key 
    singleton
    end note

    class Key <gpio_num_t Key_pin>
    {
        -pressed
        -count_ms
        -key_pin
        -Key()
        -Key(const Key&)
        -Key& operator=(const Key&)
        -~Key()
        -----
        +{static} Key& get_instance()
        .....
        +get_state()
        +set_state(bool state)
        +get_count()        
        +increment_count()
        +reset_count()
        +get_pin()
    }

    I_Key <|-up- Key : implements
 @enduml
*/

#pragma once

#include "main.hpp"

#include <cstring>

/*!
 @brief 
*/

/*!
 @brief Public interface of one device key 
*/
class I_Key
{
    public:
    
    virtual bool get_state() const = 0;
    virtual void set_state(bool state) = 0;
    virtual std::size_t get_count() const = 0;
    virtual std::size_t increment_count() = 0;
    virtual std::size_t reset_count() = 0;

    virtual gpio_num_t get_pin() const = 0;
};

/*!
 @brief Class that represents one key of device keyboard
 @details 
    This is a Meyers's singleton template; parameterized by elements of gpio_num_t type: Key_pin
    which is a esp32 pin, key is hardwired to.


*/
template <gpio_num_t  Key_pin>
class Key: public I_Key
{
    private:

    bool pressed = false;
    std::size_t count_ms = 0;

    const gpio_num_t key_pin;

    Key(): key_pin{Key_pin} {};
    Key(const Key&) {};
    Key& operator=(const Key&) {};
    ~Key() {};

    public:

    /*!
    @brief Instantiates singleton object. Object is created in static memory.
    @return Returnes instantiated object reference.
    */
    static Key& get_instance()
    {
        static Key object;
        return object;
    };

    /*!
    @defgroup interface_implementation This module implements interface I_Key
    @{ 
    */

    virtual bool get_state() const
    {
        return pressed;
    };

    virtual void set_state(bool state)
    {
        pressed = state;
    };

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

    virtual gpio_num_t get_pin() const
    {
        return key_pin;
    };

    /*! @} */

};