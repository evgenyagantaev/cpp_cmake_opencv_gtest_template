#include <limits.h>
#include "gtest/gtest.h"

#include "Key.hpp"

namespace key_tst
{

    TEST(key_class, singleton_creation) 
    {
        Key<GPIO_NUM_0>& key0_ref =  Key<GPIO_NUM_0>::get_instance();
        key0_ref.increment_count();
        EXPECT_EQ(key0_ref.get_count(), 1);
        key0_ref.increment_count();
        EXPECT_EQ(key0_ref.get_count(), 2);
        key0_ref.increment_count();
        EXPECT_EQ(key0_ref.get_count(), 3);

        Key<GPIO_NUM_7>& key7_ref =  Key<GPIO_NUM_7>::get_instance();
        key7_ref.increment_count();
        EXPECT_EQ(key7_ref.get_pin(), 7);
        key7_ref.increment_count();
        EXPECT_EQ(key7_ref.get_count(), 2);
        key7_ref.increment_count();
        EXPECT_EQ(key7_ref.get_count(), 3);
    }




}// namespace key_tst