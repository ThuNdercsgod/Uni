#include <stdio.h>
#include <math.h>

int main()
{
    //По въведени цяло число N и цяло число без знак K намерете и изведете на екрана K-тата цифра на N
    
    int N;
    unsigned int K;
    
    printf("Enter a whole number:\n");
    scanf("%d", &N);
    
    printf("Enter which digit of %d to show:\n", N);
    scanf("%u", &K);
    
    int kDig = (N / (int)pow(10, K - 1 )) % 10;

    //Имах проблем, че ми показва К-тата цигра отдясно наляво, затова прегледах в интернет,
    //и ми даде това като решение:
    //
    // int numDig = (int)log10(N) + 1;
    // int kDig = (N / (int)pow(10, numDig - K)) % 10;

    printf("The %u digit of %d is %d\n", K, N, kDig);
    
    return 0;
}