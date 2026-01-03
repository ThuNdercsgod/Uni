#include <stdio.h>

#define CAP 100

void copyArr(int arr[], int copy[], unsigned size);
void rotateArr(int arr[], unsigned size, int rotations);
void test(int arr[], unsigned size);

int main()
{
    int arr[CAP];

    unsigned size;
    puts("Enter the size of the array:");
    if (scanf("%u", &size) != 1 ||
        size <= 0 ||
        size > CAP)
    {
        puts("Invalid input!");
        return 1;
    }

    puts("Enter the elements of the array, separated by a space:");
    for (int i = 0; i < size; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            puts("Invalid input!");
            return 1;
        }
    }

    int rotations;
    puts("Enter the number of rotations:");
    if (scanf("%d", &rotations) != 1)
    {
        puts("Invalid input!");
        return 1;
    }

    rotateArr(arr, size, rotations);

    test(arr, size);

    return 0;
}

void copyArr(int arr[], int copy[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        copy[i] = arr[i];
    }
}

void rotateArr(int arr[], unsigned size, int rotations)
{
    int copy[CAP];
    copyArr(arr, copy, size);

    if (rotations > 0)
    {
        for (int i = size - 1; i - rotations >= 0; --i)
        {
            arr[i] = copy[i - rotations];
        }
        for (int i = 0; i < rotations; ++i)
        {
            arr[rotations - 1 - i] = copy[size - 1 - i];
        }
    }
    else if (rotations < 0)
    {
        unsigned rot = 0 - rotations;

        for (int i = 0; i < size - rot; ++i)
        {
            arr[i] = copy[i + rot];
        }
        for (int i = size - rot; i < size; ++i)
        {
            arr[i] = copy[i + rot - size];
        }
    }
}

void test(int arr[], unsigned size)
{
    printf("%d\n", size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
}