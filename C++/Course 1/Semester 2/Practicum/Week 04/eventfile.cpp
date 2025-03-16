#include <cstring>
#include <fstream>
#include <iostream>

#include "events.hpp"
#include "eventfile.hpp"

bool EventsInfo::File::save(Event *event, int size)
{
    std::ofstream save("EventsInfo.txt");

    if (!save.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    save << "=== Total events: " << size << " ===\n"
         << std::endl;

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

Event *EventsInfo::File::load(int &sizeLoaded)
{
    sizeLoaded = 0;
    std::ifstream load("EventsInfo.txt");

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return nullptr;
    }

    char lineBuffer[256];

    load.getline(lineBuffer, 255);
    sscanf(lineBuffer, "=== Total events: %d ===", &sizeLoaded);
    load.getline(lineBuffer, 255);

    Event *loadedEvent = new (std::nothrow) Event[sizeLoaded];
    if (!loadedEvent)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return nullptr;
    }

    int i = 0;
    while (load.getline(lineBuffer, 255) && i < sizeLoaded)
    {
        if (strncmp(lineBuffer, "[Event", 6) == 0)
        {
            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Description: %[^\n]", loadedEvent[i].description);

            load.getline(lineBuffer, sizeof(lineBuffer));
            char level[32];
            sscanf(lineBuffer, "Level: %[^\n]", level);
            for (int j = 0; j < sizeof(emergencyLevels) / sizeof(emergencyLevels[0]); ++j)
            {
                if (strcmp(level, emergencyLevels[j]) == 0)
                {
                    loadedEvent[i].emergencyLevel = (EmergencyLevel)j;
                    break;
                }
            }

            load.getline(lineBuffer, sizeof(lineBuffer));
            sscanf(lineBuffer, "Location: (%d, %d)", &loadedEvent[i].location.x, &loadedEvent[i].location.y);

            i++;
        }
    }

    load.close();

    return loadedEvent;
}