#include <iostream>

#include "cpu.hpp"
#include "laptop.hpp"

int main()
{
    try
    {
        Laptop def;
        def.print();

        CPU amd(3.8, 6, 32);

        Laptop param("ASUS", 3000, 14, amd, 16, 73);
        param.print();

        CPU amd2(4.2, 12, 32);
        param.setPrice(4000);
        param.setCPU(amd2);
        param.setRAM(32);
        param.setBatteryCapacity(80);
        param.print();

        Laptop invalid("Lenovo", -1, 0, amd, 0, 0);
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return 2;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}