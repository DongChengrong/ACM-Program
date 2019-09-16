#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace  std;

#define N 510000

int pa[N], w[N];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) pa[i] = i, w[i] = 1;
    for (int i = 0; i < m; ++i) {
        int k, x,y; scanf("%d", &k);
        if (k) { scanf("%d", &x); k--; }
        for (int j = 0; j < k; ++j) {
            scanf("%d", &y);
            x = findset(x); y = findset(y);
            if (x != y) {
                w[y] += w[x]; pa[x] = y;
                findset(x);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", w[findset(i) ], i == n ? '\n' : ' ');
    }
    return 0;
}