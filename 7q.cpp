#include <stdio.h>
#include <string.h>
#include <ctype.h>
void decryptSubstitutionCipher(char text[], char cipherMap[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            for (int j = 0; j < 26; j++) { 
                if (cipherMap[j] == text[i]) { 
                    text[i] = 'a' + j; 
                    break;
                }
            }
        }
    }
}
int main() {
    char ciphertext[] = "TQXXA IADXP"; 
    char cipherMap[26] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 
        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 
        'X', 'C', 'V', 'B', 'N', 'M'                      
    };
    decryptSubstitutionCipher(ciphertext, cipherMap);
    printf("Decrypted Text: %s\n", ciphertext);
    return 0;
}
