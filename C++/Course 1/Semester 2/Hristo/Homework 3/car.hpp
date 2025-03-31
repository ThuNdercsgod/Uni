#pragma once

class Car
{
public:
    void commands();
    void create();
    void print();
    void upgrade();
    void fill();
    void drive();
    int getHorsePower();
    float getFuel();
    float getDistanceDriven();

private:
    void printCommands();
    int horsePower = 90;
    float fuel = 0;
    float distanceDriven = 0;

    enum Commands
    {
        INITIALIZE,
        UPGRADE,
        FILL,
        DRIVE,
        SHOWMENU,
        EXIT
    };
};