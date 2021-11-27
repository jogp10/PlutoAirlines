//
// Created by john on 27/11/21.
//

#include "Airline.h"

Airline::Airline() = default;

void Airline::setAirplanes(list<Airplane> Airplanes) {
    this->airplanes = Airplanes;
}

list<Airplane> Airline::getAirplanes() {
    return airplanes;
}
