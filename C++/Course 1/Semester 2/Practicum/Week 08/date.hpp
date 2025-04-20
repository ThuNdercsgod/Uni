#pragma once

class Date
{
public:
    Date();
    Date(int day, int month, int year);

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    void print() const;

private:
    int day;
    int month;
    int year;
    static const int DAYINMONTH[12];
    static const int MAXMONTHS;
};