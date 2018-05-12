#include <stdio.h>
#include <string.h>

#define N 110000

bool ok;
int e, v;
int vis[N], pa[N];

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int same(int x, int y) {
    return findset(x) == findset(y);
}

void unite(int x, int y) {
    x = findset(x); y = findset(y);
    if (x != y) pa[x] = y;
}

void init() {
    e = v = 0;
    ok = true;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; ++i) pa[i] = i;
}

int main() {
    int x, y;
    init();
    while (scanf("%d%d",&x,&y)) {
        if (x == -1) break;
        if (x == 0) {
            if (e + 1 != v) ok = false;
            if (v == 0) ok = true;
            if (ok) puts("Yes");
            else puts("No");
            init();
            continue;
        }

        if (same(x, y)) ok = true;
        else unite(x, y);

        if (!vis[x]) { vis[x] = 1; v++; }
        if (!vis[y]) { vis[y] = 1; v++; }
        if (x != y) e++;
    }
    return 0;
}
