// Array mit bubbleSort sortieren

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void bubbleSort(int *array, int arraySize)
{
    while (arraySize--)
    {
        for (int i = 1; i <= arraySize; i++)
        {
            if (array[i] < array[i - 1])
            {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        }
    }
}

int main()
{
    int maxAmount = 8;
    int upperLimit = 50;
    int *testData = malloc(sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        int randomNumber = rand() % upperLimit;
        testData[i] = randomNumber;
        printf("%d, ", testData[i]);
    }
    bubbleSort(testData, maxAmount);
    printf("\n");
    for (int i = 0; i < maxAmount; i++)
    {
        printf("%d, ", testData[i]);
    }
    printf("\n");
    free(testData);
}
