#include <stdio.h>

int main()
{
    //Въведете две цели числа и изведете по-малкото от двете числа

    int a, b;

    printf("Enter the value of the two numbers:\n");
    scanf("%d %d", &a, &b);

    ((a < b) && printf("%d is smaller than %d\n", a, b)) || 
    ((b < a) && printf("%d is smaller than %d\n", b, a)) || 
    ((a == b) && printf("%d is equal to %d\n", a, b));

    return 0;
}