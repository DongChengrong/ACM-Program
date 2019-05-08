#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define N 4200
#define INF 0x3f3f3f3f

typedef long long ll;

struct Edge {
    int from, v, cap, flow;
};

int n, m;
int d[N];
int cur[N];
vector<Edge> edges;
vector<int> G[N];

void init(int n) {
    edges.clear();
    for (int i = 0; i <= 2 * n; ++i) G[i].clear();
}

void addEdge(int u, int v, int cap) {
    edges.push_back((Edge){u, v, cap, 0});
    edges.push_back((Edge){v, u, 0, 0});
    G[u].push_back(edges.size() - 2);
    G[v].push_back(edges.size() - 1);
}

bool bfs(int s, int t) {
    memset(d, INF, sizeof(d));
    queue<int> q; q.push(s); d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if (d[e.v] == INF && e.cap > e.flow) {
                d[e.v] = d[u] + 1;
                q.push(e.v);
            }
        }
        if (d[t] != INF) return true;
    }
    return d[t] != INF;
}

int dfs(int u, int t, int a) {
    if (u == t || !a) return a;
    int flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.v] == d[u] + 1 && (f = dfs(e.v, t, min(a, e.cap - e.flow)))) {
            a -= f; flow += f;
            e.flow += f; edges[G[u][i] ^ 1].flow -= f;
        }
    }
    return flow;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(s, t, INF);
    }
    return flow;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        int s, t; init(n); scanf("%d%d", &s, &t);
        for (int i = 1; i <= n; ++i) {
            ll x; scanf("%d", &x); addEdge(i, i + n, x);
        }
        for (int i = 0; i < m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u + n, v, INF); addEdge(v + n, u, INF);
        }
        n = n * 2;
        printf("%d\n", max_flow(s, t + n / 2));
    }
    return 0;
}
