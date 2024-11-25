#include <stdio.h>
#include <string.h>
#include <ctype.h>
void playfairCipher(char text[], char key[]) {
    printf("Playfair Cipher function needs further implementation for matrix.\n");
}
int main() {
    char text[100], key[25];
    printf("Enter plaintext: ");
    gets(text);
    printf("Enter keyword: ");
    gets(key);
    playfairCipher(text, key);
    return 0;
}
