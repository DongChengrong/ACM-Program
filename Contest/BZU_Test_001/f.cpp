#include <stdio.h>
#include <string.h>
#include <algorithm>

#define N 220000

typedef long long ll;

int b[N];
ll a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int cnt = 0;
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &a[i]);
            if (a[i] == 0) b[i] = 1;
            if (a[i] < 0) ++cnt;
        }
        int l1 = 0, l2 = 0;
        if (cnt & 1) {
            int x = 0;
            ll _min = 1; _min = (_min << 35) * -1;
            for (int i = 1; i <= n; ++i) {
                if (a[i] < 0 && a[i] > _min) _min = a[i], x = i;
            }
            b[x] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (!b[i]) {
                if (l1) printf("1 %d %d\n", l1, i);
                l1 = i;
            } else {
                if (l2) printf("1 %d %d\n", l2, i);
                l2 = i;
            }
        }
        if (l1 && l2) printf("2 %d\n", l2);
    }
    return 0;
}
