//
// Created by why_should some1 be gae on 27/11/21.
//

#include "Airplane.h"
#include <iostream>

using namespace std;

Airplane::Airplane(string plate, int capacity) {
    this->plate = plate;
    this->capacity = capacity;
}

void Airplane::setPlate(const string &platE) {
    this->plate = platE;
}

void Airplane::setCapacity(const int &capacitY) {
    this->capacity = capacitY;
}

void Airplane::setFlights(const list<Flight>& flightS) {
    for(const auto& flight: flightS)
    {
        this->flights.insert(flights.end(), 1, flight);
    }
}

void Airplane::addService(const Service& service) {
    services.push(service);
}

list<Flight> Airplane::getFlights() {
    return flights;
}

string Airplane::getPlate() {
    return plate;
}

int Airplane::getCapacity() const {
    return capacity;
}

queue<Service> Airplane::getServices() {
    while(services.front().date < flights.front().getDepartureDate())
    {
        servicesDone.push(services.front());
        services.pop();
    }
    return services;
}

queue<Service> Airplane::getPastServices() {
    return servicesDone;
}