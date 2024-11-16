#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    unsigned int parent1, parent2, crossover_point;

    puts("Enter the chromosomes of the two parent individuals:");
    if (scanf("%u %u", &parent1, &parent2) != 2
        || parent1 > 255 || parent2 > 255) //проверка дали входа е 8-битов
    {
        puts("Invalid input!");
        return 1;
    }

    srand(time(NULL));

    crossover_point = rand() % 8 + 1; //случайна точка в интервала [1, 8] - за да може да не излиза от 8-те бита

    crossover_point += 1; //добавям едно, за да може да включи точката в кръстосването

    unsigned int mask = (1 << crossover_point) - 1; //маска за частта преди точката на кръстосване
    unsigned int mask_inv = ~mask; //маска за след точката

    unsigned int newInd1 = (parent2 & mask) | (parent1 & mask_inv);
    unsigned int newInd2 = (parent1 & mask) | (parent2 & mask_inv);

    printf("The two new individuals after the crossing between the parents are:\n");
    printf("0x%x\n0x%x\n", newInd1, newInd2);

    return 0;
}