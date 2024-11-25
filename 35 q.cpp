#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void one_time_pad_vigenere(const char *plaintext, const int *key, int key_len, char *ciphertext) {
    int text_len = strlen(plaintext);
    for (int i = 0; i < text_len; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') + key[i % key_len]) % 26 + 'A';
    }
    ciphertext[text_len] = '\0';
}
int main() {
    const char plaintext[] = "HELLO";
    const int key[] = {3, 19, 5}; 
    char ciphertext[sizeof(plaintext)];
    one_time_pad_vigenere(plaintext, key, 3, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
