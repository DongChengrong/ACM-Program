#include <stdio.h>

#define N 110000

typedef long long ll;

int n, m;
ll x[N], y[N];

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%I64d", &x[i]);
        for (int i = 0; i < m; ++i) scanf("%I64d", &y[i]);
        ll sum1 = x[0], sum2 = y[0];
        int cnt = 0, i = 1, j = 1;
        while (i < n || j < m) {
            if (i >= n) {
                sum2 += y[j++]; continue;
            }
            if (j >= m) {
                sum1 += x[i++]; continue;
            }
            if (sum1 && sum1 == sum2) {
                ++cnt; sum1 = x[i++]; sum2 = y[j++];
            } else if (sum1 < sum2){
                sum1 += x[i++];
            } else {
                sum2 += y[j++];
            }
        }
        if (sum1 == sum2) ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
