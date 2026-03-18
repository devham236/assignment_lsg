/*
 * Vervollständigen Sie die Funktion rowMult, die als Eingabeargumente einen Zeiger auf ein Integer-Array, 
 * die Anzahl der Zeilen und die Anzahl der Spalten annimmt und das Produkt der Einträge in jeder einzelnen Zeile berechnet.
 * (Tipp: Der Eingabeparameter ist ein Zeiger auf ein Array und nicht das Array direkt => Eine manuelle Zeiger-Dereferenzierung ist erforderlich)
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


//TODO:
int* rowMult(int* a, int row, int col)
{
    int* result = (int*)malloc(row * sizeof(int));

    if (result == NULL)
    {
        return NULL; 
    }

    for (int i = 0; i < row; i++)
    {
        int product = 1;

        for (int j = 0; j < col; j++)
        {
            product *= *(a + i * col + j); 
            
        }

        *(result + i) = product;
    }

    return result;
}

int main()
{
    int row = 3;
    int col = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {5, 1, 7},
        {9, 0, 0}
    };

    int* result = rowMult((int*)matrix, row, col);

    if (result != NULL)
    {
        for (int i = 0; i < row; i++)
        {
            printf("Row %d product: %d\n", i + 1, *(result + i));
        }
        free(result); // free the allocated memory!
    }

    return 0;
}

