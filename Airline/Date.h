//
// Created by john on 14/12/21.
//

#ifndef MAIN_CPP_DATE_H
#define MAIN_CPP_DATE_H
#include <string>

using namespace std;

class Date{
private:
    int year, month, day, hour, minute;
    string convert(string Date);
public:
    Date() = default;
    Date(string date);
    string getDate();
    static string getNow();
    int getYear() {return year;};
    int getMonth() {return month;};
    int getDay() {return day;};
    int getHour() {return hour;};
    int getMinute() {return minute;};

    Date& operator=(const Date &a);
    bool operator==(const Date &a) const;
    bool operator<(const Date &a) const;
};


#endif //MAIN_CPP_DATE_H
