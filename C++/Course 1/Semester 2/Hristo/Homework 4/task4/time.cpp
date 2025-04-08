#include <cmath>
#include <iostream>

#include "time.hpp"

Time::Time()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
    if (!this->isValid())
    {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

bool Time::isValid() const
{
    if (!(this->hours >= 0 && this->hours <= 23 &&
          this->minutes >= 0 && this->minutes <= 59 &&
          this->seconds >= 0 && this->seconds <= 59))
    {
        return false;
    }
    return true;
}

void Time::timeToMidnight() const
{
    int hours, minutes, seconds;

    hours = 24 - this->hours;
    if (this->minutes != 0)
    {
        hours--;
    }

    minutes = 60 - this->minutes;
    if (this->seconds != 0)
    {
        minutes--;
        seconds = 60 - this->seconds;
    }
    else
    {
        seconds = this->seconds;
    }

    std::cout << "Time left to Midnight: ";
    Time::print(hours, minutes, seconds);
}

void Time::increaseSeconds()
{
    this->seconds++;
}

bool Time::timeForDinner() const
{
    if (this->hours == 21 ||
        (this->hours == 20 && this->minutes >= 30) ||
        (this->hours == 22 && this->minutes == 0 && this->seconds == 0))
    {
        return true;
    }
    return false;
}

bool Time::timeToParty() const
{
    if (this->hours >= 23 && this->hours <= 5 ||
        (this->hours == 6 && this->minutes == 0 && this->seconds == 0))
    {
        return true;
    }
    return false;
}

Time Time::difference(const Time &other) const
{
    Time difference;

    difference.hours = abs(other.hours - this->hours);
    if (this->minutes != other.minutes)
    {
        difference.hours--;
    }

    difference.minutes = abs(other.minutes - this->minutes);
    if (this->seconds != other.seconds)
    {
        difference.minutes--;
        difference.seconds = abs(other.seconds - this->seconds);
    }
    else
    {
        difference.seconds = this->seconds;
    }

    return difference;
}

void Time::print() const
{
    if (this->hours < 10)
    {
        std::cout << "0";
    }
    std::cout << this->hours << ": ";

    if (this->minutes < 10)
    {
        std::cout << "0";
    }
    std::cout << this->minutes << ": ";

    if (this->seconds < 10)
    {
        std::cout << "0";
    }
    std::cout << this->seconds << std::endl;
}

void Time::print(int hours, int minutes, int seconds) const
{
    if (hours < 10)
    {
        std::cout << "0";
    }
    std::cout << hours << ": ";

    if (minutes < 10)
    {
        std::cout << "0";
    }
    std::cout << minutes << ": ";

    if (seconds < 10)
    {
        std::cout << "0";
    }
    std::cout << seconds << std::endl;
}