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

void Airplane::setFlights(const list<Flight>& flightS) {
    for(const auto& flight: flightS)
    {
        this->flights.insert(flights.end(), 1, flight);
    }
}

void Airplane::addFlight(const Flight &flight)
{
    flights.push_back(flight);
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

string Airplane::getType() {
    return type;
}


int Airplane::getCapacity() const {
    return capacity;
}

queue<Service> Airplane::getServices() {
    while(services.front().date < flights.front().getDepartureDate())
    {
        servicesDone.push_back(servicesDone.front());
        services.pop();
    }
    return services;
}

list<Service> Airplane::getPastServices() {
    return servicesDone;
}