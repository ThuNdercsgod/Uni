#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 1024

void inputString(char string[], int size);
void clearArray(char *array);
void clear2DArray(char **array, int rows);
void clear2DArrayInt(int **array, int rows);
char *word(char *string, int start, int end, int largestWord);
void analyzeWords(char *string, int *numberOfWords, int *largestWord, int size);
void isolateWords(char *string, char **words, int size, int largestWord);
int **repeatsOfWord(char **words, int *numberOfWords);
int **compress(char *string, int *numWords, int size);
void clearRepeating(char **words, int **wordRepeats, int *numberOfWords);
void decompress(int **words, int **string, int **wordRepeats, int *numberOfWords);

int main()
{
    char string[CAPACITY];
    inputString(string, CAPACITY);
    strlwr(string);

    int numberOfWords = 0;
    int **wordsCompressed = compress(string, &numberOfWords, CAPACITY);
    if (wordsCompressed == NULL)
    {
        puts("No memory allocated!");

        return 1;
    }

    clear2DArrayInt(wordsCompressed, numberOfWords);

    return 0;
}

void inputString(char string[], int size)
{
    puts("Enter the sentence:");

    int valid = 0;
    do
    {
        valid = 0;
        valid = scanf("%s", string);

        if (strlen(string) > size)
        {
            valid = 0;
        }
        if (valid == 0)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid == 0);
}

void clearArray(char *array)
{
    free(array);
}

void clear2DArray(char **array, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(array[i]);
    }
    free(array);
}

void clear2DArrayInt(int **array, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(array[i]);
    }
    free(array);
}

char **createArray(int rows, int collumns)
{
    char **array = (char **)malloc(rows * sizeof(int *));

    if (!array)
    {
        clear2DArray(array, 1);

        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        char *row = (char *)malloc(collumns * sizeof(int));

        array[i] = row;

        if (!row)
        {
            clear2DArray(array, i);

            return NULL;
        }
    }

    return array;
}

char *word(char *string, int start, int end, int largestWord)
{
    char *word = (char *)malloc((end - start + 2) * sizeof(char));

    if (!word)
    {
        clearArray(word);
        return NULL;
    }

    int k = 0;

    for (int i = start; i <= end; ++i)
    {

        word[k] = string[i];

        k++;
    }

    if ((end - start + 1) < largestWord)
    {
        for (int i = end - start + 1; i < largestWord; ++i)
        {
            word[i] = '\0';
        }
    }

    return word;
}

void analyzeWords(char *string, int *numberOfWords, int *largestWord, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (!(string[i] >= 'A' && string[i] <= 'Z') &&
            !(string[i] >= 'a' && string[i] <= 'z') &&
            !(string[i] >= '0' && string[i] <= '9') &&
            !(string[i] == '-'))
        {
            *numberOfWords += 1;
        }
    }

    int currentWordLength = 0;

    int start = 0;
    for (int i = 0; i < size; ++i)
    {

        if (!(string[i] >= 'A' && string[i] <= 'Z') &&
            !(string[i] >= 'a' && string[i] <= 'z') &&
            !(string[i] >= '0' && string[i] <= '9') &&
            !(string[i] == '-'))
        {
            currentWordLength = i - start;

            if (currentWordLength > *largestWord)
            {
                *largestWord = currentWordLength;
            }

            start = i + 1;
        }
    }
}

void isolateWords(char *string, char **words, int size, int largestWord)
{
    int freePosition = 0;
    int start = 0;
    for (int i = 0; i < size; ++i)
    {

        if (!(string[i] >= 'A' && string[i] <= 'Z') &&
            !(string[i] >= 'a' && string[i] <= 'z') &&
            !(string[i] >= '0' && string[i] <= '9') &&
            !(string[i] == '-'))
        {
            words[freePosition] = word(string, start, i - 1, largestWord);
            start = i + 1;
            freePosition++;
        }
    }
}

int **repeatsOfWord(char **words, int *numberOfWords)
{
    int **wordRepeats = (int **)malloc(*numberOfWords * (sizeof(int *)));

    if (!wordRepeats)
    {
        return NULL;
    }

    for (int i = 0; i < *numberOfWords; ++i)
    {
        wordRepeats[i] = (int *)malloc(sizeof(int));

        if (!wordRepeats[i])
        {
            clear2DArrayInt(wordRepeats, i);

            return NULL;
        }
        wordRepeats[i] = (int *)1;
    }

    for (int i = 0; i < (*numberOfWords - 1); ++i)
    {
        for (int j = i + 1; j < *numberOfWords; ++j)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                wordRepeats[i] += 1;
            }
        }
    }

    return wordRepeats;
}

int **compress(char *string, int *numWords, int size)
{
    int numberOfWords = 0;
    int largestWord = 0;
    analyzeWords(string, &numberOfWords, &largestWord, size);

    char **words = createArray(numberOfWords, largestWord);

    isolateWords(string, words, size, largestWord);

    int **wordRepeats = repeatsOfWord(words, &numberOfWords);

    if (wordRepeats == NULL)
    {
        return NULL;
    }

    *numWords = numberOfWords;
}

void clearRepeating(char **words, int **wordRepeats, int *numberOfWords)
{
    for (int i = 0; i < (*numberOfWords - 1); ++i)
    {
        for (int j = i + 1; j < *numberOfWords; ++j)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                for (int k = i; k < *numberOfWords; ++k)
                {
                    words[k] = words[k + 1];
                }
                (*numberOfWords) -= 1;
                wordRepeats[i] += 1;
                j--;
            }
        }
    }
}

void decompress(int **words, int **string, int **wordRepeats, int *numberOfWords)
{
    clearRepeating(words, wordRepeats, numberOfWords);
}