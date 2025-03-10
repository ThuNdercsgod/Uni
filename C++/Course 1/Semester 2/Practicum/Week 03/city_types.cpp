#include <iostream>
#include "city_types.hpp"

bool isValidBuildingType(int choice)
{
    return (choice >= minType && choice <= maxType);
}

bool isValidEmergencyLevel(int choice)
{
    return (choice >= EmergencyLevel::LOW && choice <= EmergencyLevel::HIGH);
}

void printMenuBuilding()
{
    std::cout << "Building types:" << std::endl;
    for (int i = minType; i <= maxType; i++)
    {
        std::cout << i + 1 << ". " << buildingTypes[i] << std::endl;
    }
}

void printMenuEvent()
{
    std::cout << "Emergency levels:" << std::endl;
    for (int i = EmergencyLevel::LOW; i <= EmergencyLevel::HIGH; i++)
    {
        std::cout << i + 1 << ". " << emergencyLevels[i] << std::endl;
    }
}

BuildingType inputBuildingType()
{
    int input = -1;
    bool valid = false;

    printMenuBuilding();
    std::cout << "Enter the number representing the building type: ";
    do
    {
        std::cin >> input;
        input--;
        valid = isValidBuildingType(input);
        if (!valid)
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    } while (!valid);

    return (BuildingType)input;
}

EmergencyLevel inputEmergencyLevel()
{
    int input = -1;
    bool valid = false;

    printMenuEvent();
    std::cout << "Enter the number representing the emergency level: ";
    do
    {
        std::cin >> input;
        input--;
        valid = isValidEmergencyLevel(input);
        if (!valid)
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    } while (!valid);

    return (EmergencyLevel)input;
}