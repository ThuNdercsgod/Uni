#include <iostream>

#include "interval.hpp"

Interval::Interval()
{
    this->a = 0;
    this->b = 0;
}

Interval::Interval(int a, int b)
{
    if (a <= b)
    {
        this->a = a;
        this->b = b;
    }
    else
    {
        this->a = 0;
        this->b = 0;
    }
}

int Interval::getA() const
{
    return this->a;
}

int Interval::getB() const
{
    return this->b;
}

void Interval::setA(int a)
{
    if (a <= this->b)
    {
        this->a = a;
    }
}

void Interval::setB(int b)
{
    if (b >= this->a)
    {
        this->b = b;
    }
}

int Interval::length() const
{
    return this->b - this->a + 1;
}

bool Interval::isIncluded(int number) const
{
    if (number >= this->a && number <= this->b)
    {
        return true;
    }
    return false;
}

// int Interval::countOfPrimeNumbers() const {}
// int Interval::countOfPalindromes() const {}
// int Interval::countOfNoRepeating() const {}

bool Interval::isPowerOfTwo() const
{
    int powerOfTwo = 0;
    if ((this->a & 1) && (this->b & 1))
    {
        return true;
    }
    return false;
}

Interval Interval::intersection(const Interval &other) const
{
    Interval intersection;

    if ((other.a >= this->a && other.a <= this->b && this->b >= other.a && this->b <= other.b) ||
        (this->a >= other.a && this->a <= other.b && other.b >= this->a && other.b <= this->b))
    {
        intersection.a = (this->a >= other.a) ? this->a : other.a;
        intersection.b = (this->b <= other.b) ? this->b : other.b;
    }
    else
    {
        intersection.a = 0;
        intersection.b = 0;
    }

    return intersection;
}

Interval Interval::Union(const Interval &other) const
{
    Interval Union;

    if ((other.a >= this->a && other.a <= this->b && this->b >= other.a && this->b <= other.b) ||
        (this->a >= other.a && this->a <= other.b && other.b >= this->a && other.b <= this->b))
    {
        Union.a = (this->a <= other.a) ? this->a : other.a;
        Union.b = (this->b >= other.b) ? this->b : other.b;
    }
    else
    {
        Union.a = 0;
        Union.b = 0;
    }

    return Union;
}

bool Interval::isSubInterval(const Interval &other) const
{
    if (other.a >= this->a && other.a <= this->b &&
        other.b >= this->a && other.b <= this->b)
    {
        return true;
    }
    return false;
}

void Interval::print() const
{
    std::cout << "[" << this->a << ", " << this->b << "]" << std::endl;
}