#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 220
#define M 258

char s1[N], s2[N];
int vis[M];
int dp[N][N];

int main() {

    int kase = 0;
    while (1) {
        gets(s1 + 1);
        if (s1[1] == '#') break;
        int n = strlen(s1 + 1);
        gets(s2 + 1);
        int m = strlen(s2 + 1);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i] == s2[j]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", ++kase, dp[n][m]);
    }
    return 0;
}
