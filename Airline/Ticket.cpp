//
// Created by zebar on 27/11/2021.
//

#include "Ticket.h"

Ticket::Ticket(const int flightNum1, int group, Luggage luggage): flightNum(flightNum1), luggage(luggage), group(group){
}

void Ticket::setFlight(const Flight& flighT) {
    this->flight=flighT;
}

void Ticket::setLuggage(const Luggage& luggagE) {
    this->luggage = luggagE;
}

void Ticket::setGroup(int grouP) {
    this->group = grouP;
}

Luggage Ticket::getLuggage() const{ return this->luggage; }

int Ticket::getGroup() const{ return this->group; }




