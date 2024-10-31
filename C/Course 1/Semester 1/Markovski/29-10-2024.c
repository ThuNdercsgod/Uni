#include <stdio.h>

unsigned euclid(unsigned number, int derivative)
{
    unsigned mod = number % derivative;
    number = derivative;
    derivative = mod;
}

int main()
{
    unsigned N;

    puts("Enter a number greater then 20:");
    scanf("%u", &N);

    //validation...

    unsigned m, m1, m2, n;
    unsigned first, second;

    for (int i = 1; i < N; i++)
    {
        m = i;

        first = i / 10;
        euclid(first, m);

        if (m != 0)
        {
            m = i;
            second = i % 10;
            euclid(second, m);

            if (m != 0)
            {
                printf("%d ", i);
            }
        }
    }   
    
    puts(" are great numbers.\n");

    return 0;
}