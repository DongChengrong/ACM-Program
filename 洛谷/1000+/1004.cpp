#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define N 110
#define INF 0x3f3f3f3f

int n;
int G[N][N];

struct Edge {
    int from, to, cap, flow;
};

struct EdmondsKarp {
    int n, m, s, t;
    int a[N], pre[N];
    vector<Edge> edges;
    vector<int> G[N];

    void init(int n) {
        edges.clear();
        for (int i = 0; i <= n; ++i) G[i].clear();
    }

    void addEdge(int u, int v, int cap) {
        edges.push_back((Edge){u, v, cap, 0});
        edges.push_back((Edge){v, u, 0, -cap});
        m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }

    int maxFlow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while (1) {
            memset(a, 0, sizeof(a));
            queue<int> q; q.push(s); a[s] = INF;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < G[u].size(); ++i) {
                    Edge e = edges[G[u][i]];
                    if (a[u] && e.cap > e.flow) {
                        a[e.to] = min(a[u], e.cap - e.flow);
                        pre[e.to] = G[u][i]; q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            flow += a[t];
            for (int u = t; u != s; u = edges[pre[t]].from) {
                edges[pre[u]].flow += a[t];
                edges[pre[u] ^ 1].flow -= a[t];
            }
        }
        return flow;
    }
};

EdmondsKarp solver;

void id(int x, int y, int flag) {
    int tmp = x * 13 + y;
    if (flag) tmp = tmp * 2 + 1;
    return tmp;
}

void read_and_build() {
    int u, v, w;
    memset(G, 0, sizeof(G));
    while (scanf("%d%d%d", &u, &v, &w) != EOF && u) {
        G[u][v] = max(G[u][v], w);
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            solver.addEdge(id(i, j, 0), id(i, j, 1))
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        read_and_build();
        printf("%d\n", solver.maxFlow(id(0, 0, 0), id(n + 1, n + 1, 1)));
    }
    return 0;
}
