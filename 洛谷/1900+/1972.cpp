#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100000
#define M 510000

struct Node {
    int a, b, p;
    bool operator < (const Node &u) const {
        return (b < u.b) || (b == u.b && a < u.a);
    }
};

int n, m;
Node b[M];
int ma[N], c[M], a[M], ans[M];

void add(int x, int d) {
    while (x <= n) {
        c[x] += d;
        x += x & (-x);
    }
}

int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += c[x];
        x -= x & (-x);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    memset(ma, 0, sizeof(ma));
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) { scanf("%d%d", &b[i].a, &b[i].b); b[i].p = i; }
    int pos = 1;
    sort(b, b + m);
    for (int i = 0; i < m; ++i) {
        while (pos <= b[i].b) {
            if (ma[a[pos]]) {
                add(ma[a[pos]], -1);
                add(pos, 1);
            } else add(pos, 1);
            ma[a[pos]] = pos;
            pos++;
        }
        ans[b[i].p] = sum(b[i].b) - sum(b[i].a - 1);
    }
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}
