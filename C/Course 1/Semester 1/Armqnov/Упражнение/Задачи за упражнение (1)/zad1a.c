#include <stdio.h>

int main()
{
    //Въведете две цели числа и изведете тяхното произведение
    int  a, b;
    
    printf("Enter the value of the two numbers:\n");
    scanf("%d %d", &a, &b);
    
    printf("%d * %d = %d\n",a, b, a * b);
    
    return 0;
}