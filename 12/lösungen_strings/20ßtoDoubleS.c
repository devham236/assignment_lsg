// ss in einem String mit ß ersetzen.
// const String ss = „ß“ war gegeben.
// Anmerkung in der Aufgabe: strlen(ß) = 2.

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *sharpStoDoubleS(char *inputString)
{
    if (inputString == NULL)
    {
        return "string empty";
    }
    char *firstPart = malloc(sizeof(char));
    char *secondPart = malloc(sizeof(char));
    int doubleExistent = 0;
    int j = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] == 's' && inputString[i + 1] == 's' && i + 1 < strlen(inputString))
        {
            i++;
            j++;
            strcat(firstPart, "ß");
        }
        else
        {
            firstPart[j] = inputString[i];
        }
        j++;
    }
    return firstPart;
}

int main()
{
    char *testString = "Strasse";
    printf("%s\n", sharpStoDoubleS(testString));
}