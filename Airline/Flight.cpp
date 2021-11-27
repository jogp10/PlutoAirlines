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

void Flight::setFLightNum(int flightNum) {
    this->flightNum = flightNum;
}

void Flight::setDepartureDate(string departureDate) {
    this->departureDate = departureDate;
}

void Flight::setDepartureLocal(string departureLocal) {
    this->departureLocal = departureLocal;
}

void Flight::setArrivalLocal(string arrivalLocal) {
    this->arrivalLocal = arrivalLocal;
}

void Flight::setFlightDuration(int flightDuration) {
    this->flightDuration = flightDuration;

}


int Flight::getFLightNum() {
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

int Flight::getFlightDuration() {
    return flightDuration;
}
