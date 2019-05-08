//题目链接：https://pintia.cn/problem-sets/994805148990160896/problems/994805153478066176
//强连通分量板子题，可以用Kosaraju或者Tanjan算法
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define N 11000

vector<int> S;
int vis[N], sccno[N];
vector<int> G[N], G2[N];
int scc_cnt = 0;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) dfs(G[u][i]);
    S.push_back(u);
}

void dfs2(int u) {
    if (sccno[u]) return;
    sccno[u] = scc_cnt;
    for (int i = 0; i < G2[u].size(); ++i) dfs2(G2[u][i]);
}

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G2[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) dfs(i);
    for (int i = n - 1; i >= 0; --i) {
        if (!sccno[S[i]]) { scc_cnt++; dfs2(S[i]); }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int u, v; scanf("%d%d", &u, &v); --u; --v;
        if (sccno[u] == sccno[v]) puts("Yes"); else puts("No");
    }
    return 0;
}
