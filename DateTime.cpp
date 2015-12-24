//
// Created by Omar Mohamed on 20/12/2015.
//

#include "DateTime.h"

void DateTime::setCurrent() {
    time_t now = time(NULL);
    string dateTime = ctime(&now);

    for (int i = 0, counter = 0; i < dateTime.size(); i++, counter++) {
        string tmp;
        while (dateTime[i] != ' ' && dateTime[i] != '\n' && dateTime[i] != ':') {
            tmp += dateTime[i];
            i++;
        }

        if (counter == 0)
            dayName = tmp;
        else if (counter == 1)
            month = tmp;
        else if (counter == 2)
            dayNumber = tmp;
        else if (counter == 3)
            hour = tmp;
        else if (counter == 4)
            minute = tmp;
        else if (counter == 5)
            second = tmp;
        else
            year = tmp;
    }

    stringDate = dayName + " " + dayNumber + "/" + month + "/" + year;
    stringTime = hour + ":" + minute + ":" + second;
}

string DateTime::getDate() {
    return stringDate;
}

string DateTime::getDayName() {
    return dayName;
}

string DateTime::getDayNumber() {
    return dayNumber;
}

string DateTime::getMonth() {
    return month;
}

string DateTime::getYear() {
    return year;
}

string DateTime::getTime() {
    return stringTime;
}

string DateTime::getSecond() {
    return second;
}

string DateTime::getMinute() {
    return minute;
}

string DateTime::getHour() {
    return hour;
}

void DateTime::setDate(string dayName, string dayNumber, string month, string year) {
    this->dayName = dayName;
    this->dayNumber = dayNumber;
    this->month = month;
    this->year = year;
}

void DateTime::setTime(string second, string minute, string hour) {
    this->second = second;
    this->minute = minute;
    this->hour = hour;
}

int DateTime::calculateAge() {
    int year = stoi(this->year);

    DateTime now;
    now.setCurrent();
    int thisYear = stoi(now.getYear());

    return thisYear - year;
}

DateTime::DateTime() {
    setCurrent();
}

void DateTime::setDayName(string dayName) {
    this->dayName = dayName;
}

void DateTime::setDayNumber(string dayNumber) {
    this->dayNumber = dayNumber;
}

void DateTime::setMonth(string month) {
    this->month = month;
}

void DateTime::setYear(string year) {
    this->year = year;
}

void DateTime::setSecond(string second) {
    this->second = second;
}

void DateTime::setMinute(string minute) {
    this->minute = minute;
}

void DateTime::setHour(string hour) {
    this->hour = hour;
}
ostream &operator<<(ostream &out, DateTime &date) {
    out << date.getDate();
    return out;
}

