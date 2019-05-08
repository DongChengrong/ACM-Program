#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N 11000
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, cap, flow;
};

int n, m = 0;
int d[N];
int cur[N];
vector<int> G[N];
vector<Edge> edges;

void addEdge(int u, int v, int cap) {
    edges.push_back((Edge){u, v, cap, 0});
    edges.push_back((Edge){v, u, 0, 0});
    G[u].push_back(m); ++m;
    G[v].push_back(m); ++m;
}

int bfs() {
    memset(d, INF, sizeof(d));
    queue<int> q; q.push(0); d[0] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int sz = G[u].size();
        for (int i = 0; i < sz; ++i) {
            Edge e = edges[G[u][i]];
            if (d[e.to] == INF && e.cap > e.flow) {
                d[e.to] = d[u] + 1;
                q.push(e.to);
            }
        }
    }
    return d[n] != INF;
}

int dfs(int u, int a) {
    if (u == n || a == 0) return a;
    int flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.to] == d[u] + 1 && (f = dfs(e.to, min(a, e.cap - e.flow)))) {
            e.flow += f; a -= f; edges[G[u][i] ^ 1].flow -= f; flow += f;
            if (a == 0) break;
        }
    }
    return flow;
}

int maxFlow() {
    int flow = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(0, INF);
    }
    return flow;
}

int main() {
    int id = 2, tot = 0, k, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x); tot += x;
        addEdge(0, i + 1, x);
    }
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x); tot += x;
        addEdge(i + 1, n + 1, x);
    }
    id = n + 2;
    n = n + 1;
    scanf("%d", &k);
        while (k--) {
        int sz, x1, x2;
        scanf("%d%d%d", &sz, &x1, &x2);
        tot += x1 + x2;
        addEdge(0, id, x1); addEdge(id + 1, n, x2);
        for (int i = 0; i < sz; ++i) {
            int v; scanf("%d", &v);
            addEdge(id, v, INF); addEdge(v, id + 1, INF);
        }
        id += 2;
    }
    printf("%d\n",  tot - maxFlow());
    return 0;
}

