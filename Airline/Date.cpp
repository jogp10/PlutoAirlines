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

void Hour::setHourMin(string houR) {
    string hours, minutes;
    for(int i=0; i<houR.size(); i++){
        if(i<2){
            hours+=houR[i];
        }
        else if(i>2){
            minutes+=houR[i];
        }
    }
    hour=stoi(hours); minute=stoi(minutes);
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

bool Hour::operator<(const Hour &a) const {
    if(this->hour==a.hour){
        return minute<a.minute;
    }
    return hour<a.hour;
}

bool Hour::operator==(const Hour &a) const {
    return(hour==a.hour && minute==a.minute);
}


Date::Date(const string& date) : Hour(){
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
        year = stoi(years); month = stoi(months); day = stoi(days); hour = stoi(hours); minute = (stoi(minutes));
    }else {
        this->setHourMin(date);
    }
    return date;
}

string Date::getDate() {
    string months = to_string(this->month),
            days = to_string(this->day),
            hours = to_string(this->hour),
            minutes = to_string(this->minute);
    if(months.size()==1) months = '0' + months;
    if(days.size()==1) days = '0' + days;
    if(hours.size()==1) hours = '0' + hours;
    if(minutes.size()==1) minutes = '0' + minutes;

    return to_string(year) + "-" + months + "-" + days
           + " " + hours + ":" + minutes;
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
       this->day==a.day && this->hour==a.hour
       && this->minute==a.minute) return true;
    return false;
}

bool Date::operator<(const Date &a) const {
    if(this->year==a.year){
        if(this->month==a.month){
            if(this->day==a.day){
                if(this->hour==a.hour){
                    return this->minute<a.minute;
                }
                return this->hour<a.hour;
            }
            return this->day<a.day;
        }
        return this->month<a.month;
    }
    return this->year<a.year;
}

Date Date::operator+(const Date &a) {
    int befHour = hour;
    this->hour= hour + a.hour;
    if(hour < befHour) ++day;

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
    this->minute+=a.getMinute();
    if(minute>59){
        minute-=59;
        ++hour;
    }
    this->hour+=a.getHour();
    if(hour>23) hour-=23;
    this->day++;
    return *this;
}
