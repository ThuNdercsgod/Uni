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
    Collection owner;
    this->owner = &owner;
}

// Might throw std::bad_alloc or std::invalid_argument
Media::Media(const char *title, unsigned int id, bool available, Collection *owner)
{
    if (title == nullptr || owner == nullptr)
    {
        throw std::invalid_argument("Invalid parameters for Media creation!");
    }

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->id = id;
    this->available = available;

    this->owner = owner;
}

// Might throw std::bad_alloc
Media::Media(const Media &other)
{
    this->title = new char[strlen(other.title) + 1];
    strcpy(this->title, other.title);

    this->id = other.id;
    this->available = other.available;

    this->owner = other.owner;
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

        this->id = other.id;
        this->available = other.available;

        this->owner = other.owner;
    }
    return *this;
}

void Media::print() const
{
    std::cout << "Title: " << this->title
              << "\nId: " << this->id
              << "\nAvailable: " << (this->available ? "Yes" : "No")
              << "Collection: " << this->owner->getName()
              << std::endl;
}

char *Media::getTitle() const
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

Collection *Media::getOwner() const
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

void Media::setId(unsigned int id)
{
    this->id = id;
}

void Media::setAvailable(bool available)
{
    this->available = available;
}

void Media::setOwner(Collection *newOwner)
{
    this->owner = newOwner;
}