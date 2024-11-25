#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherMap(char keyword[], char cipherMap[]) {
    int used[26] = {0};
    int index = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipherMap[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipherMap[index++] = ch;
        }
    }
}
void monoalphabeticCipher(char text[], char cipherMap[], int encrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            if (encrypt) {
                text[i] = cipherMap[text[i] - offset];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (cipherMap[j] == toupper(text[i])) {
                        text[i] = j + offset;
                        break;
                    }
                }
            }
        }
    }
}
int main() {
    char keyword[] = "CIPHER";
    char cipherMap[26];
    char text[100];
    int choice;
    generateCipherMap(keyword, cipherMap);
    printf("Enter text: ");
    gets(text);
    printf("Enter 1 to Encrypt or 0 to Decrypt: ");
    scanf("%d", &choice);
    monoalphabeticCipher(text, cipherMap, choice);
    printf("%s Text: %s\n", choice ? "Encrypted" : "Decrypted", text);
    return 0;
}
