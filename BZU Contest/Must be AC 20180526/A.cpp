#include <stdio.h>

typedef long long ll;

int main() {
    ll n;
    while (scanf("%lld",&n) == 1) {
        ll res = (1 + n) * n / 2 - (n - 1);
        printf("%lld\n",res);
    }
    return 0;
}
