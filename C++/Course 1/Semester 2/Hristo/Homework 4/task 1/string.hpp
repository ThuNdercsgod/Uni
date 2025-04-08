#pragma once

class String
{
public:
    String();
    String(int size);
    String(const char *string);
    ~String();

    void copy(const char *copy);
    void append(const char *append);
    void combine(const char *combine);

    const char *const c_str() const;
    int length() const;
    void clear();
    bool empty() const;
    char at(int position) const;

private:
    char *string;
};