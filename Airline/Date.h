//
// Created by john on 14/12/21.
//

#ifndef MAIN_CPP_DATE_H
#define MAIN_CPP_DATE_H
#include <string>

using namespace std;


class Hour{
protected:
    int hour, minute;
public:
    Hour() = default;

    /**
     *
     * @param date string "HH:MM"
     */
    explicit Hour(string date);

    /**
     * MMM converted into "HH:MM"
     * @param minutes
     */
    explicit Hour(int minutes);

    /**
     * Set Hour & Minute
     * @param houR string "HH:MM"
     */
    void setHourMin(string houR);

    /**
     * set Hour
     * @param houR HH
     */
    void setHour(int houR) { this->hour = houR;};

    /**
     * set Hour
     * @param hour string "HH"
     */
    void setHour(const string& hour);

    /**
     * set Minute
     * @param minutE MM
     */
    void setMinute(int minutE) { this->minute = minutE;};

    /**
     * set Minute
     * @param minute string "MM"
     */
    void setMinute(const string& minute);

    /**
     * Get hour of date
     * @return hour
     */
    int getHour() const {return hour;};

    /**
     * Get minute of date
     * @return minute
     */
    int getMinute() const {return minute;};

    /**
     * Get hour and minute of date
     * @return "HH:MM"
     */
    string getHourMin() const {return to_string(hour) + ":" + to_string(minute);};


    /**
     * Add two hours
     * @param a this + a Hour
     * @return result of operation
     */
    Hour operator+(const Hour& a);

    /**
     * this is before Hour a
     * @param a Hour
     * @return result of operation
     */
    bool operator<(const Hour &a) const;

    /**
     * this equals Hour a
     * @param a Hour
     * @return result of operation
     */
    bool operator==(const Hour &a) const;
};



class Date: Hour{
private:
    int year{}, month{}, day{};

    /**
     * Convert from string to fullfill all parameters of date
     * @param Date Date
     * @return String of input
     */
    string convert(const string& Date);

public:
    /**
     * default
     */
    Date(): Hour(){};

    /**
     *
     * @param date string "YYYY-MM-DD HH:MM"
     */
    explicit Date(const string& date): Hour(){ convert(date);};

    /**
     * Get Date in string "YYYY-MM-DD HH:MM"
     * @return date
     */
    string getDate();

    /**
     * Get Now Date
     * @return now
     */
    static string getNow();

    /**
     * Get year of date
     * @return year
     */
    int getYear() const {return year;};

    /**
     * Get month of date
     * @return month
     */
    int getMonth() const {return month;};

    /**
     * Get day of date
     * @return day
     */
    int getDay() const {return day;};

    /**
     * Get hour of date
     * @return  hour
     */
    int getHour() {return hour;};

    /**
     * Get minute of date
     * @return  minute
     */
    int getMinute() {return minute;};

    /**
     * this equals Date a
     * @param a Date
     * @return result of operation
     */
    bool operator==(const Date &a) const;

    /**
     * this is before Date a
     * @param a Date
     * @return result of operation
     */
    bool operator<(const Date &a) const;

    /**
     * Add two dates
     * @param a Date
     * @return result of operation
     */
    Date operator+(const Date &a);
};


#endif //MAIN_CPP_DATE_H
