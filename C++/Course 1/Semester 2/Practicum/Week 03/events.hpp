#pragma once
#include "city_types.hpp"
#include "smartcity.hpp"

struct Event
{
    EmergencyLevel emergencyLevel;
    Location location;
    char description[64];
};

namespace EventsInfo
{
    void input(Event *event, int size);
    void printInfo(Event *event, int size);
    bool saveToFile(Event *event, int size);
    Event *loadFromFile(int &sizeSearch);

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

        bool inFile(int &sizeSearch);
        void byDescription(Event searchParameters, Event *loadedEvent, int sizeSearch);
        void byLevel(Event searchParameters, Event *loadedEvent, int sizeSearch);
        void byLocation(Event searchParameters, Event *loadedEvent, int sizeSearch);
    }
}