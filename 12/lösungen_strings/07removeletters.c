// nur mit hilfsfunktionen strings in exakt größen allokierten copy string übertragen, alles was letters sind ignorieren.
// Zahlen aus String rausschreiben
// Originalstring nicht verändern
// Rückgabestring dynmanisch allokieren
// nur Hilfsfunktionen verwenden und xmalloc
//     - is_letter
//     - s_length
// Beispiele
//     " " --> " "
//     "abc " --> " "
//     "1abc" --> "1"
//     "x11" --> "11"
//     "1a2b3c4d" --> "1234"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char *removeLetters(char inputString[])
{
    int numberCounter = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] >= '0' && inputString[i] <= '9')
        {
            numberCounter++;
        }
    }
    char *result = (char *)malloc(numberCounter + 1);
    int j = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (inputString[i] >= '0' && inputString[i] <= '9')
        {
            result[j] = inputString[i];
            j++;
        }
    }
    return result;
}
int main()
{
    char testString[] = "1a2b3c4d";
    printf("%s\n", removeLetters(testString));
    return 0;
}