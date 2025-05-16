#pragma once

#include "media.hpp"

class Journal : public Media
{
public:
    Journal();
    Journal(const char *title, unsigned int id, bool available, const char *publisher, unsigned int issue, unsigned int publicationYear, bool scientific);
    Journal(const Journal &other);
    ~Journal();

    Journal &operator=(const Journal &other);

    bool isRelevant(unsigned int currentYear) const;
    float calculateLateFee(unsigned int daysLate) const override;

    // other getters ...
    unsigned int getIssue() const;

    // other setters ...
    void setIssue(unsigned int issue);

private:
    char *publisher;
    unsigned int issue;
    unsigned int publicationYear;
    bool scientific;
};