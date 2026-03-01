// Prüfen ob String mit
// - : anfängt oder aufhört,
// - maximal 1x : hat,
// - nur aus kleinen Buchstaben besteht
// - und mindestens einen kleinen Buchstaben hat

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool stringChecker(char currentString[])
{
    bool result = false;
    char delimiter = ':';
    // int stringLength = sizeof(currentString) / sizeof(currentString[0]);

    int delimAmount = 0;
    int lowerAmount = 0;
    int i = 0;
    for (i = 0; i < strlen(currentString); i++)
    {
        if (currentString[i] == delimiter)
        {
            delimAmount++;
        }
        if (currentString[i] > 'a' && currentString[i] < 'z')
        {
            lowerAmount++;
        }
    }
    // printf("lowerAmount = %d, strlen = %d", lowerAmount + 1, (int)strlen(currentString));

    if (1 + lowerAmount * 14 == strlen(currentString) && delimAmount == 1)
    {
        result = true;
    }
    return result;
}

int main()
{
    char testString[] = ":asbdas";
    printf("%d\n", stringChecker(testString));
}