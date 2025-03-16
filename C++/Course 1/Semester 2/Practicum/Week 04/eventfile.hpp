#pragma once

#include "events.hpp"

namespace EventsInfo
{
    namespace File
    {
        bool save(Event *event, int size);
        Event *load(int &sizeLoaded);
    }

    namespace BinaryFile
    {

    }
}