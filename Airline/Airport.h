//
// Created by john on 14/12/21.
//

#ifndef MAIN_CPP_AIRPORT_H
#define MAIN_CPP_AIRPORT_H

#include "bst.h"
#include "Date.h"

#include <unordered_map>

enum TransType {NONE, TRAIN, SUBWAY, BUS};
unordered_map<string, TransType> const table = {{"NONE", TransType::NONE}, {"SUBWAY", TransType::SUBWAY},
                                                       {"BUS", TransType::SUBWAY}, {"TRAIN", TransType::TRAIN}};

class LandTransport{
    Hour freq, start, end;
    TransType transType;
    double distance;
    vector<Hour> schedule = vector<Hour>();
    string airportcode;

public:
    /**
     * LandTransport this < LandTransport a
     * @param a LandTransport to compare with
     * @return true if this < a
     */
    bool operator<(const LandTransport& a) const{ return this->distance<a.distance; }

    /**
     * LandTransport this == LandTransport a
     * @param LandTransport LandTransport to compare with
     * @return true if equals
     */
    bool operator==(const LandTransport &a) const;

    /**
     *
     * @param transType type of LandTransport
     * @param distance distance from the Airport to LandTransport
     * @param freq  frequency of the LandTransport
     * @param start_hour First LandTransport of the day
     * @param end_hour Time that the LandTransport doesn't work anymore for that day
     * @param airportCode
     */
    explicit LandTransport(TransType transType, double distance=0, Hour freq=Hour("24:00"), Hour start_hour=Hour("08:00"), Hour end_hour=Hour("23:00"), string airportCode="");

    /**
     *  Get LandTransport's type
     * @return type of LandTransport
     */
    TransType getTransType() const {return transType;};

    /**
     * Get LandTransport's distance to the airport
     * @return distance
     */
    double getDistance() const {return distance;};

    /**
     * Get LandTransport's Airport
     * @return Airport code
     */
    string getAirportCode() const {return airportcode;};

    /**
     * Get LandTransport's frequency
     * @return frequency
     */
    Hour getFreq() const {return freq;};

    /**
     * Get LandTransport's starting hour
     * @return
     */
    Hour getStart() const {return start;};

    /**
     * Get LandTransport's last hour
     * @return
     */
    Hour getEnd() const {return end;};

    /**
     * Get next passage of LandTransport
     * @return Hour of the next LandTransport
     */
    Hour next();

    /**
     * Set LandTransport schedule
     * @param frequency of the passages
     * @param start_hour starting hour
     * @param end_hour ending hour
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
     * @param name name of Airport
     * @param code code of Airport
     */
    Airport(const string& name, const string& code): name(name), code(code), bst(LandTransport(NONE)){};

    /**
     * Get Airport's name
     * @return name
     */
    string getAirportName() const {return name;};

    /**
     * Get Airport's code
     * @return code
     */
    string getCode() const {return code;};

    /**
     * Get Airport's LandTransport those that are subways
     * @return subways
     */
    vector<LandTransport> getSubway() const;

    /**
     * Get Airport's LandTransport those that are trains
     * @return trains
     */
    vector<LandTransport> getTrain() const;

    /**
     * Get Airport's LandTransport those that are bus
     * @return bus
     */
    vector<LandTransport> getBus() const;

    /**
     * Get Airport's LandTransport ordered by distance
     * @return LandTransports ordered by distance
     */
    vector<LandTransport> getByDistance() const;

    /**
     * Get closests transport
     * @return  Closest LandTransport
     */
    LandTransport getMinDistance() const {return bst.findMin();};

    /**
     * Get furthest transport
     * @return Fursthest LandTransport
     */
    LandTransport getMaxDistance() const {return bst.findMax();};
    /**
     * Get next transport
     * @return Next LandTransport to pass by
     */
    LandTransport getNext() const;

    /**
     * Insert new LandTransport in City
     * @param landTransport LandTransport
     */
    void insert(const LandTransport& landTransport);
};


#endif //MAIN_CPP_AIRPORT_H
