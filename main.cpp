#include "Airline/Airline.h"
#include "Airline/Flight.h"
#include "Airline/Airplane.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "App.h"
#include "Airline/Passenger.h"
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {

    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();


    class Airline Pluto;
    class Passenger p1("");

    Pluto.loadAirports();
    Pluto.loadLandTransport();
    Pluto.loadPlanes();
    Pluto.loadServices();
    Pluto.loadFlights();
    Pluto.loadTickets();
    Pluto.write("Populate/Airport.txt", "Pluto");
    Airline::write("Populate/Airport.txt", "Porto PRT");

    int menu_choice, passenger_choice, worker_choice;

    int buy_ticket_choice, flights_choice;

    while (true) {
        /** Initiating Menu */
        if(cin.eof()) { menu_choice = 0; }
        else { menu_choice = menu(); }

        switch (menu_choice) {
            /** Choosing if we are a passenger */
            case 1:
                passenger_choice = Passenger();

                switch (passenger_choice) {
                    /** BuyTicket which is a Menu for Ticket managing */
                    case 1:

                        buy_ticket_choice = BuyTicket(Pluto);

                        switch (buy_ticket_choice) {
                            /** Flight Number */
                            case 1:
                                break;

                            /** Flight Duration */
                            case 2:
                                break;

                            /** Departure Date */
                            case 3:
                                break;

                            /** Departure Local */
                            case 4:
                                break;

                            /** Arrival Local */
                            case 5:
                                break;

                            /** Go to Main Menu */
                            case 0:
                                break;
                        }
                        break;

                    /** Flights which is a Menu for Flights consulting */
                    case 2:
                        flights_choice = Flights();

                        switch (flights_choice) {
                            /** Flight Number */
                            case 1:
                                break;

                                /** Flight Duration */
                            case 2:
                                break;

                                /** Departure Date */
                            case 3:
                                break;

                                /** Departure Local */
                            case 4:
                                break;

                                /** Arrival Local */
                            case 5:
                                break;

                                /** Go to Main Menu */
                            case 0:
                                break;
                        }

                        break;

                    /** Airport which is a Menu for getting subways, trains and stuff */
                    case 3:
                        int airport_passenger_choice = AirportPassenger();

                        switch (airport_passenger_choice) {
                            /** Subways */
                            case 1:
                                break;

                            /** Trains */
                            case 2:
                                break;

                            /** Bus */
                            case 3:
                                break;

                            /** By Distance */
                            case 4:
                                break;

                            /** Next */
                            case 5:
                                break;

                            /** Max */
                            case 6:
                                break;

                            /** Min */
                            case 7:
                                break;

                            /** Go to Main Menu */
                            case 0:
                                break;
                        }
                        break;
                }
                break;

            /** Choosing if we are a worker */
            case 2:
                worker_choice = Worker();

                switch (worker_choice) {
                    /** Airline */
                    case 1: {
                        int airline_choice = Airline();

                        switch (airline_choice) {
                            /** Add airports */
                            case 1: {
                                break;
                            }

                            /** Add airplanes */
                            case 2: {
                                break;
                            }

                            /** Go to Main Menu */
                            case 0: {
                                break;
                            }
                        }

                        break;
                    }

                    /** Airport */
                    case 2: {
                        int airport_choice = Airport();

                        switch (airport_choice) {
                            /** Add Transport */
                            case 1: {
                                break;
                            }

                            /** Get Transport */
                            case 2: {
                                break;
                            }

                            /** Go to Main Menu */
                            case 0: {
                                break;
                            }
                        }
                        break;
                    }

                    /** Airplanes */
                    case 3: {
                        int airplanes_choice = Airplanes();

                        switch (airplanes_choice) {
                            /** Add flights */
                            case 1: {
                                break;
                            }

                            /** Set flights */
                            case 2: {
                                break;
                            }

                            /** Get fights */
                            case 3: {
                                break;
                            }

                            /** Get Last 20 flights */
                            case 4: {
                                break;
                            }

                            /** Add services */
                            case 5: {
                                break;
                            }

                            /** Get services */
                            case 6: {
                                break;
                            }

                            /** Get past services */
                            case 7: {
                                break;
                            }

                            /** Go to Main Menu */
                            case 0: {
                                break;
                            }
                        }

                        break;
                    }

                    /** Go back to Main Menu */
                    case 0: {
                        break;
                    }
                }

                break;

            /** Option default to close the app */
            default: {
                this_thread::sleep_for(chrono::seconds(2));
                return 0;
            }
        }
    }
}
