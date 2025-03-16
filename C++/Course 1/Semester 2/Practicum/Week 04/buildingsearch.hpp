#pragma once

#include "buildings.hpp"

namespace BuildingsInfo
{
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

        bool inFile(int &sizeLoaded);
        void byName(Building searchParameters, Building *loadedBuilding, int sizeLoaded);
        void byType(Building searchParameters, Building *loadedBulding, int sizeLoaded);
        void byLocation(Building searchParameters, Building *loadedBuilding, int sizeLoaded);
        void byOperational(Building searchParameters, Building *loadedBuilding, int sizeLoaded);
    }
}