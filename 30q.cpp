#include <stdio.h>
#include <string.h>
int xor_blocks(int a, int b) {
    return a ^ b;
}
int cbc_mac(int key, int block) {
    return xor_blocks(key, block); 
}
int main() {
    int key = 123; 
    int block1 = 456; 
    int mac1 = cbc_mac(key, block1);
    int block2 = mac1 ^ block1;
    int mac2 = cbc_mac(key, block2);
    printf("MAC of one-block message: %d\n", mac1);
    printf("MAC of forged two-block message: %d\n", mac2);
    printf("\nWarning: CBC-MAC is insecure for variable-length messages.\n");
    return 0;
}