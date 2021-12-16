//
// Created by zebar on 27/11/2021.
//

#include "Ticket.h"

Ticket::Ticket(Flight flight, int group, Luggage luggage): flight(flight), luggage(luggage), group(group){
}

void Ticket::setFlight(const Flight& flighT) {
    this->flight = flighT;
}

void Ticket::setLuggage(const Luggage& luggagE) {
    this->luggage = luggagE;
}

void Ticket::setGroup(int grouP) {
    this->group = grouP;
}

Flight Ticket::getFlight() const { return this->flight; }

Luggage Ticket::getLuggage() const{ return this->luggage; }

int Ticket::getGroup() const{ return this->group; }




