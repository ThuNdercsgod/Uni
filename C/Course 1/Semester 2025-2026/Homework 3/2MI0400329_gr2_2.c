#include <stdio.h>
#include <stdlib.h>

int **createImage(int height, int width);
void clearImage(int **image, int height);

int inputImage(int **image, int height, int width);
void printImage(int **image, int height, int width);

int needsCropLeft(int **image, int *height, int *width, int background);
int needsCropRight(int **image, int *height, int *width, int background);
int needsCropTop(int **image, int *height, int *width, int background);
int needsCropBottom(int **image, int *height, int *width, int background);

int cropLeft(int **image, int *height, int *width, int background);
int cropRight(int **image, int *height, int *width, int background);
int cropTop(int **image, int *height, int *width, int background);
int cropBottom(int **image, int *height, int *width, int background);
int cropImage(int **image, int *height, int *width, int background);

int main()
{
    int height, width;
    puts("Enter the height and width of the image (separated by a space):");
    if (scanf("%d %d", &height, &width) != 2 ||
        height <= 0 ||
        width <= 0)
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
        clearImage(image, height);
        return 1;
    }

    int background;
    puts("Enter the color of the background:");
    if (scanf("%d", &background) != 1)
    {
        puts("Invalid input!");
        clearImage(image, height);
        return 1;
    }

    if (cropImage(image, &height, &width, background) == -1)
    {
        clearImage(image, height);
        return 2;
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
        int *row = (int *)malloc(width * sizeof(int));
        if (!row)
        {
            clearImage(image, i);
            return NULL;
        }
        image[i] = row;
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

int needsCropLeft(int **image, int *height, int *width, int background)
{
    for (int i = 0; i < *height; ++i)
    {
        if (image[i][0] != background)
        {
            return 0;
        }
    }

    return 1;
}

int needsCropRight(int **image, int *height, int *width, int background)
{
    for (int i = 0; i < *height; ++i)
    {
        if (image[i][*width - 1] != background)
        {
            return 0;
        }
    }

    return 1;
}

int needsCropTop(int **image, int *height, int *width, int background)
{
    for (int i = 0; i < *width; ++i)
    {
        if (image[0][i] != background)
        {
            return 0;
        }
    }

    return 1;
}

int needsCropBottom(int **image, int *height, int *width, int background)
{
    for (int i = 0; i < *width; ++i)
    {
        if (image[*height - 1][i] != background)
        {
            return 0;
        }
    }

    return 1;
}

int cropLeft(int **image, int *height, int *width, int background)
{
    int oldWidth = *width;
    if (*width <= 0)
    {
        return 0;
    }

    while (*width > 0 && needsCropLeft(image, height, width, background))
    {
        for (int i = 0; i < *height; ++i)
        {
            for (int j = 0; j < *width - 1; ++j)
            {
                image[i][j] = image[i][j + 1];
            }
        }
        *width = *width - 1;
    }

    if (*width == 0)
    {
        return 0;
    }

    for (int i = 0; i < *height; ++i)
    {
        int *newRow = (int *)realloc(image[i], *width * sizeof(int));
        if (!newRow)
        {
            puts("Memory allocation error!");
            *width = oldWidth;
            return -1;
        }
        image[i] = newRow;
    }

    return 0;
}

int cropRight(int **image, int *height, int *width, int background)
{
    int oldWidth = *width;
    if (*width <= 0)
    {
        return 0;
    }

    while (*width > 0 && needsCropRight(image, height, width, background))
    {
        *width = *width - 1;
    }

    if (*width == 0)
    {
        return 0;
    }

    for (int i = 0; i < *height; ++i)
    {
        int *newRow = (int *)realloc(image[i], *width * sizeof(int));
        if (!newRow)
        {
            puts("Memory allocation error!");
            *width = oldWidth;
            return -1;
        }
        image[i] = newRow;
    }

    return 0;
}

int cropTop(int **image, int *height, int *width, int background)
{
    int oldHeight = *height;
    if (*height <= 0)
    {
        return 0;
    }

    while (*height > 0 && needsCropTop(image, height, width, background))
    {
        for (int i = 0; i < *height - 1; ++i)
        {
            for (int j = 0; j < *width; ++j)
            {
                image[i][j] = image[i + 1][j];
            }
        }
        *height = *height - 1;
    }

    if (*height == 0)
    {
        return 0;
    }

    int **newImage = (int **)realloc(image, (*height) * sizeof(int *));
    if (!newImage)
    {
        puts("Memory allocation error!");
        *height = oldHeight;
        return -1;
    }
    image = newImage;

    return 0;
}

int cropBottom(int **image, int *height, int *width, int background)
{
    int oldHeight = *height;
    if (*height <= 0)
    {
        return 0;
    }

    while (*height > 0 && needsCropBottom(image, height, width, background))
    {
        *height = *height - 1;
    }

    if (*height == 0)
    {
        return 0;
    }

    int **newImage = (int **)realloc(image, (*height) * sizeof(int *));
    if (!newImage)
    {
        puts("Memory allocation error!");
        *height = oldHeight;
        return -1;
    }
    image = newImage;

    return 0;
}

int cropImage(int **image, int *height, int *width, int background)
{
    // работим директно с image, защото смаляваме блока памет и
    // realloc ще го направи в същия блок, няма да го премести
    // ако я оголемявахме, тогава трябва да преместваме указателя към image,
    // но в случая няма нужда
    if (cropLeft(image, height, width, background) == -1 ||
        cropRight(image, height, width, background) == -1 ||
        cropTop(image, height, width, background) == -1 ||
        cropBottom(image, height, width, background) == -1)
    {
        return -1;
    }
}