//
// Created by zebar on 27/11/2021.
//

#ifndef PLUTOAIRLINES_TICKET_H
#define PLUTOAIRLINES_TICKET_H


#include "Flight.h"
#include "Luggage.h"

class Ticket {
    int group=1;
    Luggage luggage{};
    Flight flight{};

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
    explicit Ticket(const Flight& flight, int group = 1, Luggage luggage = Luggage(0));

    //Setters
    /**
     * Set Ticket's flight
     * @param flight
     */
    void setFlight(const Flight& flight);
    /**
     * Set Ticket's luggage
     * @param luggage
     */
    void setLuggage(const Luggage& luggage);
    /**
     * Set Ticket's group
     * @param group
     */
    void setGroup(int group);

    //Getters
    /**
     * Get Ticket's flight
     * @return
     */
    Flight getFlight() const;
    /**
     * get Ticket's luggage
     * @return
     */
    Luggage getLuggage() const;
    /**
     * get Ticket's number of seats it represent
     * @return
     */
    int getGroup() const;

};

#endif //PLUTOAIRLINES_TICKET_H
