#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define N 2100

char s[N][N];
int G[N][N];
int d[N], vis[N];

int dis(int i, int j) {
    int num = 0;
    for (int k = 0; k < 7; ++k) {
        if (s[i][k] != s[j][k]) num++;
    }
    return num;
}

int main() {
    int n;
    while (scanf("%d",&n) == 1 && n) {

        int cost = 0;
        memset(G, INF, sizeof(G));
        memset(d, INF, sizeof(d));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; ++i) {
            scanf("%s",s[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                G[i][j] = G[j][i] = dis(i, j);
            }
        }

        d[0] = 0;
        while (1) {

            int v = -1;

            for (int i = 0; i < n; ++i) {
                if( !vis[i] && (v == -1 || d[v] > d[i]) ) {
                    v = i;
                }
            }

            if (v == -1) break;


            cost += d[v];
            vis[v] = 1;

            for (int i = 0; i < n; ++i) {   //更新花费
                if (d[i] > G[v][i]) {
                    d[i] = G[v][i];
                }
            }
        }

        printf("The highest possible quality is 1/%d.\n",cost);
    }
    return 0;
}
