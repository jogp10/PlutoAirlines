//
// Created by zebar on 27/11/2021.
//

#include "Passenger.h"

Passenger::Passenger(Ticket ticket, int luggage, int group) {
    this->group = group;
    if(canBuyTicket(ticket)) { buyTicket(ticket); }
}

bool Passenger::canBuyTicket(Ticket ticket) {
    if(ticket.getFlight().getAvailableSeat() >= this->group) {
        return true;
    }
    else return false;
}

void Passenger::buyTicket(Ticket ticket) {
    this->ticket = ticket;
    ticket.getFlight().minusAvailableSeats(group, this->ticket.getLuggage());
}