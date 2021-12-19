//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_PASSENGER_H
#define PLUTOAIRLINES_PASSENGER_H


#include "Ticket.h"

class Passenger {
    string name;
    Ticket ticket{0};

public:
    /**
     *
     * @param name Name of passenger
     */
    explicit Passenger(const string& name): name(name){};

    /**
     * buy Passenger a Ticket
     * @param ticket
     * @return if purchase was a success
     */
    bool buyTicket(Ticket& ticket);

    /**
     * Check if there is available seats at airplane
     * @param ticket
     * @return true if there is available seats
     */
    static bool canBuyTicket(const Ticket& ticket) ;
};


#endif //PLUTOAIRLINES_PASSENGER_H
