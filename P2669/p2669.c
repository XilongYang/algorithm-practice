#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

ull DaySum(ull x) {
    return (x * (1 + x)) / 2;
}

// Max: 10^4^3 = 10^12 < Max(unsigned long long)
ull CoinSum(ull x) {
    return (x * (x + 1) * (2 * x + 1)) / 6;
}

ull CurrentCoin(ull x) {
    ull CurSqure = CoinSum(x) - CoinSum(x - 1);
    return sqrt(CurSqure);
}

ull CurStep(ull k) {
    ull l = 0;
    ull r = k;
    ull m = (l + r) / 2;
    while (r - l > 1) {
        if (DaySum(m) >= k) r = m;
        else l = m;
        m = (l + r) / 2;
    }
    return l;
}

int main() {
    ull k;
    scanf("%lld", &k);

    ull x = CurStep(k);
    ull reminder = k - DaySum(x);
    ull sum = CoinSum(x) + reminder * CurrentCoin(x + 1);
    
    printf("%lld\n", sum);
    return 0;
}

