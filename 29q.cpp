#include <stdio.h>
#define CAPACITY 1024
#define ROUNDS 24
int main() {
    int capacity[CAPACITY] = {0}; 
    capacity[0] = 1; 
    for (int round = 1; round <= ROUNDS; round++) {
        for (int i = 0; i < CAPACITY; i++) {
            if (capacity[i] == 0) capacity[i] = 1; 
        }
        int all_nonzero = 1;
        for (int i = 0; i < CAPACITY; i++) {
            if (capacity[i] == 0) {
                all_nonzero = 0;
                break;
            }
        }
        printf("After round %d, all nonzero: %s\n", round, all_nonzero ? "Yes" : "No");
        if (all_nonzero) break;
    }
    return 0;
}