#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f
#define N 1100
#define M 15

struct Edge {
    int u, v, w;
    bool operator < (Edge e) {
        return w < e.w;
    }
};

int n, q, cnt;
int x[N], y[N], cost[M], pa[N];
Edge edges[N * N];
vector<int> G[M], p;

void init(int n) {
    for (int i = 0; i <= n; ++i) pa[i] = i;
}

int findset(int x) {
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void unite(int u, int v) {
    u = findset(u); v = findset(v);
    if (u != v) pa[u] = v;
}

int dis(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int same(int x, int y) {
    return findset(x) == findset(y);
}

int kruskal(int k) {
    p.clear();
    int cc = n, sum = 0;
    init(n);
    for (int i = 0; i < q; ++i) {
        if (k & (1 << i)) {
            sum += cost[i];
            int u = G[i][0];
            for (int j = 1; j < G[i].size(); ++j) {
                if (!same(u, G[i][j])) {
                    unite(u, G[i][j]); cc--;
                }
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        u = findset(u); v = findset(v);
        if (u != v) {
            sum += edges[i].w;
            unite(u, v); cc--; p.push_back(i);
        }
        if (cc == 1) break;
    }
    if (cc != 1) return INF;
    else return sum;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    while (T--) {
        cnt = 0;
        for (int i = 0; i < M; ++i) G[i].clear();
        scanf("%d%d", &n, &q);
        for (int i = 0; i < q; ++i) {
            int m, x;
            scanf("%d%d", &m, &cost[i]);
            for (int j = 0; j < m; ++j) {
                scanf("%d", &x); G[i].push_back(x);
            }
        }
        for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (i == j) continue;
                edges[cnt++] = (Edge){i, j, dis(i, j)};
            }
        }
        sort(edges, edges + cnt);
        int ans = kruskal(0); cnt = 0;
        for (int i = 0; i < p.size(); ++i) {
            edges[cnt++] = edges[p[i]];
        }
        for (int i = 1; i < (1 << q); ++i) {
            ans = min(ans, kruskal(i));
        }
        printf("%d\n", ans);
        if (T) puts("");
    }
    return 0;
}
