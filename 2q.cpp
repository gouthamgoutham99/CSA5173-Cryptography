#include <stdio.h>
#include <string.h>
#include <ctype.h>
void monoalphabeticCipher(char text[], char cipherMap[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { 
            char offset = islower(text[i]) ? 'a' : 'A'; 
            text[i] = cipherMap[text[i] - offset]; 
        }
    }
}
int main() {
    char text[100]; 
    char cipherMap[] = "QWERTYUIOPLKJHGFDSAZXCVBNM";
    printf("Enter plaintext: ");
    if (fgets(text, sizeof(text), stdin) != NULL) { 
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }
        monoalphabeticCipher(text, cipherMap); 
        printf("Ciphertext: %s\n", text); 
    } else {
        printf("Error reading input.\n"); 
    }
    return 0;
}
