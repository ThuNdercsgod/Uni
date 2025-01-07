#include <stdio.h>
#define CAPACITY 100

void input(int *ptr);
void inputArray(int arr[CAPACITY], int *pSize, int cap);
void inputSequence(unsigned seq[CAPACITY][2], int k, int arrSize, int cap);
void sortSequence(unsigned arr[CAPACITY][2], int size);
void printSequence(unsigned seq[CAPACITY][2], int size);
void printArray(int arr[CAPACITY], int size);
void reverse(int arr[CAPACITY], int arrSize, unsigned seq[CAPACITY][2], int k);

int main()
{
    int arrSize;
    int arr[CAPACITY];
    inputArray(arr, &arrSize, CAPACITY);

    int k; // k е броят на интервалите
    puts("Enter the amount of intervals in the sequence:");
    input(&k);

    unsigned seq[CAPACITY][2];
    inputSequence(seq, k, arrSize, CAPACITY);
    sortSequence(seq, k);

    puts("The sorted sequence is:");
    printSequence(seq, k);
    puts("");

    reverse(arr, arrSize, seq, k);

    puts("The reversed array is:");
    printArray(arr, arrSize);

    return 0;
}

void input(int *ptr)
{
    int valid = 0;

    do
    {
        valid = 0;
        valid = scanf("%d", ptr);

        if (*ptr < 0 || *ptr > CAPACITY)
        {
            valid = 0;
        }

        if (valid != 1)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid != 1);
}

void inputArray(int arr[CAPACITY], int *pSize, int cap)
{
    int valid;
    int temp;

    puts("Enter the size of the array:");
    input(&temp);

    *pSize = temp;

    puts("Enter the elements of the array:");
    for (int i = 0; i < *pSize; ++i)
    {
        do
        {
            valid = 0;
            valid = scanf("%d", &arr[i]);

            if (valid != 1)
            {
                printf("Wrong input for element %d! Try again:\n", i + 1);
            }
        } while (valid != 1);
    }
}

void inputSequence(unsigned seq[CAPACITY][2], int k, int arrSize, int cap)
{
    int valid;

    puts("Enter the elements of the sequence:");
    for (int i = 0; i < k; ++i) // k - бр. на интервали => k-редове с 2 колони - винаги положителен брой
    {
        for (int j = 0; j < 2; ++j)
        {
            do
            {
                int temp;

                valid = 0;
                valid = scanf("%d", &temp);

                if (valid != 1)
                {
                    printf("Wrong input for element %d.%d! Try again:\n", i + 1, j + 2);
                }

                if (temp >= 0 || temp < arrSize)
                {
                    seq[i][j] = temp;
                }
                else
                {
                    valid = 0;
                }
            } while (valid != 1);
        }
        if (seq[i][0] > seq[i][1]) // прави интервала от по-малкото число към по-голямото
        {
            int temp = seq[i][0];
            seq[i][0] = seq[i][1];
            seq[i][1] = temp;
        }
    }
}

void sortSequence(unsigned seq[CAPACITY][2], int size)
{
    for (int i = 0; i < size - 1; ++i) // сортиране на големината на интервалите
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if ((seq[j][1] - seq[j][0]) < (seq[j + 1][1] - seq[j + 1][0]))
            {
                int temp[2] = {seq[j][1], seq[j][0]};
                seq[j][1] = seq[j + 1][1];
                seq[j][0] = seq[j + 1][0];
                seq[j + 1][1] = temp[0];
                seq[j + 1][0] = temp[1];
            }
        }
    }
}

void printSequence(unsigned seq[CAPACITY][2], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            printf("%d ", seq[i][j]);
        }
    }
}

void printArray(int arr[CAPACITY], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void reverse(int arr[CAPACITY], int arrSize, unsigned seq[CAPACITY][2], int k)
{
    for (int i = 0; i < k; ++i)
    {
        int j = seq[i][0];
        do
        {
            int temp = arr[j];
            arr[j] = arr[seq[i][1] - j + seq[i][0]];
            arr[seq[i][1] - j + seq[i][0]] = temp;

            ++j;
        } while (j <= ((seq[i][1] - seq[i][0]) / 2));
    }
}