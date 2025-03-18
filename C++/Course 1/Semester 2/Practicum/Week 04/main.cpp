#include <iostream>

#include "buildings.hpp"
#include "buildingfile.hpp"
#include "buildingsearch.hpp"
#include "events.hpp"
#include "eventfile.hpp"
#include "eventsearch.hpp"
#include "smartcity.hpp"

int main()
{
    std::cout << "Enter the amount of buildings: ";
    int sizeBuilding = inputNumber();
    Building *building = new Building[sizeBuilding];

    building = BuildingsInfo::BinaryFile::load(sizeBuilding);

    std::cout << "Enter the amount of events: ";
    int sizeEvent = inputNumber();
    Event *event = new Event[sizeEvent];

    if (!building || !event)
    {
        std::cout << "Memory allocation error!" << std::endl;

        return 1;
    }

    // BuildingsInfo::input(building, sizeBuilding);
    //   EventsInfo::input(event, sizeEvent);

    // BuildingsInfo::File::save(building, sizeBuilding);
    // EventsInfo::File::save(event, sizeEvent);

    // int sizeSearchBuilding = 0;
    // if (!BuildingsInfo::Search::inFile(sizeSearchBuilding))
    // {
    //     return 2;
    // }

    // int sizeSearchEvent = 0;
    // if (!EventsInfo::Search::inFile(sizeSearchEvent))
    // {
    //     return 2;
    // }

    // if (!BuildingsInfo::BinaryFile::save(building, sizeBuilding))
    // {
    //     return 1;
    // }

    BuildingsInfo::printInfo(building, sizeBuilding);
    //  printInfoEvent(event, sizeEvent);

    delete[] building;
    building = nullptr;

    delete[] event;
    event = nullptr;

    return 0;
}