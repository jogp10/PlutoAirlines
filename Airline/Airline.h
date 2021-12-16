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
    void setAirplanes(vector<Airplane> airplanes) {this->airplanes=airplanes;};

    /**
     * Set Airline's airport
     * @param airports
     */
    void setAirports(vector<Airport> airports) {this->airports=airports;};

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
