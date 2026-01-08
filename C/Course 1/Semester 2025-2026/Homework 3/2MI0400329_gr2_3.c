#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 1024
#define WORDLENGTH 50

int stringcmp(char *first, char *second);

char **createTable(int words);
void clearTable(char **table, int words);
void printTable(char **table, int words);

int wordCount(char *sentence);
void addWordsToTable(char *sentence, char **table, int words);
int wordRepeats(char *word, char **table, int words);
int rearrangeTable(char **table, int *words);

void compress(char *sentence, char **table, int words, char *compressed);
char *decompress(char *sentence, char **table, int words, char *decompressed);

int main()
{
    char sentence[CAP];
    puts("Enter the sentence:");
    fgets(sentence, CAP, stdin);
    if (sentence[strlen(sentence) - 1] == '\n')
    {
        sentence[strlen(sentence) - 1] = '\0';
    }
    strlwr(sentence);

    int words = wordCount(sentence);

    char **table = createTable(words);
    if (!table)
    {
        puts("Memory allocation error!");
        return 2;
    }

    addWordsToTable(sentence, table, words);
    if (rearrangeTable(table, &words) == -1)
    {
        puts("Memory allocation error!");
        clearTable(table, words);
        return 2;
    }

    char compressed[CAP];
    compress(sentence, table, words, compressed);
    puts(compressed);

    char decompressed[CAP];
    decompress(compressed, table, words, decompressed);
    puts(decompressed);

    clearTable(table, words);

    return 0;
}

int stringcmp(char *first, char *second)
{
    int lengthFirst = strlen(first);
    int lengthSecond = strlen(second);

    if (lengthFirst != lengthSecond)
    {
        return lengthFirst - lengthSecond;
    }

    for (int i = 0; i < lengthFirst; ++i)
    {
        if (first[i] != second[i])
        {
            return 1;
        }
    }

    return 0;
}

char **createTable(int words)
{
    char **table = (char **)malloc(words * sizeof(char *));
    if (!table)
    {
        return NULL;
    }

    for (int i = 0; i < words; ++i)
    {
        char *word = (char *)malloc(WORDLENGTH * sizeof(char));
        if (!word)
        {
            clearTable(table, i);
            return NULL;
        }
        table[i] = word;
    }

    return table;
}

void clearTable(char **table, int words)
{
    for (int i = 0; i < words; ++i)
    {
        free(table[i]);
        table[i] = NULL;
    }
    free(table);
    table = NULL;
}

void printTable(char **table, int words)
{
    for (int i = 0; i < words; ++i)
    {
        puts(table[i]);
    }
}

int wordCount(char *sentence)
{
    int pos = 0;
    int words = 0;
    while (sentence[pos] != '\0')
    {
        if (!((sentence[pos] >= 'a' && sentence[pos] <= 'z') ||
              (sentence[pos] >= '0' && sentence[pos] <= '9') ||
              sentence[pos] == '-'))
        {
            words++;
            pos++;
        }
        else if (sentence[pos + 1] == '\0')
        {
            words++;
        }
        pos++;
    }

    return words;
}

void addWordsToTable(char *sentence, char **table, int words)
{
    int pos = 0;
    char word[WORDLENGTH];
    int wordPos = 0;
    int tablePos = 0;

    while (sentence[pos] != '\0')
    {
        if ((sentence[pos] >= 'a' && sentence[pos] <= 'z') ||
            (sentence[pos] >= '0' && sentence[pos] <= '9') ||
            sentence[pos] == '-')
        {
            word[wordPos] = sentence[pos];
            wordPos++;
        }
        else
        {
            if (wordPos > 0)
            {
                word[wordPos] = '\0';
                strcpy(table[tablePos], word);
                tablePos++;
                wordPos = 0;
            }
        }
        pos++;
    }

    if (wordPos > 0)
    {
        word[wordPos] = '\0';
        strcpy(table[tablePos], word);
    }
}

int wordRepeats(char *word, char **table, int words)
{
    int count = 0;
    for (int i = 0; i < words; ++i)
    {
        if (stringcmp(word, table[i]) == 0)
        {
            count++;
        }
    }

    return count;
}

int removeRepeats(char *word, char **table, int *words)
{
    int hasAppeared = 0;
    for (int i = 0; i < *words; ++i)
    {
        if (stringcmp(word, table[i]) == 0 &&
            hasAppeared == 1)
        {
            free(table[i]);
            table[i] = NULL;
            for (int j = i; j < (*words - 1); ++j)
            {
                table[j] = table[j + 1];
            }
            table[*words - 1] = NULL;
            *words = *words - 1;

            char **newTable = (char **)realloc(table, (*words) * sizeof(char *));
            if (!newTable)
            {
                return -1;
            }
            table = newTable;
            i--;
        }
        else if (stringcmp(word, table[i]) == 0 &&
                 hasAppeared == 0)
        {
            hasAppeared = 1;
        }
    }
    return 0;
}

int rearrangeTable(char **table, int *words)
{
    for (int i = 0; i < *words; ++i)
    {
        if (wordRepeats(table[i], table, *words) > 1)
        {
            if (removeRepeats(table[i], table, words) == -1)
            {
                return -1;
            }
            i--; // Adjust index after removal
        }
    }
    return 0;
}

void compress(char *sentence, char **table, int words, char *compressed)
// наредбата им е както е редът в изречението, не успях да го направя да се подреждат
// по честота
{
    if (words < 10)
    {
        int pos = 0;
        char word[WORDLENGTH];
        int wordPos = 0;

        while (sentence[pos] != '\0')
        {
            if ((sentence[pos] >= 'a' && sentence[pos] <= 'z') ||
                (sentence[pos] >= '0' && sentence[pos] <= '9') ||
                sentence[pos] == '-')
            {
                word[wordPos] = sentence[pos];
                wordPos++;
            }
            else
            {
                if (wordPos > 0)
                {
                    word[wordPos] = '\0';

                    for (int i = 0; i < words; ++i)
                    {
                        if (stringcmp(word, table[i]) == 0)
                        {
                            switch (i)
                            {
                            case 0:
                                strcat(compressed, "0");
                                break;
                            case 1:
                                strcat(compressed, "1");
                                break;
                            case 2:
                                strcat(compressed, "2");
                                break;
                            case 3:
                                strcat(compressed, "3");
                                break;
                            case 4:
                                strcat(compressed, "4");
                                break;
                            case 5:
                                strcat(compressed, "5");
                                break;
                            case 6:
                                strcat(compressed, "6");
                                break;
                            case 7:
                                strcat(compressed, "7");
                                break;
                            case 8:
                                strcat(compressed, "8");
                                break;
                            case 9:
                                strcat(compressed, "9");
                                break;
                            }
                            strcat(compressed, " ");
                        }
                    }

                    wordPos = 0;
                }
            }
            pos++;
        }

        if (wordPos > 0)
        {
            word[wordPos] = '\0';

            for (int i = 0; i < words; ++i)
            {
                if (stringcmp(word, table[i]) == 0)
                {
                    switch (i)
                    {
                    case 0:
                        strcat(compressed, "0");
                        break;
                    case 1:
                        strcat(compressed, "1");
                        break;
                    case 2:
                        strcat(compressed, "2");
                        break;
                    case 3:
                        strcat(compressed, "3");
                        break;
                    case 4:
                        strcat(compressed, "4");
                        break;
                    case 5:
                        strcat(compressed, "5");
                        break;
                    case 6:
                        strcat(compressed, "6");
                        break;
                    case 7:
                        strcat(compressed, "7");
                        break;
                    case 8:
                        strcat(compressed, "8");
                        break;
                    case 9:
                        strcat(compressed, "9");
                        break;
                    }
                    strcat(compressed, " ");
                }
            }
        }
    }
}

char *decompress(char *compressed, char **table, int words, char *decompressed)
{
    if (words < 10)
    {
        int pos = 0;
        char word[WORDLENGTH];
        int wordPos = 0;

        while (compressed[pos] != '\0')
        {

            switch (compressed[pos])
            {
            case '0':
                strcat(decompressed, table[0]);
                break;
            case '1':
                strcat(decompressed, table[1]);
                break;
            case '2':
                strcat(decompressed, table[2]);
                break;
            case '3':
                strcat(decompressed, table[3]);
                break;
            case '4':
                strcat(decompressed, table[4]);
                break;
            case '5':
                strcat(decompressed, table[5]);
                break;
            case '6':
                strcat(decompressed, table[6]);
                break;
            case '7':
                strcat(decompressed, table[7]);
                break;
            case '8':
                strcat(decompressed, table[8]);
                break;
            case '9':
                strcat(decompressed, table[9]);
                break;
            }
            strcat(decompressed, " ");
            pos++;
        }
    }
}