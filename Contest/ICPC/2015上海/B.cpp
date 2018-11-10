#include <stdio.h>

typedef long long ll;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}

int main() {
    int T;
    ll n, k;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%lld%lld", &n, &k);
        printf("Case #%d:\n", kase);
        int MAX = qpow(2, k) - 1;
        if (n == MAX + 1) {
            ll tmp = 1;
            for (int i = 1; i < k; ++i) { printf("%lld +\n", tmp); tmp = tmp * (ll)2; }
            printf("%lld +\n", tmp + 1);
        } else {
            ll a = MAX - n, tmp = 1, b; b = (a & 1 ? (a + 1) >> 1 : a >> 1);
            for (int i = 1; i < k; ++i) {
                printf("%lld %c\n", tmp, (b & 1) ? '-' : '+');
                tmp = tmp * (ll)2;
                b = b ? b >> 1 : b;
            }
            if (a & 1) printf("%lld +\n", tmp + 1);
            else printf("%lld +\n", tmp);
        }
    }
    return 0;
}
