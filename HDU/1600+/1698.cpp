#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100000

int _sum;
int qr, ql, v;
int sum[N], setv[N];

void maintain(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    sum[o] = 0;
    if (r > l) sum[o] = sum[lc] + sum[rc];
    if (setv[o]) sum[o] = (r - l + 1) * (setv[o]);
}

void pushdown(int o) {
    int lc = o * 2, rc = o * 2 + 1;
    if (setv[o]) {
        setv[lc] = setv[rc] = setv[o];
        setv[o] = 0;
    }
}

void update(int o, int l, int r) {
    int lc = o * 2, rc = o * 2 + 1;
    if (ql <= l && qr >= r) setv[o] = v;
    else {
        pushdown(o);
        int m = (l + r) / 2;
        if (ql <= m) update(lc, l, m); else maintain(lc, l, m);
        if (qr > m) update(rc, m + 1, r); else maintain(rc, m + 1, r);
    }
    maintain(o, l, r);
}

void query(int o, int l, int r) {
    if (setv[o] > 0) _sum = setv[o] * (min(r, qr) - max(l, ql) + 1);
    else if (ql <= l && qr >= r) _sum += sum[o];
    else {
        int m = (l + r) / 2;
        if (ql <= m) query(o * 2, l, m);
        if (qr > m) query(o * 2 + 1, m + 1, r);
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        memset(sum, 0, sizeof(sum));
        memset(setv, 0, sizeof(setv));
        int n; scanf("%d", &n); v = 1;
        ql = 1, qr = n, v = 1; update(1, 1, n);
        int m; scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &ql, &qr, &v);
            update(1, 1, n);
        }
        ql = 1, qr = n, _sum = 0; query(1, 1, n);
        printf("Case %d: The total value of the hook is %d.\n", kase, _sum);
    }
    return 0;
}
