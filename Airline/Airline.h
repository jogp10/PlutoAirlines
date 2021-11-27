//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRLINE_H
#define PLUTOAIRLINES_AIRLINE_H

#include "Airplane.h"
#include <iostream>

using namespace std;

class Airline {
    vector<Airplane> airplanes;

public:
    /**
     * Airline constructor
     */
    Airline();

    void setAirplanes(vector<Airplane> airplanes);
    vector<Airplane> getAirplanes();

};


#endif //PLUTOAIRLINES_AIRLINE_H
