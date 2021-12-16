//
// Created by john on 14/12/21.
//

#ifndef MAIN_CPP_AIRPORT_H
#define MAIN_CPP_AIRPORT_H
#include "bst.h"
#include "Date.h"

enum TransType {NONE, TRAIN, SUBWAY, BUS};

class LandTransport{
    TransType transType;
    double distance;
    Hour freq;
    vector<Hour> schedule = vector<Hour>();

public:
    /**
     * Check LandTransport this < LandTransport a
     * @param a
     * @return true if this < a
     */
    bool operator<(const LandTransport& a) const{
        return this->distance<a.distance;
    }

    /**
     * Check if LandTransport this == LandTransport a
     * @param LandTransport a
     * @return true if equals
     */
    bool operator==(const LandTransport &a) const {
        if(this->distance==a.distance && this->schedule==a.schedule && this->transType==a.transType){
            return true;
        }
        return false;
    }
    /**
     *
     * @param transType1
     * @param distance1
     * @param freq1
     * @param start_hour
     * @param end_hour
     */
    LandTransport(TransType transType1, double distance1=0, Hour freq1=Hour("24:00"), Hour start_hour=Hour("08:00"), Hour end_hour=Hour("23:00"));
    /**
     *
     * @return
     */
    TransType getTransType() const {return transType;};
    /**
     *
     * @return
     */
    double getDistance() const {return distance;};

    /**
     * Get next passage of transport
     * @return Date
     */
    Hour next(){
        Date nowd(Date::getNow());
        Hour now{};
        now.setHour(nowd.getHour()); now.setMinute(nowd.getMinute());
        Hour min("23:59");
        for(auto i:schedule){
            if(now<i && i<min){
                min = i;
            }
        }
        if(min.getHour()==23 && min.getMinute()==59) return Hour{};
        return min;
    }

    /**
     * Set transport schedule
     * @param frequency of the passages
     * @param start_hour
     * @param end_hour
     */
    void setSchedule(Hour frequency, Hour start_hour, Hour end_hour){
        schedule.clear();
        Hour a = start_hour;
        while(a<end_hour){
            schedule.insert(schedule.end(), a);
            //Date freq(frequency);
            a = a+frequency;
        }
    }
};

class Airport {
private:
    string name;
    string code;
    BST<LandTransport> bst;
public:
    /**
     *
     * @param name of airport
     * @param code of airport
     */
    Airport(string name1, string code1): name(name1), code(code1), bst(LandTransport(NONE)){};

    /**
     * Get all subways
     * @return
     */
    vector<LandTransport> getSubway();

    /**
     * Get all trains
     * @return
     */
    vector<LandTransport> getTrain();

    /**
     * Get all bus
     * @return
     */
    vector<LandTransport> getBus();

    /**
     * Get all transports ordered by distance
     * @return
     */
    vector<LandTransport> getByDistance();

    /**
     * Get closests transport
     * @return
     */
    LandTransport getMinDistance();

    /**
     * Get furthest transport
     * @return
     */
    LandTransport getMaxDistance();

    /**
     * Get next transport
     * @return
     */
    LandTransport getNext();

    /**
     * Insert new Transport
     * @param landTransport
     */
    void insert(const LandTransport& landTransport);
};


#endif //MAIN_CPP_AIRPORT_H
