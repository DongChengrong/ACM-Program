#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 110
#define INF 0x3f3f3f3f

int n,m;
int G[N][N];

void init() {
    memset(G, INF, sizeof(G));
    for (int i = 0; i < N; ++i) {
        G[i][i] = 0;
    }
}

void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                G[i][j] = G[j][i] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

bool check() {
    for (int  i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (G[i][j] > 7) {
                //printf("%d     %d    %d\n",i,j,G[i][j]);
                return false;
            }
        }
    }
    return true;
}

int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        init();

        while (m--) {
            int u, v;
            scanf("%d%d",&u, &v);
            G[u][v] = G[v][u] = 1;
        }

        floyd();

        if (check()) puts("Yes");
        else puts("No");
    }
    return 0;
}
