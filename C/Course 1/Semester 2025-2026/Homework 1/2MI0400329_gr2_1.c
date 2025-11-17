#include <stdio.h>
#include <math.h>
#define EPS 1e-12

int main()
{
    double xa, ya;
    puts("Enter the coordinates of point A(x, y) as follows: \"x y\"");
    if (scanf("%lf %lf", &xa, &ya) != 2)
    {
        puts("Invalid input!");
        return 1;
    }

    double xb, yb;
    puts("Enter the coordinates of point B(x, y) as follows: \"x y\"");
    if (scanf("%lf %lf", &xb, &yb) != 2)
    {
        puts("Invalid input!");
        return 1;
    }

    double xc, yc;
    puts("Enter the coordinates of point C(x, y) as follows: \"x y\"");
    if (scanf("%lf %lf", &xc, &yc) != 2)
    {
        puts("Invalid input!");
        return 1;
    }

    double xd, yd;
    puts("Enter the coordinates of point D(x, y) as follows: \"x y\"");
    if (scanf("%lf %lf", &xd, &yd) != 2)
    {
        puts("Invalid input!");
        return 1;
    }

    double ABsq = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double BCsq = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
    double CDsq = (xd - xc) * (xd - xc) + (yd - yc) * (yd - yc);
    double DAsq = (xa - xd) * (xa - xd) + (ya - yd) * (ya - yd);

    if (!(fabs(ABsq - BCsq) < EPS &&
          fabs(BCsq - CDsq) < EPS &&
          fabs(CDsq - DAsq) < EPS &&
          fabs(DAsq - ABsq) < EPS))
    {
        puts("The points do not form a square (sides are not equal)!");
        return 1;
    }

    double ABscalarBC = (xb - xa) * (xc - xb) + (yb - ya) * (yc - yb);
    double BCscalarCD = (xc - xb) * (xd - xc) + (yc - yb) * (yd - yc);
    double CDscalarDA = (xd - xc) * (xa - xd) + (yd - yc) * (ya - yd);
    double DAscalarAB = (xa - xd) * (xb - xa) + (ya - yd) * (yb - ya);

    if (!(ABscalarBC - 0 < EPS &&
          BCscalarCD - 0 < EPS &&
          CDscalarDA - 0 < EPS &&
          DAscalarAB - 0 < EPS))
    {
        puts("The points do not form a square (sides are not perpendicular)!");
        return 0;
    }

    puts("The points form a square.");
    printf("A(%lf, %lf) B(%lf, %lf) C(%lf, %lf) D(%lf, %lf)", xa, ya, xb, yb, xc, yc, xd, yd);

    double x, y;
    puts("Enter the coordinates of the point that will be used as follows: \"x y\"");
    if (scanf("%lf %lf", &x, &y) != 2)
    {
        puts("Invalid input!");
        return 0;
    }

    double xo, yo; // O(xo, yo) - център на окръжностите
    xo = (xa + xb + xc + xd) / 4;
    yo = (ya + yb + yc + yd) / 4;

    double rsq = ABsq / 4; // r - радиус на вписана окр.
    double Rsq = ABsq / 2; // R - радису на описана окр.
    // (2*R)^2 = AB^2 + AB^2 (2*R е диагонал)

    if ((x - xo) * (x - xo) + (y - yo) * (y - yo) >= rsq &&
        (x - xo) * (x - xo) + (y - yo) * (y - yo) <= Rsq)
    {
        // => във венеца
        if (x) // условие за в квадрат или не
        {
            puts("The point is between the circumscribed and the inclined circle of the square and part of the square");
        }
        puts("The point is between the circumscribed and the inclined circle of the square but not part of the square");
    }

    puts("The point is not between the circumscribed and inclined circle of the square.");

    return 0;
}