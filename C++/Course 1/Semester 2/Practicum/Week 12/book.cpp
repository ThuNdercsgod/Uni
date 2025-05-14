#include <stdexcept>

#include "book.hpp"

Book::Book(const char *title, unsigned int id, bool available, Collection *collection, unsigned int pages)
    : Media(title, id, available, collection)
{
    if (pages == 0)
    {
        throw std::invalid_argument("Invalid parameters for Book creation!");
    }
    this->pages = pages;
}

unsigned int Book::getPages() const
{
    return this->pages;
}

void Book::setPages(unsigned int pages)
{
    if (pages == 0)
    {
        throw std::invalid_argument("Invalid parameters for Book creation!");
    }
    this->pages = pages;
}