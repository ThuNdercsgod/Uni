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
        std::cout << "There are no Buildings!" << std::endl;
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

Building *BuildingsInfo::loadFromFile(int &sizeSearch)
{
    sizeSearch = 0;
    std::ifstream load("BuildingsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return nullptr;
    }

    char lineBuffer[256];
    char *line = lineBuffer;
    while (load.getline(lineBuffer, 256))
    {
        if (strncmp(lineBuffer, "[Building", 9) == 0)
        {
            sizeSearch++;
        }
    }

    Building *building = new (std::nothrow) Building[sizeSearch];
    if (!building)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return nullptr;
    }

    load.clear();
    load.seekg(0, std::ios::beg);

    int i = 0;
    while (load.getline(lineBuffer, 256) && i < sizeSearch)
    {
        if (strncmp(lineBuffer, "[Building", 9) == 0)
        {
            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Name: %[^\n]", building[i].name);

            load.getline(lineBuffer, sizeof(lineBuffer));
            char type[32];
            sscanf(lineBuffer, "Type: %[^\n]", type);
            for (int j = 0; j < sizeof(buildingTypes) / sizeof(buildingTypes[0]); ++j)
            {
                if (strcmp(type, buildingTypes[j]) == 0)
                {
                    building[i].type = (BuildingType)j;
                    break;
                }
            }

            load.getline(lineBuffer, sizeof(lineBuffer));
            // sscanf(lineBuffer, "Work state: %d", building[i].status.workState);

            load.getline(lineBuffer, sizeof(lineBuffer));
            // sscanf(lineBuffer, "Power level: %d", building[i].status.powerLevel);

            load.getline(lineBuffer, sizeof(lineBuffer));
            // sscanf(lineBuffer, "Occupation level: %d", building[i].status.occupationLevel);

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Location: (%d, %d)", &building[i].location.x, &building[i].location.y);

            ++i;
        }
    }

    load.close();

    return building;
}

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

bool BuildingsInfo::Search::inFile(int &sizeSearch)
{
    Building *loadedBuilding = BuildingsInfo::loadFromFile(sizeSearch);
    Building searchParameters;

    if (!loadedBuilding)
    {
        return false;
    }

    BuildingsInfo::Search::Criteria searchCriteria = BuildingsInfo::Search::input();

    if (searchCriteria == BuildingsInfo::Search::Criteria::NAME)
    {
        BuildingsInfo::Search::byName(searchParameters, loadedBuilding, sizeSearch);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::TYPE)
    {
        BuildingsInfo::Search::byType(searchParameters, loadedBuilding, sizeSearch);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::LOCATION)
    {
        BuildingsInfo::Search::byLocation(searchParameters, loadedBuilding, sizeSearch);
    }
    else
    {
        std::cout << "Searching error!" << std::endl;

        return false;
    }

    delete[] loadedBuilding;
    loadedBuilding = nullptr;

    return true;
}

void BuildingsInfo::Search::byName(Building searchParameters, Building *loadedBuilding, int sizeSearch)
{
    std::cout << "Enter the searched name of the building: ";
    std::cin.ignore();
    std::cin.getline(searchParameters.name, 32);

    int buildingsCount = 0;
    int nameLength = strlen(searchParameters.name);

    for (int i = 0; i < sizeSearch; i++)
    {
        if (strcmp(searchParameters.name, loadedBuilding[i].name) == 0)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings named \"" << searchParameters.name << "\": " << buildingsCount << std::endl;
}

void BuildingsInfo::Search::byType(Building searchParameters, Building *loadedBuilding, int sizeSearch)
{
    std::cout << "Searching for building types:" << std::endl;
    searchParameters.type = BuildingsInfo::inputType();

    int buildingsCount = 0;

    for (int i = 0; i < sizeSearch; i++)
    {
        if (searchParameters.type == loadedBuilding[i].type)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings with type " << buildingTypes[searchParameters.type] << ": " << buildingsCount << std::endl;
}

void BuildingsInfo::Search::byLocation(Building searchParameters, Building *loadedBuilding, int sizeSearch)
{
    std::cout << "Enter the x-coordinate of the point: ";
    std::cin >> searchParameters.location.x;
    std::cout << "Enter the y-coordinate of the point: ";
    std::cin >> searchParameters.location.y;
    std::cout << "Enter a search radius around this point: ";
    int radius = inputNumber();

    int buildingsCount = 0;

    for (int i = 0; i < sizeSearch; i++)
    {
        int distance = distanceBetweenPoints(loadedBuilding[i].location.x, loadedBuilding[i].location.y,
                                             searchParameters.location.x, searchParameters.location.y);

        if (distance <= radius)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings in radius of " << radius << " from the point: " << buildingsCount << std::endl;
}