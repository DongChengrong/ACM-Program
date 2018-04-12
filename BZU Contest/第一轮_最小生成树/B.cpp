#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define N 100

int G[N][N];
int d[N], vis[N];

int main() {
    int n,m;
    while (scanf("%d",&n) == 1 && n) {

        scanf("%d",&m);

        int cost = 0;
        memset(G, INF, sizeof(G));
        memset(d, INF, sizeof(d));
        memset(vis, 0, sizeof(vis));

        while (m--) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v] = G[v][u] = min(G[u][v], w);
        }

        d[1] = 0;
        while (1) {

            int v = -1;

            for (int i = 1; i <= n; ++i) {
                if( !vis[i] && (v == -1 || d[v] > d[i]) ) {
                    v = i;
                }
            }

            if (v == -1) break;

            //printf("%d %d\n",v,d[v]);

            cost += d[v];
            vis[v] = 1;

            for (int i = 1; i <= n; ++i) {   //更新花费
                if (d[i] > G[v][i]) {
                    d[i] = G[v][i];
                }
            }
        }

        printf("%d\n",cost);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define N 100

int G[N][N];
int d[N], vis[N];

int main() {
    int n,m;
    while (scanf("%d",&n) == 1 && n) {

        scanf("%d",&m);

        int cost = 0;
        memset(G, INF, sizeof(G));
        memset(d, INF, sizeof(d));
        memset(vis, 0, sizeof(vis));

        while (m--) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v] = G[v][u] = min(G[u][v], w);
        }

        d[1] = 0;
        while (1) {

            int v = -1;

            for (int i = 1; i <= n; ++i) {
                if( !vis[i] && (v == -1 || d[v] > d[i]) ) {
                    v = i;
                }
            }

            if (v == -1) break;

            //printf("%d %d\n",v,d[v]);

            cost += d[v];
            vis[v] = 1;

            for (int i = 1; i <= n; ++i) {   //更新花费
                if (d[i] > G[v][i]) {
                    d[i] = G[v][i];
                }
            }
        }

        printf("%d\n",cost);
    }
    return 0;
}
