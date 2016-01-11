<<<<<<< HEAD
#ifndef SOCIAL_DATETIME_H
#define SOCIAL_DATETIME_H

#include <bits/stdc++.h>
=======
#ifndef DATETIME_H_
#define DATETIME_H_

#include <iostream>
#include <string>
#include <ctime>

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
using namespace std;

class DateTime {
private:
    string dayName, dayNumber, month, year;
<<<<<<< HEAD
    string second, minute, hour;

    bool validDate(int day, int month, int year);
    bool validDate(string &DDMMYY);
=======
    string stringDate;

    string stringTime;
    string second, minute, hour;
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22

public:
    DateTime();

<<<<<<< HEAD
    static string whatDay(int Y, int M, int D); // formula


    void setCurrent();

    string getDate()const; // dayName DD/MM/YY
    void setDate(string dayNumber, string month, string year);
    void setDate(string DDMMYY); // DD/MM/YYYY format

    string getTime();
    void setTime(string second, string minute, string hour);
=======
    void setCurrent();

    int calculateAge(string);

    string getDate();
    void setDate(string dayName, string dayNumber, string month, string year);
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22

    string getDayName();
    void setDayName(string);

    string getDayNumber();
    void setDayNumber(string);

    string getMonth();
    void setMonth(string);

    string getYear();
    void setYear(string);

<<<<<<< HEAD
=======
    string getTime();
    void setTime(string second, string minute, string hour);

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
    string getSecond();
    void setSecond(string);

    string getMinute();
    void setMinute(string);

    string getHour();
    void setHour(string);

<<<<<<< HEAD
    friend ostream& operator<< (ostream &out, const DateTime &date);

    int calculateAge();

};


#endif //SOCIAL_DATETIME_H
=======
    friend ostream& operator<< (ostream &out, DateTime &date);

};
#endif
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
