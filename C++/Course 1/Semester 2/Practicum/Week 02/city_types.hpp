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

const int minType = BuildingType::RESIDENTIAL;
const int maxType = BuildingType::FIRESTATION;

const char *const buildingTypes[] = {"Residential",
                                     "Hospital",
                                     "Police",
                                     "Fire station"};

const char *const emergencyLevels[] = {"Low",
                                       "Medium",
                                       "High"};

bool isValidBuildingType(int type);
bool isValidEmergencyLevel(int emergency);

void printMenuBuilding();
void printMenuEvent();

BuildingType inputBuildingType();
EmergencyLevel inputEmergencyLevel();