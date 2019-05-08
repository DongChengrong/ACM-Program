#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 110000

int main() {
    int T; scanf("%d", &T);
    while (T--){
        ll n, b = 0, c = 0; scanf("%lld", &n);
        for (int i = 0; i < n; ++i) {
            ll x; scanf("%lld", &x);
            if (x < 0) x = -x;
            b += x; c += x * x;
        }
        ll pre = n * c - b * b, d = __gcd(pre, n);
        if (!pre) puts("0/1"); else printf("%lld/%lld\n", pre / d, n / d);
    }
    return 0;
}
