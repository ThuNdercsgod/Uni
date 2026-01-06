#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 1024

char **createTable(int rows, int cols);
void clearTable(char **table, int rows);
void printTable(char **table, int rows, int cols);

void putWord(char **table, const char *word, int row, int cols, int isENG);
void inputTable(char **table, int rows, int cols);

const char *translate(const char **table, int rows, int cols, const char *sentence);

int main()
{
    int rows;
    int cols = 32; // заради 2-те терминиращи нули

    puts("Enter the number of words in the dictionary:");
    if (scanf("%d", &rows) != 1 ||
        rows <= 0)
    {
        puts("Invalid input!");
        return 1;
    }
    getchar();

    char **table = createTable(rows, cols);
    if (!table)
    {
        puts("Memory allocation error!");
        return 2;
    }

    inputTable(table, rows, cols);

    char sentence[CAP];
    puts("Enter the sentence for translation:");
    fgets(sentence, CAP, stdin);
    if (sentence[strlen(sentence) - 1] == '\n')
    {
        sentence[strlen(sentence) - 1] = '\0';
    }

    // printTable(table, rows, cols);

    clearTable(table, rows);

    return 0;
}

char **createTable(int rows, int cols)
{
    char **table = (char **)malloc(rows * sizeof(char *));
    if (!table)
    {
        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        table[i] = (char *)malloc(cols * sizeof(char));
        if (!table[i])
        {
            clearTable(table, i);
            return NULL;
        }
    }

    return table;
}

void clearTable(char **table, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(table[i]);
        table[i] = NULL;
    }

    free(table);
    table = NULL;
}

void printTable(char **table, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int count = 0;

        while (table[i][count] != '\0') // винаги ще стигне до \0
        {                               // заради fgets() в inputTable()
            printf("%c", table[i][count]);
            count++;
        }
        printf(" - ");

        count = cols / 2;
        while (table[i][count] != '\0')
        {
            printf("%c", table[i][count]);
            count++;
        }
        printf("\n");
    }
}

void putWord(char **table, const char *word, int row, int cols, int isENG)
{
    if (isENG)
    {
        for (int i = 0; i < cols / 2; ++i)
        {
            table[row][cols / 2 + i] = word[i];
        }
    }
    else
    {
        for (int i = 0; i < cols / 2; ++i)
        {
            table[row][i] = word[i];
        }
    }
}

void inputTable(char **table, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        char tempBG[16];
        printf("Enter word %d in Bulgarian:\n", i + 1);
        fgets(tempBG, 16, stdin);
        if (tempBG[strlen(tempBG) - 1] == '\n')
        {
            tempBG[strlen(tempBG) - 1] = '\0';
        }
        putWord(table, tempBG, i, cols, 0);

        char tempENG[16];
        printf("Enter word %d in English:\n", i + 1);
        fgets(tempENG, 16, stdin);
        if (tempENG[strlen(tempENG) - 1] == '\n')
        {
            tempENG[strlen(tempENG) - 1] = '\0';
        }
        putWord(table, tempENG, i, cols, 1);
    }
}

const char *translate(const char **table, int rows, int cols, const char *sentence)
{
    int count = 0;
    while (sentence[count] != ' ' && sentence[count] != ',' && sentence[count] != '.')
    {
        }
}