#include <stdio.h>

typedef long long ll;

int main() {
    ll res = 0, n;
    scanf("%I64d", &n);
    for (ll i = 2; i < n; ++i) res += i * (i + 1);
    printf("%I64d\n", res);
    return 0;
}
