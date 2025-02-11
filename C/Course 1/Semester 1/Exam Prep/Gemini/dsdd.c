#include <stdio.h>

int f(int a[5][5])
{
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += a[i][0] + a[0][i];
    return sum;
}

int main()
{
    int a[5][5] = {{1}, {2}, {3}};
    printf("%d ", f(a));
}