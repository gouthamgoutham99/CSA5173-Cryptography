#include <stdio.h>
#include <string.h>
#include <ctype.h>
char matrix[5][5];
void generateMatrix(char key[]) {
    int used[26] = {0}, k = 0;
    used['J' - 'A'] = 1; 
        for (int i = 0; key[i] != '\0'; i++) {
        if (!used[toupper(key[i]) - 'A']) {
            matrix[k / 5][k % 5] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            k++;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            k++;
        }
    }
}
void findPosition(char c, int *row, int *col) {
    if (c == 'J') c = 'I'; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void decryptPlayfair(char ciphertext[]) {
    int r1, c1, r2, c2;
    for (int i = 0; ciphertext[i] != '\0' && ciphertext[i + 1] != '\0'; i += 2) {
        findPosition(ciphertext[i], &r1, &c1);
        findPosition(ciphertext[i + 1], &r2, &c2);
        if (r1 == r2) {
            ciphertext[i] = matrix[r1][(c1 - 1 + 5) % 5];
            ciphertext[i + 1] = matrix[r2][(c2 - 1 + 5) % 5];
        } else if (c1 == c2) {
            ciphertext[i] = matrix[(r1 - 1 + 5) % 5][c1];
            ciphertext[i + 1] = matrix[(r2 - 1 + 5) % 5][c2];
        } else {
            ciphertext[i] = matrix[r1][c2];
            ciphertext[i + 1] = matrix[r2][c1];
        }
    }
}
int main() {
    char key[] = "PT109"; // Example key
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFS"; // Example ciphertext
    generateMatrix(key);
    decryptPlayfair(ciphertext);
    printf("Decrypted Text: %s\n", ciphertext);
    return 0;
}
