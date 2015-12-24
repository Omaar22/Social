#ifndef SOCIAL_DATETIME_H
#define SOCIAL_DATETIME_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class DateTime {
private:
    string dayName, dayNumber, month, year;
    string stringDate;

    string stringTime;
    string second, minute, hour;

public:
    DateTime();

    void setCurrent();

    int calculateAge();

    string getDate();
    void setDate(string dayName, string dayNumber, string month, string year);

    string getDayName();
    void setDayName(string);

    string getDayNumber();
    void setDayNumber(string);

    string getMonth();
    void setMonth(string);

    string getYear();
    void setYear(string);

    string getTime();
    void setTime(string second, string minute, string hour);

    string getSecond();
    void setSecond(string);

    string getMinute();
    void setMinute(string);

    string getHour();
    void setHour(string);

    friend ostream& operator<< (ostream &out, DateTime &date);

};


#endif //SOCIAL_DATETIME_H
