#include <stdio.h>
#include <math.h>

#define CAPACITY 10
#define BIGCAPACITY 20
#define EPS 1E-9

void transform(double arr[], unsigned  size);
int checkNext(double arr[], unsigned size);
void removeNext(double arr[], unsigned size);
int isSet(double arr[], unsigned size);
void toSet(double arr[], unsigned size);
void unionOfArrays(double arr1[], double arr2[], double arrUnion[], unsigned size);
// с union ми дава грешка, затова сложих друго име
void intersection(double arr1[], double arr2[], double arrIntersection[], unsigned size);
void sortArray(double arr[], unsigned size);
void printArray(double arr[], unsigned size);

int main()
{
    double tran[CAPACITY] = { 4, 3, -5, 2.3, -1.2, 0 };

    puts("The array is:");
    printArray(tran, CAPACITY);
    puts("");

    transform(tran, CAPACITY);

    puts("The transformed array is:");
    printArray(tran, CAPACITY);
    puts("");

    double check[CAPACITY] = { 4, 4, 1, 2, 3, 3, 3, 0 };

    puts("The array is:");
    printArray(check, CAPACITY);
    puts("");

    (checkNext(check, CAPACITY) == 1)? puts("There are repeating elements next to eachother") : 
    puts("There are no repeating elements next to eachother");
    puts("");
 
    removeNext(check, CAPACITY);

    puts("When removing the same elements next to eachother, the array is:");
    printArray(check, CAPACITY);
    puts("");

    double set[CAPACITY] = { 0, 1, 2, 1, 3, 4, 1, 0, 0, 2, 0 };

    puts("The array is:");
    printArray(set, CAPACITY);
    puts("");

    if (isSet(set, CAPACITY) == 0)
    {
        puts("The array is not a set");
        puts("");

        toSet(set, CAPACITY);
        sortArray(set, CAPACITY);

        puts("When remade into a set, the array is:");
        printArray(set, CAPACITY);
        puts("");
    }
    else
    {
        puts("The array is a set\n");
    }

    double arrUnion[BIGCAPACITY] = { 0 };

    unionOfArrays(check, set, arrUnion, BIGCAPACITY);

    puts("The Union of the arrays");
    printArray(check, CAPACITY);
    puts("and");
    printArray(set, CAPACITY);
    puts("is:");
    
    printArray(arrUnion, BIGCAPACITY);
    puts("");

    double arrIntersection[BIGCAPACITY] = { 0 };

    intersection(check, set, arrIntersection, BIGCAPACITY);

    puts("The intersection of the arrays");
    printArray(check, CAPACITY);
    puts("and");
    printArray(set, CAPACITY);
    puts("is:");
    
    printArray(arrIntersection, BIGCAPACITY);
    puts("");

    return 0;
}

void transform(double arr[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        if (fabs(arr[i]) < EPS)
        {
            arr[i] = 1;
        }
        else if (arr[i] < 0)
        {
            arr[i] = arr[i] * arr[i];  
        }
        else if (arr[i] > 0)
        {
            arr[i] = arr[i] / 2;
        }
    }
}

int checkNext(double arr[], unsigned size)
{
    for (int i = 1; i < (size); ++i)
    {
        if(fabs(arr[i] - arr[i - 1]) < EPS)
        {
            return 1;
        }
    }

    return 0;
}

void removeNext(double arr[], unsigned size)
{
    for (int i = 1; i < (size); ++i)
    {
        if(fabs(arr[i] - arr[i - 1]) < EPS)
        {
            arr[i - 1] = 0;
        }
    }
    sortArray(arr, size);
}

int isSet(double arr[], unsigned size)
{
    for (int i = 0; i < (size - 1); ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            if(fabs(arr[i] - arr[j]) < EPS && i != j)
            {
                return 0;
            }
        }
    }
    return 1;
}

void toSet(double arr[], unsigned size)
{
    for (int i = 0; i < (size - 1); ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            if (fabs(arr[i] - arr[j]) < EPS && i != j)
            {
                arr[j] = 0;
            }
        }
    }
    sortArray(arr, size);
}

void unionOfArrays(double arr1[], double arr2[], double arrUnion[], unsigned size)
{
    int size1 = 0, size2 = 0;

    while (!(fabs(arr1[size1]) < EPS))
    {
        size1++;
    }
    while (!(fabs(arr2[size2]) < EPS))
    {
        size2++;
    }

    for (int i = 0; i <= size1; ++i)
    {
        arrUnion[i] = arr1[i];
    }

    for (int i = size1; i <= size1 + size2; ++i)
    {
        arrUnion[i] = arr2[i - size1];
    }

    toSet(arrUnion, size);
}

void intersection(double arr1[], double arr2[], double arrIntersection[], unsigned size)
{
    int size1 = 0, size2 = 0;

    while (!(fabs(arr1[size1]) < EPS))
    {
        size1++;
    }
    while (!(fabs(arr2[size2]) < EPS))
    {
        size2++;
    }

    for (int i = 0; i <= size1; ++i)
    {
        for (int j = 0; j <= size2; ++j)
        {
            if (fabs(arr1[i] - arr2[j]) < EPS)
            {
                arrIntersection[i] = arr1[i];
            }
        }
    }
    sortArray(arrIntersection, size);
}

void sortArray(double arr[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = 0;
        while (!(fabs(arr[j]) < EPS))
        {
            j++;
        }

        if (!(fabs(arr[i]) < EPS))
        arr[j] = arr[i];
        arr[i] = 0;
    }
}

void printArray(double arr[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("arr[%d] = %lf ", i, arr[i]);
    }
    puts("");
}