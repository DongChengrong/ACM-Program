#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N 50
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, cap, flow;
};

int m, n;
int d[N], cur[N];
vector<int> G[N];
vector<Edge> edges;

void init() {
    scanf("%d%d", &n, &m);
    edges.clear();
    for (int i = 0; i <= n; ++i) G[i].clear();
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        edges.push_back((Edge){u, v, w, 0});
        edges.push_back((Edge){v, u, 0, 0});
        G[u].push_back(edges.size() - 2);
        G[v].push_back(edges.size() - 1);
    }
}

//利用bfs构造层次图
int bfs(int s, int t) {
    memset(d, INF, sizeof(d));
    d[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if (d[e.to] > d[e.from] + 1 && e.cap > e.flow) {
               // printf("%d %d %d %d\n", e.from, e.to, e.cap, e.flow);
                d[e.to] = d[e.from] + 1;
                q.push(e.to);
            }
        }
    }
    return d[t] != INF;
}

//dfs得到阻塞流
int dfs(int u, int t, int a) {
    if (u == t || !a) return a;
    int flow = 0, f = 0;
    for (int &i = cur[u]; i < G[u].size(); ++i) {
        Edge &e = edges[G[u][i]];
        if (d[e.to] == d[e.from] + 1 && (f = dfs(e.to, t, min(a, e.cap - e.flow))) > 0) {
            e.flow += f; flow += f; a -= f; edges[G[u][i] ^ 1].flow -= f;
            if (a == 0) break;
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
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        init();
        printf("Case %d: %d\n", kase, maxFlow(1, n));
    }
    return 0;
}
