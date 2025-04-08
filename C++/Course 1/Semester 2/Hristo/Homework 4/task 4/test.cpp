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

    Time dinner(21, 22, 22);
    dinner.print();
    if (dinner.timeForDinner())
    {
        std::cout << "Time for dinner!" << std::endl;
    }

    Time party(5, 5, 5);
    party.print();
    if (party.timeToParty())
    {
        std::cout << "Time to party!" << std::endl;
    }

    paramConstr.print();
    if (!(paramConstr.timeToParty()))
    {
        std::cout << "Not time to party" << std::endl;
    }

    Time difference = dinner.difference(party);
    difference.print();

    Time comparison = dinner.comparisonEarly(party);
    comparison.print();

    return 0;
}