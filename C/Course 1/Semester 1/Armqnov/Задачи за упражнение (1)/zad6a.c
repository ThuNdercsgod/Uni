#include <stdio.h>
#include <math.h>

int main()
{
    //Въведете евклидови координати на три 
    //точки - върхове на триъгълник. За тях 
    //изведете периметъра и лицето на този 
    //триъгълник. Какво имаме да валидираме тук?

    int xa, ya;
    int xb, yb;
    int xc, yc;
    
    printf("Enter the coordinates of the point A:\n");
    scanf("%d %d", &xa, &ya);
    
    printf("Enter the coordinates of the point B:\n");
    scanf("%d %d", &xb, &yb);
    
    printf("Enter the coordinates of the point C:\n");
    scanf("%d %d", &xc, &yc);
    
    double AB, BC, AC;
    double P;
    double p;
    double S;
    double SPow2;
    
    double ABPow2 = ((xb - xa) * (xb - xa)) + ((yb - ya) * (yb - ya));
    double BCPow2 = ((xc - xb) * (xc - xb)) + ((yc - yb) * (yc - yb));
    double ACPow2 = ((xc - xa) * (xc - xa)) + ((yc - ya) * (yc - ya));

    (ABPow2 >= 0) && (BCPow2 >= 0) && (ACPow2 >= 0) &&
    (
        AB = sqrt(ABPow2),
        BC = sqrt(BCPow2),
        AC = sqrt(ACPow2),
        
        (AB > 0) && (BC > 0) && (AC > 0) && (AB + BC > AC) && (BC + AC > AB) && (AB + AC > BC) &&
        (
            P = AB + BC + AC,
            p = P / 2,

            SPow2 = (p - AB) * (p - BC) * (p - AC),

            (SPow2 >= 0) &&
            (
                S = sqrt(SPow2),
                
                printf("The perimeter is %lf\n", P),
                printf("The area is %lf\n", S)
            ) ||
            (
                printf("Invalid data!\n")
            )
        ) ||
        (
            printf("Invalid data!\n")
        )
    ) ||
    (
        printf("Invalid data!\n")
    );

    return 0;
}