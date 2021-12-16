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
    Airplane a1;
    EXPECT_EQ("", a1.getPlate());

    a1.setCapacity(295);
    a1.setType("A310");
    a1.setPlate("José");

    EXPECT_EQ("José", a1.getPlate());
    EXPECT_EQ("A310", a1.getType());
    EXPECT_NE(300, a1.getCapacity());

    Flight f1(00365, "2022-12-03 14:53:00", "Miami", "Porto", 480);
    Flight f2(00366, "2022-12-03 14:50:00", "Lisbon", "Porto", 450);
    Flight f3;
    f3.setArrivalLocal("Lisbon");
    f3.setDepartureDate("2021-12-07 16:30:00");
    f3.setDepartureLocal("New York");
    f3.setFlightDuration(1280);


    list<Flight> flights;
    flights.insert(flights.end(), f1);
    flights.insert(flights.end(), f2);
    flights.insert(flights.end(), f3);

    a1.setFlights(flights);
    list<Flight> flightsTest = a1.getFlights();

    EXPECT_EQ(flightsTest.size(), 2);
    auto itr = flightsTest.begin();
    EXPECT_EQ(00365, itr->getFLightNum());
    itr++;
    EXPECT_EQ(Date("2022-12-03 14:50:00"), itr->getDepartureDate());

    EXPECT_EQ(295, flightsTest.front().getAvailableSeat());

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

    EXPECT_EQ(servicesTest.front().type, MAINTENANCE);
    EXPECT_EQ(servicesDoneTest.front().name, "José Alberto");
    EXPECT_EQ(servicesDoneTest.front().type, CLEAN);

}