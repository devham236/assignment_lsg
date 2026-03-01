// wie oft der gleiche Buchstabe im String vorkommt

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int *repeatingChar(char testString[])
{
    int resultArray[strlen(testString)];
    int *resultPointer = resultArray;
    int counter = 0;
    for (int i = 0; i < strlen(testString); i++)
    {
        char currentChar = testString[i];
        for (int j = 0; j < strlen(testString); j++)
        {
            if (currentChar == testString[j] && currentChar != '-')
            {
                // testString[i] = '-';
                counter++;
                resultArray[i] = counter;
            }
        }
        counter = 0;
    }
    return resultPointer;
}

int main()
{
    char testString[] = "1234";
    printf("%s\n", testString);
    int *result = repeatingChar(testString);
    for (int i = 0; i < strlen(testString); i++)
    {
        printf("%d,", result[i]);
    }
    printf("\n");
    return 0;
}