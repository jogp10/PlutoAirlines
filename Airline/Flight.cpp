//
// Created by zebar on 27/11/2021.
//

#include "Flight.h"

Flight::Flight(int flightNum, string departureDate, string departureLocal, string arrivalLocal, int flightDuration) {
    this->flightNum = flightNum;
    this->departureDate = departureDate;
    this->departureLocal = departureLocal;
    this->arrivalLocal = arrivalLocal;
    this->flightDuration = flightDuration;
}

void Flight::setFLightNum(int flightnum) {
    this->flightNum = flightnum;
}

void Flight::setDepartureDate(string departuredate) {
    this->departureDate = departuredate;
}

void Flight::setDepartureLocal(string departurelocal) {
    this->departureLocal = departurelocal;
}

void Flight::setArrivalLocal(string arrivallocal) {
    this->arrivalLocal = arrivallocal;
}

void Flight::setFlightDuration(int flightduration) {
    this->flightDuration = flightduration;

}

void Flight::setAvailableSeats(int capacity) {
    availableSeat = capacity;
}


int Flight::getFLightNum() const {
    return flightNum;
}

string Flight::getDepartureDate() {
    return departureDate;
}

string Flight::getDepartureLocal() {
    return departureLocal;
}

string Flight::getArrivalLocal() {
    return arrivalLocal;
}

int Flight::getFlightDuration() const {
    return flightDuration;
}

int Flight::getAvailableSeat() const {
    return availableSeat;
}

void Flight::minusAvailableSeats(int ticketsBought, Luggage luggagE) {
    this->availableSeat -= ticketsBought;
    this->luggage.push_back(luggagE);
}

vector<Luggage> Flight::getLuggage() const {
    return luggage;
}


