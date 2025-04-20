#include <cstring>
#include <iostream>
#include <stdexcept>

#include "patient.hpp"

const int Patient::MAXNAMELENGTH = 30;

// Might throw std::bad_alloc
Patient::Patient()
{
    this->name = new char[strlen("Unknown") + 1];
    strcpy(this->name, "Unknown");
    Date dateOfBirth(0, 0, 1900);
    this->dateOfBirth = dateOfBirth;
    this->visits = 0;
}

// Might throw std::bad_alloc or std::invalid_argument
Patient::Patient(const char *name, const Date dateOfBirth, int visits)
{
    if (name == nullptr)
    {
        throw std::invalid_argument("Invalid value for Patient name!");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->dateOfBirth = dateOfBirth;

    if (!(visits >= 0))
    {
        throw std::invalid_argument("Invalid value for Patient visits!");
    }

    this->visits = visits;
}

Patient::Patient(const Patient &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->dateOfBirth = other.dateOfBirth;

    this->visits = other.visits;
}

// Might throw std::bad_alloc
Patient &Patient::operator=(const Patient &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->dateOfBirth = other.dateOfBirth;

        this->visits = other.visits;
    }

    return *this;
}

Patient::~Patient()
{
    delete[] this->name;
}

const char *Patient::getName() const
{
    return this->name;
}

Date Patient::getDate() const
{
    return this->dateOfBirth;
}

int Patient::getVisits() const
{
    return this->visits;
}

// Might throw std::bad_alloc or std::invalid_argument
void Patient::setName(const char *name)
{
    if (name == nullptr)
    {
        delete[] this->name;
        throw std::invalid_argument("Invalid value for Patient name!");
    }

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Patient::setDate(const Date dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

// Might throw std::invalid_argument
void Patient::setVisits(int visits)
{
    if (!(visits >= 0))
    {
        delete[] this->name;
        throw std::invalid_argument("Invalid value for Patient visits!");
    }

    this->visits = visits;
}

void Patient::print() const
{
    std::cout << "\nName: " << this->name
              << "\nDate of Birth: ";
    this->dateOfBirth.print();
    std::cout << "\nNumber of Visits: " << this->visits << std::endl;
}