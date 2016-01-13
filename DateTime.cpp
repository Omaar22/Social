#include "DateTime.h"

DateTime::DateTime() {
	setCurrent();
}

string DateTime::timePassed() {

	DateTime now;

	if (now.year - year)
		return to_string(now.year - year) + " years";
	if (now.month - month)
		return to_string(now.month - month) + " months";
	if (now.day - day)
		return to_string(now.day - day) + " days";
	if (now.hour - hour)
		return to_string(now.hour - hour) + " hours";

	return to_string(now.minute - minute) + " minutes";
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

string DateTime::whatDay(int D, int M, int Y) {
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
		else if (counter == 1) {
			string M[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
			for (int j = 0; j < 12; j++) {
				if (M[j] == tmp)
					month = j + 1;
			}
		}
		else if (counter == 2)
			day = stoi(tmp);
		else if (counter == 3)
			hour = stoi(tmp);
		else if (counter == 4)
			minute = stoi(tmp);
		else if (counter == 5)
			second = stoi(tmp);
		else
			year = stoi(tmp);
	}

}

void DateTime::setDate(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
	dayName = whatDay(day, month, year);
}
void DateTime::setDate(string DDMMYY) {
	if (validDate(DDMMYY)) {
		day = stoi(DDMMYY.substr(0, 2));
		month = stoi(DDMMYY.substr(3, 2));
		year = stoi(DDMMYY.substr(6, 4));
		dayName = whatDay(day, month, year);
	}
	else
		throw "Invalid date.";
}
void DateTime::setTime(int second, int minute, int hour) {
	this->second = second;
	this->minute = minute;
	this->hour = hour;
}
void DateTime::setDayName(string dayName) {
	this->dayName = dayName;
}
void DateTime::setDayNumber(int dayNumber) {
	day = dayNumber;
}
void DateTime::setMonth(int month) {
	this->month = month;
}
void DateTime::setYear(int year) {
	this->year = year;
}
void DateTime::setSecond(int second) {
	this->second = second;
}
void DateTime::setMinute(int minute) {
	this->minute = minute;
}
void DateTime::setHour(int hour) {
	this->hour = hour;
}

string DateTime::getDate() {
	return dayName + " " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}
string DateTime::getDayName() {
	return dayName;
}
int DateTime::getDayNumber() {
	return day;
}
int DateTime::getMonth() {
	return month;
}
int DateTime::getYear() {
	return year;
}
string DateTime::getTime() {
	return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}
int DateTime::getSecond() {
	return second;
}
int DateTime::getMinute() {
	return minute;
}
int DateTime::getHour() {
	return hour;
}

ostream &operator<<(ostream &out, const DateTime &date) {
//	out << date.getDate();
	out << date.minute << " " << date.day << "/" << date.month << "/" << date.year;

	return out;
}
