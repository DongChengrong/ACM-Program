#include <stdio.h>
#include <string.h>

#define N 110000

typedef long long ll;

int a[N];
ll c[N];

int lowbit(int x) {
    return x & -x;
}

ll sum(int x) {
    ll sum = 0;
    while (x > 0) {
        sum += c[x];
        x = x - lowbit(x);
    }
    return sum;
}

void add(int x, int d) {
    while (x < N) {
        c[x] += d;
        x = x + lowbit(x);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(c, 0, sizeof(c));
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x); a[x] = i;
        }
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            add(a[x], 1);
            res = res + (i - sum(a[x]));
        }
        printf("%I64d\n", res);
    }
    return 0;
}
