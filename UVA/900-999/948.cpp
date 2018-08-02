#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 100

typedef long long ll;

int n;
ll vis[N], f[N];

void init() {
    f[0] = 1; f[1] = 2;
    for (n = 2; f[n - 1] <=  100000000; ++n) {
        f[n] = f[n - 1] + f[n - 2];
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll x;
        scanf("%lld", &x); printf("%lld = ", x);
        memset(vis, 0, sizeof(vis));
        int MAX = lower_bound(f, f + n, x) - f;
        if (f[MAX] != x) MAX -= 1;
        vis[MAX] = 1; x -= f[MAX];
        for (int i = MAX - 1; i >= 0; --i) {
            if (x == 0) break;
            if (f[i] <= x) {
                vis[i] = 1;
                x -= f[i];
            }
        }
        for(int i = MAX; i >= 0; --i) {
            if (vis[i]) printf("1");
            else printf("0");
        }
        puts(" (fib)");
    }
    return 0;
}
