#pragma once

class Point
{
public:
    Point();
    Point(int x, int y);
    Point(const Point &other);

    Point &operator=(const Point &other);
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

    void print() const;

    int getX() const;
    int getY() const;

    void setX(int newX);
    void setY(int newY);

private:
    int x;
    int y;
};