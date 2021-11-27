//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRPLANE_H
#define PLUTOAIRLINES_AIRPLANE_H

#include "Flight.h"
#include "Service.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Airplane {
    string plate;
    int capacity;
    queue<Flight> flights;
    queue<Service> services, servicesDone;

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
    void setFlights(const vector<Flight>& flights);

    /**
     * Get Airplane's flights
     * @return
     */
    Flight getNextFlight(); // Get travel plan

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

    /**
     * Schedule a new service for the airplane
     * @param service
     */
    void addService(Service service);

    /**
     * Get schedule services for the airplane
     * @return
     */
    queue<Service> getServices();

    /**
     * Get Past services done on the airplane
     * @return
     */
    queue<Service> getPastServices();

};


#endif //PLUTOAIRLINES_AIRPLANE_H
