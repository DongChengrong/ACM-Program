#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1399709

typedef long long ll;

ll a[N], cnt;
int vis[N];

void init() {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    ll m = sqrt(N);
    for (ll i = 2; i <= m; ++i) {
        if (!vis[i]) {
            for (ll j = i + i; j < N; j += i) vis[j] = 1;
        }
    }
    for (ll i = 2; i < N; ++i) if (!vis[i]) a[cnt++] = i;
}

int main() {
    ll n;
    init();
    while (scanf("%lld", &n) != EOF && n) {
        int pos = lower_bound(a, a + cnt, n) - a;
        if (a[pos] == n) puts("0");
        else printf("%lld\n", a[pos] - a[pos - 1]);
    }
    return 0;
}
