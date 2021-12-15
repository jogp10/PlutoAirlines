//
// Created by john on 14/12/21.
//

#include "Date.h"
#include <string>
#include <ctime>

Hour::Hour(string date) {
    string hours, minutes;

    for(int i=0; i<date.size(); i++) {
        if(i<2) {
            hours += date[i];
        } else if(i>2) {
            minutes += date[i];
        }
    }
    hour = stoi(hours);
    minute = stoi(minutes);
}

Hour::Hour(int minutes) {
    hour = minutes/60;
    minute = minutes%60;
}

void Hour::setHour(const string& houR) {
    string hours;
    for(auto i:houR) hours+=i;
    this->hour = stoi(hours);
}

void Hour::setMinute(const string& minutE) {
    string minutes;
    for(auto i:minutE) minutes+=i;
    this->minute = stoi(minutes);
}

Hour Hour::operator+(const Hour& a){
    this->minute+=a.getMinute();
    if(minute>59){
        minute-=59;
        ++hour;
    }
    this->hour+=a.getHour();
    if(hour>23) hour-=23;
    return *this;
}


Date::Date(const string& date){
    convert(date);
}

string Date::convert(const string& date){
    string years, months, days, hours, minutes;
    unsigned size = date.size();
    if(size>6) {
        for (unsigned i = 0; i < size; ++i) {
            if (i < 4) {
                years += date[i];
            } else if (i > 4 && i < 7) {
                months += date[i];
            } else if (i > 7 && i < 10) {
                days += date[i];
            } else if (i > 10 && i < 13) {
                hours += date[i];
            } else if (i > 13 && i < 16) {
                minutes += date[i];
            }
        }
    }else {
        Hour h1(date);
        hour=h1;
    }
    year = stoi(years); month = stoi(months); day = stoi(days); hour.setHour(stoi(hours)); hour.setMinute(stoi(minutes));
    return date;
}

string Date::getDate() {
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day)
           + " " + to_string(hour.getHour()) + ":" + to_string(hour.getMinute());
}

string Date::getNow() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string month = to_string(now->tm_mon+1),
            day = to_string(now->tm_mday),
            hour = to_string(now->tm_hour),
            minute = to_string(now->tm_min);
    if(month.size()==1) month = '0' + month;
    if(day.size()==1) day = '0' + day;
    if(hour.size()==1) hour = '0' + hour;
    if(minute.size()==1) minute = '0' + minute;

    string date = (to_string(now->tm_year+1900) + '-' + month + '-' +
                   day + ' ' + hour + ':' + minute);

    return date;
}

bool Date::operator==(const Date &a) const{
    if(this->year==a.year && this->month==a.month &&
       this->day==a.day && this->hour.getHour()==a.hour.getHour()
       && this->hour.getMinute()==a.hour.getMinute()) return true;
    return false;
}

bool Date::operator<(const Date &a) const {
    if(this->year==a.year){
        if(this->month==a.month){
            if(this->day==a.day){
                if(this->hour.getHour()==a.hour.getHour()){
                    return this->hour.getMinute()<a.hour.getMinute();
                }
                return this->hour.getHour()<a.hour.getHour();
            }
            return this->day<a.day;
        }
        return this->month<a.month;
    }
    return this->year<a.year;
}

Date Date::operator+(const Date &a) {
    int befHour = hour.getHour();
    this->hour= hour + a.hour;
    if(hour.getHour() < befHour) ++day;

    this->day+=a.day;
    if(this->day>30){
        this->day-=30;
        this->month+=1;
    }

    this->month+=a.month;
    if(this->month>12){
        this->month-=12;
        this->year+=1;
    }

    this->year+=a.year;
    return *this;
}

Date Date::operator+(const Hour &a) {
    this->hour= hour + a;
    return *this;
}
