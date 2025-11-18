#include <stdio.h>

int powOf10(int power);
int removeKthDigit(int n, int m);
int isPalindrome(int num);

int main()
{
    int a, b;
    puts("Enter the interval of non-negative intergers [a, b] as follows: \"a b\"");
    if (scanf("%d %d", &a, &b) != 2 ||
        a < 0 ||
        b < a)
    {
        puts("Invalid input!");
        puts("a b");

        return 1;
    }

    int temp = b;
    int digitsB = 0;
    if (temp == 0)
    {
        digitsB = 1;
    }
    else
    {
        while (temp > 0)
        {
            digitsB++;
            temp /= 10;
        }
    }

    int k;
    puts("Enter the non-negative integer k as follows: \"k\"");
    if (scanf("%d", &k) != 1 ||
        k > digitsB)
    {
        puts("Invalid input!");

        return 1;
    }

    for (int i = a; i <= b; ++i)
    {
        int m = removeKthDigit(i, k);
        if (m != -1 &&
            isPalindrome(m))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}

int powOf10(int power)
{
    int result = 1;
    while (power-- > 0)
    {
        result *= 10;
    }

    return result;
}

int removeKthDigit(int num, int k)
{
    int p = powOf10(k - 1);
    if (num < p)
    {
        return -1;
    }

    int rightOfK = num % p;
    int leftOfK = num / (p * 10);

    return leftOfK * p + rightOfK;
}

int isPalindrome(int num)
{
    if (num < 0)
    {
        return 0;
    }

    int temp = num;
    int reversed = 0;
    while (temp > 0)
    {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    return reversed == num;
}