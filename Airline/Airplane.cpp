//
// Created by why_should some1 be gae on 27/11/21.
//

#include "Airplane.h"


void Airplane::addFlight(Flight &flight) {
    flight.setAvailableSeats(capacity);
    flights.push_back(flight);
    updateFlights();
    this->sortFLights(flights, 0, flights.size());
}


void Airplane::addService(Service& service) {
    service.airplane_plate=plate;
    services.push(service);
    updateServices();
}


void Airplane::updateServices() {
    while(services.front().date.getDate() < Date::getNow() && !(services.empty()))
    {
        servicesDone.push_back(services.front());
        services.pop();
    }
}


void Airplane::updateFlights() {
    auto itr = flights.begin();
    while(itr!=flights.end()){
        string d1 = itr->getDepartureDate().getDate(); // start of the flight
        string d11 = itr->getFlightDuration().getHourMin(); // flight duration
        d1.append(d11); // arrival
        string d2 = Date::getNow();
        if(d1<d2) {
            last20flights.push(flights.front());
            if (last20flights.size() > 20)last20flights.pop();
            flights.erase(itr--);
        }
        else break;
        ++itr;
    }
}


const Flight &median(vector<Flight> &f, unsigned left, unsigned right){
    int center = (int) (left+right) /2;
    if(f[center] < f[left])
        swap(f[left], f[center]);
    if(f[right] < f[left])
        swap(f[left], f[right]);
    if(f[right] < f[center])
        swap(f[center], f[right]);

    swap(f[center], f[right-1]);
    return f[right-1];
}


void insertionSort(vector<Flight> &f, unsigned left, unsigned right){
    for(unsigned p=left+1; p<right; p++){
        Flight tmp = f[p];
        unsigned j;
        for( j=p; j>0 && tmp<f[j-1]; j--)
            f[j] = f[j-1];
        f[j] = tmp;
    }
}


//Quick Sort
void Airplane::sortFLights(vector<Flight> &f, unsigned left, unsigned right) {
    if(right-left<=10)
        insertionSort(f, left, right);
    else {
        Flight x = median(f, left, right);
        int i = (int) left;
        int j = (int) right - 1;
        for (;;) {
            while (f[++i] < x);
            while (x < f[--j]);
            if (i < j)
                swap(f[i], f[j]);
            else break;
        }
        swap(f[i], f[right - 1]);
        sortFLights(f, left, i - 1);
        sortFLights(f, i + 1, right);
    }
}


bool Airplane::removeFlight(const Flight &f) {
    for(auto itr=flights.begin();itr!=flights.end(); ++itr){
        if(itr->getFLightNum()==f.getFLightNum()) {
            flights.erase(itr);
            break;
        }
    }
    return false;
}