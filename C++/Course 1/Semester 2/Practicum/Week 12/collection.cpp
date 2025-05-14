#include <cstring>
#include <iostream>

#include "collection.hpp"
#include "media.hpp"

// Might throw std::bad_alloc or std::invalid_argument
Collection::Collection()
    : items(nullptr), numOfItems(0)
{
    strcpy(this->name, "Unknown");
}

// Might throw std::bad_alloc or std::invalid_argument
Collection::Collection(const char *name, Media **items, int numOfItems)
{
    if (numOfItems < 0 || name == nullptr)
    {
        throw std::invalid_argument("Invalid parameters for Collection creation!");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->items = new (std::nothrow) Media *[numOfItems];
    if (this->items == nullptr)
    {
        delete[] this->name;
        this->name = nullptr;
        throw std::bad_alloc();
    }

    for (int i = 0; i < numOfItems; i++)
    {
        this->items[i] = items[i];
    }

    this->numOfItems = numOfItems;
}

// Might throw std::bad_alloc
Collection::Collection(const Collection &other)
{
    delete[] this->name;
    this->name = nullptr;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->items = new (std::nothrow) Media *[other.numOfItems];
    if (this->items == nullptr)
    {
        delete[] this->name;
        this->name = nullptr;
        throw std::bad_alloc();
    }

    for (int i = 0; i < other.numOfItems; i++)
    {
        this->items[i] = other.items[i];
        this->items[i]->setOwner(this);
    }

    this->numOfItems = other.numOfItems;
}

Collection::~Collection()
{
    delete[] this->name;
    this->name = nullptr;

    delete[] this->items;
    this->items = nullptr;
}

Collection &Collection::operator=(const Collection &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = nullptr;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->items = new (std::nothrow) Media *[other.numOfItems];
        if (this->items == nullptr)
        {
            delete[] this->name;
            this->name = nullptr;
            throw std::bad_alloc();
        }

        for (int i = 0; i < other.numOfItems; i++)
        {
            this->items[i] = other.items[i];
            this->items[i]->setOwner(this);
        }

        this->numOfItems = other.numOfItems;
    }
    return *this;
}

void Collection::print() const
{
    std::cout << "\n=== Collection "
              << this->name << " ===\n"
              << "Media: ";

    for (int i = 0; i < this->numOfItems; i++)
    {
        std::cout << "\n\t";
        this->items[i]->print();
    }
    std::cout << std::endl;
}

const char *Collection::getName() const
{
    return this->name;
}