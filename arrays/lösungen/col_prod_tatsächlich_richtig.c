#include "base.h"

// Eingabe 2D Array, a
// a - a a --> 3 <br>
// b - - - --> 0 --> [3,0] Rückgabe Array

#define ROWS 3
#define COLS 2

int* countCharInArray (char inputarray[ROWS][COLS], char inputChar){
    int result[ROWS] = {}; 
    int* resultpointer = result; 
    int count = 0; 

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if(inputarray[i][j] == inputChar){
                count++; 
                
            }
        }
        result[i] = count; 
        count = 0; 
    }

    return resultpointer; 
}


int main(){
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
    
    return 0; 
}