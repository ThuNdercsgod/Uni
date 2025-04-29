#pragma once

#include "point.hpp"

class Nvector
{
public:
    Nvector();
    Nvector(Point A, Point B);

    Nvector operator+(const Nvector &other) const;

    float getLength() const;

private:
    Point A;
    Point B;
    float length;
};