#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    int size = 65;
    int arr[4] = {2, 3, 4, 1};

    bubbleSort(arr, 4);

    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", arr[i]);
    }

    // for (int i = 0; i < size - 1; ++i)
    // {
    //     for (int j = i + 1; j < size; ++j)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }
}