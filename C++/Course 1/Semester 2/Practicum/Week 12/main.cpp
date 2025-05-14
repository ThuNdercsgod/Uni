#include <iostream>
#include <cstring>

#include "collection.hpp"
#include "media.hpp"

int main()
{
    Collection collection("Collection", nullptr, 0);

    // Media media("Book", 12345, true, &collection);

    // media.print();

    const char *a = collection.getName();

    std::cout << collection.getName();

    return 0;
}