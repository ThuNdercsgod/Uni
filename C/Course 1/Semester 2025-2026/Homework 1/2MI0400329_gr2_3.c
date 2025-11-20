#include <stdio.h>

int isValid(int num);
int isLeap(int year);
int extractYear(int num);
int extractMonth(int num);
int isCorrectDate(int day, int month, int year);
int extractDay(int num);
int extractExpDate(int num);
int dayOfYear(int day, int month, int year);
int isExpired(int day, int month, int year, int expires, int prodDay, int prodMonth, int prodYear);

int main()
{
    int currentDay = 1;
    int currentMonth = 11;
    int currentYear = 2025;

    int num;
    puts("Enter the number from the scanner:");
    if (scanf("%d", &num) != 1)
    {
        puts("Invalid");
        return 0;
    }

    if (!isValid(num))
    {
        puts("Invalid");
        return 0;
    }

    int prodDay = extractDay(num);
    int prodMonth = extractMonth(num);
    int prodYear = extractYear(num);
    int expDays = extractExpDate(num);

    if (prodDay == -1 || prodMonth == -1 || prodYear == -1)
    {
        puts("Invalid");
        return 0;
    }

    int exp = isExpired(currentDay, currentMonth, currentYear, expDays, prodDay, prodMonth, prodYear);
    if (!exp)
    {
        puts("Good");
    }
    else if (exp)
    {
        puts("Too old");
    }
    else
    {
        puts("Invalid");
    }

    return 0;
}

int isValid(int num)
{
    int mask = 1u;
    int count = 0;

    for (int i = 0; i < 31; ++i)
    {
        if (num & mask)
        {
            count++;
        }
        num = num >> 1;
    }

    if (count % 2 == 0 &&
        (num & mask) == 0)
    {
        return 1;
    }
    else if (count % 2 != 0 &&
             (num & mask) == 1)
    {
        return 1;
    }

    return 0;
}

int isLeap(int year)
{
    return (year % 4 == 0) &&
           (year % 100 != 0 ||
            year % 400 == 0);
}

// Might return -1 if invalid
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

// Might return -1 if invalid
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
    int leap = isLeap(year);

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
        if (leap)
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

// Might return -1 if invalid
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

// Might return -1 if invalid
int dayOfYear(int day, int month, int year)
{
    int days;
    int leap = isLeap(year);

    for (int i = 1; i <= month; ++i)
    {
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
                if (leap)
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

// Might return -1 if invalid
int isExpired(int day, int month, int year, int expires, int prodDay, int prodMonth, int prodYear)
{
    int prodDayOfYear = dayOfYear(prodDay, prodMonth, prodYear);
    int currentDayOfYear = dayOfYear(day, month, year);

    if (prodDayOfYear == -1 || currentDayOfYear == -1)
    {
        return -1;
    }

    if (year - prodYear == 0 && currentDayOfYear - prodDayOfYear >= 0)
    {
        return 0;
    }
    else if (year - prodYear == 0 && currentDayOfYear - prodDayOfYear < 0)
    {
        return 1;
    }
    else if (year - prodYear < 0)
    {
        return 1;
    }
    else if ((expires / 365) > (year - prodYear))
    {
        return 0;
    }
    else if ((expires / 365) < (year - prodYear))
    {
        return 1;
    }
    else if ((expires / 365) == (year - prodYear))
    {
        int yearsBetween = year - prodYear;

        for (int i = 1; i < yearsBetween; ++i)
        {
            expires = expires - (365 + isLeap(prodYear));
            ++prodYear;
        }

        expires = expires - (365 + isLeap(prodYear) - prodDayOfYear);

        if (expires >= currentDayOfYear)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return -1;
    }
}