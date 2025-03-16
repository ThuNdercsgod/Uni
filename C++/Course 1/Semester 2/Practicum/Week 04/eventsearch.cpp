#include <cstring>
#include <iostream>

#include "eventfile.hpp"
#include "eventsearch.hpp"

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

bool EventsInfo::Search::inFile(int &sizeLoaded)
{
    Event *loadedEvent = EventsInfo::File::load(sizeLoaded);
    Event searchParameters;

    if (!loadedEvent)
    {
        return false;
    }

    EventsInfo::Search::Criteria searchCriteria = EventsInfo::Search::input();

    if (searchCriteria == EventsInfo::Search::Criteria::DESCRIPRION)
    {
        EventsInfo::Search::byDescription(searchParameters, loadedEvent, sizeLoaded);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::LEVEL)
    {
        EventsInfo::Search::byLevel(searchParameters, loadedEvent, sizeLoaded);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::LOCATION)
    {
        EventsInfo::Search::byLocation(searchParameters, loadedEvent, sizeLoaded);
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

void EventsInfo::Search::byDescription(Event searchParameters, Event *event, int sizeLoaded)
{
    std::cout << "Enter the description of the event: ";
    std::cin.ignore();
    std::cin.getline(searchParameters.description, 32);

    int eventsCount = 0;
    int nameLength = strlen(searchParameters.description);

    for (int i = 0; i < sizeLoaded; i++)
    {
        if (strcmp(searchParameters.description, event[i].description) == 0)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events with description \"" << searchParameters.description << "\": " << eventsCount << std::endl;
}

void EventsInfo::Search::byLevel(Event searchParameters, Event *event, int sizeLoaded)
{
    std::cout << "Searching for event emergency levels:" << std::endl;
    searchParameters.emergencyLevel = EventsInfo::inputLevel();

    int eventsCount = 0;

    for (int i = 0; i < sizeLoaded; i++)
    {
        if (searchParameters.emergencyLevel == event[i].emergencyLevel)
        {
            eventsCount++;
        }
    }

    std::cout << "Amount of events with emergency level ";
    std::cout << emergencyLevels[searchParameters.emergencyLevel] << ": " << eventsCount << std::endl;
}

void EventsInfo::Search::byLocation(Event searchParameters, Event *event, int sizeLoaded)
{
    std::cout << "Enter the x-coordinate of the point: ";
    std::cin >> searchParameters.location.x;
    std::cout << "Enter the y-coordinate of the point: ";
    std::cin >> searchParameters.location.y;
    std::cout << "Enter a search radius around this point: ";
    int radius = inputNumber();

    int eventsCount = 0;

    for (int i = 0; i < sizeLoaded; i++)
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