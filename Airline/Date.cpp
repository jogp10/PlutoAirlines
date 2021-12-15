//
// Created by john on 14/12/21.
//

#include "Date.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

Date::Date(string date) {
    convert(date);
}

string Date::getDate() {
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day)
    + " " + to_string(hour) + ":" + to_string(minute);
}

string Date::getNow() {
    time_t t = time(0);
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

string Date::convert(string date){
    string years = "", months = "", days = "", hours = "", minutes = "";
    for(int i=0; i<date.size(); ++i){
        if(i<4){
            years += date[i];
        }
        else if(i>4 && i<7){
            months += date[i];
        }
        else if(i>7 && i<10){
            days += date[i];
        }
        else if(i>10 && i<13){
            hours += date[i];
        }
        else if(i>13 && i<16){
            minutes += date[i];
        }
    }
    year = stoi(years); month = stoi(months); day = stoi(days);
    hour = stoi(hours); minute = stoi(minutes);
    return years + "-" + months + "-" + days + " " + hours + ":" + minutes;
}

Date& Date::operator=(const Date &a) {
    this->year=a.year;
    this->month=a.month;
    this->day=a.day;
    this->hour=a.hour;
    this->minute=a.minute;
    return *this;
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
