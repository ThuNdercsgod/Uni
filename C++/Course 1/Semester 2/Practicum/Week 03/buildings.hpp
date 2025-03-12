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
    Building *loadFromFile(int &sizeSearch);

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

        bool inFile(int &sizeSearch);
        void byName(Building searchParameters, Building *loadedBuilding, int sizeSearch);
        void byType(Building searchParameters, Building *loadedBukding, int sizeSearch);
        void byLocation(Building searchParameters, Building *loadedBuilding, int sizeSearch);
    }
}