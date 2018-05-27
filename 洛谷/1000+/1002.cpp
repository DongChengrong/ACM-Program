#include <stdio.h>
#include <string.h>

#define N 110

typedef long long ll;

const int dir[8][2] = { {-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2} };
int vis[N][N];
ll dp[N][N];

int main() {
    int n, m, x, y;
    while (scanf("%d%d%d%d",&n, &m, &x, &y) == 4) {
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        dp[0][0] = 1;
        vis[x][y] = 1;
        for (int i = 0; i < 8; ++i) {
            int u = x + dir[i][0];
            int v = y + dir[i][1];
            if (u >= 0 && v >= 0) vis[u][v] = 1;
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                ll u, v;
                if (vis[i][j]) continue;
                if (i == 0 || vis[i - 1][j]) u = 0;
                else u = dp[i - 1][j];
                if (j == 0 || vis[i][j - 1]) v = 0;
                else v = dp[i][j - 1];
                dp[i][j] += u + v;
            }
        }
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
