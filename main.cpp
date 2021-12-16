#include "Airline/Airline.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "App.h"
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {
    /*cout << "so why are u gae!" << endl;


    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
     */
    int menu_choice;
    int passenger_choice;
    int worker_choice;

    while (true) {
        /** Initiating Menu */
        if(cin.eof()) { menu_choice = 0; }
        else { menu_choice = menu(); }

        switch (menu_choice) {
            /** Choosing if we are a passenger */
            case 1:
                passenger_choice = Passenger();

                switch (passenger_choice) {
                    /** BuyTicket which is responsible for setting up a ticket for a passenger
                     * in a certain flight
                     */
                    case 1:
                        BuyTicket();
                        break;

                    /** Go back to Main Menu */
                    case 0:
                        break;
                }
                break;

            /** Choosing if we are a worker */
            case 2:
                worker_choice = Worker();

                switch (worker_choice) {
                    /** AddPlane which is responsible for adding new Plane to the lineup */
                    case 1:
                        AddPlane();
                        break;

                    /** ManageFlight which is responsible for setting up a flight */
                    case 2:
                        ManageFlight();
                        break;

                    /** Go back to Main Menu */
                    case 0:
                        break;
                }
                break;

            /** Option default to close the app */
            default:
                this_thread::sleep_for(chrono::seconds(2));
                return 0;
        }
    }
}
