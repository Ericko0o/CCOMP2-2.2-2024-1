#include "Date.h"
#include <iostream>

Date::Date(int m, int d, int y)
    : month(m), day(d), year(y) {
    if (month < 1 || month > 12) {
        month = 1;
    }
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    } else {
        month = 1;
    }
}

int Date::getMonth() const {
    return month;
}

void Date::setDay(int d) {
    day = d;
}

int Date::getDay() const {
    return day;
}

void Date::setYear(int y) {
    year = y;
}

int Date::getYear() const {
    return year;
}

void Date::displayDate() const {
    std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
}
