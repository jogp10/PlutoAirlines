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

void Airplane::setFlights(const vector<Flight>& flightS) {
    for(auto flight: flightS)
    {
        this->flights.push(flight);
    }
}

Flight Airplane::getNextFlight() {
    return flights.front();
}

string Airplane::getPlate() {
    return plate;
}

int Airplane::getCapacity() const {
    return capacity;
}

void Airplane::addService(Service service) {
    services.push(service);
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
