#pragma once

class Point
{
public:
    Point();
    Point(int x, int y);

    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};