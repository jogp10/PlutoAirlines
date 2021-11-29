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
     *
     */
    Airline();

    /**
     * Set Airline's airplanes
     * @param airplanes
     */
    void setAirplanes(vector<Airplane> airplanes);


    /**
     * Get Airline's airplanes
     * @return
     */
    vector<Airplane> getAirplanes();
};


#endif //PLUTOAIRLINES_AIRLINE_H
