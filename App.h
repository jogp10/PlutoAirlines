//
// Created by zebar on 16/12/2021.
//

#ifndef MAIN_CPP_APP_H
#define MAIN_CPP_APP_H

#include "Airline/Airline.h"

// --------------------------
/** Main Menu */
int menu();

// --------------------------
/** All methods related to Passenger */
int Passenger();


int BuyTicket(class Airline &airline);
/**/
int GroupSize();

int LuggageSize();

int ShowFlights(class Airline airline);
/**/


int Flights();
/**/
int FlightsShow(class Airline airline);
/**/

int AirportPassenger();
/**/
int AirportSubway(class Airline airline);

int AirportTrain(class Airline airline);

int AirportBus(class Airline airline);
/**/


// --------------------------
/** All methods related to Worker */
int Worker();

int Airline();
/**/

/**/

int Airport();
/**/

/**/

int Airplanes();
/**/

/**/

#endif //MAIN_CPP_APP_H
