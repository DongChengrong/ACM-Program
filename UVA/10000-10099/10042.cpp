#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long LL;

LL sum(LL x) {
    LL ans = 0;
    while (x) {
        ans = ans + x % 10;
        x /= 10;
    }
    return ans;
}

LL psum(LL y) {
    LL ans = 0, x = y;
    for (LL i = 2; i <= (LL)sqrt(x); ++i) {
        while (x % i == 0) {
            ans += sum(i);
            x /= i;
        }
    }

    if (x == y) return 0;
    if (x != 1) ans += sum(x);

    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        LL n;
        scanf("%lld",&n);

        for (LL i = n + 1; ; ++i) {
            LL x = sum(i);
            LL y = psum(i);
            if (x == y) {
                printf("%lld\n",i);
                break;
            }
        }
    }
    return 0;
}
