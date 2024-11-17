#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int input1, input2;

    puts("Enter the chromosomes of the two parent individuals:");
    if (scanf("%d %d", &input1, &input2) != 2
        || input1 < 0 || input2 < 0)
    {
        puts("Invalid input!");

        return 1;
    }

    unsigned parent1 = input1;
    unsigned parent2 = input2;
    //за да може коректно да се провери дали входът е беззнаков

    srand(time(NULL)); //за да може rand() винаги да дава различни числа

    int upperLimit = 31;
    int lowerLimit = 1;

    unsigned crossoverPoint = rand() % (upperLimit - lowerLimit + 1) + lowerLimit; //случайна точка в интервала [1, 31]

    printf("The crossover point is %u\n", crossoverPoint);
 
    unsigned mask1 = ~0u; //маска за частта преди точката на кръстосване
    unsigned mask2 = ~0u; //маска за след точката
    //за да може маските да са само единици

    mask1 = mask1 <<= crossoverPoint;
    mask2 = ~mask1;

    unsigned newInd1 = (parent1 & mask1) | (parent2 & mask2);
    unsigned newInd2 = (parent1 & mask2) | (parent2 & mask1);

    puts("The two new individuals after the crossing between the parents are:");
    printf("%x\n%x\n", newInd1, newInd2);

    return 0;
}