/*
因为给出了一个矩阵，所以这个题仍然用prim解决
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1100
#define INF 0x3f3f3f3f

int vis[N],d[N],a[N];
int G[N][N];

int main() {

    int T, n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d",&G[i][j]);
                G[i][j] += a[i] + a[j];
            }
        }

        memset(vis, 0, sizeof(vis));
        memset(d, INF, sizeof(d));

        int cost = 0, cnt = n;
        d[0] = 0;

        while (1) {

            int v = -1;

            for (int i = 0; i < n; ++i) {
                if (!vis[i] && (v == -1 || d[i] < d[v] )) {
                    v = i;
                }
            }

            if (v == -1) break;
            vis[v] = 1;
            cnt--;
            cost += d[v];

            for (int i = 0; i < n; ++i) {
                if (d[i] > G[i][v]) {
                    d[i] = G[i][v];
                }
            }
        }

        if (cnt == 0) printf("%d",cost);
        putchar('\n');
    }
    return 0;
}
