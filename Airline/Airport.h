//
// Created by john on 14/12/21.
//

#ifndef MAIN_CPP_AIRPORT_H
#define MAIN_CPP_AIRPORT_H
#include "bst.h"
#include "Date.h"

enum TransType {TRAIN, SUBWAY, BUS};

struct LandTransport{
    TransType transType;
    int distance = 0;
    vector<Date> schedule = vector<Date>();

    inline bool operator<(const LandTransport& a) const{
        return this->distance<a.distance;
    }

    inline bool operator==(const LandTransport &a) const {
        if(this->distance==a.distance && this->schedule==a.schedule && this->transType==a.transType){
            return true;
        }
        return false;
    }

    Date next(){
        Date now(Date::getNow());
        Date min(*schedule.end());
        for(auto i:schedule){
            if(now<i && i<min){
                min = i;
            }
        }
        return min;
    }
};

class Airport {
private:
    string name;
    string code;
    BST<LandTransport> bst;
public:
    Airport(string name1, string code1);
    vector<LandTransport> getSubway();
    vector<LandTransport> getTrain();
    vector<LandTransport> getBus();
    vector<LandTransport> getByDistance();

    LandTransport getMinDistance();
    LandTransport getMaxDistance();
    LandTransport getNext();

    void insert(LandTransport landTransport);


};


#endif //MAIN_CPP_AIRPORT_H
