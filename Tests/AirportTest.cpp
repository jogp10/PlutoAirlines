//
// Created by john on 15/12/21.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Airline/Airport.h"
#include <list>

using testing::Eq;


TEST(airport_1, a_setairport) {
    cout << endl << "Testing 'Airport'" << endl;
   Airport airport("Porto", "PT01");

   Hour d1("07:30");
   Hour d2("9:00");
   Hour d10("00:30");
   Hour d11("02:45");
   Hour freq("1:00");

   vector<Hour> schedule1, schedule2;
   schedule1.push_back(d1);
   schedule1.push_back(d2);

   LandTransport l1={TRAIN, 10, schedule1};
   LandTransport l2={SUBWAY, 25};
   l2.setSchedule(freq, d10, d11);

   airport.insert(l1);
   airport.insert(l2);

    EXPECT_EQ(airport.getMaxDistance().distance, l2.distance);
    EXPECT_EQ(airport.getMinDistance().distance, l1.distance);
    vector<LandTransport> answer = {l1, l2};
    EXPECT_EQ(airport.getByDistance(), answer);
    vector<LandTransport> bus = {};
    EXPECT_EQ(airport.getBus(), bus );
    vector<LandTransport> subway = {l2};
    EXPECT_EQ(airport.getSubway(), subway);
    vector<LandTransport> train = {l1};
    EXPECT_EQ(airport.getTrain(), train);

    EXPECT_EQ(airport.getNext(), l1);
}
