#include <stdio.h>

int main()
{
    int num;

    puts("Enter a non-negative integer:");
    if (scanf("%d", &num) != 1
        || (num < 0 || num > 9999))
    {
        puts("Invalid input");

        return 1;
    }

    int firstDig, secondDig, thirdDig, fourthDig;
    int bigDig, smallDig;

    //най-голямата разлика между произволни цифри на числото е разликата
    //между най-голямата цифра и най-малката цифра на числото

    if (num < 10) //едноцифрено число
    {
        puts("The number is single digit, so");
        puts("The largest difference between 2 digits of the number is:");
        printf("%d\n", num);

        return 0;
    }
    else if (num < 100) //двуцифрено число
    {
        firstDig = num / 10;
        secondDig = num % 10;

        bigDig = (firstDig > secondDig)? firstDig : secondDig;

        smallDig = (firstDig < secondDig)? firstDig : secondDig;
    }
    else if (num < 1000) //трицифрено число
    {
        firstDig = num / 100;
        secondDig = (num / 10) % 10;
        thirdDig = num % 10;

        bigDig = (firstDig > secondDig)? firstDig : secondDig;
        bigDig = (bigDig > thirdDig)? bigDig : thirdDig;

        smallDig = (firstDig < secondDig)? firstDig : secondDig;
        smallDig = (smallDig < thirdDig)? smallDig : thirdDig;
    }
    else //четирицифрено число
    {
        firstDig = num / 1000;
        secondDig = (num / 100) % 10;
        thirdDig = (num / 10) % 10;
        fourthDig = num % 10;

        bigDig = (firstDig > secondDig)? firstDig : secondDig;
        bigDig = (bigDig > thirdDig)? bigDig : thirdDig;
        bigDig = (bigDig > fourthDig)? bigDig : fourthDig;
        
        smallDig = (firstDig < secondDig)? firstDig : secondDig;
        smallDig = (smallDig < thirdDig)? smallDig : thirdDig;
        smallDig = (smallDig < fourthDig)? smallDig : fourthDig;
    }

    int diff = bigDig - smallDig;

    puts("The largest difference between 2 digits of the number is:");
    printf("%d\n", diff);

    return 0;
}