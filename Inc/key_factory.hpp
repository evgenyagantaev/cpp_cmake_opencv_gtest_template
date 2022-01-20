/*!
 @file
 @startuml
    
    note top of Key_factory 
        factory creates keys
        for device keyboard
        (realized as singleton)
    end note

    class Key_factory 
    {
        
        .....
        -Key_factory()
        -Key_factory(const Key_factory&)
        -Key_factory& operator=(const Key_factory&)
        -~Key_factory()
        -----
        +{static} Key_factory& get_instance()
        .....
    }

    

    
 @enduml
*/



#pragma once




class Key_factory
{

}