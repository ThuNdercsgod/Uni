#include <fstream>
#include <iostream>
#include <cmath>
#include "buildings.hpp"
#include "events.hpp"
#include "smartcity.hpp"

// void printCommands()
// {
//     std::cout << "=== Commands ===" << std::endl;

//     for (int i = Command::INPUT; i <= Command::EXIT; i++)
//     {
//         std::cout << i + 1 << ". " << commandNames[i] << std::endl;
//     }
// }

// void checkCommand(int command, Building *building, Event *event)
// {
//     switch (command)
//     {
//     case 0:
//         break;
//     case 1:
//     case 2:
//     case 3:
//     case 4:
//     case 5:
//     case 6:
//     default:
//     }
// }

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

double distanceBetweenPoints(int x1, int y1, int x2, int y2)
{
    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    return distance;
}