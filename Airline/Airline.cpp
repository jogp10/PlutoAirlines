//
// Created by john on 27/11/21.
//

#include "Airline.h"

void Airline::setAirplanes(const vector<Airplane>& airplaneS) {
    this->airplanes=airplaneS;
    for(auto &i: airplanes)
        for(auto &j: i.getFlights()){
            flights.push_back(j);
        }
    updateFlights();
}


void Airline::addAirplane(Airplane& airplane) {
    for(auto &f: airplane.getFlights()) flights.push_back(f);
    updateFlights();
    airplanes.push_back(airplane);
}

void Airline::addAirport(const Airport& airport) {
    airports.push_back(airport);
}


void Airline::addFlight(Flight &flight) {
    for(auto& i: airplanes){
        if(i.getPlate()==flight.getAirplanePlate()){
            flight.setAvailableSeats(i.getCapacity());
            i.addFlight(flight);
        }
    }
    flights.push_back(flight);
}


// Merge Sort
bool operator<= (const Flight& lhs, const Flight& rhs){
    if(lhs.getDepartureLocal()==rhs.getDepartureLocal()) return lhs.getArrivalLocal()<=rhs.getArrivalLocal();
    return lhs.getDepartureLocal()<rhs.getDepartureLocal();
}

void merge(vector<Flight> &v, vector<Flight> &tmpArr, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1, tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
        if ( v[leftPos] <= v[rightPos] )
            tmpArr[tmpPos++] = v[leftPos++];
        else
            tmpArr[tmpPos++] = v[rightPos++];
    while ( leftPos <= leftEnd )
        tmpArr[tmpPos++] = v[leftPos++];
    while ( rightPos <= rightEnd )
        tmpArr[tmpPos++] = v[rightPos++];
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        v[rightEnd] = tmpArr[rightEnd];
}

void mergeSort(vector<Flight> &v, vector<Flight> &tmpArr, int left, int right){
    if (left < right){
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

void mergeSort(vector<Flight>& v) {
    vector<Flight> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
}

void Airline::updateFlights() {
    flights.clear();
    for(auto &i: this->getAirplanes()){
        for(auto &j: i.getFlights()){
            flights.push_back(j);
        }
    }
    mergeSort(flights);
}

//Binary Search
bool operator> (const Flight& lhs, const Flight& rhs){
    return lhs.getDepartureLocal()>rhs.getDepartureLocal();
}


int BinarySearch(const vector<Flight> &v, Flight el)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (el > v[middle])
            left = middle + 1;
        else if (v[middle] > el)
            right = middle - 1;
        else
            return middle; // found
    }
    return -1; // not found
}

vector<Flight> Airline::filterFromX(const string& code) {
    vector<Flight> result;
    vector<Flight> tmp = flights;
    Flight f1(0, "2999-12-30 23:59", code, "", 1, "");
    while(true){
        int ind = BinarySearch(tmp,  f1);
        if(ind == -1) break;
        result.push_back(tmp[ind]);
        tmp.erase(tmp.begin()+ind);
    }
    return result;
}

vector<Flight> Airline::filterToX(const string& code) {
    vector<Flight> result;
    for(auto &f: flights){
        if(f.getArrivalLocal()==code) result.push_back(f);
    }
    return result;
}

vector<Flight> Airline::filterbyDateX(const string& date) {
    vector<Flight> result;
    for(auto &f: flights){
        Date date1 = f.getDepartureDate();
        string d = date1.getDate();
        d.erase(d.begin()+10, d.end());
        if(f.getArrivalLocal()==date) result.push_back(f);
    }
    return result;
}

vector<Flight> Airline::filterDuration(const int min) {
    vector<Flight> result;
    for(auto &f: flights){
        if(f.getFlightDuration()<Hour(min)) result.push_back(f);
    }
    return result;
}



bool Airline::removeAirplane(const Airplane &a) {
    for(auto itr=airplanes.begin(); itr!=airplanes.end(); ++itr){
        if(itr->getPlate()==a.getPlate()){
            for(auto &f: itr->getFlights()){
                removeFlight(f);
            }
            airplanes.erase(itr);
            return true;
        }
    }
    return false;
}

bool Airline::removeFlight(const Flight &f) {
    int ind=0;
    for(ind; ind<flights.size(); ind++){
        if(flights[ind].getFLightNum()==f.getFLightNum()) break;
    }
    string plate = flights.at(ind).getAirplanePlate();
    for(auto &a: airplanes){
        if(plate==a.getPlate()) a.removeFlight(flights.at(ind));
    }
    flights.erase(flights.begin()+ind);
    return true;
}

bool Airline::removeAirport(const Airport &p) {
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getDepartureLocal() == p.getCode() || flights[i].getArrivalLocal() == p.getCode()) {
            removeFlight(flights[i]);
            --i;
        }
    }
    for (auto itr = airports.begin(); itr != airports.end(); ++itr) {
        if (itr->getCode() == p.getCode()) {
            airports.erase(itr);
            return true;
        }
    }
    return false;
}

vector<Airplane> Airline::loadPlanes() {
    string namePlane, typePlane, platePlane, objPlane, name ;
    vector<Airplane> result;

    ifstream file_airplanes;
    file_airplanes.open("Populate/Airplane.txt");

    while(getline(file_airplanes, namePlane)) {
        getline(file_airplanes, typePlane);
        getline(file_airplanes, platePlane);

        class Airplane plane(namePlane, typePlane, stoi(platePlane));

        result.push_back(plane);
    }
    this->setAirplanes(result);
    file_airplanes.close();
    return result;
}

vector<Airport> Airline::loadAirports() {
    /** Filling Airports vector */
    string nameAirport, codeAirport;
    vector<Airport> result;

    ifstream file_airport;
    file_airport.open("Populate/Airport.txt");

    while (getline(file_airport, nameAirport)) {
        getline(file_airport, codeAirport);

        class Airport airport(nameAirport, codeAirport);

        result.push_back(airport);
    }
    this->setAirports(result);
    file_airport.close();
    return result;
}

vector<Flight> Airline::loadFlights() {
    /** Filling Flights vector */
    string flightNum, departureDate, departureLocal, arrivalLocal, flightDuration, airplanePlate;
    vector<Flight> result;

    ifstream file_flight;
    file_flight.open("Populate/Flight.txt");

    while (getline(file_flight, flightNum)) {
        getline(file_flight, departureDate);
        getline(file_flight, departureLocal);
        getline(file_flight, arrivalLocal);
        getline(file_flight, flightDuration);
        getline(file_flight, airplanePlate);

        class Flight flight(stoi(flightNum), departureDate, departureLocal, arrivalLocal,
                            stoi(flightDuration), airplanePlate);

        result.push_back(flight);
        this->addFlight(flight);
    }

    file_flight.close();
    return result;
}

vector<LandTransport> Airline::loadLandTransport() {
    /** Filling Flights vector */
    string transType, distance, freq, startHour, endHour;
    vector<LandTransport> result;

    ifstream file_landtransport;
    file_landtransport.open("Populate/LandTransport.txt");

    while (getline(file_landtransport, transType)) {
        getline(file_landtransport, distance);
        getline(file_landtransport, freq);
        getline(file_landtransport, startHour);
        getline(file_landtransport, endHour);
        auto itr = table.find(transType);
        TransType transType1 = itr->second;

        class LandTransport landTransport(transType1, stoi(distance), Hour(freq), Hour(startHour),
                            Hour(endHour));

        result.push_back(landTransport);
    }

    file_landtransport.close();
    return result;
}
