#include <stdio.h>
#include <string.h>

#define N 1200

int dp[N][N];
char s1[N], s2[N], s[N];

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%s %s %s", s1, s2, s);
        //puts(s1); puts(s2); puts(s);
        int n = strlen(s1);
        int m = strlen(s2);
        int k = n + m;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i > 0 && s[i + j - 1] == s1[i - 1] && dp[i - 1][j]) dp[i][j] = 1;
                if (j > 0 && s[i + j - 1] == s2[j - 1] && dp[i][j - 1]) dp[i][j] = 1;
            }
        }
        printf("Data set %d: %s\n", kase, (dp[n][m] ? "yes" : "no"));
    }
    return 0;
}
