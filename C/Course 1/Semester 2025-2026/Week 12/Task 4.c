#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 1024

void inputString(char *string);
void moveLeft(char *string, const char *where, int amount, const char *pos);
void moveRight(char *string, const char *where, int amount, const char *pos);
int replace(char *string, const char *where, const char *what);

int main()
{
    char string[CAP];
    inputString(string);

    char where[CAP];
    inputString(where);

    char what[CAP];
    inputString(what);

    if (strlen(string) == 0 ||
        strlen(where) == 0 ||
        strlen(what) == 0)
    {
        puts("Invalid input!");
        return 1;
    }

    if (replace(string, where, what) == -1)
    {
        return 2;
    }

    puts(string);

    return 0;
}

void inputString(char *string)
{
    puts("Enter the sentence:");
    fgets(string, CAP, stdin);
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }
}

void moveLeft(char *string, const char *where, int amount, const char *pos)
{
    char *posn = pos;
    posn = posn + strlen(where) - amount;
    for (int i = 0; i < strlen(string) + 1; ++i)
    {
    }
}

void moveRight(char *string, const char *where, int amount, const char *pos)
{
}

int replace(char *string, const char *where, const char *what)
{
    while (strstr(string, where) != NULL)
    {
        char *pos = strstr(string, where);

        int amount = strlen(where) - strlen(what);

        if (amount > 0)
        {
            moveLeft(string, where, amount, pos);
        }
        else if (amount < 0)
        {
            moveRight(string, where, amount, pos);
        }
    }

    return 0;
}