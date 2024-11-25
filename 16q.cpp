#include <stdio.h>
#include <string.h>
#include <ctype.h>
void count_frequencies(const char *text, int *frequencies) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            frequencies[tolower(text[i]) - 'a']++;
        }
    }
}
void frequency_attack(const char *ciphertext, char *plaintext) {
    int frequencies[26] = {0};
    count_frequencies(ciphertext, frequencies);

    char most_frequent[] = "etaoinshrdlcumwfgypbvkjxqz"; 
    int mapping[26] = {0};
    for (int i = 0; i < 26; i++) {
        int max_index = 0;
        for (int j = 1; j < 26; j++) {
            if (frequencies[j] > frequencies[max_index]) {
                max_index = j;
            }
        }
        mapping[max_index] = most_frequent[i];
        frequencies[max_index] = -1; 
    }
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[i] = toupper(mapping[tolower(ciphertext[i]) - 'a']);
            } else {
                plaintext[i] = mapping[ciphertext[i] - 'a'];
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main() {
    char ciphertext[] = "Uijt jt b tfdsfu nfttbhf!";
    char plaintext[256];

    frequency_attack(ciphertext, plaintext);

    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}
