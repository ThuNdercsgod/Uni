#include <cstring>
#include <fstream>
#include <iostream>

struct Students
{
    char firstName[128];
    char lastName[128];
    char email[256];
    char fn[6];
};

void checkCommand(char const *fileName);
std::ifstream loadFromFile(char const *fileName);
void inputFN(char fn[6]);
int inputAmountStudents();
Students inputStudentInfo();
bool inputToFile(char const *fileName);
Students *loadStudentFromFile(char const *fileName, int &size);
bool editEmail(char const *fileName, char input[256]);
bool printContent(char input[256], char const *fileName);

int main()
{
    char fileName[64];
    std::cout << "Open file:" << std::endl;
    std::cin.getline(fileName, 63);

    checkCommand(fileName);

    return 0;
}

void printCommands()
{
    std::cout << "=== Commands ===\n"
              << "print <faculty number>\n"
              << "input\n"
              << "edit <faculty number> <new email>\n"
              << "save file" << std::endl;
}

void checkCommand(char const *fileName)
{
    bool valid = true;
    char command[6];
    char input[256];

    do
    {
        valid = true;
        printCommands();
        std::cout << "Enter command:" << std::endl;

        std::cin.getline(command, 6, ' ');
        std::cin.getline(input, 255);

        if (strcmp(command, "print") == 0)
        {
            if (!printContent(input, fileName))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
            }
            valid = false;
        }
        else if (strcmp(command, "input") == 0)
        {
            if (!inputToFile(fileName))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
            }
            valid = false;
        }
        else if (strcmp(command, "edit") == 0)
        {
            if (!editEmail(fileName, input))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
            }
            valid = false;
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

void inputFN(char fn[6])
{
    char input[6];
    bool valid;

    do
    {
        valid = true;
        std::cin.getline(input, 5);

        for (int i = 0; i < 6; i++)
        {
            if (!(input[i] >= 0 && input[i] <= 9))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                valid = false;
            }
        }
    } while (!valid);

    input[5] = '\0';
}

int inputAmountStudents()
{
    int number = 0;
    bool valid;
    std::cout << "Enter the amount of students: ";

    do
    {
        valid = true;
        std::cin >> number;

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
    inputFN(student.fn);

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

    int amount = inputAmountStudents();

    input << amount << std::endl;

    Students *student = new (std::nothrow) Students[amount];

    if (!student)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return false;
    }

    for (int i = 0; i < amount; i++)
    {
        std::cout << "Student " << i + 1 << std::endl;
        student[i] = inputStudentInfo();

        input << student[i].firstName << ", " << student[i].lastName
              << ", " << student[i].email
              << ", " << student[i].fn << std::endl;
    }

    delete[] student;

    input.close();

    return true;
}

Students *loadStudentFromFile(char const *fileName, int &size)
{
    char lineBuffer[256];

    std::ifstream load = loadFromFile(fileName);

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return nullptr;
    }

    load.getline(lineBuffer, sizeof(int));
    sscanf(lineBuffer, "%d", &size);

    Students *student = new (std::nothrow) Students[size];

    if (!student)
    {
        std::cout << "Memory allocation error!" << std::endl;

        return nullptr;
    }

    for (int i = 0; i < size; i++)
    {
        load.getline(lineBuffer, sizeof(lineBuffer), ',');
        strcpy(student[i].firstName, lineBuffer);
        load.getline(lineBuffer, sizeof(lineBuffer), ' ');

        load.getline(lineBuffer, sizeof(lineBuffer), ',');
        strcpy(student[i].lastName, lineBuffer);
        load.getline(lineBuffer, sizeof(lineBuffer), ' ');

        load.getline(lineBuffer, sizeof(lineBuffer), ',');
        strcpy(student[i].email, lineBuffer);
        load.getline(lineBuffer, sizeof(lineBuffer), ' ');

        load.getline(lineBuffer, sizeof(lineBuffer));
        strcpy(student[i].fn, lineBuffer);
    }

    load.close();

    return student;
}

bool editEmail(char const *fileName, char input[256])
{
    int size;
    Students *student = loadStudentFromFile(fileName, size);
    int place;
    char searchedFN[6];
    for (int i = 0; i < 5; i++)
    {
        searchedFN[i] = input[i];
    }
    searchedFN[5] = '\0';

    for (int i = 0; i < size; i++)
    {
        if (strcmp(student[i].fn, searchedFN) == 0)
        {
            place = i;
            break;
        }
    }

    std::ofstream edit(fileName);

    if (!edit.is_open())
    {
        std::cout << "File opening error!" << std::endl;

        return false;
    }

    char *ptr = strchr(input, ' ');
    ptr++;

    strcpy(student[place].email, ptr);

    edit << size + 1 << std::endl;
    for (int i = 0; i < size; i++)
    {
        edit << student[i].firstName << ", " << student[i].lastName
             << ", " << student[i].email
             << ", " << student[i].fn << std::endl;
    }

    edit.close();

    return true;
}

bool printContent(char input[256], char const *fileName)
{
    int size;
    Students *student = loadStudentFromFile(fileName, size);

    int place;
    char searchedFN[6];
    for (int i = 0; i < 5; i++)
    {
        searchedFN[i] = input[i];
    }
    searchedFN[5] = '\0';

    for (int i = 0; i < size; i++)
    {
        if (strcmp(student[i].fn, searchedFN) == 0)
        {
            place = i;
            break;
        }
    }

    std::cout << student[place].firstName << ", "
              << student[place].lastName << ", "
              << student[place].email << ", "
              << student[place].fn << std::endl;

    return true;
}