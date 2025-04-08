#include <cstring>
#include <iostream>
#include <stdexcept>

#include "string.hpp"

// Might throw exception std::bad_alloc
String::String()
{
    this->string = new char[17];
}

// Might throw exception std::bad_alloc or int 1
String::String(int size)
{
    if (size <= 16)
    {
        this->string = new char[size + 1];
    }
    else
    {
        throw 1;
    }
}

// Might throw exception std::bad_alloc or int 1
String::String(const char *string)
{
    if (strlen(string) <= 16)
    {
        this->string = new char[strlen(string) + 1];
        strcpy(this->string, string);
    }
    else
    {
        throw 1;
    }
}

String::~String()
{
    if (this->string != nullptr)
    {
        delete[] this->string;
        this->string = nullptr;
    }
}

// Might throw exception std::bad_alloc or int 1
void String::copy(const char *copy)
{
    if (strlen(copy) <= 16)
    {
        delete[] this->string;
        this->string = new char[strlen(copy) + 1];
        strcpy(this->string, copy);
    }
    else
    {
        throw 1;
    }
}

// Might throw exception std::bad_alloc or int 1
void String::append(const char *append)
{
    if ((strlen(this->string) + strlen(append)) <= 16)
    {
        char *oldString = new char[strlen(this->string) + 1];
        strcpy(oldString, this->string);
        delete[] this->string;
        this->string = nullptr;

        this->string = new char[strlen(oldString) + strlen(append) + 1];
        strcpy(this->string, oldString);
        delete[] oldString;
        oldString = nullptr;

        strcat(this->string, append);
    }
    else
    {
        throw 1;
    }
}

// Might throw exception std::bad_alloc or int 1
void String::combine(const char *combine)
{
    if ((strlen(this->string) + strlen(combine)) <= 16)
    {
        char *oldString = new char[strlen(this->string) + 1];
        strcpy(oldString, this->string);
        delete[] this->string;
        this->string = nullptr;

        this->string = new char[strlen(oldString) + strlen(combine) + 1];
        strcpy(this->string, oldString);
        delete[] oldString;
        oldString = nullptr;

        strcat(this->string, combine);
    }
    else
    {
        throw 1;
    }
}

const char *const String::c_str() const
{
    return this->string;
}

int String::length() const
{
    return strlen(this->string);
}

void String::clear()
{
    delete[] this->string;
    this->string = nullptr;
}

bool String::empty() const
{
    if (!this->string)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Might throw exception int 2
char String::at(int position) const
{
    if (position < 16)
    {
        char a = this->string[position];
        return a;
    }
    else
    {
        throw 2;
    }
}