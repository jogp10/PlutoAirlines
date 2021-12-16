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

    cout << "0) Go Back" << endl;


    /** Passenger Menu execution (asking for passenger_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> passenger_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (passenger_choice == 0) { return 0; }
        else if (passenger_choice == 1 || passenger_choice == 2 ) { return passenger_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0 or 1 to proceed)" << endl;
    }
}

void BuyTicket() {}


//--------------------------
int Worker() {
    int worker_choice;

    /** Worker Menu Interface */
    cout << endl;
    cout << "1) Add Plane" << endl;
    cout << "2) Manage Flight" << endl;
    cout << "0) Go Back" << endl;


    /** Worker Menu execution (asking for worker_choice) */
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> worker_choice;

        if (cin.eof()) { return 0; }
        if (cin.fail()) { cin.ignore(10000, '\n'); }
        if (worker_choice == 0) { return 0; }
        else if (worker_choice == 1 || worker_choice == 2 ) { return worker_choice; }

        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
    }
}

void AddPlane() {}

void ManageFlight() {}