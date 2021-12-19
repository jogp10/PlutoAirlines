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

    testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();


    class Airline Pluto;
    class Passenger p1("");

    Pluto.loadAirports();
    Pluto.loadLandTransport();
    Pluto.loadPlanes();
    Pluto.loadServices();
    Pluto.loadFlights();
    Pluto.loadTickets();

    int menu_choice, passenger_choice, worker_choice;

    int buy_ticket_choice, flights_show_choice, airport_passenger_choice;

    string depLocal, arrLocal, depDate;
    int maxTime;

    vector<Flight> flights_filtered;

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
                        BuyTicket(Pluto);
                        break;

                    /** Flights which is a Menu for Flights consulting */
                    case 2:
                        flights_show_choice = FlightsShow(Pluto);

                        switch (flights_show_choice) {
                            /** Filter by departure local code */
                            case 1:
                                cout << "What is the Departure Local?" << endl;
                                cin >> depLocal;

                                flights_filtered = Pluto.filterFromX(depLocal);

                                break;

                            /** Filter by arrival local code */
                            case 2:
                                cout << "What is the Arrival Local?" << endl;
                                cin >> arrLocal;

                                flights_filtered = Pluto.filterToX(arrLocal);
                                break;

                            /** Filter by departure date */
                            case 3:
                                cout << "What is the Departure Date?" << endl;
                                cin >> depDate;

                                flights_filtered = Pluto.filterbyDateX(depDate);
                                break;

                            /** Filter by time travel smaller than max */
                            case 4:
                                cout << "What is the Maximum Travel Time?" << endl;
                                cin >> maxTime;

                                flights_filtered = Pluto.filterDuration(maxTime);
                                break;

                            /** Go back to Main Menu */
                            case 0:
                                break;
                        }

                        cout << endl;
                        cout << "This are your choice of Flights:" << endl;
                        for (auto i: flights_filtered) {
                            cout << "- " << i.getFLightNum() << ", " ;
                            cout << i.getDepartureDate().getDate() << ", " ;
                            cout << i.getDepartureLocal() << ", " << i.getArrivalLocal() << ", " ;
                            cout << i.getFlightDuration().getHourMin() << ", ";
                            cout << i.getAirplanePlate() << endl;
                        }

                        break;

                    /** Airport which is a Menu for getting subways, trains and stuff */
                    case 3:
                        airport_passenger_choice = AirportPassenger();

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
                            /** Add airport */
                            case 1: {
                                break;
                            }

                            /** Add airplane */
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

                            /** Get fights */
                            case 2: {
                                break;
                            }

                            /** Get Last 20 flights */
                            case 3: {
                                break;
                            }

                            /** Add service */
                            case 4: {
                                break;
                            }

                            /** Get services */
                            case 5: {
                                break;
                            }

                            /** Get past services */
                            case 6: {
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
