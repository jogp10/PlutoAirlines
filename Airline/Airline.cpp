//
// Created by john on 27/11/21.
//

#include "Airline.h"

Airline::Airline() {

}

void Airline::setAirplanes(list<Airplane> Airplanes) {
    this->Airplanes = Airplanes;
}

list<Airplane> Airline::getAirplanes() {
    return Airplanes;
}
