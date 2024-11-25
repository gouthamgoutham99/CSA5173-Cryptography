#include <stdio.h>
#include <ctype.h>
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1; 
}
void decryptAffineCipher(char text[], int a, int b) {
    int aInverse = modInverse(a, 26);
    if (aInverse == -1) {
        printf("Invalid value of a. No modular inverse exists.\n");
        return;
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            text[i] = ((aInverse * ((text[i] - offset - b + 26)) % 26) + offset);
        }
    }
}
int main() {
    char ciphertext[] = "U...B..."; 
    int a = 5, b = 8; 
    decryptAffineCipher(ciphertext, a, b);
    printf("Decrypted Text: %s\n", ciphertext);
    return 0;
}
