//
// Created by john on 27/11/21.
//

#include "Airline.h"

Airline::Airline() = default;

void Airline::addAirplane(const Airplane& airplane) {
    airplanes.push_back(airplane);
}

void Airline::addAirport(const Airport& airport) {
    airports.push_back(airport);
}
