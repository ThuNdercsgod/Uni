#pragma once

class Media;

class Collection
{
public:
    Collection();
    Collection(const char *name);
    Collection(const Collection &other);
    ~Collection();

    Collection &operator=(const Collection &other);

    void print() const;

    void addMedia(const Media *media);
    void removeMedia(Media *media);
    float calculateTotalLateFees(unsigned int daysLate) const;
    void saveToFile(const char *filName) const;
    void loadFromFile(const char *fileName);

    const char *getName() const;

private:
    void freeItems(int numOfItems);

    char *name;
    // Dynamic array of pointers to Media objects that belong to this Collection
    Media **items = nullptr;
    int numOfItems;
};