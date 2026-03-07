// Für _buchstabe neuen String allokieren und "_" entfernen und den ersten Buchstaben nach "\_" groß Schreiben.
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
char *removeSlash(char *inputString)
{
    char *result = (char *)malloc(strlen(inputString));
    int j = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] != '_')
        {
            result[j] = inputString[i];
            j++;
        }
    }
    result[0] = toupper(result[0]);
    return result;
}

int main()
{
    char *testString = "_hallo";
    printf("%s\n", removeSlash(testString));
}