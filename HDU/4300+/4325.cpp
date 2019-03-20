#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

int c[N];

void add(int x, int d) {
    while (x < N) {
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
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        int n, m;
        printf("Case #%d:\n", kase);
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            add(l, 1); add(r + 1, -1);
        }
        while (m--) {
            int x; scanf("%d", &x);
            printf("%d\n", sum(x));
        }
    }
    return 0;
}
