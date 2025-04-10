#include <iostream>

#include "cpu.hpp"

CPU::CPU()
    : CPU(3.8, 6, 32) {}

// Might throw std::invalid_argument
CPU::CPU(float clockRate, int cores, int cache)
{
    if (clockRate > 0 && cores > 0 && cache > 0)
    {
        this->clockRate = clockRate;
        this->cores = cores;
        this->cache = cache;
    }
    else
    {
        throw std::invalid_argument("Invalid CPU parameters!");
    }
}

void CPU::print() const
{
    std::cout << "CPU:"
              << "\n\tClock rate: " << this->clockRate
              << "\n\tCores: " << this->cores
              << "\n\tCache: " << this->cache << std::endl;
}