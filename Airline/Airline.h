//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRLINE_H
#define PLUTOAIRLINES_AIRLINE_H

#include "Airplane.h"
#include "Airport.h"
#include <iostream>

using namespace std;

class Airline {
    vector<Airplane> airplanes;
    vector<Airport> airports;
    vector<Flight> flights;

public:
    Airline() = default;

    /**
     * Set Airline's airplanes
     * @param airplanes
     */
    void setAirplanes(vector<Airplane> airplaneS);

    /**
     * Set Airline's airport
     * @param airports
     */
    void setAirports(vector<Airport> airportS) {this->airports=airportS;};

    /**
     * Add airplane
     * @param airplane
     */
    void addAirplane(Airplane& airplane);

    /**
     * Add airport
     * @param airport
     */
    void addAirport(const Airport& airport);


    /**
     * Get Airline's airplanes
     * @return
     */
    vector<Airplane> getAirplanes() {return airplanes;};

    /**
     * Get Airline's airport
     * @return
     */
    vector<Airport> getAirports() {return airports;};

    /**
     * Update Airline next planned flights
     */
    void updateFlights();

    /**
     * Update Airline next planned flights
     * @param Airplane
     */
    void updateFlights(Airplane &a);

    /**
     * Filter flights from X
     * @param code
     * @return
     */
    vector<Flight> filterFromX(string code);

};


#endif //PLUTOAIRLINES_AIRLINE_H
