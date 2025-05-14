#pragma once

class Media;

class Collection
{
public:
    Collection();
    Collection(const char *name, Media **items, int numOfItems);
    Collection(const Collection &other);
    ~Collection();

    Collection &operator=(const Collection &other);

    void print() const;

    void add();

    const char *const getName() const;

private:
    char *name;
    Media **items;
    int numOfItems;
};