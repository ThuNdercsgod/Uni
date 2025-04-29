#include <cmath>

#include "nvector.hpp"

Nvector::Nvector()
{
    Point A, B;
    this->A = A;
    this->B = B;
    this->length = sqrt((B.getX() - A.getX()) * (B.getX() - A.getX()) + (B.getY() - A.getY()) * (B.getY() - A.getY()));
}

Nvector::Nvector(Point A, Point B)
    : A(A), B(B), length(sqrt((B.getX() - A.getX()) * (B.getX() - A.getX()) + (B.getY() - A.getY()) * (B.getY() - A.getY()))) {}

float Nvector::getLength() const
{
    return this->length;
}