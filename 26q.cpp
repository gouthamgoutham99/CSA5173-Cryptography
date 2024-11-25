#include <stdio.h>
#include <stdlib.h>
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
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void generate_keys(long long *e, long long *d, long long *n) {
    long long p = 61, q = 53;
    *n = p * q;
    long long phi = (p - 1) * (q - 1);

    *e = 17; 
    while (gcd(*e, phi) != 1) (*e)++;
    long long k = 1;
    while ((k * phi + 1) % *e != 0) k++;
    *d = (k * phi + 1) / *e;
}
int main() {
    long long e, d, n;
    generate_keys(&e, &d, &n);
    printf("Public Key: (e = %lld, n = %lld)\n", e, n);
    printf("Private Key: (d = %lld, n = %lld)\n", d, n);
    long long message = 42;
    long long encrypted = mod_exp(message, e, n);
    long long decrypted = mod_exp(encrypted, d, n);
    printf("Original Message: %lld\n", message);
    printf("Encrypted Message: %lld\n", encrypted);
    printf("Decrypted Message: %lld\n", decrypted);
    printf("\nIf private key d is leaked, regenerate n (new primes p and q).\n");
    return 0;
}