//
// Created by john on 27/11/21.
//

#ifndef PLUTOAIRLINES_AIRLINE_H
#define PLUTOAIRLINES_AIRLINE_H

#include "Airplane.h"
#include "Airport.h"
#include "Ticket.h"
#include "Passenger.h"
#include <iostream>

using namespace std;

class Airline {
    vector<Airplane> airplanes;
    vector<Airport> airports;
    vector<Flight> flights;

public:
    Airline() = default;

    /**
     * Add Airplane to Airline
     * @param airplane
     * @param write false to not write in file
     */
    void addAirplane(Airplane& airplane, bool write=true);

    /**
     * Add Airport to Airline
     * @param airport
     * @param write false to not write in file
     */
    void addAirport(const Airport& airport, bool write=true);

   /**
    * Add Flight to Airline and respective Airplane
    * @param flight
    * @param write false to not write in file
    */
    void addFlight(Flight &flight, bool write=true);

    /**
     * Add Service to respective Airplane
     * @param service
     * @param write false to not write in file
     */
    void addService(Service &service, bool write=true);

    /**
     * Add Ticket to respective Flight
     * @param t Ticket
     * @param p Passenger
     * @param write false to not write in file
     */
    void addTicket(Ticket &t, Passenger p=Passenger(""), bool write=true);

    /**
     * Add LandTransport to respective Airport
     * @param landTransport
     * @param write false to not write in file
     */
    void addLandTransport(LandTransport &landTransport, bool write=true);

    /**
     * Get Airline's Airplanes
     * @return vector containing Airplanes
     */
    vector<Airplane> getAirplanes() {return airplanes;};

    /**
     * Get Airline's Airports
     * @return vector containing Airports
     */
    vector<Airport> getAirports() {return airports;};

     /**
      * Get Airline's Flights
      * @return vector containing FLights
      */
    vector<Flight> getFlights() {updateFlights(); return flights;};


    /**
     * Update Airline's Flights (with Merge Sort)
     * Schedule flights are now in vector flights and sorted by departure local
     */
    void updateFlights();


    /**
     * Filter the Flights by departure local
     * @param code code of airport of departure
     * @return vector containing Flights with departure local code
     */
    vector<Flight> filterFromX(const string& code);

    /**
     * Filter the Flights by arrival local
     * @param code code of airport of arrival
     * @return vector containing Flights with arrival local code
     */
    vector<Flight> filterToX(const string& code);

    /**
     * Filter the Flights by departure date
     * @param date date of flight's departure
     * @return vector containing Flights with departure date date
     */
    vector<Flight> filterbyDateX(const string& date);

    /**
     * Filter the Flights by travel duration
     * @param max max travel duration time
     * @return vector containing Flights with time travel smaller than max
     */
    vector<Flight> filterDuration(int max);


    /**
     * Remove Airplane from Airline and his Fligts and Services
     * @param a airplane
     * @return if it existed
     */
    bool removeAirplane(const Airplane& a);

    /**
     * Remove Flight from Airline and his Tickets
     * @param f flight
     * @return if it existed
     */
    bool removeFlight(const Flight& f);

    /**
     * Remove Airport from Airline and his LandTransports and Flights
     * @param a airport
     * @return if it existed
     */
    bool removeAirport(const Airport& p);

    /**
     * Load Flights from file
     * @return the flights in database
     */
    vector<Flight> loadFlights();

    /**
     * Load Planes from file
     * @return the Planes in database
     */
    vector<Airplane> loadPlanes();

    /**
     * Load Airports from file
     * @return the airports in database
     */
    vector<Airport> loadAirports();

    /**
     * Load LandTransports from file
     * @return the landtransports in database
     */
    vector<LandTransport> loadLandTransport();

    /**
     * Load Services from file
     * @return the Services in database
     */
    vector<Service> loadServices();

    /**
     * Load Tickets from file
     * @return the tickets in database
     */
    vector<Ticket> loadTickets();

    /**
     *  Write in file of database
     * @param file file to write in
     * @param content content to write in file
     */
    static void write(const string& file, const string& content);

    /**
     * Delete from file of database
     * @param file file to delete from
     * @param del vector<string> containing the key of the elem to eliminate and number of lines that goes with the elem
     */
    static void del(const char* file, const vector<string>& del);
};


#endif //PLUTOAIRLINES_AIRLINE_H
