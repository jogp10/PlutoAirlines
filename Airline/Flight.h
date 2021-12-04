//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_FLIGHT_H
#define PLUTOAIRLINES_FLIGHT_H

#include "Luggage.h"

#include <iostream>
#include <vector>

using namespace std;


class Flight {
    int flightNum, flightDuration;
    string departureDate, departureLocal, arrivalLocal;
    int availableSeat;
    vector<Luggage> luggage;

public:

    Flight() = default;
    /**
     * Flight Constructor
     * @param flightNum
     * @param departureDate
     * @param departureLocal
     * @param arrivalLocal
     * @param flightDuration
     */
    Flight(int flightNum, string departureDate, string departureLocal, string arrivalLocal, int flightDuration);

    //Setters
    /**
     * Set Flight's number
     * @param flightNum
     */
    void setFLightNum(int flightNum);
    /**
     * Set Flight's Departure Date
     * @param departureDate
     */
    void setDepartureDate(string departureDate);
    /**
     * Set Flight's Departure Local
     * @param departureLocal
     */
    void setDepartureLocal(string departureLocal);
    /**
     * Set Flight's Arrival Local
     * @param arrivalLocal
     */
    void setArrivalLocal(string arrivalLocal);
    /**
     * Set Flight's Duration Time
     * @param flightDuration
     */
    void setFlightDuration(int flightDuration);
    /**
     * Set flight's max capacity
     * @param capacity
     */
    void setAvailableSeats(int capacity);
    /**
     * After the buy of x tickets, will be (AvailableSeats - x) Seats Available
     * @param minus
     */
    void minusAvailableSeats(int ticketsBought, Luggage luggage);


    //Getters
    int getFLightNum() const;
    string getDepartureDate();
    string getDepartureLocal();
    string getArrivalLocal();
    int getFlightDuration() const;
    int getAvailableSeat() const;
    vector<Luggage> getLuggage() const;

};


#endif //PLUTOAIRLINES_FLIGHT_H
