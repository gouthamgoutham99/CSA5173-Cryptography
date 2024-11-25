#include <stdio.h>
#include <stdint.h>
void generate_subkeys(uint8_t *K1, uint8_t *K2, uint8_t block_size) {
    uint8_t Rb = (block_size == 64) ? 0x1B : 0x87; 
    uint8_t L[16] = {0}; 
    for (int i = 0; i < block_size / 8; i++) {
        K1[i] = L[i] << 1;
        if (i > 0 && (L[i - 1] & 0x80)) K1[i] |= 1;
    }
    if (L[0] & 0x80) K1[block_size / 8 - 1] ^= Rb; 
    for (int i = 0; i < block_size / 8; i++) {
        K2[i] = K1[i] << 1;
        if (i > 0 && (K1[i - 1] & 0x80)) K2[i] |= 1;
    }
}
int main() {
    uint8_t K1[16] = {0}, K2[16] = {0};
    generate_subkeys(K1, K2, 128); 
    return 0;
}
