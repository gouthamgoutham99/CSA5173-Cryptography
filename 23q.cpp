#include <stdio.h>
#include <string.h>
void CTR_encrypt(const char *plaintext, const char *key, int counter, char *ciphertext, int block_size) {
    for (int i = 0; i < strlen(plaintext); i += block_size) {
        for (int j = 0; j < block_size && i + j < strlen(plaintext); ++j) {
            ciphertext[i + j] = plaintext[i + j] ^ (key[j % strlen(key)] ^ counter);
        }
        counter++;
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() {
    char plaintext[] = "CounterModeText";
    char key[] = "12345"; 
    int counter = 1;
    char ciphertext[256];

    CTR_encrypt(plaintext, key, counter, ciphertext, 5);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
