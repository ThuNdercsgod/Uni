#pragma once

class Task
{
public:
    Task();
    Task(int id, const char *description, bool isCompleted);
    Task(const Task &other);
    Task &operator=(const Task &other);
    ~Task();

    bool valid() const;
    bool valid(int id, const char *description, bool isCompleted) const;

    void print() const;

    void completeTask();

private:
    int id;
    char *description;
    bool isCompleted;
};