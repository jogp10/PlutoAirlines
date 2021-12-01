//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_TICKET_H
#define PLUTOAIRLINES_TICKET_H


#include "Flight.h"
#include "Luggage.h"

class Ticket {
    int group;
    Flight flight;
    Luggage luggage;

public:
    /**
     * Tickets
     * @param flight
     * @param luggage
     * @param group
     * Each Ticket must be related to a Flight, whether it can take Luggage and if the Ticket belongs to a
     * Passenger that is travelling with a group or not.
     */
    Ticket() = default;
    Ticket(Flight flight, Luggage luggage = Luggage(0), int group = 1);

    //Setters
    void setFlight(Flight flight);
    void setLuggage(Luggage luggage);
    void setGroup(int group);

    //Getters
    Flight getFlight();
    Luggage const getLuggage();
    int const getGroup();


};

#endif //PLUTOAIRLINES_TICKET_H
