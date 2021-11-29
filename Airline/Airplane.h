//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRPLANE_H
#define PLUTOAIRLINES_AIRPLANE_H

#include "Flight.h"
#include "Service.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Airplane {
    string plate;
    int capacity;
    list<Flight> flights;
    queue<Service> services, servicesDone;

public:
    /**
     *
     */
    Airplane() = default;


    /**
     *
     * @param plate
     * @param capacity
     */
    explicit Airplane(string plate, int capacity);


    /**
     * Set Airplane's plate
     * @param plate
     */
    void setPlate(const string& platE);


    /**
     * Set Airplane's capacity
     * @param capacity
     */
    void setCapacity(const int& capacitY);


    /**
     * Set Airplane's Travel plan
     * @param flights
     */
    void setFlights(const list<Flight>& flightS);


    /**
     * Schedule a new service for the Airplane
     * @param service
     */
    void addService(const Service& service);


    /**
     * Get Airplane's plate
     * @return
     */
    string getPlate();


    /**
     * Get Airplane's Capacity
     * @return
     */
    int getCapacity() const;


    /**
     * Get Airplane's Flight plan
     * @return list of flights
     */
    list<Flight> getFlights();


    /**
     * Get schedule services for the Airplane
     * @return
     */
    queue<Service> getServices();


    /**
     * Get Past services done on the Airplane
     * @return
     */
    queue<Service> getPastServices();
};


#endif //PLUTOAIRLINES_AIRPLANE_H
