#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110000

typedef long long ll;

ll a[N], b[N], c[N];

int main() {
    ll n;
    ll ans = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &c[i]);
    sort(a, a + n); sort(b, b + n); sort(c, c + n);
    for (int i = 0; i < n; ++i) {
        ll pos1 = lower_bound(a, a + n, b[i]) - a;
        ll pos2 = upper_bound(c, c + n, b[i]) - c;
        pos2 = n - pos2;
        ans += pos1 * pos2;
    }
    printf("%lld\n", ans);
    return 0;
}
