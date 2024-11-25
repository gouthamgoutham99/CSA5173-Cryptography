#include <stdio.h>
#include <string.h>
void apply_padding(unsigned char *input, int length, int block_size) {
    int padding_needed = block_size - (length % block_size);
    for (int i = length; i < length + padding_needed; i++) {
        input[i] = padding_needed; 
    }
}
int main() {
    unsigned char data[32] = "Hello, World!";
    int block_size = 16;
    int length = strlen((char *)data);
    apply_padding(data, length, block_size);
    printf("Padded data: ");
    for (int i = 0; i < length + (block_size - (length % block_size)); i++) {
        printf("%02X ", data[i]);
    }
    return 0;
}
