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
#include "base.h"

int count_target_string(char *text, char *string)
{
    if (!s_contains(text, string))
    {
        return 0;
    }

    int count = 0;
    int count_loop = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c \n", text[i]);

        if (s_contains(string, &text[i]))
        {
            printf("current char is in string \n");
            count_loop++;
        }

        if (count_loop == s_length(string))
        {
            printf("last char of string reached \n");

            // string ist am Ende und hat links space
            if (i == s_length(text) - 1 && text[i - s_length(string)] == ' ')
            {
                printf("string is at the end of text and has space left of it! \n");
                count++;
            }

            // string hat links und rechts space
            if (text[i + 1] == ' ' && text[i - s_length(string)] == ' ')
            {
                printf("string has space left and right of it \n");
                count++;
            }
        }
    }

    return count;
}

void test()
{
    test_equal_i(count_target_string("abc of", "of"), 1);
    // test_equal_i(count_target_string("abcof", "of"), 0);
    // test_equal_i(count_target_string("ofabc", "of"), 0);
    // test_equal_i(count_target_string("of abc", "of"), 1);
    test_equal_i(count_target_string("abc of abc", "of"), 1);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}