// Verschlüsselung von Buchstaben in einem String (Caesar Alg).
// Alle Kleinbuchstaben(!) sollten um 5 chars verschoben werden
// Nur s_length/xmalloc/strlen
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *encode(char *toEncode, int shift)
{
    char *result = (char *)malloc(strlen(toEncode));
    int j = 0;
    for (int i = 0; i < strlen(toEncode); i++)
    {
        if (toEncode[i] >= 'a' && toEncode[i] <= 'z')
        {
            result[j] = (toEncode[i] + shift - 'a') % 26 + 'a';
        }
        else
        {
            result[j] = toEncode[i];
        }
        j++;
    }
    return result;
}

char *decode(char *toDecode, int shift)
{
    char *result = (char *)malloc(strlen(toDecode));
    int j = 0;
    for (int i = 0; i < strlen(toDecode); i++)
    {
        if (toDecode[i] >= 'a' && toDecode[i] <= 'z')
        {
            result[j] = (toDecode[i] + shift - 'a') % 26 + 'a';
        }
        else
        {
            result[j] = toDecode[i];
        }
        j++;
    }
    return result;
}

int main()
{
    char *testString = "Hello";
    int encodeShift = 5;
    printf("%s\n", encode(testString, encodeShift));
    printf("%s\n", decode(encode(testString, encodeShift), -encodeShift));
}