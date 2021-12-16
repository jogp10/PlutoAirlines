//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_PASSENGER_H
#define PLUTOAIRLINES_PASSENGER_H


#include "Ticket.h"

class Passenger {
    Ticket ticket;

public:
    Passenger() = default;
    /**
     *
     * @param ticket
     */
    explicit Passenger(Ticket ticket);
    /**
     * Buy the ticket if posible
     * @param ticket
     * @return
     */
    bool buyTicket(Ticket& ticket);
private:
    /**
     * Check if there is available seats at airplane
     * @param ticket
     * @return
     */
    bool canBuyTicket(const Ticket& ticket) const;
};


#endif //PLUTOAIRLINES_PASSENGER_H
