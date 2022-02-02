#pragma once

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



#include "main.hpp"
#include "key.hpp"
#include "key_factory.hpp"

#include <sstream>
#include <iostream>
#include <string>

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
    object ar { 
        released after short
    }
     object aar { 
        released after long
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

    Key &a_button = *(Key_factory::get_instance().create(KEY_CLASS_ID));
    Key &b_button = *(Key_factory::get_instance().create(KEY_CLASS_ID));
    Key &c_button = *(Key_factory::get_instance().create(KEY_CLASS_ID));
    Key &d_button = *(Key_factory::get_instance().create(KEY_CLASS_ID));

    Keyboard()
    {
        populate_with_keys();
    };
    Keyboard(const Keyboard&);
    Keyboard& operator=(const Keyboard&);
    ~Keyboard(){};

    size_t populate_with_keys();

    public:

    static Keyboard& get_instance()
    {
        static Keyboard obj;
        return obj;
    }
    //****************


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