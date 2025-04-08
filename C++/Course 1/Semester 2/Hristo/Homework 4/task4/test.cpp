#include <iostream>

#include "time.hpp"

int main()
{
    Time defConstr;
    defConstr.print();

    Time paramConstr(10, 23, 45);
    paramConstr.print();

    paramConstr.timeToMidnight();

    paramConstr.increaseSeconds();
    paramConstr.print();

    if (!paramConstr.timeForDinner())
    {
        std::cout << "Not time for dinner!" << std::endl;
    }

    Time dinner(22, 22, 22);
    if (dinner.timeForDinner())
    {
        std::cout << "Time for dinner!" << std::endl;
    }

    Time party(5, 5, 5);
    if (party.timeToParty())
    {
        std::cout << "Time to party!" << std::endl;
    }

    return 0;
}