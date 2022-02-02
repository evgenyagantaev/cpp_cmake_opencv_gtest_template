#include "aux.hpp"
#include <time.h>

    

void gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode)
{}

size_t xTaskGetTickCount()
{
    clock_t cl = clock( );
    if ( cl != (clock_t)-1 )
        return (size_t)((double)cl / ((double)CLOCKS_PER_SEC / 1000.0));
    else
        return 0;
}

size_t gpio_get_level(gpio_num_t pin)
{
    return 0;
}