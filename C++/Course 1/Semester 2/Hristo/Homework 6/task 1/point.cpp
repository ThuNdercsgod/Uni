#include <iostream>

#include "point.hpp"

Point::Point()
    : Point(0, 0) {}

Point::Point(int newX, int newY)
    : x(newX), y(newY) {}

Point::Point(const Point &other)
    : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    return *this;
}

bool Point::operator==(const Point &other) const
{
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point &other) const
{
    return !(this == &other);
}

void Point::print() const
{
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}

int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}

void Point::setX(int newX)
{
    this->x = newX;
}

void Point::setY(int newY)
{
    this->y = newY;
}