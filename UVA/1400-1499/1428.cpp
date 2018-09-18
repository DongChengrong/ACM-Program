#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 101000

typedef long long ll;

int n, m;
int C[N], c[N], d[N], num[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int d) {
    while (x <= m) {
        C[x] += d;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += C[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    int T;
    m = N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(C, 0, sizeof(C));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            m = max(num[i], m);
            add(num[i], 1);
            c[i] = sum(num[i] - 1);
        }
        memset(C, 0, sizeof(C));
        for (int i = n; i >= 1; --i) {
            add(num[i], 1);
            d[i] = sum(num[i] - 1);
        }
        ll res = 0;
        for (int i = 2; i <= n - 1; ++i) {
            res += (ll)(c[i] * (n - i - d[i])) + (ll)(d[i] * (i - 1 - c[i]));
        }
        printf("%lld\n", res);
    }
    return 0;
}
