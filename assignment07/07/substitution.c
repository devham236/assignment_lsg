#include "base.h"

const String permutation = "SGEMFVYZIDPBUKHARNXQWOLJTC";
const String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int index_of(String s, char c) {
    // TODO
    int str_length = s_length(s);
    for (int i = 0; i < str_length; i++)
    {
        if(s[i] == c){
            return i;
        }
    }
    
    return -1;
}

/*
Verschlüsselt den übergebenen String, basierend auf 'permutation' oben.
@param String -> Input String der verschlüsselt wird
@return -> Gibt einen verschlüsselten bzw. modifizierten String zurück
*/
String encrypt(String input) {
    // TODO
    int str_length = s_length(input);
    String encryptedStr = s_copy(input);
    for (int i = 0; i < str_length; i++)
    {
        /* code */
        int indexOfChar = index_of(alphabet, input[i]);

        if(indexOfChar != -1) {
            s_set(encryptedStr, i, s_get(permutation, indexOfChar));
        }
        else {
            // do nothing
        }
        
    }
    
    return encryptedStr;
}



String decrypt(String input) {
    // TODO
    int str_length = s_length(input);
    String decryptedStr = s_copy(input);

    for (int i = 0; i < str_length; i++)
    {
        int indexOfChar = index_of(permutation, input[i]);
        if (indexOfChar != -1) {
            s_set(decryptedStr, i, s_get(alphabet, indexOfChar));
        }
        else {
            /* code */
        }
    }
    
    return decryptedStr;
}

void test_identity(String s) {
    assert("encrypted text must differ from input", !s_equals(s, encrypt(s)));
    // test_equal_s(s, decrypt(encrypt(s)));
}

int main(void) {
    test_identity("HELLO WORLD");
    test_identity("SOME SUPER SECRET TEXT");
    test_identity("DOES QUOTATION CAUSE ISSUES? IT SHOULDN'T.");
    test_identity("BE SURE TO DRINK YOUR OVALTINE");
    printsln("The secret text says:");
    printsln(decrypt("VNSKC DSYQ IU PHUABFQQ OFNLSZNBHXQFK QSJI RWFN MWNEZ GSTFNK."));
}
