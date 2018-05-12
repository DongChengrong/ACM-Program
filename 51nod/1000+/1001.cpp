#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 55000

typedef long long LL;

LL a[N];
int vis[N];

int main() {
    LL n, k;
    while (scanf("%lld%lld",&k, &n) == 2) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) scanf("%lld",&a[i]);
        sort(a, a + n);
        int cnt = 0;
        for (LL i = 0; i < n; ++i) {
            if (vis[i]) continue;
            LL key = k - a[i];
            int p = lower_bound(a, a + n, key) - a;
            if (a[p] == key && i != p) {
                cnt++;
                vis[i] = vis[p] = 1;
                printf("%lld %lld\n",min(a[i], a[p]), max(a[i], a[p]));
            }
        }
        if (!cnt) puts("No Solution");
    }
    return 0;
}
