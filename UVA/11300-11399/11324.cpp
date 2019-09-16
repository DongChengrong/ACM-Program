//SCC + 缩点 + 记忆化搜索
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 1100

int n, m, cnt;
int ma[N][N], vis[N];
int sz[N], dp[N];
vector<int> G[N], G2[N], S, g[N];

void dfs1(int u) {
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        if (!vis[G[u][i] ]) {
            dfs1(G[u][i]);
        }
    }
    S.push_back(u);
}

void dfs2(int u, int cnt) {
    vis[u] = cnt;
    for (int i = 0; i < G2[u].size(); ++i) {
        if (!vis[G2[u][i]]) dfs2(G2[u][i], cnt);
    }
    sz[cnt]++;
}

void scc() {
    S.clear();
    cnt = 0; memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs1(i);
    }
    memset(sz, 0, sizeof(sz));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (!vis[S[i]]) {
            dfs2(S[i], ++cnt);
        }
    }
}

void build() {  //缩点
   // memset(ma, 0, sizeof(ma));
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= n; ++i) {
        int u = vis[i];
        for (int j = 0; j < G[i].size(); ++j) {
            int v = vis[G[i][j]];
            if (u == v) continue;
            //if (ma[u][v]) continue;
            //ma[u][v] = 1;
            g[u].push_back(v);
        }
    }
}

int dfs(int u) {
    if (dp[u]) return dp[u];
    int &ans = dp[u]; ans = sz[u];
    for (int i = 0; i < g[u].size(); ++i) {
        int v= g[u][i];
        ans = max(ans, sz[u] + dfs(v));
    }
    return ans;
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; ++i) { G[i].clear(); G2[i].clear(); }
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G2[v].push_back(u);
        }
        scc(); build();
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= cnt; ++i) {
            if (!dp[i]) ans = max(ans, dfs(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
