#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 1100

int n, m;
int vis[N];
vector<int> G[N];

int dfs(int u) {
    vis[u] = 1;
    int ans = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        if (!vis[G[u][i] ]) ans += dfs(G[u][i]);
    }
    return ans;
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; ++i) G[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof(vis));
            ans = max(ans, dfs(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
