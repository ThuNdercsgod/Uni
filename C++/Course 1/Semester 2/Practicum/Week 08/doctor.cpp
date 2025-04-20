#include <cstring>
#include <iostream>
#include <stdexcept>

#include "doctor.hpp"

const int Doctor::MAXPATIENTS = 100;

// Might throw std::bad_alloc
Doctor::Doctor()
    : Doctor("Unknown") {}

// Might throw std::bad_alloc or std::invalid_argument
Doctor::Doctor(const char *name)
{
    if (name == nullptr)
    {
        throw std::invalid_argument("Invalid Doctor name!");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->patientList = new (std::nothrow) Patient[1];

    if (!this->patientList)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }

    this->sizeOfList = 1;
    this->patientsRegistered = 0;
    this->registered = 0;
}

// Might throw std::bad_alloc
Doctor::Doctor(const Doctor &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->patientList = new (std::nothrow) Patient[other.sizeOfList];

    if (!this->patientList)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }

    for (int i = 0; i < other.sizeOfList; i++)
    {
        this->patientList[i] = other.patientList[i];
    }

    this->sizeOfList = other.sizeOfList;
    this->patientsRegistered = other.patientsRegistered;
    this->registered = other.registered;
}

// Might throw std::bad_alloc
Doctor &Doctor::operator=(const Doctor &other)
{
    if (this != &other)
    {
        delete[] this->name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->patientList = new (std::nothrow) Patient[other.sizeOfList];

        if (!this->patientList)
        {
            delete[] this->name;
            throw std::bad_alloc();
        }

        for (int i = 0; i < other.sizeOfList; i++)
        {
            this->patientList[i] = other.patientList[i];
        }

        this->sizeOfList = other.sizeOfList;
        this->patientsRegistered = other.patientsRegistered;
        this->registered = other.registered;
    }
    return *this;
}

Doctor::~Doctor()
{
    delete[] this->name;
}

const char *Doctor::getName() const
{
    return this->name;
}

const Patient *Doctor::getPatientList() const
{
    return this->patientList;
}

int Doctor::getSizeOfList() const
{
    return this->getSizeOfList();
}

int Doctor::getPatientsRegistered() const
{
    return this->patientsRegistered;
}

int Doctor::getRegistered()
{
    return this->registered;
}

// Might throw std::bad_alloc or std::invalid_argument
void Doctor::setName(const char *name)
{
    if (name == nullptr)
    {
        delete[] this->name;
        throw std::invalid_argument("Invalid Doctor name!");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Might throw std::invalid_argument
void Doctor::setRegistered(int registered)
{
    if (!(registered >= 0 && registered <= this->sizeOfList))
    {
        throw std::invalid_argument("Invalid patient index in Doctors list!");
    }
    this->registered = registered;
}

// Might throw std::bad_alloc or std::invalid_argument
void Doctor::registerPatient(const Patient &patient)
{
    if (this->patientsRegistered == this->MAXPATIENTS)
    {
        std::cout << "Maximum number of patients reached!" << std::endl;
    }
    if (this->sizeOfList == this->patientsRegistered)
    {
        Patient *temp = new (std::nothrow) Patient[this->patientsRegistered];

        if (!temp)
        {
            delete[] this->name;
            delete[] this->patientList;
            throw std::bad_alloc();
        }

        for (int i = 0; i < patientsRegistered; i++)
        {
            temp[i] = this->patientList[i];
        }
        delete[] this->patientList;

        this->patientList = new (std::nothrow) Patient[this->patientsRegistered + 1];

        if (!this->patientList)
        {
            delete[] temp;
            delete[] this->name;
            throw std::bad_alloc();
        }

        for (int i = 0; i < patientsRegistered; i++)
        {
            this->patientList[i] = temp[i];
        }

        delete[] temp;

        this->patientList[this->patientsRegistered] = patient;

        this->patientsRegistered++;
    }
    else if (this->sizeOfList > this->patientsRegistered)
    {
        this->patientList[patientsRegistered] = patient;
        this->patientsRegistered++;
    }
    else
    {
        delete[] this->name;
        delete[] this->patientList;
        throw std::invalid_argument("Ivalid Doctor's patient list!");
    }
}

double Doctor::average() const
{
    double average;
    int totalVisits = 0;

    for (int i = 0; i < this->patientsRegistered; i++)
    {
        totalVisits += patientList[i].getVisits();
    }

    average = totalVisits / patientsRegistered;

    return average;
}

void Doctor::printUpper(int limit) const
{
    for (int i = 0; i < this->patientsRegistered; i++)
    {
        if (patientList[i].getVisits() > limit)
        {
            patientList[i].print();
        }
    }
}