#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    // 保证最后剩下一个，即其它序号都出现了偶数次，xor即可消去。
    int res = 0;
    for (int i = 0; i < n; ++i) {
        double a;
        int t;
        scanf("%lf %d", &a, &t);
        for (int j = 1; j <= t; ++j) {
            res ^= (int)(a * j);
        }
    }
    printf("%d\n", res);

    return 0;
}
