#include <cstring>
#include <stdexcept>

#include "journal.hpp"

Journal::Journal()
    : Journal("Unknown", 0, false, "Unknown", 1, 0, false) {}

Journal::Journal(const char *title, unsigned int id, bool available, const char *publisher, unsigned int issue, unsigned int publicationYear, bool scientific)
    : Media(title, id, available) // Needed to construct the base class parameters
{
    if (title == nullptr || publisher == nullptr || issue == 0)
    {
        throw std::invalid_argument("Invalid parameters for Journal creation!");
    }
    this->publisher = new char[strlen(publisher) + 1];
    strcpy(this->publisher, publisher);

    this->issue = issue;
    this->publicationYear = publicationYear;
    this->scientific = scientific;
}

Journal::Journal(const Journal &other)
    : Media(other) // Needed to construct the base class parameters
{
    this->publisher = new char[strlen(other.publisher) + 1];
    strcpy(this->publisher, other.publisher);

    this->issue = other.issue;
    this->publicationYear = other.publicationYear;
    this->scientific = other.scientific;
}

Journal::~Journal()
{
    delete[] this->publisher;
    this->publisher = nullptr;
}

Journal &Journal::operator=(const Journal &other)
{
    if (this != &other)
    {
        // Delete this Media and copy other Media
        Media::operator=(other);

        delete[] this->publisher;
        this->publisher = new char[strlen(other.publisher) + 1];
        strcpy(this->publisher, other.publisher);

        this->issue = other.issue;
        this->publicationYear = other.publicationYear;
        this->scientific = other.scientific;
    }
    return *this;
}

bool Journal::isRelevant(unsigned int currentYear) const
{
    if (currentYear > this->publicationYear)
    {
        throw std::invalid_argument("Invalid parameters for Journal!");
    }
    if ((currentYear - this->publicationYear) < 5)
    {
        return true;
    }
    return false;
}

float Journal::calculateLateFee(unsigned int daysLate) const
{
    if (this->scientific == true)
    {
        return daysLate;
    }
    else
    {
        return 0.3 * daysLate;
    }
}

// Other getters .....
unsigned int Journal::getIssue() const
{
    return this->issue;
}

// other setters ....
void Journal::setIssue(unsigned int issue)
{
    if (issue == 0)
    {
        throw std::invalid_argument("Invalid parameters for changing issue!");
    }

    this->issue = issue;
}