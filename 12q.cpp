#include <stdio.h>
#include <string.h>
void hill_cipher_encrypt(int key[2][2], char *plaintext, char *ciphertext) {
    int i, temp[2];
    for (i = 0; i < strlen(plaintext); i += 2) {
        temp[0] = (key[0][0] * (plaintext[i] - 'a') + key[0][1] * (plaintext[i + 1] - 'a')) % 26;
        temp[1] = (key[1][0] * (plaintext[i] - 'a') + key[1][1] * (plaintext[i + 1] - 'a')) % 26;
        ciphertext[i] = temp[0] + 'a';
        ciphertext[i + 1] = temp[1] + 'a';
    }
    ciphertext[i] = '\0';
}
int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    char plaintext[] = "meetmeattheusualplace";
    char ciphertext[50];
    printf("Plaintext: %s\n", plaintext);
    hill_cipher_encrypt(key, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
