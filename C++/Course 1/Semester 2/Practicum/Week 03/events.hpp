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
    bool loadFromFile(Event *event, int size);

    namespace Search
    {
        enum Criteria
        {
            Description,
            Level,
            Location
        };

        // const char *const criteriaName[] = {"Level",
        //                         "Description",
        //                         "Location"};

        bool isValidCriteria(int input);
        Criteria input();

        bool inFile(std::ifstream &load);
        void byDescription(std::ifstream &load);
        void byLevel(std::ifstream &load);
        void byLocation(std::ifstream &load);
    }
}