/*
Compile: make palindrome
Run: ./palindrome
make palindrome && ./palindrome
*/

#include "base.h"


/**
(a)
Return whether a character is in the alphabet
*/
bool is_in_alphabet(char c) {
    return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

/**
(b)
Return whether a String is a palindrome
*/
bool is_palindrome(char* s) {
    if (strlen(s) == 0) {
        return false;
    }
    for (int i = 0, j = strlen(s)-1; i < strlen(s) && j > 0; i++, j--) {
        while (!is_in_alphabet(s[i])) {
            i++;
        }
        while (!is_in_alphabet(s[j])) {
            j--;
        }
        if (s[i] != s[j]) {
            return false;
        }
    } 
    return true;
}

/**
(c)
Return whether a String contains at least one palindrome of minimum size minimumPalindromeSize
*/
bool contains_palindrome(char* s, int minimumPalindromeSize) {    
    for (int chunksize = minimumPalindromeSize; chunksize <= strlen(s); chunksize++) {
        for (int i = 0; i < strlen(s) - chunksize+1; i++) {
            char chunk[chunksize+1];
            memcpy(chunk, &s[i], chunksize);
            chunk[chunksize] = '\0';
            //printf("evaluating %s\n", chunk);
            if (is_palindrome(chunk)) {
                //printf("%s is a palindrome\n", chunk);
                return true;
            }
        }
    }
    return false;
}




void test(void) {
    // (a)
    test_equal_b(is_in_alphabet('a'), true);
    test_equal_b(is_in_alphabet('y'), true);
    test_equal_b(is_in_alphabet('B'), true);
    test_equal_b(is_in_alphabet('X'), true);
    test_equal_b(is_in_alphabet(' '), false);
    test_equal_b(is_in_alphabet('.'), false);
    test_equal_b(is_in_alphabet('{'), false);
    
    // (b)
    test_equal_b(is_palindrome("hello world"), false);
    test_equal_b(is_palindrome("anna"), true);
    test_equal_b(is_palindrome(""), false);
    test_equal_b(is_palindrome("shower."), false);
    test_equal_b(is_palindrome("madam ?"), true);
    test_equal_b(is_palindrome("nurses run"), true);
    
    // (c)
    test_equal_b(contains_palindrome("hello world", 5), false);
    test_equal_b(contains_palindrome("hello world", 3), true);
    test_equal_b(contains_palindrome("anna", 3), true);
    test_equal_b(contains_palindrome("", 0), false);
    test_equal_b(contains_palindrome("shower thoughts by madam anna", 4), true);
    test_equal_b(contains_palindrome("madam anna is a nurse", 3), true);
    test_equal_b(contains_palindrome("nurses run", 4), true);
    
}

int main(void) {
    test();
    return 0;
}
