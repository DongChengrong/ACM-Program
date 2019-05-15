#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 110

int ma[N][N], vis2[N];
int vis[N], dp1[N], dp2[N];
int n, m;
vector<int> G[N], G2[N], S;

void init(int n) {
    memset(vis, 0, sizeof(vis));
    memset(ma, 0, sizeof(ma));
    for (int i = 0; i <= n; ++i) {
        G[i].clear(); G2[i].clear();
    }
}

void scc_dfs1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) scc_dfs1(G[u][i]);
    S.push_back(u);
}

void scc_dfs2(int u, int scc_cnt) {
    if (vis2[u]) return;
    vis2[u] = scc_cnt;
    for (int i = 0; i < G2[u].size(); ++i) scc_dfs2(G2[u][i], scc_cnt);
}

int check() {
    int cnt = 0;
    S.clear();
    memset(vis, 0, sizeof(vis));
    memset(vis2, 0, sizeof(vis2));
    for (int i = 1; i <= n; ++i) scc_dfs1(i);
    for (int i = n - 1; i >= 0; --i) {
        if (!vis2[S[i]]) { scc_dfs2(S[i], ++cnt); }
    }
    return cnt == n;
}

int dfs1(int u) {
    int ans = 1;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        if (vis[G[u][i]]) continue;
        ans += dfs1(G[u][i]);
    }
    return ans;
}

int dfs2(int u) {
    int ans = 1;
    vis2[u] = 1;
    for (int i = 0; i < G2[u].size(); ++i) {
        if (vis2[G2[u][i]]) continue;
        ans += dfs2(G2[u][i]);
    }
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int ok = 1;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            if (u == v) { ok = 0; continue; }
            if (ma[u][v]) continue;
            ma[u][v] = ma[v][u] = 1;
            G[u].push_back(v); G2[v].push_back(u);
        }
        if (!check()) ok = 0;
        if (!ok) {
            for (int i = 0; i < n; ++i) printf("0"); puts("");
        } else {
            for (int i = 1; i <= n; ++i) {
                memset(vis, 0, sizeof(vis));
                memset(vis2, 0, sizeof(vis2));
                int num1 = dfs1(i) - 1;
                int num2 = dfs2(i) - 1;
                if (num1 <= n / 2 && num2 <= n / 2) printf("1"); else printf("0");
            }
            puts("");
        }
    }
    return 0;
}
/*
5
5 4
1 2
3 2
2 4
2 5
3 2
1 1
2 3
5 5
4 1
5 1
1 2
2 3
1 3
4 4
1 2
1 3
2 4
3 4
3 3
1 2
2 3
3 1
**/
