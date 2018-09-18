#include <stdio.h>

typedef unsigned long long ll;

const ll ul = 1;

ll Size(ll n) {
    return n == 0 ? 1 : (ul << (n - 1));
}

ll slove(ll b, ll n) {
    ll i;
    if (b == 1 || b == 0) return b;
    if (n == Size(b)) return b;

    for (i = 1; i < b; ++i) {
        ll k = (b - i - 1), m = Size(k);
        if (n <= i * m) return slove(k, n % m == 0 ? m : n % m);
        n -= i * m;
    }
}

ll slove(ll n) {
    if (!n) return 0;
    ll b = 1;
    while (n) {
        ll m = Size(b);
        if (n <= m) return slove(b, n);
        else b = b + 1, n -= m;
    }
}

int main() {
    ll n;
    while (scanf("%llu", &n) != EOF && n) {
        printf("%llu\n", slove(n - 1));
    }
    return 0;
}
