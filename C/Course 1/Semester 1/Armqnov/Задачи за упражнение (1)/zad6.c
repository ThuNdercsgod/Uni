#include <stdio.h>
#include <math.h>

int main()
{
    //Въведете три числа с плаваща точка и за тях изведете периметъра 
    //и лицето на триъгълник със страни с дължини тези числа. Отново 
    //без допълнителни конструкции (извън изрази) валидирайте, че 
    //стойностите са коректни

    double a, b, c;
    double P;
    double p;
    double S;
    
    printf("Enter the length of the sides of the triangle:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    (a > 0) && (b > 0) && (c > 0) && ((a + b) > c) && ((b + c) > a) && ((a + c) > b) &&
    (
        (P = a + b + c),
        (p = P / 2),
        
        (S = sqrt((p - a) * (p - b) * (p - c))),
        
        (printf("The perimeter is %lf\n", P)),
        (printf("The area is %lf\n", S))
    ) || 
    (
        printf("Invalid data!\n")
    );
    
    return 0;
}