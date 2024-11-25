#include <stdio.h>
#include <string.h>
void CBC_encrypt(const char *plaintext, const char *key, const char *iv, char *ciphertext, int block_size) {
    char previous_block[block_size];
    strncpy(previous_block, iv, block_size);

    for (int i = 0; i < strlen(plaintext); i += block_size) {
        for (int j = 0; j < block_size && i + j < strlen(plaintext); ++j) {
            ciphertext[i + j] = (plaintext[i + j] ^ previous_block[j]) ^ key[j % strlen(key)];
        }
        strncpy(previous_block, ciphertext + i, block_size); 
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() {
    char plaintext[] = "HelloWorld123456";
    char key[] = "12345"; 
    char iv[] = "ABCDE";  
    char ciphertext[256];
    CBC_encrypt(plaintext, key, iv, ciphertext, 5);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
