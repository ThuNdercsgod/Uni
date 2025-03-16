#include <cstring>
#include <fstream>
#include <iostream>

#include "buildings.hpp"
#include "buildingfile.hpp"

bool BuildingsInfo::File::save(Building *building, int size)
{
    std::ofstream save("BuildingsInfo.txt");

    if (!save.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    save << "=== Total buildings: " << size << " ===\n"
         << std::endl;

    for (int i = 0; i < size; ++i)
    {
        save << "[Building " << i + 1 << "]\n";
        save << "Name: " << building[i].name << "\n";
        save << "Type: " << buildingTypes[building[i].type] << "\n";
        save << "Work state: " << (int)building[i].status.workState << "\n";
        save << "Power level: " << (int)building[i].status.powerLevel << "\n";
        save << "Occupation level: " << (int)building[i].status.occupationLevel << "\n";
        save << "Location: (" << building[i].location.x << ", " << building[i].location.y << ")\n";
        save << "\n";
    }

    save.close();

    return true;
}

Building *BuildingsInfo::File::load(int &sizeLoaded)
{
    sizeLoaded = 0;
    std::ifstream load("BuildingsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return nullptr;
    }

    char lineBuffer[256];

    load.getline(lineBuffer, 255);
    sscanf(lineBuffer, "=== Total buildings: %d ===", &sizeLoaded);
    load.getline(lineBuffer, 255);

    Building *loadedBuilding = new (std::nothrow) Building[sizeLoaded];
    if (!loadedBuilding)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return nullptr;
    }

    int i = 0;
    while (load.getline(lineBuffer, 255) && i < sizeLoaded)
    {
        if (strncmp(lineBuffer, "[Building", 9) == 0)
        {
            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Name: %[^\n]", loadedBuilding[i].name);

            load.getline(lineBuffer, sizeof(lineBuffer));
            char type[32];
            sscanf(lineBuffer, "Type: %[^\n]", type);
            for (int j = 0; j < sizeof(buildingTypes) / sizeof(buildingTypes[0]); ++j)
            {
                if (strcmp(type, buildingTypes[j]) == 0)
                {
                    loadedBuilding[i].type = (BuildingType)j;
                    break;
                }
            }

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Work state: %d", loadedBuilding[i].status.workState);

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Power level: %d", loadedBuilding[i].status.powerLevel);

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Occupation level: %d", loadedBuilding[i].status.occupationLevel);

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Location: (%d, %d)", &loadedBuilding[i].location.x, &loadedBuilding[i].location.y);

            ++i;
        }
    }

    load.close();

    return loadedBuilding;
}

bool BuildingsInfo::BinaryFile::save(Building *building, int size)
{
    char lineBuffer[256];

    std::ofstream save("BuildingsInfo.bin", std::ios::binary);

    if (!save.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    save.write("=== Total buildings: ", 22);
    save.write((char *)&size, sizeof(size));
    save.write(" ===\n", 6);

    for (int i = 0; i < size; i++)
    {
        int n = i + 1;
        save.write("[Building ", 11);
        save.write((char *)&n, sizeof(n));
        save.write("]\n", 3);

        save.write("Name: ", 7);
        save.write(building[i].name, strlen(building[i].name));
        save.write("\n", 2);

        save.write("Type: ", 7);
        save.write((char *)buildingTypes[building[i].type], strlen(buildingTypes[building[i].type]));
        save.write("\n", 2);

        int temp = building[i].status.workState;
        save.write("Work state: ", 13);
        save.write((char *)&temp, sizeof(temp));
        save.write("\n", 2);

        temp = building[i].status.powerLevel;
        save.write("Power level: ", 14);
        save.write((char *)&temp, sizeof(temp));
        save.write("\n", 2);

        temp = building[i].status.occupationLevel;
        save.write("Occupation level: ", 19);
        save.write((char *)&temp, sizeof(temp));
        save.write("\n", 2);

        save.write("Location: (", 12);
        save.write((char *)&building[i].location.x, sizeof(building[i].location.x));
        save.write(", ", 3);
        save.write((char *)&building[i].location.y, sizeof(building[i].location.y));
        save.write(")\n", 3);
    }

    save.close();

    return true;
}

Building *BuildingsInfo::BinaryFile::load(int &sizeLoaded)
{
    sizeLoaded = 0;
    std::ifstream load("BuildingsInfo.bin", std::ios::binary);

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return nullptr;
    }

    char lineBuffer[256];

    load.seekg(22, std::ios::beg);
    load.read((char *)&sizeLoaded, sizeof(int));

    Building *loadedBuilding = new (std::nothrow) Building[sizeLoaded];

    if (!loadedBuilding)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return nullptr;
    }

    load.seekg(57, std::ios::beg);

    // TODO finish this up

    // int i = 0;
    // while (load.getline(lineBuffer, 255) && i < sizeLoaded)
    // {
    //     if (strncmp(lineBuffer, "[Building", 9) == 0)
    //     {
    //         load.getline(lineBuffer, sizeof(lineBuffer));
    //         sscanf(lineBuffer, "Name: %[^\n]", loadedBuilding[i].name);

    //         load.getline(lineBuffer, sizeof(lineBuffer));
    //         char type[32];
    //         sscanf(lineBuffer, "Type: %[^\n]", type);
    //         for (int j = 0; j < sizeof(buildingTypes) / sizeof(buildingTypes[0]); ++j)
    //         {
    //             if (strcmp(type, buildingTypes[j]) == 0)
    //             {
    //                 loadedBuilding[i].type = (BuildingType)j;
    //                 break;
    //             }
    //         }

    //         load.getline(lineBuffer, sizeof(lineBuffer));
    //         // sscanf(lineBuffer, "Work state: %d", building[i].status.workState);

    //         load.getline(lineBuffer, sizeof(lineBuffer));
    //         // sscanf(lineBuffer, "Power level: %d", building[i].status.powerLevel);

    //         load.getline(lineBuffer, sizeof(lineBuffer));
    //         // sscanf(lineBuffer, "Occupation level: %d", building[i].status.occupationLevel);

    //         load.getline(lineBuffer, sizeof(lineBuffer));
    //         sscanf(lineBuffer, "Location: (%d, %d)", &loadedBuilding[i].location.x, &loadedBuilding[i].location.y);

    //         ++i;
    //     }
    // }

    load.close();

    return loadedBuilding;
}