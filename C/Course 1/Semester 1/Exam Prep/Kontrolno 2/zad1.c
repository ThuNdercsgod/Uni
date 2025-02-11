#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

int inputNumber()
{
    int number = 0;
    int valid = 0;

    do
    {
        valid = scanf("%d", &number);

        if (valid != 1)
        {
            puts("Input error! Try again:");
            valid = 0;
        }
    } while (valid == 0);

    return number;
}

void clearArray(int *array)
{
    free(array);

    array = NULL;
}

void clearTable(int **table, int size)
{
    for (int i = 0; i < size; ++i)
    {
        clearArray(table[i]);
    }

    free(table);

    *table = NULL;
}

int **createTable(int collumns, int rows)
{
    int **table = (int **)malloc(rows * sizeof(int *));

    if (!table)
    {
        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        int *row = (int *)malloc(collumns * sizeof(int));
        table[i] = row;

        if (!table[i])
        {
            clearTable(table, i);

            return NULL;
        }
    }
}

void inputTable(int **table, int rows, int collumns)
{
    for (int i = 0; i < rows; ++i)
    {
        printf("Enter the elements in row %d:", i + 1);
        for (int j = 0; j < collumns; ++j)
        {
            table[i][j] = inputNumber();
        }
        puts("");
    }
}

int sum(int **table, int row, int collumns)
{
    int sum = 0;

    for (int i = 0; i < collumns; ++i)
    {
        sum += table[row][i];
    }

    return sum;
}

void removeRow(int **table, int *rows, int row)
{
    for (int i = row; i < *rows; ++i)
    {
        swapRows(table, i, i + 1);
    }

    free(table[*rows]);

    *rows--;
}

void swapRows(int **table, int row1, int row2)
{
}