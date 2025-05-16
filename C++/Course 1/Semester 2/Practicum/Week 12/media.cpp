#include <cstring>
#include <iostream>
// #include <stdexcept>

#include "collection.hpp"
#include "media.hpp"

// Might throw std::bad_alloc
Media::Media()
    : id(0), available(false)
{
    strcpy(this->title, "Unknown");
    this->owner = nullptr;
}

// Might throw std::bad_alloc or std::invalid_argument
Media::Media(const char *title, unsigned int id, bool available)
    : id(id)
{
    if (title == nullptr)
    {
        throw std::invalid_argument("Invalid parameters for Media creation!");
    }

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->available = available;
}

// Might throw std::bad_alloc
Media::Media(const Media &other)
    : id(other.id)
{
    this->title = new char[strlen(other.title) + 1];
    strcpy(this->title, other.title);

    this->available = other.available;

    this->owner = other.owner;
}

Media::Media(std::istream &load, unsigned int id)
    : id(id)
{
    if (!load)
    {
        throw std::ios_base::failure("Could not open file!");
    }

    int size;

    load.read((char *)&size, sizeof(unsigned int));
    load.read((char *)&size, sizeof(int));
    this->title = new char[size + 1];
    load.read(this->title, size);
    this->title[size] = '\0';
    load.read((char *)&this->available, sizeof(bool));
}

Media::~Media()
{
    delete[] this->title;
    this->title = nullptr;
}

// Might throw std::bad_alloc
Media &Media::operator=(const Media &other)
{
    if (this != &other)
    {
        delete[] this->title;
        this->title = new char[strlen(other.title) + 1];
        strcpy(this->title, other.title);

        this->available = other.available;

        this->owner = other.owner;
    }
    return *this;
}

bool Media::operator==(const Media &other) const
{
    if (this->id == other.id)
    {
        return true;
    }
    return false;
}

// It's not good for the child classes
void Media::displayInfo() const
{
    std::cout << "Title: " << this->title
              << "\nId: " << this->id
              << "\nAvailable: " << (this->available ? "Yes" : "No")
              << "\nCollection: " << this->owner->getName()
              << std::endl;
}

float Media::calculateLateFee(unsigned int daysLate) const
{
    return 0.5 * daysLate;
}

void Media::saveToFile(std::ostream &save) const
{
    if (!save)
    {
        throw std::ios_base::failure("Could not open file!");
    }

    save.write((char *)&this->id, sizeof(unsigned int));
    int size = strlen(this->title);
    save.write((char *)&size, sizeof(int));
    save.write(this->title, size);
    save.write((char *)&this->available, sizeof(bool));
}

const char *Media::getTitle() const
{
    return this->title;
}

unsigned int Media::getId() const
{
    return this->id;
}

bool Media::getAvailable() const
{
    return this->available;
}

const Collection *Media::getOwner() const
{
    return this->owner;
}

// Might throw std::bad_alloc or std::invalid_argument
void Media::setTitle(const char *title)
{
    if (title == nullptr)
    {
        throw std::invalid_argument("Invalid Title!");
    }

    delete[] this->title;
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

void Media::setAvailable(bool available)
{
    this->available = available;
}

void Media::setOwner(Collection *newOwner)
{
    this->owner = newOwner;
}