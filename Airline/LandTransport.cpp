//
// Created by john on 17/12/21.
//

#include "Airport.h"

LandTransport::LandTransport(TransType transType1, double distance1, Hour freq1, Hour start_hour, Hour end_hour, string airportCode):
            transType(transType1), distance(distance1), freq(freq1), start(start_hour), end(end_hour) {
    this->setSchedule(freq, start, end);
    this->airportcode=airportCode;
}

bool LandTransport::operator==(const LandTransport &a) const {
    if(this->distance==a.distance && this->schedule==a.schedule && this->transType==a.transType){
        return true;
    }
    return false;
}


Hour LandTransport::next() {
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

void LandTransport::setSchedule(Hour frequency, Hour start_hour, Hour end_hour) {
    schedule.clear();
    Hour a = start_hour;
    while(a<end_hour){
        schedule.insert(schedule.end(), a);
        if(a.getHour()<a.getHour()+frequency.getHour()) break;
        a= a + frequency;
    }
}
