#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Airline/Airline.h"
#include <string>
#include "performance.h"

using testing::Eq;


TEST(airline_1, a_setAirplanes){
    cout<<endl<<"Testing 'setAirplanes'"<<endl;
    Airline Pluto;

    EXPECT_EQ(0, Pluto.getAirplanes().size());

    Airplane a1("Dora", "A1234", 120);
    Airplane a2("Josefina", "B1234", 1200);
    Airplane a3("Alberto", "A3234", 200);
    Airplane a4("Paulo", "C1234", 150);
    Airplane a5{};

    vector<Airplane> airplanes;

    airplanes.push_back(a1);
    airplanes.push_back(a2);
    airplanes.push_back(a3);

    Pluto.setAirplanes(airplanes);

    EXPECT_EQ(3, Pluto.getAirplanes().size());

    airplanes.clear();
    airplanes = Pluto.getAirplanes();

    EXPECT_EQ(3, airplanes.size());

    if (airplanes.size()==3) {
        Airplane t = airplanes.front();
        EXPECT_EQ(120, t.getCapacity());
        t = airplanes.back();
        EXPECT_EQ("A3234", t.getType());
    }


    Airline Pluto2;

    a5.setPlate("Quim Roscas");
    a5.setType("D1232");
    a5.setCapacity(250);

    airplanes.clear();
    EXPECT_EQ(0, airplanes.size());

    airplanes.push_back(a4);
    airplanes.push_back(a5);
    Pluto2.setAirplanes(airplanes);

    EXPECT_EQ(2, Pluto2.getAirplanes().size());

    airplanes.clear();
    airplanes = Pluto2.getAirplanes();

    if(airplanes.size()==2) {
        Airplane t = airplanes.back();
        EXPECT_EQ("D1232", t.getType());
        EXPECT_EQ(250, t.getCapacity());
    }

}