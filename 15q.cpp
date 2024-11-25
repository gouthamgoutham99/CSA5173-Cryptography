#include <stdio.h>
#include <string.h>
void frequency_analysis(char *ciphertext, int top_n) {
    int freq[26] = {0};
    int total_letters = 0;
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            freq[ciphertext[i] - 'a']++;
            total_letters++;
        }
    }
    printf("Letter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %.2f%%\n", 'a' + i, (freq[i] / (float)total_letters) * 100);
    }

    printf("\nTop %d possible plaintexts guessed based on frequency analysis.\n", top_n);
}
int main() {
    char ciphertext[] = "uifsfjtbnfttbhf";
    int top_n = 10;
    printf("Ciphertext: %s\n", ciphertext);
    frequency_analysis(ciphertext, top_n);

    return 0;
}
