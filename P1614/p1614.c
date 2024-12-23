#include <stdio.h>

int sum[10005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int cur;
        scanf("%d", &cur);
        sum[i] = sum[i - 1] + cur;
    }
    int min = (1 << 31) - 1;
    for (int i = m; i <= n; ++i) {
        int cur = sum[i] - sum[i - m];
        min = min > cur ? cur : min;
    }
    printf("%d\n", min);
    return 0;
}
