//
// Created by john on 27/11/21.
//

#include "Airline.h"

void Airline::setAirplanes(vector<Airplane> airplaneS) {
    this->airplanes=airplaneS;
    for(auto &i: airplaneS) updateFlights(i);
}


void Airline::addAirplane(Airplane& airplane) {
    updateFlights(airplane);
    airplanes.push_back(airplane);
}

void Airline::addAirport(const Airport& airport) {
    airports.push_back(airport);
}

// Merge Sort
bool operator<= (const Flight& lhs, const Flight& rhs){
    if(lhs.getDepartureLocal()==rhs.getDepartureLocal()) return lhs.getDepartureDate()<rhs.getDepartureDate();
    return lhs.getDepartureLocal()<=rhs.getDepartureLocal();
}

void merge(vector<Flight> &v, vector<Flight> &tmpArr,
           int leftPos, int rightPos, int rightEnd) {
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
            flights.emplace_back(j);
        }
    }
    mergeSort(flights);
}

void Airline::updateFlights(Airplane &a) {
    for(auto &i: a.getFlights()) flights.emplace_back(i);
    mergeSort(flights);
}

//Binary Search
bool operator>= (const Flight& lhs, const Flight& rhs){
    return lhs.getDepartureLocal()>=rhs.getDepartureLocal();
}

int BinarySearch(const vector<Flight> &v, Flight el)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (el >= v[middle])
            left = middle + 1;
        else if (v[middle] >= el)
            right = middle - 1;
        else
            return middle; // found
    }
    return -1; // not found
}

vector<Flight> Airline::filterFromX(string code) {
    vector<Flight> result;
    vector<Flight> tmp = flights;
    Flight f1(0, "", code, "", 1);
    while(true){
        int ind = BinarySearch(tmp,  f1);
        if(ind == -1) break;
        result.push_back(tmp[ind]);
        tmp.erase(tmp.begin()+ind);
    }
    return result;
}




