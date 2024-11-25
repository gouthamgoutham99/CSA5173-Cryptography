#include <stdio.h>
#include <math.h> 
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int letters = 25;
    long long total_keys = factorial(letters);

    printf("Total possible unique keys for Playfair cipher: %lld\n", total_keys);
    double approx_power_of_2 = log2(total_keys);
    printf("Approximation: Approximately 2^%.0f\n", approx_power_of_2);

    return 0;
}
