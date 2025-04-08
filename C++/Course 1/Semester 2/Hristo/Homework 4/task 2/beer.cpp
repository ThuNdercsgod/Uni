#include <cstring>
#include <stdexcept>

#include "beer.hpp"

// Might throw int 1
Beer::Beer(const char *brand, int volume)
{
    if (strlen(brand) <= 128 && volume > 0)
    {
        strcpy(this->brand, brand);
        this->volume = volume;
    }
    else
    {
        throw 1;
    }
}

const char *Beer::getBrand() const
{
    return this->brand;
}

int Beer::getVolume() const
{
    return this->volume;
}

// Might throw int 1
void Beer::add(Beer beer)
{
    if ((strlen(this->brand) + strlen(beer.brand) + 1) <= 128)
    {
        strcat(this->brand, "&");
        strcat(this->brand, beer.brand);

        this->volume += beer.volume;
    }
    else
    {
        throw 1;
    }
}

// Might throw 1;
void Beer::fill(int volume)
{
    if (volume > 0)
    {
        this->volume += volume;
    }
    else
    {
        throw 1;
    }
}

bool Beer::check(const char *brand) const
{
    if (strstr(this->brand, brand) != nullptr)
    {
        return true;
    }
    return false;
}