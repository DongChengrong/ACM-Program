#include <stdio.h>

#define N 1500
#define Mod 1000000007

typedef long long ll;

ll f[N];

ll qpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % Mod;

    ll res = qpow(a, b / 2) % Mod;
    res = res * res % Mod;
    if (b & 1) res = (res * a) % Mod;
    return res % Mod;
}

ll rev(ll x) {
    return qpow(x, Mod - 2) % Mod;
}

void init() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 1100; ++i) f[i] = (f[i - 1] * i) % Mod;
}

ll C(int n, int m) {
    ll res = f[n];
    res = res * rev(f[m]) % Mod;
    res = res * rev(f[n - m]) % Mod;
    return res % Mod;
}

int main() {
    int a, b, c, d;
    init();
    while (scanf("%d%d%d%d",&a, &b, &c, &d) == 4) {
        ll res = C(a * 2 + 1, a) * C(b * 2 + 1, b) % Mod;
        res = res * C(c * 2 + 1, c) % Mod;
        res = res * C(d * 2 + 1, d) % Mod;
        printf("%lld\n",res % Mod);
    }
    return 0;
}
