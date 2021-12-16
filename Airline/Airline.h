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

public:
    /**
     *
     */
    Airline();

    /**
     * Set Airline's airplanes
     * @param airplanes
     */
    void setAirplanes(vector<Airplane> airplaneS) {this->airplanes=airplaneS;};

    /**
     * Set Airline's airport
     * @param airports
     */
    void setAirports(vector<Airport> airportS) {this->airports=airportS;};

    /**
     * Add airplane
     * @param airplane
     */
    void addAirplane(const Airplane& airplane);

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
};


#endif //PLUTOAIRLINES_AIRLINE_H
