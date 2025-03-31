#include <iostream>

#include "car.hpp"
#include "complex.hpp"

int main()
{
    std::cout << "=== Test Complex ===" << std::endl;

    Complex left, right;

    left.create();
    right.create();

    Complex result;

    result.addition(left, right);
    result.print();

    result.subtraction(left, right);
    result.print();

    result.multiplication(left, right);
    result.print();

    std::cout << "=== Test complete ===" << std::endl;

    std::cout << "=== Test Car ===" << std::endl;

    Car car;

    car.commands();

    std::cout << "=== Test complete ===" << std::endl;

    return 0;
}