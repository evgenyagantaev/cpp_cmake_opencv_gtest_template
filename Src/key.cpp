#include "key.hpp"
#include "key_factory.hpp"

/// @brief create anonymous namespace to isolate names in accordance with factory pattern 
namespace
{
    /*
    Key* create_key_obj()
    {
        return new Key;
    }
    */

    /// @brief integer class identificator for object production factory class
    const int KEY_CLASS_ID = 1;

    /// @brief artificial syntax construction just to call registration function
    const bool key_creation_callback_registered = 
        Key_factory::get_instance().register_creation_callback(
            KEY_CLASS_ID, 
            []()->Key*
            {return new Key;}
        );

} // namespace