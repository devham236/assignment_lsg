#include "base.h"

const String permutation = "SGEMFVYZIDPBUKHARNXQWOLJTC";
const String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int index_of(String s, char c) {
    // TODO
    for (int i = 0; i < s_length(s); i++)
    {
        if(s[i] == c){
            return i;
        }
    }
    
    return -1;
}

String encrypt(String input) {
    // TODO
    int str_length = s_length(input);
    String encryptedStr = s_copy(input);
    for (int i = 0; i < s_length(input); i++)
    {
        /* code */
        int indexOf = index_of(alphabet, input[i]);

        if(indexOf != -1) {
            s_set(encryptedStr, i, s_get(permutation, i));
        }
        else {
            // do nothing
        }
        
    }
    
    printf("%s\n", encryptedStr);
    return s_copy(encryptedStr);
}



String decrypt(String input) {
    // TODO
    return s_copy(input);
}

void test_identity(String s) {
    // assert("encrypted text must differ from input", !s_equals(s, encrypt(s)));
    // test_equal_s(s, decrypt(encrypt(s)));
}

int main(void) {
    test_identity("HELLO WORLD");
    test_identity("SOME SUPER SECRET TEXT");
    test_identity("DOES QUOTATION CAUSE ISSUES? IT SHOULDN'T.");
    test_identity("BE SURE TO DRINK YOUR OVALTINE");
    printsln("The secret text says:");
    printsln(decrypt("VNSKC DSYQ IU PHUABFQQ OFNLSZNBHXQFK QSJI RWFN MWNEZ GSTFNK."));
    encrypt("HELLO WORLD");
}
