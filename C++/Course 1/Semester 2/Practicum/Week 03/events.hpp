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
    std::ifstream loadFromFile(Event *event, int size);

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

        bool inFile(Event *event, int size);
        void byDescription(std::ifstream &load, Event searchParameters, Event *event, int size);
        void byLevel(std::ifstream &load, Event searchParameters, Event *event, int size);
        void byLocation(std::ifstream &load, Event searchParameters, Event *event, int size);
    }
}