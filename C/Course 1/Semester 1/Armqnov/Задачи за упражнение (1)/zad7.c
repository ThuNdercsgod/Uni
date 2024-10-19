#include <stdio.h>
#include <math.h>

int main()
{
    //Въведете три числа a, b и c. Нека те са коефициенти в уравнението 
    //ax^2 + bx + c = 0. Решете уравнението (изведете корените му). 
    //Помислете за различните случаи. Отново (за сега) използвайте само изрази.

    int a, b, c;
    double x1, x2;
    
    printf("Enter the values of the multipliers \"a\", \"b\" and \"c\":\n");
    scanf("%d %d %d", &a, &b, &c);
    
    int D = (b * b) - (4 * a * c);

    (a != 0) && (D >= 0) &&
    (
        x1 = (-b + sqrt(D)) / (2 * a),
        x2 = (-b - (sqrt(D))) / (2 * a),
        
        printf("x1 = %lf and x2 = %lf\n", x1, x2)
    ) ||
    (
        printf("Invalid data!\n")
    );
    
    return 0;
}