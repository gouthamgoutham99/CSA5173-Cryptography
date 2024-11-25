#include <stdio.h>
#include <string.h>

void generate_keys(const char *initial_key, char subkeys[16][48]) {
    strncpy(subkeys[0], initial_key, 24);
    strncpy(subkeys[1], initial_key + 24, 24);
}

int main() {
    char initial_key[] = "101010101011101100001001000110000010011100110110";
    char subkeys[16][48];
    generate_keys(initial_key, subkeys);
    for (int i = 0; i < 2; i++) {
        printf("Subkey %d: %s\n", i + 1, subkeys[i]);
    }

    return 0;
}
