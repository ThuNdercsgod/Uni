#pragma once

class Collection;

class Media
{
public:
    Media();
    Media(const char *title, unsigned int id, bool available);
    Media(const Media &other);
    Media(std::istream &load, unsigned int id);
    virtual ~Media();

    Media &operator=(const Media &other);
    bool operator==(const Media &other) const;

    void displayInfo() const;
    virtual float calculateLateFee(unsigned int daysLate) const;
    void saveToFile(std::ostream &save) const;

    const char *getTitle() const;
    unsigned int getId() const;
    bool getAvailable() const;
    const Collection *getOwner() const;

    void setTitle(const char *title);
    void setAvailable(bool available);
    void setOwner(Collection *newOwner);

private:
    char *title;
    const unsigned int id;
    bool available;
    // Pointer to the Collection it belongs
    Collection *owner = nullptr;
};