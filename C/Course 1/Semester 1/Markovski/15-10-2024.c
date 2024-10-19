#include <stdio.h>

int main()
{
    // //zadacha 1
    // int a;

    // printf("Enter a whole number:\n");
    // scanf("%d", &a);

    // if (a > 0)
    // {
    //     printf("The number is Positive\n");
    // }
    // else if (a == 0)
    // {
    //     printf("The number is 0\n");
    // }
    // else
    // {
    //     printf("The number is Negative\n");
    // }

    // //zadacha 2
    // int a, b;
    // printf("Enter the value of the first number:\n");
    // scanf("%d", &a);

    // printf("Enter the value of the second number:\n");
    // scanf("%d", &b);

    // if (a > b)
    // {
    //     printf("%d is bigger than %d\n", a, b);
    // }
    // else if (a < b)
    // {
    //     printf("%d is bigger than %d\n", b, a);
    // }
    // else
    // {
    //     printf("%d is equal to %d", a, b);
    // }

    // //zadacha 3
    // int dayofWeek;
    
    // printf("Enter the number of the day of the week (1-7)\n");
    // scanf("%d", &dayofWeek);
    
    // switch (dayofWeek)
    // {
    //     case 1:
    //         printf("The day of the week is Monday.\n");
    //         break;

    //     case 2:
    //         printf("The day of the week is Tuesday.\n");
    //         break;

    //     case 3:
    //         printf("The day of the week is Wednesday.\n");
    //         break;

    //     case 4:
    //         printf("The day of the week is Thursday.\n");
    //         break;

    //     case 5:
    //         printf("The day of the week is Friday.\n");
    //         break;

    //     case 6:
    //         printf("The day of the week is Saturday.\n");
    //         break;

    //     case 7:
    //         printf("The day of the week is Sunday.\n");
    //         break;

    //     default:
    //         printf("The number should be between 1 and 7!");
    //         break;
    // }

    // //zadacha 4
    // int year;

    // printf("Enter the Year:\n");
    // scanf("%d", &year);

    // int four = year % 4;
    // int hundred = year % 100;
    // int fourhun = year % 400;
    
    // if (four == 0)
    // {
    //     printf("The year is a leap year.\n");
    // }
    // else if (hundred == 0)
    // {
    //     printf("The year is not a leap year.\n");
    // }
    // else if (fourhun == 0)
    // {
    //     printf("The year is a leap year.\n");
    // }
    // else
    // {
    //     printf("The year is not a leap year\n");
    // }

    ////zadacha 5
    // int a, b, c;

    // printf("Enter the 3 numbers:\n");
    // scanf("%d %d %d", &a, &b, &c);

    // int t;
    // if (a > b)
    // {
    //     t = a;
    //     a = b;
    //     b = c;
    //     a = t;
    // }

    // if (b > c)
    // {
    //     t = b;
    //     b = c;
    //     c = t;
    // }

    // printf("%d, %d, %d", a, b, c);

    // //zadacha 6
    // int a, b, c, d, e;

    // printf("Enter the value of the 5 numbers:\n");
    // scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // if (b >= a && b >= c)
    // {
    //     if (c <= d)
    //     {
    //         printf("yes");
    //     }
    //     else
    //     {
    //         printf("no");
    //     }
    // }
    // else if ((b <= a) && (b <= c))
    // {
    //     if (c >= d)
    //     {
    //         printf("yes");
    //     }
    //     else
    //     {
    //         printf("no");
    //     }
    // }
    // else
    // {
    //     printf("no");
    // }

    // //zadacha 7
    // int radius;
    // int x;
    // int y;

    // printf("Enter the value of the radius:\n");
    // scanf("%d", &radius);

    // printf("Enter the x-coordinate and the y-coordinate:\n");
    // scanf("%d %d", &x, &y);

    // if (x == radius || y == radius)
    // {
    //     printf("On the circle");
    // }
    // else if (x > radius || y > radius)
    // {
    //     printf("Outside of the circle\n");
    // }
    // else if (x < radius || y < radius)
    // {
    //     printf("Inside of the circle\n");
    // }
    // else
    // {
    //     printf("Something is wrong\n");
    // }

    //zadacha 8
    int Day;
    int Month;
    int Year;

    printf("Enter the day(1-31), the month(1-12) and the year:\n");
    scanf("%d %d %d", &Day, &Month, &Year);

    if ((Day <= 1 && Day >= 31) && (Month <= 1 && Month >=12))
    {
        printf("Invalid date\n");
    }
    else
    {   
        int four = Year % 4;
        int hundred = Year % 100;
        int fourhun = Year % 400;
        int isLeap;
        
        if (four == 0)
        {
            isLeap = 1;
        }
        else if (hundred == 0)
        {
            isLeap = 0;
        }
        else if (fourhun == 0)
        {
            isLeap = 1;
        }
        else
        {
            isLeap = 0;
        }

        switch (Month)
        {
            case 1:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 2:
                if (isLeap == 1)
                {
                    if (Day < 29)
                    {
                        Day ++;
                        printf("The next day is %d\n", Day);
                    }
                    else
                    {
                        printf("The next day is 1\n");
                    }
                }
                else
                {
                    if (Day < 28)
                    {
                        Day ++;
                        printf("The next day is %d\n", Day);
                    }
                    else
                    {
                        printf("The next day is 1\n");
                    }
                }
                break;
            case 3:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 4:
                if (Day < 30)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 5:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 6:
                if (Day < 30)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 7:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 8:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 9:
                if (Day < 30)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 10:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 11:
                if (Day < 30)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
            case 12:
                if (Day < 31)
                {
                    Day ++;
                    printf("The next day is %d\n", Day);
                }
                else
                {
                    printf("The next day is 1\n");
                }
                break;
        }
    }

    return 0;
}