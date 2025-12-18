/*
Compile: make indentation
Run: ./indentation
Compile & run: make indentation && ./indentation
*/
#include "base.h"

int indentation(char * s) {
    // todo
    require_not_null(s);
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '\t') return -1;
        if(s[i] != ' ') return count;
        count++;
    }
    return count;
}

/*
In dieser funktion, sagst du mit der Deklaration vom Pointer p, das alle Leerzeichen überspringen werden sollen und erst beim ersten nicht Leerzeichen character der string gelesen werden soll.
Vergiss nicht, strings sind character arrays
-> [' ', ' ', ' ', 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']
*/
char * left_trim(char * s) { // s zeigt auf den ersten character des übergebenen strings
    require_not_null(s);
    char *p = s; // p zeigt auf dasselbe, also den ersten character des strings

    while(*p == ' ' || *p == '\t'){
        if(*p == '\t') return "";
        p++;
    }

    return p; // originaler string wird nicht verändert, es wird nur der Teil zurückgegeben an dem p zum ersten mal auf ein nicht Leerzeichen (einen Buchstaben) trifft. Bei ("   Hello World   ") zum Beispiel, überspringt er die Leerzeichen, bedeutet der while loop läuft weil die Bedingung gilt. Wenn *p jetzt == 'H' ist, wird der while loop übersrpungen und p wird zurück gegeben, also der gesamte string ab dem ersten nicht Leerzeichen -> "Hello World   " 
}

char * extract_comment(char * s) {
    require_not_null(s);
    char *p = s;

    while (*p != '\0') {
        if (*p == '/' && *(p + 1) == '/') {
            return left_trim(p + 2);
        }
        p++;
    }

    return "";
}

void extract_comment_test(void) {
    test_equal_s(extract_comment("int i = 4/2;"), "");
    test_equal_s(extract_comment("int i = 0; // a new integer"), "a new integer");
    test_equal_s(extract_comment("   double f = 0.0; //   a new double"), "a new double");
    test_equal_s(extract_comment("  bool b = false; //a new bool"), "a new bool");
    test_equal_s(extract_comment("  bool b = false; //a new bool  "), "a new bool  ");
    test_equal_s(extract_comment("  bool b = false; //"), "");
    test_equal_s(extract_comment("int i = 0;"), "");
}

void left_trim_test(void) {
    test_equal_s(left_trim("   sample  "), "sample  ");
    test_equal_s(left_trim("Hello World"), "Hello World");
    test_equal_s(left_trim("    hello"), "hello");
    test_equal_s(left_trim("  Hello World"), "Hello World");
    test_equal_s(left_trim("\t\tHello"), ""); // error
    test_equal_s(left_trim("    \tHello"), ""); // error
}

void indentation_test(void) {
    test_equal_i(indentation(""), 0);
    test_equal_i(indentation(" "), 1);
    test_equal_i(indentation("x"), 0);
    test_equal_i(indentation("\t"), -1); // error
    test_equal_i(indentation("  "), 2);
    test_equal_i(indentation("x "), 0);
    test_equal_i(indentation("\t "), -1); // error
    test_equal_i(indentation(" x"), 1);
    test_equal_i(indentation("xy"), 0);
    test_equal_i(indentation("\tx"), -1); // error
    test_equal_i(indentation(" \t"), -1); // error
    test_equal_i(indentation("  \t"), -1); // error
    test_equal_i(indentation("x\t"), 0);
    test_equal_i(indentation("\t\t"), -1); // error
    test_equal_i(indentation("    \tx"), -1); // error
    test_equal_i(indentation("    \t x"), -1); // error
    test_equal_i(indentation("xy \t"), 0);
    test_equal_i(indentation(" xyz \t"), 1);
    test_equal_i(indentation("  abcd \t"), 2);
    test_equal_i(indentation("    a \t"), 4);
    test_equal_i(indentation("  "), 2);
    test_equal_i(indentation("    "), 4);
    test_equal_i(indentation("    hello \t "), 4);
}





int main(void) {
    // indentation_test();
    // left_trim_test();
    extract_comment_test();
    return 0;
}
