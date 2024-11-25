#include <stdio.h>
#include <ctype.h>
#include <string.h>
void vigenereCipher(char text[], char key[]) {
    int keyLen = strlen(key), keyIndex = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - offset + tolower(key[keyIndex]) - 'a') % 26 + offset;
            keyIndex = (keyIndex + 1) % keyLen;
        }
    }
}
int main() {
    char text[100], key[100];
    printf("Enter plaintext: ");
    gets(text);
    printf("Enter key: ");
    gets(key);
    vigenereCipher(text, key);
    printf("Ciphertext: %s\n", text);
    return 0;
}
