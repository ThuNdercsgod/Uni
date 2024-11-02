#include <stdio.h>
#include <math.h>

int main()
{
    //По въведено лице на равностранен триъгълник изведете дължината на страната му

    double area;

    printf("Enter the area of the triangle:\n");
    scanf("%lf", &area);
    
    double sidePower2 = (4 * area) / sqrt(3);
    double side;

    (sidePower2 >= 0) && 
    (
        (side = sqrt(sidePower2)),
        (printf("The side of the triangle is %lf\n", side))
    ) ||
    (
        printf("Invalid data!\n")
    );

    return 0;
}