//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRLINE_H
#define PLUTOAIRLINES_AIRLINE_H

#include "Airplane.h"
#include <iostream>
#include <list>

using namespace std;

class Airline {
    list<Airplane> airplanes;

public:
    /**
     * Airline constructor
     */
    Airline();

    void setAirplanes(list<Airplane> airplanes);
    list<Airplane> getAirplanes();

};


#endif //PLUTOAIRLINES_AIRLINE_H
