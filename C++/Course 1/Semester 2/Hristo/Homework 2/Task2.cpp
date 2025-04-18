#include <cstring>
#include <fstream>
#include <iostream>

enum Commands
{
    VIEW,
    CHANGE,
    REMOVE,
    ADD,
    SAVE,
    SAVE_AS
};

const char *const commandsList[] = {"View",
                                    "Change",
                                    "Remove",
                                    "Add",
                                    "Save",
                                    "Save as"};

char inputChar();
void printMenuCommands();
void checkCommand(char const *fileName, int size);
bool view(const char *fileName, int size);
bool changeByte(const char *fileName, int &size);
bool removeByte(const char *fileName, int &size);
bool addByte(const char *fileName, int &size);
bool saveAs(const char *fileName, int size);

int main()
{
    char fileName[128];

    std::cout << "Open file:" << std::endl;
    std::cin.getline(fileName, 127);

    char buffer[1024];

    // Тук намирам размера на файла. Сигурно има и по-бърз начин, но за това се сетих
    std::ifstream load(fileName, std::ios::binary);

    if (!load.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return 1;
    }

    load.read((char *)buffer, sizeof(buffer));

    int sizeOfBuffer = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        sizeOfBuffer++;
    }

    load.close();

    checkCommand(fileName, sizeOfBuffer);

    return 0;
}

char inputChar()
{
    char input;
    std::cout << "Enter the new symbol:" << std::endl;

    bool valid;

    valid = true;
    std::cin >> input;

    if (!(input >= 'A' && input <= 'Z' ||
          input >= 'a' && input <= 'z'))
    {
        input = '.';
    }

    return input;
}

int inputByte(int size)
{
    int input;
    bool valid;

    std::cout << "Enter a position [1, " << size << "] in the file:" << std::endl;

    do
    {
        valid = true;
        std::cin >> input;
        input--;

        if (!(input >= 0 && input < size))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            valid = false;
        }
    } while (!valid);

    return input;
}

void printMenuCommands()
{
    std::cout << "---Commands---" << std::endl;
    for (int i = Commands::VIEW; i <= Commands::SAVE_AS; i++)
    {
        std::cout << commandsList[i] << std::endl;
    }
}

void checkCommand(char const *fileName, int initialSize)
{
    int size = initialSize;
    char command[64];
    printMenuCommands();

    bool valid;
    do
    {
        valid = true;
        // std::cin.clear();
        // std::cin.ignore();
        std::cout << "Enter command: " << std::endl;
        std::cin.getline(command, 63);

        if (strcmp(command, "View") == 0)
        {
            if (!view(fileName, size))
            {
                std::cout << "Wrong input! Try again:" << std::endl;

                // std::cin.ignore();
            }
            valid = false;
        }
        else if (strcmp(command, commandsList[1]) == 0)
        {
            if (!changeByte(fileName, size))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
            }
            valid = false;
        }
        else if (strcmp(command, commandsList[2]) == 0)
        {
            if (!removeByte(fileName, size))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
            }
            valid = false;
        }
        else if (strcmp(command, commandsList[3]) == 0)
        {
            if (!addByte(fileName, size))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
            }
            valid = false;
        }
        else if (strcmp(command, commandsList[4]) == 0)
        {
            std::cout << "File successfullly saved to " << fileName << std::endl;
        }
        else if (strcmp(command, commandsList[5]) == 0)
        {
            if (!saveAs(fileName, size))
            {
                std::cout << "Wrong input! Try again:" << std::endl;
                valid = false;
            }
        }
        else
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            // std::cin.ignore();
            valid = false;
        }
    } while (!valid);
}

bool view(const char *fileName, int size)
{
    std::ifstream load(fileName, std::ios::binary);

    if (!load.is_open())
    {
        std::cout << "File  opening error!" << std::endl;
        return false;
    }

    char *text = new (std::nothrow) char[size + 1];

    if (!text)
    {
        std::cout << "Memory allocation error!" << std::endl;
        return false;
    }

    load.read((char *)text, size);
    text[size] = '\0';

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!(text[i] >= 'A' && text[i] <= 'Z' ||
              text[i] >= 'a' && text[i] <= 'z'))
        {
            text[i] = '.';
        }
    }

    std::cout << text << std::endl;

    delete[] text;
    text = nullptr;

    load.close();

    return true;
}

bool changeByte(const char *fileName, int &size)
{
    int position = inputByte(size);

    char symbol = inputChar();

    char *file = new (std::nothrow) char[size];

    if (!file)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return false;
    }

    std::ifstream load(fileName, std::ios::binary);

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        delete[] file;
        file = nullptr;
        return false;
    }

    load.read(file, size);

    load.close();

    std::ofstream edit(fileName, std::ios::binary);

    if (!edit.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return false;
    }

    file[position] = symbol;
    edit.write(file, size);

    edit.close();

    delete[] file;
    file = nullptr;

    return true;
}

bool removeByte(const char *fileName, int &size)
{
    std::ifstream load(fileName);

    if (!load.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        return false;
    }

    char *file = new (std::nothrow) char[size];

    if (!file)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return false;
    }

    load.read((char *)file, size);

    load.close();

    std::ofstream save(fileName);

    if (!save.is_open())
    {
        std::cout << "File opening error!" << std::endl;
        delete[] file;
        file = nullptr;

        return false;
    }

    size--;

    save.write(file, size);

    save.close();

    delete[] file;
    file = nullptr;

    return true;
}

bool addByte(const char *fileName, int &size)
{
    std::ifstream load(fileName, std::ios::binary);

    if (!load.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        return false;
    }

    size++;

    char *file = new (std::nothrow) char[size + 1];

    if (!file)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return false;
    }

    load.read((char *)file, size - 1);

    load.close();

    file[size - 1] = inputChar();
    file[size] = '\0';

    std::ofstream save(fileName, std::ios::binary);

    if (!save.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        delete[] file;
        file = nullptr;

        return false;
    }

    save.write((const char *)file, size);

    save.close();

    delete[] file;
    file = nullptr;

    return true;
}

bool saveAs(const char *fileName, int size)
{
    char *file = new (std::nothrow) char[size];

    if (!file)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        return false;
    }

    std::ifstream load(fileName, std::ios::binary);

    if (!load.is_open())
    {
        std::cerr << "File opening error!" << std::endl;
        delete[] file;
        file = nullptr;

        return false;
    }

    load.read((char *)file, size);

    load.close();

    char newFile[128];

    std::cout << "Enter where to save it as:" << std::endl;
    std::cin.getline(newFile, 127);

    std::ofstream save(newFile, std::ios::binary);

    if (!save.is_open())
    {
        std::cout << "File opening error!";
        delete[] file;
        file = nullptr;

        return false;
    }

    save.write(file, sizeof(file));

    delete[] file;
    file = nullptr;

    return true;
}