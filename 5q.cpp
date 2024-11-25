#include <stdio.h>
#include <ctype.h>
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}
void affineCipher(char text[], int a, int b) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            text[i] = ((a * (text[i] - offset) + b) % 26 + 26) % 26 + offset;
        }
    }
}
int main() {
    char text[100];
    int a, b;
    printf("Enter plaintext: ");
    gets(text);
    printf("Enter values for a and b: ");
    scanf("%d %d", &a, &b);
    if (modInverse(a, 26) == -1) {
        printf("Invalid value of a. It must be coprime with 26.\n");
    } else {
        affineCipher(text, a, b);
        printf("Ciphertext: %s\n", text);
    }
    return 0;
}
