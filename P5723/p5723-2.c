#include <stdio.h>

#define TRUE  1
#define FALSE 0

typedef long long ll;

char not_prime[10000];
ll prime[10000];
int prime_end = 0;

int main() {
    ll n;
    scanf("%lld", &n);
    ll sum = 0;
    for (ll i = 2; i < n; ++i) {
        if (!not_prime[i]) {
            if (sum + i > n) break;
            prime[prime_end++] = i;
            sum += i;
            printf("%lld\n", i);
        }
        for (int j = 0; j < prime_end; ++j) {
            if (prime[j] * i > 10000) break;
            not_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime_end);
    return 0;
}
