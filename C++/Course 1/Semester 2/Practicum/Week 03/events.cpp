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
        std::cout << "There are no EventsInfo!" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "Emergency information:" << std::endl;
        std::cout << "Description: " << event[i].description << std::endl;
        std::cout << "Emergency level: " << emergencyLevels[event[i].emergencyLevel] << std::endl;
        std::cout << "Location: (" << event[i].location.x << ", " << event[i].location.y << ")" << std::endl;
    }
}

bool EventsInfo::saveToFile(Event *event, int size)
{
    std::ofstream save("EventsInfo.txt");

    if (!save.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    for (int i = 0; i < size; ++i)
    {
        save << "[Event " << i + 1 << "]\n";
        save << "Description: " << event[i].description << "\n";
        save << "Level: " << emergencyLevels[event[i].emergencyLevel] << "\n";
        save << "Location: (" << event[i].location.x << ", " << event[i].location.y << ")\n";
        save << "\n";
    }

    save.close();

    return true;
}

// TODO make it load the info from the file onto a dynamic event
std::ifstream EventsInfo::loadFromFile(Event *event, int size)
{
    std::ifstream load("EventsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return nullptr;
    }

    return load;
}
// TODO end

bool EventsInfo::Search::isValidCriteria(int input)
{
    return (input >= EventsInfo::Search::Criteria::DESCRIPRION && input <= EventsInfo::Search::Criteria::LOCATION);
}

EventsInfo::Search::Criteria EventsInfo::Search::input()
{
    int input = -1;
    bool valid = false;

    std::cout << "Search criterias:" << std::endl;
    std::cout << "1. By description\n2. By level\n3. By location" << std::endl;
    std::cout << "Enter the number representing the search criteria: ";

    do
    {
        std::cin >> input;
        input--;
        valid = EventsInfo::Search::isValidCriteria(input);
        if (!valid)
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    } while (!valid);

    return (EventsInfo::Search::Criteria)input;
}

bool EventsInfo::Search::inFile(Event *event, int size)
{
    Event searchParameters;

    std::ifstream load = EventsInfo::loadFromFile(event, size);

    if (!load.is_open())
    {
        return false;
    }

    EventsInfo::Search::Criteria searchCriteria = EventsInfo::Search::input();

    if (searchCriteria == EventsInfo::Search::Criteria::DESCRIPRION)
    {
        EventsInfo::Search::byDescription(load, searchParameters, event, size);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::LEVEL)
    {
        EventsInfo::Search::byLevel(load, searchParameters, event, size);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::LOCATION)
    {
        EventsInfo::Search::byLocation(load, searchParameters, event, size);
    }
    else
    {
        std::cout << "Searching error!";

        return false;
    }

    load.close();

    return true;
}

void EventsInfo::Search::byDescription(std::ifstream &load, Event searchParameters, Event *event, int size)
{
    std::cout << "Enter the description of the event: ";
    std::cin.ignore();
    std::cin.getline(searchParameters.description, 32);

    int eventsCount = 0;
    int nameLength = strlen(searchParameters.description);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchParameters.description, event[i].description) == 0)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events with description \"" << searchParameters.description << "\": " << eventsCount << std::endl;
}

void EventsInfo::Search::byLevel(std::ifstream &load, Event searchParameters, Event *event, int size)
{
    std::cout << "Searching for event emergency levels:" << std::endl;
    searchParameters.emergencyLevel = EventsInfo::inputLevel();

    int eventsCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (searchParameters.emergencyLevel == event[i].emergencyLevel)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events with emergency level ";
    std::cout << emergencyLevels[searchParameters.emergencyLevel] << ": " << eventsCount << std::endl;
}

void EventsInfo::Search::byLocation(std::ifstream &load, Event searchParameters, Event *event, int size)
{
    std::cout << "Enter the x-coordinate of the point: ";
    std::cin >> searchParameters.location.x;
    std::cout << "Enter the y-coordinate of the point: ";
    std::cin >> searchParameters.location.y;
    std::cout << "Enter a search radius around this point: ";
    int radius = inputNumber();

    int eventsCount = 0;

    for (int i = 0; i < size; i++)
    {
        int distance = distanceBetweenPoints(event[i].location.x, event[i].location.y,
                                             searchParameters.location.x, searchParameters.location.y);

        if (distance <= radius)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events in radius of " << radius << " from the point: " << eventsCount << std::endl;
}