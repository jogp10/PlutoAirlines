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
    string plate, type;
    int capacity;
    list<Flight> flights;
    list<Service> servicesDone;
    queue<Service> services;

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
    explicit Airplane(string plate, string type, int capacity);


    /**
     * Set Airplane's plate
     * @param plate
     */
    void setPlate(const string& platE);


    /**
     *  Set Airplane's type
     * @param typE
     */
    void setType(const string& typE);

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
     * Add new Flight to Travel plan
     * @param flight
     */
    void addFlight(const Flight &flight);


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
     * Get Airplane's type
     * @return
     */
    string getType();


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
    list<Service> getPastServices();
};


#endif //PLUTOAIRLINES_AIRPLANE_H
