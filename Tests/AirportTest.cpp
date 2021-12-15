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

   Date d1("2021-12-15 07:30");
   Date d2("2021-12-15 06:30");
   Date d3("2021-12-15 05:30");
   Date d4("2021-12-15 04:30");
   Date d5("2021-12-15 03:30");
   Date d6("2021-12-15 02:30");
   Date d7("2021-12-15 01:30");
   Date d8("2021-12-15 15:40");
   Date d9("2021-12-15 15:35");
   Date d10("2021-12-15 00:30");

   vector<Date> schedule1, schedule2;
   schedule1.push_back(d1);
   schedule1.push_back(d2);
    schedule1.push_back(d3);
    schedule1.push_back(d4);
    schedule1.push_back(d5);
    schedule1.push_back(d6);
    schedule1.push_back(d7);

    schedule2.push_back(d8);
    schedule2.push_back(d9);
    schedule2.push_back(d10);

   LandTransport l1={TRAIN, 10, schedule1};
   LandTransport l2={SUBWAY, 25, schedule2};

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
