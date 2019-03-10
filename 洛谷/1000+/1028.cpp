#include <stdio.h>
#include <string.h>

#define N 1100

int dp[N];

int dfs(int n) {
    if (n == 1) return dp[n] = 1;
    if (dp[n]) return dp[n];
    int &ans = dp[n]; ans = 1;
    for (int i = 1; i <= n / 2; ++i) ans += dfs(i);
    return ans;
}

int main() {
    int n;
    memset(dp, 0, sizeof(dp));
    while (scanf("%d", &n) != EOF) {
        int ans = dfs(n);
        printf("%d\n", ans);
    }
    return 0;
}
