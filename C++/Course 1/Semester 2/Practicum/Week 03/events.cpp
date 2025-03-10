#include <fstream>
#include <iostream>
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

        event[i].emergencyLevel = inputEmergencyLevel();
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

bool EventsInfo::Search::isValidCriteria(int input)
{
    return (input >= EventsInfo::Search::Criteria::Description && input <= EventsInfo::Search::Criteria::Location);
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

bool EventsInfo::loadFromFile(Event *event, int size)
{
    std::ifstream load("EventsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    if (!EventsInfo::Search::inFile(load))
    {
        return false;
    }

    load.close();

    return true;
}

bool EventsInfo::Search::inFile(std::ifstream &load)
{
    EventsInfo::Search::Criteria searchCriteria = EventsInfo::Search::input();

    if (searchCriteria == EventsInfo::Search::Criteria::Description)
    {
        EventsInfo::Search::byDescription(load);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::Level)
    {
        EventsInfo::Search::byLevel(load);
    }
    else if (searchCriteria == EventsInfo::Search::Criteria::Location)
    {
        EventsInfo::Search::byLocation(load);
    }
    else
    {
        std::cout << "Input error!";

        return false;
    }

    return true;
}

// TODO
void EventsInfo::Search::byDescription(std::ifstream &load)
{
}

void EventsInfo::Search::byLevel(std::ifstream &load)
{
}

void EventsInfo::Search::byLocation(std::ifstream &load)
{
}
// TODO END