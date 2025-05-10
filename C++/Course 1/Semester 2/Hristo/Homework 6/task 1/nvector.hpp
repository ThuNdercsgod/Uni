#pragma once

#include "point.hpp"

class Nvector
{
public:
    Nvector();
    Nvector(Point start, Point end);
    Nvector(const Nvector &other);

    Nvector operator=(const Nvector &other);
    Nvector operator+(const Nvector &lhs) const;
    float operator*(int scalar) const;
    friend std::ostream &operator<<(std::ostream &os, const Nvector &obj);
    std::istream &operator>>(std::istream &is);

    bool checkParallel(const Nvector &other) const;
    bool checkPerpendicular(const Nvector &other) const;

    void print() const;

    Point getStart() const;
    Point getEnd() const;
    int getX() const;
    int getY() const;
    float getLength() const;

    void setStart(Point newStart);
    void setEnd(Point newEnd);

private:
    void calculateCoordinates();
    void calculateLength();

    Point start;
    Point end;
    int x;
    int y;
    float length;
};