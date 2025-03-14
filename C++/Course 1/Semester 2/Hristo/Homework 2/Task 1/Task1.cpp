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

void checkCommand(char command[6], char input[256], char const *fileName);
std::ifstream loadFromFile(char const *fileName);
int inputFN();
int inputAmountStudents();
Students inputStudentInfo();
bool inputToFile(char const *fileName);
Students loadStudentFromFile(char const *fileName);
bool editEmail(char const *fileName, char input[256]);
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

    checkCommand(command, input, fileName);

    return 0;
}

void checkCommand(char command[6], char input[256], char const *fileName)
{
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
        else if (strcmp(command, "input") == 0)
        {
            if (!inputToFile(fileName))
            {
                valid = false;
            }
        }
        else if (strcmp(command, "edit") == 0)
        {
            if (!editEmail(fileName, input))
            {
                valid = false;
            }
        }
        else if (strcmp(command, "save") == 0)
        {
            std::cout << "File successfully saved!";
        }
        else
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);
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

int inputFN()
{
    int input;
    bool valid;

    do
    {
        valid = true;
        std::cin >> input;

        if (!(input >= 10000 && input < 100000))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);

    return input;
}

int inputAmountStudents()
{
    int number = 0;
    bool valid;

    do
    {
        valid = true;
        std::cin >> number;

        std::cout << "enfdg";
        if (!(number >= 0))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);

    return number;
}

Students inputStudentInfo()
{
    Students student;

    std::cin.clear();
    std::cin.ignore();
    std::cout << "Enter the name of the student:" << std::endl;
    // std::cin >> student.firstName >> student.lastName;
    std::cin.getline(student.firstName, 255, ' ');
    std::cin.getline(student.lastName, 255);

    std::cout << "Enter the E-Mail of the student:" << std::endl;
    std::cin.getline(student.email, 255);

    std::cout << "Enter the faculty number of the student:" << std::endl;
    student.fn = inputFN();

    return student;
}

bool inputToFile(char const *fileName)
{
    std::ofstream input(fileName);

    if (!input.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    // int amountStudents = 0;
    // std::cout << "Enter amount of students to save:" << std::endl;
    // std::cin.clear();
    // std::cin.ignore();
    // amountStudents = inputAmountStudents();

    Students student = inputStudentInfo();

    input << student.firstName << " " << student.lastName
          << ", " << student.email
          << ", " << student.fn << std::endl;

    // delete[] student;

    input.close();

    return true;
}

Students loadStudentFromFile(char const *fileName)
{
    Students student;

    std::ifstream load = loadFromFile(fileName);

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        strcpy(student.firstName, "Error 1");
        return student;
    }

    char lineBuffer[256];
    load.getline(lineBuffer, sizeof(lineBuffer), ' ');
    strcpy(student.firstName, lineBuffer);

    load.getline(lineBuffer, sizeof(lineBuffer), ',');
    strcpy(student.lastName, lineBuffer);
    load.getline(lineBuffer, sizeof(lineBuffer), ' ');

    load.getline(lineBuffer, sizeof(lineBuffer), ',');
    strcpy(student.email, lineBuffer);
    load.getline(lineBuffer, sizeof(lineBuffer), ' ');

    load.getline(lineBuffer, sizeof(lineBuffer));
    sscanf(lineBuffer, "%d", &student.fn);

    load.close();

    return student;
}

bool editEmail(char const *fileName, char input[256])
{
    Students student = loadStudentFromFile(fileName);

    std::ofstream edit(fileName);

    if (!edit.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    char *ptr = strchr(input, ' ');
    ptr++;

    strcpy(student.email, ptr);

    edit << student.firstName << " " << student.lastName
         << ", " << student.email
         << ", " << student.fn << std::endl;

    edit.close();

    return true;
}

bool printContent(char input[256], char const *fileName)
{
    Students student = loadStudentFromFile(fileName);

    if (strcmp(student.firstName, "Error 1") == 0)
    {
        return false;
    }

    std::cout << student.firstName << " "
              << student.lastName << ", "
              << student.email << ", "
              << student.fn << std::endl;

    return true;
}