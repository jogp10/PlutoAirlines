//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_FLIGHT_H
#define PLUTOAIRLINES_FLIGHT_H

#include <iostream>

using namespace std;

class Flight {
    int flightNum, flightDuration;
    string departureDate, departureLocal, arrivalLocal;

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
    void setFLightNum(int flightNum);
    void setDepartureDate(string departureDate);
    void setDepartureLocal(string departureLocal);
    void setArrivalLocal(string arrivalLocal);
    void setFlightDuration(int flightDuration);

    //Getters
    int getFLightNum();
    string getDepartureDate();
    string getDepartureLocal();
    string getArrivalLocal();
    int getFlightDuration();
    
};


#endif //PLUTOAIRLINES_FLIGHT_H
