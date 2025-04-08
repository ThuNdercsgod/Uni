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
    if ((this->hours >= 23 && this->hours <= 24) ||
        (this->hours >= 0 && this->hours <= 5) ||
        (this->hours == 6 && this->minutes == 0 && this->seconds == 0))
    {
        return true;
    }
    return false;
}

// Смята само разликата от по-малкия час(като число) до по-големия
// Другия случай не съм го имплементирал
Time Time::difference(Time &other)
{
    Time difference;

    difference.hours = abs(other.hours - this->hours);
    if (this->minutes == 0 || other.minutes == 0)
    {
        difference.hours--;
    }

    difference.minutes = abs(other.minutes - this->minutes);
    if (this->seconds == 0 || other.seconds == 0)
    {
        difference.minutes--;
    }
    difference.seconds = abs(other.seconds - this->seconds);

    return difference;
}

// Връща часа, който е по-късен
Time &Time::comparisonLate(Time &other)
{
    if ((this->hours > other.hours) ||
        (other.hours == this->hours && this->minutes > other.minutes) ||
        (other.hours == this->hours && other.minutes == this->minutes && this->seconds > other.seconds) ||
        (other.hours == this->hours && other.minutes == this->minutes && other.seconds == this->seconds))
    {
        return *this;
    }
    else if ((other.hours > this->hours) ||
             (other.hours == this->hours && other.minutes > this->minutes) ||
             (other.hours == this->hours && other.minutes == this->minutes && other.seconds > this->seconds))
    {
        return other;
    }
    else
    {
        return *this;
    }
}

// Връща часа, който е по-ранен
Time &Time::comparisonEarly(Time &other)
{
    if ((this->hours > other.hours) ||
        (other.hours == this->hours && this->minutes > other.minutes) ||
        (other.hours == this->hours && other.minutes == this->minutes && this->seconds > other.seconds) ||
        (other.hours == this->hours && other.minutes == this->minutes && other.seconds == this->seconds))
    {
        return other;
    }
    else if ((other.hours > this->hours) ||
             (other.hours == this->hours && other.minutes > this->minutes) ||
             (other.hours == this->hours && other.minutes == this->minutes && other.seconds > this->seconds))
    {
        return *this;
    }
    else
    {
        return other;
    }
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