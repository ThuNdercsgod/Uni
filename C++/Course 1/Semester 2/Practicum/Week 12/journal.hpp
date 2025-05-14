#pragma once

#include "media.hpp"

class Journal : public Media
{
public:
    Journal(const char *title, unsigned int id, bool available, Collection *collection, unsigned int issue);

    unsigned int getIssue() const;

    void setIssue(unsigned int issue);

private:
    unsigned int issue;
};