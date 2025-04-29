#include "point.hpp"

Point::Point()
    : Point(0, 0) {}

Point::Point(int newX, int newY)
    : x(newX), y(newY) {}

int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}