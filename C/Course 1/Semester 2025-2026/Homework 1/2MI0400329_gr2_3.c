#include <stdio.h>

int extractYear(int num);
int extractMonth(int num);
int isCorrectDate(int day, int month, int year);
int extractDay(int num);
int extractExpDate(int num);
int dayOfYear(int day, int month, int year);
int isExpired(int day, int month, int year, int expires);

int main()
{
    int currentDay = 1;
    int currentMonth = 11;
    int currentYear = 2025;

    int num = 95746904;

    int prodDay = extractDay(num);
    int prodMonth = extractMonth(num);
    int prodYear = extractYear(num);

    if (prodDay == -1)
    {
        puts("Invalid");
        return 0;
    }

    int days = dayOfYear(prodDay, prodMonth, prodYear);

    printf("num of days %d\n", days);

    return 0;
}

int extractYear(int num)
{
    int mask = 261632; // 00000000000000111111111000000000

    num = num & mask;
    num = num >> 9;

    if (num < 0)
    {
        return -1;
    }

    num += 1900;

    return num;
}

int extractMonth(int num)
{
    int mask = 480; // 00000000000000000000000111100000

    num = num & mask;
    num = num >> 5;

    if (num <= 0 || num > 12)
    {
        return -1;
    }

    return num;
}

int isCorrectDate(int day, int month, int year)
{
    int isLeap = year % 4 == 0 ||
                 year % 100 != 0 ||
                 year % 400 == 0;

    int lastDayInMonth;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        lastDayInMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        lastDayInMonth = 30;
    case 2:
        if (isLeap)
        {
            lastDayInMonth = 29;
        }
        else
        {
            lastDayInMonth = 28;
        }
        break;
    default:
        return 0;
    }

    if (day > 0 && day <= lastDayInMonth)
    {
        return 1;
    }

    return 0;
}

int extractDay(int num)
{
    int month = extractMonth(num);
    int year = extractYear(num);

    if (month == -1 || year == -1)
    {
        return -1;
    }

    int mask = 31; // 00000000000000000000000000011111

    num = num & mask;

    if (isCorrectDate(num, month, year) != 1)
    {
        return -1;
    }

    return num;
}

int extractExpDate(int num)
{
    int mask = 2147221504; // 01111111111111000000000000000000

    num = num & mask;
    num = num >> 18;

    return num;
}

int dayOfYear(int day, int month, int year)
{
    int days;
    int isLeap = year % 4 == 0 ||
                 year % 100 != 0 ||
                 year % 400 == 0;

    for (int i = 1; i <= month; ++i)
    {
        printf("%d\n", i);
        if (i == 1)
        {
            days = day;
        }
        else
        {
            switch (i - 1)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
            case 2:
                if (isLeap)
                {
                    days += 29;
                }
                else
                {
                    days += 28;
                }
                break;
            default:
                return -1;
                break;
            }
        }
    }

    return days;
}

int isExpired(int day, int month, int year, int expires)
{
    return 0;
}