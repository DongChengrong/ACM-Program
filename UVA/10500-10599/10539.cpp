#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N (long long)(1e6)
#define M (long long)(1e12)

typedef long long ll;

int n;
ll a[N], vis[N + 100];

void sieve() {
    n = 0;
    memset(vis, 0, sizeof(vis));
    for (ll i = 2; i <= N;  ++i) {
        if (!vis[i]) {
            for (ll j = i * i; j <= M; j *= i) a[n++] = j;
            for (ll j = i + i; j <= (N); j += i) vis[j] = 1;
        }
    }
    sort(a, a + n);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T;
    ll L, R;
    sieve();
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &L, &R);
        int l = lower_bound(a, a + n, L) - a;
        int r = lower_bound(a, a + n, R) - a;
        printf("%d\n", a[r] == R ? r - l + 1 : r - l);
    }
    return 0;
}
