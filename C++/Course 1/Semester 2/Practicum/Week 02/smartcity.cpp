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

void inputBuilding(Building *building, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the name of the building:" << std::endl;
        std::cin.ignore();
        std::cin.getline(building[i].name, 32);

        building[i].type = inputBuildingType();

        std::cout << "Enter the x-coordinate of the building:" << std::endl;
        building[i].location.x = inputCoordinates();
        std::cout << "Enter the y-coordinate of the building:" << std::endl;
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

void inputEvent(Event *event, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the description of the event:" << std::endl;
        std::cin.ignore();
        std::cin.getline(event[i].description, 64);

        std::cout << "Enter the x-coordinate of the event:" << std::endl;
        event[i].location.x = inputCoordinates();
        std::cout << "Enter the y-coordinate of the event:" << std::endl;
        event[i].location.y = inputCoordinates();

        event[i].emergencyLevel = inputEmergencyLevel();
    }
}

void printInfoBuilding(Building *building, int size)
{
    if (size == 0)
    {
        std::cout << "There are no buildings!" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "Building information:" << std::endl;
        std::cout << "Name: " << building[i].name << std::endl;
        std::cout << "Type: " << buildingTypes[building[i].type] << std::endl;
        std::cout << "Location: (" << building[i].location.x << ", " << building[i].location.y << ")" << std::endl;
        std::cout << "Work state: " << building[i].status.workState << "; ";
        std::cout << "Power level: " << building[i].status.powerLevel << "; ";
        std::cout << "Occupation level: " << building[i].status.occupationLevel << std::endl;
    }
}

void printInfoEvent(Event *event, int size)
{
    if (size == 0)
    {
        std::cout << "There are no events!" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "Emergency information:" << std::endl;
        std::cout << "Description: " << event[i].description << std::endl;
        std::cout << "Emergency level: " << emergencyLevels[event[i].emergencyLevel] << std::endl;
        std::cout << "Location: (" << event[i].location.x << ", " << event[i].location.y << ")" << std::endl;
    }
}