#include <iostream>

#include "complex.hpp"

void Complex::create()
{
    setA();
    setB();
}

void Complex::addition(Complex first, Complex second)
{
    this->a = first.a + second.a;
    this->b = first.b + second.b;
}

void Complex::subtraction(Complex first, Complex second)
{
    this->a = first.a - second.a;
    this->b = first.b - second.b;
}

void Complex::multiplication(Complex first, Complex second)
{
    this->a = (first.a * second.a) - (first.b * second.b);
    this->b = (first.a * second.b) + (first.b * second.a);
}

void Complex::print()
{
    if (this->a != 0)
    {
        std::cout << this->a << " ";
    }
    if (this->b < 0)
    {
        std::cout << this->b << "i" << std::endl;
    }
    else if (this->b == 0)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << "+ " << this->b << "i" << std::endl;
    }
}

int Complex::getA()
{
    return this->a;
}

int Complex::getB()
{
    return this->b;
}

void Complex::setA()
{
    std::cout << "Enter a:" << std::endl;

    bool valid;
    int temp;
    do
    {
        valid = true;
        std::cin >> temp;

        if (!(temp >= -1000 && temp <= 1000))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);
    this->a = temp;
}

void Complex::setB()
{
    std::cout << "Enter b:" << std::endl;

    bool valid;
    int temp;
    do
    {
        valid = true;
        std::cin >> temp;

        if (!(temp >= -1000 && temp <= 1000))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);
    this->b = temp;
}