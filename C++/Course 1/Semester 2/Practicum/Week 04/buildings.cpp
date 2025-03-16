#include <cstring>
#include <fstream>
#include <iostream>

#include "buildings.hpp"

void BuildingsInfo::input(Building *building, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the name of the building:" << std::endl;
        std::cin.ignore();
        std::cin.getline(building[i].name, 32);

        building[i].type = BuildingsInfo::inputType();

        std::cout << "Enter the x-coordinate of the building:";
        building[i].location.x = inputCoordinates();
        std::cout << "Enter the y-coordinate of the building:";
        building[i].location.y = inputCoordinates();

        std::cout << "Enter the status of the bulding:" << std::endl;
        std::cout << "Work state: ";
        building[i].status.workState = inputNumber();
        std::cout << "Power level: ";
        building[i].status.powerLevel = inputNumber();
        std::cout << "Occupation level: ";
        building[i].status.occupationLevel = inputNumber();
        std::cout << std::endl;
    }
}

void BuildingsInfo::printInfo(Building *building, int size)
{
    if (size == 0)
    {
        std::cout << "There are no Buildings!" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "=== Building " << i + 1 << " ===" << std::endl;
        std::cout << "Name: " << building[i].name << std::endl;
        std::cout << "Type: " << buildingTypes[building[i].type] << std::endl;
        std::cout << "Location: (" << building[i].location.x << ", " << building[i].location.y << ")" << std::endl;
        std::cout << "Work state: " << building[i].status.workState << "; ";
        std::cout << "Power level: " << building[i].status.powerLevel << "; ";
        std::cout << "Occupation level: " << building[i].status.occupationLevel << std::endl;
        std::cout << std::endl;
    }
}

bool BuildingsInfo::isOperational(Building building)
{
    if (building.status.workState == 0 ||
        building.status.powerLevel == 0 ||
        building.status.occupationLevel == 0)
    {
        return false;
    }

    return true;
}