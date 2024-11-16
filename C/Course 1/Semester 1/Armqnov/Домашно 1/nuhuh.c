#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned int parent1, parent2;

    puts("Enter the chromosomes of the two parent individuals:");
    if (scanf("%u %u", &parent1, &parent2) != 2)
    {
        puts("Invalid input!");

        return 1;
    }
    else if (parent1 > 255 || parent2 > 255)
    {
        puts ("Invalid input!");

        return 1;
    }

    srand(time(NULL));
    unsigned int crossPoint = rand() % (8 + 1 - 1) + 1;
    crossPoint -= 1; //изваждам едно, за да мога да включа точката в разменянето

    printf("%u\n", crossPoint);

    unsigned int mask1ChangedPart = 0; //за частта от първия родител след точката
    unsigned int mask1UnchangedPart = 0; //за частта от първия родител преди точката

    unsigned int mask2ChangedPart = 0; //същото, но за втория родител
    unsigned int mask2UnchangedPart = 0;

    mask1ChangedPart = parent1 << crossPoint;
    mask1UnchangedPart = parent1 >> (8 - crossPoint);
    mask2ChangedPart = parent2 << crossPoint;
    mask2UnchangedPart = parent2 >> (8 - crossPoint);

    mask1ChangedPart = mask1ChangedPart;
    mask1UnchangedPart = mask1UnchangedPart;
    mask2ChangedPart = mask2ChangedPart;
    mask2UnchangedPart = mask2UnchangedPart;

    mask1ChangedPart = mask1ChangedPart >> crossPoint;
    mask1UnchangedPart = mask1UnchangedPart << (8 - crossPoint);
    mask2ChangedPart = mask2ChangedPart >> crossPoint;
    mask2UnchangedPart = mask2UnchangedPart << (8 - crossPoint);

    unsigned int child1 = mask1UnchangedPart ^ mask2ChangedPart;
    unsigned int child2 = mask2UnchangedPart ^ mask1ChangedPart;

    puts("The two new individuals after the crossing between the parents are:");
    printf("%u \n%u \n", child1, child2);

    return 0;
}