#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define N 220
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, cap, flow;
};

int d[N];
int cur[N];
int n,m, s, t;
vector<int> G[N];
vector<Edge> edges;

void addEdge(int u, int v, int w) {
    edges.push_back((Edge){u, v, w, 0});
    edges.push_back((Edge){v, u, 0, 0});
    G[u].push_back(edges.size() - 2);
    G[v].push_back(edges.size() - 1);
}

int bfs() {
    memset(d, INF, sizeof(d));
    queue<int> q; q.push(s); d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i] ];
            if (d[e.to] == INF && e.cap > e.flow) {
                d[e.to] = d[u] + 1;
                q.push(e.to);
            }
        }
    }
    return d[t] != INF;
}

int dfs(int u, int a) {
    if (u == t  || !a) return a;
    int flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.to] == d[u] + 1 && (f = dfs(e.to, min(a, e.cap - e.flow)))) {
            e.flow += f; edges[G[u][i] ^ 1].flow -= f; a -= f; flow += f;
        }
        if (!a) break;
    }
    return flow;
}

int maxFlow() {
    int flow = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(s, INF);
    }
    return flow;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t); s += n;
    for (int i = 1; i <= n; ++i) addEdge(i, i + n, 1);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u + n, v, INF); addEdge(v + n, u, INF);
    }
    printf("%d\n", maxFlow());
    return 0;
}
