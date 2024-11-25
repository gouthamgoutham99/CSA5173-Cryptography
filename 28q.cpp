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
    long long p = 23, g = 5; 
    long long a = 6, b = 15; 
    long long A = mod_exp(g, a, p);
    long long B = mod_exp(g, b, p);
    printf("Public Parameters: p = %lld, g = %lld\n", p, g);
    printf("Alice sends: %lld\n", A);
    printf("Bob sends: %lld\n", B);
    long long alice_key = mod_exp(B, a, p);
    long long bob_key = mod_exp(A, b, p);
    printf("Shared Key (Alice): %lld\n", alice_key);
    printf("Shared Key (Bob): %lld\n", bob_key);
    if (alice_key == bob_key)
        printf("Key exchange successful!\n");
    else
        printf("Key exchange failed.\n");
    return 0;
}