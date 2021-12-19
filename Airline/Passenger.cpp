//
// Created by zebar on 27/11/2021.
//

#include "Passenger.h"

bool Passenger::canBuyTicket(const Ticket& tickeT) {
    return tickeT.getFlight().getAvailableSeat() >= tickeT.getGroup();
}


bool Passenger::buyTicket(Ticket& tickeT) {
    if(!canBuyTicket(tickeT)) return false;
    this->ticket = tickeT;
    ticket.getFlight().minusAvailableSeats(ticket.getGroup(), this->ticket.getLuggage());
    return true;
}