#include <stdio.h>
#include <math.h>
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int main() {
    long long e = 17, n = 3233; 
    char message[] = "HELLO";
    long long encrypted[5];
    printf("Original Message: %s\n", message);
    for (int i = 0; i < 5; i++) {
        encrypted[i] = mod_exp(message[i] - 'A', e, n);
        printf("Encrypted[%d]: %lld\n", i, encrypted[i]);
    }
    printf("\nWarning: Encrypting single characters is insecure due to dictionary attacks.\n");
    return 0;
}