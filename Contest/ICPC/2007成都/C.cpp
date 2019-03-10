#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 550
#define M 5500000
#define INF 0x3f3f3f3f

struct Edge {
    int to, cost;
};

int n, m, start;
int dp[N][N][2], son[N], ind[N];
vector<Edge> G[N];

void init() {
    m = start = 0;
    memset(ind, 0, sizeof(ind));
    memset(son, 0, sizeof(son));
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < n; ++i) G[i].clear();
}

void build_graph() {
    int u, v, d;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &v, &u, &d);
        G[u].push_back((Edge){v, d});
        ind[u];
    }
    for (int i = 0; i < n; ++i) if (!ind[i]) { start = i; break; }
}

void dfs(int root) {
    son[root] = 1;
    dp[root][1][0] = dp[root][1][1] = 0;
    for (Edge e : G[root]) {
        int y = e.to, len = e.cost; dfs(y);
        for (int j = son[root]; j >= 1; --j) {
            for (int k = 1; k <= son[y]; ++k) {
                dp[root][j + k][0] = min(dp[root][j + k][0], dp[root][j][0] + dp[y][k][0] + 2 * len);
                dp[root][j + k][1] = min(dp[root][j + k][1], min(dp[root][j][0] + dp[y][k][1] + len \
                                , dp[root][j][1] + dp[y][k][0] + 2 * len));
            }
        }
        son[root] = son[root] + son[y];
    }
}

void query() {
    int q; scanf("%d", &q);
    while (q--) {
        int x, ans; scanf("%d", &x);
        for (int i = n; i >= 1; --i) if (dp[start][i][1] <= x || dp[start][i][0] <= x) { ans = i; break; }
        printf("%d\n", ans);
    }
}

int main() {
    int kase = 0;
    while (scanf("%d", &n) != EOF && n) {
        printf("Case %d:\n", ++kase);
        init();
        build_graph();
        dfs(start);
        query();
    }
    return 0;
}
