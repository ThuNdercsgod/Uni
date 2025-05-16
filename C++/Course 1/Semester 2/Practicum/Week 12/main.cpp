#include <iostream>
#include <cstring>

#include "collection.hpp"
#include "media.hpp"

int main()
{
    // Collection collection("Collection");

    // Media media("Book", 12345, true, &collection);

    // media.displayInfo();

    // const char *a = collection.getName();

    char *b = new char[strlen("") + 1];
    strcpy(b, "");

    bool rtr = (b == nullptr);
    std::cout << b;

    return 0;
}