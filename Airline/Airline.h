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
    vector<Flight> flights;

public:
    Airline() = default;

    /**
     * Set Airline's airplanes
     * @param airplanes
     */
    void setAirplanes(const vector<Airplane> &airplaneS);

    /**
     * Set Airline's airport
     * @param airports
     */
    void setAirports(vector<Airport> airportS) { this->airports=airportS; };

    /**
     * Add airplane
     * @param airplane
     */
    void addAirplane(Airplane& airplane);

    /**
     * Add airport
     * @param airport
     */
    void addAirport(const Airport& airport);

    /**
     * Add flight
     * @param flight
     */
    void addFlight(Flight &flight);

    /**
     * Add service
     * @param service
     */
    void addService(Service &service);

    /**
     * Add landTransport
     * @param landTransport
     */
    void addLandTransport(LandTransport &landTransport);

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


     /** Get Airline's flights
     * @return
     */
    vector<Flight> getFlights() {updateFlights(); return flights;};


    /**
     * Update Airline next planned flights
     */
    void updateFlights();


    /**
     * Filter flights from X
     * @param code
     * @return
     */
    vector<Flight> filterFromX(const string& code);

    /**
     * Filter flights to X
     * @param code
     * @return
     */
    vector<Flight> filterToX(const string& code);

    /**
     * Filter flights from date X
     * @param date
     * @return
     */
    vector<Flight> filterbyDateX(const string& date);

    /**
     * Filter flights from max duration
     * @param min
     * @return
     */
    vector<Flight> filterDuration(const int min);


    /**
     * Remove Airplane
     * @param a
     * @return
     */
    bool removeAirplane(const Airplane& a);

    /**
     * Remove flight
     * @param f
     * @return
     */
    bool removeFlight(const Flight& f);

    /**
     * Remove Airport
     * @param p
     * @return
     */
    bool removeAirport(const Airport& p);


    /**
     *
     * @return
     */
    vector<Flight> loadFlights();

    /**
     *
     * @return
     */
    vector<Airplane> loadPlanes();

    /**
     *
     * @return
     */
    vector<Airport> loadAirports();

    /**
     *
     * @return
     */
    vector<LandTransport> loadLandTransport();

    /**
     *
     * @return
     */
    vector<Service> loadServices();
};


#endif //PLUTOAIRLINES_AIRLINE_H
