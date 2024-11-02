#include <stdio.h>
#include <math.h>

int main()
{
    //По въведени координати на център на окръжност и нейният радиус, 
    //както и координати на някаква точка да се определи и изведе 
    //какво е взаимното положение на точката и окръжността. Отново само с изрази

    int r;
    int x1, y1;
    int x2, y2;
    double length;
    
    printf("Enter the value of the radius of the circle:\n");
    scanf("%d", &r);
    
    printf("Enter the coordinates of the center O\n");
    scanf("%d %d", &x2, &y2);
    
    printf("Enter the coordinates of A:\n");
    scanf("%d %d", &x1, &y1);
    
    int lengthPow2 = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));

    (lengthPow2 >= 0) &&
    (
        length = sqrt(lengthPow2),
        
        (length < r) && 
        (
            printf("A is inside of the circle\n")
        ) ||
        abs(length - r) <= pow(10, (-6)) && 
        (
            printf("A is on the circle\n")
        ) || 
        (length > r) && 
        (
            printf("A is outside of the circle\n")
        )
    ) ||
    (
        printf("Invalid data!\n")
    );
    
    return 0;
}