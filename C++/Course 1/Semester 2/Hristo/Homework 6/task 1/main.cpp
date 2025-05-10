#include <iostream>

#include "nvector.hpp"

int main()
{
    std::cout << "=== Testing construction ===" << std::endl;

    Nvector def;
    // Should return (0, 0)
    def.print();

    Point A(1, 1);
    Point B(2, 2);
    Nvector points(A, B);
    // Should return (1, 1)
    points.print();

    Nvector copy(def);
    // Should return (0, 0)
    copy.print();

    std::cout << "\n=== Testing operators ===" << std::endl;

    Nvector equal = points;
    // Should return (1, 1)
    equal.print();

    Point C(2, 5);
    Nvector add1(A, B);
    Nvector add2(B, C);
    Nvector add = add1 + add2;
    // Should return (1, 1)
    add.getStart().print();
    // Should return (2, 5)
    add.getEnd().print();

    std::cout << std::endl;

    add = add2 + add1;
    // Should return (1, 1)
    add.getStart().print();
    // Should return (2, 5)
    add.getEnd().print();

    std::cout << std::endl;

    Nvector multiply(A, B);
    // Should return 4.24264
    std::cout << multiply * 3;

    std::cout << "\n=== Testing exception handling ===" << std::endl;
    Nvector exc1(A, C);
    try
    {
        Nvector exc = exc1 + def;
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Testing output and input ===" << std::endl;
    // Should return (1, 1)
    std::cout << points << std::endl;

    return 0;
}