// strings mit xmalloc kopieren über string laufen und alle lowercases in string direkt übergeben, leerzeichen auch,
// uppercases je nach position übergeben oder zu "\_x" transformieren.
// die zusätzliche größenveränderung beim allocieren natürlich vorher beachten.
// Originalstring nicht verändern.
// Rückgabestring dynmanisch allokieren.
//   - nur wenn Uppercase \_ untermische und und die innere Buchstabe zu lowercase
//   - Hilfsfunktionen
//      - is_letter()....
//      - is_upper()....
//      - is_lower()....
//      - to_upper()...
//      - to_lower()...
//   - Beispiele
//     - abcd --> abcd
//     - Abcd --> Abcd
//     - ABCD --> A_b_c_d
//     - ABCDEF --> A_b_c_d_e_f
//     - ABCD EF --> A_b_c_d E_f

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isLetter(char inputChar)
{
    bool result = false;
    if (inputChar >= 'a' && inputChar <= 'z' || inputChar >= 'A' && inputChar <= 'Z')
    {
        result = true;
    }
    return result;
}

char *camelCase(char inputString[])
{
    char *result = (char *)malloc((strlen(inputString)) * sizeof(char));
    bool entireStringUpperCase = true;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (islower(inputString[i]))
        {
            entireStringUpperCase = false;
        }
    }

    int j = 0;
    for (int i = 0; i < strlen(inputString); i++)
    {
        printf("%d\n", j);
        if (entireStringUpperCase)
        {
            if (i == 0)
            {
                result[i] = inputString[i];
            }
            if (i != 0)
            {
                result[j] = '_';
                j++;
                result[j] = tolower(inputString[i]);
            }
        }
        else
        {
            result[i] = inputString[i];
        }
        j++;
    }
    return result;
}

int main()
{
    char testString1[] = "ABCEDTL";
    printf("%s\n", camelCase(testString1));
    return 0;
}