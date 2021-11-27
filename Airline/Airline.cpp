//
// Created by john on 27/11/21.
//

#include "Airline.h"

Airline::Airline() = default;

void Airline::setAirplanes(vector<Airplane> Airplanes) {
    this->airplanes = Airplanes;
}

vector<Airplane> Airline::getAirplanes() {
    return airplanes;
}
