#include <stdio.h>
#include <math.h>

#define N 110

typedef long long ll;

ll f[N];

void init() {
    f[1] = f[0] = 1;
    for (int i = 2; i <= 15; ++i) f[i] = f[i - 1] * i;
}

int main() {
    int n, k;
    init();
    while (scanf("%d%d",&n, &k) == 2) {
        ll res = 1;
        for (int i = 0; i < k; ++i) {
            int x; scanf("%d",&x);
            res *= f[x];
        }
        printf("%lld\n", f[n] / res);
    }
    return 0;
}
