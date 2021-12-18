//
// Created by john on 04/12/21.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Airline/Airplane.h"
#include "../Airline/Date.h"
#include <list>

using testing::Eq;


TEST(airplane_1, a_setAirplane){
    cout<<endl<<"Testing 'setAirplane'"<<endl;
    Airplane a1("José", "A310", 295);

    EXPECT_EQ("José", a1.getPlate());
    EXPECT_EQ("A310", a1.getType());
    EXPECT_NE(300, a1.getCapacity());

    Flight f1(00365, "2022-12-03 14:53:00", "Miami", "Porto", 480, "José");
    Flight f2(00366, "2022-12-03 14:50:00", "Lisbon", "Porto", 450, "José");


    vector<Flight> flights;
    flights.insert(flights.end(), f1);
    flights.insert(flights.end(), f2);

    a1.setFlights(flights);
    vector<Flight> flightsTest = a1.getFlights();

    EXPECT_EQ(flightsTest.size(), 2);
    auto itr = flightsTest.begin();
    EXPECT_EQ(00366, itr->getFLightNum());
    itr++;
    EXPECT_EQ(Date("2022-12-03 14:53:00"), itr->getDepartureDate());

    EXPECT_EQ(295, flightsTest.front().getAvailableSeat());
    EXPECT_EQ(a1.getNextFlight().getFLightNum(), 00366);
    Service s1;
    s1.type = MAINTENANCE;
    s1.date = Date("2021-01-01 12:00:00");
    s1.name = "José Alberto";

    a1.addService(s1);

    Service s2;
    s2.type = CLEAN;
    s2.date = Date("2023-01-01 12:00:00");
    s2.name = s1.name;

    a1.addService(s2);
    list<Service> servicesDoneTest(a1.getPastServices());
    queue<Service> servicesTest(a1.getServices());

    EXPECT_EQ(servicesTest.front().type, CLEAN);
    EXPECT_EQ(servicesDoneTest.front().name, "José Alberto");
    EXPECT_EQ(servicesDoneTest.front().type, MAINTENANCE);

}