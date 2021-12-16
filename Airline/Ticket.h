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
    Ticket() = default;
    /**
     * Tickets
     * @param flight
     * @param luggage
     * @param group
     * Each Ticket must be related to a Flight, whether it can take Luggage and if the Ticket belongs to a
     * Passenger that is travelling with a group or not.
     */
    explicit Ticket(Flight flight, int group = 1, Luggage luggage = Luggage(0));

    //Setters
    void setFlight(const Flight& flight);
    void setLuggage(const Luggage& luggage);
    void setGroup(int group);

    //Getters
    Flight getFlight() const;
    Luggage getLuggage() const;
    int getGroup() const;

};

#endif //PLUTOAIRLINES_TICKET_H
