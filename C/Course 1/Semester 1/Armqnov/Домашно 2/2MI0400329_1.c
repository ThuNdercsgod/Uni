#include <stdio.h>
#define CAPACITY 1024

void inputMemory(unsigned char memory[CAPACITY], int position);
void inputText(unsigned char text[CAPACITY], int position);
int commands(unsigned char memory[CAPACITY], int endMemory, unsigned char text[CAPACITY], int *pPositionText, int *pCurrentPosition, int size);
void interpretation(unsigned char memory[CAPACITY], unsigned char text[CAPACITY], int size);

int main()
{
    unsigned char memory[CAPACITY] = {0};
    unsigned char text[CAPACITY] = {0};
    interpretation(memory, text, CAPACITY);

    return 0;
}

void inputMemory(unsigned char memory[CAPACITY], int position)
{
    int valid = 0;
    while (valid != 1)
    {
        valid = 0;
        valid = scanf("%c", &memory[position]);
        putchar(memory[position]);
        if (memory[position] != '+' && memory[position] != '-' && memory[position] != '>' && memory[position] != '<' && memory[position] != '.' && memory[position] != ',' && memory[position] != '[' && memory[position] != ']' && memory[position] != 'x')
        {
            valid = 0;
        }
        if (valid != 1)
        {
            puts("Wrong input! Try again:s");
        }
    }
}

void inputText(unsigned char text[CAPACITY], int position)
{
    int valid = 0;
    do
    {
        valid = 0;
        valid = scanf("%c", &text[position]);
        if (valid != 1)
        {
            puts("Wrong input! Try again:");
        }
    } while (valid != 1);
}

int commands(unsigned char memory[CAPACITY], int endMemory, unsigned char text[CAPACITY], int *pPositionText, int *pCurrentPosition, int size)
{
    while (*pCurrentPosition != endMemory)
    {
        switch (memory[*pCurrentPosition])
        {
        case '+':
            text[*pPositionText] = text[*pPositionText] + 1;
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        case '-':
            text[*pPositionText] = text[*pPositionText] - 1;
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        case '>':
            *pPositionText = *pPositionText + 1;
            *pCurrentPosition = *pCurrentPosition + 1;
            return 1;
            break;
        case '<':
            *pPositionText = *pPositionText - 1;
            *pCurrentPosition = *pCurrentPosition + 1;
            return 1;
            break;
        case '.':
            putchar(text[*pPositionText]);
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        case ',':
            inputText(text, *pPositionText);
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        case '[':
            if (text[*pPositionText] == 0)
            {
                while (memory[*pCurrentPosition] != ']')
                {
                    *pCurrentPosition = *pCurrentPosition + 1;
                }
            }
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        case ']':
            if (text[*pPositionText] != 0)
            {
                while (memory[*pCurrentPosition] != '[')
                {
                    *pCurrentPosition = *pCurrentPosition - 1;
                }
            }
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        case 'x':
            *pCurrentPosition = *pCurrentPosition + 1;
            break;
        }
    }
    return 0;
}

void interpretation(unsigned char memory[CAPACITY], unsigned char text[CAPACITY], int size)
{
    int endMemory = 0;
    int currentPosition = 0;

    puts("Enter the symbols:");
    do
    {
        inputText(memory, endMemory);
        endMemory++;
    } while (memory[endMemory - 1] != 'x');
}