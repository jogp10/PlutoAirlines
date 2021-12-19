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
    void updateServices();
    void updateFlights();
    void sortFLights(vector<Flight> &f, unsigned left, unsigned right);

public:
    /**
     *
     * @param plate
     * @param capacity
     */
    explicit Airplane(const string& plate, const string& type, int capacity);

    explicit Airplane(ifstream file);

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
     * Set Airplane's TraveFlightl plan
     * @param flights
     */
    void setFlights(vector<Flight>& flightS);


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
     * @return
     */
    string getPlate() const;


    /**
     * Get Airplane's type
     * @return
     */
    string getType() const;


    /**
     * Get Airplane's Capacity
     * @return
     */
    int getCapacity() const;


    /**
     * Get Airplane's Flight plan
     * @return list of flights
     */
    vector<Flight> getFlights();

    /**
     * Get Airplane's Last Flights
     * @return
     */
    queue<Flight> getLastFlights();

    /**
     * Get Airplane's Next Flight
     * @return
     */
    Flight getNextFlight();


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

    /**
     * Remove flight
     * @param f
     * @return
     */
    bool removeFlight(const Flight& f);

};


#endif //PLUTOAIRLINES_AIRPLANE_H
