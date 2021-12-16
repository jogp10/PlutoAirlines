//
// Created by zebar on 27/11/2021.
//

#include "Flight.h"

Flight::Flight(int flightNum, string departureDate, string departureLocal, string arrivalLocal, int flightDuration) {
    this->flightNum = flightNum;
    Date departuredate(departureDate);
    this->departureDate = departuredate;
    this->departureLocal = departureLocal;
    this->arrivalLocal = arrivalLocal;
    Hour flightduration(flightDuration);
    this->flightDuration = flightduration;
}

void Flight::setFLightNum(int flightnum) {
    this->flightNum = flightnum;
}

void Flight::setDepartureDate(const string& departuredatE) {
    Date departuredate(departuredatE);
    this->departureDate = departuredate;
}

void Flight::setDepartureLocal(string departurelocal) {
    this->departureLocal = departurelocal;
}

void Flight::setArrivalLocal(string arrivallocal) {
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

Date Flight::getDepartureDate() {
    return departureDate;
}

string Flight::getDepartureLocal() {
    return departureLocal;
}

string Flight::getArrivalLocal() {
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
    this->luggage.push_back(luggagE);
    numTotalBags += luggagE.getnumBags();
}

vector<Luggage> Flight::getLuggage() const {
    return luggage;
}

int Flight::getnumTotalBags() const{
    return numTotalBags;
}


