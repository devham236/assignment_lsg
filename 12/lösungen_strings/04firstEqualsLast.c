// Gibt true zurück, wenn das erste und letzte Zeichen im String gleich sind
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool firstEqualsLast(char inputString[])
{
    bool result = false;
    if (inputString[0] == inputString[strlen(inputString) - 1])
        result = true;
    return result;
}

int main()
{
    char testString[] = "anna";
    printf("%d\n", firstEqualsLast(testString));
    return 0;
}