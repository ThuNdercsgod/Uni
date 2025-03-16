#pragma once

#include "buildings.hpp"

namespace BuildingsInfo
{
    namespace File
    {
        bool save(Building *building, int size);
        Building *load(int &sizeLoaded);
    }

    namespace BinaryFile
    {
        bool save(Building *building, int size);
        Building *load(int &sizeLoaded);
    }
}