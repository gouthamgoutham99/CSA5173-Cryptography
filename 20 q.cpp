#include <stdio.h>
#include <string.h>
void ECB_encrypt(const char *plaintext, const char *key, char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() {
    char plaintext[] = "HelloWorld";
    char key[] = "Key";
    char ciphertext[256];

    ECB_encrypt(plaintext, key, ciphertext);
    ciphertext[3] = '0';

    printf("Ciphertext with error: %s\n", ciphertext);

    return 0;
}
