#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 5500
#define INF 0x3f3f3f3f

int n;
int a[N];
int dp[N][N][2];

int main() {
    while (scanf("%d", &n) != EOF) {
        int K = (n + 1) / 2;
        memset(dp, INF, sizeof(dp));
        for (int i = 0; i <= n; ++i) dp[i][0][0] = dp[i][0][1] = 0;
        dp[1][1][0] = INF; dp[1][1][1] = 0; a[0] = INF;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= (i + 1) / 2; ++j) {
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + max(0, a[i] - a[i - 1] + 1));
                dp[i][j][1] = min(dp[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0), \
                                  dp[i - 2][j - 1][1] + max(0, a[i - 1] - min(a[i - 2], a[i]) + 1));
            }
        }
        for (int i = 1; i <= K; ++i) printf("%d%c", min(dp[n][i][0], dp[n][i][1]), i == K ? '\n' : ' ');
    }
    return 0;
}
