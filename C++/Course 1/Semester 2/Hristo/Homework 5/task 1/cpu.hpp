#pragma once

struct CPU
{
public:
    CPU();
    CPU(float clockRate, int cores, int cache);
    void print() const;

private:
    float clockRate;
    int cores;
    int cache;
};