#include <stdio.h>

typedef unsigned long long ll;

int main() {
    ll n, m, r;
    while (scanf("%lld%lld%lld", &n, &m, &r) != EOF) {
        ll num = (n / 2) * m;
        if (n & 1) {
            if (r) num += (m + 1) / 2;
            else num += (m - 1) / 2;
        }
        printf("%lld\n", num);
    }
    return 0;
}
