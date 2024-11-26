#include <stdio.h>
#include <math.h>

#define CAPACITY 10
#define EPS 1E-9

void transform(double arr[], unsigned  size);
int checkNext(double arr[], unsigned size);
void printArray(double arr[], unsigned size);

int main()
{
    double arr[CAPACITY] = { 4, 3, -5, 2.3, -1.2, 0 };

    puts("The array is:");
    printArray(arr, CAPACITY);

    transform(arr, CAPACITY);

    puts("The transformed array is:");
    printArray(arr, CAPACITY);

    checkNext(arr, CAPACITY);
    
    
    return 0;
}

void transform(double arr[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        if (fabs(arr[i]) < EPS)
        {
            arr[i] = 1;
        }
        else if (arr[i] < 0)
        {
            arr[i] = arr[i] * arr[i];  
        }
        else if (arr[i] > 0)
        {
            arr[i] = arr[i] / 2;
        }
    }
}

int checkNext(double arr[], unsigned size)
{
    for (int i = 0; i < (size - 1); ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            if (fabs(arr[i] - arr[j]) < EPS)
            {
                printf("arr[%d] = arr[%d] = %lf", i, j, arr[i]);
            }
        }
    }
}

void printArray(double arr[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("arr[%d] = %lf, ", i, arr[i]);
    }
    puts("");
}