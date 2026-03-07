// String war gegeben.Sollte abwechselnd zu Upper und Lowercase gemacht werden mit bestimmter Anzahl
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char *countedLowerUpperCase(char *inputString, int amount)
{
    char *result = (char *)malloc(strlen(inputString));
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (i < amount)
        {
            if (i % 2 == 0)
            {
                result[i] = toupper(inputString[i]);
            }
            else
            {
                result[i] = tolower(inputString[i]);
            }
        }
        else
        {
            result[i] = inputString[i];
        }
    }
    return result;
}

int main()
{
    char *testString = "hello";
    int amount = 3;
    printf("%s\n", countedLowerUpperCase(testString, amount));
    return 0;
}