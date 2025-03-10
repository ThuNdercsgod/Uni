#pragma once
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
    bool saveToFile(Building *building, int size);
    bool loadFromFile(Building *building, int size);

    namespace Search
    {
        enum Criteria
        {
            Name,
            Type,
            Location
        };

        // const char *const criteriaName[] = {"Level",
        //                         "Description",
        //                         "Location"};

        bool isValidCriteria(int input);
        Criteria input();

        bool inFile(std::ifstream &load);
        void byName(std::ifstream &load);
        void byType(std::ifstream &load);
        void byLocation(std::ifstream &load);
    }
}