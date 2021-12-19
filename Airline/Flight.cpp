//
// Created by zebar on 27/11/2021.
//

#include "Flight.h"
#include "Date.h"

Flight::Flight(int flightNum, const Date departureDate, const string& departureLocal, const string& arrivalLocal, Hour flightDuration, const string& airplane_platE): flightDuration(flightDuration){
    this->flightNum = flightNum;
    Date departuredate(departureDate);
    this->departureDate = departuredate;
    this->departureLocal = departureLocal;
    this->arrivalLocal = arrivalLocal;
    this->airplane_plate = airplane_platE;
}

void Flight::setFLightNum(int flightnum) {
    this->flightNum = flightnum;
}

void Flight::setDepartureDate(const string& departuredatE) {
    Date departuredate(departuredatE);
    this->departureDate = departuredate;
}

void Flight::setDepartureLocal(const string& departurelocal) {
    this->departureLocal = departurelocal;
}

void Flight::setArrivalLocal(const string& arrivallocal) {
    this->arrivalLocal = arrivallocal;
}

void Flight::setFlightDuration(int flightduratioN) {
    Hour flightduration(flightduratioN);
    this->flightDuration = flightduration;
}

void Flight::setAvailableSeats(int capacity) {
    availableSeat = capacity;
}


int Flight::getFLightNum() const {
    return flightNum;
}

Date Flight::getDepartureDate() const{
    return departureDate;
}

string Flight::getDepartureLocal() const{
    return departureLocal;
}

string Flight::getArrivalLocal() const{
    return arrivalLocal;
}

Hour Flight::getFlightDuration() const {
    return flightDuration;
}

int Flight::getAvailableSeat() const {
    return availableSeat;
}

void Flight::minusAvailableSeats(int ticketsBought, Luggage luggagE) {
    this->availableSeat -= ticketsBought;
    this->luggage.insert(luggage.end(), 1, luggagE);
    numTotalBags += luggagE.getnumBags();
}

list<Luggage> Flight::getLuggage() const {
    return luggage;
}

int Flight::getnumTotalBags() const{
    return numTotalBags;
}

bool Flight::operator<(const Flight &a) const {
    return this->getDepartureDate()<a.getDepartureDate();
}


