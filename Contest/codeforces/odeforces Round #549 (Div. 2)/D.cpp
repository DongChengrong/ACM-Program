#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define INF 110000000000

int main() {
    ll a, b, x, y, n, k;
    while (scanf("%I64d%I64d", &n, &k) != EOF) {
        scanf("%I64d%I64d", &a, &b);
        x = INF, y = -INF;
        ll l1 = k + b - a;
        ll l2 = k - a -  b;
        while (l1 <= 0) l1 += k;
        while (l2 <= 0) l2 += k;
        for (int i = 1; i <= n; ++i) {
            x = min(x, n *k / __gcd(n * k , l1));
            x = min(x, n * k / __gcd(n * k, l2));
            y = max(y, n * k / __gcd(n * k, l1));
            y = max(y, n * k / __gcd(n * k, l2));
            l1 += k, l2 += k;
        }
        printf("%I64d %I64d\n", x, y);
    }
    return 0;
}
