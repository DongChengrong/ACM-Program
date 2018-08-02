//题目https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 550
#define INF 0x3f3f3f3f

int n, m, s, t;
int vis[N], cost[N], d[N], sum[N], dp[N];
int G[N][N];

void dijstra() {
    memset(vis, 0, sizeof(vis));
    memset(d, INF, sizeof(d));
    d[s] = 0;
    while (1) {
        int v = -1;

        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            if (v == -1 || d[v] > d[i] ) {
                v = i;
            }
        }

        if (v == -1) break;
        vis[v] = 1;

        for (int i = 0; i < n; ++i) {
            if (i == v) continue;
            if (d[i] > d[v] + G[i][v]) {
                d[i] = d[v] + G[i][v];
                sum[i] = sum[v] + cost[i];
            } else if (d[i] == d[v] + G[i][v]) {
                if (sum[i] < sum[v] + cost[i]) {
                    sum[i] = sum[v] + cost[i];
                }
            }
        }

    }
}

int dfs(int t) {
    int &ans = dp[t];
    if (ans) return ans;

    for (int i = 0; i < n; ++i) {
        if (d[i] + G[i][t] == d[t]) {
            ans += dfs(i);
        }
    }

    return ans;

}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(G, INF, sizeof(G));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i]);
        sum[i] = cost[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        G[u][v] = G[v][u] = min(c, G[u][v]);
    }
    dijstra();

    memset(dp, 0, sizeof(dp)); dp[s] = 1;
    printf("%d %d\n", dfs(t), sum[t]);
    return 0;
}
