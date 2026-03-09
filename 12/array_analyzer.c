// a.) 2D-Matrix mit Buchstaben und - gegeben, Anzahl der gegebenen chars pro Spalte in 1D-Array speichern
// Eingabe 2D Array, a
// a - a a --> 3 <br>
// b - - - --> 0 --> [3,0] Rückgabe Array

#include <stdio.h>
#include <stdlib.h>
#include "base.h"

#define ROWS 3
#define COLS 2

int *countCharInArray(char inputArray[ROWS][COLS], char searchChar)
{
    int *result = xmalloc(COLS * sizeof(int));

    for (int i = 0; i < COLS; i++)
    {
        int count = 0;

        for (int j = 0; j < ROWS; j++)
        {
            if (inputArray[i][j] == searchChar)
            {
                count++;
            }
        }

        result[i] = count;
    }

    return result;
}

int main()
{
    char testArray[ROWS][COLS] = {{'a', 'a'},
                                  {'a', '-'},
                                  {'-', 'b'}};
    int *result = countCharInArray(testArray, 'a');
    for (int i = 0; i < COLS; i++)
    {
        if (i == COLS - 1)
        {
            printf("%d", result[i]);
        }
        else
        {
            printf("%d, ", result[i]);
        }
    }
    printf("\n");
}