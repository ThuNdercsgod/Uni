#pragma once

class Interval
{
public:
    Interval();
    Interval(int a, int b);

    int getA() const;
    int getB() const;

    void setA(int a);
    void setB(int b);

    int length() const;
    bool isIncluded(int number) const;

    int countOfPrimeNumbers() const;
    int countOfPalindromes() const;
    int countOfNoRepeating() const;

    bool isPowerOfTwo() const;
    Interval intersection(const Interval &other) const;
    Interval Union(const Interval &other) const;
    bool isSubInterval(const Interval &other) const;

    void print() const;

private:
    int a;
    int b;
};