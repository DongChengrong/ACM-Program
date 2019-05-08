#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define N (int)(3e5 + 10)

int n, cnt;
int dp[N], a[N];
vector<int> G[N];

void dfs(int u) {
    int &ans = dp[u];
    if (G[u].empty()) {
        ans = 1; cnt++; return;
    } else {
        ans = (a[u] ? n + 100 : 0);
        for (int v : G[u]) {
            dfs(v);
            if (a[u]) ans = min(ans, dp[v]);
            else ans += dp[v];
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 2, f; i <= n; ++i) {
            scanf("%d", &f); G[f].push_back(i);
        }
        memset(dp, 0, sizeof(dp));
        cnt = 0; dfs(1);
        printf("%d\n", cnt + 1 - dp[1]);
    }
    return 0;
}
