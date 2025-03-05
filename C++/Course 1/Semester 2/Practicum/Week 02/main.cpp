#include <iostream>
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

    inputBuilding(building, size1);
    inputEvent(event, size2);

    printInfoBuilding(building, size1);
    printInfoEvent(event, size2);

    delete[] building;
    delete[] event;

    building = nullptr;
    event = nullptr;

    return 0;
}