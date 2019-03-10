#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000
#define INF 0x3f3f3f3f
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;

int bit[N];
ll a[N];

void detail(ll x) {
    int n = 0;
    while (x) {
        if (x & 1) bit[n]++;
        x >>= 1;
        ++n;
    }
}

int main() {
    int n;
    ll k, tmp;
    while (scanf("%d%lld", &n, &k) != EOF) {
        int m = 0; tmp = k;
        while (k) m++, k = k >> 1;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            detail(a[i]);
        }
        k = 0;
        for (int i = m - 1; i >= 0; --i) {
            k = k << 1;
            if (bit[i] <= n / 2 && ((k + 1) << i) <= tmp) k = k + 1;
        }
        ll res = 0;
        for (int i = 0; i < n; ++i) res += k ^ a[i];
        printf("%lld\n", res);
    }
    return 0;
}
