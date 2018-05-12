#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1100000

int pa[N], vis[N];

void init() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; ++i) pa[i] = i;
}

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int same(int x, int y) {
    return findset(x) == findset(y);
}

void unite(int x, int y) {
    x = findset(x); y = findset(y);
    if (x != y) {
        pa[x] = y;
    }
}

int main() {
    int u, v, T = 1;
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    while (1) {
        init();
        bool ok = true;

        int vex  = 0, edge = 0;
        scanf("%d%d",&u,&v);

        if (u == -1) break;

        if (same(u, v)) ok = false;
        else unite(u, v);

        if (u == 0 && v == 0) {
            printf("Case %d is a tree.\n", T++);
            continue;
        }

        if (u != v) edge++;
        if (!vis[u]) { vex++; vis[u] = 1; }
        if (!vis[v]) { vex++; vis[v] = 1; }

        while (scanf("%d%d",&u, &v) == 2 && u) {
            if (same(u, v)) ok = false;
            else unite(u, v);

            if (u != v) edge++;
            if (!vis[u]) { vex++; vis[u] = 1; }
            if (!vis[v]) { vex++; vis[v] = 1; }
        }

        if(vex !=  edge + 1) ok = false;

        if (ok) printf("Case %d is a tree.\n", T++);
        else printf("Case %d is not a tree.\n",T++);
    }

    return 0;
}
