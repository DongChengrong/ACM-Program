#include <stdio.h>

typedef long long ll;

const ll base = 1;

void convert(ll &res, ll b) {
    for (int i = 15; i >= 0; --i) {
        res = res * 2;
        if (b & (base << i)) res = res + 1;
    }
}

int main() {
    ll n;
    while (scanf("%lld", &n) != EOF) {
        ll res = 0;
        convert(res, n); convert(res, n >> 16);
        printf("%lld\n", res);
    }
    return 0;
}

