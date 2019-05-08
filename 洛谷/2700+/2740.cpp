//ÍøÂçÁ÷°å×ÓÌâ
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f

const int maxn = 2e2 + 10;

struct Edge {
    int from, to, cap, flow;
};

int d[maxn], cur[maxn];
int n, m;
vector<int> G[maxn];
vector<Edge> edges;

void addEdge(int u, int v, int cap) {
    edges.push_back((Edge){u, v, cap, 0});
    edges.push_back((Edge){v, u, 0, 0});
    G[u].push_back(edges.size() - 2);
    G[v].push_back(edges.size() - 1);
}

int bfs(int s, int t) {
    memset(d, INF, sizeof(d));
    queue<int> q; q.push(s); d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if (d[e.to] == INF && e.cap > e.flow) {
                d[e.to] = d[u] + 1;
                q.push(e.to);
            }
        }
    }
    return d[t] != INF;
}

int dfs(int u, int t, int a) {
    if (u == t || !a) return a;
    int flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.to] == d[u] + 1 && (f = dfs(e.to, t, min(a, e.cap - e.flow)))) {
            e.flow += f; edges[G[u][i] ^ 1].flow -= f; a -= f; flow += f;
            if (!a) break;
        }
    }
    return flow;
}

int maxFlow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(s, t, INF);
    }
    return flow;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    printf("%d\n", maxFlow(1, n));
    return 0;
}
