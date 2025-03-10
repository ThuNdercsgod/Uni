#include <fstream>
#include <iostream>
#include "buildings.hpp"

void BuildingsInfo::input(Building *building, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the name of the building:" << std::endl;
        std::cin.ignore();
        std::cin.getline(building[i].name, 32);

        building[i].type = inputBuildingType();

        std::cout << "Enter the x-coordinate of the building:" << std::endl;
        building[i].location.x = inputCoordinates();
        std::cout << "Enter the y-coordinate of the building:" << std::endl;
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
        save << "Location: (" << building[i].location.x << ", " << building[i].location.y << ")\n";
        save << "\n";
    }

    save.close();

    return true;
}

bool BuildingsInfo::loadFromFile(Building *building, int size)
{
    std::ifstream load("BuildingsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    load.close();

    return true;
}

bool BuildingsInfo::Search::isValidCriteria(int input)
{
    return (input >= BuildingsInfo::Search::Criteria::Name && input <= BuildingsInfo::Search::Criteria::Location);
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

bool BuildingsInfo::loadFromFile(Building *building, int size)
{
    std::ifstream load("BuildingsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    if (!BuildingsInfo::Search::inFile(load))
    {
        return false;
    }

    load.close();

    return true;
}

bool BuildingsInfo::Search::inFile(std::ifstream &load)
{
    BuildingsInfo::Search::Criteria searchCriteria = BuildingsInfo::Search::input();

    if (searchCriteria == BuildingsInfo::Search::Criteria::Name)
    {
        BuildingsInfo::Search::byName(load);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::Type)
    {
        BuildingsInfo::Search::byType(load);
    }
    else if (searchCriteria == BuildingsInfo::Search::Criteria::Location)
    {
        BuildingsInfo::Search::byLocation(load);
    }
    else
    {
        std::cout << "Input error!";

        return false;
    }

    return true;
}

// TODO
void BuildingsInfo::Search::byName(std::ifstream &load)
{
}

void BuildingsInfo::Search::byType(std::ifstream &load)
{
}

void BuildingsInfo::Search::byLocation(std::ifstream &load)
{
}
// TODO END