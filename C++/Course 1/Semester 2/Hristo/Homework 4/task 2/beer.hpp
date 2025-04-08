#pragma once

class Beer
{
public:
    Beer(const char *brand, int volume);

    const char *getBrand() const;
    int getVolume() const;

    void add(Beer beer);
    void fill(int volume);
    bool check(const char *brand) const;

private:
    char brand[129];
    int volume;
};