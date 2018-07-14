#include <stdio.h>

#define Mod 998244353

typedef long long ll;

ll qpow(ll a, ll b) {
    if (b == 0) return (ll)1;
    if (b == 1) return a % Mod;

    ll ans = qpow(a, b / 2) % Mod;
    ans = ans * ans % Mod;
    if (b & 1) ans = ans * a % Mod;
    return ans % Mod;
}

int main() {
    ll n;
    while (scanf("%lld", &n) == 1) {
        printf("%lld\n", qpow(2, n - 2) - 1);
    }
    return 0;
}
