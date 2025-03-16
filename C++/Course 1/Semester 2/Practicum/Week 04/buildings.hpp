#pragma once

#include "city_types.hpp"
#include "smartcity.hpp"

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

namespace BuildingsInfo
{
    void input(Building *building, int size);
    void printInfo(Building *building, int size);
    bool isOperational(Building building);
}