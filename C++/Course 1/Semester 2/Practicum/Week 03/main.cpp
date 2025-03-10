#include <iostream>
#include "buildings.hpp"
#include "events.hpp"
#include "smartcity.hpp"

int main()
{
    std::cout << "Enter the amount of buildings: ";
    int size1 = inputNumber();
    Building *building = new Building[size1];

    std::cout << "Enter the amount of events: ";
    int size2 = inputNumber();
    Event *event = new Event[size2];

    if (!building || !event)
    {
        std::cout << "Memory allocation error!" << std::endl;

        return 1;
    }

    BuildingsInfo::input(building, size1);
    EventsInfo::input(event, size2);

    if (!BuildingsInfo::saveToFile(building, size1))
    {
        return 2;
    }
    if (!EventsInfo::saveToFile(event, size2))
    {
        return 2;
    }

    // TODO in buldings.cpp and events.cpp

    // printInfoBuilding(building, size1);
    // printInfoEvent(event, size2);

    delete[] building;
    delete[] event;

    building = nullptr;
    event = nullptr;

    return 0;
}