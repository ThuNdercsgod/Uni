#include <stdio.h>
#include <math.h>

int main()
{
    //По въведени евклидови координати на три точки в равнината проверете дали лежат на една права

    double x1, y1;
    double x2, y2;
    double x3, y3;
    double k, b;
    
    printf("Enter the coordinates of the point A:\n");
    scanf("%lf %lf", &x1, &y1);
    
    printf("Enter the coordinates of the point B:\n");
    scanf("%lf %lf", &x2, &y2);
    
    printf("Enter the coordinates of the point C:\n");
    scanf("%lf %lf", &x3, &y3);
    
    abs(x2 - x1) <= pow(10, (-6)) &&
    (
        k = (y2 - y1) / (x2 - x1),
        b = y1 - ((y2 - y1) / (x2 - x1)) * x1,

        abs(y3 - ((k * x3) + b)) <= pow(10, (-6)) &&
        (
            printf("A, B and C lie on a straight line\n")
        ) || 
        (
            printf("A, B and C are do not lie on a straight line\n")
        )
    ) ||
    (
        printf("Invalid data!\n")
    );
    return 0;
}