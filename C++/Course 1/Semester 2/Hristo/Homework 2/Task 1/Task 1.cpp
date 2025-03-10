#include <cstring>
#include <fstream>
#include <iostream>

struct Students
{
    char firstName[128];
    char lastName[128];
    char email[256];
    int fn[5];
};

bool openFile(char const *file);

int main()
{
    char command[6];
    char fileName[64];
    std::cout << "Open file:" << std::endl;
    std::cin.getline(command, 5, ' ');

    std::cin.getline(fileName, 63);

    if (!openFile(fileName))
    {
        return 1;
    }

    return 0;
}

bool printFile(char const *file, Students &student)
{
    std::ifstream print(file);

    if (!print.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    char line;
    do
    {
        std::cout << line;
    } while (line != ',');

    std::cout << std::endl;

    print.close();

    return true;
}

bool openFileInput(char const *fileName)
{
    std::ofstream input(fileName);

    if (!input.is_open())
    {
        std::cout << "Opening file error!" << std::endl;

        return false;
    }

    std::cout << "File successfully opened!" << std::endl;

    return true;
}