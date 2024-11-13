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

    //заб.: ако точката попада на границата между две части - ще бъде изведен цвета на частта, проверена преди другата
    
    //проверката за покрив разделяме на правоъгълна част и два триъгълника:

    //проверка за покрив само триъгълни части, използвайки коефициент на подобие на
    //триъг. от покрива и триъг., образуван от прокцията на точката върху височината
    //на първия триъг. (т.е. само y-координатата на точката)

    double k = 2 - y; //коефициент на подобие
    double b = 0.6 * k; //страна на триъг., образувана от точката

    //проверка за луна (точката трябва да е в жълтата окр. но извън отрязаната):

    double lengthOO1 = sqrt((x - (-0.5)) * (x - (-0.5)) + (y - 2.5) * (y - 2.5)); //дължина от точка до център на жълта окръжност
    double lengthOO2 = sqrt((x - (-0.2)) * (x - (-0.2)) + (y - 2.8) * (y - 2.8)); //дължина от точка до център на отрязана окръжност

    if ((y >= 1 && y <= 2) && (x >= -1 && x <= 1)) //проверка за покрив само правоъгълна част
    {
        puts("Blue");
    } 
    //проверка за покрив само триъгълни части:
    else if ((y >= 1 && y <= 2) && (x >= (-1 - b) && x <= -1))
    {
        puts("Blue");
    }
    else if ((y >= 1 && y <= 2) && (x >= 1 && x <= (1 + b)))
    {
        puts("Blue");
    }
    else if ((y >= 0 && y <= 0.8) && (x >= -0.9 && x <= -0.6)) //проверка за врата
    {
        puts("Green");
    }
    else if ((y >= 0.5 && y <= 0.8) && (x >= 0.5 && x <= 0.9)) //проверка за прозорец
    {
        puts("Light blue");
    }
    else if ((y >= 2 && y <= 2.3) && (x >= 0.6 && x <= 0.8)) //проверка за комин
    {
        puts("Brown");
    }
    else if ((y >= 0 && y <= 1) && (x >= -1 && x <= 1)) //преоверка за основна част на къщата
    {
        puts("Gray");
    }   
    else if (lengthOO1 <= 0.4 && lengthOO2 >= 0.7) //проверка за луна
    {
        puts("Yellow");
    }
    else //точката е извън къщата и луната
    {
        puts("White");
    }
    
    return 0;
}

