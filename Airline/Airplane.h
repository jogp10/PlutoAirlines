//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRPLANE_H
#define PLUTOAIRLINES_AIRPLANE_H


#include "Flight.h"
#include "Service.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;


class Airplane {
    string plate, type;
    int capacity{};
    queue<Flight> last20flights{};
    vector<Flight> flights;
    list<Service> servicesDone{};
    queue<Service> services;


private:
    /**
     * Update Services based on present time
     */
    void updateServices();
    /**
     * Update Flights based on present time
     */
    void updateFlights();
    /**
     * Sort Flights with QuickSort
     */
    void sortFLights(vector<Flight> &f, unsigned left, unsigned right);

public:
    /**
     *
     * @param plate plate of Airplane
     * @param type type of Airplane
     * @param capacity capacity of Airplane
     */
    explicit Airplane(const string& plate, const string& type, int capacity): plate(plate), type(type), capacity(capacity){};

    /**
     * Set Airplane's plate
     * @param plate
     */
    void setPlate(const string& plate) {this->plate=plate;};

    /**
     *  Set Airplane's type
     * @param type
     */
    void setType(const string& type) {this->type=type;};

    /**
     * Set Airplane's capacity
     * @param capacity
     */
    void setCapacity(const int& capacity) {this->capacity=capacity;};

    /**
     * Add new Flight to Travel plan
     * @param flight
     */
    void addFlight(Flight &flight);

    /**
     * Schedule a new service for the Airplane
     * @param service
     */
    void addService(Service& service);


    /**
     * Get Airplane's plate
     * @return plate
     */
    string getPlate() const {return plate;};

    /**
     * Get Airplane's type
     * @return type
     */
    string getType() const {return type;};

    /**
     * Get Airplane's Capacity
     * @return capacity
     */
    int getCapacity() const {return capacity;};

    /**
     * Get Airplane's Flight plan
     * @return vector of next Flights
     */
    vector<Flight> getFlights() {updateFlights(); return flights;};

    /**
     * Get Airplane's Last Flights
     * @return of last 20 Flights
     */
    queue<Flight> getLastFlights() {updateFlights(); return last20flights;};

    /**
     * Get Airplane's next Flight
     * @return next Flight
     */
    Flight getNextFlight() {updateFlights(); return flights[0];};

    /**
     * Get Airplane's next Services
     * @return queue of schedule services
     */
    queue<Service> getServices() {updateServices(); return services;};

    /**
     * Get past services done on the Airplane
     * @return list of services
     */
    list<Service> getPastServices() {updateServices(); return servicesDone;};

    /**
     * Remove Flight from Travel Plan
     * @param f Flight
     * @return if it existed
     */
    bool removeFlight(const Flight& f);

};


#endif //PLUTOAIRLINES_AIRPLANE_H
