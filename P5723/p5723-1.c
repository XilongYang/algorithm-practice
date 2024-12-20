#include <stdio.h>

#define TRUE  1
#define FALSE 0

typedef long long ll;

ll check_arr[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

// x^e % m
ll binexp(ll x, ll e, ll m) {
    x %= m;
    ll res = 1;
    while (e) {
        if (e & 1) res = (res * x) % m;
        x = (x * x) % m;
        e >>= 1;
    }
    return res;
}

// Miller-Robin
int is_prime(ll n) {
    if (n < 3 || n % 2 == 0) return n == 2;
    ll u = n - 1;
    ll t = 0;
    while (u % 2 == 0) {
        u /= 2;
        t++;
    }
    for (int i = 0; i < sizeof(check_arr) / sizeof(ll); ++i) {
        ll a = check_arr[i] % n;
        if (a == 0 || a == n - 1 || a == 1) continue;
        ll v = binexp(a, u, n);
        if (v == 1) continue;
        int j = 0;
        for (; j < t; ++j) {
            if (v == n - 1) break;
            v = v * v % n;
        }
        if (j == t) return FALSE;
    }
    return TRUE;
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll cnt = 0;
    ll sum = 0;
    for (ll i = 2; i < n; ++i) {
        if (!is_prime(i)) continue;
        
        if (sum + i > n) break;

        printf("%lld\n", i);

        sum += i;
        cnt++;
    }
    printf("%lld\n", cnt);
    return 0;
}
