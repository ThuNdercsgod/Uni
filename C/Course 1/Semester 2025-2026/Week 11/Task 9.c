#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int rows, int cols);
void inputMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
int **addition(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2);
int **subtraction(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2);
int **transpose(int **matrix, int rows, int cols);
void clearMatrix(int **matrix, int rows);

int main()
{
    int rows = 3, cols = 2;
    // puts("Enter the number of rows and columns:");
    // if (scanf("%d %d", &rows, &cols) != 2)
    // {
    //     puts("Invalid input!");
    //     return 1;
    // }

    int **matrix1 = createMatrix(rows, cols);
    if (!matrix1)
    {
        puts("Memory allocation error!");
        return 2;
    }

    inputMatrix(matrix1, rows, cols);
    if (!matrix1)
    {
        return 1;
    }

    int **matrix2 = createMatrix(rows, cols);
    if (!matrix2)
    {
        puts("Memory allocation error!");
        return 2;
    }

    inputMatrix(matrix2, rows, cols);
    if (!matrix2)
    {
        return 1;
    }

    int **result = transpose(matrix1, rows, cols);
    int rowsT = cols;
    int colsT = rows;

    printMatrix(result, rowsT, colsT);

    clearMatrix(matrix1, rows);
    clearMatrix(matrix2, rows);
    clearMatrix(result, rowsT);

    return 0;
}

int **createMatrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (!matrix)
    {
        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        int *row = (int *)malloc(cols * sizeof(int));

        if (!row)
        {
            clearMatrix(matrix, i);
            return NULL;
        }

        matrix[i] = row;
    }

    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols)
{
    puts("Enter the values of the matrix:");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                puts("Invalid input!");
                clearMatrix(matrix, rows);
                return;
            }
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

int **addition(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2)
{
    if (rows1 != rows2 || cols1 != cols2)
    {
        puts("Incompatibility of matrixes!");
        return NULL;
    }

    int **result = createMatrix(rows1, cols1);
    if (!result)
    {
        puts("Memory allocation error!");
        return NULL;
    }

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

int **subtraction(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2)
{
    if (rows1 != rows2 || cols1 != cols2)
    {
        puts("Incompatibility of matrixes!");
        return NULL;
    }

    int **result = createMatrix(rows1, cols1);
    if (!result)
    {
        puts("Memory allocation error!");
        return NULL;
    }

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

int **transpose(int **matrix, int rows, int cols)
{
    int **transposed = createMatrix(cols, rows);
    if (!transposed)
    {
        puts("Memory allocation error!");
        return NULL;
    }

    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            transposed[i][j] = matrix[j][i];
        }
    }

    return transposed;
}

void clearMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);
    matrix = NULL;
}