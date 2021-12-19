//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_FLIGHT_H
#define PLUTOAIRLINES_FLIGHT_H

#include "Luggage.h"
#include "Date.h"
#include "Airport.h"

#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Flight {
    string airplane_plate;
    int flightNum=0;
    Hour flightDuration=Hour(1);
    Date departureDate = Date("1999-12-30 23:59");
    string departureLocal, arrivalLocal;
    int availableSeat{};
    list<Luggage> luggage{};
    int numTotalBags=0;

public:
    Flight() = default;

   /**
    *
    * @param flightNum Flight's num
    * @param departureDate departure Date
    * @param departureLocal departure local
    * @param arrivalLocal arrival local
    * @param flightDuration Flight's duration
    * @param airplane_plate Airplane plate
    */
    Flight(int flightNum, const string& departureDate, const string& departureLocal, const string& arrivalLocal, int flightDuration, const string& airplane_plate);

    //Setters
    /**
     * Set the Flight's plate
     * @param plate
     */
    void setAirplanePlate(string plate){airplane_plate=plate;};

    /**
     * Set Flight's number
     * @param flightNum
     */
    void setFLightNum(int flightNum) {this->flightNum=flightNum;};

    /**
     * Set Flight's departure Date
     * @param departureDate
     */
    void setDepartureDate(const string& departureDate) {this->departureDate = Date(departureDate);};

    /**
     * Set Flight's departure local
     * @param departureLocal
     */
    void setDepartureLocal(const string& departureLocal) {this->departureLocal=departureLocal;};
    /**
     * Set Flight's arrival local
     * @param arrivalLocal
     */
    void setArrivalLocal(const string& arrivalLocal) {this->arrivalLocal=arrivalLocal;};
    /**
     * Set Flight's Duration Time
     * @param flightDuration
     */
    void setFlightDuration(int flightDuration) {this->flightDuration=Hour(flightDuration);};
    /**
     * Set flight's max capacity
     * @param capacity
     */
    void setAvailableSeats(int capacity){availableSeat=capacity;};
    /**
     * After the buy of x tickets, will be (AvailableSeats - x) Seats Available
     * @param minus
     */
    void minusAvailableSeats(int ticketsBought, Luggage luggage = Luggage(0));

    //Getters
    /**Get Flight's Airplane's plate
     * @return
     */
    string getAirplanePlate() const {return airplane_plate;};

    /**
     *  Get Flight's num
     * @return
     */
    int getFLightNum() const {return flightNum;};

    /**
     *  Get Flight's departure date
     * @return
     */
    Date getDepartureDate() const {return departureDate;};

    /**
     *  Get Flight's departure local
     * @return
     */
    string getDepartureLocal() const {return departureLocal;};

    /**
     *  Get Flight's arrival local
     * @return
     */
    string getArrivalLocal() const {return arrivalLocal;};

    /**
     *  Get Flight's travel duration
     * @return
     */
    Hour getFlightDuration() const {return flightDuration;};

    /**
     *  Get Flight's available seat (remaining seat)
     * @return
     */
    int getAvailableSeat() const {return availableSeat;};

    /**
     *  Get Flight's luggage from passengers
     * @return
     */
    list<Luggage> getLuggage() const {return luggage;};

    /**
     * Get Flight's total number of bags;
     * @return
     */
    int getnumTotalBags() const {return numTotalBags;};

    /**
     * Compare two flights
     * @param a
     * @return
     */
    bool operator<(const Flight &a) const;
};


#endif //PLUTOAIRLINES_FLIGHT_H
