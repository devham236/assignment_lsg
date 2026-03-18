// - Strings in einer Liste reversen

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *reverseString(char inputString[])
{
    char *result = (char *)malloc(strlen(inputString) + 1);
    int j = 0;
    for (int i = strlen(inputString) - 1; i >= 0; i--)
    {
        result[j] = inputString[i];
        j++;
    }
    result[strlen(inputString)] = '\0';
    return result;
}

int main()
{
    char testString[] = "Hello";
    printf("%s\n", reverseString(testString));
    return 0;
}