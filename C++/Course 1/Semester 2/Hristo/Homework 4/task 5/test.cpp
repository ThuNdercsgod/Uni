#include <iostream>

#include "interval.hpp"

int main()
{
    Interval defConstr;
    defConstr.print();

    Interval paramConstr(1, 4);
    paramConstr.print();

    Interval invalid(4, 1);
    invalid.print();

    std::cout << paramConstr.getA() << "," << paramConstr.getB() << std::endl;

    std::cout << "length: " << paramConstr.length() << std::endl;

    invalid.setB(3);
    invalid.setA(2);

    invalid.print();

    if (paramConstr.isSubInterval(invalid))
    {
        std::cout << "sub interval" << std::endl;
    }

    if (!(defConstr.isSubInterval(invalid)))
    {
        std::cout << "is not sub interval" << std::endl;
    }

    if (paramConstr.isIncluded(2))
    {
        std::cout << "number is included" << std::endl;
    }

    if (!(paramConstr.isIncluded(0)))
    {
        std::cout << "number is not included" << std::endl;
    }

    defConstr.setB(5);
    defConstr.setA(1);
    defConstr.print();

    invalid.setB(7);
    invalid.setA(3);
    invalid.print();

    Interval intersection = defConstr.intersection(invalid);
    intersection.print();

    Interval Union = defConstr.Union(invalid);
    Union.print();

    return 0;
}