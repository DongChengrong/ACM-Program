#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 110
#define M 25

int a[M][N];
int dp[M][N];

int main() {
    int T, m, n;
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i][0]);
            for (int j = 0; j < a[i][0]; ++j) scanf("%d", &a[i][j + 1]);
        }
        for (int i = 1; i <= a[0][0]; ++i) if (a[0][i] <= m) dp[0][m - a[0][i]] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = m; j >= 0; --j) {
                if (dp[i - 1][j]) {
                    for (int k = 1; k <= a[i][0]; ++k) {
                        if (j >= a[i][k]) dp[i][j - a[i][k] ] = 1;
                    }
                }
            }
        }
        int money;
        for (money = 0; money <= m; ++money) if (dp[n - 1][money]) break;
        if (money == m + 1) puts("no solution");
        else printf("%d\n", m - money);
    }
    return 0;
}
