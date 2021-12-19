//
// Created by john on 27/11/21.
//

#include "Airline.h"


void Airline::addAirplane(Airplane& airplane, bool write) {
    for(auto &f: airplane.getFlights()) flights.push_back(f);
    updateFlights();
    airplanes.push_back(airplane);
    if(write) {
        string content = airplane.getPlate() + " " + airplane.getType() + " " +
                        to_string(airplane.getCapacity());
        Airline::write("Populate/Airplane.txt", content);
    }
}


void Airline::addAirport(const Airport& airport, bool write) {
    airports.push_back(airport);
    if(write) {
        string content = airport.getAirportName() + " " + airport.getCode();
        Airline::write("Populate/Airport.txt", content);
    }
}


void Airline::addFlight(Flight &flight, bool write) {
    for(auto& i: airplanes){
        if(i.getPlate()==flight.getAirplanePlate()){
            flight.setAvailableSeats(i.getCapacity());
            i.addFlight(flight);
        }
    }
    flights.push_back(flight);
    if(write) {
        string content = to_string(flight.getFLightNum()) + " " +
                        flight.getDepartureDate().getDate() + " " +
                        flight.getDepartureLocal() + " " +
                        flight.getArrivalLocal() + " " +
                to_string(flight.getFlightDuration().getHour()*60+flight.getFlightDuration().getMinute()) + " "+
                flight.getAirplanePlate();
        Airline::write("Populate/Flight.txt", content);
    }
}


void Airline::addService(Service &service, bool write) {
    for(auto& i:airplanes){
        if(i.getPlate()==service.airplane_plate){
            i.addService(service);
        }
    }
    if(write) {
        string content = service.airplane_plate + " " + to_string(service.type) + " " +
                            service.name + " " + service.date.getDate();
        Airline::write("Populate/Service.txt", content);
    }
}


void Airline::addLandTransport(LandTransport &landTransport, bool write) {
    string code = landTransport.getAirportCode();
    for(auto& i: airports){
        if(i.getCode()==code){
            i.insert(landTransport);
        }
    }
    if(write) {
        string content = landTransport.getAirportCode() + " " + to_string(landTransport.getTransType()) + " " +
                        to_string(landTransport.getDistance()) + " " + landTransport.getFreq().getHourMin() + " "+
                        landTransport.getStart().getHourMin() + " " +
                        landTransport.getEnd().getHourMin();
        Airline::write("Populate/LandTransport.txt", content);
    }
}


void Airline::addTicket(Ticket &t, Passenger p, bool write) {
    p.buyTicket(t);
    int flightNum = t.getFlightNum();
    for(auto &i:flights){
        if(i.getFLightNum()==flightNum){
            t.setFlight(i);
            i.minusAvailableSeats(t.getGroup());
        }
    }
    if(write) {
        string content = to_string(t.getFlightNum()) + " " + to_string(t.getGroup()) + " " + to_string(t.getLuggage().getnumBags());
        Airline::write("Populate/Ticket.txt", content);
    }
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
    mergeSort(v, tmpArr, 0, (int)v.size()-1);
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


int BinarySearch(const vector<Flight> &v, const Flight& el)
{
    int left = 0, right = (int) v.size() - 1;
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
        if(d==date) result.push_back(f);
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
    vector<string> del;
    del.push_back(a.getPlate());
    del.push_back(to_string(3));
    Airline::del("Populate/Airplane.txt", del);
    del[1]=to_string(4);
    Airline::del("Populate/Service.txt", del);
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
    vector<string> del;
    del.push_back(to_string(f.getFLightNum()));
    del.push_back(to_string(6));
    Airline::del("Populate/Flight.txt", del);
    del[1]=to_string(3);
    Airline::del("Populate/Ticket.txt", del);
    int ind=0;
    for(;ind<flights.size(); ind++){
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
    vector<string> del;
    del.push_back(p.getAirportName());
    del.push_back(to_string(2));
    Airline::del("Populate/Airport.txt", del);
    del[0]=p.getCode();
    del[1]=to_string(6);
    Airline::del("Populate/LandTransport.txt", del);

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
        this->addAirplane(plane, false);
    }
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
        this->addAirport(airport, false);
    }
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
        this->addFlight(flight, false);
    }

    file_flight.close();
    return result;
}


vector<LandTransport> Airline::loadLandTransport() {
    /** Filling LandTransport vector */
    string transType, distance, freq, startHour, endHour, airportCode;
    vector<LandTransport> result;

    ifstream file_landtransport;
    file_landtransport.open("Populate/LandTransport.txt");

    while (getline(file_landtransport, airportCode)) {
        getline(file_landtransport, transType);
        getline(file_landtransport, distance);
        getline(file_landtransport, freq);
        getline(file_landtransport, startHour);
        getline(file_landtransport, endHour);
        auto itr = table.find(transType);
        TransType transType1 = itr->second;

        class LandTransport landTransport(transType1, stoi(distance), Hour(freq), Hour(startHour),
                            Hour(endHour),airportCode);

        result.push_back(landTransport);
        this->addLandTransport(landTransport, false);
    }

    file_landtransport.close();
    return result;
}


vector<Service> Airline::loadServices() {
    /** Filling Services vector */
    string type, name, date, airplanePlate;
    vector<Service> result;

    ifstream file_service;
    file_service.open("Populate/Service.txt");

    while (getline(file_service, airplanePlate)) {
        getline(file_service, type);
        getline(file_service, name);
        getline(file_service, date);

        auto itr = servtable.find(type);
        ServType servType = itr->second;

        class Service service{servType, name, Date(date), airplanePlate};

        result.push_back(service);
        this->addService(service, false);
    }

    file_service.close();
    return result;
}


vector<Ticket> Airline::loadTickets() {
    /** Filling Tickets vector */
    string flightnum, group, luggage;
    vector<Ticket> result;

    ifstream file_ticket;
    file_ticket.open("Populate/Ticket.txt");

    while (getline(file_ticket, flightnum)) {
        getline(file_ticket, group);
        getline(file_ticket, luggage);

        class Ticket ticket(stoi(flightnum), stoi(group), Luggage(stoi(luggage)));

        result.push_back(ticket);
        this->addTicket(ticket, Passenger(""), false);
    }

    file_ticket.close();
    return result;
}


void Airline::write(const string& file, const string& content) {
    ofstream file_generic(file, ios::app);

    if(file_generic.fail()) return;
    vector<string> strings;
    string word;
    for(auto i: content){
        if(i==' ') {
            strings.push_back(word);
            word="";
        }
        else word+=i;
    }
    strings.push_back(word);
    for(const auto& i:strings) file_generic << i << endl;
    file_generic.close();
}


void Airline::del(const char* file1, const vector<string>& del) {
    ifstream file(file1);
    ofstream o("Populate/temp.txt");
    int count=stoi(del[1]);
    string line;
    while(getline(file, line)){
        if(count==-1) count = stoi(del[1]);
        if(del[0]==line) {
            count--;
        }
        if(count == stoi(del[1])) o << line << endl;
        else count--;
    }

    o.close();
    file.close();
    remove(file1);
    rename("Populate/temp.txt", file1);
}