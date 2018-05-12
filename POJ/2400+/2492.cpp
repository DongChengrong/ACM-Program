#include <stdio.h>

#define N 2200

int pa[N * 2];

void init(int n) {
    for (int i = 1; i <= 2 * n; ++i) pa[i] = i;
}

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int same(int x, int y) {
    return findset(x) == findset(y);
}

void unite(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x != y) pa[x] = y;
}

int main() {
    int T;
    scanf("%d",&T);
    for (int kase = 1; kase <= T; ++kase) {
        int n, q;
        printf("Scenario #%d:\n",kase);
        scanf("%d%d",&n, &q);
        init(n);
        int ok = 1;
        while (q--) {
            int x, y;
            scanf("%d%d",&x, &y);
            if (same(x, y)) ok = 0;   //如果是来自同一集团找到反例
            else { unite(x, y + n); unite(x + n, y); }
        }

        if (ok) puts("No suspicious bugs found!");
        else puts("Suspicious bugs found!");
        puts("");
    }
    return 0;
}
