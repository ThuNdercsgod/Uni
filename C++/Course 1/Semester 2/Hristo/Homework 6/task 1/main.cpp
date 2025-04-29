#include <iostream>

#include "nvector.hpp"

int main()
{
    Point A(1, 2);
    Point B;
    Nvector v(A, B);

    return 0;
}