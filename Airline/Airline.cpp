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
/*
// Merge Sort
bool operator<= (const pair<Airplane, Flight>& lhs, const pair<Airplane, Flight>& rhs){
    if(lhs.second.getDepartureLocal()==rhs.second.getDepartureLocal()) return lhs.second.getDepartureDate()<rhs.second.getDepartureDate();
    return lhs.second.getDepartureLocal()<=rhs.second.getDepartureLocal();
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

void mergeSort(vector <pair<Airplane, Flight>> &v, vector<pair<Airplane, Flight>> &tmpArr, int left, int right){
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
/*
//Binary Search
bool operator< (const pair<Airplane, Flight>& lhs, const pair<Airplane, Flight>& rhs){
    if(lhs.second.getDepartureLocal()==rhs.second.getDepartureLocal()) return lhs.second.getDepartureDate()<rhs.second.getDepartureDate();
    return lhs.second.getDepartureLocal()<rhs.second.getDepartureLocal();
}

int BinarySearch(const vector<pair<Airplane, Flight>> &v, pair<Airplane, Flight> el)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (v[middle] < el)
            left = middle + 1;
        else if (el < v[middle])
            right = middle - 1;
        else
            return middle; // found
    }
    return -1; // not found
}

vector<Flight> Airline::filterFromX(string code) {
    vector<Flight> result;
    vector<pair<Airplane, Flight>> tmp = flights;
    Airplane a1("", "", 1);
    Flight f1(0, "", code, "", 1);
    while(true){
        int ind = BinarySearch(tmp, make_pair(a1, f1));
        if(ind == -1) break;
        result.push_back(tmp[ind].second);
        tmp.erase(tmp.begin()+ind);
    }
    return result;
}
 */



