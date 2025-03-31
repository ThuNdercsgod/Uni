#include <iostream>

#include "car.hpp"

void Car::commands()
{
    bool valid;
    int input;

    (*this).printCommands();
    do
    {
        std::cout << "Enter the number representing a command:" << std::endl;
        std::cin >> input;
        input--;

        switch (input)
        {
        case 0:
            (*this).create();
            break;
        case 1:
            (*this).print();
            break;
        case 2:
            (*this).upgrade();
            break;
        case 3:
            (*this).fill();
            break;
        case 4:
            (*this).drive();
            break;
        case 5:
            (*this).printCommands();
            break;
        case 6:
            valid = true;
            break;
        default:
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
            break;
        }
    } while (!valid);
}

void Car::print()
{
    std::cout << "Horsepower: " << this->horsePower << std::endl;
    std::cout << "Fuel: " << this->fuel << std::endl;
    std::cout << "Distance driven: " << this->distanceDriven << std::endl;
}

void Car::create()
{
    int valid;
    int temp;

    std::cout << "Enter the horsepower of the car:" << std::endl;
    do
    {
        valid = true;
        std::cin >> temp;

        if (!(temp >= 90 && temp <= 150))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (!valid);
    this->horsePower = temp;

    float tem;

    std::cout << "Enter the amount of fuel in the car (in percent):" << std::endl;
    do
    {
        valid = true;
        std::cin >> tem;

        if (!(tem > 0 && tem <= 150))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (!valid);
    this->fuel = tem;
}

void Car::upgrade()
{
    if (this->horsePower == 150 || this->horsePower + 15 >= 150)
    {
        this->horsePower = 150;
        return;
    }

    this->horsePower += 15;
}

void Car::fill()
{
    this->fuel = 100;
}

void Car::drive()
{
    bool valid;
    int distance;

    std::cout << "Enter the amount of distance you want to drive: " << std::endl;
    do
    {
        valid = true;
        std::cin >> distance;

        if (!(distance > 0))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (!valid);

    if (distance * (this->horsePower / 15) >= this->fuel)
    {
        int possibleDistance = 0;

        while ((possibleDistance + 1) * (this->horsePower / 15) < fuel)
        {
            possibleDistance++;
        }

        std::cout << "You can only drive " << possibleDistance << "km!" << std::endl;

        this->fuel -= possibleDistance * (this->horsePower / 15);
        this->distanceDriven += possibleDistance;

        return;
    }
    this->distanceDriven += distance;
    this->fuel -= distance * (this->horsePower / 15);
}

int Car::getHorsePower()
{
    return this->horsePower;
}

float Car::getFuel()
{
    return this->fuel;
}

float Car::getDistanceDriven()
{
    return this->distanceDriven;
}

void Car::printCommands()
{
    std::cout << "=== Commands ===" << std::endl;

    std::cout << "1. Initialize\n"
              << "2. Show car stats\n"
              << "3. Upgrade\n"
              << "4. Fill\n"
              << "5. Drive\n"
              << "6. Show commands\n"
              << "7. Exit"
              << std::endl;
}