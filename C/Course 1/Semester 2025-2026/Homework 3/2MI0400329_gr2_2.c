#include <stdio.h>
#include <stdlib.h>

int **createImage(int height, int width);
void clearImage(int **image, int height);

int inputImage(int **image, int height, int width);
void printImage(int **image, int height, int width);

void cropImage(int **image, int height, int width, int background);

int main()
{
    int height, width;
    puts("Enter the height and width of the image (separated by a space):");
    if (scanf("%d %d", &height, &width) != 2)
    {
        puts("Invalid input!");
        return 1;
    }

    int **image = createImage(height, width);
    if (!image)
    {
        puts("Memory allocation error!");
        return 2;
    }

    if (inputImage(image, height, width) == -1)
    {
        puts("Invalid input!");
        return 1;
    }

    int background;
    puts("Enter the color of the background:");
    if (scanf("%d", &background) != 1)
    {
        puts("Invalid input!");
        return 1;
    }

    printImage(image, height, width);

    clearImage(image, height);

    return 0;
}

int **createImage(int height, int width)
{
    int **image = (int **)malloc(height * sizeof(int *));
    if (!image)
    {
        return NULL;
    }

    for (int i = 0; i < height; ++i)
    {
        image[i] = (int *)malloc(width * sizeof(int));
        if (!image[i])
        {
            clearImage(image, i);
            return NULL;
        }
    }

    return image;
}

void clearImage(int **image, int height)
{
    for (int i = 0; i < height; ++i)
    {
        free(image[i]);
        image[i] = NULL;
    }

    free(image);
    image = NULL;
}

int inputImage(int **image, int height, int width)
{
    puts("Enter the color of each pixel (width, separated by space, height by enter):");

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (scanf("%d", &image[i][j]) != 1)
            {
                return -1;
            }
        }
    }

    return 0;
}

void printImage(int **image, int height, int width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

void cropImage(int **image, int height, int width, int background)
{
}