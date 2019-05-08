#include <stdio.h>

typedef long long ll;

ll exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int main() {
    ll a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        ll x, y, d;
        exgcd(a, b, d, x, y);
        ll bb = b / d;
        x = (x * 1 / d % bb + bb) % bb;
        printf("%lld\n", x);
    }
    return 0;
}
