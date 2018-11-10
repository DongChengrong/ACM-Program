#include <stdio.h>
#include <string.h>

#define N 1100000

typedef long long ll;

int a[N], b[N];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        memset(b, 0, sizeof(b));
        while (m--) {
            int q, l, r, p;
            scanf("%d%d%d%d", &q, &l, &r, &p);
            if (q == 1) {
                b[l] -= p; b[r + 1] += p;
            }
            else {
                b[l] += p; b[r + 1] -= p;
            }
        }
        ll res = 0, tmp = 0;
        int l, r; scanf("%d%d", &l, &r);
        for (int i = 1; i <= n; ++i) {
            tmp += b[i];
            if (l <= i && i <= r) res = res + tmp + a[i];
        }
        printf("%lld\n", res);
    }
    return 0;
}
