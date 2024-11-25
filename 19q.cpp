#include <stdio.h>
#include <string.h>
void TDES_encrypt_block(const char *block, const char *key1, const char *key2, const char *key3, char *output) {
    strncpy(output, block, 8); 
}
void CBC_TDES_encrypt(const char *plaintext, const char *key1, const char *key2, const char *key3, const char *iv, char *ciphertext, int block_size) {
    char previous_block[block_size];
    strncpy(previous_block, iv, block_size);

    for (int i = 0; i < strlen(plaintext); i += block_size) {
        char block[block_size + 1];
        strncpy(block, plaintext + i, block_size);
        block[block_size] = '\0';
        for (int j = 0; j < block_size; ++j) {
            block[j] ^= previous_block[j];
        }
        TDES_encrypt_block(block, key1, key2, key3, ciphertext + i);
        strncpy(previous_block, ciphertext + i, block_size);
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() {
    char plaintext[] = "ThisIsAPlainTextMessageForEncryption";
    char key1[] = "Key12345"; 
    char key2[] = "Key23456"; 
    char key3[] = "Key34567";
    char iv[] = "InitialV";   
    char ciphertext[256];
    int block_size = 8;      
    CBC_TDES_encrypt(plaintext, key1, key2, key3, iv, ciphertext, block_size);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
