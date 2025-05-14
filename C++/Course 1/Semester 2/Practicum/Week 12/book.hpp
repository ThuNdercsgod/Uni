#pragma once

#include "media.hpp"

class Book : public Media
{
    Book(const char *title, unsigned int id, bool available, Collection *collection, unsigned int pages);

    unsigned int getPages() const;

    void setPages(unsigned int pages);

private:
    unsigned int pages;
};