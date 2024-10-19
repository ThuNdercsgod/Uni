#include <stdio.h>

int main()
{
    //Час в денонощието ще представяме с две числа - H и M, 
    //съответно часове и минути. По въведени две такива двойки 
    //(H1 и M1 и H2 и M2) да се намери изминалото време между 
    //H1:М1 и H2:M2 в минути
    
    int H1, M1;
    int H2, M2;
    int difference;
    
    printf("Enter the first values for hour and minutes:\n");
    scanf("%d %d", &H1, &M1);
    
    printf("Enter the second values for hour and minutes:\n");
    scanf("%d %d", &H2, &M2);
    
    (M1 <= 60) && (M2 <= 60) && (H1 <= 24) && (H2 <= 24) &&
    (
        M1 = M1 + (H1 * 60),
        M2 = M2 + (H2 * 60),
        
        difference = M2 - M1,
        
        printf("The time difference is %d minutes\n", difference)
    ) ||
    (
        printf("Invalid data!\n")
    );
    
    return 0;
}