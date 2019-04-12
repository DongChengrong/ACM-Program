#include <stdio.h>

typedef long long ll;

ll n, k, T;

ll solve() {
    ll res = 0, sign = 1;
    while (n) {
        res += sign * n;
        sign = -sign;
        n /= k;
    }
    return res;
}

int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", solve());
    }
    return 0;
}
