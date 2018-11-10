#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 110

struct Solve {

    int n;
    int vis[N], have[N];
    vector<int> G[N];
    int res[N][N];

    void build() {
        memset(res, 0, sizeof(res));
        for (int i = 0; i <= n; ++i) G[i].clear();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x; scanf("%d", &x);
                if (x) G[i].push_back(j);
            }
        }
    }

    void dfs(int u, int k) {
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); ++i) {
            if (!vis[G[u][i]] && G[u][i] != k) dfs(G[u][i], k);
        }
    }

    void setConf() {
        memset(have, 0, sizeof(have));
        memset(vis, 0, sizeof(vis));
        dfs(0, -1);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                have[i] = 1; res[i][i] = 1; res[0][i] = 1;
            }
        }
    }

    void solve() {
        for (int i = 1; i < n; ++i) {
            if (have[i]) {
                memset(vis, 0, sizeof(vis));
                dfs(0, i);
                for (int j = 1; j < n; ++j) {
                    if (have[j] && !vis[j]) res[i][j] = 1;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            printf("+");
            for (int i = 0; i < 2 * n - 1; ++i) printf("-");
            puts("+");
            for (int j = 0; j < n; ++j) printf("|%c", res[i][j] ? 'Y' : 'N');
            puts("|");
        }
        printf("+");
            for (int i = 0; i < 2 * n - 1; ++i) printf("-");
            puts("+");
    }

};

int main() {
    int T;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        Solve solver;
        solver.build();
        solver.setConf();
        solver.solve();
        printf("Case %d:\n", kase);
        solver.print();
    }
    return 0;
}
