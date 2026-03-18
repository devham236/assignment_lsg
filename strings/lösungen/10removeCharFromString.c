// Chars aus einem String entfernen
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *removeChar(char *inputString, char charToRemove)
{
    char *result = (char *)malloc(strlen(inputString) + 1);
    int j = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] == charToRemove)
        {
            i++;
        }
        result[j] = inputString[i];
        j++;
    }
    result[strlen(inputString)] = '\0';
    return result;
}

int main()
{
    char *testString = "ReeeA";
    char toRemove = 'R';
    printf("%s\n", removeChar(testString, toRemove));
}