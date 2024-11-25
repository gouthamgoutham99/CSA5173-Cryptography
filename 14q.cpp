#include <stdio.h>
#include <string.h>
void vigenere_encrypt(char *plaintext, int key[], int key_length, char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = ((plaintext[i] - 'a') + key[i % key_length]) % 26 + 'a';
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() {
    char plaintext[] = "sendmoremoney";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int key_length = sizeof(key) / sizeof(key[0]);
    char ciphertext[50];
    printf("Plaintext: %s\n", plaintext);
    vigenere_encrypt(plaintext, key, key_length, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
