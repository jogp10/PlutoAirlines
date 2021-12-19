//
// Created by zebar on 16/12/2021.
//

#include <iostream>
#include <thread>
#include "App.h"

using namespace std;

//--------------------------
int menu() {
    int menu_choice;

    /** Main Menu interface */
    cout << endl;
    cout <<  "What are you? " << endl;
    cout << "1) Passenger" << endl;
    cout << "2) Worker" << endl;
    cout << "0) Exit" << endl;

    /** Main Menu execution (asking for menu_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> menu_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) {
            cin.ignore(10000, '\n');
        }
        if (menu_choice == 0) { return 0; }

        else if (menu_choice == 1 || menu_choice == 2 ) { return menu_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
    }
}

//--------------------------
int Passenger() {
    int passenger_choice;

    /** Passenger Menu Interface */
    cout << endl;
    cout << "1) Buy Ticket" << endl;
    cout << "2) Flights" << endl;
    cout << "3) Airport" << endl;
    cout << "0) Go Back" << endl;


    /** Passenger Menu execution (asking for passenger_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> passenger_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (passenger_choice == 0) { return 0; }
        else if (passenger_choice == 1 || passenger_choice == 2 || passenger_choice == 3) { return passenger_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1, 2 or 3 to proceed)" << endl;
    }
}

int BuyTicket(class Airline airline) {
    /** Getting group size */
    int group_size = GroupSize();

    /** Getting Luggage size */
    int numLuggage = LuggageSize();
    Luggage luggage(numLuggage);

    /** Getting flight's choice */
    int flight_choice = ShowFlights(airline);
    Flight chosen_flight = airline.getFlights()[flight_choice--];

    //Ticket(chosen_flight.getFLightNum(), );
    //addTicket;
}

int GroupSize() {
    int group_size;

    cout << "What is your goup size?" << endl;
    cout << "Choose 0 (zero) if you want to cancel operation." << endl;

    /** groupSize execution (asking for group_size) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> group_size;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (group_size == 0) { return 0; }
        else if (group_size > 0) { return group_size; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation!" << endl;
    }
}

int LuggageSize() {
    int luggage_size;

    cout << "How many luggage do you want to take with you?" << endl;
    cout << "Choose 0 (zero) if you want to cancel operation." << endl;

    /** LuggageSize execution (asking for group_size) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: ";
        cin >> luggage_size;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (luggage_size == 0) { return 0; }
        else if (luggage_size > 0) { return luggage_size; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation!" << endl;
    }
}

int ShowFlights(class Airline airline) {
    int flights_print, count = 1;
    vector<Flight> flights = airline.getFlights();

    cout << endl;
    for (const auto& i: flights) {
        cout << count << ") " << i.getFLightNum() << ", " ;
        cout << i.getDepartureDate().getDate() << ", " ;
        cout << i.getDepartureLocal() << ", " << i.getArrivalLocal() << ", " ;
        cout << i.getFlightDuration().getHourMin() << ", ";
        cout << i.getAirplanePlate() << endl;
        count++;
    }
    cout << "0) Go Back" << endl;

    /** Flights execution (asking for ticket_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> flights_print;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (flights_print == 0) { return 0; }
        else if (flights_print <= flights.size()) { return flights_print; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0 to " << flights.size() << " to proceed)" << endl;
    }
}


int Flights() {
    int flights_choice;

    /** Flights Menu Interface */
    cout << endl << "Get: " << endl;
    cout << "1) Flight Number" << endl;
    cout << "2) Flight Duration" << endl;
    cout << "3) Departure Date" << endl;
    cout << "4) Departure Local" << endl;
    cout << "5) Arrival Local" << endl;
    cout << "0) Go Back" << endl;

    /** Flights Menu execution (asking for flights_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> flights_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (flights_choice == 0) { return 0; }
        else if (flights_choice == 1 || flights_choice == 2 || flights_choice == 3 ||
                 flights_choice == 4 || flights_choice == 5) { return flights_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1, 2, 3, 4 or 5 to proceed)" << endl;
    }
}

int AirportPassenger() {
    int airport_passenger_choice;

    /** AirportPassenger Menu Interface */
    cout << endl << "Get:    " << endl;
    cout << "1) Subways" << endl;
    cout << "2) Trains" << endl;
    cout << "3) Bus" << endl;
    cout << "4) By Distance" << endl;
    cout << "5) Next" << endl;
    cout << "6) Max" << endl;
    cout << "7) Min" << endl;
    cout << "0) Go Back" << endl;

    /** AirportPassenger Menu execution (asking for airport_passenger_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> airport_passenger_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (airport_passenger_choice == 0) { return 0; }
        else if (airport_passenger_choice == 1 || airport_passenger_choice == 2 || airport_passenger_choice == 3 ||
                 airport_passenger_choice == 4 || airport_passenger_choice == 5 || airport_passenger_choice == 6 ||
                 airport_passenger_choice == 7) { return airport_passenger_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1, 2, 3, 4, 5, 6 or 7 to proceed)" << endl;
    }
}

//--------------------------
int Worker() {
    int worker_choice;

    /** Worker Menu Interface */
    cout << endl;
    cout << "1) Airline" << endl;
    cout << "2) Airport" << endl;
    cout << "3) Airplanes" << endl;
    cout << "0) Go Back" << endl;


    /** Worker Menu execution (asking for worker_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> worker_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (worker_choice == 0) { return 0; }
        else if (worker_choice == 1 || worker_choice == 2 || worker_choice == 3) { return worker_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1, 2 or 3 to proceed)" << endl;
    }
}

int Airline() {
    int airline_choice;

    /** Airline Menu Interface */
    cout << endl;
    cout << "1) Add Airports" << endl;
    cout << "2) Add Airplanes" << endl;
    cout << "0) Go Back" << endl;

    /** Airline Menu execution (asking for airline_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> airline_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (airline_choice == 0) { return 0; }
        else if (airline_choice == 1 || airline_choice == 2) { return airline_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
    }
}

int Airport() {
    int airport_choice;

    /** Airport Menu Interface */
    cout << endl;
    cout << "1) Add Transport" << endl;
    cout << "2) Get Transport" << endl;
    cout << "0) Go Back" << endl;

    /** Aiport Menu execution (asking for airport_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> airport_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (airport_choice == 0) { return 0; }
        else if (airport_choice == 1 || airport_choice == 2 ) { return airport_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
    }
}

int Airplanes() {
    int airplanes_choice;

    /** Airplanes Menu Interface */
    cout << endl;
    cout << "1) Add Flights" << endl;
    cout << "2) Set Flights" << endl;
    cout << "3) Get Flights" << endl;
    cout << "4) Get Last 20 Flights" << endl;
    cout << "5) Add Services" << endl;
    cout << "6) Get Services" << endl;
    cout << "7) Get Past Services" << endl;
    cout << "0) Go Back" << endl;

    /** Airplanes Menu execution (asking for airplanes_choice */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> airplanes_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (airplanes_choice == 0) { return 0; }
        else if (airplanes_choice == 1 || airplanes_choice == 2 || airplanes_choice == 3 ||
                 airplanes_choice == 4 || airplanes_choice == 5 || airplanes_choice == 6 ||
                 airplanes_choice == 7) { return airplanes_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1, 2, 3, 4, 5, 6 or 7 to proceed)" << endl;
    }
}