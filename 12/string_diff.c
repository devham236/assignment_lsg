// 2 Strings gegeben.
// Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

bool compare(char *s, char c)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }

    return false;
}

char *stringDiff(char *s1, char *s2)
{
    int count = 0;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (!compare(s2, s1[i]))
        {
            count++;
        }
    }

    char *result = xmalloc(count + 1);
    result[count] = '\0';

    for (int i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if (!compare(s2, s1[i]))
        {
            result[j] = s1[i];
            j++;
        }
    }

    return result;
}

int main()
{
    char *s1 = "HeTestllo";
    char *s2 = "Test";
    test_equal_s(stringDiff(s1, s2), "Hllo");

    char *s3 = "abc";
    char *s4 = "abcde";
    test_equal_s(stringDiff(s3, s4), "");

    char *s5 = "User_123";
    char *s6 = "123";
    test_equal_s(stringDiff(s5, s6), "User_");

    return 0;
}