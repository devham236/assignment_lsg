// Prüfen ob ein string t in einem string s vorkommt.
// string t kann zudem m '?' als wildchar(beliebiger character)erhalten
// Bei den Testfällen gab es zudem den Fall dass der String '' geprüft werden musste mit dem erwarteten Ergebnis true.
// '' ist die binäre Null, der String ist damit nicht leer... Dazu die Abfrage t[0] == '\0'
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool strstrWithWildcards(char searchString[], char stringToCompare[])
{
    bool result = false;
    if (strcmp(searchString, stringToCompare) == 0 && strcmp(searchString, " ") == 0 || strcmp(searchString, stringToCompare) == 0)
    {
        result = true;
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
                result = true;
            }
            toComparePointer = toComparePointerBegin + 1;
        }
    }
    return result;
}

int main()
{
    char searchString[] = "1";
    char stringToCompare[] = "123";
    printf("%d\n", strstrWithWildcards(searchString, stringToCompare));
    return 0;
}