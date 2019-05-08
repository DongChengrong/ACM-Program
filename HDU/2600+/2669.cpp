#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int main() {
    ll a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        ll x, y, d, c = 1;
        exgcd(a, b, d, x, y);
        if (d != 1) { puts("sorry"); continue; }
        else {
            ll bb = b / d;
            x = ((x * c / d) % bb + bb) % bb;
            y = (1 - a * x) / b;
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}
