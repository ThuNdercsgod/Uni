#pragma once

#include "media.hpp"

class Book : public Media
{
    Book();
    Book(const char *title, unsigned int id, bool available, const char *author, const char *genre, unsigned int pages, bool hardcover);
    Book(const Book &other);
    ~Book();

    Book &operator=(const Book &other);

    float estimateReadingTime() const;
    float calculateLateFee(unsigned int daysLate) const override;

    const char *getAuthor() const;
    const char *getGenre() const;
    unsigned int getPages() const;
    bool getHardcover() const;

    void setAuthor(const char *author);
    void setGenre(const char *genre);
    void setPages(unsigned int pages);
    void setHardcover(bool hardcover);

private:
    char *author;
    char *genre;
    unsigned int pages;
    bool hardcover;
};