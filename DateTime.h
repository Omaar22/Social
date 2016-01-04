#ifndef SOCIAL_DATETIME_H
#define SOCIAL_DATETIME_H

#include <bits/stdc++.h>
using namespace std;

class DateTime {
private:
    string dayName, dayNumber, month, year;
    string second, minute, hour;

    bool validDate(int day, int month, int year);
    bool validDate(string &DDMMYY);

public:
    DateTime();

    static string whatDay(int Y, int M, int D); // formula


    void setCurrent();

    string getDate()const; // dayName DD/MM/YY
    void setDate(string dayNumber, string month, string year);
    void setDate(string DDMMYY); // DD/MM/YYYY format

    string getTime();
    void setTime(string second, string minute, string hour);

    string getDayName();
    void setDayName(string);

    string getDayNumber();
    void setDayNumber(string);

    string getMonth();
    void setMonth(string);

    string getYear();
    void setYear(string);

    string getSecond();
    void setSecond(string);

    string getMinute();
    void setMinute(string);

    string getHour();
    void setHour(string);

    friend ostream& operator<< (ostream &out, const DateTime &date);

    int calculateAge();

};


#endif //SOCIAL_DATETIME_H
