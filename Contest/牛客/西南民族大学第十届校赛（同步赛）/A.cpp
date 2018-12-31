#include <stdio.h>

#define Mod 10000019

typedef long long ll;

ll qpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % Mod;
    ll c = qpow(a, b / 2) % Mod;
    c = c * c % Mod;
    if (b & 1) c = c * a % Mod;
    return c % Mod;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        ll sum = 0;
        for (int k = 1; k <= n; ++k) {
            ll i; scanf("%lld", &i);
            //printf("%lld\n", qpow(i, i));
            sum = (sum + qpow(i, k)) % Mod;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
