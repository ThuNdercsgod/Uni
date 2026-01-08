#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 1024

char **createTable(int rows, int cols);
void clearTable(char **table, int rows);
void printTable(char **table, int rows, int cols);

void putWord(char **table, const char *word, int row, int cols, int isENG);
void inputTable(char **table, int rows, int cols);

int addSpaces(const char *sentence, char *translated, int posSent);
int wordTranslate(char **table, int rows, int cols, const char *sentence, char *translated, int posSent);
char *translate(char **table, int rows, int cols, const char *sentence);

int main()
{
    int rows;
    int cols = 32; // заради 2-те терминиращи нули

    puts("Enter the number of words in the dictionary:");
    if (scanf("%d", &rows) != 1 ||
        rows <= 0)
    {
        puts("Invalid input!");
        return 1;
    }
    getchar();

    char **table = createTable(rows, cols);
    if (!table)
    {
        puts("Memory allocation error!");
        return 2;
    }

    inputTable(table, rows, cols);

    char sentence[CAP];
    puts("Enter the sentence for translation:");
    fgets(sentence, CAP, stdin);
    if (sentence[strlen(sentence) - 1] == '\n')
    {
        sentence[strlen(sentence) - 1] = '\0';
    }
    strlwr(sentence);

    char *translated = translate(table, rows, cols, sentence);
    if (!translated)
    {
        clearTable(table, rows);
        return 2;
    }

    puts(translated);

    // printTable(table, rows, cols);

    clearTable(table, rows);
    free(translated);

    return 0;
}

char **createTable(int rows, int cols)
{
    char **table = (char **)malloc(rows * sizeof(char *));
    if (!table)
    {
        return NULL;
    }

    for (int i = 0; i < rows; ++i)
    {
        char *row = (char *)malloc(cols * sizeof(char));
        if (!row)
        {
            clearTable(table, i);
            return NULL;
        }
        table[i] = row;
    }

    return table;
}

void clearTable(char **table, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(table[i]);
        table[i] = NULL;
    }

    free(table);
    table = NULL;
}

void printTable(char **table, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int count = 0;

        while (table[i][count] != '\0') // винаги ще стигне до \0
        {                               // заради fgets() в inputTable()
            printf("%c", table[i][count]);
            count++;
        }
        printf(" - ");

        count = cols / 2;
        while (table[i][count] != '\0')
        {
            printf("%c", table[i][count]);
            count++;
        }
        printf("\n");
    }
}

void putWord(char **table, const char *word, int row, int cols, int isENG)
{
    if (isENG)
    {
        for (int i = 0; i < cols / 2; ++i)
        {
            table[row][cols / 2 + i] = word[i];
        }
    }
    else
    {
        for (int i = 0; i < cols / 2; ++i)
        {
            table[row][i] = word[i];
        }
    }
}

void inputTable(char **table, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        char tempBG[16];
        printf("Enter word %d in Bulgarian:\n", i + 1);
        fgets(tempBG, 16, stdin);
        if (tempBG[strlen(tempBG) - 1] == '\n')
        {
            tempBG[strlen(tempBG) - 1] = '\0';
        }
        putWord(table, tempBG, i, cols, 0);

        char tempENG[16];
        printf("Enter word %d in English:\n", i + 1);
        fgets(tempENG, 16, stdin);
        if (tempENG[strlen(tempENG) - 1] == '\n')
        {
            tempENG[strlen(tempENG) - 1] = '\0';
        }
        putWord(table, tempENG, i, cols, 1);
    }
}

int addSpaces(const char *sentence, char *translated, int posSent)
{
    int posTransl = strlen(translated);

    while (sentence[posSent] == ' ' ||
           sentence[posSent] == ',' ||
           sentence[posSent] == '.' ||
           sentence[posSent] == '\n')
    {
        if (posTransl >= CAP)
        {
            puts("Sentence too long to translate!");
            return -1;
        }

        translated[posTransl] = sentence[posSent];

        posTransl++;
        posSent++;

        translated[posTransl] = '\0';
    }

    return posSent;
}

int wordTranslate(char **table, int rows, int cols, const char *sentence, char *translated, int posSent)
{
    char wordBG[cols / 2];
    int posWord = 0;

    while (sentence[posSent] != ' ' &&
           sentence[posSent] != ',' &&
           sentence[posSent] != '.' &&
           sentence[posSent] != '\n' &&
           sentence[posSent] != '\0')
    {
        if (posSent >= CAP)
        {
            puts("Sentence too long to translate!");
            return -1;
        }

        wordBG[posWord] = sentence[posSent];
        posSent++;
        posWord++;
    }
    wordBG[posWord] = '\0';

    int rowOfTable = 0;
    while (strcmp(wordBG, table[rowOfTable]) != 0)
    {
        if (rowOfTable >= rows)
        {
            strcat(translated, wordBG);
            return posSent;
        }
        rowOfTable++;
    }

    char wordENG[cols / 2];
    for (int i = 0; i < cols / 2; ++i)
    {
        wordENG[i] = table[rowOfTable][i + 16];
        if (table[rowOfTable][i + 16] == '\0')
        {
            break;
        }
    }

    strcat(translated, wordENG);

    return posSent;
}

char *translate(char **table, int rows, int cols, const char *sentence)
{
    int posSent = 0;
    char translated[CAP];
    translated[0] = '\0';

    while (sentence[posSent] != '\0')
    {
        posSent = wordTranslate(table, rows, cols, sentence, translated, posSent);
        if (posSent == -1)
        {
            return NULL;
        }

        posSent = addSpaces(sentence, translated, posSent);
        if (posSent == -1)
        {
            return NULL;
        }
    }

    char *transl = (char *)malloc((strlen(translated) + 1) * sizeof(char));
    if (!transl)
    {
        puts("Memory allocation error!");
        return NULL;
    }
    transl[0] = '\0';

    strcat(transl, translated);

    return transl;
}