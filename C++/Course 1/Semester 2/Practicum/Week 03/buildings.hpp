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
    bool saveToFile(Building *building, int size);
    std::ifstream loadFromFile(Building *building, int size);

    namespace Search
    {
        enum Criteria
        {
            NAME,
            TYPE,
            LOCATION
        };

        //* const char *const criteriaName[] = {"Level",
        //*                        "Description",
        //*                        "Location"};

        bool isValidCriteria(int input);
        Criteria input();

        bool inFile(Building *building, int size);
        void byName(std::ifstream &load, Building searchParameters, Building *building, int size);
        void byType(std::ifstream &load, Building searchParameters, Building *building, int size);
        void byLocation(std::ifstream &load, Building searchParameters, Building *building, int size);
    }
}