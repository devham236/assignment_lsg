// a.) 2D-Matrix mit Buchstaben und - gegeben, Anzahl der gegebenen chars pro Spalte in 1D-Array speichern
// Eingabe 2D Array, a
// a - a a --> 3 <br>
// b - - - --> 0 --> [3,0] Rückgabe Array

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 2

int *countCharInArray(char inputArray[ROWS][COLS], char searchChar)
{
    int resultArray[ROWS] = {};
    int *resultPointer = resultArray;
    int colResult = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (inputArray[i][j] == searchChar)
            {
                colResult++;
                resultArray[i] = colResult;
            }
            printf("%c ", inputArray[i][j]);
        }
        colResult = 0;
        printf("\n");
    }
    printf("\n");

    return resultPointer;
}

int main()
{
    char testArray[ROWS][COLS] = {{'a', 'a'},
                                  {'a', '-'},
                                  {'-', 'b'}};
    int *result = countCharInArray(testArray, 'a');
    for (int i = 0; i < ROWS; i++)
    {
        if (i == ROWS - 1)
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