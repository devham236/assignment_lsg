// Leerzeichen am Anfang/Ende eines Strings entfernen. Es darf nur s_length/xmalloc/strlen verwendet

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *trimString(char *inputString)
{
    char *result = (char *)malloc(strlen(inputString));
    int j = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] != ' ')
        {
            result[j] = inputString[i];
            j++;
        }
    }
    return result;
}

int main()
{
    char *testString = " Hallo ";
    printf("%s\n", trimString(testString));
}