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

Event *EventsInfo::loadFromFile(int &sizeSearch)
{
    sizeSearch = 0;
    std::ifstream load("EventsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return nullptr;
    }

    char lineBuffer[256];
    char *line = lineBuffer;
    while (load.getline(lineBuffer, 256))
    {
        if (strncmp(lineBuffer, "[Event", 6) == 0)
        {
            sizeSearch++;
        }
    }

    Event *event = new (std::nothrow) Event[sizeSearch];
    if (!event)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return nullptr;
    }

    load.clear();
    load.seekg(0, std::ios::beg);

    int i = 0;
    while (load.getline(lineBuffer, 256) && i < sizeSearch)
    {
        if (strncmp(lineBuffer, "[Event", 6) == 0)
        {
            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Description: %[^\n]", event[i].description);

            load.getline(lineBuffer, sizeof(lineBuffer));
            char level[32];
            sscanf(lineBuffer, "Level: %[^\n]", level);
            for (int j = 0; j < sizeof(emergencyLevels) / sizeof(emergencyLevels[0]); ++j)
            {
                if (strcmp(level, emergencyLevels[j]) == 0)
                {
                    event[i].emergencyLevel = (EmergencyLevel)j;
                    break;
                }
            }

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Location: (%d, %d)", &event[i].location.x, &event[i].location.y);

            ++i;
        }
    }

    load.close();

    return event;
}

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

bool EventsInfo::Search::inFile(int &sizeSearch)
{
    Event *loadedEvent = EventsInfo::loadFromFile(sizeSearch);
    Event searchParameters;

    if (!loadedEvent)
    {
        return false;
    }

    EventsInfo::Search::Criteria searchCriteria = EventsInfo::Search::input();

    if (searchCriteria == EventsInfo::Search::Criteria::DESCRIPRION)
    {
        EventsInfo::Search::byDescription(searchParameters, loadedEvent, sizeSearch);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::LEVEL)
    {
        EventsInfo::Search::byLevel(searchParameters, loadedEvent, sizeSearch);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::LOCATION)
    {
        EventsInfo::Search::byLocation(searchParameters, loadedEvent, sizeSearch);
    }
    else
    {
        std::cout << "Searching error!";

        return false;
    }

    delete[] loadedEvent;
    loadedEvent = nullptr;

    return true;
}

void EventsInfo::Search::byDescription(Event searchParameters, Event *event, int sizeSearch)
{
    std::cout << "Enter the description of the event: ";
    std::cin.ignore();
    std::cin.getline(searchParameters.description, 32);

    int eventsCount = 0;
    int nameLength = strlen(searchParameters.description);

    for (int i = 0; i < sizeSearch; i++)
    {
        if (strcmp(searchParameters.description, event[i].description) == 0)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events with description \"" << searchParameters.description << "\": " << eventsCount << std::endl;
}

void EventsInfo::Search::byLevel(Event searchParameters, Event *event, int sizeSearch)
{
    std::cout << "Searching for event emergency levels:" << std::endl;
    searchParameters.emergencyLevel = EventsInfo::inputLevel();

    int eventsCount = 0;

    for (int i = 0; i < sizeSearch; i++)
    {
        if (searchParameters.emergencyLevel == event[i].emergencyLevel)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events with emergency level ";
    std::cout << emergencyLevels[searchParameters.emergencyLevel] << ": " << eventsCount << std::endl;
}

void EventsInfo::Search::byLocation(Event searchParameters, Event *event, int sizeSearch)
{
    std::cout << "Enter the x-coordinate of the point: ";
    std::cin >> searchParameters.location.x;
    std::cout << "Enter the y-coordinate of the point: ";
    std::cin >> searchParameters.location.y;
    std::cout << "Enter a search radius around this point: ";
    int radius = inputNumber();

    int eventsCount = 0;

    for (int i = 0; i < sizeSearch; i++)
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