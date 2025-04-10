#include <cstring>
#include <iostream>

#include "cpu.hpp"
#include "laptop.hpp"

// Might throw std::bad_alloc and std::invalid_argument
Laptop::Laptop()
{
    this->brand = new char[strlen("Default")];
    strcpy(this->brand, "Default");
    this->model = new char[strlen("Default")];
    strcpy(this->model, "Default");
    this->price = 0;
    this->screenSize = 0;
    CPU cpu;
    this->cpu = &cpu;
    this->RAM = 0;
    this->batteryCapacity = 0;
}

// Might throw std::bad_alloc and std::invalid_argument
Laptop::Laptop(const char *brand, const char *model, int price, int screenSize, CPU cpu, int RAM, int batteryCapacity)
{
    if (valid(brand, model, price, screenSize, cpu, RAM, batteryCapacity))
    {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        this->price = price;
        this->screenSize = screenSize;
        this->cpu = &cpu;
        this->RAM = RAM;
        this->batteryCapacity = batteryCapacity;
    }
    else
    {
        throw std::invalid_argument("Invalid Laptop parameters");
    }
}

Laptop::Laptop(const Laptop &other)
{
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);

    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);

    this->price = other.price;
    this->screenSize = other.screenSize;
    this->cpu = other.cpu;
    this->RAM = other.RAM;
    this->batteryCapacity = other.batteryCapacity;
}

Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        delete[] this->brand;
        this->brand = new char[strlen(other.brand) + 1];
        strcpy(this->brand, other.brand);

        delete[] this->model;
        this->model = new char[strlen(other.model) + 1];
        strcpy(this->model, other.model);

        this->price = other.price;
        this->screenSize = other.screenSize;
        this->cpu = other.cpu;
        this->RAM = other.RAM;
        this->batteryCapacity = other.batteryCapacity;
    }

    return *this;
}

Laptop::~Laptop()
{
    delete[] brand;
    delete[] model;
}

char *Laptop::getBrand() const
{
    return this->brand;
}

char *Laptop::getModel() const
{
    return this->model;
}

int Laptop::getPrice() const
{
    return this->price;
}

int Laptop::getScreenSize() const
{
    return this->screenSize;
}

CPU &Laptop::getCPU() const
{
    return *this->cpu;
}

int Laptop::getRAM() const
{
    return this->RAM;
}

int Laptop::getBatteryCapacity() const
{
    return this->batteryCapacity;
}

// Might throw int std::invalid_argument
void Laptop::setPrice(int price)
{
    if (price > 0)
    {
        this->price = price;
    }
    else
    {
        throw std::invalid_argument("Invalid price value!");
    }
}

// Might throw int std::invalid_argument
void Laptop::setCPU(CPU cpu)
{
    if (&cpu != nullptr)
    {
        this->cpu = &cpu;
    }
    else
    {
        throw std::invalid_argument("Invalid CPU!");
    }
}

// Might throw int std::invalid_argument
void Laptop::setRAM(int RAM)
{
    if (RAM > 0)
    {
        this->RAM = RAM;
    }
    else
    {
        throw std::invalid_argument("Invalid RAM value!");
    }
}

// Might throw int std::invalid_argument
void Laptop::setBatteryCapacity(int batteryCapacity)
{
    if (batteryCapacity > 0)
    {
        this->batteryCapacity = batteryCapacity;
    }
    else
    {
        throw std::invalid_argument("Invalid battery capacity value!");
    }
}

bool Laptop::valid() const
{
    if (this->brand != nullptr &&
        this->model != nullptr &&
        this->price > 0 &&
        this->screenSize > 0 &&
        this->cpu != nullptr &&
        this->RAM > 0 &&
        this->batteryCapacity > 0)
    {
        return true;
    }
    return false;
}

bool Laptop::valid(const char *brand, const char *model, int price, int screenSize, CPU cpu, int RAM, int batteryCapacity) const
{
    if (brand != nullptr &&
        model != nullptr &&
        price > 0 &&
        screenSize > 0 &&
        &cpu != nullptr &&
        RAM > 0 &&
        batteryCapacity > 0)
    {
        return true;
    }
    return false;
}

void Laptop::print() const
{
    std::cout << "\n=== Laptop " << this->brand << " " << this->model << " ===\n"
              << "Price: " << this->price << "\n"
              << "\nScreen size: " << this->screenSize << "\n";
    this->cpu->print();
    std::cout << "RAM: " << this->RAM
              << "\nBattery capacity: " << this->batteryCapacity << std::endl;
}