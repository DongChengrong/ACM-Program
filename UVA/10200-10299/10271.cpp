#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define M 1100
#define N 5500
#define INF 0x3f3f3f3f

int w[N],dp[N][M];

int main() {
    int T, k, n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&k, &n);
        for (int i = n; i >= 1; --i) scanf("%d",&w[i]);
        memset(dp, INF, sizeof(dp));
        for (int i = 1; i <= n; ++i) dp[i][0] = 0;

        k = k + 8;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i >= j * 3 && dp[i - 2][j - 1] != INF) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (w[i] - w[i - 1]) * (w[i] - w[i - 1]));
                    //printf("%d %d %d\n",i, j, dp[i][j]);
                }
            }
        }

        printf("%d\n",dp[n][k]);
    }
    return 0;
}
