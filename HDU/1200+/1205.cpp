#include <stdio.h>

typedef long long ll;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll sum = 0, max = 0, n;
        scanf("%lld", &n);
        for (ll i = 1; i <= n; ++i) {
            ll tmp; scanf("%lld", &tmp);
            sum += tmp;
            if (tmp > max) {
                max = tmp;
            }
        }
        if (sum - max >= max - 1) puts("Yes");
        else puts("No");
    }
    return 0;
}
