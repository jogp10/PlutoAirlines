//
// Created by zebar on 27/11/2021.
//

#include "Ticket.h"

Ticket::Ticket(const int flightNum, int group, Luggage luggage): flightNum(flightNum), luggage(luggage), group(group){
}

void Ticket::setFlight(const Flight& flighT) {
    this->flightNum = flighT.getFLightNum();
    this->flight=flighT;
}

void Ticket::setLuggage(const Luggage& luggagE) {
    this->luggage = luggagE;
}

void Ticket::setGroup(int grouP) {
    this->group = grouP;
}

int Ticket::getFlightNum() const { return this->flightNum; }

Flight Ticket::getFlight() const {return this->flight; }

Luggage Ticket::getLuggage() const{ return this->luggage; }

int Ticket::getGroup() const{ return this->group; }




