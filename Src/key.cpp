#include "key.hpp"
#include "key_factory.hpp"
#include <cassert>
#include "aux.hpp"



/// @brief create anonymous namespace to isolate names in accordance with factory pattern 
namespace
{


    /// @brief artificial syntax construction just to call registration function
    const bool key_creation_callback_registered = 
        Key_factory::get_instance().register_creation_callback(
            KEY_CLASS_ID, 
            []()->Key*
            {return new Key;}
        );

    

} // namespace

/// @brief Binds button to gpio pin
/// @param pin - the pin to bind the button to
bool Key::bind_pin(gpio_num_t pin)
{
    key_pin = pin;
    gpio_set_direction(key_pin, GPIO_MODE_INPUT);

    return true;
}


/// @brief renewes the current state of the key
/// @returns current system tick counter value
size_t Key::check_state()
{
    size_t current_system_tick = xTaskGetTickCount();
    assert(current_system_tick > 0);
    assert(current_system_tick > ticks);
    
    key_state_t current_key_press_state;

    if(gpio_get_level(key_pin) == 0)
    {
        if(key_pin == S4_PIN)
        {
            current_key_press_state = RELEASED;   // released
        }
        else
        {
            current_key_press_state = PRESSED;   // pressed
        }
    }
    else
    {
        if(key_pin == S4_PIN)
        {
            current_key_press_state = PRESSED;   // pressed
        }
        else
        {
            current_key_press_state = RELEASED;   // released
        }
            
    }

    if(current_key_press_state == PRESSED)
    {
        key_state = PRESSED;
        count_ms += (current_system_tick - ticks);
    }
    else
    {
        if(key_state == PRESSED)
        {
            key_state = RELEASED;
        }
        else if(key_state == RELEASED)
        {
            key_state = INACTIVE;
            count_ms = 0;
        }
    }

    ticks = current_system_tick;
    return ticks;
    
}