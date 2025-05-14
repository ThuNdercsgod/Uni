#pragma once

class Collection;

class Media
{
public:
    Media();
    Media(const char *title, unsigned int id, bool available, Collection *owner);
    Media(const Media &other);
    virtual ~Media();

    Media &operator=(const Media &other);

    void print() const;

    char *getTitle() const;
    unsigned int getId() const;
    bool getAvailable() const;
    Collection *getOwner() const;

    void setTitle(const char *title);
    void setId(unsigned int id);
    void setAvailable(bool available);
    void setOwner(Collection *newOwner);

private:
    char *title;
    unsigned int id;
    bool available;
    Collection *owner;
};