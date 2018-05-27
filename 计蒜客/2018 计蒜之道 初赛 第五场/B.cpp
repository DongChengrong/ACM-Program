#include <stdio.h>
#include <string.h>

#define N 1100
#define Mod 998244353

typedef long long ll;

ll f[N];
ll n, k;

ll get(ll x) {
    ll res = 1;
    while (x) {
        res *= x % 10;
        x /= 10;
    }
    return res;
}

void init() {
    for (ll i = 1; i <= 1000; ++i) {
        f[i] = get(i);
    }
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int check(ll i, ll j) {
    ll d = gcd(f[i], f[j]);
    if (f[i] * f[j] > 0 && d > 0 && d <= k) return 1;
    return 0;
}

int main() {
    init();
    while (scanf("%lld%lld", &n, &k) == 2) {
        ll res = 0;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (check(i, j)) res = (res + 1) % Mod;
            }
        }
        printf("%lld\n", res % Mod);
    }
    return 0;
}
