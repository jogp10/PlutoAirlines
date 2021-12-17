//
// Created by john on 27/11/21.
//

#include "Airline.h"

void Airline::setAirplanes(vector<Airplane> airplaneS) {
    this->airplanes=airplaneS;
    for(auto &i: airplaneS) updateFlights(i);
}


void Airline::addAirplane(Airplane& airplane) {
    updateFlights(airplane);
    airplanes.push_back(airplane);
}

void Airline::addAirport(const Airport& airport) {
    airports.push_back(airport);
}

// Merge Sort


void Airline::updateFlights() {
    flights.clear();


    for(auto &i: this->getAirplanes()){
        for(auto &j: i.getFlights()){
            flights.emplace_back(i, j);
        }
    }
}

void Airline::updateFlights(Airplane &a) {
    for(auto &i: a.getFlights()) flights.emplace_back(a, i);
}



