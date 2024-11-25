#include <stdio.h>
#include <string.h>
#define BLOCK_SIZE 8
void des_encrypt(const unsigned char *plaintext, unsigned char *ciphertext, const unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
}

int main() {
    unsigned char plaintext[BLOCK_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    unsigned char key[BLOCK_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    unsigned char ciphertext[BLOCK_SIZE];

    des_encrypt(plaintext, ciphertext, key);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", ciphertext[i]); 
    }
    printf("\n");

    return 0;
}
