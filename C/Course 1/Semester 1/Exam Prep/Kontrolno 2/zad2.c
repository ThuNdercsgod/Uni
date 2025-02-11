#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 1024

void clearString(char **string);
void clearList(char ***list, int size);
char *createString(int size);
void inputString(char **string);
int wordsNumber(char *string);
int wordsLength(char *string);
char **wordList(int numberOfWords, int length, char *string);

int main()
{
    char *string = createString(CAPACITY);

    if (!string)
    {
        puts("Memory allocation error!");
        clearString(&string);

        return 1;
    }

    inputString(&string);

    int words = wordsNumber(string);
    int length = wordsLength(string);

    char **list = wordList(words, length, string);

    if (!list)
    {
        puts("Memory allocation error!");
        clearString(list);

        return 1;
    }

    clearList(&list, words);
    clearString(&string);

    return 0;
}

void clearString(char **string)
{
    free(*string);

    *string = NULL;
}

void clearList(char ***list, int size)
{
    for (int i = 0; i < size; ++i)
    {
        clearString(list[i]);
    }

    free(list);

    list = NULL;
}

char *createString(int size)
{
    char *string = (char *)malloc(size * sizeof(char));

    if (!string)
    {
        return NULL;
    }

    return string;
}

void inputString(char **string)
{
    puts("Enter the string:");

    int valid = 0;
    do
    {
        fgets(*string, CAPACITY, stdin);

        if ((strlen(*string) - 1) == 0) // because fgets also takes the '\n'
        {
            valid = 0;
            puts("Input error! Try again:");
        }
        else
        {
            valid = 1;
        }
    } while (valid == 0);
}

int wordsNumber(char *string)
{
    int numberOfWords = 0;

    for (int i = 0; i < CAPACITY - 2; ++i)
    {

        if (!(string[i] >= 'a' && string[i] <= 'z' ||
              string[i] >= 'A' && string[i] <= 'Z' ||
              string[i] >= '0' && string[i] <= '9'))
        {
            numberOfWords++;
        }
        if (!(string[i] >= 'a' && string[i] <= 'z' ||
              string[i] >= 'A' && string[i] <= 'Z' ||
              string[i] >= '0' && string[i] <= '9') &&
            string[i + 1] == '\n')
        {
            break;
        }
        else if (string[i] == '\n')
        {
            // numberOfWords++;

            break;
        }
    }

    return numberOfWords;
}

int wordsLength(char *string)
{
    int length = 0;
    int maxLength = 0;

    for (int i = 0; i < CAPACITY - 2; ++i)
    {
        if (string[i] == '\n')
        {
            break;
        }
        if (string[i] >= 'a' && string[i] <= 'z' ||
            string[i] >= 'A' && string[i] <= 'Z' ||
            string[i] >= '0' && string[i] <= '9')
        {
            length++;
        }
        else if (length > maxLength)
        {
            maxLength = length;
            length = 0;
        }
        else
        {
            length = 0;
        }
    }

    return maxLength;
}

char **wordList(int numberOfWords, int length, char *string)
{
    char **list = (char **)malloc(numberOfWords * sizeof(char *));

    if (!list)
    {
        return NULL;
    }

    for (int i = 0; i < length; ++i)
    {
        char *row = (char *)malloc((length + 1) * sizeof(char));

        list[i] = row;

        if (!row)
        {
            for (int i = 0; i < numberOfWords; ++i)
            {
                clearString(&list[i]);
            }

            return NULL;
        }
    }

    if (numberOfWords == 1)
    {
        strcpy(list[0], string);
    }

    else
    {
        for (int i = 0, k = 0; i < numberOfWords; ++i)
        {
            for (int j = 0; j <= length + 1; ++j)
            {
                if (string[k] >= 'a' && string[k] <= 'z' ||
                    string[k] >= 'A' && string[k] <= 'Z' ||
                    string[k] >= '0' && string[k] <= '9')
                {
                    list[i][j] = string[k];
                    k++;
                }
                else
                {
                    list[i][j] = '\0';
                    break;
                }
            }
        }
    }

    return list;
}

void wordsCounter(char **list, int numberOfWords)
{
    for (int i = 0; i < numberOfWords; ++i)
    {
    }
}