#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
    explicit Date(int d, int m, int y);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool isLeapYear() const;
    bool isValidDay(int d) const;

    void displayDate() const;

private:
    int day;
    int year;
    int month;
};

#endif
