#pragma once

#include "date.hpp"

class Patient
{
public:
    Patient();
    Patient(const char *name, const Date dateOfBirth, int visits);
    Patient(const Patient &other);
    Patient &operator=(const Patient &other);
    ~Patient();

    const char *getName() const;
    Date getDate() const;
    int getVisits() const;

    void setName(const char *name);
    void setDate(const Date dateOfBirth);
    void setVisits(int visits);

    void print() const;

private:
    char *name;
    Date dateOfBirth;
    int visits;
    static const int MAXNAMELENGTH;
};