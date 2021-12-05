//
// Created by john on 05/12/21.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Airline/Luggage.h"
#include <string>

using testing::Eq;
using namespace std;


TEST(luggage_1, a_setLuggage){
    cout<<endl<<"Testing 'Luggage'"<<endl;

    Luggage l1;

    EXPECT_FALSE(l1.haveLuggage());

    l1.setnumBags(3);

    EXPECT_TRUE(l1.haveLuggage());
    EXPECT_EQ(3, l1.getnumBags());
}
