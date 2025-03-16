#include <fstream>
#include <iostream>
#include <cstring>
#include "events.hpp"

void EventsInfo::input(Event *event, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the description of the event:" << std::endl;
        std::cin.ignore();
        std::cin.getline(event[i].description, 64);

        std::cout << "Enter the x-coordinate of the event:";
        event[i].location.x = inputCoordinates();
        std::cout << "Enter the y-coordinate of the event:";
        event[i].location.y = inputCoordinates();

        event[i].emergencyLevel = EventsInfo::inputLevel();
    }
}

void EventsInfo::printInfo(Event *event, int size)
{
    if (size == 0)
    {
        std::cout << "There are no Events!" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "=== Emergency " << i + 1 << " ===" << std::endl;
        std::cout << "Description: " << event[i].description << std::endl;
        std::cout << "Emergency level: " << emergencyLevels[event[i].emergencyLevel] << std::endl;
        std::cout << "Location: (" << event[i].location.x << ", " << event[i].location.y << ")" << std::endl;
        std::cout << std::endl;
    }
}