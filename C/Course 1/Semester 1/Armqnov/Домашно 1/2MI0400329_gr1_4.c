#include <stdio.h>

int main()
{
    unsigned N = 0;
    int K;

    puts("Enter the value of N and K:");
    if(scanf("%u %d", &N, &K) != 2
        || !(K >= 1 && K <= 32))
    {
        puts("Invalid input!");

        return 1;
    }

    int powerOf2 = 0; //колко пъти е имало 2 на някоя степен
    unsigned copyOfN = N;

    while (copyOfN > 0)
    {
        if (copyOfN & 1)
        {
            powerOf2++;
        }
        copyOfN >>= 1;
    }
    //проверка дали има точнко K на брой единици в бинарния запис

    if (powerOf2 == K)
    {
        puts("True");
    }
    else
    {
        puts("False");
    }

    return 0;
}