#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modInverse(int e, int phi) {
    for (int x = 1; x < phi; x++) {
        if ((e * x) % phi == 1) {
            return x;
        }
    }
    return -1;
}
int main() {
    int p = 61, q = 59; 
    int n = p * q;      
    int phi = (p - 1) * (q - 1);
    int e = 31;        
    int d = modInverse(e, phi);
    if (d == -1) {
        printf("No modular inverse found.\n");
        return -1;
    }
    int plaintext = 42; 
    int ciphertext = 1, decrypted = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * ciphertext) % n;
    }
    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted: %d\n", decrypted);
    return 0;
}
