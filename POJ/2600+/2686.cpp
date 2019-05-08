#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define N 1024
#define M 33
#define INF (1e9 + 7)

struct Edge {
    int to; double w;
};

int horse[15];
int n, m, p, a, b;
vector<Edge> G[M];
double dp[N][M];

double dfs(int S, int u) {
    //printf("%d %d\n", S, u);
    if (u != a && dp[S][u] != 0) return dp[S][u];
    if (u == b) return dp[S][u] = 0;
    double res = INF;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge e = G[u][i];
        for (int i = 0; i < n; ++i) {
            if (S & ( 1 << i)) continue;
            res = min(res, dfs(S | (1 << i), e.to) + e.w / (double)horse[n - i]);
        }
    }
    return dp[S][u] = res;
}

int main() {
    while (scanf("%d%d%d%d%d", &n, &m, &p, &a, &b) != EOF && (n + m)) {
        for (int i = 1; i <= m; ++i) G[i].clear();
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) scanf("%d", &horse[i]);
        for (int i = 0; i < p; ++i) {
            int u, v; double w;
            scanf("%d%d%lf", &u, &v, &w);
            G[u].push_back((Edge){v, w});
            G[v].push_back((Edge){u, w});
        }
        for (int i = 0; i < ( 1 << n); ++i) dp[i][a] = INF;
        dfs(0, a);
        double res = INF;
        for (int i = 0; i < (1 << n); ++i) res = min(res, dp[i][a]);
        if (res == INF) puts("Impossible"); else printf("%.3f\n", res);
    }
    return 0;
}
