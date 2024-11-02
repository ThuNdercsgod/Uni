#include <stdio.h>
#include <math.h>

int main()
{
    //По въведени евклидови координати на две точки в равнината намерете и изведете разстоянието между тях.

    int x1, y1;
    int x2, y2;
    double length;
    
    printf("Enter the coordinates of the point A:\n");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the point B:\n");
    scanf("%d %d", &x2, &y2);
    
    int lengthPower2 = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));

    lengthPower2 >= 0 &&
    (
        length = sqrt(lengthPower2),
        
        printf("The length of AB is %lf\n", length)
    ) ||
    (
        printf("Invalid data!\n")
    );
    
    return 0;
}