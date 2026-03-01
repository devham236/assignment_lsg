// Es sind 2 Strings gegeben, wenn der eine in dem anderen vorkommt, soll der String nach dem anderen String ausgegeben werden,
//sonst der ursprüngliche String.Mit allokieren
#include <stdio.h>
#include <string.h>

char *printStrings(char *string, char *searchText)
{
    if (strstr(searchText, string) != NULL)
    {
        printf("%s --> %s\n", string, searchText);
    }
    else
    {
        printf("%s\n", string);
    }
}

int main()
{
    char *string = "Hello";
    char *searchText = "Ghello";
    printStrings(string, searchText);
}