#include <cstring>
#include <fstream>
#include <iostream>

struct Students
{
    char firstName[128];
    char lastName[128];
    char email[256];
    int fn;
};

void print(Students &student);
std::ifstream loadFromFile(char const *fileName);
bool printContent(char input[256], char const *fileName);

int main()
{
    char fileName[64];
    std::cout << "Open file:" << std::endl;
    std::cin.getline(fileName, 63);

    char command[6];
    char input[256];
    std::cout << "Enter command:" << std::endl;
    std::cin.getline(command, 6, ' ');
    std::cin.ignore();
    std::cin.getline(input, 255);

    bool valid = true;
    do
    {
        valid = true;
        if (strcmp(command, "print") == 0)
        {
            if (!printContent(input, fileName))
            {
                valid = false;
            }
        }
        else if (strcmp(command, "edit") == 0)
        {
        }
        else if (strcmp(command, "save") == 0)
        {
        }
        else
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);

    return 0;
}

void print(Students &student)
{
    // TODO somethings wrong
    std::cout << student.firstName << ", " << student.lastName << ", ";
    std::cout << student.email << ", " << student.fn << std::endl;
}

std::ifstream loadFromFile(char const *fileName)
{
    std::ifstream load(fileName);

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return nullptr;
    }

    return load;
}

bool inputToFile(char const *fileName)
{
    std::ofstream input(fileName);

    if (!input.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    std::cout << "File successfully opened!" << std::endl;

    return true;
}

bool printContent(char input[256], char const *fileName)
{
    Students student;

    std::ifstream load = loadFromFile(fileName);

    if (!load.is_open())
    {
        return false;
    }

    // TODO FIX THIS
    char lineBuffer[256];
    load.getline(lineBuffer, sizeof(lineBuffer), ',');
    strcpy(student.firstName, lineBuffer);
    load.getline(lineBuffer, sizeof(lineBuffer), ' ');

    load.getline(lineBuffer, sizeof(lineBuffer), ',');
    strcpy(student.lastName, lineBuffer);
    load.getline(lineBuffer, sizeof(lineBuffer), ' ');

    load.getline(lineBuffer, sizeof(lineBuffer), ',');
    sscanf(lineBuffer, "Email: %[^,]", &student.email);
    load.getline(lineBuffer, sizeof(lineBuffer), ' ');

    load.getline(lineBuffer, sizeof(lineBuffer));
    sscanf(lineBuffer, "FN: %d", &student.fn);
    // TODO END

    load.close();

    print(student);

    return true;
}