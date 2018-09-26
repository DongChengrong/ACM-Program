#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define N 5
#define INF 1000000

int dp[N][N][N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int val;
        char s[5];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    dp[i][j][k] = INF;
        for (int i = 0; i < n; ++i) {
            int a[5]; memset(a, 0, sizeof(a));
            scanf("%d %s", &val, s);
            for (int i = 0; i < strlen(s); ++i) a[s[i] - 'A'] = 1;
            dp[a[0]][a[1]][a[2]] = min(val, dp[a[0]][a[1]][a[2]]);
        }
        dp[1][1][1] = min(dp[1][1][1], dp[1][0][0] + dp[0][1][0] + dp[0][0][1]);
        dp[1][1][1] = min(dp[1][1][1], dp[1][0][0] + dp[0][1][1]);
        dp[1][1][1] = min(dp[1][1][1], dp[0][1][0] + dp[1][0][1]);
        dp[1][1][1] = min(dp[1][1][1], dp[0][0][1] + dp[1][1][0]);
        dp[1][1][1] = min(dp[1][1][1], dp[1][1][0] + dp[0][1][1]);
        dp[1][1][1] = min(dp[1][1][1], dp[1][1][0] + dp[1][0][1]);
        dp[1][1][1] = min(dp[1][1][1], dp[0][1][1] + dp[1][1][0]);
        dp[1][1][1] = min(dp[1][1][1], dp[0][1][1] + dp[1][0][1]);
        if (dp[1][1][1] >= INF) puts("-1");
        else printf("%d\n", dp[1][1][1]);

    }
    return 0;
}
