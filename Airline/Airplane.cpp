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

void Airplane::setFlights(list<Flight> flights) {
    this->flights = flights;
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
