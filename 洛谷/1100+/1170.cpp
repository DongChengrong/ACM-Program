#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        ll x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        ll x = abs(x1 - x2), y = abs(y1 - y2);
        if (__gcd(x, y) != 1) puts("yes"); else puts("no");

    }
    return 0;
}
