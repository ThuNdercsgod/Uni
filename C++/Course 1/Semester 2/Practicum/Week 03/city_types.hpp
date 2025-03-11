#pragma once

enum BuildingType
{
    RESIDENTIAL,
    HOSPITAL,
    POLICE,
    FIRESTATION
};

enum EmergencyLevel
{
    LOW,
    MEDIUM,
    HIGH
};

const char *const buildingTypes[] = {"Residential",
                                     "Hospital",
                                     "Police",
                                     "Fire station"};

const char *const emergencyLevels[] = {"Low",
                                       "Medium",
                                       "High"};

namespace BuildingsInfo
{
    bool isValidType(int type);
    void printMenu();
    BuildingType inputType();
}

namespace EventsInfo
{
    bool isValidLevel(int emergency);
    void printMenu();
    EmergencyLevel inputLevel();
}