#include <stdexcept>

#include "date.hpp"

const int Date::DAYINMONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Date::MAXMONTHS = 12;

Date::Date()
    : Date(1, 1, 2025) {}

Date::Date(int day, int month, int year)
{
    setMonth(month);
}

void Date::setDay(int day)
{
}