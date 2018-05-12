#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1100
#define INF 0x3f3f3f3f

int t,s,d,V;
int vis[N], c[N];
int G[N][N];

void dijkstra() {
    memset(c, INF, sizeof(c));
    memset(vis, 0, sizeof(vis));
    c[0] = 0;

    while (1) {

        int v = -1;

        for (int i = 0; i <= V; ++i) {
            if (!vis[i] && c[i] != INF && (v == -1 || c[v] > c[i]) ) {
                v = i;
            }
        }

        if (v == -1) break;
        vis[v] = 1;

        for (int i = 0; i <= V; ++i) {
            if (!vis[i] && c[i] > c[v] + G[v][i]) {
                c[i] = c[v] + G[v][i];
            }
        }

    }
}

int main() {
    while (scanf("%d%d%d",&t, &s, &d) == 3) {

        memset(G, INF, sizeof(G));

        V = -1;
        while (t--) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v] = G[v][u] = min(w,G[u][v]);
            V = max(max(u, v), V);
        }

        while (s--) {
            int x;
            scanf("%d",&x);
            G[0][x] = G[x][0] = 0;
        }

        dijkstra();

        int cost = INF;
        while (d--) {
            int x;
            scanf("%d",&x);
            cost = min(cost, c[x]);
        }

        printf("%d\n",cost);
    }
    return 0;
}
