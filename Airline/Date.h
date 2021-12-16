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
     * @param date
     */
    explicit Hour(string date);
    /**
     *
     * @param minutes
     */
    explicit Hour(int minutes);

    /**
     * Set Hour & Minute
     * @param houR
     */
    void setHourMin(string houR);

    /**
     * set Hour
     * @param houR
     */
    void setHour(int houR) { this->hour = houR;};
    /**
     * set Hour
     * @param hour
     */
    void setHour(const string& hour);

    /**
     * set Minute
     * @param minutE
     */
    void setMinute(int minutE) { this->minute = minutE;};
    /**
     * set Minute
     * @param minute
     */
    void setMinute(const string& minute);

    /**
     * Get hour of date
     * @return hour
     */
    int getHour() const {return hour;};

    /**
     * Get minute of date
     * @return
     */
    int getMinute() const {return minute;};


    /**
     * Add two hours
     * @param a
     * @return
     */
    Hour operator+(const Hour& a);

    /**
     * Check if < than another Hour object
     * @param a
     * @return
     */
    bool operator<(const Hour &a) const;

    /**
     * Check if this equals another Hour object
     * @param Comparable Hour
     * @return true if equal
     */
    bool operator==(const Hour &a) const;

};



class Date: Hour{
private:
    int year{}, month{}, day{};

    /**
     * Convert from string to fullfill all parameters of date
     * @param Date
     * @return same string as input
     */
    string convert(const string& Date);
public:
    Date() = default;
    explicit Date(const string& date);

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
     * @return
     */
    int getHour() {return hour;};

    /**
     * Get minute of date
     * @return
     */
    int getMinute() {return minute;};

    /**
     * Check if this equals another Date object
     * @param Comparable Date
     * @return true if equal
     */
    bool operator==(const Date &a) const;

    /**
     * Check if < than another Date object
     * @param a
     * @return
     */
    bool operator<(const Date &a) const;

    /**
     * Add two dates
     * @param a
     * @return
     */
    Date operator+(const Date &a);

    /**
     * Add a date with an hour
     * @param a
     * @return
     */
    Date operator+(const Hour &a);
};


#endif //MAIN_CPP_DATE_H
