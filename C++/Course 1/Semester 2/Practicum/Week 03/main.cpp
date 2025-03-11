#include <iostream>
#include "buildings.hpp"
#include "events.hpp"
#include "smartcity.hpp"

int main()
{
    std::cout << "Enter the amount of buildings: ";
    int sizeBuilding = inputNumber();
    Building *building = new Building[sizeBuilding];

    std::cout << "Enter the amount of events: ";
    int sizeEvent = inputNumber();
    Event *event = new Event[sizeEvent];

    if (!building || !event)
    {
        std::cout << "Memory allocation error!" << std::endl;

        return 1;
    }

    BuildingsInfo::input(building, sizeBuilding);
    EventsInfo::input(event, sizeEvent);

    BuildingsInfo::saveToFile(building, sizeBuilding);
    EventsInfo::saveToFile(event, sizeEvent);

    BuildingsInfo::Search::inFile(building, sizeBuilding);
    EventsInfo::Search::inFile(event, sizeEvent);

    std::cout << "Finished!" << std::endl;

    // TODO in buldings.cpp and events.cpp
    // TODO make them load info from the file onto a dynamic event/building

    // printInfoBuilding(building, sizeBuilding);
    // printInfoEvent(event, sizeEvent);

    delete[] building;
    delete[] event;

    building = nullptr;
    event = nullptr;

    return 0;
}