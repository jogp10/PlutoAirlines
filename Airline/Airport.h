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
    bool operator<(const LandTransport& a) const{ return this->distance<a.distance; }

    /**
     * Check if LandTransport this == LandTransport a
     * @param LandTransport a
     * @return true if equals
     */
    bool operator==(const LandTransport &a) const;
    /**
     *
     * @param transType
     * @param distance
     * @param freq
     * @param start_hour
     * @param end_hour
     */
    explicit LandTransport(TransType transType1, double distance1=0, Hour freq1=Hour("24:00"), Hour start_hour=Hour("08:00"), Hour end_hour=Hour("23:00"));
    /**
     *  Get Transport type
     * @return
     */
    TransType getTransType() const {return transType;};
    /**
     * Get Transport distance to the airport
     * @return
     */
    double getDistance() const {return distance;};

    /**
     * Get next passage of transport
     * @return Date
     */
    Hour next();

    /**
     * Set transport schedule
     * @param frequency of the passages
     * @param start_hour
     * @param end_hour
     */
    void setSchedule(Hour frequency, Hour start_hour, Hour end_hour);
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
    Airport(const string& name1, const string& code1): name(name1), code(code1), bst(LandTransport(NONE)){};

    /**
     * Get all subways
     * @return
     */
    vector<LandTransport> getSubway() const;

    /**
     * Get all trains
     * @return
     */
    vector<LandTransport> getTrain() const;

    /**
     * Get all bus
     * @return
     */
    vector<LandTransport> getBus() const;

    /**
     * Get all transports ordered by distance
     * @return
     */
    vector<LandTransport> getByDistance() const;

    /**
     * Get closests transport
     * @return
     */
    LandTransport getMinDistance() const;

    /**
     * Get furthest transport
     * @return
     */
    LandTransport getMaxDistance() const;

    /**
     * Get next transport
     * @return
     */
    LandTransport getNext() const;

    /**
     * Insert new Transport
     * @param landTransport
     */
    void insert(const LandTransport& landTransport);
};


#endif //MAIN_CPP_AIRPORT_H
