#include <fstream>
#include <iostream>
#include <cstring>
#include "buildings.hpp"

void BuildingsInfo::input(Building *building, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the name of the building:" << std::endl;
        std::cin.ignore();
        std::cin.getline(building[i].name, 32);

        building[i].type = BuildingsInfo::inputType();

        std::cout << "Enter the x-coordinate of the building:";
        building[i].location.x = inputCoordinates();
        std::cout << "Enter the y-coordinate of the building:";
        building[i].location.y = inputCoordinates();

        std::cout << "Enter the status of the bulding:" << std::endl;
        std::cout << "Work state: ";
        building[i].status.workState = inputNumber();
        std::cout << "Power level: ";
        building[i].status.powerLevel = inputNumber();
        std::cout << "Occupation level: ";
        building[i].status.occupationLevel = inputNumber();
        std::cout << std::endl;
    }
}

void BuildingsInfo::printInfo(Building *building, int size)
{
    if (size == 0)
    {
        std::cout << "There are no BuildingsInfo!" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "Building information:" << std::endl;
        std::cout << "Name: " << building[i].name << std::endl;
        std::cout << "Type: " << buildingTypes[building[i].type] << std::endl;
        std::cout << "Location: (" << building[i].location.x << ", " << building[i].location.y << ")" << std::endl;
        std::cout << "Work state: " << building[i].status.workState << "; ";
        std::cout << "Power level: " << building[i].status.powerLevel << "; ";
        std::cout << "Occupation level: " << building[i].status.occupationLevel << std::endl;
    }
}

bool BuildingsInfo::saveToFile(Building *building, int size)
{
    std::ofstream save("BuildingsInfo.txt");

    if (!save.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    for (int i = 0; i < size; ++i)
    {
        save << "[Building " << i + 1 << "]\n";
        save << "Name: " << building[i].name << "\n";
        save << "Type: " << buildingTypes[building[i].type] << "\n";
        save << "Work state: " << building[i].status.workState << "\n";
        save << "Power level: " << building[i].status.powerLevel << "\n";
        save << "Occupation level: " << building[i].status.occupationLevel << "\n";
        save << "Location: (" << building[i].location.x << ", " << building[i].location.y << ")\n";
        save << "\n";
    }

    save.close();

    return true;
}

// TODO make it load the info from the file into a dynamic building
std::ifstream BuildingsInfo::loadFromFile(Building *building, int size)
{
    std::ifstream load("BuildingsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return nullptr;
    }

    return load;
}
// TODO end

bool BuildingsInfo::Search::isValidCriteria(int input)
{
    return (input >= BuildingsInfo::Search::Criteria::NAME && input <= BuildingsInfo::Search::Criteria::LOCATION);
}

BuildingsInfo::Search::Criteria BuildingsInfo::Search::input()
{
    int input = -1;
    bool valid = false;

    std::cout << "Search criterias:" << std::endl;
    std::cout << "1. By name\n2. By type\n3. By location" << std::endl;
    std::cout << "Enter the number representing the search criteria: ";

    do
    {
        std::cin >> input;
        input--;
        valid = BuildingsInfo::Search::isValidCriteria(input);
        if (!valid)
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    } while (!valid);

    return (BuildingsInfo::Search::Criteria)input;
}

bool BuildingsInfo::Search::inFile(Building *building, int size)
{
    Building searchParameters;

    std::ifstream load = BuildingsInfo::loadFromFile(building, size);

    if (!load.is_open())
    {
        return false;
    }

    BuildingsInfo::Search::Criteria searchCriteria = BuildingsInfo::Search::input();

    if (searchCriteria == BuildingsInfo::Search::Criteria::NAME)
    {
        BuildingsInfo::Search::byName(load, searchParameters, building, size);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::TYPE)
    {
        BuildingsInfo::Search::byType(load, searchParameters, building, size);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::LOCATION)
    {
        BuildingsInfo::Search::byLocation(load, searchParameters, building, size);
    }
    else
    {
        std::cout << "Searching error!" << std::endl;

        return false;
    }

    return true;
}

void BuildingsInfo::Search::byName(std::ifstream &load, Building searchParameters, Building *building, int size)
{
    std::cout << "Enter the name of the building: ";
    std::cin.ignore();
    std::cin.getline(searchParameters.name, 32);

    int buildingsCount = 0;
    int nameLength = strlen(searchParameters.name);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(searchParameters.name, building[i].name) == 0)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings named \"" << searchParameters.name << "\": " << buildingsCount << std::endl;
}

void BuildingsInfo::Search::byType(std::ifstream &load, Building searchParameters, Building *building, int size)
{
    std::cout << "Searching for building types:" << std::endl;
    searchParameters.type = BuildingsInfo::inputType();

    int buildingsCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (searchParameters.type == building[i].type)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings with type " << buildingTypes[searchParameters.type] << ": " << buildingsCount << std::endl;
}

void BuildingsInfo::Search::byLocation(std::ifstream &load, Building searchParameters, Building *building, int size)
{
    std::cout << "Enter the x-coordinate of the point: ";
    std::cin >> searchParameters.location.x;
    std::cout << "Enter the y-coordinate of the point: ";
    std::cin >> searchParameters.location.y;
    std::cout << "Enter a search radius around this point: ";
    int radius = inputNumber();

    int buildingsCount = 0;

    for (int i = 0; i < size; i++)
    {
        int distance = distanceBetweenPoints(building[i].location.x, building[i].location.y,
                                             searchParameters.location.x, searchParameters.location.y);

        if (distance <= radius)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings in radius of " << radius << " from the point: " << buildingsCount << std::endl;
}