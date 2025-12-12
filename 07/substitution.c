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
    String encrypted_str = s_copy(input);
    for (int i = 0; i < str_length; i++)
    {
        int index_of_char = index_of(alphabet, input[i]);

        if(index_of_char != -1) {
            char matching_char = s_get(permutation, index_of_char);
            s_set(encrypted_str, i, matching_char);
        }
    }
    
    return encrypted_str;
}



String decrypt(String input) {
    // TODO
    int str_length = s_length(input);
    String decrypted_str = s_copy(input);

    for (int i = 0; i < str_length; i++)
    {
        int index_of_char = index_of(permutation, input[i]);
        if (index_of_char != -1) {
            char matching_char = s_get(alphabet, index_of_char);
            s_set(decrypted_str, i, matching_char);
        }
    }
    
    return decrypted_str;
}

void test_identity(String s) {
    assert("encrypted text must differ from input", !s_equals(s, encrypt(s)));
    test_equal_s(s, decrypt(encrypt(s)));
}

int main(void) {
    test_identity("HELLO WORLD");
    test_identity("SOME SUPER SECRET TEXT");
    test_identity("DOES QUOTATION CAUSE ISSUES? IT SHOULDN'T.");
    test_identity("BE SURE TO DRINK YOUR OVALTINE");
    printsln("The secret text says:");
    printsln(decrypt("VNSKC DSYQ IU PHUABFQQ OFNLSZNBHXQFK QSJI RWFN MWNEZ GSTFNK."));
}
