#include <stdio.h>
#include <math.h>

typedef long long ll;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        ll n; scanf("%lld", &n);
        ll m = sqrt(n + 1), ans = 0;
        for (ll i = 2; i <= m; ++i) if ((n + 1) % i == 0) ans++;
        printf("%lld\n", ans);
    }
    return 0;
}
