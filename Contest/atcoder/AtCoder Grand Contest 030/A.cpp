#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {
        ll res = min(b, c);
        b -= res; c -= res; res *= 2;
        if (b) res += b;
        if (c) res += min(c, a);
        c -= min(c, a);
        if (c) res++;
        printf("%lld\n", res);
    }
    return 0;
}
