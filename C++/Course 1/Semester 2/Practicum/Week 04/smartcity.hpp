#pragma once
#include "city_types.hpp"

struct Location
{
    int x;
    int y;
};

// enum Command
// {
//     INPUT,
//     LOAD,
//     SAVE,
//     LOADBINARY,
//     SAVEBINARY,
//     SEARCH,
//     EXIT
// };

// const char *const commandNames[] = {"Input",
//                                     "Load",
//                                     "Save",
//                                     "Load binary",
//                                     "Save binary",
//                                     "Search",
//                                     "Exit"};

int inputNumber();
int inputCoordinates();
double distanceBetweenPoints(int x1, int y1, int x2, int y2);