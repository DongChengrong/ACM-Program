#include <stdio.h>

typedef long long ll;

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        ll h, w, sum = 0;
        scanf("%lld%lld", &h, &w);
        if (h >= 4 && w >= 2) sum += (w - 1) * (h - 3);
        printf("%lld\n", sum);
        printf("%lld\n", (h - 1) * (w - 2));
        if (h >= 2 && w >= 4) sum += (h - 1) * (w - 3);
        printf("Case %d: %lld\n", ++kase, sum);
    }
    return 0;
}
