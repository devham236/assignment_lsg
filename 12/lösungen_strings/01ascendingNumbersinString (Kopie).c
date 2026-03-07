// Schreiben Sie eine Funktion, die überprüft, ob in einem String 4 aufeinanderfolgende aufsteigende Zahlen auftreten.
// Beispielsweise "as53679e".

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxLength 4

bool isDigit(char inputChar)
{
    bool result = false;
    if (inputChar >= '0' && inputChar <= '9')
    {
        result = true;
    }
    return result;
}

bool checkString(char inputString[])
{
    bool result = false;
    int hitCounter = 1;
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (isDigit(inputString[i]))
        {
            if (i + 1 < strlen(inputString) && inputString[i] + 1 == inputString[i + 1])
            {
                hitCounter++;
            }
        }
    }
    if (hitCounter >= maxLength)
    {
        result = true;
    }
    printf("%d\n", hitCounter);
    return result;
}

int main()
{
    char test01[] = "_12_34_";
    printf("--> %d\n", checkString(test01));
    return 0;
}