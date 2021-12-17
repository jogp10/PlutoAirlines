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
bool operator<= (const pair<Airplane, Flight>& lhs, const pair<Airplane, Flight>& rhs){
    if(lhs.first.getPlate()==rhs.first.getPlate()) return lhs.second.getFLightNum()<rhs.second.getFLightNum();
    return lhs.first.getPlate()<=rhs.first.getPlate();
}

void merge(vector <pair<Airplane, Flight>> &v, vector<pair<Airplane, Flight>> &tmpArr,
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

void mergeSort(vector <pair<Airplane, Flight>> &v, vector<pair<Airplane, Flight>> &tmpArr,
               int left, int right){
    if (left < right){
        int center = (left + right) / 2;
        mergeSort(v, tmpArr, left, center);
        mergeSort(v, tmpArr, center + 1, right);
        merge(v, tmpArr, left, center +1, right);
    }
}

void mergeSort(vector <pair<Airplane, Flight>> & v) {
    vector<pair<Airplane, Flight>> tmpArr(v.size());
    mergeSort(v, tmpArr, 0, v.size()-1);
}

void Airline::updateFlights() {
    flights.clear();
    for(auto &i: this->getAirplanes()){
        for(auto &j: i.getFlights()){
            flights.emplace_back(i, j);
        }
    }
    mergeSort(flights);
}

void Airline::updateFlights(Airplane &a) {
    for(auto &i: a.getFlights()) flights.emplace_back(a, i);
    mergeSort(flights);
}



