#include <stdio.h>
#include <string.h>

#define N 50

int n, m;
int dp[N][N];

int main() {
    while (scanf("%d%d",&n, &m) == 2) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j][i] = dp[(j + 1) % n][i - 1] + dp[(j - 1 + n) % n][i - 1];
            }
        }
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
