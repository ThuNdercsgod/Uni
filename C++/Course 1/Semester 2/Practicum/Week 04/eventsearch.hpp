#pragma once

#include "events.hpp"

namespace EventsInfo
{
    namespace Search
    {
        enum Criteria
        {
            DESCRIPRION,
            LEVEL,
            LOCATION
        };

        //* const char *const criteriaName[] = {"Level",
        //*                         "Description",
        //*                         "Location"};

        bool isValidCriteria(int input);
        Criteria input();

        bool inFile(int &sizeLoaded);
        void byDescription(Event searchParameters, Event *loadedEvent, int sizeLoaded);
        void byLevel(Event searchParameters, Event *loadedEvent, int sizeLoaded);
        void byLocation(Event searchParameters, Event *loadedEvent, int sizeLoaded);
    }
}