#include <stdio.h>

int main()
{
    //Да се въведе число D, означаващо мярка на ъгъл в градуси. Да се изведе същата мярка в радиани

    int angDeg;
    double angRad;
    
    printf("Enter the value of the angle in degrees:\n");
    scanf("%d", &angDeg);
    
    angRad = angDeg / 180.0;
    
    printf("If \"P\" = pi(180 degrees):\n");
    printf("The angle in radians is %lf * P\n", angRad);
    
    return 0;
}
