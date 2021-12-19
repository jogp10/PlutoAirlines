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


int BuyTicket(Airline airline);
/**/
int GroupSize();

int LuggageSize();

int ShowFlights(class Airline airline);
/**/


int Flights();
/**/
//int flightNum();
/**/

int AirportPassenger();
/**/

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
