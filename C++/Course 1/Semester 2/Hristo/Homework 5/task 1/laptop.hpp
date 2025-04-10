#pragma once

struct CPU;

class Laptop
{
public:
    Laptop();
    Laptop(const char *brand, const char *model, int price, int screenSize, CPU cpu, int RAM, int batteryCapacity);
    Laptop(const Laptop &other);
    Laptop &operator=(const Laptop &other);
    ~Laptop();

    char *getBrand() const;
    char *getModel() const;
    int getPrice() const;
    int getScreenSize() const;
    CPU &getCPU() const;
    int getRAM() const;
    int getBatteryCapacity() const;

    void setPrice(int price);
    // няма set-ър за екрана, защото няма как да се увеличи на лаптоп
    void setCPU(CPU cpu);
    void setRAM(int RAM);
    void setBatteryCapacity(int batteryCapacity);

    bool valid() const;
    bool valid(const char *barnd, const char *model, int price, int screenSize, CPU cpu, int RAM, int batteryCapacity) const;

    void print() const;

private:
    char *brand;
    char *model;
    int price;
    int screenSize;
    CPU *cpu;
    int RAM;
    int batteryCapacity;
};