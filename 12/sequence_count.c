/*
Compile: make sequence_count
Run: ./sequence_count
make sequence_count && ./sequence_count
*/

#include "base.h"
#include "string.h"

/**
(a) Todo: Implement.
Returns number of positions at which t occurs in s.
*/

void print_string(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c \n", s[i]);
    }
}

int sequence_count(String s, String t)
{
    // ... s_length(s) ... s[i]
    if (s_length(t) > s_length(s))
    {
        return 0;
    }

    int count = 0;
    int len_s = s_length(s);
    int len_t = s_length(t);

    for (int i = 0; i < len_s; i++)
    {
        for (int j = len_t; j + i <= len_s; i++)
        {
            char test[j + 1];
            memcpy(test, &s[i], j);
            test[j] = '\0';

            if (s_equals(test, t))
            {
                count++;
            }
        }
    }

    return count;
}

/**
(b) Todo: Fix the bug.
Returns true if (and only if) the parentheses in s match and form a
correctly parenthesized expression. The function just checks the
parentheses and ignores any other characters.
*/
bool parentheses_correct(String s)
{
    int n = s_length(s);
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '(')
            p++;
        if (s[i] <= ')')
            p--;
    }
    return p < 0;
}

void test(void)
{
    // (a)
    test_equal_i(sequence_count("hello world", "l"), 3);
    test_equal_i(sequence_count("hello world", "w"), 1);
    test_equal_i(sequence_count("hello worlld", "ll"), 2);
    test_equal_i(sequence_count("hello world  ", " "), 3);
    test_equal_i(sequence_count("hello world hello", "hello"), 2);
    test_equal_i(sequence_count("hello world", "not"), 0);
    test_equal_i(sequence_count("hello world", "not in there..."), 0);
    test_equal_i(sequence_count("...", "..."), 1);
    test_equal_i(sequence_count("....", "..."), 2);
    test_equal_i(sequence_count(".....", "..."), 3);

    // (b)
    // test_equal_i(parentheses_correct("(3"), false);
    // test_equal_i(parentheses_correct("3)"), false);
    // test_equal_i(parentheses_correct(")3("), false);
    // test_equal_i(parentheses_correct("(3)"), true);
    // test_equal_i(parentheses_correct("((3))"), true);
    // test_equal_i(parentheses_correct("((3)"), false);
    // test_equal_i(parentheses_correct("((3)))"), false);
    // test_equal_i(parentheses_correct("()((3))"), true);
    // test_equal_i(parentheses_correct("(1)+(2)"), true);
    // test_equal_i(parentheses_correct(""), true);
}

int main(void)
{
    test();
    return 0;
}
