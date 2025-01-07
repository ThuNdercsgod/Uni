#include <stdio.h>
#define CAPACITY 100

unsigned dist(const unsigned *pNumber1, const unsigned *pNumber2);
void read(int arr[CAPACITY][CAPACITY], int size, int *pRows, int *pCollumns);
void printArray(unsigned arr[CAPACITY][CAPACITY], int size, const int *pRows, const int *pCollumns);
void toUnsigned(int arr1[CAPACITY][CAPACITY], unsigned arr2[CAPACITY][CAPACITY], int rows, int collumns, int size);
void clearRow(unsigned arr[CAPACITY][CAPACITY], int rowToClear, const int *pCollumns, int size);
void clearK(int K, unsigned arr[CAPACITY][CAPACITY], int rows, int collumns, int size);

int main()
{
    int rows, collumns;
    int arrSigned[CAPACITY][CAPACITY] = {0};
    unsigned arrUnsigned[CAPACITY][CAPACITY] = {0};

    read(arrSigned, CAPACITY, &rows, &collumns);

    toUnsigned(arrSigned, arrUnsigned, rows, collumns, CAPACITY);

    printArray(arrUnsigned, CAPACITY, &rows, &collumns);

    int valid = 0;

    int K;

    puts("Enter the value of the integer K:");
    do
    {
        valid = 0;
        valid = scanf("%d", &K);

        if (K > sizeof(int) * 8 * rows || K < 0)
        {
            valid = 0;
        }

        if (valid != 1)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid != 1);

    clearK(K, arrUnsigned, rows, collumns, CAPACITY);

    printf("The matrix, after removing the %d-similar rows is:\n", K);

    printArray(arrUnsigned, CAPACITY, &rows, &collumns);

    return 0;
}

unsigned dist(const unsigned *pNumber1, const unsigned *pNumber2)
{
    unsigned hemming = 0;

    unsigned difference = *pNumber1 ^ *pNumber2;

    while (difference != 0u)
    {
        if (difference & 1u)
        {
            hemming++;
        }

        difference >>= 1;
    }

    return hemming;
}

void read(int arr[CAPACITY][CAPACITY], int size, int *pRows, int *pCollumns)
{
    int valid;

    puts("Enter the amount of rows in the matrix:");
    do
    {
        valid = 0;
        valid = scanf("%d", pRows);

        if (*pRows < 0 || *pRows > size)
        {
            valid = 0;
        }

        if (valid != 1)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid != 1);

    puts("Enter the amount of collumns in the matrix:");
    do
    {
        valid = 0;
        valid = scanf("%d", pCollumns);

        if (*pCollumns < 0 || *pCollumns > size)
        {
            valid = 0;
        }

        if (valid != 1)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid != 1);

    printf("Enter the elements of the matrix:");
    for (int i = 0; i < *pRows; ++i)
    {
        for (int j = 0; j < *pCollumns; ++j)
        {
            do
            {
                valid = 0;
                valid = scanf("%d", &arr[i][j]);

                if (arr[i][j] < 0)
                {
                    arr[i][j] = 0;
                }

                if (valid != 1)
                {
                    printf("Wrong for element %d.%d! Try again:\n", i + 1, j + 1);
                }
            } while (valid != 1);
        }
    }
}

void printArray(unsigned arr[CAPACITY][CAPACITY], int size, const int *pRows, const int *pCollumns)
{
    for (int i = 0; i < *pRows; ++i)
    {
        for (int j = 0; j < *pCollumns; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

void toUnsigned(int arrSigned[CAPACITY][CAPACITY], unsigned arrUnsigned[CAPACITY][CAPACITY], int rows, int collumns, int size)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < collumns; ++j)
        {
            if (arrSigned[i][j] >= 0)
            {
                arrUnsigned[i][j] = (unsigned)arrSigned[i][j];
            }
            else
            {
                arrUnsigned[i][j] = 0;
            }
        }
    }
}

void clearRow(unsigned arr[CAPACITY][CAPACITY], int rowToClear, const int *pCollumns, int size)
{
    for (int i = 0; i < *pCollumns; ++i)
    {
        arr[rowToClear][i] = 0;
    }
}

void clearK(int K, unsigned arr[CAPACITY][CAPACITY], int rows, int collumns, int size)
{
    int valid = 0;

    unsigned rowsHemmingDist;
    for (int i = 0; i < rows; ++i)
    {
        rowsHemmingDist = 0;
        for (int j = 0; j < collumns; ++j)
        {
            for (int k = 0; k < collumns; ++k)
            {
                rowsHemmingDist += dist(&arr[i][j], &arr[i][k]);
            }
        }

        if (rowsHemmingDist > K)
        {
            clearRow(arr, i, &collumns, size);
        }
    }
}