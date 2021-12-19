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
    int flightNum;

public:

    /**
     * Tickets
     * @param flight
     * @param luggage
     * @param group
     * Each Ticket must be related to a Flight, whether it can take Luggage and if the Ticket belongs to a
     * Passenger that is travelling with a group or not.
     */
    explicit Ticket(const int flightNum, int group = 1, Luggage luggage = Luggage(0)): flightNum(flightNum), group(group), luggage(luggage){};

    //Setters
    /**
     * Set Ticket's flight
     * @param flight
     */
    void setFlight(const Flight& flight) {this->flight=flight;};

    /**
     * Set Ticket's luggage
     * @param luggage
     */
    void setLuggage(const Luggage& luggage) {this->luggage=luggage;};

    /**
     * Set Ticket's group
     * @param group
     */
    void setGroup(int group) {this->group=group;};

    //Getters
    /**
     * Get Ticket's flight
     * @return
     */
    Flight getFlight() const {return this->flight; }

    /**
     *
     * @return
     */
    int getFlightNum() const {return flightNum;};

    /**
     * get Ticket's luggage
     * @return
     */
    Luggage getLuggage() const {return luggage;};

    /**
     * get Ticket's number of seats it represent
     * @return
     */
    int getGroup() const {return group;};
};

#endif //PLUTOAIRLINES_TICKET_H
