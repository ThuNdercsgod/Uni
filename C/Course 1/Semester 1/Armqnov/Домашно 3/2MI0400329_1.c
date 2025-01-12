#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(int *ptr);
char **inputTable(int rows, int collumns);
void clearTable(char **table, int rows);
void printTable(char **table, int rows, int collumns);
int checkIfEven(char **table, int row, int collumns);
void findEven(char **table, int *rows, int collumns);
int convertToDecimal(char element);
int sum(char **table, int rows, int collumns);
void sortBySum(char **table, int rows, int collumns);

int main()
{
    int rows = 0, collumns = 0;

    puts("Enter the number of rows in the table:");
    input(&rows);

    puts("Enter the number of collumns in the table:");
    input(&collumns);

    char **table = inputTable(rows, collumns);

    if (table == NULL)
    {
        puts("No memory allocated!");

        return 1;
    }

    findEven(table, &rows, collumns);

    sortBySum(table, rows, collumns);

    puts("After sorting and clearing, the table is:");
    printTable(table, rows, collumns);

    clearTable(table, rows);

    return 0;
}

void input(int *ptr)
{
    int valid = 0;

    do
    {
        valid = 0;
        valid = scanf("%d", ptr);

        if (*ptr <= 0)
        {
            valid = 0;
        }
        if (valid != 1)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid != 1);
}

char **inputTable(int rows, int collumns)
{
    char **table = (char **)malloc(rows * sizeof(char *));

    if (!table)
    {
        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        char *row = (char *)malloc(collumns * sizeof(char));

        table[i] = row;

        if (!row)
        {
            clearTable(table, i);

            return NULL;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        int valid = 0;

        printf("Enter the elements in row %d:\n", i + 1);

        for (int j = 0; j < collumns; ++j)
        {
            scanf("%c", &table[i][j]); // това премахва символът за нов ред от printf, за да не създава проблеми
            do
            {
                valid = scanf("%c", &table[i][j]);

                if (!(table[i][j] >= '0' && table[i][j] <= '9') &&
                    !(table[i][j] >= 'A' && table[i][j] <= 'F') &&
                    !(table[i][j] >= 'a' && table[i][j] <= 'f'))
                {
                    valid = 0;
                }

                if (valid != 1)
                {
                    puts("Wrong input! Try again:");
                    while (getchar() != '\n')
                        ;
                }
            } while (valid != 1);
        }
    }

    return table;
}

void clearTable(char **table, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(table[i]);
    }
    free(table);
}

void printTable(char **table, int rows, int collumns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < collumns; ++j)
        {
            printf("%c ", table[i][j]);
        }
        puts("");
    }
}

int checkIfEven(char **table, int row, int collumns)
{
    char temp = table[row][collumns - 1];

    if (temp & 1u)
    {
        return 0;
    }

    return 1;
}

void findEven(char **table, int *rows, int collumns)
{
    for (int i = 0; i < *rows; ++i)
    {
        int isEven = checkIfEven(table, i, collumns);

        if (isEven == 1)
        {
            free(table[i]);

            for (int j = i; j < *rows - 1; ++j)
            {
                table[j] = table[j + 1];
            }

            i--;
            (*rows)--;
        }
    }
}

int convertToDecimal(char element)
{
    switch (element)
    {
    case 'A':
        return 11;
    case 'B':
        return 12;
    case 'C':
        return 13;
    case 'D':
        return 14;
    case 'E':
        return 15;
    case 'F':
        return 16;
    case 'a':
        return 11;
    case 'b':
        return 12;
    case 'c':
        return 13;
    case 'd':
        return 14;
    case 'e':
        return 15;
    case 'f':
        return 16;
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
}

int sum(char **table, int rows, int collumn)
{
    int sum = 0;

    for (int i = 0; i < rows; ++i)
    {
        sum += convertToDecimal(table[i][collumn]);
    }

    return sum;
}

void sortBySum(char **table, int rows, int collumns)
{
    for (int i = 0; i < collumns - 1; ++i)
    {
        int minSum = sum(table, rows, i);
        int minCol = i;

        for (int j = i + 1; j < collumns; ++j)
        {
            if (sum(table, rows, j) < minSum)
            {
                minSum = sum(table, rows, j);
                minCol = j;
            }
        }

        for (int k = 0; k < rows; ++k)
        {
            int temp = table[k][i];
            table[k][i] = table[k][minCol];
            table[k][minCol] = temp;
        }
    }
}