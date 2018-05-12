//完全背包问题
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 110
#define M 110000000

int n, C, T;
int v[N], c[N];
int dp[M], vis[N];

int dfs(int cnt, int C) {
    if (cnt >= n) return 0;
    if (C <= 0) return 0;

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && C - c[i] >= 0) {
            vis[i] = 1; res = max(res, dfs(cnt + 1, C - c[i]) + v[i]); vis[i] = 0;
        }
    }

    return res;
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n, &C);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d",&v[i], &c[i]);
        }

        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));

        printf("%d\n",dfs(0,C));
    }
    return 0;
}
