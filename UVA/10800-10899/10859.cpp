#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

int n, m;
int vis[N][2], dp[N][2];
vector<int> G[N];

void init() {
    memset(vis, 0, sizeof(vis));
    _for (i, 0, N) G[i].clear();
}

int dfs(int i, int j, int f) {
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = 1;
    int &ans = dp[i][j];

    ans = 2000;  //默认放置街灯
    _for (k, 0, G[i].size()) {
        int v = G[i][k];
        if (v != f) ans += dfs(v, 1, i);
    }

    if (f >= 0 && !j) ans += 1;  //发现一个单边

    if (f == -1 || j == 1) {
        int sum = 0;
        _for (k, 0, G[i].size()) {
            int v = G[i][k];
            if (v != f) sum += dfs(v, 0, i);
        }
        if (f != -1) sum += 1;
        ans = min(ans, sum);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        init();
        _for (i, 0, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ans = 0;
        _for (i, 0, n - 1) {
            if (!vis[i][0]) ans += dfs(i, 0, -1);
        }
        printf("%d %d %d\n", ans / 2000, m - (ans % 2000), ans % 2000 );
    }
    return 0;
}
