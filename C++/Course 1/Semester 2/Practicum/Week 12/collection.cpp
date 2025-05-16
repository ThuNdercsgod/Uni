#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "collection.hpp"
#include "media.hpp"

// Might throw std::bad_alloc or std::invalid_argument
Collection::Collection()
    : Collection("Unknown") {}

// Might throw std::bad_alloc or std::invalid_argument
Collection::Collection(const char *name)
{
    if (name == nullptr)
    {
        throw std::invalid_argument("Invalid parameters for Collection creation!");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->numOfItems = numOfItems;
}

// Might throw std::bad_alloc
Collection::Collection(const Collection &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    // this->items points to a dynamic array of pointers to media objects
    this->items = new (std::nothrow) Media *[other.numOfItems];
    if (!this->items)
    {
        delete[] this->name;
        this->name = nullptr;
        throw std::bad_alloc();
    }

    for (int i = 0; i < other.numOfItems; i++)
    {
        // Every pointer from this->items points to the corresponding Media object form other
        this->items[i] = new (std::nothrow) Media(*other.items[i]); // !!! Important to put Media constructor here
        if (!this->items[i])
        {
            delete[] this->name;
            this->name = nullptr;
            this->freeItems(i); // Frees the pointers before i and frees the array itself
            throw std::bad_alloc();
        }
        this->items[i]->setOwner(this);
    }

    this->numOfItems = other.numOfItems;
}

Collection::~Collection()
{
    delete[] this->name;
    this->name = nullptr;

    this->freeItems(this->numOfItems); // Frees all of the pointers and the array itself
}

Collection &Collection::operator=(const Collection &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];

        this->freeItems(this->numOfItems);

        // this->items points to a dynamic array of pointers to media objects
        this->items = new (std::nothrow) Media *[other.numOfItems];
        if (!this->items)
        {
            delete[] this->name;
            this->name = nullptr;
        }
        strcpy(this->name, other.name);

        for (int i = 0; i < other.numOfItems; i++)
        {
            // Every pointer from this->items points to the corresponding Media object form other
            this->items[i] = new (std::nothrow) Media(*other.items[i]); // !!! Important to put Media constructor here
            if (!this->items[i])
            {
                delete[] this->name;
                this->name = nullptr;
                this->freeItems(i); // Frees the pointers before i and frees the array itself
                throw std::bad_alloc();
            }
            this->items[i]->setOwner(this);
        }

        this->numOfItems = other.numOfItems;
    }
    return *this;
}

void Collection::addMedia(const Media *media)
{
    Collection temp = *this;

    this->freeItems(this->numOfItems);
    this->numOfItems++;

    // this->items points to a dynamic array of pointers to media objects
    this->items = new (std::nothrow) Media *[this->numOfItems];
    if (!this->items)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }

    for (int i = 0; i < temp.numOfItems; i++)
    {
        // Every pointer from this->items points to the corresponding Media object form other
        this->items[i] = new (std::nothrow) Media(*temp.items[i]); // !!! Important to put Media constructor here
        if (!this->items[i])
        {
            delete[] this->name;
            this->freeItems(i); // Frees the pointers before i and frees the array itself
            throw std::bad_alloc();
        }
        this->items[i]->setOwner(this);
    }

    this->items[this->numOfItems - 1] = new (std::nothrow) Media(*media);
    if (!this->items[this->numOfItems - 1])
    {
        delete[] this->name;
        this->freeItems(this->numOfItems - 1); // Frees the pointers before numOfItems - 1 and frees the array itself
        throw std::bad_alloc();
    }
    this->items[this->numOfItems - 1]->setOwner(this);
}

void Collection::removeMedia(Media *media)
{
    Collection temp = *this;

    this->freeItems(this->numOfItems);
    this->numOfItems--;

    // this->items points to a dynamic array of pointers to media objects
    this->items = new (std::nothrow) Media *[this->numOfItems];
    if (!this->items)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }

    int index = 0;                            // index is for the current Collection (one less element)
    for (int i = 0; i < temp.numOfItems; i++) // i is for the other Collection
    {
        if (media != temp.items[i]) // Don't put the removed Media
        {
            // Every pointer from this->items points to the corresponding Media object form other
            this->items[index] = new (std::nothrow) Media(*temp.items[i]); // !!! Important to put Media constructor here
            if (!this->items[index])
            {
                delete[] this->name;
                this->freeItems(index); // Frees the pointers before i and frees the array itself
                throw std::bad_alloc();
            }
            this->items[i]->setOwner(this);
            index++;
        }
    }
    media->setOwner(nullptr);
}

// Might throw std::ios_bas::failure or std::bad_alloc
void Collection::saveToFile(const char *fileName) const
{
    std::ofstream save(fileName, std::ios::binary);
    if (!save.is_open())
    {
        throw std::ios_base::failure("Could not open file!");
    }
    int size = strlen(this->name);
    save.write((const char *)&size, sizeof(int));
    save.write(this->name, size);
    save.write((const char *)&this->numOfItems, sizeof(int));

    for (int i = 0; i < this->numOfItems; i++)
    {
        this->items[i]->saveToFile(save);
    }

    save.close();
}

// Might throw std::ios_base::failure or std::bad_alloc
void Collection::loadFromFile(const char *fileName)
{
    delete[] this->name;
    this->freeItems(this->numOfItems);

    std::ifstream load(fileName, std::ios::binary);
    if (!load.is_open())
    {
        throw std::ios_base::failure("Could not open file!");
    }

    int nameSize;
    load.read((char *)&nameSize, sizeof(int));
    this->name = new char[nameSize + 1];
    load.read(this->name, nameSize);
    this->name[nameSize] = '\0';
    load.read((char *)&this->numOfItems, sizeof(int));

    unsigned int id;
    load.read((char *)&id, sizeof(unsigned int));

    this->items = new (std::nothrow) Media *[this->numOfItems];
    if (!this->items)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }

    for (int i = 0; i < this->numOfItems; i++)
    {
        this->items[i] = new (std::nothrow) Media(load, id);
        if (!this->items[i])
        {
            delete[] this->name;
            freeItems(i);
            throw std::bad_alloc();
        }
        this->items[i]->setOwner(this);
    }

    load.close();
}

float Collection::calculateTotalLateFees(unsigned int daysLate) const
{
    float fees = 0;

    for (int i = 0; i < this->numOfItems; i++)
    {
        fees += this->items[i]->calculateLateFee(daysLate);
    }

    return fees;
}

void Collection::print() const
{
    std::cout << "\n=== Collection "
              << this->name << " ===\n"
              << "Media: ";

    for (int i = 0; i < this->numOfItems; i++)
    {
        std::cout << "\n\t";
        this->items[i]->displayInfo();
    }
    std::cout << std::endl;
}

const char *Collection::getName() const
{
    return this->name;
}

void Collection::freeItems(int numOfItems)
{
    if (this->items != nullptr)
    {
        for (int j = 0; j < numOfItems; j++)
        {
            delete this->items[j];
            this->items[j] = nullptr;
        }
        delete[] this->items;
        this->items = nullptr;
    }
}