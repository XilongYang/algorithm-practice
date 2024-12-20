#include <stdio.h>

// Sqrt(2 * 10^9)
#define MAX_RANGE 44722

char not_prim[MAX_RANGE];
int prime[MAX_RANGE];
int prime_end = 0;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < MAX_RANGE; ++i) {
        if (!not_prim[i]) {
            prime[prime_end++] = i;
            if (n % i == 0) {
                printf("%d\n", n / i);
                break;
            }
        }
        for (int j = 0; j < prime_end; ++j) {
            if (prime[j] * i >= MAX_RANGE) break;
            not_prim[prime[j]*i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return 0;
}
