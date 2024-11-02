#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, a1, b1;
    double x2, y2, a2, b2;
    double S, a3, b3;
    
    puts("Enter the coordinates (x1; y1) of the lower leftmost point of the first rectangle:");
    scanf("%lf %lf", &x1, &y1);
    
    puts("Enter the length and the height of of the first rectangle:");
    scanf("%lf %lf", &a1, &b1);
    
    puts("Enter the coordinates x2; y2) of the lower leftmost point of the second rectangle:");
    scanf("%lf %lf", &x2, &y2);
    
    puts("Enter the length and the height of the second rectangle:");
    scanf("%lf %lf", &a2, &b2);
    
    if ((x1 < x2) && (y1 < y2))
    {
        a3 = a1 - abs(x2 - x1);
        b3 = b1 - abs(y2 - y1);
        S = a3 * b3;
            
        printf("The area of the common ground of the rectangles is %lf", S);
    }
    else if ((x1 < x2) && !(y1 < y2))
    {
        a3 = a1 - abs(x2 - x1);
        b3 = b2 - abs(y1 - y2);
        S = a3 * b3;
            
        printf("The area of the common ground of the rectangles is %lf", S);
    }
    else if (!(x1 < x2) && (y1 < y2))
    {
        a3 = a2 - abs(x1 - x2);
        b3 = b1 - abs(y2 - y1);
        S = a3 * b3;
            
        printf("The area of the common ground of the rectangles is %lf", S);
    }
    else if (!(x1 < x2) && ! (y1 < y2))
    {
        a3 = a2 - abs(x1 - x2);
        b3 = b2 - abs(y1 - y2);
        S = a3 * b3;
        
        printf("The area of the common ground of the rectangles is %lf", S);
    }
    
    return 0;
}