// Aus einem String die Länge der kürzesten Folge des Char c finden.
// Dazu noch Funktion schreiben die herausfindet ob der String mit einer Ziffer beginnt.

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool startWithNumber(char *currentString)
{
    bool result = false;
    int stringLength = 0;

    for (int i = 0; i < strlen(currentString); i++)
    {
        if (currentString[i] >= 'a' && currentString[i] <= 'z')
        {
            stringLength++;
        }
    }

    for (int i = 0; i < stringLength; i++)
    {
    }

    if (currentString[0] >= '0' && currentString[0] <= '9')
    {
        result = true;
    }
    return result;
}

int shortestOrder(char *currentString)
{
    int result = 0;
    int stringLength = 0;
    for (int i = 0; i < strlen(currentString); i++)
    {
        if (currentString[i] >= 'a' && currentString[i] <= 'z')
        {
            stringLength++;
        }
    }
    // printf("stringlength = %d\n", stringLength);
    for (int i = 0; i < stringLength; i++)
    {
        char currentChar = currentString[i];
        result = 0;
        for (int j = 0; j < stringLength; j++)
        {
            if (currentChar == currentString[j])
            {
                result++;
            }
            printf("%d.comperison: currentChar = %c, compared to = %c, amount = %d\n", j, currentChar, currentString[j], result);
        }
        printf("\n");
    }
    return result;
}

int main()
{
    char testString[] = "1asbdas";
    // printf("%d\n", shortestOrder(testString));
    printf("%d\n", startWithNumber(testString));
}