#include <stdio.h>

#define CAP 10

int input(unsigned num[]);
void output(unsigned num[], int size);
int areEqual(unsigned first[], int size1, unsigned scnd[], int size2);
int add(unsigned first[], int size1, unsigned scnd[], int size2, unsigned result[]);

int main()
{
    unsigned first[CAP] = {0};
    int size1 = input(first);

    if (size1 == -1)
    {
        return 1;
    }

    unsigned scnd[CAP] = {0};
    int size2 = input(scnd);

    if (size2 == -1)
    {
        return 1;
    }

    output(first, size1);
    output(scnd, size2);

    if (areEqual(first, size1, scnd, size2))
    {
        puts("eq");
    }

    return 0;
}

int input(unsigned num[])
{
    unsigned long long number;
    unsigned size = 0;
    puts("Enter the digits, separated by spaces (less than 10 digits):");
    for (int i = 0; i < CAP; ++i)
    {
        if (scanf("%u", &num[i]) != 1)
        {
            puts("Invalid input!");
            return -1;
        }
    }

    for (int i = 0; i < CAP; ++i)
    {
        if (num[i] == 0)
        {
            size++;
        }
        else
        {
            break;
        }
    }
    size = CAP - size;

    return size;
}

void output(unsigned num[], int size)
{
    for (int i = CAP - size; i < CAP; ++i)
    {
        printf("%u", num[i]);
    }
    printf("\n");
}

int areEqual(unsigned first[], int size1, unsigned scnd[], int size2)
{
    if (size1 != size2)
    {
        return 0;
    }

    for (int i = 0; i < CAP; ++i)
    {
        if (first[i] != scnd[i])
        {
            return 0;
        }
    }

    return 1;
}

int add(unsigned first[], int size1, unsigned scnd[], int size2, unsigned res[])
{
    int size3 = 0;
    for (int i = CAP - 1; i >= 0; --i)
    {
        if (first[i] + scnd[i] > 9)
        {
            res[i] = (first[i] + scnd[i]) % 10;
            first[i - 1]++;
        }
        else
        {
            res[i] = first[i] + scnd[i];
        }
        if (i = 0 && first[i] + scnd[i] > 9)
        {
            puts("Number is too big!");
            return -1;
        }
        size3++;
    }

    return size3;
}