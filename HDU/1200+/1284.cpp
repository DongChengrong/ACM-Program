#include <stdio.h>
#include <string.h>

#define N 32768

typedef long long ll;

ll dp[4][N];

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0) dp[i][j] += dp[i][j - i];
        }
    }
    int n;
    while (scanf("%d", &n) != EOF) printf("%lld\n", dp[3][n]);
    return 0;
}
