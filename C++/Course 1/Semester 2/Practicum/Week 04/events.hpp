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
}