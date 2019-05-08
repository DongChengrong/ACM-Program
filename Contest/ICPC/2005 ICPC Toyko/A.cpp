#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 11000

int m;
int vis[N], primes[N], pre[N];

void init() {
    m = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= 10000; ++i) {
        if (!vis[i]) {
            primes[m++] = i;
            for (int j = i + i; j <= 10000; j += i) vis[j] = 1;
        }
    }
    pre[0] = 0;
    for (int i = 1; i <= m; ++i) pre[i] = pre[i - 1] + primes[i - 1];
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) !=EOF && n) {
        int res = 0;
        int p = lower_bound(primes, primes + m, n) - primes;
        if (primes[p] == n) ++p;
        for (int i = 0; i <= p; ++i) {
            for (int j = i + 1; j <= p; ++j) {
                if (pre[j] - pre[i] == n) ++res;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
