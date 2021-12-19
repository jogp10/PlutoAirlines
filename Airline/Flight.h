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
    * @param flightNum
    * @param departureDate
    * @param departureLocal
    * @param arrivalLocal
    * @param flightDuration
    * @param airplane_plate
    */

    Flight(int flightNum, const string& departureDate, const string& departureLocal, const string& arrivalLocal, int flightDuration, const string& airplane_plate);

    //Setters
    /**
     * Set the flight to the corresponding airplane
     * @param plate
     */
    void setAirplanePlate(string plate){airplane_plate=plate;};
    /**
     * Set Flight's number
     * @param flightNum
     */
    void setFLightNum(int flightNum);
    /**
     * Set Flight's Departure Date
     * @param departureDate
     */
    void setDepartureDate(const string& departureDate);
    /**
     * Set Flight's Departure Local
     * @param departureLocal
     */
    void setDepartureLocal(const string& departureLocal);
    /**
     * Set Flight's Arrival Local
     * @param arrivalLocal
     */
    void setArrivalLocal(const string& arrivalLocal);
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
    /**Get Flight's Airplane's plate
     * @return
     */
    string getAirplanePlate() const {return airplane_plate;};
    /**
     *  Get Flight's num
     * @return
     */
    int getFLightNum() const;
    /**
     *  Get Flight's departure date
     * @return
     */
    Date getDepartureDate() const;
    /**
     *  Get Flight's departure local
     * @return
     */
    string getDepartureLocal() const;
    /**
     *  Get Flight's arrival local
     * @return
     */
    string getArrivalLocal() const;
    /**
     *  Get Flight's travel duration
     * @return
     */
    Hour getFlightDuration() const;
    /**
     *  Get Flight's available seat (remaining seat)
     * @return
     */
    int getAvailableSeat() const;
    /**
     *  Get Flight's luggage from passengers
     * @return
     */
    list<Luggage> getLuggage() const;
    /**
     * Get Flight's total number of bags;
     * @return
     */
    int getnumTotalBags() const;
    /**
     * Compare two flights
     * @param a
     * @return
     */
    bool operator<(const Flight &a) const;

};


#endif //PLUTOAIRLINES_FLIGHT_H
