#pragma once

#include "patient.hpp"

class Doctor
{
public:
    Doctor();
    Doctor(const char *name);
    Doctor(const Doctor &other);
    Doctor &operator=(const Doctor &other);
    ~Doctor();

    const char *getName() const;
    const Patient *getPatientList() const;
    int getSizeOfList() const;
    int getPatientsRegistered() const;
    int getRegistered();

    void setName(const char *name);
    void setRegistered(int registered);

    void registerPatient(const Patient &patient);
    double average() const;
    void printUpper(int limit) const;

private:
    char *name;
    Patient *patientList;
    int sizeOfList;
    int patientsRegistered;
    int registered;
    static const int MAXPATIENTS;
};