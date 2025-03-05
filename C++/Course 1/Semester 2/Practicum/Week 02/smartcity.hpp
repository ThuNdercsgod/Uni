#pragma once
#include "city_types.hpp"

struct Location
{
    int x;
    int y;
};

struct BuildingStatus
{
    int workState : 1;
    int powerLevel : 2;
    int occupationLevel : 2;
};

struct Building
{
    char name[32];
    BuildingType type;
    Location location;
    BuildingStatus status;
};

struct Event
{
    EmergencyLevel emergencyLevel;
    Location location;
    char description[64];
};

int inputNumber();
int inputCoordinates();

void inputBuilding(Building *building, int size);
void inputEvent(Event *event, int size);

void printInfoBuilding(Building *building, int size);
void printInfoEvent(Event *event, int size);