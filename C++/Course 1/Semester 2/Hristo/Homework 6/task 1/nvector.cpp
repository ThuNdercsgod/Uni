#include <cmath>
#include <iostream>

#include "nvector.hpp"

Nvector::Nvector()
{
    // Start(0, 0) End(0, 0) Length = 0
    Point start, end;
    this->start = start;
    this->end = end;
    this->calculateCoordinates();
    this->calculateLength();
}

Nvector::Nvector(Point start, Point end)
{
    this->start = start;
    this->end = end;
    this->calculateCoordinates();
    this->calculateLength();
}

Nvector::Nvector(const Nvector &other)
{
    this->start = other.start;
    this->end = other.end;
    this->calculateCoordinates();
    this->calculateLength();
}

Nvector Nvector::operator=(const Nvector &other)
{
    if (this != &other)
    {
        this->start = other.start;
        this->end = other.end;
        this->calculateCoordinates();
        this->calculateLength();
    }
    return *this;
}

// Might throw std::invalid_argument
Nvector Nvector::operator+(const Nvector &other) const
{
    if (this->end == other.start)
    {
        Nvector result(this->start, other.end);
        return result;
    }
    else if (other.end == this->start)
    {
        Nvector result(other.start, this->end);
        return result;
    }
    else
    {
        throw std::invalid_argument("Invalid vectors for addition!");
    }
}

float Nvector::operator*(int scalar) const
{
    return this->length * scalar;
}

std::ostream &operator<<(std::ostream &os, const Nvector &obj)
{
    if (os.fail() || os.bad())
    {
        return os;
    }

    return os << "(" << obj.x << ", " << obj.y << ")";
}

std::istream &Nvector::operator>>(std::istream &is)
{
    // Ще бъде твърде сложно да се направи само с input stream, понеже
    // моите вектори са направени от точки с координати, т.е. ще ми
    // трябва въвеждане на 4 цели числа от конзолата, което не е опитмално
    return is;
}

bool Nvector::checkParallel(const Nvector &other) const
{
    if (this->start.getX() * this->end.getY() - this->start.getY() * this->end.getX() == 0)
    {
        return true;
    }
    return false;
}

bool Nvector ::checkPerpendicular(const Nvector &other) const
{
    // Трябва да измисля условие за скаларно произведение, за да може косинусът да е 0
    return false;
}

void Nvector::print() const
{
    std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
}

Point Nvector::getStart() const
{
    return this->start;
}

Point Nvector::getEnd() const
{
    return this->end;
}

int Nvector::getX() const
{
    return this->x;
}

int Nvector::getY() const
{
    return this->y;
}

float Nvector::getLength() const
{
    return this->length;
}

void Nvector::setStart(Point newStart)
{
    this->start = newStart;
    calculateLength();
}

void Nvector::setEnd(Point newEnd)
{
    this->end = newEnd;
    this->calculateLength();
}

void Nvector::calculateCoordinates()
{
    this->x = this->end.getX() - this->start.getX();
    this->y = this->end.getY() - this->start.getY();
}

void Nvector::calculateLength()
{
    this->length = sqrt(this->x * this->x + this->y * this->y);
}