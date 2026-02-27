/*
Compile: make palindrome
Run: ./palindrome
make palindrome && ./palindrome
*/

#include "base.h"

String alphabet = "abcdefghijklmnopqrstuvwxyz";
/**
(a) Todo: Implement.
Return whether a character is in the alphabet
*/
bool is_in_alphabet(char c)
{
    int lower_case_char = tolower(c);

    // TODO implement
    for (int i = 0; i < strlen(alphabet); i++)
    {
        /* code */
        if (lower_case_char == alphabet[i])
            return true;
    }

    return false;
}

/**
(b) Todo: Implement.
Return whether a String is a palindrome
*/
bool is_palindrome(char *s)
{
    // TODO implement
    int str_length = strlen(s);

    if (str_length == 0)
    {
        return false;
    }

    int left = 0;
    int right = str_length - 1;

    while (left < right)
    {

        if (!is_in_alphabet(s[left]))
        {
            left++;
            continue;
        }

        if (!is_in_alphabet(s[right]))
        {
            right--;
            continue;
        }
        /*
        Wenn s[left] oder s[right] nicht im Alphabet ist wird um einen erhöht/verringert und man springt durch "continue" an den Anfang der while Schleife.

        Zum Beispiel bei "shower." ist left = 0 (s[left] = s) und right = 6 (s[right] = .). Beim ersten Durchlauf ist s[left] im Alphabet, s[right] aber nicht, also wird right um einen verringert und man springt an den Anfang der while Schleife, s[left] ist immernoch gleich s, s[right] ist jetzt aber r
        */
        if (s[left] != s[right])
        {
            return false;
        }

        else
        {
            left++;
            right--;
        }
    }

    return true;
}

/**
(c) Todo: Implement.
Return whether a String contains at least one palindrome of minimum size minimum_palindrome_size
*/
bool contains_palindrome(char *s, int minimum_palindrome_size)
{
    // TODO implement
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = minimum_palindrome_size; j + i <= strlen(s); j++)
        {
            char test[j + 1];       // Der Teilstring muss minimum_palindrome_size haben und die terminierende null '\0', deswegen plus 1
            memcpy(test, s + i, j); // memcpy kümmert sich nicht um das 0-Byte, deswegen musst man es manuell einfügen.
            test[j] = '\0';

            if (is_palindrome(test))
            {
                return true;
            }
        }
    }
    return false;

    /*
    Der äußere for loop bestimmt bei welchem index des strings geschaut werden soll ob ein Palindrome mit der minimum_palindrome_size vorliegt.
    Der innere loop kopiert die ersten j Zeichen, vom aktuellen Index, aus dem String und überprüft ob ein Palindrome vorliegt.

    Zum Beispiel: "test_equal_b(contains_palindrome("madam anna is a nurse", 3), true);"
    Der String hat mindestens ein Palindrom mit 3 oder mehr character.
    Äußere Schleife ist bei i = 0, also bei char 'm'. Innere Schleife kopiert jetzt die character 0-3, also "mad", in das array und schaut mit der if Abfrage ob das ein Palindrome ist.
    "mad" ist kein Palindrome, also erhöht sich j um 1. Jetzt kopiert der innere loop, "mada" in das test array und schaut ob das ein Palindrome.
    "mada" ist auch kein Palindrome, also erhöht sich j wieder um 1. Jetzt kopiert der innere loop "madam" in das test array und schaut ob ein Palindrome vorliegt.
    "madam" ist ein Palindrome, die if Abfrage gibt ein true wieder und die beiden loops werden beendet. Den Rest des Strings muss man nicht mehr beachten, weil ja ein Palindrome mit Größe 3 schon gefunden wurde.

    Die äußere Schleife wird erst um 1 erhöht, bzw. geht erst ein Index weiter im String, wenn die innere Schleife die Abbruchbedingung erreicht, also wenn der zu überprüfende Teilstring länger ist als der string an sich.
    */
}

/*****************ZUSATZAUFGABEN*****************/

// (e)
int string_length(char *s)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        count++;
    }

    return count;
}

// (a)
bool digits_have_length_3(char *s)
{
    return true;
}

void test(void)
{
    // (a)
    // test_equal_b(is_in_alphabet('a'), true);
    // test_equal_b(is_in_alphabet('y'), true);
    // test_equal_b(is_in_alphabet('B'), true);
    // test_equal_b(is_in_alphabet('X'), true);
    // test_equal_b(is_in_alphabet(' '), false);
    // test_equal_b(is_in_alphabet('.'), false);
    // test_equal_b(is_in_alphabet('{'), false);

    // (b)
    // test_equal_b(is_palindrome("hello world"), false);
    // test_equal_b(is_palindrome("anna"), true);
    // test_equal_b(is_palindrome(""), false);
    // test_equal_b(is_palindrome("shower."), false);
    // test_equal_b(is_palindrome("madam ?"), true);
    // test_equal_b(is_palindrome("nurses run"), true);

    // (c)
    // test_equal_b(contains_palindrome("hello world", 5), false);
    // test_equal_b(contains_palindrome("hello world", 3), true);
    // test_equal_b(contains_palindrome("anna", 3), true);
    // test_equal_b(contains_palindrome("", 0), false);
    // test_equal_b(contains_palindrome("shower thoughts by madam anna", 4), true);
    // test_equal_b(contains_palindrome("madam anna is a nurse", 3), true);
    // test_equal_b(contains_palindrome("nurses run", 4), true);

    /*****************ZUSATZAUFGABEN*****************/

    // (e)
    // test_equal_i(string_length("hello"), 5);
    // test_equal_i(string_length("hello world"), 10);
    // test_equal_i(string_length("1234567"), 7);
    // test_equal_i(string_length("h i , t h e r e !"), 9);
    // test_equal_i(string_length(""), 0);

    // (a)
    test_equal_b(digits_have_length_3("123"), true);
    test_equal_b(digits_have_length_3("ab c de 123456"), true);
    test_equal_b(digits_have_length_3("123 asdbderb 890"), true);
    test_equal_b(digits_have_length_3("1234"), false);
    test_equal_b(digits_have_length_3("aaa"), false);
}

int main(void)
{
    test();
    return 0;
}
