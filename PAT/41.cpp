//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define N 1100

int n, m, k;

struct Solve {
    int vis[N];
    int n, m;
    vector<int> G[N];

    void build(int n, int m) {
        memset(vis, 0, sizeof(vis));
        this->n = n; this->m = m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    void dfs(int u, int fa, int k) {
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (v != k && v != fa && !vis[v]) dfs(v, u, k);
        }
    }

    int solve(int k) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != k && !vis[i]) {
                dfs(i, -1, k); ++cnt;
            }
        }
        return cnt;
    }

};

int getAns(Solve solver, int k) {
    return solver.solve(k);
}

int main() {
    Solve solver;
    scanf("%d%d%d", &n, &m, &k);
    solver.build(n, m);
    for (int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        printf("%d\n", getAns(solver, x) - 1);
    }
    return 0;
}
