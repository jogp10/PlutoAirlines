//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRPLANE_H
#define PLUTOAIRLINES_AIRPLANE_H

#include "Flight.h"
#include <iostream>

using namespace std;

class Airplane {
    string plate;
    int capacity;
    list<Flight> flights;

public:
    Airplane() = default;

    /**
     * Airplane Constructor
     * @param plate
     * @param capacity
     */
    explicit Airplane(string plate, int capacity);

    /**
     * Travel plan
     * @param flights
     */
    void setFlights(list<Flight> flights);

    /**
     * Get Airplane's flights
     * @return
     */
    list<Flight> getFlights(); // Get travel plan

    /**
     * Get Airplane's plate
     * @return
     */
    string getPlate(); // Get plane's plate

    /**
     * Get Airplane's Capacity
     * @return
     */
    int getCapacity() const; // Get plane's capacity

};


#endif //PLUTOAIRLINES_AIRPLANE_H
