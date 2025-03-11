#include <iostream>
#include "city_types.hpp"

namespace BuildingsInfo
{
    bool isValidType(int choice)
    {
        return (choice >= BuildingType::RESIDENTIAL && choice <= BuildingType::FIRESTATION);
    }

    void printMenu()
    {
        std::cout << "Building types:" << std::endl;
        for (int i = BuildingType::RESIDENTIAL; i <= BuildingType::FIRESTATION; i++)
        {
            std::cout << i + 1 << ". " << buildingTypes[i] << std::endl;
        }
    }

    BuildingType inputType()
    {
        int input = -1;
        bool valid = false;

        BuildingsInfo::printMenu();
        std::cout << "Enter the number representing the building type: ";
        do
        {
            std::cin >> input;
            input--;
            valid = BuildingsInfo::isValidType(input);
            if (!valid)
            {
                std::cout << "Wrong input! Try again:" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        } while (!valid);

        return (BuildingType)input;
    }
}

namespace EventsInfo
{
    bool isValidLevel(int choice)
    {
        return (choice >= EmergencyLevel::LOW && choice <= EmergencyLevel::HIGH);
    }

    void printMenu()
    {
        std::cout << "Emergency levels:" << std::endl;
        for (int i = EmergencyLevel::LOW; i <= EmergencyLevel::HIGH; i++)
        {
            std::cout << i + 1 << ". " << emergencyLevels[i] << std::endl;
        }
    }

    EmergencyLevel inputLevel()
    {
        int input = -1;
        bool valid = false;

        EventsInfo::printMenu();
        std::cout << "Enter the number representing the emergency level: ";
        do
        {
            std::cin >> input;
            input--;
            valid = EventsInfo::isValidLevel(input);
            if (!valid)
            {
                std::cout << "Wrong input! Try again:" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        } while (!valid);

        return (EmergencyLevel)input;
    }
}