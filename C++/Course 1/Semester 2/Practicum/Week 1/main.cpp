#include <iostream>

enum BuildingType
{
    RESIDENTIAL = 0,
    HOSPITAL = 1,
    POLICE = 2,
    FIRESTATION = 3
};

enum EmergencyLevel
{
    LOW = 0,
    MEDIUM = 1,
    HIGH = 2
};

namespace
{
    const int minType = BuildingType::RESIDENTIAL;
    const int maxType = BuildingType::FIRESTATION;

    const char *const buildingTypes[] = {"Residential",
                                         "Hospital",
                                         "Police",
                                         "Fire station"};

    const char *const emergencyLevels[] = {"Low",
                                           "Medium",
                                           "High"};

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
        for (int i = minType; i < maxType; i++)
        {
            std::cout << i << ". " << buildingTypes[i] << std::endl;
        }
        std::cout << "Enter the number representing the building type: ";
    }

    void printMenuEmergency()
    {
        std::cout << "Emergency levels:" << std::endl;
        for (int i = EmergencyLevel::LOW; i < EmergencyLevel::HIGH; i++)
        {
            std::cout << i << ". " << emergencyLevels[i] << std::endl;
        }
        std::cout << "Enter the number representing the emergency level: ";
    }
}

BuildingType getBuildingTypeFromUser()
{
    int input;
    bool valid = false;

    printMenuBuilding();
    do
    {
        std::cin >> input;
        valid = isValidBuildingType(input);
        if (valid == false)
        {
            std::cout << "Wrong input! Try again:" << std::endl;
        }
    } while (valid == false);

    return (BuildingType)input;
}

EmergencyLevel getEmergencyLevellFromUser()
{
    int input;
    bool valid = false;

    printMenuEmergency();
    do
    {
        std::cin >> input;
        valid = isValidEmergencyLevel(input);
        if (valid == false)
        {
            std::cout << "Wrong input! Try again:" << std::endl;
        }
    } while (valid == false);

    return (EmergencyLevel)input;
}

void printBuildingType(BuildingType type)
{
    std::cout << "The building type is:" << std::endl;
    std::cout << buildingTypes[type] << std::endl;
}

void printEmergencyLevel(EmergencyLevel type)
{
    std::cout << "The emergency level is:" << std::endl;
    std::cout << emergencyLevels[type] << std::endl;
}

int main()
{
    BuildingType buildingType = getBuildingTypeFromUser();
    EmergencyLevel emergencyLevel = getEmergencyLevellFromUser();

    printBuildingType(buildingType);
    printEmergencyLevel(emergencyLevel);

    return 0;
}