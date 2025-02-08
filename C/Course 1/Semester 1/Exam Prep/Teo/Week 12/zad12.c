#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int rows, int collumns);
void clearMatrix(int ***matrix, int rows);
void inputMatrix(int **matrix, int rows, int collumns);

int main()
{
    int rows = 5, collumns = 5;

    int **matrix = createMatrix(rows, collumns);

    if (matrix == NULL)
    {
        puts("No memory allocated!");

        return 1;
    }

    inputMatrix(matrix, rows, collumns);

    int count = 0;

    for (int i = 1; i < rows - 1; ++i)
    {
        for (int j = 1; j < collumns - 1; ++j)
        {
            if (matrix[i + 1][j] == 1 &&
                matrix[i - 1][j] == 1 &&
                matrix[i][j + 1] == 1 &&
                matrix[i][j - 1] == 1)
            {
                count++;
            }
        }
    }

    printf("sdsds %d", count);

    clearMatrix(&matrix, rows);

    return 0;
}

void clearMatrix(int ***matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(*matrix[i]);
    }
    free(*matrix);
}

int **createMatrix(int rows, int collumns)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));

    if (!matrix)
    {
        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (int *)malloc(collumns * sizeof(int));

        if (!matrix[i])
        {
            clearMatrix(&matrix, rows);

            return NULL;
        }
    }

    return matrix;
}

void inputMatrix(int **matrix, int rows, int collumns)
{
    for (int i = 0; i < rows; ++i)
    {
        printf("Enter the elemnts in row %d:\n", i + 1);
        for (int j = 0; j < collumns; ++j)
        {
            int number = 0;
            scanf("%d", &number);
            matrix[i][j] = number;
        }
    }
}