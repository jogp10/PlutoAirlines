//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_PASSENGER_H
#define PLUTOAIRLINES_PASSENGER_H


#include "Ticket.h"

class Passenger {
    string name;
    Ticket ticket;

public:
    /**
     *
     * @param ticket
     */
    explicit Passenger(const string& name): name(name){};
    /**
     * Buy the ticket if posible
     * @param ticket
     * @return
     */
    bool buyTicket(Ticket& ticket);

    /**
     * Check if there is available seats at airplane
     * @param ticket
     * @return
     */
    static bool canBuyTicket(const Ticket& ticket) ;
};


#endif //PLUTOAIRLINES_PASSENGER_H
