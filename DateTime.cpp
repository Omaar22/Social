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

}

string DateTime::getDate()const {
    return dayName + " " + dayNumber + "/" + month + "/" + year;
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
    return hour + ":" + minute + ":" + second;
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

void DateTime::setDate(string dayNumber, string month, string year) {
    this->dayNumber = dayNumber;
    this->month = month;
    this->year = year;
    dayName = whatDay(stoi(year), stoi(month), stoi(dayNumber));
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

ostream &operator<<(ostream &out, const DateTime &date) {
    out << date.getDate();
    return out;
}

void DateTime::setDate(string DDMMYY) {
    if (validDate(DDMMYY)) {
        dayNumber = DDMMYY.substr(0, 2);
        month = DDMMYY.substr(3, 2);
        year = DDMMYY.substr(6, 4);
        dayName = whatDay(stoi(year), stoi(month), stoi(dayNumber));
    }
    else
        throw "Invalid date.";

}

bool  DateTime::validDate(string &DDMMYY) {

    if (DDMMYY[1] == '/')
        DDMMYY.insert(0, "0");
    if (DDMMYY[4] == '/')
        DDMMYY.insert(3, "0");

    if (DDMMYY.size() != 10)
        return false;

    int day;
    if (isdigit(DDMMYY[0]) && isdigit(DDMMYY[1])) {
        string DD;
        DD += DDMMYY[0];
        DD += DDMMYY[1];
        day = stoi(DD);
    }
    else
        return false;

    int month;
    if (isdigit(DDMMYY[3]) && isdigit(DDMMYY[4])) {
        string MM;
        MM += DDMMYY[3];
        MM += DDMMYY[4];

        month = stoi(MM);
    }
    else
        return false;

    int year;
    if (isdigit(DDMMYY[6]) && isdigit(DDMMYY[7]) && isdigit(DDMMYY[8]) && isdigit(DDMMYY[9]))
        year = stoi(DDMMYY.substr(6, 4));
    else
        return false;

    return validDate(day, month, year);
}
bool DateTime::validDate(int day, int month, int year) {
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year < 1850 || year > 2100)
        return false;

    if (year % 4 == 0 && year % 100 || year % 400 == 0)
        daysInMonths[1] = 29;  // Feb has 29 days in leap year

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > daysInMonths[month - 1])
        return false;

    return true;
}
string DateTime::whatDay(int Y, int M, int D) {
    if (M == 1) {
        M = 13;
        Y--;
    }
    if (M == 2) {
        M = 14;
        Y--;
    }

    long long day, k, j;

    k = Y % 100;
    j = Y / 100;
    day = D + 13 * (M + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    day = day % 7;

    if (day == 0)
        return ("Sat");
    else if (day == 1)
        return ("Sun");
    else if (day == 2)
        return ("Mon");
    else if (day == 3)
        return ("Tue");
    else if (day == 4)
        return ("Wed");
    else if (day == 5)
        return ("Thu");
    else
        return ("Fri");

}

