//
// Created by why_should some1 be gae on 27/11/21.
//

#include "Airplane.h"
#include <iostream>

using namespace std;

Airplane::Airplane(string plate, string type, int capacity) {
    this->plate = plate;
    this->type = type;
    this->capacity = capacity;
}

void Airplane::setPlate(const string &platE) {
    this->plate = platE;
}

void Airplane::setType(const string &typE) {
    this->type = typE;
}

void Airplane::setCapacity(const int &capacitY) {
    this->capacity = capacitY;
}

void Airplane::setFlights(list<Flight>& flightS) {
    for(auto& flight: flightS)
    {
        flight.setAvailableSeats(capacity);
        this->flights.insert(flights.end(), 1, flight);
    }
}

void Airplane::addFlight(const Flight &flight) {
    flights.insert(flights.end(), 1, flight);
}

void Airplane::addService(const Service& service) {
    services.push(service);
}

list<Flight> Airplane::getFlights(){
    updateFlights();
    return flights;
}

queue<Flight> Airplane::getLastFlights(){
    updateFlights();
    return last20flights;
}

Flight Airplane::getNextFlight() {
    updateFlights();
    Flight min = *flights.begin();
    for(auto itr=flights.begin(); itr!=flights.end(); itr++){
        if(itr->getDepartureDate()<min.getDepartureDate()) min = *itr;
    }
    return min;
}


string Airplane::getPlate() {
    return plate;
}

string Airplane::getType() {
    return type;
}


int Airplane::getCapacity() const {
    return capacity;
}

queue<Service> Airplane::getServices() {
    updateServices();
    return services;
}

list<Service> Airplane::getPastServices() {
    updateServices();
    return servicesDone;
}

void Airplane::updateServices() {
    while(services.front().date < this->getNextFlight().getDepartureDate() && !(services.empty()))
    {
        servicesDone.push_back(services.front());
        services.pop();
    }
}

void Airplane::updateFlights() {
    for(auto itr = flights.begin(); itr != flights.end(); ++itr){
        if(!(itr->getDepartureDate()<Date::getNow())) continue;
        last20flights.push(flights.front());
        if(last20flights.size()>20)last20flights.pop();
        flights.erase(itr--);
    }
}
