#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 1024

void inputInitial(char string[], int size);
char *createString(char initialString[]);
void swap(char *a, char *b);
void permutation(char *helperString, int start, int end);

int main()
{
    char initialString[CAPACITY];

    inputInitial(initialString, CAPACITY);

    char *helperString = createString(initialString);
    if (!helperString)
    {
        free(helperString);

        return 1;
    }

    strcpy(helperString, initialString);
    permutation(helperString, 0, strlen(initialString) - 1);

    free(helperString);
}

void inputInitial(char string[], int size)
{
    int valid = 0;

    puts("Enter a string:");
    do
    {
        valid = 0;
        valid = scanf("%s", string);

        if (valid == 0)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid == 0);
}

char *createString(char initialString[])
{
    int size = strlen(initialString) + 1;
    char *string = (char *)malloc(size * sizeof(char));

    if (!string)
    {
        return NULL;
    }

    return string;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char *helperString, int start, int end)
{
    if (start == end)
    {
        printf("%s\n", helperString);
    }

    for (int i = start; i <= end; ++i)
    {
        swap(&helperString[start], &helperString[i]);
        permutation(helperString, start + 1, end);
        swap(&helperString[start], &helperString[i]);
    }
}