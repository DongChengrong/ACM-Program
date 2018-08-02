#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 21000
#define INF 0x3f3f3f3f

int dp[2][N][2], p[N], t[N];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int x, nx = 0;
        for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i], &t[i]);
        for (int i = 1; i <= n; ++i) dp[0][i][0] = dp[0][i][1] = 0;
        for (int i = 1; i < n; ++i) {
            x = nx; nx ^= 1;
            for (int j = 1; j <= n; ++j) {
                dp[nx][j][0] = min(dp[x][j + 1][0] + p[j + 1] - p[j], dp[x][j + 1][1] + p[i + j] - p[j]);
                dp[nx][j][1] = min(dp[x][j][0] + p[i + j] - p[j], dp[x][j][1] + p[i + j] - p[j + i - 1]);
                if (dp[nx][j][0] >= t[j]) dp[nx][j][0] = INF;
                if (dp[nx][j][1] >= t[i + j]) dp[nx][j][1] = INF;
            }
        }
        int MIN = min(dp[nx][1][0], dp[nx][1][1]);
        if (MIN == INF) puts("No solution");
        else printf("%d\n", MIN);
    }
    return 0;
}
