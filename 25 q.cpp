#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int n = 3599;       
    int plaintext = 123; 
    int factor = gcd(n, plaintext);
    if (factor > 1) {
        printf("A factor of n found: %d\n", factor);
    } else {
        printf("No factor found. RSA remains secure.\n");
    }
    return 0;
}
