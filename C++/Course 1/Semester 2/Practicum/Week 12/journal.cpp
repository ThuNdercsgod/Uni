#include <stdexcept>

#include "journal.hpp"

Journal::Journal(const char *title, unsigned int id, bool available, Collection *collection, unsigned int issue)
    : Media(title, id, available, collection)
{
    if (issue == 0)
    {
        throw std::invalid_argument("Invalid parameters for Journal creation!");
    }
    this->issue = issue;
}

unsigned int Journal::getIssue() const
{
    return this->issue;
}

void Journal::setIssue(unsigned int issue)
{
    if (issue == 0)
    {
        throw std::invalid_argument("Invalid parameters for changing issue!");
    }

    this->issue = issue;
}