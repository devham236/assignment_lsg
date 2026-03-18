// Implementieren Sie die Funktion in sequencePosition(String s, String t).
// Diese soll die Indexposition des ersten Auftretens von t in s zurückgeben(-1 falls t nicht in s vorkommt).
// Dabei sind '?' Jokerzeichen(wildcards).
// Ein ? in t bedeutet, dass das zugehörige Zeichen in s ein beliebiges(einzelnes) Zeichen sein darf.
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int sequencePosition(char searchString[], char stringToCompare[])
{
    char *result = NULL;
    if (strcmp(searchString, stringToCompare) == 0 && strcmp(searchString, " ") == 0 || strcmp(searchString, stringToCompare) == 0)
    {
        return 1;
    }
    else
    {
        char *toComparePointer = stringToCompare;
        while (*toComparePointer)
        {
            char *toComparePointerBegin = toComparePointer;
            char *searchPointer = searchString;
            while (*toComparePointer && *searchPointer && (*toComparePointer == *searchPointer || *searchPointer == '!'))
            {
                toComparePointer++;
                searchPointer++;
            }
            if (!*searchPointer)
            {
                result = toComparePointerBegin;
            }
            toComparePointer = toComparePointerBegin + 1;
        }
    }
    if (result != NULL)
    {
        return result - stringToCompare + 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char searchString[] = "123";
    char stringToCompare[] = "123";
    printf("%d\n", sequencePosition(searchString, stringToCompare));
    return 0;
}