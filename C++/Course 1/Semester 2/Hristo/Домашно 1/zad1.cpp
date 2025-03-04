#include <iostream>
#include <cmath>

struct Triangle
{
    int xA, yA;
    int xB, yB;
    int xC, yC;
    double area;
};

Triangle *triangleArray(unsigned size);
unsigned inputUnsigned();
void inputCoordinates(Triangle &triangle);
// int absolute(int a);
void area(Triangle &triangle);
void sortTriangles(Triangle *array, unsigned size);
void printArray(Triangle *array, unsigned size);

int main()
{
    std::cout << "Enter the number of triangles:" << std::endl;
    unsigned N = inputUnsigned();

    Triangle *triangles = triangleArray(N);

    if (!triangles)
    {
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << "Enter the coordinates of triangle " << i + 1 << ":" << std::endl;
        inputCoordinates(triangles[i]);
        area(triangles[i]);
    }

    sortTriangles(triangles, N);

    printArray(triangles, N);

    delete[] triangles;

    return 0;
}

Triangle *triangleArray(unsigned size)
{
    Triangle *array = new (std::nothrow) Triangle[size];

    if (!array)
    {
        std::cout << "Memory allocation error!" << std::endl;

        return nullptr;
    }

    return array;
}

unsigned inputUnsigned()
{
    int number = 0;
    bool valid;

    do
    {
        valid = true;
        std::cin >> number;

        if (!(number >= 1 && number <= 1000))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);

    return (unsigned int)number;
}

void inputCoordinates(Triangle &triangle)
{
    bool valid;

    do
    {
        valid = true;
        std::cin >> triangle.xA >> triangle.yA >> triangle.xB >> triangle.yB >> triangle.xC >> triangle.yC;

        if (!((triangle.xA >= -100 && triangle.xA <= 100) && (triangle.yA >= -100 && triangle.yA <= 100) &&
              (triangle.xB >= -100 && triangle.xB <= 100) && (triangle.yB >= -100 && triangle.yB <= 100) &&
              (triangle.xC >= -100 && triangle.xC <= 100) && (triangle.yC >= -100 && triangle.yC <= 100)))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);
}

// int absolute(int a)
// {
//     if (a >= 0)
//     {
//         return a;
//     }
//     else
//     {
//         return -a;
//     }
// }

double length(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void area(Triangle &triangle)
{
    double lengthA = length(triangle.xB, triangle.yB, triangle.xC, triangle.yC);
    double lengthB = length(triangle.xA, triangle.yA, triangle.xC, triangle.yC);
    double lengthC = length(triangle.xA, triangle.yA, triangle.xB, triangle.yB);
    double semiPerimeter = (lengthA + lengthB + lengthC) / 2;

    triangle.area = sqrt(semiPerimeter * (semiPerimeter - lengthA) * (semiPerimeter - lengthB) * (semiPerimeter - lengthC));
}

void sortTriangles(Triangle *array, unsigned size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].area < array[i].area)
            {
                double temp = array[i].area;
                array[i].area = array[j].area;
                array[j].area = temp;
            }
        }
    }
}

void printArray(Triangle *array, unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Area of triangle " << i + 1 << ": " << array[i].area << std::endl;
    }
}