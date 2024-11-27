#include <stdio.h>
#include <math.h>

#define CAPACITY 10
#define BIGCAPACITY 20
#define EPS 1E-9

void transform(double arr[], unsigned  size);
void checkNext(double arr[], unsigned size);
double removeNext(double arr[], unsigned size);
void isSet(double arr[], unsigned size);
double toSet(double arr[], unsigned size);
double unionOfArrays(double arr1[], double arr2[], double arrUnion[], unsigned size);
//с union ми дава грешка, затова сложих друго име
double sortArray(double arr[], unsigned size);
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

    puts("Checking if there are the the same elements next to eachother");
    puts("...");
    checkNext(check, CAPACITY);
    puts("\nare the elements that exist more than once.");
    puts("");
    
    removeNext(check, CAPACITY);

    puts("When removing the same elements next to eachother, the array is:");
    printArray(check, CAPACITY);
    puts("");

    double set[CAPACITY] = { 0, 1, 2, 1, 3, 4, 1, 0, 2, 0 };

    puts("The array is:");
    printArray(set, CAPACITY);
    puts("");

    isSet(set, CAPACITY);
    puts("");

    toSet(set, CAPACITY);
    sortArray(set, CAPACITY);

    puts("When remade into a set, the array is:");
    printArray(set, CAPACITY);
    puts("");

    //double arrUnion[BIGCAPACITY] = { 0 };
    //unionOfArrays(check, set, arrUnion, BIGCAPACITY);

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

void checkNext(double arr[], unsigned size)
{
    for (int i = 0; i < (size); ++i)
    {
        if(fabs(arr[i] - arr[i - 1]) < EPS)
        {
            printf("arr[%d] = arr[%d] = %lf ", i - 1, i, arr[i]);
        }
    }
}

double removeNext(double arr[], unsigned size)
{
    for (int i = 0; i < (size); ++i)
    {
        if(fabs(arr[i] - arr[i - 1]) < EPS)
        {
            arr[i - 1] = 0;
        }
    }
}

void isSet(double arr[], unsigned size)
{
    for (int i = 0; i < (size - 1); ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            if(fabs(arr[i] - arr[j]) < EPS && i != j)
            {
                puts("The array is not a set");

                return;
            }
        }
    }
}

double toSet(double arr[], unsigned size)
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
}
//todo finish it after the sorting algorithm
double unionOfArrays(double arr1[], double arr2[], double arrUnion[], unsigned size)
{
    
}

//TODO fix it, cuz something wrong
double sortArray(double arr[], unsigned size)
{
    for (int i = 1; i < size; ++i)
    {
        if (fabs(arr[i - 1]) < EPS)
        {
            arr[i - 1] = arr[i];
            arr[i] = 0;
        }
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