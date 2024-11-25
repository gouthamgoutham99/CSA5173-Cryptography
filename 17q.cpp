#include <stdio.h>
#include <string.h>
void DES_decrypt(const char *ciphertext, char *plaintext, const char keys[16][7]) {
    char reversed_keys[16][7];
    for (int i = 0; i < 16; i++) {
        strncpy(reversed_keys[i], keys[15 - i], 7);
    }
    strncpy(plaintext, ciphertext, strlen(ciphertext));
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[] = "EncryptedMessage";
    char plaintext[256];
    char keys[16][7] = {
        "K1", "K2", "K3", "K4", "K5", "K6", "K7", "K8",
        "K9", "K10", "K11", "K12", "K13", "K14", "K15", "K16"
    };

    DES_decrypt(ciphertext, plaintext, keys);

    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}
