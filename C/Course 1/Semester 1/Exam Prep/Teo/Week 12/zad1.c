#include <stdio.h>

unsigned addition(unsigned A, unsigned B);
unsigned multiply(unsigned A, unsigned B);

int main()
{
    unsigned A, B;

    puts("Enter the value of A:");
    scanf("%u", &A);
    puts("Enter the value of B:");
    scanf("%u", &B);

    printf("%u + %u = %u\n", A, B, addition(A, B));
    printf("%u * %u = %u\n", A, B, multiply(A, B));

    return 0;
}

unsigned addition(unsigned A, unsigned B)
{
    if (B == 1)
    {
        return A + 1;
    }
    addition(A + 1, B - 1);
}

unsigned multiply(unsigned A, unsigned B)
{
    if (B == 1)
    {
        return A + A * 1;
    }
    multiply(A + A, B - 1);
}