// "int count_target_string(char *text, char *string)", die zählt, wie oft "string"
// in "text" vorkommt. Es darf nur gezählt werden, wenn "string" von Leerzeichen
// umschlossen wird bzw. wenn es am Ende / am Anfang steht. Gehen Sie davon aus,
// dass nur Kleinbuchstaben und Leerzeichen vorkommen. Sie dürfen nur selbst
// programmierte Hilfsfunktionen und strlen() und strncmp() verwenden.

// Beispiele (Testfälle waren in der .c-Datei bereits programmiert):

// count_target_string("abc of", "of") -> 1
// count_target_string("abcof", "of")  -> 0
// count_target_string("ofabc", "of") -> 0
// count_target_string("of abc", "of")  -> 1
// count_target_string("abc of abc of", "of") -> 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countTargetString(char *text, char *string)
{
    char *splittedString;
    splittedString = strtok(text, " ");
    int result = 0;
    while (splittedString != NULL)
    {
        if (strcmp(string, splittedString) == 0)
        {
            result++;
        }
        splittedString = strtok(NULL, " ");
    }
    return result;
}

int main(int argc, char *argv[])
{
    int index = 0;
    char const *const fileName = argv[1];
    FILE *file = fopen(fileName, "r");
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        printf("%d\n", countTargetString(line, "of"));
        index++;
    }
    fclose(file);
    return 0;
}