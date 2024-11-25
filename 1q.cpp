#include <stdio.h>
#include <ctype.h>
void caesarCipher(char text[], int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + k) % 26 + offset;
        }
    }
}
int main() {
    char text[100];
    int k;
    printf("Enter plaintext: ");
    gets(text);
    printf("Enter shift value (k): ");
    scanf("%d", &k);
    caesarCipher(text, k);
    printf("Ciphertext: %s\n", text);
    return 0;
}
