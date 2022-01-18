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

    //class Airport Miami("Miami", "MMI");
    //Pluto.removeAirport(Miami);


    int menu_choice, passenger_choice, worker_choice;

    int buy_ticket_choice, flights_show_choice, airport_passenger_choice;

    string depLocal, arrLocal, depDate;

    int maxTime;

    int airport_subway_choice, airport_train_choice, airport_bus_choice;

    vector<Flight> flights_filtered;

    string nameAirport, codeAirport, plateAirplane, typeAirplane, capacityAirplane;

    string typeTransport, distanceTransport, freqTransport, startTransport,
            endTransport, airportCodeTransport;

    string flightNum, departureDate, departureLocal, arrivalLocal,
            flightDuration, airplanePlatE;

    queue<Flight> queueFlight;

    queue<Service> queueServices;

    list<Service> listServices;

    string typeService, nameService, dateService, plateService;

    int airplane_service_choice;

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
                                airport_subway_choice = AirportSubway(Pluto);

                                cout << endl;
                                cout << "The subways are: " << endl;
                                for (auto i: Pluto.getAirports()[airport_subway_choice -1].getSubway() ) {
                                    auto itr= invtable.find(i.getTransType());
                                    cout << "- " << itr->second << ", " << i.getDistance() << ", " ;
                                    cout << i.next().getHourMin() << endl;
                                }

                                break;

                            /** Trains */
                            case 2:
                                airport_train_choice = AirportTrain(Pluto);

                                cout << endl;
                                cout << "The trains are: " << endl;
                                for (auto i: Pluto.getAirports()[airport_train_choice -1].getTrain() ) {
                                    auto itr= invtable.find(i.getTransType());
                                    cout << "- " << itr->second << ", " << i.getDistance() << ", " ;
                                    cout << i.next().getHourMin() << endl;
                                }

                                break;

                            /** Bus */
                            case 3:
                                airport_bus_choice = AirportBus(Pluto);

                                cout << endl;
                                cout << "The buses are: " << endl;
                                for (auto i: Pluto.getAirports()[airport_bus_choice -1].getBus() ) {
                                    auto itr= invtable.find(i.getTransType());
                                    cout << "- " << itr->second << ", " << i.getDistance() << ", " ;
                                    cout << i.next().getHourMin() << endl;
                                }

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
                                cout << endl;
                                cout << "What is the name of the Airport?" << endl;
                                cin >> nameAirport;
                                cout << "What is the code of the Airport?" << endl;
                                cin >> codeAirport;

                                class Airport airport(nameAirport, codeAirport);

                                Pluto.addAirport(airport);

                                break;
                            }

                            /** Add airplane */
                            case 2: {
                                cout << endl;
                                cout << "What is the plate of the Airplane?" << endl;
                                cin >> plateAirplane;
                                cout << "What is the type of the Airplane?" << endl;
                                cin >> typeAirplane;
                                cout << "What is the capacity of the Airplane?" << endl;
                                cin >> capacityAirplane;

                                class Airplane airplane(plateAirplane, typeAirplane, stoi(capacityAirplane));

                                Pluto.addAirplane(airplane);

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
                                cout << endl;
                                cout << "What is the type of the Transport?" << endl;
                                cin >> typeTransport;
                                cout << "What is the distance?" << endl;
                                cin >> distanceTransport;
                                cout << "What is the frequency of the Transport?" << endl;
                                cin >> freqTransport;
                                cout << "What is the start hour of Transport?" << endl;
                                cin >> startTransport;
                                cout << "What is the end hour of Transport?" << endl;
                                cin >> endTransport;
                                cout << "What is the airport code of this Transport?" << endl;
                                cin >> airportCodeTransport;

                                auto itr = table.find(typeTransport);
                                class LandTransport transport(itr->second, stod(distanceTransport),
                                        Hour(freqTransport), Hour(startTransport), Hour(endTransport),
                                        airportCodeTransport);

                                Pluto.addLandTransport(transport);

                                break;
                            }

                            /** Get Transport */
                            case 2: {
                                for (auto i: Pluto.getAirports()) {
                                    cout << endl;
                                    cout << "Buses: " <<  endl;
                                    for (auto j: i.getBus()) {
                                        cout << "- " << j.getTransType() << ", " << j.getDistance() << ", ";
                                        cout << j.getFreq().getHourMin() << ", " << j.getStart().getHourMin() << ", ";
                                        cout << j.getEnd().getHourMin() << ", " << j.getAirportCode() << endl;
                                    }

                                    cout << endl;
                                    cout << "Subways: " <<  endl;
                                    for (auto j: i.getSubway()) {
                                        cout << "- " << j.getTransType() << ", " << j.getDistance() << ", ";
                                        cout << j.getFreq().getHourMin() << ", " << j.getStart().getHourMin() << ", ";
                                        cout << j.getEnd().getHourMin() << ", " << j.getAirportCode() << endl;
                                    }

                                    cout << endl;
                                    cout << "Trains: " <<  endl;
                                    for (auto j: i.getTrain()) {
                                        cout << "- " << j.getTransType() << ", " << j.getDistance() << ", ";
                                        cout << j.getFreq().getHourMin() << ", " << j.getStart().getHourMin() << ", ";
                                        cout << j.getEnd().getHourMin() << ", " << j.getAirportCode() << endl;
                                    }
                                }

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
                                cout << endl;
                                cout << "What is the flight number?" << endl;
                                cin >> flightNum;
                                cout << "What is the departure date?" << endl;
                                cin >> departureDate;
                                cout << "What is the departure local?" << endl;
                                cin >> departureLocal;
                                cout << "What is the arrival local?" << endl;
                                cin >> arrivalLocal;
                                cout << "What is the flight duration?" << endl;
                                cin >> flightDuration;
                                cout << "What is the airplane plate?" << endl;
                                cin >> airplanePlatE;

                                class Flight flight(stoi(flightNum), departureDate, departureLocal,
                                        arrivalLocal, stoi(flightDuration), airplanePlatE);

                                break;
                            }

                            /** Get flights */
                            case 2: {
                                cout << endl;
                                cout << "Flights: " << endl;
                                for (auto i: Pluto.getFlights()) {
                                    cout << "- " << i.getFLightNum() << ", " << i.getDepartureDate().getDate() << ", ";
                                    cout << i.getDepartureDate().getDate() << ", " << i.getDepartureLocal() << ", ";
                                    cout << i.getArrivalLocal() << ", " << i.getFlightDuration().getHourMin() << ", ";
                                    cout << i.getAirplanePlate();
                                }

                                break;
                            }

                            /** Get Last 20 flights */
                            case 3: {
                                for (auto i: Pluto.getAirplanes()) {
                                    queueFlight = i.getLastFlights();

                                    while(!queueFlight.empty()) {
                                        cout << endl;
                                        cout << "- " << queueFlight.front().getFLightNum() << ", " ;
                                        cout << queueFlight.front().getDepartureDate().getDate() << ", ";
                                        cout << queueFlight.front().getDepartureLocal() << ", ";
                                        cout << queueFlight.front().getArrivalLocal() << ", ";
                                        cout << queueFlight.front().getFlightDuration().getHourMin() << ", ";
                                        cout << queueFlight.front().getAirplanePlate() << endl;

                                        queueFlight.pop();
                                    }
                                }

                                break;
                            }

                            /** Add service */
                            case 4: {
                                cout << "What is the type of service?" << endl;
                                cin >> typeService;
                                cout << "What is the name of service?" << endl;
                                cin >> nameService;
                                cout << "What is date of service?" << endl;
                                cin >> dateService;
                                cout << "What is the plate?" << endl;
                                cin >> plateService;

                                Service service;
                                service.type = servtable.find(typeService)->second;
                                service.name = nameService;
                                service.date = Date(dateService);
                                service.airplane_plate = plateService;

                                cout << endl;
                                cout << "Add service to what airplane?" << endl;

                                airplane_service_choice = ShowAirplanes(Pluto);

                                Pluto.getAirplanes()[airplane_service_choice -1].addService(service);

                                cout << "Service Added Successfully" << endl;

                                break;
                            }

                            /** Get services */
                            case 5: {
                                for (auto i: Pluto.getAirplanes()) {
                                    queueServices = i.getServices();

                                    while(!queueServices.empty()) {
                                        cout << endl;
                                        cout << "- " << queueServices.front().type << ", " ;
                                        cout << queueServices.front().name << ", ";
                                        cout << queueServices.front().date.getDate() << ", ";
                                        cout << queueServices.front().airplane_plate << endl;

                                        queueServices.pop();
                                    }
                                }

                                break;
                            }

                            /** Get past services */
                            case 6: {
                                for (auto i: Pluto.getAirplanes()) {
                                    listServices = i.getPastServices();

                                    for(auto i = listServices.begin(); i != listServices.end(); i++) {
                                        cout << endl;
                                        cout << "- " << i->type << ", " ;
                                        cout << i->name << ", ";
                                        cout << i->date.getDate() << ", ";
                                        cout << i->airplane_plate << endl;
                                    }
                                }

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
