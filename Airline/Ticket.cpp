//
// Created by zebar on 27/11/2021.
//

#include "Ticket.h"

Ticket::Ticket(Flight flight, Luggage luggage, int group) {
    this->flight = flight;
    this->luggage = luggage;
    this->group = group;

}

void Ticket::setFlight(Flight flight) {
    this->flight = flight;
}

void Ticket::setLuggage(Luggage luggage) {
    this->luggage = luggage;
}

void Ticket::setGroup(int group) {
    this->group = group;
}

Flight const Ticket::getFlight() { return this->flight; }

Luggage const Ticket::getLuggage() { return this->luggage; }

int const Ticket::getGroup() { return this->group; }




