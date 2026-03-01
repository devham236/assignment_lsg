// 2 Strings gegeben.
// Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *stringDiff(char *string1, char *string2)
{
    char *result = (char *)malloc(strlen(string1) + strlen(string2));
    int stringLength = 0;

    if (strcmp(string1, string2) == 0)
    {
        return "strings identical";
    }
    else
    {
        int j = 0;
        for (int i = 0; i < strlen(string1); i++)
        {
            if (!strchr(string2, string1[i]))
            {
                result[j] = string1[i];
                j++;
            }
        }
    }
    return result;
}

int main()
{
    char *string1 = "HeTestllo";
    char *string2 = "Test";
    printf("%s\n", stringDiff(string1, string2));
    return 0;
}