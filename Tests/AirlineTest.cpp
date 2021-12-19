#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Airline/Airline.h"
#include <string>

using testing::Eq;


TEST(airline_1, a_setAirplanes){
    cout<<endl<<"Testing 'setAirplanes'"<<endl;
    Airline Pluto;

    EXPECT_EQ(0, Pluto.getAirplanes().size());

    Airplane a1("Dora", "A1234", 120);
    Airplane a2("Josefina", "B1234", 1200);
    Airplane a3("Alberto", "A3234", 200);
    Airplane a4("Paulo", "C1234", 150);

    vector<Airplane> airplanes;

    airplanes.push_back(a1);
    airplanes.push_back(a2);
    airplanes.push_back(a3);

    Pluto.addAirplane(a1);
    Pluto.addAirplane(a2);
    Pluto.addAirplane(a3);

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

    Airplane a5("Quim Roscas", "D1232", 250);

    airplanes.clear();
    EXPECT_EQ(0, airplanes.size());

    airplanes.push_back(a4);
    airplanes.push_back(a5);
    Pluto2.addAirplane(a4);
    Pluto2.addAirplane(a5);

    EXPECT_EQ(2, Pluto2.getAirplanes().size());

    airplanes.clear();
    airplanes = Pluto2.getAirplanes();

    if(airplanes.size()==2) {
        Airplane t = airplanes.back();
        EXPECT_EQ("D1232", t.getType());
        EXPECT_EQ(250, t.getCapacity());
    }

}

TEST(airline_2, b_ariline){
    Airline pluto;

    Airport a1("Porto", "PRT");
    Airport a2("Lisboa", "LSB");
    Airport a3("Miami", "MMI");

    Airplane aa1("Alfonso", "B360", 290);
    Airplane aa2("Jose", "B120", 350);
    Airplane aa3("Tito", "B360", 290);

    pluto.addAirport(a1);
    pluto.addAirport(a2);
    pluto.addAirport(a3);

    pluto.addAirplane(aa1);
    pluto.addAirplane(aa2);
    pluto.addAirplane(aa3);

    Flight f1(36, "2021-12-30 14:35", "PRT", "LSB", 50, "Alfonso");
    Flight f2(37, "2022-12-30 14:35", "PRT", "MMI", 50, "Jose");
    Flight f3(40, "2021-12-20 14:35", "LSB", "PRT", 50, "Tito");
    Flight f4(41, "2021-12-30 14:55", "LSB", "MMI", 50, "Alfonso");
    Flight f5(42, "2021-12-30 19:35", "MMI", "PRT", 500, "Alfonso");
    Flight f6(43, "2021-11-20 14:35", "MMI", "LSB", 480, "Tito");
    Flight f7(44, "2023-11-15 12:35", "MMI", "LSB", 520, "Jose");

    pluto.addFlight(f1);
    pluto.addFlight(f4);
    pluto.addFlight(f5);
    pluto.addFlight(f2);
    pluto.addFlight(f7);
    pluto.addFlight(f3);
    pluto.addFlight(f6);

    vector<Airport> airports = pluto.getAirports();
    vector<Airplane> airplanes = pluto.getAirplanes();
    vector<Flight> flights = pluto.getFlights();

    EXPECT_EQ(flights.size(), 6);

    EXPECT_EQ(pluto.filterFromX("PRT").size(), 2);
    pluto.removeAirport(a1);

    EXPECT_EQ(pluto.getFlights().size(), 2);
    pluto.removeFlight(f7);
    EXPECT_EQ(pluto.getFlights().size(), 1);
    EXPECT_EQ(aa2.getFlights().size(), 0);

    pluto.removeAirplane(aa1);
    EXPECT_EQ(aa1.getFlights().size(), 0);
    EXPECT_EQ(pluto.getFlights().size(), 0);

}