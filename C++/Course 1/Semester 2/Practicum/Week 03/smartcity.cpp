#include <fstream>
#include <iostream>
#include "smartcity.hpp"

int inputNumber()
{
    int number = 0;
    bool valid;

    do
    {
        valid = true;
        std::cin >> number;

        if (!(number >= 0))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);

    return number;
}

int inputCoordinates()
{
    int number = 0;
    bool valid;

    do
    {
        valid = true;
        std::cin >> number;

        if (!(number >= -1000 && number <= 1000))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);

    return number;
}