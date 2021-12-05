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
    void minusAvailableSeats(int ticketsBought, Luggage luggage = Luggage(0));


    //Getters
    /**
     *  Get Flight's num
     * @return
     */
    int getFLightNum() const;
    /**
     *  Get Flight's departure date
     * @return
     */
    string getDepartureDate();
    /**
     *  Get Flight's departure local
     * @return
     */
    string getDepartureLocal();
    /**
     *  Get Flight's arrival local
     * @return
     */
    string getArrivalLocal();
    /**
     *  Get Flight's travel duration
     * @return
     */
    int getFlightDuration() const;
    /**
     *  Get Flight's available seat (remaining seat)
     * @return
     */
    int getAvailableSeat() const;
    /**
     *  Get Flight's luggage from passengers
     * @return
     */
    vector<Luggage> getLuggage() const;

};


#endif //PLUTOAIRLINES_FLIGHT_H
