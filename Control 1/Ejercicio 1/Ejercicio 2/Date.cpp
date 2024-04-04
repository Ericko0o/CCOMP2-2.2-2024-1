#include "Date.h"

Date::Date(int d, int m, int y) {
    setYear(y);
    setMonth(m);
    setDay(d);
}

void Date::setDay(int d) {
    if (isValidDay(d)) {
        day = d;
    } else {
        day = 1; // Default to 1 if day is invalid
    }
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    } else {
        month = 1; // Default to January if month is invalid
    }
}

void Date::setYear(int y) {
    if (y >= 1900 && y <= 2050) {
        year = y;
    } else {
        year = 1900; // Default to 1900 if year is out of range
    }
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

bool Date::isLeapYear() const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool Date::isValidDay(int d) const {
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear()) {
        return (d >= 1 && d <= 29);
    } else {
        return (d >= 1 && d <= daysInMonth[month - 1]);
    }
}

void Date::displayDate() const {
    std::cout << day << " / " << month << " / " << year << std::endl;
}
