/*
这个题有点难度了，我们先建立一个最小生成树，然后以链表的形式把他们都保存起来
因为要件链表，所以本题我们用Prim算法来实现
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 110
#define INF 0x3f3f3f3f

int vis[N];
int G[N][N], d[N];

int main() {
    int n;
    scanf("%d",&n);

    memset(vis,0,sizeof(vis));
    memset(d, INF, sizeof(d));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j){
            scanf("%d",&G[i][j]);
        }
    }

    int q, a, b;
    scanf("%d",&q);
    while (q--) {

        scanf("%d%d",&a, &b);
        G[a][b] = G[b][a] = 0;

    }

    d[1] = 0;
    int cost = 0;
    while (1) {

        int v = -1;

        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && (v == -1 || d[v] > d[i])) {
                v = i;
            }
        }

        if(v == -1) break;
        vis[v] = 1;
        cost += d[v];

        for (int i = 1; i <= n; ++i) {
            if (d[i] > G[v][i]) {
                d[i] = G[v][i];
            }
        }
    }

    printf("%d\n",cost);

    return 0;
}