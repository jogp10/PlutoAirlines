//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_PASSENGER_H
#define PLUTOAIRLINES_PASSENGER_H


#include "Ticket.h"

class Passenger {
    int group;
    Luggage luggage;


    /**
     * Meaning of Passenger
     * @param ticket
     * @param group
     * We need to know if the passenger has/can buy a Ticket based on available seats and point out whether he has a
     * group or is travelling alone;
     * If he is travelling alone, the value of group should be zero, otherwise it must be group number
     */
    Passenger(Ticket ticket, int luggagE = 0, int group = 0);

};


#endif //PLUTOAIRLINES_PASSENGER_H
