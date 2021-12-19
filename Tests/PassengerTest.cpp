//
// Created by john on 16/12/21.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Airline/Passenger.h"
#include "../Airline/Airplane.h"
#include <string>

using testing::Eq;
using namespace std;


TEST(passenger_1, a_setPassenger){
    cout<<endl<<"Testing 'Passenger'"<<endl;

    Passenger p1("António");
    Airplane a1("Quim", "A1", 100);
    Flight f1(12345, "2022-23-12 14:23","Porto", "Lisbon", 145, "Quim");
    a1.addFlight(f1);
    Ticket t1(f1.getFLightNum(), 1, Luggage(2));
    EXPECT_TRUE(p1.buyTicket(t1));
    f1.minusAvailableSeats(f1.getAvailableSeat());
    Ticket t2(f1.getFLightNum());
    EXPECT_FALSE(p1.buyTicket(t2));
}