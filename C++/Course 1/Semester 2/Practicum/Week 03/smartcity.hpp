#pragma once
#include "city_types.hpp"

struct Location
{
    int x;
    int y;
};

// enum Action
// {
//     SEARCH,
//     LOAD,
//     SAVE,
//     EXIT
// };

// const char *const actionNames[] = {"Search",
//                                    "Load",
//                                    "Save",
//                                    "Exit"};

int inputNumber();
int inputCoordinates();
double distanceBetweenPoints(int x1, int y1, int x2, int y2);