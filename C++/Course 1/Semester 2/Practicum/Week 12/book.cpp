#include <cstring>
#include <stdexcept>

#include "book.hpp"

// Might throw std::bad_alloc
Book::Book()
    : Book("Unknown", 0, false, "Unknown", "Unknown", 0, false) {}

// Might throw std::invalid_argument or std::bad_alloc
Book::Book(const char *title, unsigned int id, bool available, const char *author, const char *genre, unsigned int pages, bool hardcover)
    : Media(title, id, available) // Construct the Media parameters with Media constructor
{
    if (author == nullptr || genre == nullptr || pages == 0)
    {
        throw std::invalid_argument("Invalid parameters for Book!");
    }

    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);

    this->genre = new (std::nothrow) char[strlen(genre) + 1];
    if (!this->genre)
    {
        delete[] this->author;
        this->author = nullptr;
    }
    strcpy(this->genre, genre);

    this->pages = pages;
    this->hardcover = hardcover;
}

// Might throw std::bad_alloc
Book::Book(const Book &other)
    : Media(other) // Construct the Media parameters with Media constructor
{
    this->author = new char[strlen(other.author) + 1];
    strcpy(this->author, other.author);

    this->genre = new (std::nothrow) char[strlen(other.genre) + 1];
    if (!this->genre)
    {
        delete[] this->author;
        this->author = nullptr;
    }
    strcpy(this->genre, other.genre);

    this->pages = other.pages;
    this->hardcover = other.hardcover;
}

Book::~Book()
{
    delete[] this->author;
    this->author = nullptr;
    delete[] this->genre;
    this->genre = nullptr;
}

// Might throw std::bad_alloc
Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        // Delete this Media and copy other Media
        Media::operator=(other);

        delete[] this->author;
        this->author = new char[strlen(other.author) + 1];
        strcpy(this->author, other.author);

        delete[] this->genre;
        this->genre = new (std::nothrow) char[strlen(other.genre) + 1];
        if (!this->genre)
        {
            delete[] this->author;
            this->author = nullptr;
        }
        strcpy(this->genre, other.genre);

        this->pages = other.pages;
        this->hardcover = other.hardcover;
    }
    return *this;
}

float Book::estimateReadingTime() const
{
    return this->pages / 30;
}

float Book::calculateLateFee(unsigned int daysLate) const
{
    if (this->hardcover == true)
    {
        return 0.7 * daysLate;
    }
    else
    {
        return 0.5 * daysLate;
    }
}

const char *Book::getAuthor() const
{
    return this->author;
}

const char *Book::getGenre() const
{
    return this->genre;
}

unsigned int Book::getPages() const
{
    return this->pages;
}

bool Book::getHardcover() const
{
    return this->hardcover;
}

// Might throw std::invalid_argument or std::bad_alloc
void Book::setAuthor(const char *author)
{
    if (author == nullptr)
    {
        throw std::invalid_argument("Invalid parameters for Book!");
    }
    delete[] this->author;
    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);
}

// Might throw std::invalid_argument or std::bad_alloc
void Book::setGenre(const char *genre)
{
    if (genre == nullptr)
    {
        throw std::invalid_argument("Invalid parameters for Book!");
    }
    delete[] this->genre;
    this->genre = new char[strlen(genre) + 1];
    strcpy(this->genre, genre);
}

void Book::setPages(unsigned int pages)
{
    if (pages == 0)
    {
        throw std::invalid_argument("Invalid parameters for Book creation!");
    }
    this->pages = pages;
}

void Book::setHardcover(bool hardcover)
{
    this->hardcover = hardcover;
}