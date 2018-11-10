#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        ll x, y;
        int cnt = 1;
        scanf("%lld%lld", &x, &y);
        while (1) {
            if (x > y) swap(x, y);
            ll d = __gcd(x, y);
            //if (y % ((x / d + 1) * d) == 0) {
            if (y % (x + d) == 0) {
                y = y / (x / d + 1);
                ++cnt;
            } else break;
        }
        printf("Case #%d: %d\n", kase, cnt);
    }
    return 0;
}
