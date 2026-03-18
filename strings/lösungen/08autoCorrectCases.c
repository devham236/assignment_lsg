// ersten Buchstaben eines Wortes groß den Rest klein
//     Eingabe: HELLO WORLD
//     Ausgabe: Hello World

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *autocorrectCases(char inputString[])
{
    char *result = (char *)malloc(strlen(inputString + 1));
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (i == 0)
        {
            result[i] = inputString[i];
        }
        if (inputString[i] == ' ' && i + 1 < strlen(inputString))
        {
            result[i] = inputString[i];
            result[i + 1] = toupper(inputString[i + 1]);
        }
        if (i != 0 && inputString[i - 1] != ' ')
        {
            result[i] = tolower(inputString[i]);
        }
    }
    return result;
}

int main()
{
    char testString[] = "HELLO WOLRD";
    printf("%s\n", autocorrectCases(testString));
    return 0;
}