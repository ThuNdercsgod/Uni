#include <stdio.h>
#include <math.h>

int main()

{
    double x, y;
    
    puts("Enter the coordinates x and y of point O(x,y):");
    if (scanf("%lf %lf", &x, &y) != 2)
    {
        puts("Invalid input!");
        return 1;
    }
    
    int position = 0;
    
    if ((y >= 1 && y <= 2) && (x >= -1 && x <= 1)) //проверка за покрив само правоъгълна част
    {
        position = 1;
    }
    
    //проверка за покрив само триъгълни части, използвайки коефициент на подобие на
    //триъг. от покрива и триъг., образуван от прокцията на точката върху височината
    //на първия триъг. (т.е. само y-координатата на точката)
    
    double k = 2 - y; //коефициент на подобие
    double b = 0.6 * k; //страна на триъг. от точката
    if ((y >= 1 && y <= 2) && (x >= (-1 - b) && x <= -1))
    {
        position = 1;
    }
    else if ((y >= 1 && y <= 2) && (x >= 1 && x <= (1 + b)))
    {
        position = 1;
    }
    else if ((y >= 0 && y <= 0.8) && (x >= -0.9 && x <= -0.6)) //проверка за врата
    {
        position = 2;
    }
    else if ((y >= 0.5 && y <= 0.8) && (x >= 0.5 && x <= 0.9)) //проверка за прозорец
    {
        position = 3;
    }
    else if ((y >= 2 && y <= 2.3) && (x >= 0.6 && x <= 0.8)) //проверка за комин
    {
        position = 4;
    }
    else if ((y >= 0 && y <= 1) && (x >= -1 && x <= 1)) //преоверка за основна част на къщата
    {
        position = 5;
    }
    
    //проверка за луна:

    double lengthOO1 = sqrt((x - (-0.5)) * (x - (-0.5)) + (y - 2.5) * (y - 2.5)); //дължина от точка до център на жълта окръжност
    double lengthOO2 = sqrt((x - (-0.2)) * (x - (-0.2)) + (y - 2.8) * (y - 2.8)); //дължина от точка до център на отрязана окръжност
    if (lengthOO1 <= 0.4 && lengthOO2 >= 0.7)
    {
        position = 6;
    }
    
    switch (position)
    {
        case 1:
            puts("Blue");
            break;
        case 2:
            puts("Green");
            break;
        case 3:
            puts("Light blue");
            break;
        case 4:
            puts("Brown");
            break;
        case 5:
            puts("Gray");
            break;
        case 6:
            puts("Yellow");
            break;
        default:
            puts("White");
            break;
    }

    return 0;
}

