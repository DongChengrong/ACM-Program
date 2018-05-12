#include <stdio.h>

#define N 1100

int pa[N];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int same(int x, int y) {
    return findset(x) == findset(y);
}

void unite(int x, int y) {
    pa[findset(x)] = findset(y);
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int m, n;
        scanf("%d%d",&n, &m);
        for (int i = 1; i <= n; ++i) pa[i] = i;
        int cnt = n;
        while (m--) {
            int x, y;
            scanf("%d%d",&x, &y);
            if (same(x, y)) continue;
            unite(x, y);
            cnt--;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
