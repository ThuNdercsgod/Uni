#include <stdio.h>
#include <stdlib.h>

int inputNumber();
void printArray(int size, int *array);
int findDigits(int number, int numberOfDigits);
int *createArray(int size);
void digitsOfNumber(int number, int numberOfDigits, int *digits);
int powerOfNum(int num, int power);
int sum(int numberOfDigits, int *digits);

int main()
{
    puts("Enter a number:");
    unsigned number = inputNumber();

    int numberOfDigits = findDigits(number, 0);

    int *digits = createArray(numberOfDigits);

    if (!digits)
    {
        puts("No memory allocated!");
        free(digits);
    }

    digitsOfNumber(number, numberOfDigits, digits);

    if (number == sum(numberOfDigits, digits))
    {
        puts("The number is a \"Number of the Fallen Angel\"!");
    }
    else
    {
        puts("The number is not a \"Number of the Fallen Angel\"!");
    }

    free(digits);

    return 0;
}

int inputNumber()
{
    int number = 0;
    int valid = 0;

    do
    {
        valid = scanf("%d", &number);

        if (number < 0)
        {
            valid = 0;
        }

        if (valid != 1)
        {
            puts("Wrong input! Try again:");

            valid = 0;
        }
    } while (valid == 0);

    return number;
}

void printArray(int size, int *array)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", array[i]);
    }
}

int findDigits(int number, int numberOfDigits)
{
    if (number == 0)
    {
        return numberOfDigits;
    }

    numberOfDigits++;
    findDigits((number / 10), numberOfDigits);
}

int *createArray(int size)
{
    int *array = (int *)malloc((size) * sizeof(int));

    if (!array)
    {
        return NULL;
    }
}

void digitsOfNumber(int number, int numberOfDigits, int *digits)
{
    digits[numberOfDigits - 1] = number % 10;
    number /= 10;

    for (int i = numberOfDigits - 2; i >= 0; --i)
    {
        digits[i] = number % 10;
        number /= 10;
    }
}

int powerOfNum(int num, int power)
{
    if (power == 1)
    {
        return num;
    }

    return num * powerOfNum(num, power - 1);
}

int sum(int numberOfDigits, int *digits)
{
    int sum = 0;

    for (int i = 0; i < numberOfDigits; ++i)
    {
        sum = sum + powerOfNum(digits[i], i + 1);
    }

    return sum;
}
