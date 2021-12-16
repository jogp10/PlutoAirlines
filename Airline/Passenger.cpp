//
// Created by zebar on 27/11/2021.
//

#include "Passenger.h"

Passenger::Passenger(Ticket ticket) {
    buyTicket(ticket);
}

bool Passenger::canBuyTicket(const Ticket& tickeT) const {
    if(tickeT.getFlight().getAvailableSeat() >= tickeT.getGroup()) {
        return true;
    }
    else return false;
}

bool Passenger::buyTicket(Ticket& tickeT) {
    if(!canBuyTicket(tickeT)) return false;
    this->ticket = tickeT;
    ticket.getFlight().minusAvailableSeats(ticket.getGroup(), this->ticket.getLuggage());
    return true;
}