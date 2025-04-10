#include <cstring>
#include <iostream>

#include "todo.hpp"

Task::Task()
    : Task(0, "Default", false) {}

Task::Task(int id, const char *description, bool isCompleted)
{
    if (valid(id, description, isCompleted))
    {
        this->id = id;
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);
        this->isCompleted = isCompleted;
    }
    else
    {
        throw std::invalid_argument("Invalid Task parameters!");
    }
}

Task::Task(const Task &other)
{
    this->id = other.id;
    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);
    this->isCompleted = other.isCompleted;
}

Task &Task::operator=(const Task &other)
{
    if (this != &other)
    {
        this->id = other.id;
        delete[] this->description;
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
        this->isCompleted = other.isCompleted;
    }

    return *this;
}

Task::~Task()
{
    delete[] this->description;
}

bool Task::valid() const
{
    if (this->id >= 0 &&
        this->description != nullptr)
    {
        return true;
    }
    return false;
}

bool Task::valid(int id, const char *description, bool isCompleted) const
{
    if (id >= 0 &&
        description != nullptr)
    {
        return true;
    }
    return false;
}

void Task::print()
{
    std::cout << "\n=== Task " << this->id << " ===\n"
              << "Description: \"" << this->description << "\"" << std::endl;

    if (this->isCompleted)
    {
        std::cout << "Task is completed!" << std::endl;
    }
    else
    {
        std::cout << "Task is not completed!" << std::endl;
    }
}

void Task::completeTask()
{
    if (!this->isCompleted)
    {
        this->isCompleted = true;
    }
    else
    {
        std::cout << "Task is already completed!" << std::endl;
    }
}