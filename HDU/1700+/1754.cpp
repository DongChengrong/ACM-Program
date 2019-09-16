#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 600000
#define INF 0x3f3f3f3f

int n, m, len;
int maxv[N];
int ql, qr, p, v;

void update(int o, int l, int r) {
    if (l == r) maxv[o] = v;
    else {
        int mid = (l + r) / 2;
        if (p <= mid) update(o * 2, l, mid);
        else update(o * 2 + 1, mid + 1, r);
        maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
    }
}

int query(int o, int l, int r) {
    int ans = -INF, mid = (l + r) / 2;
    if (ql <= l && qr >= r) return maxv[o];
    if (ql <= mid) ans = max(ans, query(o * 2, l, mid));
    if (qr > mid) ans = max(ans, query(o * 2 + 1, mid + 1, r));
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (p = 1; p <= n; ++p) {
            scanf("%d", &v); update(1, 1, n);
        }
        while (m--) {
            char s[2];
            scanf("%s%d%d", s, &ql, &qr); v = qr, p = ql;
            if (s[0] == 'Q') printf("%d\n", query(1, 1, n));
            else update(1, 1, n);
        }
    }
    return 0;
}
