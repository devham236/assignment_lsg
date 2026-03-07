#include "base.h"

// (1)
bool ascending_numbers_in_string(char *s)
{
    int count = 0;
    int len = s_length(s);

    if (len < 4)
    {
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]) && i > 0 && isdigit(s[i - 1]) && (s[i] >= s[i - 1] + 1))
        {
            count++;
        }
        else if (isdigit(s[i]))
        {
            count = 1;
        }
        else
        {
            count = 0;
        }

        if (count >= 4)
        {
            return true;
        }
    }

    return false;
}

// (4)

bool first_equals_last(char *s)
{
    return s[0] == s[s_length(s) - 1];
}

// (7)
char *remove_letters(char *s)
{
    int count = 0;

    if (s[0] == '\0')
    {
        return "";
    }

    for (int i = 0; i < s_length(s); i++)
    {
        if (isdigit(s[i]))
        {
            count++;
        }
    }

    char *new_string = xmalloc(count + 1);
    new_string[count] = '\0';

    for (int i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            new_string[j] = s[i];
            j++;
        }
    }

    return new_string;
}

// (8)
bool upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool lower(char c)
{
    return c >= 'a' && c <= 'z';
}

char *auto_correct_cases(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!upper(s[0]))
        {
            s[0] = toupper(s[0]);
        }

        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
        }

        if (i > 0 && s[i - 1] != ' ' && isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }

    return s;
}

// (9)
char *reverse_string(char *s)
{
    int left = 0;
    int right = s_length(s) - 1;

    while (left < right)
    {
        char curr_left = s[left];
        char curr_right = s[right];

        s[left] = curr_right;
        left++;

        s[right] = curr_left;
        right--;
    }

    return s;
}

// (10)
char *remove_char_from_string(char *s, char t)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != t)
        {
            count++;
        }
    }

    char *new_string = xmalloc(count + 1);
    new_string[count] = '\0';

    for (int i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != t)
        {
            new_string[j] = s[i];
            j++;
        }
    }

    printf("%s \n", new_string);

    return new_string;
}

void test()
{
    // (1)
    // test_equal_b(ascending_numbers_in_string("as5678e"), true);
    // test_equal_b(ascending_numbers_in_string("as58bb1234ett"), true);
    // test_equal_b(ascending_numbers_in_string("123"), false);
    // test_equal_b(ascending_numbers_in_string("2468"), true);
    // test_equal_b(ascending_numbers_in_string("6789"), true);
    // test_equal_b(ascending_numbers_in_string("abcd"), false);
    // test_equal_b(ascending_numbers_in_string("54321"), false);
    // test_equal_b(ascending_numbers_in_string("abc 123 de 4567"), true);
    // test_equal_b(ascending_numbers_in_string("abc 123 de 645"), false);

    // (4)
    // test_equal_b(first_equals_last("abba"), true);
    // test_equal_b(first_equals_last("1997"), false);
    // test_equal_b(first_equals_last("a        a"), true);
    // test_equal_b(first_equals_last("!caution!"), true);
    // test_equal_b(first_equals_last("x00abcdefg...00x"), true);

    // (7)
    // test_equal_s(remove_letters(""), "");

    // char *r2 = remove_letters("x");
    // test_equal_s(r2, "");
    // free(r2);

    // char *r3 = remove_letters("12hello24");
    // test_equal_s(r3, "1224");
    // free(r3);

    // char *r4 = remove_letters("aaaa200aaaa");
    // test_equal_s(r4, "200");
    // free(r4);

    // char *r5 = remove_letters("x      2      x");
    // test_equal_s(r5, "2");
    // free(r5);

    // (8)
    // char input1[] = "hELLO wORLD";
    // test_equal_s(auto_correct_cases(input1), "Hello World");

    // char input2[] = "HELLO WORLD";
    // test_equal_s(auto_correct_cases(input2), "Hello World");

    // char input3[] = "hERJEJWENF eEFJKJJFN";
    // test_equal_s(auto_correct_cases(input3), "Herjejwenf Eefjkjjfn");

    // char input4[] = "abc123 DEF456";
    // test_equal_s(auto_correct_cases(input4), "Abc123 Def456");

    // (9)
    // char input1[] = "Hello World";
    // test_equal_s(reverse_string(input1), "dlroW olleH");

    // char input2[] = "ab cd ef g";
    // test_equal_s(reverse_string(input2), "g fe dc ba");

    // char input3[] = "    ";
    // test_equal_s(reverse_string(input3), "    ");

    // char input4[] = "1234abc5678";
    // test_equal_s(reverse_string(input4), "8765cba4321");

    // (10)
    // char *s1 = "ReeeA";
    // char t1 = 'R';
    // test_equal_s(remove_char_from_string(s1, t1), "eeeA");

    // char *s2 = "Hello";
    // char t2 = 'l';
    // test_equal_s(remove_char_from_string(s2, t2), "Heo");

    // char *s3 = "F*ck you!";
    // char t3 = '*';
    // test_equal_s(remove_char_from_string(s3, t3), "Fck you!");

    // char *s4 = "12345xx6789";
    // char t4 = 'x';
    // test_equal_s(remove_char_from_string(s4, t4), "123456789");
}

int main(void)
{
    test();
    return 0;
}