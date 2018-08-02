#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f
#define N 550

int G[N][N], d[N], vis[N];
int n, m, k;

void prim(int &sum) {
    int cnt = 0;
    sum = 0;
    memset(d, INF, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[1] = 0;
    while (1) {
        int v = 0;

        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            if ((v == 0 && d[i] != INF) || d[i] < d[v]) {
                v = i;
            }
        }

        if (v == 0) break;
        vis[v] = 1;
        cnt++;

        sum += d[v];

        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            if (G[v][i] != INF && d[i] > G[v][i]) {
                d[i] = G[v][i];
            }
        }

    }
    if (cnt != n) sum = INF;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int cc = n;
        memset(G, INF, sizeof(G));
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            G[u][v] = G[v][u] = min(c, G[u][v]);
        }
        for (int i = 0; i < k; ++i) {
            int t, x, y;
            scanf("%d", &t); scanf("%d", &x);
            for (int j = 1; j < t; ++j) {
                scanf("%d", &y);
                G[x][y] = G[y][x] = 0;
            }
        }

        int sum;
        prim(sum);
        printf("%d\n", sum == INF ? -1 : sum);
    }
    return 0;
}
