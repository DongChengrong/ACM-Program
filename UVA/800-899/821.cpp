/*
*   UVA 821
* Floyd 算法水题
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110
#define INF 0x3f3f3f3f

int p, l;  //p代表对数，l代表长度
int G[N][N];

bool init() {
    int u, v;
    memset(G, INF, sizeof(G));
    for (int i = 0; i <= 100; ++i) G[i][i] = 0;
    scanf("%d%d", &u, &v); if (u == 0) return false;
    G[u][v] = 1;
    while (scanf("%d%d", &u, &v) == 2 && u) {
        G[u][v] = 1;
    }
    return true;
}

void floyd() {
    for (int k = 1; k <= 100; ++k) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    p = l = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <=  100; ++j) {
            if (i != j && G[i][j] != INF) {
                ++p; l += G[i][j];
            }
        }
    }
}

int main() {
    int kase = 0;
    while (init()) {
        floyd();
        printf("Case %d: average length between pages = %.3f clicks\n", ++kase, (double)l / (double)p);
    }
    return 0;
}
