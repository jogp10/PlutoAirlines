//
// Created by zebar on 01/12/2021.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "../Airline/Ticket.h"
#include "../Airline/Airplane.h"

using testing::Eq;

TEST(test_1, TicketTest) {
    Ticket t1;

    Airplane a1("Albeto", "A360", 320);

    Flight f6(1234, "2022-03-03 12:45", "Porto", "Lisbon", 35, "Alberto");
    a1.addFlight(f6);
    Ticket t2(f6, 3);
    t2.getGroup();
    EXPECT_EQ(t2.getLuggage().getnumBags(), 0);
    EXPECT_EQ(t2.getFlight().getFLightNum(), 1234);
    EXPECT_FALSE(t2.getLuggage().haveLuggage());

    t1.setFlight(f6);
    //EXPECT_EQ(t1.getFlightNum().getAvailableSeat(), f6.getAvailableSeat());
}
