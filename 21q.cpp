#include <stdio.h>
#include <string.h>
const char KEY[256] = {
};
void ECB_encrypt(const char *plaintext, char *ciphertext, int block_size) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % block_size]; 
    }
    ciphertext[i] = '\0';
}
int main() {
    char plaintext[] = "Example message.";
    char ciphertext[256];
    int block_size = 16; 
    printf("Plaintext: %s\n", plaintext);
    ECB_encrypt(plaintext, ciphertext, block_size);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
