#pragma once

class Time
{
public:
    Time();
    Time(int hours, int minutes, int seconds);

    void timeToMidnight() const;
    void increaseSeconds();
    bool timeForDinner() const;
    bool timeToParty() const;

    Time difference(Time &other);
    Time &comparisonLate(Time &other);
    Time &comparisonEarly(Time &other);

    void print() const;
    void print(int hours, int minutes, int seconds) const;

private:
    bool isValid() const;

    int hours;
    int minutes;
    int seconds;
};