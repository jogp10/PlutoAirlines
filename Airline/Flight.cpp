//
// Created by zebar on 27/11/2021.
//

#include "Flight.h"

Flight::Flight(int flightNum, const string& departureDate, const string& departureLocal, const string& arrivalLocal, int flightDuration, const string& airplane_platE): flightDuration(flightDuration){
    this->flightNum = flightNum;
    this->departureDate = Date(departureDate);
    this->departureLocal = departureLocal;
    this->arrivalLocal = arrivalLocal;
    this->airplane_plate = airplane_platE;
}


void Flight::minusAvailableSeats(int ticketsBought, Luggage luggagE) {
    this->availableSeat -= ticketsBought;
    this->luggage.insert(luggage.end(), 1, luggagE);
    numTotalBags += luggagE.getnumBags();
}


bool Flight::operator<(const Flight &a) const {
    return this->getDepartureDate()<a.getDepartureDate();
}


