#include <cstring>
#include <iostream>

#include "buildings.hpp"
#include "buildingfile.hpp"
#include "buildingsearch.hpp"

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

bool BuildingsInfo::Search::inFile(int &sizeLoaded)
{
    Building *loadedBuilding = BuildingsInfo::File::load(sizeLoaded);
    Building searchParameters;

    if (!loadedBuilding)
    {
        return false;
    }

    BuildingsInfo::Search::Criteria searchCriteria = BuildingsInfo::Search::input();

    if (searchCriteria == BuildingsInfo::Search::Criteria::NAME)
    {
        BuildingsInfo::Search::byName(searchParameters, loadedBuilding, sizeLoaded);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::TYPE)
    {
        BuildingsInfo::Search::byType(searchParameters, loadedBuilding, sizeLoaded);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::LOCATION)
    {
        BuildingsInfo::Search::byLocation(searchParameters, loadedBuilding, sizeLoaded);
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

void BuildingsInfo::Search::byName(Building searchParameters, Building *loadedBuilding, int sizeLoaded)
{
    std::cout << "Enter the searched name of the building: ";
    std::cin.ignore();
    std::cin.getline(searchParameters.name, 32);

    int buildingsCount = 0;
    int nameLength = strlen(searchParameters.name);

    for (int i = 0; i < sizeLoaded; i++)
    {
        if (strcmp(searchParameters.name, loadedBuilding[i].name) == 0)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings named \"" << searchParameters.name << "\": " << buildingsCount << std::endl;
}

void BuildingsInfo::Search::byType(Building searchParameters, Building *loadedBuilding, int sizeLoaded)
{
    std::cout << "Searching for building types:" << std::endl;
    searchParameters.type = BuildingsInfo::inputType();

    int buildingsCount = 0;

    for (int i = 0; i < sizeLoaded; i++)
    {
        if (searchParameters.type == loadedBuilding[i].type)
        {
            buildingsCount++;
        }
    }

    std::cout << "Amount of buildings with type " << buildingTypes[searchParameters.type] << ": " << buildingsCount << std::endl;
}

void BuildingsInfo::Search::byLocation(Building searchParameters, Building *loadedBuilding, int sizeLoaded)
{
    std::cout << "Enter the x-coordinate of the point: ";
    std::cin >> searchParameters.location.x;
    std::cout << "Enter the y-coordinate of the point: ";
    std::cin >> searchParameters.location.y;
    std::cout << "Enter a search radius around this point: ";
    int radius = inputNumber();

    int buildingsCount = 0;

    for (int i = 0; i < sizeLoaded; i++)
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

void BuildingsInfo::Search::byOperational(Building searchParameters, Building *loadedBuilding, int sizeLoaded)
{
    int buildingsCount = 0;

    for (int i = 0; i < sizeLoaded; i++)
    {
        if (isOperational(loadedBuilding[i]))
        {
            buildingsCount++;
        }
    }

    std::cout << "The amount of operational buildings: " << buildingsCount << std::endl;
}